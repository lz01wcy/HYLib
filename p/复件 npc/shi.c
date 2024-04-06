//dadi.c 任务使
// [lsg 1999/11/24]

inherit NPC;
#include <ansi.h>;
#include "teamjob.c"
int time_period(int timep,object me);
mixed rooms = ({
        ({
        "少林广场","王府路","华藏庵","有所不为轩","紫霄宫大门",
        "天微堂","日月坪","大雪山山谷","六和塔","全真教大门", 
        "墓门","桃花山庄正厅","神龙教大厅","独尊厅","星宿海", 
        "雪山寺山门","一品堂大院","昆仑派山门","燕子坞","五指堂", 
        "朱雀外门","青龙外门","白虎外门","玄武外门","天安门",
        "扬州武馆","福威镖局","玄妙观","灵隐寺","泉州南门",
        "灵州南门","诸葛亮殿","烟雨楼","南阳城","佛山南门",                
        "蛇骨塔","长安乐坊","衡阳西街","喜州城","葛鲁城", 
        "伊犁","山海关","老龙头","长白天池","天山脚下",
        "丽春院","涌泉寺","听雨轩","五老峰","紫金城",
        "松风观","终南山脚","抱子岩","白马潭","升仙坊",                
        "嘉应门","玄妙观","峻极禅院","侠义厅","萧家桥", 
        "凌霄内门","凌霄殿","桃花江东","五毒教大门","天心岩",
        "嘉峪关","丝绸之路","长白天池","黑风口","龙门峰",
        "南城","土窑馆","萧然居"," 铁木真部落","铁木真营帐",
        "蒙古草原","回族部落","小溪流","鳌拜府","王府井大街",
        "塘沽口","汝州城"," 永定门","山贼窝","草莓地",
        "长安乐坊","十字街头","长安城西门","乐府诗社","浣花溪",
        "蓉城酒楼","金牛武馆","锦城驿","南诏德化碑","剑川镇",
        "玉虚观","星云湖畔","鲁望镇","喜州城","太和街口",
        "葛鲁城","圣湖","忘忧谷","大雪山北麓","华严顶",
        "凌云梯","十二盘","佛山镇街","英雄会馆","北帝庙",
        "福威镖局","榕城驿","向阳巷老宅","终南山主峰","寒水潭",
        "太湖","南浔镇","净慈寺","胡庆余堂","保淑塔",
        "风雷堂","圣姑堂","青龙堂大厅","成德殿","平定州",
        "见性峰","大字岭","悬空寺","衡阳西街","刘府大院",
        "玄坛庙","打谷场","群仙观","莲花峰","莎萝坪",
        "五佛寺","古浪","黄河帮寨门","黄土高原","青城",
        "悦来客栈","归来客栈","太和殿","泰和殿","养心殿",
        "天师洞","松风观","泉州南门","神龙教大厅","峻极禅院",
        "嵩岳寺塔","万景山庄","沧浪亭","紫金庵","寒山寺",
        "玉皇顶","岱宗坊","桃花轩","般若台","清都瑶池",
        "澜沧江畔","武当玄岳门","遇真宫","紫霄宫门","朝天宫",
        "观景楼","望云台","安抚使衙门","玄武门外门","朱雀门外门",
        "日月洞","逍遥洞","雪山祭坛","雪山寺山门","观星台",
        "燕子坞","听香水榭","扬州武馆","丽春院","草堂寺",
        "终南山脚","普光寺","重阳宫大门","祝融殿","福严寺",
        "缥缈峰山脚","独尊厅","琴心小筑","昆仑山门","迎风酒店",
        "五指堂","中指峰","无名峰","拇指峰","太白酒楼",
        "盛京城门","赵王府","冰火岛海滩","灵獒宫","巴颜喀拉山",
        "响琴榭","居庸关","星星峡","暖阁","皇宫正门",
        }),
        });
void create()
{
        set_name("任务使", ({ "renwu shi", "shi", "renwu"}));
        set("title", HIG"玩家帮派"NOR);
        set("gender", "男性" );
        set("age", 102);
        set("str", 50);
        set("int", 25);
        set("con", 30);
        set("dex", 30);
        set("per", 30);
        set("long", 
"一位的任务使。专门负责给本派弟子各种任务.\n");
        set("combat_exp", 50000000);
        set("shen_type", 1);

        set("attitude", "peaceful");
        set("max_qi", 35000);
        set("max_jing", 10000);
        set("neili", 55000);
        set("max_neili", 55000);
        set("jiali", 200);
        
        set_skill("force", 300);
        set_skill("zhemei-shou", 300);
        set_skill("unarmed", 500);
        set_skill("xiantian-qigong", 500);

         map_skill("unarmed","zhemei-shou");
       map_skill("force","xiantian-qigong");
        
        set("inquiry", ([
              "job"  : "本派弟子可以在我这用quest领任务啦，我不会为难你们的。\n",       
 	      "攻打门派"  : (: ask_jianxi :),
 	      "teamjob"  : (: ask_jianxi :),
]) );

        setup();
        carry_object("/clone/cloth/cloth")->wear();

}
void init()
{
        add_action("give_quest", "quest");
}


int give_quest()
{
        mapping quest,item,npc;
        object me;
        int j, combatexp, timep,factor,num;
        string room;
        string tag = "2000000";
        string *levels = ({
                        "10000",
                        "15000",
                        "20000",
                        "30000",
                        "50000",
                        "80000",
                        "100000",
                        "130000",
                        "170000",
                        "220000",
                        "300000",
                        "450000",
                        "600000",
                        "800000",
                        "1000000",
                        "2000000"
        });

        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
        
                        if(me->query_temp("jobitem"))
        {
tell_object(me,"\n任务使笑着说到，你先把刚才让你找的东西找到给人家吧....”\n");
             return 1;
        }
                if(me->query_temp("roomjob"))
        {
tell_object(me,"\n任务使笑着说到，你先把刺探任务做好吧....”\n");
             return 1;
        }
        
        if ((int)me->query_condition("roomjob")){message_vision("$N对着$n摇了摇头说：你刚接过刺探任务!等会再来!\n", this_object(), me);return 1;}

        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你办事不利,等会再来!\n", this_object(), me);
                      return 1;
            }
        if(combatexp<10000)
        {
tell_object(me,"\n任务使笑着说到，你的武功还不行....”\n");
             return 1;

        }

        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
tell_object(me,"任务使瞪了你一眼说道，我刚才要你找的东西呢？\n");
                   me->set_temp("menpaijob",0);
                   me->delete_temp("menpaijob");
                   return 0;
             }
             
        }


        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             if( atoi(levels[j])  <= combatexp )
             {
                   num=j;
                   factor=10;
                   break;
             }
        }
        if (num>0)
        {
             if (random(50)>45)
             {
                   num=num-1;
             }
        } 
        else
        {
             if ((num<sizeof(levels)-1)&&(random(100)>95))
             {
                   num=num+1;
                   factor=15;
             }
        }
        tag=levels[num];


        if (random(3) == 0)
        {
     quest = QUESTS_D(tag)->query_quest();
	}
       else
        if (random(3) == 1)
        {
     quest = QUESTH_D(tag)->query_quest();
	}
       else
        if (random(3) == 2)
        {
     quest = QUESTW_D(tag)->query_quest();
	}
       else
{
	  room=rooms[0][random(205)];
          me->apply_condition("roomjob",8);
	  me->set_temp("roomjob",room);
	  tell_object(me,HIG"我听说在『"HIR+room+HIG"』，发生了一些江湖事件。\n"+
           "你赶快去『"HIY+room+HIG"』刺探(citan)一下吧。\n"+
           "路上多加小心。\n"NOR);
return 1;
}

if (random(15)==0)
{
item  = QUESTW_D(tag)->query_quest();
npc = QUESTS_D(tag)->query_quest();
if (random(2)==1)
npc = QUESTH_D(tag)->query_quest();
me->set_temp("jobitem",item["quest"]);
me->set_temp("jobnpc",npc["quest"]);
me->apply_condition("roomjob",8);
tell_object(me,HIC"把『"HIG+item["quest"]+HIC"』找到，并交给『"HIG+npc["quest"]+HIC"』。\n" NOR);
return 1;
}

        timep = quest["time"];if (!quest["time"]) timep=400;

        time_period(timep, me);
        if(quest["quest_type"]=="杀")
             tell_object(me,"把『"HIR+quest["quest"]+HIC"』杀了，他对本派不利。\n" NOR);
        else
             tell_object(me,"找回『"HIG+quest["quest"]+HIC"』此物对本派有用。\n" NOR);
if (me->query_temp("menpaijob") < 0)
me->delete_temp("menpaijob");
me->add_temp("menpaijob",1);
if (me->query_temp("menpaijob") > 1)
tell_object(me,"你已经连续为本门做了『"HIC+me->query_temp("menpaijob")+NOR"』个任务了。\n" NOR);
if (me->query_temp("menpaijob") > 160)
{
tell_object(me,"你做的不错！你的江湖阅历增加了!\n" NOR);tell_object(me,"目前为止,你的门派贡献度为『"HIC+me->query("mpgx")+NOR"』。\n" NOR);me->add("mpgx",1);
me->add("score",200);
me->delete_temp("menpaijob");
}
             quest["time"]=300;
             quest["exp_bonus"]=200+(int)me->query_temp("menpaijob");
             quest["pot_bonus"]=140+me->query_temp("menpaijob")/2;
             quest["score"]=50;
        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me,HIC "任务使说道：请帮我在" + time + "内");
        return 1;
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score;
        string test;
        mapping quest;

        if (ob->query("money_id"))
        {
             if(!who->query("quest"))
             {
                  tell_object(who,"没找到？你真差劲，看来还是请别的弟子帮忙算了！\n");
                   return 1;
             }
       if ( ob->value() < 2000)
             {
tell_object(who,"任务使看了看$P交上来的钱说道，太少了，这么点你也好意思拿出手！\n");
                   return 1;
             }
             else
             {

tell_object(who,"任务使说道，好吧，这次就算了，下不为例。\n");
                   who->apply_condition("menpai_busy",3+random(4));who->delete_temp("menpaijob");
                   who->delete_temp("menpaijob");
                   who->set("quest",0);
                  return 1;
             }
        }
        if(!(quest = who->query("quest")))
        {
             tell_object(who,"任务使说道：你秀逗了，我要的不是这个。\n");
             return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
        tell_object(who,"任务使火冒三丈：这是什么？想鱼目浑珠呀，真是气死老夫了！\n");
        return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
             tell_object(who,"任务使说道：对不起，时间过了，别的弟子刚把货物接走了！\n");
             destruct(ob);
             return 0;
        }
        else
        {
             tell_object(who,"任务使高兴地说道：太好了！我就是要这个，你真有本事！\n");
             exp = 50 + random(100)+(int)who->query_temp("menpaijob")/2;
             pot = 20 + random(30)+(int)who->query_temp("menpaijob")/3;
             score = 2 + random(5);

             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
//             if( bonus > 300) bonus = 300;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->set("score", bonus);
             tell_object(who,HIW"恭喜你又完成一个任务！\n"NOR);
             tell_object(who,HIW"你被奖励了：" + chinese_number(exp)
               + "点实战经验，\n"+ chinese_number(pot) + "点潜能，\n"
               + chinese_number(score)+"点江湖阅历。\n"NOR);
             who->set("quest", 0 );
             who->start_busy(3);
             return 1;
}
        return 1;
}
void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say( "任务使狞笑着说：我是无敌不死版！\n");
	command("hehe");
}

void die()
{
	unconcious();
}
