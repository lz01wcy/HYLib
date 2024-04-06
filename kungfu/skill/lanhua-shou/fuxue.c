// fuxue.c 兰花拂穴手 「兰花拂穴」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「兰花拂穴」只能在战斗中使用。\n");

	if((int)me->query_str() < 25)
		return notify_fail("你臂力不够,不能使用这一绝技!\n");

	if((int)me->query_skill("bibo-shengong",1) < 100)
		return notify_fail("你碧波神功的功力不够不能使用兰花拂穴!\n");

	if((int)me->query_skill("hand") < 120)
		return notify_fail("你的手法修为不够,目前还不能使用兰花拂穴绝技!\n");

	if((int)me->query("neili") < 500)
		return notify_fail("你内力现在不够, 不能使用拈花拂穴! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧\n");

	msg = HIB "$N右手反手伸出，三个指头婉转如一朵盛开的兰花，轻盈点向了$n的胁下要穴, 使$n动弹不得。\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3 )
	{
		msg +=  HIB "结果$p被$P点个正着，顿时手足无措，呆立当地! \n" NOR;
		target->start_busy( (int)me->query_skill("lanhua-shou",1) / 50 + 3 );
		me->add("neili", -100);
	}
	else
	{
		msg += HIY "可是$p看破了$P的企图，轻轻一跃，跳了开去。\n" NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}

