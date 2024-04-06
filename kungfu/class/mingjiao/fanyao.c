// FanYao.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_me();

void create()
{
	set_name("范遥", ({"fan yao","fan","yao",}));
	set("long",
        "他是一位带发修行的头陀，身穿白布长袍。\n"
        "他的脸上七七八八的全是伤疤，简直看不出本来面目了。\n"
	);

	set("title",HIG "明教" HIR "光明右使" NOR);
	set("level",11);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 38);
	set("shen_type", 1);
	set("per", 12);
	set("str", 50);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 13500);
	set("max_jing", 11500);
	set("neili", 13000);
	set("max_neili", 13000);
	set("jiali", 150);
	set("combat_exp", 6000000);
	set("score", 800000);
    set_skill("cuff", 100);
    set_skill("strike", 100);
    set_skill("qingfu-shenfa", 200);
    set_skill("hanbing-mianzhang", 100);
    set_skill("sougu", 300);
	set_skill("force", 180);
	set_skill("jiuyang-shengong", 180);
	set_skill("dodge", 180);
	set_skill("lingxu-bu", 180);
	set_skill("finger", 180);
	set_skill("strike", 180);
	set_skill("hand", 180);
	set_skill("claw", 180);
	set_skill("parry", 180);
	set_skill("blade", 180);
	set_skill("jinwu-daofa", 280);
	set_skill("nianhua-zhi", 280);
	set_skill("sanhua-zhang", 280);
	set_skill("fengyun-shou", 280);
	set_skill("longzhua-gong", 280);
	set_skill("buddhism", 100);
	set_skill("literate", 110);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "lingxu-bu");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("blade", "jinwu-daofa");
	map_skill("parry", "nianhua-zhi");

	set("inquiry", ([
		"光明圣火阵"  : (: ask_me :),
		"明教圣火阵"  : (: ask_me :),
		"圣火阵"      : (: ask_me :)
	]));

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: prepare_skill("finger", "nianhua-zhi") :),
		(: prepare_skill("strike", "sanhua-zhang") :),
	}) );
	create_family("明教",34, "光明右使");
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 660);
	set_temp("apply/armor", 660);
	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

void attempt_apprentice(object ob)
{
	command("say 我不收徒的，你找各位法王去。");
	return 0;
}

#include "fanyao.h"
