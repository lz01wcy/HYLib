#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";

#define JIA "「" HIY "掌中夹镖" NOR "」"

inherit F_SSERVER;

int perform(object me, object target) {
    int ap, dp, damage, p;
    string pmsg;
    string msg;
    object weapon;


    if (!target) target = offensive_target(me);

    if (!target || !me->is_fighting(target))
        return notify_fail(JIA "只能在战斗中对对手使用。\n");

    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail(JIA "只能空手施展。\n");


    if ((int) me->query_skill("linji-zhuang", 1) < 50)
        return notify_fail("你的临济十二庄等级不够。\n");

    if (me->query_skill_mapped("strike") != "bagua-zhang")
        return notify_fail("你没有激发八卦掌，难以施展" JIA "。\n");


    if ((int) me->query_skill("bagua-zhang", 1) < 120)
        return notify_fail("你的八卦掌不够娴熟，难以施展" JIA "。\n");


    if ((int) me->query_skill("force") < 150)
        return notify_fail("你的内功火候不够，难以施展" JIA "。\n");

    if ((int) me->query("neili") < 150)
        return notify_fail("你现在真气不足，难以施展" JIA "。\n");

    if (!living(target))
        return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

    me->add("neili", -100);

    msg = HIY
    "$N"
    HIY
    "一声暴喝，一掌重重击向$n"
    HIY
    "，$p"
    HIY
    "正欲格挡，忽然只见眼前金光一闪，一股劲风已由$N"
    HIY
    "掌中激射而出！\n"
    NOR;

    me->start_busy(2);

    ap = me->query_skill("strike") + me->query_skill("throwing");
    dp = target->query_skill("dodge") + target->query_skill("parry");

    if (ap / 2 + random(ap) > dp) {
        damage = ap / 4 + random(ap / 4);
        msg += HIR
        "$n"
        HIR
        "果真始料不及，$N"
        HIR
        "那几枚暗器" +
        HIR
        "正好打在$p"
        HIR
        "要穴上，顿时血气上涌，"
        "连退数步！\n"
        NOR;
        target->receive_damage("qi", damage * 2, me);
        target->receive_wound("qi", damage, me);
        p = (int) target->query("qi") * 100 / (int) target->query("max_qi");
        message_combatd(msg, me, target);

    } else {
        msg += CYN
        "可是$p"
        CYN
        "早料得$P"
        CYN
        "有此一着，哈哈一笑，斜跳闪开。\n"
        NOR;
        message_combatd(msg, me, target);
    }
    me->reset_action();
    return 1;
}
