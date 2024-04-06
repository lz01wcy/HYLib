// powerup.c
// Last Modified by winder on Jul. 20 2001

#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
	int skill;


	if( target != me )
		return notify_fail("你只能用寒冰真气提升自己的战斗力。\n");
	if( (int)me->query("neili") < 100 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");

//	me->add("bellicosity", 100 + skill/2 );
	me->add("neili", -100);
	me->receive_damage("qi",0);

	message_combatd(HIB"$N微一凝神，全身一阵颤抖，默运寒冰真气。\n"NOR, me);

	me->add_temp("apply/defense", skill/3);
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/3:),skill);
	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/defense", - amount);
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	tell_object(me, "你的寒冰真气运行完毕，将内力收回丹田。\n");
}

int help(object me)
{
	write(WHT"\n寒冰真气之加力："NOR"\n");
	write(@HELP

	使用功效：
		提升自己的攻击防御能力

	出手要求：
	        内力100
HELP
	);
	return 1;
}

