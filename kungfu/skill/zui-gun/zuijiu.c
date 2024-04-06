// zuijiu.c 八仙醉酒

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int drunk, limit, zui, skill;
        if( !target ) target = offensive_target(me);
         if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("八仙醉酒只能对战斗中的对手使用。\n");


        drunk = me->query_condition("drunk");
        limit = (me->query("con") + (int)me->query("max_neili") / 50) * 2;
        if( !target->query_temp("zui_baxian") )
               target->set_temp("zui_baxian", 1);
        zui = target->query_temp("zui_baxian");
        skill = (int)me->query_skill("zui-gun") / 15;

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力不足！\n");     

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧\n");

        message_vision(
    GRN "只见$N喷出一口酒气，一式「八仙醉酒」，围着$n一摇一摆地走动着。\n" NOR, me, target);

        me->start_busy(1);
        me->add("neili", -200);
        me->add("jing", -10);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 &&
            drunk > limit/4) {
                 message_vision(
    HIR " $N脚下却是暗含八卦，步步紧逼，使得$n碍手碍脚难以出招！\n" NOR, me, target);
                target->start_busy( skill/zui + 2);
        } 
        else if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 &&
            drunk > limit/2) {
                 message_vision(
    HIR " 却见$N脚下暗含八卦，步步紧逼，使得$n碍手碍脚难以出招！\n" NOR, me, target);
                target->start_busy( skill/zui + 4);
        }
        else {
          message_vision(
    CYN "可是$n看破了$N的招数，向后纵了开去。\n" NOR, me, target);
          me->start_busy(2);
        }
        target->add_temp("zui_baxian", 1);
        return 1;
}
