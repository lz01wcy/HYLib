// wu-changfeng.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("吴长风", ({"wu changfeng", "wu", "changfeng"}));
	set("nickname", "丐帮六老");
	set("gender", "男性");
	set("age", 50);
	set("long","他是一个红脸老者，手中拿的是一把鬼头刀，背厚刃薄，刀身甚长。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 9000);
	set("max_qi", 9000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1300);
	set("max_neili", 1200);
	set("jiali", 100);
	
	set("combat_exp", 1000000);
	set("score", 20000);
	
	set_skill("force", 90); // 基本内功
	set_skill("huntian-qigong", 90); // 混天气功
	set_skill("blade", 200); // 基本刀法
	set_skill("liuhe-dao", 200); // 四象六合刀
	set_skill("hand", 85); // 基本手法

	set_skill("dodge", 95); // 基本躲闪
	set_skill("xiaoyaoyou", 85); // 逍遥游
	set_skill("parry", 90); // 基本招架
	set_skill("strike",85);  // 基本掌法
	set_skill("xianglong-zhang",185);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "liuhe-blade");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");

	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", RED"九袋长老"NOR);
	set("party/level", 9);
	create_family("丐帮", 10, "弟子");

	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/guitou-blade")->wield();
}

void attempt_apprentice(object ob)
{
	command("say 老夫不收徒弟，" + RANK_D->query_respect(ob) + "还是请回吧。");
}
#include "/kungfu/class/gaibang/gaibang.h"
