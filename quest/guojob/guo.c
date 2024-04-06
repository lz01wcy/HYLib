// guojing.c 郭靖
inherit NPC;
#include <ansi.h>
#include "zzzjob.c"
#include "teamjob.c"
string ask_newjob();
string ask_newover();
int job_over(string arg);

void create()
{
	set_name("郭靖", ({"guo jing", "guo", "jing"}));
	set("nickname", HIY"北侠"NOR);
	set("gender", "男性");
	set("age", 41);
	set("long", 
		"他就是人称北侠的郭靖，既是蒙古成吉思汗的金刀驸马，又是\n"
		"江南七怪、全真派马钰道长、「北丐」洪七公和「老顽童」周\n"
		"伯通等人的徒弟，身兼数门武功。他身着一件灰色长袍，体态\n"
		"魁梧，敦厚的面目中透出一股威严。\n");
	set("attitude", "friendly");
	set_max_encumbrance(100000000);
	set("per", 20);
	set("str", 60);
	set("int", 20);
	set("con", 60);
	set("dex", 60);
        set_temp("no_get",1);
        set_temp("no_kill",1);
	set("chat_chance", 1);
	set("chat_msg", ({
		"郭靖叹了口气道：“蒙古兵久攻襄阳不下，一定会再出诡计，蓉儿又不在身边，这....\n",
		"郭靖说道：“华筝公主近来不知可好，抽空一定要回大漠去看看她。\n",
//		(: random_move :),
	}));

	set("inquiry", ([
		"周伯通" : "你见到我周大哥了？他现在可好？\n",
		"老顽童" : "周大哥一贯这样，没点正经！\n",
		"洪七公" : "师父除了吃，就是喜欢玩。到处玩，还是为了找吃的。\n",
		"黄药师" : "那是我泰山大人。他云游四海，神龙见首不见尾的。\n",
		"一灯大师" : "在下对大师好生感激。\n",
		"欧阳锋" : "这个老毒物，害死我六位师父，一待襄阳事了，决不与他干休。\n",
		"黄蓉"   : "蓉儿是我的爱妻，你问她做甚？\n",
		"蓉儿"   : "蓉儿就是蓉儿了。你问这么多干嘛？\n",
		"郭芙"   : "这个女儿，又笨又不听话。\n",
		"郭襄"   : "襄儿生于乱世，这辈子又多艰厄。但愿她能快乐一世。\n",
		"郭破虏" : "那是我的小儿子。\n",
		"杨过"   : "过儿确实有出息。\n",
		"马钰"   : "马道长于我有半师之谊。\n",
		"丘处机" : "邱道长义薄云天，是真豪杰。\n",
		"柯镇恶" : "那是我大师父。\n",
		"朱聪"   : "那是我二师父。\n",
		"韩宝驹" : "那是我三师父。\n",
		"南希仁" : "那是我四师父。\n",
		"张阿生" : "那是我五师父。\n",
		"全金发" : "那是我六师父。\n",
		"韩小莹" : "那是我七师父。\n",
		"丐帮"   : "丐帮英雄几百年了，守卫襄阳多亏了他们。\n",
		"拜师"   : "现在蒙古人围攻襄阳，我哪有心情收徒啊！\n",
		 "job"   : (: ask_job :),
         "功劳"  : (: ask_gonglao :),
         "fangqi": (: ask_fangqi :),
         "放弃"  : (: ask_fangqi :),
		 "奸细"  : (: ask_jianxi :),
                "守城" : (: ask_newjob :),
                "job2"  : (: ask_newjob :),
                "撤退"  : (: ask_newover :),
		]));

	set("qi", 8000);
	set("max_qi", 8000);
	set("jing", 8000);
	set("max_jing", 8000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("jiali", 500);
	
	set("combat_exp", 25000000);
	set("score", 200000);
	 
	set_skill("force", 400);		// 基本内功
	set_skill("huntian-qigong", 450);	// 混天气功
	set_skill("unarmed", 400);		// 基本拳脚
	set_skill("xianglong-zhang", 450);	// 降龙十八掌
	set_skill("dodge", 400);		// 基本躲闪
	set_skill("xiaoyaoyou", 400);		// 逍遥游
	set_skill("parry", 400);		// 基本招架
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	prepare_skill("unarmed","xianglong-zhang");
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("job_over","task");
}

string ask_newjob()
{
        object *ene;
        object me = this_player();

        if(is_fighting()) 
        {
                ene=query_enemy();
                
                if(sizeof(ene)>1) return "“请"+RANK_D->query_respect(me)+"稍等片刻，我先和这"+sizeof(ene)+"位高手切磋几下！”\n";
                if(sizeof(ene)==1) return "“请"+RANK_D->query_respect(me)+"稍等片刻，我先和"+ene[0]->name()+"切磋几下！”\n";
        }

        if(me->query_temp("mark/job_shadi")>0 ) return "“"+RANK_D->query_respect(me)+"不是已有任务了吗！”\n";

/*        if((int)me->query("shen") < 0) return "“"+RANK_D->query_respect(me)+"心术不正，我们不欢迎！”\n";
*/     
        if ((int)me->query("combat_exp")<100000) return "“"+RANK_D->query_respect(me)+"手无缚鸡之力，还是别领任务的为好！”\n";

    if ( (int)me->query_skill("force",1) < 100 )
       return "守城是件危险工作，我看"+RANK_D->query_respect(me)+"的基本内功不足！\n";
if (me->query("shen")<0)
       return "你这个恶徒，走远一点！\n";

        if(me->query_temp("job_over"))
       return "你先把你手上的活干完再说！\n";
       if(me->query_temp("killed_mgb"))
       return "你先把你手上的活干完再说！\n";

    if ( (int)me->query("combat_exp") < 100000 )
       return "守城是件危险工作，我看"+RANK_D->query_respect(me)+"的经验不足！\n";

      if ((int)me->query_condition("jobshadi_failed"))
{
     message_vision("$N对着$n摇了摇头说：逃跑失败了还来见我??\n", this_object(), me);
return "“"+RANK_D->query_respect(me)+"你还是别领任务的为好！”\n";
//return;
}

       if ((int)me->query_condition("gf_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("feitian2_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("gf_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("gumu_job"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("hu_song"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("huang_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("huaxunshan"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("husong_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("hxsd_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("lingjiu_song"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("lingxiao2_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("ljjob2"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("lyjob"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("lyjob2"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("menggu_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("mingjiaojob"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("mr_job"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("nonamejob"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("quanzhenjob"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("riyue_guard"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("riyuejob"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("roomjob"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("ry2_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("shaolin_song"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("taohuajob"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("tz_job"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("wdj2_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("xsjob2"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("xsjob"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("xh_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("wudangjob"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("bt2_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("dali_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("emeijob"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("menpai_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("yl2_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("zzz_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("yue_busy"))  
       return "守城是件危险工作，我看"+me->query("name")+"需要休息一会！\n";

      if ((int)me->query_condition("jobshadi_limit")>1)
{
     message_vision("$N对着$n摇了摇头说：你不是正做着吗??\n", this_object(), me);
return "“"+RANK_D->query_respect(me)+"你快点回你的岗位上去！”\n";
//return;
}
   if ((int)me->query_condition("guojob2_busy"))
{
     message_vision("$N对着$n摇了摇头说：现在蒙古人正在攻城！！\n", this_object(), me);
return "“"+RANK_D->query_respect(me)+"你等会再来！”\n";
//return;
}
if (this_object()->is_busy())
{
     message_vision("$N对着$n摇了摇头说：我正忙着布置人手呢！！\n", this_object(), me);
return "“"+RANK_D->query_respect(me)+"你等会再来！”\n";
//return;
}

this_object()->start_busy(15);
message("channel:chat", HIB"【朝廷急报】"GRN + "有消息说：蒙古靼子马上要侵犯襄阳了!\n"NOR,users() );
	if (random(2)==0)
	{
        switch( random(2) ) {
                case 0:
			me->set_temp("mark/job_shadi",1);
        	        me->set_temp("carry_location","northgate1");		
                me->apply_condition("guojob2_busy",10);
                return "“现在蒙古靼子侵犯中原，这位"+RANK_D->query_respect(me)+"去玄武内门帮助宋军守城吧。";

	               break;
                case 1:
			me->set_temp("mark/job_shadi",2);
                	me->set_temp("carry_location","northgate1");		
                me->apply_condition("guojob2_busy",10);
                return "“现在蒙古靼子侵犯中原，这位"+RANK_D->query_respect(me)+"去青龙内门帮助宋军守城吧。";

	               break;
        	}	
        }
        else
        {
        switch( random(2) ) {
                case 0:
                	me->set_temp("mark/job_shadi",3);
                	me->set_temp("carry_location","southgate1");
                me->apply_condition("guojob2_busy",10);
                return "“现在蒙古靼子侵犯中原，这位"+RANK_D->query_respect(me)+"去朱雀内门帮助宋军守城吧。";

	               break;
                case 1:
                	me->set_temp("mark/job_shadi",4);
                	me->set_temp("carry_location","southgate1");
                me->apply_condition("guojob2_busy",10);
                return "“现在蒙古靼子侵犯中原，这位"+RANK_D->query_respect(me)+"去白虎内门帮助宋军守城吧。";

	               break;
        	}
        }
me->apply_condition("menpai_busy",13);
}

int job_over(string arg)
{
        int job_pot,job_exp;
        object me = this_player();
	object badguy;
	object room;

        if(!arg) return 1;

        if(arg!="over") return 1;
	if(me->query_temp("help_killed")>0)
	{
        	message_vision(CYN "$N拍了拍$n的肩膀说道：“"+RANK_D->query_respect(me)+"，为国杀敌，不错不错！”\n" NOR, this_object(), me);
	        job_exp=((int)me->query_temp("killed_mgb"))*80;
                  job_pot=job_exp*2/3;
                  job_exp=job_exp;
if (job_exp >2000) job_exp=2000;
job_pot=job_exp*2/3;
if (job_pot >1500) job_pot=1500;

	        me->add("combat_exp", job_exp);
	        me->add("potential",job_pot);
tell_object(me, "你被奖励了"+chinese_number(job_exp)+"点经验值！\n"+chinese_number(job_pot)+"点潜能\n");
	        me->delete_temp("killed_mgb");        
                me->delete_temp("job_over");
                me->delete_temp("mark/job_shadi");
                me->delete_temp("help_killed");
        me->add("eff_jing",- me->query("max_jing")/10);
        me->add("eff_qi",- me->query("max_qi")/10);
        me->start_busy(3);
                me->apply_condition("guojob2_busy",12);
me->apply_condition("menpai_busy",11);
if (me->query("combat_exp") > 8000000)
me->apply_condition("guojob2_busy",13);
me->apply_condition("menpai_busy",13);
        	return 1;
        }
        	
        if(me->query_temp("mark/job_shadi")==0)
        {
                message_vision(CYN"$N瞧了$n一眼:“没任务还什么完成不完成。”\n",this_object(),me);
                return 1;
        }
        
        if(me->query_temp("job_over")==0)
        {
                message_vision(CYN"$N瞧了$n一眼:“任务还没完成。”\n"NOR,this_object(),me);
                return 1;
        }

       if(me->query_temp("killed_mgb")<2)
       {
                  message_vision(CYN"$N瞧了$n一眼:“你杀了几个敌人，你还来领赏？。”\n"NOR,this_object(),me);
         me->delete_temp("job_over");
         me->delete_temp("mark/job_shadi");
                  return 1;
          }

        message_vision(CYN "$N对$n说道：“"+RANK_D->query_respect(me)+"辛苦了，去休息一下吧！”\n" NOR, this_object(), me);
        me->delete_temp("job_over");
        me->delete_temp("mark/job_shadi");
        job_exp=((int)me->query_temp("killed_mgb"))*80;
        job_pot=job_exp*2/3;
        job_exp=job_exp;
if (job_exp >2000) job_exp=2000;
if (job_pot >1600) job_pot=1600;
tell_object(me, "你被奖励了"+chinese_number(job_exp)+"点经验值！\n"+chinese_number(job_pot)+"点潜能和50点江湖阅历。\n");
                me->apply_condition("guojob2_busy",11);
me->apply_condition("menpai_busy",11);
if (me->query("combat_exp") > 8000000)
me->apply_condition("guojob2_busy",13);
me->apply_condition("menpai_busy",13);
        me->add("combat_exp", job_exp);
        me->add("potential",job_pot);
        me->delete_temp("killed_mgb");        
        me->add("eff_jing",-me->query("max_jing")/10);
        me->add("eff_qi",-me->query("max_qi")/10);
        me->add("score",50);
        me->start_busy(3);
        if (random(4) == 0)
        {
message("channel:chat", HIB"【襄阳战报】"HIW + "一队宋军伤兵，退到了襄阳城中心附近!\n"NOR,users() );
		if(objectp(room=load_object("/d/xiangyang/eastjie1")) && 
		objectp(badguy = new("/quest/guojob/menggu/songbing")))
		badguy->move(room);
                badguy->random_move();
                room=load_object("/d/xiangyang/westjie1");
                badguy = new("/quest/guojob/menggu/songbing");
                badguy->move(room);
                room=load_object("/d/xiangyang/southjie1");
                badguy = new("/quest/guojob/menggu/songbing");
                badguy->move(room);
                badguy->random_move();
	}
        if (random(4) == 1)
        {
message("channel:chat", HIB"【襄阳战报】"HIW + "一队蒙古精兵，冲进了襄阳城北门附近!\n"NOR,users() );
		if(objectp(room=load_object("/d/xiangyang/dingzi")) && 
		objectp(badguy = new("/quest/guojob/menggu/mengu2")))
		badguy->move(room);
                badguy->random_move();
                room=load_object("/d/xiangyang/northroad1");
                badguy = new("/quest/guojob/menggu/mengu2");
                badguy->move(room);
                badguy->random_move();
                room=load_object("/d/xiangyang/jiekou2");
                badguy = new("/quest/guojob/menggu/mengu2");
                badguy->move(room);
                badguy->random_move();
                room=load_object("/d/xiangyang/dingzi");
                badguy = new("/quest/guojob/menggu/mengu3");
                badguy->move(room);
                badguy->random_move();  	
  	}
        if (random(4) == 2)
        {
message("channel:chat", HIB"【襄阳战报】"HIW + "一大队蒙古兵，冲进了襄阳城西门附近!\n"NOR,users() );
		if(objectp(room=load_object("/d/xiangyang/westjie1")) && 
		objectp(badguy = new("/quest/guojob/menggu/mengu1")))
		badguy->move(room);
                room=load_object("/d/xiangyang/westjie2");
                badguy = new("/quest/guojob/menggu/mengu1");
                badguy->move(room);
                badguy->random_move();
                room=load_object("/d/xiangyang/juyiyuan");
                badguy = new("/quest/guojob/menggu/mengu1");
                badguy->move(room);
                badguy->random_move();
                room=load_object("/d/xiangyang/westjie2");
                badguy = new("/quest/guojob/menggu/mengu1");
                badguy->move(room);
                badguy->random_move();
                room=load_object("/d/xiangyang/westjie2");
                badguy = new("/quest/guojob/menggu/mengu1");
                badguy->move(room);
                badguy->random_move();
                room=load_object("/d/xiangyang/westjie2");
                badguy = new("/quest/guojob/menggu/mengu1");
                badguy->move(room);
                badguy->random_move();
 	}
        if (random(4) == 3)
        {
message("channel:chat", HIB"【襄阳战报】"HIW + "有几名蒙古奸细，混进了襄阳城南门附近!\n"NOR,users() );
		if(objectp(room=load_object("/d/xiangyang/southjie2")) && 
		objectp(badguy = new("/quest/guojob/menggu/mengu4")))
		badguy->move(room);
                badguy->random_move();
                room=load_object("/d/xiangyang/southjie2");
                badguy = new("/quest/guojob/menggu/mengu4");
                badguy->move(room);
                badguy->random_move();	
	}

        return 1;

}

string ask_newover()
{
         object me;
         me = this_player();
          if(me->query_condition("jobshadi_limit")<=1)
         return "你没有领任务,跑这里瞎嚷嚷什麽?";
         me->clear_condition("jobshadi_limit");
         me->add("combat_exp",-100+random(20));
         me->apply_condition("jobshadi_failed",13);
         me->delete_temp("mark/job_shadi");
	 me->delete_temp("carry_location");
         me->delete_temp("job_over");
         me->delete_temp("start_job");
	 return "没关系,下次继续努力 。";
}