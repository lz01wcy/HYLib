#include <ansi.h>
#include <combat.h>

#define HUAN "「" HIG "阴阳环" NOR "」"

inherit F_SSERVER;

int perform(object me, object target) {
    object weapon;
    string msg;
    int ap, dp;
    int count;
    int i, attack_time;


    if (!target) target = offensive_target(me);

    if (!target || !me->is_fighting(target))
        return notify_fail(HUAN "只能对战斗中的对手使用。\n");


    if (!objectp(weapon = me->query_temp("weapon")) ||
        (string) weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对，难以施展" HUAN "。\n");

    if (me->query_skill("dodge") < 220)
        return notify_fail("你的阴阳刃法修为不够，难以施展" HUAN "。\n");

    if (me->query("neili") < 270)
        return notify_fail("你的真气不够，难以施展" HUAN "。\n");

    if ((int) me->query_skill("linji-zhuang", 1) < 120)
        return notify_fail("你的临济十二庄火候太浅。\n");

    if (me->query_skill("bagua-dao", 1) < 140)
        return notify_fail("你的八卦刀法修为不够，难以施展" HUAN "。\n");

    if (me->query_skill_mapped("blade") != "bagua-dao")
        return notify_fail("你没有激发八卦刀法，难以施展" HUAN "。\n");

    msg = HIY
    "$N"
    HIY
    "长啸一声，手中" + weapon->name() + HIY
    "化出"
    "无数光环，猛然间光芒瀑涨，连连洒向$n"
    HIY
    "。\n"
    NOR;

    // 根据所激发的是sword或blade来判断ap值。
    ap = me->query_skill("blade");

    dp = target->query_skill("dodge");
    attack_time = 4;

    if (ap / 2 + random(ap * 2) > dp) {
        msg += HIR
        "结果$n"
        HIR
        "被$N"
        HIR
        "攻了个措手不及，$n"
        HIR
        "慌忙招架，心中叫苦。\n"
        NOR;
        count = ap / 12;
        attack_time += random(ap / 45);
        if (count > 100) count = 100;

    } else {
        msg += HIC
        "$n"
        HIC
        "见$N"
        HIC
        "这几招凌厉无比，凶猛异"
        "常，只得苦苦招架。\n"
        NOR;
        count = 0;
    }
    message_combatd(msg, me, target);

    if (attack_time > 8)
        attack_time = 8;

    me->add("neili", -attack_time * 20);
    me->add_temp("apply/attack", count);
    me->add_temp("apply/damage", 200);
    for (i = 0; i < attack_time; i++) {
        if (!me->is_fighting(target))
            break;

        COMBAT_D->do_attack(me, target, weapon, 0);
    }
    me->add_temp("apply/attack", -count);
    me->add_temp("apply/damage", -200);
    me->start_busy(4);

    return 1;
}
