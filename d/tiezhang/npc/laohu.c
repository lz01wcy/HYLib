// laohu.c

inherit NPC;

void create()
{
        set_name("老虎", ({ "lao hu", "hu" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只凶猛的大老虎。\n");

        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100000);

      	set("chat_chance", 6);
      	set("chat_msg", ({
              (: random_move :),
      	}) );
	set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 50);

        setup();
}

void init()
{
  	object me;

  	me=this_player();
	if (interactive(me)) kill_ob(me);
}
 void die()
{
       object ob;
       message_vision("$N惨嚎一声，死了！\n", this_object());
        ob = new(__DIR__"obj/hupi");
       ob->move(environment(this_object()));
       destruct(this_object());
}
