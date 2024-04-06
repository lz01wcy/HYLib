// 燕南天南天剑法的绝招“天人合一”
#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target) {
    string msg;
    int delay, i, skill;
    object weapon;
    skill = (int) me->query_skill("chixin-jian", 1);
    if ((int) me->query_skill("chixin-jian", 1) >= 200)
        i = (me->query_skill("chixin-jian", 1) - 180) / 20;
    if (i == 0) i = 1;
    if (i >= 3) i = 3;

    if (!target) target = offensive_target(me);
    if (!target
        || !target->is_character()
        || !me->is_fighting(target))
        return notify_fail("“天人合一”只能对战斗中的对手使用。\n");
    if ((int) me->query_skill("chixin-jian", 1) < 200)
        return notify_fail("你的这门剑法还不够精纯，不能发出“天人合一”。\n");
    if (me->query_skill("bibo-shengong", 1) < 150)
        return notify_fail("你的碧涛玄功修为不够！\n");

    if (!objectp(weapon = me->query_temp("weapon")) ||
        (string) weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");

    if (me->query("neili") < 600)
        return notify_fail("你的真气不够，无法使用「夺命银龙」！\n");


    delay = 1 + random(3 - i);
    message_vision(HIG
    "$N心神进入止水不波的清明天地。\n"
    NOR, me, target);
    me->start_call_out((: call_other, __FILE__, "kill_him", me,
            target :), delay);
    me->start_busy(1 + random(3 - i));
    return 1;
}

void kill_him(object me, object target) {
    int targetexp, damage, mylevel, myexp, targetkee;
    int res_kee;
    int i, x, lvl, skill;
    string msg;
    skill = (int) me->query_skill("chixin-jian", 1);
    if ((int) me->query_skill("chixin-jian", 1) >= 200)
        i = (me->query_skill("chixin-jian", 1) - 180) / 20;
    if (i == 0) i = 1;
    if (i >= 3) i = 3;

    lvl = me->query_skill("chixin-jian", 1);
    x = (lvl - 190) / 2;
    if (x == 0) x = 1;
    if (x >= 50) x = 50;

    if (me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target)) {
        msg = HIY
        "\n剑光一闪即没，归于$N掌中，登时风停树止，鸟寂林息，刚才的一切气
        象似乎只是一场幻梦，荡然无存。" ;
        targetexp = target->query("combat_exp");
        myexp = me->query("combat_exp");
        mylevel = me->query_skill("chixin-jian", 1) / 3;
        targetkee = target->query("max_qi");
        damage = targetkee * (20 + random(50) + random(mylevel)) / 100;
        if (damage > 12000) damage = 12000;

        if (random(targetexp * 2) + myexp > targetexp) {
            msg += HIR
            "\n$n只觉躯体一凉，一支血箭突然从$p胸前溅出。\n"
            NOR;
            target->start_busy(random(i));
        } else {
            msg += HIR
            "\n$n就地一滚，非常狼狈的躲过了$N的这一剑，但却无法躲过漫天的剑气。\n"
            NOR;
            damage = random(damage / 2);
            target->start_busy(1 + random(i));
        }
        target->receive_wound("qi", damage);
        message_vision(msg, me, target);

        COMBAT_D->report_status(target);

    }
    me->add("neili", -300);
    if ((!userp(me) || skill > 300)) {
        if (random(3) == 0) target->start_busy(3);
        msg = HIG
        "松剑－－$N舒臂轻弹手中$w，直刺$n的$l！"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIR
        "江山如画－－$N纵身跃起，直上青天，手中$w大力劈出，自上而下攻向$n的$l！"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIG
        "云剑－－$N手中$w化做流云，飘向$n的$l！"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIR
        "余音袅袅－－$N心神合一，刀力自手中$w呼啸而出，狂奔$n的$l！"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIG
        "石剑－－$N手中$w似重逾千斤，磕向$n的$l！"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIR
        "声景交融－－$N暴喝一声，手中$w圈转，啸音反强，刀光啸音浑然一体，滚向$n的$l！"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIG
        "泉剑－－$N纤腰摆动，手中$w似流水般袭向$n的$l！"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        me->add("neili", -200);
    }

    me->start_busy(2);
    return;
}  

