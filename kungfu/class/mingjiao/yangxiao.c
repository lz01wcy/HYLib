// YangXiao.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_me();
string ask_ling();

void create()
{
	set_name("杨逍", ({"yang xiao","yang","xiao",}));
	set("long",
        "他是一位中年书生，身穿白布长袍。\n"
        "他相貌俊雅，只是双眉略向下垂，嘴边露出几条深深的皱纹，不免略带衰老凄苦\n"
        "之相。他不言不动，神色漠然，似乎心驰远方，正在想什么事情。\n"
	);

	set("title",HIG "明教" HIR "光明左使" NOR);
	set("level",11);
	set("gender", "男性");
	set("attitude", "peaceful");
	
	set("age", 42);
	set("shen_type", 1);
	set("per", 29);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 13500);
	set("max_jing", 11500);
	set("neili", 23000);
	set("max_neili", 23000);
	set("jiali", 150);
	set("combat_exp", 2000000);
	set("score", 800000);
    set_skill("cuff", 100);
    set_skill("strike", 100);
    set_skill("qingfu-shenfa", 100);
    set_skill("hanbing-mianzhang", 100);
    set_skill("sougu", 100);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("blade", 180);
	set_skill("sword", 180);
	set_skill("blade", 180);
	set_skill("jinwu-daofa", 180);
	set_skill("literate", 110);

	set_skill("jiuyang-shengong", 180);
	set_skill("qiankun-danuoyi", 80);
	set_skill("lingxu-bu", 180);
	set_skill("nianhua-zhi", 380);
	set_skill("sanhua-zhang", 380);
	set_skill("fengyun-shou", 180);
	set_skill("longzhua-gong", 180);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "lingxu-bu");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "qiankun-danuoyi");
	map_skill("blade", "jinwu-daofa");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 660);
	set_temp("apply/armor", 660);
	set("inquiry", 
	([
		"光明圣火阵"  : (: ask_me :),
		"明教圣火阵"  : (: ask_me :),
		"圣火阵"      : (: ask_me :),
		"铁焰令"      : (: ask_ling :)
	]));

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform qianlibingfeng") :),
	}) );
	create_family("明教",34, "光明左使");
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

string ask_ling()
{
	mapping party, skl; 
	string *sname;
	object ob;
	int i;
	
	if ( !(party = this_player()->query("party")) || party["party_name"] != HIG "明教" NOR )
		return RANK_D->query_respect(this_player()) + "与本教素无来往，不知此话从何谈起？";

	skl = this_player()->query_skills();
	sname  = sort_array( keys(skl), (: strcmp :) );

	for(i=0; i<sizeof(skl); i++) 
	{
		if (skl[sname[i]] < 30) 
		return RANK_D->query_respect(this_player()) + 
		"功力不够，不能领取铁焰令。";
	}

	ob = new("d/mingjiao/obj/tieyanling");
	ob->move(this_player());
	message_vision("$N要得一面铁焰令。\n",this_player());

	return "好吧，凭这面铁焰令，你可自由向你的尊长挑战。";

}

#include "yangxiao.h"
