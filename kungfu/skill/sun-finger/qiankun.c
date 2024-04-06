// qiankun.c 一阳指 「一指乾坤」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
           return notify_fail("「一指乾坤」只能在战斗中使用。\n");

	if((int)me->query_str() < 28)
		return notify_fail("你臂力不够,不能使用这一绝技!\n");

	if((int)me->query_skill("kurong-changong",1) < 90)
		return notify_fail("你枯荣禅功的功力不够不能使用一指乾坤!\n");

	if((int)me->query_skill("sun-finger",1) < 90)
		return notify_fail("你的一阳指修为不够,目前还不能使用一指乾坤绝技!\n");

	if((int)me->query("max_neili") < 850)
		return notify_fail("你内力修为不够, 不能使用一指乾坤! \n");

	if((int)me->query("neili") < 200)
		return notify_fail("你内力现在不够, 不能使用一指乾坤! \n");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「一指乾坤」只能对战斗中的对手使用。\n");
	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧\n");

	msg = CYN "$N使出一阳指绝技「一指乾坤」，罩住$n的全身要穴, 企图使$n动弹不得。\n"NOR;

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
        {
		msg +=   "结果$n被$N攻了个措手不及! 一时不能动弹! \n";
		target->start_busy( (int)me->query_skill("sun-finger",1) / 50 + 4);
		me->add("neili", -200);
	}
	else
	{
		msg += "可是$n看破了$N的企图，并没有上当。\n";
		me->start_busy(3);
		me->add("neili", -200);

	}
	message_combatd(msg, me, target);

	return 1;
}
