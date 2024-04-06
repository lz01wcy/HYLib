//LUCAS 2000-6-18
#include <ansi.h>
inherit NPC;

inherit F_MASTER;
int ask_fail();
string  ask_job();

string ask_jianxi();
string ask_finish();
mixed names = ({
        ({
        "山崖","冰梯","分天崖","雪山温泉","天风川",
        "山路","凌霄内门","冰雪轩","冰道","城头",
        "花径","练武厅","凌霄殿","副殿","云海石",                
        "戏梅亭","冰车","监狱小厅","中庭","飞花阁", 
        "后园","风火居","气寒轩","走廊","小桥",
        "威德居","城外","木屋","石崖客栈","梅道",
        }),
        ({
         "宋兵","偏将","裨将","佐将","小贩","男孩","郭芙","老先生",
		 "小孩","书店老板","武三通","穷汉","铁匠","朱子柳","店小二","宋兵",
		 "静玄师太","静照师太","宋远桥","莫声谷","陆乘风","韩宝驹","黄药师","余沧海",
		 "殷野王","胡青牛","尹志平","小龙女","刘承风","欧阳锋","白衣少女","九翼道人",
		 "阿紫","玉磬子","玉音子","岳夫人","岳不群","令狐冲","玄苦大师","清善比丘",
		 "独臂神尼","庄夫人","双儿","吴六奇","木婉清","萧远山","李沅芷","向问天",
		 "曲洋","黑白子","程瑶迦","程瑶迦","沐剑屏","天柏道人","本尘","本观",
		 "天山童姥","韦一笑","谢逊","澄坚","陆乘风","张翠山","宋青书","玄贞道长",
		 "石破天","苏星河","逍遥子","朱丹臣","简长老","封不平",
        }),
        });

void create()
{
        set_name("白万剑",({"bai wanjian","bai"}));
        set("nickname", HIC"气寒西北"NOR);
        set("gender", "男性");
        set("age", 30);
        set("long", 
               "白万剑是雪山派掌门人威德先生白自在的长子，他\n"
                "们师兄弟均以“万”字排行，他名字居然叫到白万剑,\n"
                "足见剑法之高.他外号气寒西北,与‘风火神龙’封万\n"
                "里合称‘雪山双杰’。\n");
        set("attitude", "peaceful");

        set("str", 50);
        set("con", 50);
        set("int", 50);
        set("dex", 50);
        set("per", 50);
        set("neili", 33000);
        set("max_neili", 33000);
        set("jing", 18000);
        set("max_jing", 18000);
        set("qi", 18000);
        set("max_qi", 18000);
        set("jiali", 100);

        set("combat_exp", 7500000);
        set("score", 50000);
        set("inquiry", ([
            "白自在"   : "老爷子的台炜是你叫的吗!。",
            "老爷子"   : "你想拜见老爷子吗？但他闭关面壁,你得找成师叔要到玉牌,才能见到他。",
            "掌门"   : 
     "你想拜见老爷子吗？但他闭关面壁,你得找成师叔要到玉牌,才能见到他。",
            "玉牌"   : "寒玉牌乃我门中重宝,只有凭它,才能进入监狱。",
   	    "任务"  : (: ask_jianxi :),
	    "job"  : (: ask_jianxi :),
   	    "护卫"  : (: ask_job :),
	    "huweijob"  : (: ask_job :),
            "huweifail" : (: ask_fail() :),
            "护卫失败" : (: ask_fail() :),
   	    "完成"  : (: ask_finish :),
	    "finish"  : (: ask_finish :),

        ]));
        set("shen_type", 1);


        set_skill("unarmed", 280);
        set_skill("sword", 280);
        set_skill("force", 230);
        set_skill("parry", 230);
        set_skill("dodge", 230);
        set_skill("literate", 180);

        set_skill("xueshan-sword", 320);
        set_skill("bingxue-xinfa", 320);
        set_skill("snow-zhang", 300);
        set_skill("snowstep", 300);
        set_skill("doom-hand", 300);
        set_skill("hanshan-strike", 300);
        set_skill("snowwhip", 300);
        set_skill("hand", 250);
        set_skill("whip", 250);
         set_skill("strike", 280);
        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        map_skill("strike", "hanshan-strike");
        map_skill("hand", "doom-hand");
	prepare_skill("strike", "hanshan-strike");
	prepare_skill("hand", "doom-hand");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengxue" :),
                (: perform_action, "sword.wanmei" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "dodge.snowfly" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.zhe" :),
                (: perform_action, "unarmed.lang" :),
                (: perform_action, "strike.zhangjian" :),
                (: perform_action, "strike.siji" :),
	               (: perform_action, "hand.hantian" :),                		
                (: exert_function, "powerup" :),
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("凌霄城", 6, "弟子");
        setup();

        
        carry_object("/clone/money/gold.c");
        carry_object("/d/lingxiao/obj/baihongjian.c")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    if (ob->query_int() < 28) {
        command("say 你这种资质,怎能跟我学剑！");
                return;
    }
    if ((int)ob->query_skill("bingxue-xinfa",1) < 60 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
                return;
    } 
    if ((int)ob->query_skill("xueshan-sword",1) < 80 ) { 
        command("say 你的本门剑法太低了,还是先找你原来的师父提高吧!"); 
                return;
        }
    if ((int)ob->query_skill("sword",1) < 80 ) {  
        command("say 你的基本剑法太低了,还是先提高基本功吧!"); 
                return; 
    }
    if ((int)ob->query("shen") < 20000 ) {
         command("say 学剑须先正身，你做到了吗?"); 
                return;
    } 

    command("say 很好，很好。");
    command("recruit " + ob->query("id"));
} 

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) 
        ob->set("title", "凌霄城第七代弟子"); 
}

string ask_jianxi()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "凌霄城")
           {
                      message_vision("$N对着$n大喝一声：本派弟子才能做任务。你是哪来的？\n", this_object(), ob);
                      return  "快走。";
            }

    if ((int)ob->query_skill("bingxue-xinfa",1) < 30 ) {
                      message_vision("$N对着$n大喝一声：你的本门内功太低了？\n", this_object(), ob);
                      return  "快走。";
    } 


if ((int)ob->query_condition("guojob2_busy"))
        return  "你刚接过任务，等会再来。";
     if(ob->query_condition("lingxiao_busy"))
        return  "你刚接过任务，等会再来。";

	  if(ob->query("combat_exp")<10000)
      return  "你的功夫太差了。";
            if(ob->query_temp("lingxiao"))
      return  "你不是正在干活啊!";

	  where=names[0][random(30)];
	  ob->set_temp("lingxiao",1);
	  ob->set_temp("lingxiaojob",where);
          ob->apply_condition("lingxiao_busy",8);
if (!ob->query_skill("bingxue-xinfa",1))
{
ob->apply_condition("lingxiao_busy",9);
}
          obn=new(__DIR__"saozhou");
          obn->move(ob);
	  return    WHT"我刚得到消息，外面雪下的太大，把路给堵了。\n"+
           "          你赶快去"+where+"扫一下雪吧(saoxue)。\n"+
           "          可能有别的门派的人来挑兴，多加小心。"NOR; 
}

string ask_finish()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
      if(!ob->query_temp("lingxiao"))
      return  "我没叫你干过活啊!";

	  if(!ob->query_temp("lingxiaook"))
      return  "你的活没干完啊!";
        ob->delete_temp("lingxiao");
        ob->delete_temp("lingxiaojob");
        ob->delete_temp("lingxiaook");
        ob->add("combat_exp",50+random(150));
        ob->add("potential",25+random(100));
	  return    HIW"做得好，。\n"+
           "          我指点你二手功夫吧。\n"+
           "          你的经验和潜能增加了!"NOR; 
}


string ask_job()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "凌霄城")
           {
                      message_vision("$N对着$n大喝一声：本派弟子才能做任务。你是哪来的？\n", this_object(), ob);
                      return  "快走。";
            }

    if ((int)ob->query_skill("bingxue-xinfa",1) < 30 ) {
                      message_vision("$N对着$n大喝一声：你的本门内功太低了？\n", this_object(), ob);
                      return  "快走。";
    } 

if ((int)ob->query_condition("guojob2_busy"))
        return  "你刚接过任务，等会再来。";
     if(ob->query_condition("lingxiao2_busy"))
        return  "你刚接过任务，等会再来。";


     if(ob->query("combat_exp")<100000)
      return  "你的功夫太差了。";
        if (ob->query_temp("lxhw")) {
                command("kick " + ob->query("id"));
      return  "我不是给了你任务了吗？";
                }
        if (ob->query_temp("lxhwjob")) {
                command("kick " + ob->query("id"));
      return  "我不是给了你任务了吗？";
                }
      
	  where=names[0][random(30)];
	  ob->set_temp("lxhw",1);
	  ob->set_temp("lxhwjob",where);
          ob->apply_condition("lingxiao2_busy",22);
if (!ob->query_skill("bingxue-xinfa",1))
{
ob->apply_condition("lingxiao2_busy",25);
}
          obn=new(__DIR__"ling");
          obn->set("usename",ob->query("name"));
          obn->move(ob);
	  return    RED"我刚得到消息，所谓的名门正派，来了几个人挑战我派。\n"+
           "          你赶快去"+where+"护卫一下吧(huwei)。\n"+
           "          如果真的有人来挑战，消灭他们。"NOR; 
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query_temp("lxhwjob")) {
                command("sigh");
                command("say 这么点事，你都做不好，也罢，你去吧.");
          me->apply_condition("lingxiao2_busy",32);
       destruct(present("lx lingpai",me));
       me->delete_temp("lxjob");
        me->delete_temp("lxhw");
        me->delete_temp("lxhwjob");
        return 1;
                }
}

