#include <ansi.h>
inherit NPC;
int have_yuzhuo=1;

void create()
{
	set_name("碧涟", ({ "bilian","girl", "xiaojie" }));
	set("age", 16);
	set("gender", "女性");
	set("attitude", "peaceful");
	set("str", 34);
	set("dex", 36);
       set("title","小姐");
	set("combat_exp", 100000);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("force", 80);


    set("chat_chance", 7);
	set("chat_msg", ({
		"唉,衣带渐宽众不悔,为伊销得人憔悴!\n",
		"碧涟抬头看着窗外,一动不动,似乎在想着什么.\n",
	}));
	set("inquiry", ([
		"玉簪" : "嗯,昨天不知道掉哪儿了？",
		"鱼肠剑" : "嘻嘻,这几天问这问题的人真多!",
		]) );	
	setup();
add_money("gold",1);
	carry_object("/clone/weapon/changjian")->wield();
carry_object("/clone/misc/cloth")->wear();
}
int accept_object(object who,object item)
{	
	if(item->query("id")=="biyuzan")
	{if (have_yuzhuo==1)
	   {  command("say 啊,是我的玉簪.....真谢谢你,这件小东西送给你。\n");
message_vision("小姐给$N一只"+HIC+"翠玉镯.\n"NOR,who);
clone_object(__DIR__"obj/cuiyuzhu.c")->move(who);
have_yuzhuo=0;		
return 1; }
       else command("say 唉,你来晚了,东西已经给别人拿走了!\n");
       return 0;
	}
	command("say 这又不是我的东西,给我干什么。\n");
	return 0;
}
