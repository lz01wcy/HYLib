// linghu.c 令狐冲

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("令狐冲", ({ "ling huchong", "ling", "huchong" }));
	set("nickname", "大师兄");
	set("long", 
"令弧冲身材较瘦，长的浓眉阔眼，气宇暄昂，他在同门中排行老大，\n"
"是华山派年轻一代中的顶尖好手。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 12800);
	set("max_qi", 12800);
	set("jing", 11600);
	set("max_jing", 11600);
	set("neili", 12400);
	set("max_neili", 12400);
	set("jiali", 60);

	set("combat_exp", 1800000);
	set("score", 100000);
set_skill("chongling-jian", 380);
	set_skill("blade", 60);
	set_skill("cuff", 60);
	set_skill("feiyan-huixiang", 120);
	set_skill("hand", 60);
	set_skill("finger", 60);
	set_skill("strike",60);
	set_skill("claw", 60);
	set_skill("unarmed",125);
	set_skill("force", 150);
	set_skill("zixia-shengong", 320);
	set_skill("dodge", 180);
	set_skill("parry", 140);
	set_skill("sword", 190);
	set_skill("huashan-sword", 250);
	set_skill("lonely-sword",160);
	set_skill("literate", 80);
//	set_skill("chongling-jianfa", 60);

	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "huashan-sword");
	map_skill("sword", "chongling-jian");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
(: perform_action, "sword.ai" :),
(: perform_action, "sword.jianzhang" :),	
(: perform_action, "sword.jie" :),	
(: perform_action, "sword.jm" :),	
(: perform_action, "sword.wudui" :),				
        }) );
	create_family("华山派", 14, "弟子");

	set("inquiry", ([
		
		"风清扬" : "唉，已经很久没有见到他老人家了。你问这干嘛？\n",
		"任盈盈" : "你真有她的消息吗,说罢,以见他神情激动,好象眼睛红红的！\n",
	    		   	]));
	setup();	 	
	carry_object("/d/heimuya/npc/obj/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/heimuya/npc/obj/card2")->wear();
}


void init()

{
	object ob;
	ob = this_player();	
	::init();
	if( interactive(ob) && !is_fighting() )
	       {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("何日才能见道盈盈啊!" + RANK_D->query_respect(ob)
	  +"，你可有她的消息?\n");
}

int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

	if (  (string)ob->query("id") != "qing xin")
		    return notify_fail("令狐冲不需要这件东西。\n");
       say( "令狐冲双手捧着任盈盈的信，泪如雨下, 这块白虎堂令牌你拿去还给盈盈,
告诉她我就去找她!\n" );
	obn = new("/d/heimuya/npc/obj/card2");
    obn->set_amount(1);
	obn->move(who);
    destruct(obn);
    set_temp("card2",0);
    return 1;
}




void attempt_apprentice(object ob)
{
	int student_num;
	string temp, line;
	mapping myfam;

	temp = read_file("/kungfu/class/huashan/FENG", 1, 1);
	student_num = atoi(temp);

	line = "风清扬现在共有" + temp + "个徒弟。\n";
	write(line);

	if ((int)ob->query("shen") < 0) {
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	if ((int)ob->query_int() < 25) {
		command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我华山派武功？");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
		ob->set("class", "swordsman");

	        myfam = (mapping)ob->query("family");
 		if( (myfam["master_id"] == "feng qingyang") || (myfam["master_name"] == "风清扬"))
		{
			temp = read_file("/kungfu/class/huashan/FENG", 1, 1);
			student_num = atoi(temp);
			if(student_num == 1)
				temp = "0";
			else if(student_num == 2)
				temp = "1";
			else if(student_num == 3)
				temp = "2";
			write_file("/kungfu/class/huashan/FENG", temp, 1);
			line = "风清扬现在共有" + temp + "个徒弟。\n";
			write(line);
		}
   return;
}
