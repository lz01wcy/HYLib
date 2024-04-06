// migong lev14

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(BLU"孽龙"NOR, ({ "nie long" , "long" , "dragon" }));
                set("race", "野兽");
       set("long",
"一条丑陋不堪，凶残无比的巨龙。
它充斥着这整个洞穴，你顿觉空气的压抑，觉得它十分地可怕
。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("max_qi",70000+random(20000));
  set("max_jing",70000+random(20000));
  set("max_sen",70000+random(20000));
  set("max_mana",700000+random(20000));
    set("max_neili",70000+random(20000));
set("neili",50000+random(20000));

      set("dex",120);
      set("con",100);
     set("str" ,120);
       
    set("age", 150);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 10000000+random(2000000));
            set_temp("apply/attack", 600);
        set_temp("apply/damage", 600);
        set_temp("apply/armor", 600);
        set_temp("apply/defence",600);
      set_skill("dodge", 600+random(100));

      set_skill("unarmed", 600+random(100));

       set_skill("dragon", 600+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),

 }) );
     
   setup();

    
    carry_object("/d/migong/obj/dan2");
	    

}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}
void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
if (!me) return;
              me->add("score",1);
        message_vision(WHT"$N一声怒吼，浑身鲜血直流，缓缓躺倒在地。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp") < 16000000)   {
if (random(20) < 1)
{
             corpse=new("/clone/gem/gem");
             message_vision("$N得到一颗亮晶晶的宝石。\n",me);
             command("rumor "+me->query("name")+"得到一颗"+corpse->query("name")+"!"NOR"。\n");
             corpse->move(me);
}

        message("vision", me->name() + "成功打死猎物增加了600经验和250潜能。\n", me);
        me->add("combat_exp",500);
        me->add("potential",250);
        destruct(ob);
        }
               destruct(ob);
        return;
}


int hit_ob(object me, object ob, int damage)
{
   if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("wugong_poison") < 10 ) {
		ob->apply_condition("wugong_poison", 40);
        tell_object(ob, HIG "你觉得被咬中的地方一阵麻痒！\n" NOR );
	}
}
