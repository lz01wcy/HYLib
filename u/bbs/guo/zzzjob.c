#include <ansi.h>

mixed names = ({
        ({
        "北京药铺",
        }),
        ({
         "宋兵","流氓","偏将","裨将","佐将",
        }),
        });

// names need modify
string ask_job()
{ 
  object  ob, me,gift,*team;
  int exp,position;
  string target,myfam,obfam,job_type;
  ob=this_player();
  me=this_object();
  exp=ob->query("combat_exp");
 /* myfam = me->query("family/family_name"); //同一门派的才给他job,把这四行去
  obfam = ob->query("family/family_name"); //掉后就没有门派限制
  if(!myfam ||!obfam||myfam != obfam) 
  return "你不是本门弟子,我不能给你工作!";
  */
  if (interactive(ob) && ob->query_temp("zzz_job_target")
      && (int)ob->query_condition("zzz_mission"))  
       return "你上一次的任务还没完成!";
  if (interactive(ob) && !ob->query_temp("zzz_job_target")
      && (int)ob->query_condition("zzz_mission"))  
       return "你办事不力，先等会吧。";
   
    if (interactive(ob) &&
       (int)ob->query_condition("zzz_busy"))  
       return "现在我可没有给你的任务，等会再来吧。\n";
     
	
	if(exp<=100000)     
    return "你的武功太差了,等练强了再来吧。\n";
    //team=ob->query_team();
	//if(sizeof(team)<=1)
    job_type="保护";
    //else job_type="买药材";
	
	ob->set_temp("zzz_job_type",job_type);
        
	if(job_type=="保护")
	{target = names[1][random(sizeof(names[1]))];
    ob->apply_condition("zzz_mission",30);    
	ob->set_temp("zzz_job_target", target);
    message_vision(CYN"$N点了点头，对$n说道:蒙古人收买了一批武林败类,好象要暗杀"+target+"，你去保护他一下。\n"NOR , me,ob);
    call_out("begin_kill",30,ob,target);
	return "多加小心。";
	}
/*	if(job_type=="买药材")
	{target = names[0][random(sizeof(names[0]))];
    ob->apply_condition("zzz_mission",60);    
	ob->set_temp("zzz_job_target", target);
    message_vision(CYN"$N点了点头,对$n说道:由于和蒙古人交战，伤兵日益增加，现在药材短缺。
		                                   我准备了一笔钱款，你们马上到"+target+"去买一批药材回来。\n"NOR , me,ob);
    gift=new(__DIR__"gift");
    gift->move(ob);
	gift->set_temp("target_name",target);
	gift->set_temp("host",ob->query("id"));
    message_vision("$N给$n一只"+HIG+"玉匣"NOR"。\n" , me,ob);
//	call_out("begin_kill",30,ob,target);
	return "一路上多加小心。";
	}
	
*/
}

int accept_object(object who, object ob,object me)
{
        if ( ob->query("id") != "corpse") {
                command("say 你给我这个干吗?");
                return 0;
        }
        if ( !who->query_temp("zzz_job_target") ) {
                command("say 好啊！不过你得先申请任务。");
                return 0;
        }

/*      if( who->query_temp("zzz_job_type")=="杀")
		if ( ob->query("victim_name")!= who->query_temp("zzz_job_target")
			||ob->query("victim_user")||who->query_temp("zzz_given") )
		{       command("shake");
                command("say 你杀错人了。");
                return 0;
        }*/
        if( who->query_temp("zzz_job_type")=="保护")
		if (ob->query_temp("must_killby")!= who->query("id")
			||ob->query("victim_user")||who->query_temp("zzz_given") )
		{       command("shake");
                command("say 你杀错人了。");
                return 0;
        } 

/* if ( ob->query("kill_by") != who) {
                command("say 这个任务似乎不是你自己完成的吧？");
                return 0;
}*/
        who->set_temp("zzz_given",1);
        call_out("destroying", 1, ob);
        call_out("ok", 1, who);
        return 1;
}

void ok(object who)
{
        int exp,pot,i;
        if (!who) return;
        command("pat" + who->query("id"));
        command("say 干的好，你办事干净利落,将来必成大器!");
        if(!who->query("zzz_job_count"))
		who->set("zzz_job_count",1);
        else
		who->add("zzz_job_count",1);        
		i=who->query("zzz_job_count");
		i/=100;
		exp=100+random(20)+i+random(i);
        pot=exp/3+random(50);
		who->add("potential",pot);
        who->add("combat_exp",exp);
        who->delete_temp("zzz_job_target");
        who->delete_temp("zzz_given");
		who->delete_temp("zzz_job_type");
		who->clear_condition("zzz_mission");
               
				tell_object(who,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战经验\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);
                return;
}


void destroying(object obj)
{
        destruct(obj);
        return;
}

string ask_fangqi()
{
         object me;
         me = this_player();
         if(me->query_condition("zzz_mission")<=1)
         return "你没有领任务,跑这里瞎嚷嚷什麽?";
         me->clear_condition("zzz_mission");
         me->add("combat_exp",-50+random(20));
       //me->apply_condition("zzz_busy",4+random(4));
         me->delete_temp("zzz_job_target");
		 me->delete_temp("zzz_job_type");
         return "没关系,下次继续努力 。";
}


void begin_kill(object me,string target)
{  object obj,*ob;
   int i,flag=0;
   if(!me->query_condition("zzz_mission"))
   return;
   if (me->query_temp("zzz_job_type")!="保护"||me->query_temp("zzz_job_target")!=target)
   return;
   ob = all_inventory(environment(me));
   for(i=0; i<sizeof(ob); i++)
   {
   if( !living(ob[i])||ob[i]==me ) continue;
   if(ob[i]->query("name")==target)
   {flag=1;
	break;
   }
   }
   if (flag==0)
   { call_out("begin_kill",30,me,target);
     return;	   
   } 
	obj=new(__DIR__"killer");
	obj->move(environment(me));
    obj->do_copy(me);
	obj->set_temp("must_killby",me->query("id"));
	message_vision(GRN"\n$N对着"+target+"发出一阵阴笑声，令"+target+"全身上下的寒毛根根竖起，不寒而栗。\n"NOR,obj); 
	message_vision(HIY"$N对$n喝道:大胆狂徒,竟敢在这撒野！！\n"NOR,me,obj);    
    message_vision(HIY"$N阴阴一笑:要你多管闲事,去死吧！！\n"NOR,obj);
    obj->kill_ob(me);
}

string ask_gonglao(object who)
{
  object me;
  int i;
           
  me = this_player();
  if(!me->query("zzz_job_count"))
  i=0;
  else 
  i =(int)me->query("zzz_job_count"); 
  message_vision(CYN"$N对$n说道:你已经完成了" + chinese_number(i) + "次任务。\n"NOR,who,me);
  return "继续努力吧！";
}
