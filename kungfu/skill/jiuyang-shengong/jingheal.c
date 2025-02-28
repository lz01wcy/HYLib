// jingheal.c

#include <ansi.h>

int exert(object me, object target) {
    //if ( !wizardp(this_player()) )
    //	return notify_fail("你无权进行精的治疗！\n");

    if (!target)
        return notify_fail("你要用真气为谁疗伤？\n");

    if (me->is_busy())
        return notify_fail("你现在正忙。\n");

    if (me->is_fighting() || target->is_fighting())
        return notify_fail("战斗中无法运功疗伤！\n");

    if ((int) me->query("max_neili") < 300)
        return notify_fail("你的内力修为不够。\n");

    if ((int) target->query("max_neili") < 300)
        return notify_fail("对方的内力修为不够。\n");

    if ((int) me->query("neili") < (int) me->query("max_neili") / 9)
        return notify_fail("你的真气不够。\n");

    if ((int) target->query("neili") < (int) target->query("max_neili") / 9)
        return notify_fail("对方的真气不够。\n");

    message_vision(
            HIY
    "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"
    "过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n"
    NOR,
            me, target );

    target->receive_curing("jing", 10 + (int) me->query_skill("force") / 3);
    target->add("jing", 10 + (int) me->query_skill("force") / 3);
    target->clear_condition("xuanming_poison");
    target->clear_condition("cold_poison");
    target->clear_condition("xscold_poison");
    target->clear_condition("ice_poison");
    target->clear_condition("iceshock");

    if ((int) target->query("jing") > (int) target->query("eff_jing"))
        target->set("jing", (int) target->query("eff_jing"));

    me->add("neili", -(int) me->query("max_neili") / 10);
    me->set("jiali", 0);
    me->start_busy(3);
    target->start_busy(3);
    target->add("neili", -(int) me->query("max_neili") / 10);
    return 1;
}

