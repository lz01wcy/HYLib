
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("龙三爷", ({ "long sanye", "long", "sanye" }));
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 60);
	set("long",
		"他身穿绸袍，头带锦帽，一看就是个富贵之人。\n");
	set_skill("cuff", 40);
	set_skill("dodge", 40);
	set_temp("apply/damage", 80);

	set("combat_exp", 25000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/tanggu/obj/fengcai",
		"/d/tanggu/obj/jinfo",
		"/d/tanggu/obj/yinpan",
	}));

	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
