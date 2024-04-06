// Obj: /d/nanshaolin/obj/juechan.c
// Last Modified by winder on May. 29 2001
inherit NPC;

void create()
{
	set_name("觉禅石人", ({ "juechan shiren", "juechan", "shiren" }));
	set("long", "年代久远已无法看清他当年之相貌，\n"
		"他身材中等，周身棱角分明，便如刀削斧刻一般。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("age", 100);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1200);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 1200000);
	set("score", 200);
	set_skill("force", 140);
	set_skill("yijinjing",140);
	set_skill("yizhi-chan", 140);
	set_skill("dodge", 140);
	set_skill("shaolin-shenfa", 140);
	set_skill("finger", 140);
	set_skill("parry", 140);
	set_skill("buddhism", 140);
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "yizhi-chan");
	map_skill("parry", "yizhi-chan");
	prepare_skill("finger", "yizhi-chan");
	setup();
}
#include "chan.h"
