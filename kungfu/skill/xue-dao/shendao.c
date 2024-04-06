// jixue.c  血刀经 [祭血神刀]
// coded by emnil@sj	2/5/2000

#include <ansi.h>
#include <skill.h>
#include <combat.h>
#include <weapon.h>

inherit F_SSERVER;

void jixue(object me, object target, int times, int now);

int perform(object me, object target) {
    object ob, weapon;
    string msg;
    int lvl, times, extra;
    extra = me->query_skill("xue-dao", 1);
    if (!target) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string) weapon->query("skill_type") != "blade")
        return notify_fail(RED
    "装备刀才能使用「祭血神刀」？\n"
    NOR);
    if (!target || !target->is_character() || !me->is_fighting(target))
        return notify_fail("「祭血神刀」只能对战斗中的对手使用。\n");
    if ((int) me->query_skill("xue-dao", 1) < 100)
        return notify_fail(WHT
    "你血刀刀法不够娴熟，使不出「祭血神刀」。\n"
    NOR);
    if ((int) me->query_skill("longxiang", 1) < 60)
        return notify_fail(RED
    "你龙象般若功火候不够，使不出「祭血神刀」。\n"
    NOR);
    if ((int) me->query("max_neili") < 600)
        return notify_fail(RED
    "你内力修为不足，无法运足内力。\n"
    NOR);
    if ((int) me->query("neili") < 600) {
        return notify_fail(HIC
        "你现在内力不够，没能将「祭血神刀」使完！\n"
        NOR);
    }

    if (!me->is_fighting())
        return notify_fail("「祭血神刀」只能在战斗中使用。\n");

    if (!objectp(weapon = me->query_temp("weapon")) || (string) weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");

    if ((int) me->query_skill("xue-dao", 1) < 120)
        return notify_fail("你的刀法修为不够， 目前不能使用「祭血神刀」! \n");

    if (me->query_temp("xs/jixue"))
        return notify_fail("你正在使用「祭血神刀」! \n");

    if ((int) me->query_skill("longxiang", 1) < 120)
        return notify_fail("你的龙象般若功修为不够， 目前不能使用「祭血神刀」! \n");

    if (me->query_skill_mapped("force") != "longxiang")
        return notify_fail("你现在所使用的内功同「龙象般若功」向抵触，不能使出「祭血神刀」的绝技！\n");

    if (me->query_skill("yujiamu-quan", 1) < 120)
        return notify_fail("你现在的金刚瑜迦母拳不足。\n");
    if (me->query_skill("dashou-yin", 1) < 120)
        return notify_fail("你现在密宗大手印不足。\n");
    if (me->query_skill("xiangmo-chu", 1) < 120)
        return notify_fail("你现在的金刚降魔杵不足。\n");
    if (me->query_skill("mingwang-jian", 1) < 120)
        return notify_fail("你现在的不动明王剑不足。\n");
    if (me->query_skill("shenkong-xing", 1) < 120)
        return notify_fail("你现在的身空行不足。\n");

    if ((int) me->query("max_neili") < 2000)
        return notify_fail("你的内力修为不够！\n");
    if ((int) me->query("neili") < 500)
        return notify_fail("你的真气不够！\n");

    ob = me->select_opponent();
    lvl = me->query_skill("xue-dao", 1);
    me->set_temp("xs/jixue", 1);
    times = me->query("env/jixue");
    if (times < 1) times = 1;
    if (times > lvl / 40) times = lvl / 40;
    if (times > 7) times = 7;
    if (extra > 200) extra = 200;

    me->add_temp("apply/attack", 80);
    me->add_temp("apply/damage", extra * 3);
    msg = YEL
    "$N右手持刀向左肩一勒，一阵血珠溅满刀面，紧接着右臂抡出，一片血光
    裹住刀影向$n当头劈落，\n
    "NOR;
    if (!target->is_busy()) target->start_busy(3);
    COMBAT_D->do_attack(me, target, weapon, TYPE_REGULAR, msg);
    COMBAT_D->do_attack(me, target, weapon, TYPE_REGULAR, msg);
    COMBAT_D->do_attack(me, target, weapon, TYPE_REGULAR, msg);
    me->add_temp("apply/attack", -80);
    me->add_temp("apply/damage", -extra * 3);

    msg = HIR
    "\n$N脸色陡然一变，口中念念有词，同时倒转兵刃，不知道要做什么！\n\n"
    NOR;
    message_vision(msg, me);
    me->add("neili", -100);
    me->start_busy(2);
//	me->start_perform(10,"祭血神刀");

    call_out("jixue", 0, me, ob, times, 0);

    return 1;
}

void jixue(object me, object target, int times, int now) {
    string msg, weaname;
    object weapon;
    int lvl, force, damage, attack, qi;

    if (!objectp(me)) return;
    if (!objectp(target) || !me->is_fighting(target) || (now >= times) || (me->query("neili") < 200) ||
        (!objectp(weapon = me->query_temp("weapon"))) || ((string) weapon->query("skill_type") != "blade")) {
        me->set_temp("xs/jixue", 0);
        me->start_busy(1);
        if (living(me))
            message_vision(HIC
        "\n$N慢慢收回内劲，脸上也似乎有了血色。\n"
        NOR, me);
        return;
    }

    weapon = me->query_temp("weapon");
    weaname = weapon->query("name");
    lvl = me->query_skill("xue-dao", 1);
    force = me->query_skill("longxiang", 1);

    now++;
    if (now <= 1)
        msg = HIR
    "\n$N狂啸一声，以兵刃自砍手臂，顿时一飙鲜血飞溅在"
    NOR + weaname + HIR
    "之上，"
    NOR + weaname + HIR
    "隐隐泛出一层血色。";
    else
    if (now <= 3)
        msg = HIR
    "\n$N狂啸一声，以兵刃自砍胸膛，顿时一腔鲜血飞溅在" + weaname + HIR
    "之上，"
    NOR + weaname + HIR
    "泛出一层血色！";
    else
    msg = RED
    "\n$N狂啸一声，当头砍了自己一刀，顿时一股鲜血飞溅在" + weaname + RED
    "之上，"
    NOR + weaname + RED
    "整个变的通红！！！";

    attack = 7 - now;
    damage = 8 - now;
    if (me->query_temp("xs/longxiang")) {
        damage--;
        if (damage < 2) damage = 2;
        msg += "$N更把龙象内劲附于兵刃之上！";
    }
    msg += "\n"
    NOR;
    message_vision(msg, me);
    if (wizardp(me))
        tell_object(me, sprintf("damage:%d , attack:%d , qi:%d \n", force / damage, lvl / attack, -50 * now));

    me->add_temp("apply/damage", 1000);
    me->add_temp("apply/attack", 100);
    if (!target->is_busy()) target->start_busy(3);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    me->add_temp("apply/damage", -1000);
    me->add_temp("apply/attack", -100);

    if (me->query("qi") < (60 * now))
        qi = me->query("qi") - 10;
    else
        qi = 60 * now;
    if (qi < 0) qi = 0;

    me->receive_damage("qi", qi / 2);
    me->receive_wound("qi", qi / 3);

    me->add("neili", -30 * now);
    if (me->query("neili") < 0) me->set("neili", 0);

    call_out("jixue", 2 + random(3), me, target, times, now);
}
