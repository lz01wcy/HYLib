//lianhuan.c 连环 perform

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        mapping fam;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("连环决只能对战斗中的对手使用。\n");

//        if (!(fam = this_player()->query("family")) || fam["family_name"] != "神龙教")
//                return notify_fail("你非神龙教弟子，不能运本教神龙腿法！\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正晕头转向，乘机进攻吧\n");

	if( (int)me->query_skill("shenlong-xinfa", 1) < 150 )
		return notify_fail("你的神龙心法不够娴熟。\n");

	if( (int)me->query_skill("huagu-mianzhang", 1) < 140 )
		return notify_fail("你的化骨绵掌不够娴熟。\n");

        if( me->query("neili") <= 300 )
                return notify_fail("你的内力不够使用连环决！\n");

        if( (int)me->query("jing") < 150 )
                return notify_fail("你的精神无法集中。\n");

        message_vision(HIR"左一掌！\n" NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIM"右一掌！\n" NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        msg = HIY "\n 突然间$N身形腾空而起，凌空向$n奋力连踢几腿！\n" NOR;


        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
         {
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") )
{
        target->start_busy( (int)me->query_skill("huagu-mianzhang", 1) / 20 );
}
                damage = (int)me->query_skill("huagu-mianzhang", 1);
                damage = damage/2 + random(damage);

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
        target->apply_condition("cold_poison",10);
		msg += HIB "忽然一股寒气优似冰箭，循着手臂，迅速无伦的射入$p胸膛\n" NOR;
        target->apply_condition("snake_poison",10);
                me->add("neili", -damage/10);

                if( damage < 40 ) msg += HIY"结果$n被$N的连环腿踢得晕头转向！\n" NOR;
                else msg += HIR"结果$n被$N的连环腿踢中要害，「哇！」的一口鲜血喷涌而出！\n"NOR;
        }

         else {
                msg += "可是$p看破了$P的企图，巧妙得躲了开去。\n" NOR;
                me->start_busy(1 + random(3));
        }
        message_vision(msg, me, target);

        return 1;
}

