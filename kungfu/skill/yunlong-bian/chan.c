// chan.c 云龙鞭法 缠字诀

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
    object weapon = me->query_temp("weapon");  
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("yunlong-bian",1) < 50)
		return notify_fail("你的「云龙鞭法」功力太浅，使不了「缠」字诀！\n");

	if( (int)me->query_skill("yunlong-shengong", 1) < 50 )
		return notify_fail("你的云龙神功不够高，不能用来反震伤敌。\n");

    if (!weapon || weapon->query("skill_type") != "whip")
        return notify_fail("你使用的武器不对。\n");
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力不足！\n");     

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧\n");

	msg = CYN "$N使出云龙鞭法「缠」字诀，连挥长鞭企图把$n的全身缠住。\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
		msg += "结果$p被$P攻了个措手不及\n" NOR;
		target->start_busy( (int)me->query_skill("yunlong-bian") / 50 + 2);
	} else {
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(2);
	}
me->add("neili", -100);
	message_combatd(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
