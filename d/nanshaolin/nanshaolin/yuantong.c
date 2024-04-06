// yuantong.c
// Last Modified by winder on May. 29 2001

#include "yuan.h";
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("元痛", ({ "yuan tong", "tong", "yuan" }));
	set("long","他是一位胖大和尚，身穿一袭青布镶边袈裟。太阳穴微凸，双目炯炯有神。\n");
	set("nickname", "达摩院上座三僧");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 30);
	set("int", 20);
	set("con", 30);
	set("dex", 20);
	set("max_qi", 1500);
	set("max_jing", 600);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 50);
	set("combat_exp", 500000);
	set("score", 3000);
		set_skill("zhanzhuang-gong", 260);
	set_skill("shaolin-cuff", 260);
	set_skill("shaolin-leg", 260);
	set_skill("yiwei-dujiang", 260);
	set_skill("boluomi-hand", 260);
	set_skill("jingang-strike", 260);
	set_skill("wuxiang-finger", 260);
	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("yijinjing", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
// basic skill begin
	set_skill("hunyuan-yiqi", 100);
	set_skill("luohan-quan", 100);
	set_skill("sanhua-zhang", 100);
	set_skill("sanhua-zhang", 100);
	set_skill("ranmu-daofa", 100);
	set_skill("weituo-gun", 100);
// basic skill end
// 掌、指、鞭、杖
	set_skill("strike", 100);
	set_skill("finger", 100);
	set_skill("yizhi-chan", 100);
	set_skill("yizhi-chan", 100);
	set_skill("staff", 100);
	set_skill("wuchang-zhang", 100);
	set_skill("whip", 100);
	set_skill("riyue-bian", 100);
	set_skill("riyue-bian", 100);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "weituo-gun");
	map_skill("finger", "yizhi-chan");
	map_skill("staff", "wuchang-zhang");
	map_skill("whip", "riyue-bian");
	map_skill("parry", "wuchang-zhang");

	prepare_skill("strike", "weituo-gun");
	prepare_skill("finger", "yizhi-chan");

	create_family("南少林派", 20, "弟子");

	setup();
	carry_object(__DIR__"fangbianchan")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

int accept_object(object who, object ob,object me)
{
	mapping fam; 
	me=this_object();
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "南少林派")
	{
		command("hehe "+who->query("id"));
		command("say 你给我东西有什么企图？！");
		return 0;
	}
	if(!who->query_temp("lunzhi"))
	{
		command("say 你的令牌是那来的，轮值必须得到大苦大师的允许！");
		return 0;
	}
	if(ob->query("name")=="轮值令")
	{
		command( "say 好吧，你既然有大苦大师的令牌，你就在这和方通他们一起守卫吧。");
		who->apply_condition("sl_lunzhi",30);
		who->set_temp("lunzhied",1);
		return 1;
	}
	return 1;
}

void init()
{
	object ob;

	::init();
	add_action("do_nod", "nod");
}

