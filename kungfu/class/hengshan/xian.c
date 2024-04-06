// Last Modified by Sir on May. 22 2001
// xian.c
inherit NPC;
inherit F_MASTER;

#include <command.h>
#include <ansi.h>
string ask_for_join();
string ask_me();
string ask_yao();
void create()
{
	set_name("定闲师太", ({ "dingxian shitai", "shitai", "dingxian" }) );
	set("long", "她就是恒山派的定闲师太，她身材瘦高，慈眉善目，\n"
		"是现任恒山派掌门人。\n");
	set("gender", "女性");
	set("title", HIB"恒山派第十三代掌门"NOR);
	set("class", "bonze");
	set("age", 45);
	set("attitude", "peaceful");
	set("per", 24);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("inquiry",([
		"剃度"  : "贫尼不剃度弟子。",
		"出家"  : "贫尼不剃度弟子。",
		"还俗"  : "恒山弟子，不能还俗。",
		"白云熊胆丸" : (: ask_yao :),
		"秘籍"	 : (: ask_me :),
		"天长掌法谱" : (: ask_me :),
	]));	
	set("no_get",1);
	
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: perform_action, "sword.yuyin" :),
		(: perform_action, "sword.shenfeng" :),	
		(: perform_action, "sword.liuyun" :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: perform_action, "hand.break" :),
		(: perform_action, "strike.diezhang" :),
	}));


	set("max_qi", 24000);
	set("max_jing", 22000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("jiali",100);
	set("jingli", 1500);
	set("max_jingli", 1500);
	set("combat_exp", 9000000);
	set("score", 1000);
	set("book_count", 1);
	set("yao_count", 1);
	
	set_skill("unarmed", 200);
	set_skill("sword", 300);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 300);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("buddhism", 350);
	set_skill("medicine", 380);
	set_skill("goplaying", 380);
	set_skill("baiyun-xinfa",380);	
	set_skill("hengshan-jian", 380);
	set_skill("chuanyun-shou",380);
	set_skill("tianchang-zhang",380); 
	set_skill("lingxu-bu", 380);
	set_skill("literate", 150);
	
	map_skill("force","baiyun-xinfa");
	map_skill("sword", "hengshan-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	map_skill("parry", "hengshan-jian");
	map_skill("dodge", "lingxu-bu");

	prepare_skill("hand", "chuanyun-shou");
	prepare_skill("strike", "tianchang-zhang");
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	create_family("恒山派", 13, "掌门");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	string name, new_name;

	if ((string)ob->query("class")!="bonze" )
	{
		command ("say 阿弥陀佛！贫尼不收俗家弟子。");
		return;
	}
	
	if ((int)ob->query_skill("baiyun-xinfa",1) < 90 )
	{
		command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
		return;
	}
	if ((int)ob->query("shen")<100000) 
	{
		command( "say 你若能多为侠义之举，当能承我衣钵。\n");
		return;
	}
	command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
	command("say 希望你能努力行善，济度众生，以光大我恒山派。");
	command("recruit " + ob->query("id"));
	name = ob->query("name");
	new_name = "仪" + name[2..3];
	command("say 从今以后你的法名叫做" + new_name + "。");	
	ob->set("name", new_name);
}


string ask_me()
{
	object ob;
	
	if (this_player()->query("family/family_name")!="恒山派")
		return RANK_D->query_respect(this_player()) +
		"与本派毫无瓜葛，我派的武功典籍可不能交给你。";
	if (query("book_count") < 1)
		return "你来晚了，本派的秘籍不在此处。";
	add("book_count", -1);
	ob = new(__DIR__"tianchang-zhangpu");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到天长掌法谱啦。\n");
	return "好吧，这本「天长掌法谱」你拿回去好好钻研。";
}
string ask_yao()
{
	object ob;
	
	if (this_player()->query("family/master_id")!="dingxian shitai")
		return RANK_D->query_respect(this_player()) + 
		"非我弟子，不知此话从何谈起？";
	if (query("yao_count") < 1 || random(3) > 0)
		return "你来晚了，白云熊胆丸刚巧给人了。";
	add("yao_count", -1);
	ob = new(__DIR__"baiyunwan");
	ob->move(this_player());
	return "好吧，这粒白云熊胆丸就先给你吧。";
}
