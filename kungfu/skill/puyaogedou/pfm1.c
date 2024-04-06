// chan.c 太极剑法「缠」字诀

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("只能对战斗中的对手使用。\n");

        if( me->query("up1") < 1 )
                return notify_fail("你现在不能使用此pfm.\n");
        if( me->query("pfm1") < 1 )
                return notify_fail("你现在不能使用此pfm.\n");


        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧\n");
                
        if( (int)me->query_skill("puyaogedou", 1) < 40 )
                return notify_fail("你的等级不够娴熟，不会使用「吐雾」\n");
        if( me->query("up1") < 1 )
                return notify_fail("你现在不能使用此pfm.\n");


        msg = HIG "只见$N口一张，一团重重的浓雾喷向$n。\n"NOR;

if (me->query("up1")==1)
{
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR "$n一下啥也看不清了,只得采取守式，不敢妄动！\n" NOR;
            target->start_busy(6);           
target->apply_condition("ill_dongshang",10 );
target->apply_condition("ill_fashao",10 );
target->apply_condition("ill_kesou",10 );
target->apply_condition("ill_shanghan",10 );
target->apply_condition("ill_zhongshu",10 );
            } else {
                msg += HIY"可是$p看破了$P的企图，镇定逾恒，全神应对自如。\n" NOR;
                me->start_busy(random(2));
        }
        message_combatd(msg, me, target);
}
if (me->query("up1")==2)
{
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
                msg += HIR "$n一下啥也看不清了,只得采取守式，不敢妄动！\n" NOR;
target->apply_condition("ill_dongshang",30 );
target->apply_condition("ill_fashao",30 );
target->apply_condition("ill_kesou",30 );
target->apply_condition("ill_shanghan",30 );
target->apply_condition("ill_zhongshu",30 );
            target->start_busy(8);           
            } else {
                msg += HIY"可是$p看破了$P的企图，镇定逾恒，全神应对自如。\n" NOR;
                me->start_busy(random(2));
        }
        message_combatd(msg, me, target);
}

        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}

