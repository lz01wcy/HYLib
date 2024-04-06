// shaqianli.c
// 沙千里
// amber
#include <ansi.h>
inherit NPC;
string ask_job();
int do_task(string arg);

void create()
{
        set_name("沙千里", ({ "sha qianli", "sha" }));
        set("nickname", HIG "黑龙" NOR);
        set("long",@LONG
他就是五毒教的护法弟子沙千里，身材魁梧，方面大耳。在教中转管招募
教众，教授弟子们的入门功夫。
LONG
        );
        set("title","五毒教护法弟子");
        set("gender", "男性");
        set("age", 32);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 11000);
        set("max_jing", 11000);
        set("neili", 11000);
        set("max_neili", 11000);
        set("jiali", 40);
        set("combat_exp", 1200000);
        set("score", 5000);

        set_skill("force", 170);
        set_skill("wudu-shengong", 180);
        set_skill("dodge", 170);
        set_skill("wudu-yanluobu", 180);
        set_skill("unarmed", 80);
        set_skill("qianzhu-wandushou", 180);
        set_skill("parry", 180);
        set_skill("sword", 170);
        set_skill("wudu-goufa", 180);
        set_skill("poison", 180);
        set_skill("literate", 160);
	set_skill("shedu-qiqiao",180);
	set_skill("finger",180);
//        set_skill("hammer", 60);
//        set_skill("jinshe-chui", 70 );
//      set_skill("strike", 200 );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
	map_skill("poison","shedu-qiqiao");
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
//        map_skill("hammer", "jinshe-chui");

        create_family("五毒教", 13, "护法弟子");

        setup();
        set("inquiry", ([
                        "巡山" : (: ask_job :),
                       ]));

        carry_object("/d/wudujiao/obj/ganggou")->wield();
        carry_object("/d/city/obj/cloth")->wear();

        add_money("silver",10);
}

void attempt_apprentice(object ob)
{

                  if ((string)ob->query("gender") == "无性") {
                                 command("say 这位公公不要开玩笑了。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是快去伺候皇上吧！");
                return;
                  }

                  if ((int)ob->query("shen") > 1000) {
                                 command("say 做我五毒教弟子必须心狠手辣。");
                command("say 我教弟子贵在随心所欲，不收伪君子");
                return;
                  }


//          command("chat 嘿嘿嘿嘿！！！！！");
//          command("chat 该当我五毒教发扬光大，称霸武林指日可待了。");
//          command("chat 嘿嘿嘿嘿！！！！！");
        command("recruit " + ob->query("id"));
        ob->set("class", "none");
         ob->set("title","五毒教徒");
}


void init()
{
        add_action("do_task","task");
}


string ask_job()
{
        mapping fam;

        object me;
        object ob;
        ob=this_player();
        me=this_object();
 if (!(fam = this_player()->query("family"))
                 || fam["family_name"] != "五毒教")
                                         return RANK_D->query_respect(this_player()) +
                "，你不是五毒教的弟子，此话从何说起？";
        if (ob->query_temp("xunshan"))
                return ("你不是已经领了巡山的任务吗？还不快去做。\n");
        if (ob->query("combat_exp")<5000)
                return ("你武功太低，无法胜任!。\n");
        if (ob->query("combat_exp")>=100000)
        return ("我看你的武功已有相当的功底了，就不用在我这里干事了，去找岑其斯和潘秀达吧。\n");
        ob->set_temp("xunshan",1);
             ob->apply_condition("wudu_xunshan2",random(6)+9);;
        return "好吧，你就在本教周围四处查看一下，巡山时应当小心防范，防止外敌。";
}

int do_task(string arg)
{
        object ob,me;
        int pot,exp,sco,sil;
        ob=this_player();
        me=this_object();
        if(!(arg||arg=="ok")) return 0;
    if(!ob->query_temp("xunshan")) 
            return notify_fail("你没巡山跑来领什么功？\n");
    if (interactive(ob)&&(int)ob->query_condition("wudu_xunshan2")) {
                 command("angry "+ob->query("id"));
                 return notify_fail(RED "你这么快回来了，是不是有些地方只是马马虎虎看看？\n"NOR);
                 }          
        if(!(ob->query_temp("wudu_xs/huayuan1")
&&ob->query_temp("wudu_xs/huayuan2")&&ob->query_temp("wudu_xs/huayuan3")))
            return notify_fail("你是不是偷懒，花园漏了些地方没巡？ \n");
        if(!(ob->query_temp("wudu_xs/huating1")
&&ob->query_temp("wudu_xs/huating2")&&ob->query_temp("wudu_xs/huating3")))
            return notify_fail("你是不是偷懒，花厅漏了些地方没巡？ \n");
        if(!(ob->query_temp("wudu_xs/beiyuan")
&&ob->query_temp("wudu_xs/chufang")&&ob->query_temp("wudu_xs/bingqi")))
            return notify_fail("你是不是偷懒，北院漏了些地方没巡? \n");
        if(!(ob->query_temp("wudu_xs/damen")
&&ob->query_temp("wudu_xs/jingshi")&&ob->query_temp("wudu_xs/shufang")        
&&ob->query_temp("wudu_xs/lianwu")&&ob->query_temp("wudu_xs/dating")))
            return notify_fail("你是不是偷懒，大门漏了些地方没巡? \n");    
        if(!(ob->query_temp("wudu_xs/nanyuan")
&&ob->query_temp("wudu_xs/liandu")&&ob->query_temp("wudu_xs/xiangfang")
&&ob->query_temp("wudu_xs/yaoshi")))
            return notify_fail("你是不是偷懒，南院漏了些地方没巡? \n");    
        if(arg=="ok")
        {
                command("pat "+ob->query("id"));
                command("say 哈哈，真难为你了，"+RANK_D->query_respect(ob)+"，你做得好！");
        sil=(int)(ob->query_skill("force",1)/10)+random(5);
             pot=30+random(50);
             sco=30+random(50);
            exp=random(50)+random(100);
        me->add_money("silver",sil);
        command("give "+ob->query("id")+" "+sil+" silver");
              ob->add("potential",pot);
              ob->add("combat_exp",exp);
              ob->add("wudu_job",1);
                          tell_object(ob,HIW" 你被奖励了：\n" + 
                       chinese_number(exp) + "点实战经验\n" +
                       chinese_number(pot) + "点潜能\n"+
                       chinese_number(sil)+"两白银\n"+
                       "你为五毒教做了"+ob->query("wudu_job")+"次工作。\n"
                       NOR);
                      ob->delete_temp("xunshan");
              ob->delete_temp("wudu_xs");
                return 1;
        }
        return 1;
}

