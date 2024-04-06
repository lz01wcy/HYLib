// chan.c 日月鞭法「缠绕」诀

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    object weapon = me->query_temp("weapon");  
    if( !target ) target = offensive_target(me);

    if( !target
    ||      !target->is_character()
    ||      !me->is_fighting(target) )
        return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

    if (!weapon || weapon->query("skill_type") != "whip"
    || me->query_skill_mapped("whip") != "riyue-bian")
        return notify_fail("你现在无法使用「缠绕」。\n");
	if((int)me->query_skill("hunyuan-yiqi",1) < 50)
		return notify_fail("你混元一气功的功力不够!\n");

    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧\n");

    msg = CYN "$N使出日月鞭法「缠绕」诀，连挥数鞭企图把$n的全身缠绕起来。\n";

        me->add("neili", -200);
        me->add("jing", - 40);
        me->start_busy(2);
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
    {
        msg += "结果$p被$P攻了个措手不及\n" NOR;
        target->start_busy( (int)me->query_skill("riyue-bian") / 50 + 2);
    } else {
        msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->start_busy(3);
    }
    message_combatd(msg, me, target);

    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}

