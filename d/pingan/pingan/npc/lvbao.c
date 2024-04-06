// poorman.c
#include <ansi.h>

inherit NPC;
void backattack();
void create()
{
        set_name(GRN"绿豹镖师"NOR, ({ "lvbao biaoshi","lvbao","biaoshi"}) );
        set("gender", "男性" );
        set("age", 26);
        set("long", "龙门镖局的镖师。\n");
        set("combat_exp", 250000);
        set("shen_type", 1);
	set_skill("unarmed",80);
	set_skill("jingang-quan",80);
	set_skill("dodge",80);
	set_skill("shaolin-shenfa",80);
	set_skill("force",80);
	set_skill("hunyuan-yiqi",80);
	set_skill("parry",80);
	set_skill("sword",80);
	set_skill("damo-jian",80);
	map_skill("unarmed","jingang-quan");
	map_skill("dodge","shaolin-shenfa");
	map_skill("parry","jingang-quan");
	map_skill("force","hunyuan-yiqi");
	map_skill("sword","damo-jian");
	set("max_force",1100);
	set("force",1100);
	set("force_factor",80);
	set("max_kee",800);

	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/tongjia")->wear();
	carry_object(__DIR__"obj/tongxue")->wear();
	carry_object(__DIR__"obj/tongkui")->wear();
	carry_object(__DIR__"obj/tongshoutao")->wear();
	carry_object(__DIR__"obj/sword")->wield();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",
		HIY + name() + "说道：现在我已经完成护卫任务，就此告辞！\n\n"
		+ name() + "往人群里一钻，消失不见了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who, int level)
{
	int i;
	object *enemy;
	message("vision",
		HIY "从附近的街道里,冲出一个全身劲装镖师。\n\n"
		+ name() + "说道：我奉绿豹令的召唤，特来护卫！\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
	set("possessed",who);
}
void backattack()
{
	int i;
	object owner, *enemy;
	if(objectp(owner=this_object()->query("possessed")))
	{
		enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        }

	}

}


