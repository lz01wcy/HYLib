// hezudao.c (kunlun)

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int do_work();
string ask_me();

void create()
{
	set_name("何足道", ({ "he zudao", "he" }));
	set("title", "昆仑派开山祖师");
	set("nickname", "昆仑三圣");
	set("long",
		"他就是昆仑派开山祖师，号称琴剑棋三绝的“昆仑三圣”。\n"
		"长脸深目，瘦骨棱棱，约莫三十岁左右年纪。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 77);
	set("int", 70);
	set("con", 70);
	set("dex", 78);

	set("max_qi", 24000);
	set("max_jing", 23000);
	set("neili", 45000);
	set("max_neili", 45000);
	set("jiali", 100);
	set("eff_jingli", 22000);
	set("jingli", 22000);
	set("combat_exp", 9500000);
	set("score", 400000);
	set_skill("art", 380);
	set_skill("goplaying", 380);
	set_skill("taxue-wuhen", 380);
	set_skill("luteplaying", 380);
        set_skill("literate", 300);
	set_skill("force", 250);
	set_skill("xuantian-wuji", 380);
	set_skill("dodge", 280);
	set_skill("kunlun-shenfa", 380);
	set_skill("strike", 380);
	set_skill("kunlun-zhang", 380);
set_skill("mantian-huayu", 380);
set_skill("qixian-jian", 380);
	set_skill("chuanyun-tui", 380);
	set_skill("zhentian-quan", 380);
	set_skill("parry", 250);
	set_skill("sword", 300);
        set_skill("cuff", 250);
	set_skill("leg", 250);

        set_skill("finger", 280);
	set_skill("hand", 250);
set_skill("qidao", 380);
set_skill("music", 380);

	set_skill("liangyi-jian", 380);
	set_skill("throwing", 380);
	set_skill("taiji-shengong", 180);
	map_skill("throwing", "mantian-huayu");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("strike", "kunlun-zhang");
	map_skill("parry", "qixian-jian");
	map_skill("parry", "art");
	map_skill("sword", "qixian-jian");
	//prepare_skill("strike", "kunlun-zhang");
	
	map_skill("finger", "qidao");
	map_skill("hand", "music");
	prepare_skill("finger", "qidao");
	prepare_skill("hand", "music");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "hand.gong" :),
                	(: perform_action, "hand.libie" :),
                 	(: perform_action, "hand.lv" :),
                (: perform_action, "finger.xb" :),                		
                (: perform_action, "strike.diezhang" :),
                	(: perform_action, "throwing.huayu" :),
                 	(: perform_action, "strike.liuyun" :),
                (: perform_action, "strike.yixing" :),                		
                (: command("unwield qin") :),
                (: command("wield qin") :),
                (: perform_action, "sword.ni" :),
                (: perform_action, "sword.shan" :),
                (: perform_action, "sword.yin" :),
                                (: perform_action, "sword.hebi ban" :),
            		(: command("perform sword.hebi ban") :),
                (: perform_action, "sword.zhu" :),
                (: perform_action, "parry.tianwaifeiyin" :),
        }) );
        set("inquiry", ([
                "弹琴" : (: ask_me :),
                "job" : (: ask_me :),
                ]));
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
	create_family("昆仑派", 1, "开山祖师");
//	set("class", "taoist");
	setup();
	carry_object("/d/kunlun/obj/jwqin.c")->wield();
  }

void attempt_apprentice(object ob)
{
                mapping skill;
		string *skl;
                int i;

//		if(ob->query("kar") < 20)
//		return;

//		if(ob->query_int() < 32 ) {
//		command("say 弹琴下棋需要灵性极高的人才可以领悟其真谛，不致与武功背道而驰。");
//		command("say "+RANK_D->query_respect(ob)+"还是先回去多读点书吧。");
//		return;
//	}
                if ((int)ob->query_skill("xuantian-wuji", 1) < 85) {
		command("say 琴棋书画虽为小技，但也需内力融入其中。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该先在玄天无极功上多下点功夫？");
		return;
	}

		if ((int)ob->query("max_neili", 1) < 500) {
		command("say 内力不够，一心二用则极容易走火入魔。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该先好好修炼内力？");
		return;
	}

//        	skill = ob->query_skills();
//		skl = keys(skill);
//		i = sizeof(skl);
//		while (i--) {
//              if (skill[skl[i]] < 80)
//                command("say " + RANK_D->query_respect(ob) + 
//		        "是否在" + 
//		        CHINESE_D->chinese(skl[i]) + 
//		        "上多下些功夫？");
//        	return;
//	}
	        
		command("say 看来你也是性情中人，我就教你一些琴剑棋的知识吧。");
		command("recruit "+ob->query("id"));

if (!ob->query("appren_hezudao"))
{
                ob->set("appren_hezudao", 1);
		ob->add("int", 1);
		ob->set_skill("art", ob->query_skill("literate"));
}
//		ob->set_skill("literate", 10 + ob->query_skill("literate", 1));
}

void init()
{
        add_action("do_work", "lianqin");
}

string ask_me()
{
        object me;
        me=this_player();

        if( strsrch(file_name(environment(me)), "/d/kunlun/jingshenfeng") == -1 )
                return "不是在惊神峰那里，风景不适合弹琴。";

        if (me->query("family/family_name")!="昆仑派")
                return "对不起，你问的问题我一点儿都听不懂。";
        if (me->query_temp("kl_working"))
                return "你不是在弹着吗！";

        me->set_temp("kl_working",random(20)+8);
        me->set_temp("kl_times",0);
        return HIC"好吧。我们就合奏一曲天外飞音吧。(lianqin)"NOR;
}

int do_work()
{
        object me, ob, weapon;
        me=this_player();


        if( strsrch(file_name(environment(me)), "/d/kunlun/jingshenfeng") == -1 )
                return notify_fail("不是在惊神峰那里，风景不适合弹琴。");
        if (me->query("family/family_name")!="昆仑派")
                return notify_fail("区区在下，怎么敢当啊！");
        if (!me->query_temp("kl_working"))
                return notify_fail("区区在下，怎么敢当啊！\n");

        if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

         tell_object(me, HIC"你在何足道的指导下摆出了一张古筝，近地而坐，静静地将一曲「天外飞音」弹了起来，一时间，万具晖音，周围的人都沉静在一片琴音之中！\n"NOR);

                        message_vision(HIC"$N只觉听得心旷神怡，无比舒坦......。\n"NOR, me);
                        me->add("jing",-10);
                        me->set_temp("kl_times",me->query_temp("kl_times")+1);
                        me->start_busy(1);

                if (me->query_temp("kl_times")>=me->query_temp("kl_working"))
                {
                        message_vision(HIC"何足道对$N微微一笑，满意地说：“不错，今天的琴就弹到这里吧。\n"NOR, me);
                        me->set_temp("kl_times",0);
                        me->set_temp("kl_working",0);
                        me->delete_temp("kl_times");
                        me->delete_temp("kl_working");

                        me->add("combat_exp", random(30)+26);
                        me->add("potential", random(20)+15);
                }
                return 1;
}
