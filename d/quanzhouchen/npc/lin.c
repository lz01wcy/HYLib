// lin.c
// Last Modified by winder on May. 29 2001

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("林少宁", ({ "lin shaoning", "lin" }));
	set("long", "林少宁是泉州武馆馆长。\n");
	set("gender", "男性");
	set("age", 35);
	set_skill("dodge", 180);
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("claw", 180);
	set_skill("hand", 180);
	set_skill("strike", 180);
	set_skill("finger", 180);
	set_skill("cuff", 180);
	set_skill("blade", 180);
	set_skill("stick", 180);
	set_skill("club", 180);
	set_skill("staff", 180);
	set_skill("sword", 180);
	set_skill("throwing", 180);
	set_skill("changquan", 140);

	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");

	set("combat_exp", 400000);
	set("shen_type", 1);
	setup();

}
int accept_object(object who, object ob)
{
	if (who->query("combat_exp")>= 3500)
	{
		message_vision("林少宁望着$N说：你的武功应该历练江湖才能再长进，不能埋没在这里了。\n", who);
		return 0;
	}
	if (ob->query("money_id") && ob->value() >= 500)
	{
		who->set_temp("marks/quanzhou_paied",1);
		message_vision("林少宁对$N说：好！这位" + RANK_D->query_respect(who) + "想学什么呢？\n" , who);
		return 1;
	}
	else
		message_vision("林少宁皱眉对$N说：钱我不在乎。可你也给的也太少了点儿吧？\n", who);
	return 0;
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("marks/quanzhou_paied")==1) return 0;
	return 1;
}


