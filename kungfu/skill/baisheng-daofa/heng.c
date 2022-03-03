// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define HENG "「" HIR "横扫千军" NOR "」"

inherit F_SSERVER;

string final(object me, object target, int ap, int dp);

int perform(object me, object target) {
    object weapon;
    string msg;
    int ap, dp;
    int damage;


    if (!target) {
        me->clean_up_enemy();
        target = me->select_opponent();
    }

    if (!target || !me->is_fighting(target))
        return notify_fail(HENG "只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon")) ||
        (string) weapon->query("skill_type") != "blade")
        return notify_fail("你所使用的武器不对，难以施展" HENG "。\n");

    if ((int) me->query_skill("baisheng-daofa", 1) < 150)
        return notify_fail("你百胜刀法还不到家，难以施展" HENG "。\n");

    if (me->query_skill_mapped("blade") != "baisheng-daofa")
        return notify_fail("你没有激发百胜刀法，难以施展" HENG "。\n");

    if ((int) me->query_skill("force") < 200)
        return notify_fail("你的内功火候不够，难以施展" HENG "。\n");

    if ((int) me->query("neili") < 500)
        return notify_fail("你现在的真气不够，难以施展" HENG "。\n");

    if (!living(target))
        return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

    ap = me->query_skill("blade", 1);
    dp = target->query_skill("force", 1);
    ap = me->query_skill("blade", 1) + me->query_str() * 5;
    if (random(2) == 0) {
        msg = HIR
        "$N"
        HIR
        "嗔目大喝，杀气凛然而起，手持" + weapon->name() +
        HIR
        "义无反顾的猛然横扫$n"
        HIR
        "，全然不顾生死，浩气怅然！\n"
        NOR;
        ap += ap * 1 / 4;
    } else
        msg = HIR
    "$N"
    HIR
    "狂提内劲，将全身力道灌注于" + weapon->name() +
    HIR
    "之上疾斩劈出，“唰”的一声扫向$n"
    HIR
    "而去！\n"
    NOR;

    dp = target->query_skill("force", 1) + target->query_str() * 5;
    damage = 0;
    if (ap / 2 + random(ap) > dp) {
        damage = me->query_skill("blade", 1) * 2;
        me->add("neili", -350);
        target->add("qi", -damage);
        target->add("eff_qi", -damage / 2);
        me->add("neili", -150);
        msg += HIR
        "$n"
        HIR
        "连忙抵挡，却那里招架得住，整个人"
        "被这一击打得飞身而起，远落平沙。";
        if (ap / 3 > dp && userp(target)) {
            msg += "就此毙命！\n"
            NOR;
            call_out("char_killed", 0, target, me);
        } else if ((ap / 2 > dp) && objectp(weapon = target->query_temp("weapon"))) {
            msg += "手中的" + weapon->name() + HIR
            "再也拿捏不住，应声而出。\n"
            NOR;
            weapon->move(environment(me));
        } else
            msg += "\n"
        NOR;

        me->start_busy(2);
    } else {
        msg += HIC
        "$n"
        HIC
        "奋力招架，硬生生的挡住了这令天地失色之必杀一击！\n"
        NOR;
        me->add("neili", -150);
        me->start_busy(2);
    }
    message_combatd(msg, me, target);

    return 1;
}

string final(object me, object target, int ap, int dp) {
    object weapon;
    string msg;

    msg = HIR
    "$n"
    HIR
    "连忙抵挡，却那里招架得住，整个人"
    "被这一击打得飞身而起，远落平沙。";
    if (ap / 3 > dp && userp(target)) {
        msg += "就此毙命！\n"
        NOR;
        call_out("char_killed", 0, target, me);
    } else if ((ap / 2 > dp) && objectp(weapon = target->query_temp("weapon"))) {
        msg += "手中的" + weapon->name() + HIR
        "再也拿捏不住，应声而出。\n"
        NOR;
        weapon->move(environment(me));
    } else
        msg += "\n"
    NOR;
    return msg;
}

void char_killed(object ob, object me) {
    if (objectp(ob) && objectp(me) && me->is_fighting(ob) &&
        environment(ob) == environment(me))
        ob->unconcious();
}
