#include <ansi.h>
#include <combat.h>

#define KOU "「" HIM "环环相扣" NOR "」"

inherit F_SSERVER;

int perform(object me, object target) {
    object weapon;
    int damage, extra, count;
    string msg;
    int ap, dp;


    if (!target) {
        me->clean_up_enemy();
        target = me->select_opponent();
    }

    if (!target || !me->is_fighting(target))
        return notify_fail(KOU "只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon")) ||
        (string) weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对，难以施展" KOU "。\n");

    if ((int) me->query_skill("force") < 100)
        return notify_fail("你的内功火候不够，难以施展" KOU "。\n");

    if ((int) me->query_skill("bingpo-blade", 1) < 80)
        return notify_fail("你的冰魄寒刀还不到家，难以施展" KOU "。\n");

    if ((int) me->query_skill("huagong-dafa", 1) < 125)
        return notify_fail("你的化功大法火候不够.\n");
    if ((int) me->query("neili") < 350)
        return notify_fail("你的真气不够，难以施展" KOU "。\n");

    if (!living(target))
        return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

    msg = HIM
    "$N"
    HIM
    "刀法忽然一变，时而削，时而砍，时而劈，挥舞如风，转瞬"
    "即至劈向$n"
    HIM
    "！\n"
    NOR;

    ap = me->query_skill("blade");
    dp = target->query_skill("parry");

    if (ap / 2 + random(ap) > dp) {
        damage = ap / 2 + random(ap / 2);
        me->add("neili", -100);
        damage = 150 + me->query_skill("unarmed");
        target->add("qi", -damage);
        target->add("eff_qi", -damage);
        msg += HIR
        "结果$n"
        HIR
        "一个不留神，被刀锋扫"
        "到，鲜血四溅，痛彻心肺！\n"
        NOR;
        me->start_busy(2);
    } else {
        msg += CYN
        "可是$p"
        CYN
        "凝神聚气，护住门户，无论$P"
        CYN
        "怎样变招，始终奈何不得。\n"
        NOR;
        me->add("neili", -50);
        me->start_busy(3);
    }
    message_combatd(msg, me, target);
    if ((int) me->query_skill("bingpo-blade", 1) > 160) {
        msg = HIW
        "$N猛然将刀身一横，明晃晃的刀身在日光下反射一片白光,直射$n的面门！\n"
        NOR;
        message_vision(msg, me, target);
        if (random(me->query("combat_exp")) > (int) target->query("combat_exp") / 2) {
            msg = HIW
            "$N只觉一道眩光刺得双眼什么都看不见了，$n见状大喜连续三刀，从三个不同的方向砍来！\n"
            NOR;
            message_vision(msg, target, me);
            extra = me->query_skill("bingpo-blade", 1) / 50;
            if (extra > 4) extra = 4;
            target->start_busy(extra + count);
        } else {
            msg = "可是$n看破了$N的企图，往旁一闪躲了过去。\n"
            NOR;
            message_vision(msg, me, target);

            me->start_busy(3);
            return 1;
        }
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add("neili", -150);

    }
    return 1;
}
