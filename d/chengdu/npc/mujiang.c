// mujiang.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("张木匠", ({ "zhang mujiang", "mujiang", "zhang" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 43);
	set("long", "他是个手艺高超的木匠，据说他在为少林做事。\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");
	set("inquiry", ([
		"name": "小人姓张，在成都也算一个好手艺人。",
		"木人": "说到木人嘛，那可是大半生研究的成果哦。",
		"陈麻婆": "她....我暗恋了她大半辈子，但是.......",
	]));

	setup();
	carry_object(__DIR__"obj/cloth/cloth")->wear();
	carry_object(__DIR__"obj/cloth/male-shoe")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

