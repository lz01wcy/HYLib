// wangjiaju.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("王家驹", ({ "wang jiaju", "wang", "jiaju" }) );
	set("title", HIY"金刀门"NOR"第五代弟子");
	set("gender", "男性" );
	set("shen_type", 1);
	set("age", 15);
	set("per", 15);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	set("long",
"他是王仲强的小儿子，武功不过尔尔。不过在洛阳城中，教训起地痞流氓
来，那倒是够了。\n" );
	set("combat_exp", 150000);
	set("attitude", "friendly");
	set_skill("blade", 120);
	set_skill("dodge", 120);
	set_skill("unarmed", 120);
	set_skill("jinwu-daofa", 120);
	set_skill("yanfly", 120);
	set_skill("parry", 120);
	map_skill("blade", "jinwu-daofa");
	map_skill("parry", "jinwu-daofa");
	map_skill("dodge", "yanfly");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 1);
}

