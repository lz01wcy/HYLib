// bing.c 官兵

inherit NPC;

void create()
{
	set_name("官兵", ({ "guan bing", "bing" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "虽然官兵的武艺不能和武林人士相比，可是他们讲究的是人多力量大。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 310000);
	set("shen_type", 1);

    set("max_neili",5500);
    set("neili",5500);
    set("qi",5500);
    set("eff_qi",5500);
    set("max_qi",5500);

    set("jing",5500);
    set("eff_jing",5500);
    set("max_jing",5500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 180+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );


//	if (random(2) == 1) {
//		set("chat_chance", 10);
//		set("chat_msg", ({
//			(: random_move :),
//		}));
//	}

        set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"官兵喝道：大胆刁民，竟敢造反不成？\n",
		"官兵喝道：跑得了和尚跑不了庙，你还是快快束手就擒！\n",
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
	}));
	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/junfu")->wear();
	carry_object(__DIR__"obj/jitui")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
//	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}
