// guanzho3.c
inherit NPC;
#include <ansi.h>
inherit F_MASTER;

void consider();

void create()
{
    set_name("观众丙", ({"bing"}));
    set("gender", "女性");
    set("age", 18);
    set("long", "这是一位小姑娘。\n");
    set("attitude", "peaceful");
	
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 200);
    set("max_qi", 200);
    set("jing", 100);
    set("max_jing", 100);
	
    set("combat_exp", 5000);
    set("score", 0);
	
    set_skill("force", 60);
    set_skill("unarmed", 60);
    set_skill("dodge", 60);
    set_skill("parry", 65);
	
	setup();
	carry_object("/d/city/obj/pink_cloth")->wear();
	carry_object("/d/city/obj/flower_shoe")->wear();
}

void init()
{

	object me, ob;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight"))
	{
		if( !ob->query_temp("warned") ) {
			command("say 居然有人敢不让我看戏，气死我了！");
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say 我杀了你！！！\n");
//			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

        remove_call_out("leave");
        call_out("leave",30);

}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "观众钻进路边的杂草，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
