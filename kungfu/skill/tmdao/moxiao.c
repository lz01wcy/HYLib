
// moxiao 魔笑
// 99.2.1  by Bless

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
object weapon;
int i,j;
	int extra;
if( !target ) target = offensive_target(me);

if( !target || !target->is_character()|| !me->is_fighting(target) )

 return notify_fail("「魔笑击」只能对战斗中的对手使用。\n");

if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你所使用的武器不对\n");

    if (me->query("family/family_name") != "日月神教" )
        return notify_fail("你不是日月神教弟子，不能使用这项绝技！\n");
if ( (int)me->query_int() < 30 )
 return notify_fail("你的先天不足，不能领悟「魔笑七击」！\n");


if( (int)me->query_skill("tmdao", 1) < 199 )
 return notify_fail("你的天魔刀法不够娴熟，不会使用「魔笑击」绝技。\n");

if( (int)me->query_skill("tmdafa", 1) < 101 )
 return notify_fail("你的天魔大法不够深厚，不会使用「魔笑击」绝技。\n");

if( (int)me->query("neili")<500)
 return notify_fail("你现在内力太弱，不能使用「魔笑击」绝技。\n");

if( (time()-(int)me->query_temp("last_perform_time"))<
  me->query_temp("last_perform_busy") )
 return notify_fail("你的内力运转的没有这么快。\n");
me->set_temp("last_perform_time",time());
me->set_temp("last_perform_busy",3);

/* */ if(random(2)==1) {
/* */ i=8;
  message_vision(YEL+"\n$N"+RED+"阴侧侧长笑数声，天魔刀法接连出招。\n"NOR,me);
}
else {
/* */ i=7;
 message_vision(YEL+"\n$N"+RED+"阴侧侧长笑数声，天魔刀法接连出招。\n"NOR,me);
}

	extra = me->query_skill("tmdao",1) / 15;
	extra += me->query_skill("tmdafa",1) /10;

/* */ weapon=me->query_temp("weapon");
/* */

me->set_temp("action_flag", 1);
  for(j=1;j<=i;j++) {
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
 COMBAT_D->do_attack(me, target, weapon, 1);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra);


}
me->delete_temp("action_flag");
me->start_busy(2);
me->add("neili",-200);

return 1;
}
