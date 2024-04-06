//li.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void greeting(object);
void init();
void create()
{
	set_name("李教头", ({ "li"}) );
	set("gender", "男性" );
	set("age", 25);
	set("long", "这是个和蔼可亲的教头。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 400);
	set("max_jing", 500);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 1850000);
	set("score", 20000);

	set_skill("force", 180);
	set_skill("dodge", 190);
	set_skill("unarmed", 190);
	set_skill("parry", 180);
	set_skill("staff",180);
	
	set_skill("hamagong",170);
	set_skill("chanchu-bufa", 180);
	set_skill("lingshe-zhangfa", 180);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "reserve" :),
                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shoot" :),
                (: perform_action, "staff.saoluoye" :),
                (: command("unwield shengzhang") :),
                (: command("unwield shengzhang") :),
                (: command("wield shengzhang") :),
                (: command("wield shengzhang") :),
                (: perform_action, "strike.hama" :),                
                (: perform_action, "strike.hama" :),                
                (: perform_action, "hand.diaoshou" :),                
                (: perform_action, "hand.diaoshou" :),                
        }) );
	create_family("白驼山派",2,"弟子");

	set("chat_chance", 2);
	set("chat_msg", ({
		"李教头说道: 勤学苦练方可出神功..\n",
		"李教头鼓励小弟子们不畏艰苦，好好练功。\n",
		"李教头拍拍学徒的头说：好样的！\n",
	}) );
	setup();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "白驼山派")
	     {
	       message_vision("李教头冲着$N点点头，微微笑了笑。\n",ob);
	       return;
	      }
	if (!(string)ob->query("family/family_name"))
	     {
	       message_vision("李教头冲着$N微笑说：你是来拜师的吧，拜我吧。\n",ob);
	       return;
	      }
	  message_vision("李教头对$N嚷道:小家伙,你瞎逛什么呢?\n",ob);
}

void attempt_apprentice(object ob)
{
     command("say 好吧，我收下你。\n");
     command("recruit "+ob->query("id"));
     if((int)ob->query("combat_exp")<10000)
       command("say 你先到东边练功室找陪练童子比划几招吧。\n");
     return;
}

int accept_fight(object ob)
{
      if ((string)ob->query("family/family_name") == "白驼山派")
	 {
	  if((int)ob->query("combat_exp")<1000)
	    return notify_fail("李教头笑道：你的经验太低了，还是先找陪练童子比划几招吧。！\n");
	  }
    return 1;
}
