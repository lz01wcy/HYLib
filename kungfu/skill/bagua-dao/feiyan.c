#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target) {
    object weapon;
    string msg, dodge_skill;
    int p;

    if (!target) target = offensive_target(me);

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string) weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");

    if (!target
        || !me->is_fighting(target))
        return notify_fail("「飞雁随风刃」只能在战斗中对对手使用。\n");

    if ((int) me->query_skill("linji-zhuang", 1) < 150)
        return notify_fail("你的临济十二庄等级不够，不能使用飞雁随风刃。\n");

    if ((int) me->query_skill("linji-zhuang", 1) < 120)
        return notify_fail("你的临济十二庄火候太浅。\n");

    if (me->query_skill("bagua-dao", 1) < 140)
        return notify_fail("你的八卦刀法修为不够，难以施展。\n");

    if (me->query_skill_mapped("blade") != "bagua-dao")
        return notify_fail("你没有激发八卦刀法，难以施展。\n");


    if ((int) me->query_skill("bagua-zhang") < 150)
        return notify_fail("你的八卦掌火候太浅。\n");

    if ((int) me->query("neili") < 500)
        return notify_fail("你现在真气太弱，不能使用飞雁随风刃！\n");

    if ((int) me->query("max_neili") < 2000)
        return notify_fail("你现在内力太弱，不能使用飞雁随风刃！\n");

    message_vision(HIY
    "$N突然把手中" + weapon->query("name") + "往上一扔！\n"
    NOR, me, target);
    message_vision(HIR
    "$N看$n一怔，立刻使出一招四象掌的绝学“飘雪穿云掌”！\n"
    NOR, me, target);
    me->add_temp("apply/dexerity", me->query_skill("dodge") / 20);
    if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2) {
        target->receive_damage("qi", me->query_skill("bagua-zhang") * 3);
        target->receive_wound("qi", me->query_skill("bagua-zhang") * 3);
        message_vision(HIY
        "$n一疏忽，被$N重重的击中！\n"
        NOR, me, target);
        p = (int) target->query("qi") * 100 / (int) target->query("max_qi");
        msg = "( $n" + eff_status_msg(p) + " )\n";
        message(msg, me, target);
    } else {
        dodge_skill = target->query_skill_mapped("dodge");
        if (!dodge_skill) dodge_skill = "dodge";
        msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        message(msg, me, target);
    }
    message_vision(HIR
    "\n$N接了空中落下来的刀，唰唰连劈五刀！\n"
    NOR, me, target);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    me->add_temp("apply/dexerity", -me->query_skill("dodge") / 20);
    me->start_busy(2);
    me->add("neili", -(int) me->query_skill("bagua-dao", 1));
    return 1;
}
