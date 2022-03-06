// shield.c 九阳护体神功

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target) {
    int skill;

    if (target != me)
        return notify_fail("你只能用九阳神功来提升自己的防御力。\n");

    if ((int) me->query("neili") < 200)
        return notify_fail("你的真气不够。\n");

    if ((int) me->query_skill("jiuyang-shengong", 1) < 40)
        return notify_fail("你的九阳神功等级不够。\n");

    if (!me->query("jiuyangok"))
        return notify_fail("你虽然听说过九阳神功是护体神功，但不会用。\n");
    if ((int) me->query_temp("liuyun"))
        return notify_fail(HIG
    "你已经在默运流云水袖神功了。\n");

    if ((int) me->query_temp("qzj_tong"))
        return notify_fail("你已经在运同归剑了。\n");
    if (me->query_temp("fumo"))
        return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
    if (me->query_temp("jingang"))
        return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」！\n");
    if (me->query_temp("fanzhen"))
        return notify_fail("你正在运用「金刚不坏体神功」！\n");
    if ((int) me->query_temp("jiuyin/powerup"))
        return notify_fail("你已经在运九阴真功中了。\n");
    if ((int) me->query_temp("hslj/powerup"))
        return notify_fail("你已经在运万法归宗中了。\n");
    if (me->query_temp("yuxiao/tianwu"))
        return notify_fail("你正在运用「凤凰天舞」心法！\n");

    if ((int) me->query_temp("tzzf"))
        return notify_fail("你已经在掌刀的运功中。\n");

    if ((int) me->query_temp("shield"))
        return notify_fail("你已经在运功中了。\n");
    if (me->query_temp("wdpowerup"))
        return notify_fail("你现在正在使用「五毒神功」的绝技。\n");
    if (me->query_temp("zhuihun/lpf"))
        return notify_fail("你正在使用五毒追魂钩之「乱披风」\n");

    skill = me->query_skill("force");
    me->add("neili", -100);
    me->receive_damage("qi", 0);

    message_combatd(HIR
    "$N"
    HIR
    "默念九阳神功的口诀：他"
    "强由他强，清风拂山冈。他横任他横，"
    "明月照大江……\n刹那间只见$N"
    HIR
    "全身顿时浮现出一层刚猛的劲气，将$P"
    HIR
    "全全笼罩。\n"
    NOR, me);


    me->add_temp("apply/dodge", skill / 3);
    tell_object(me, HIG
    "你的轻功提高了!\n"
    NOR);
    me->add_temp("apply/damage", skill / 3);
    tell_object(me, HIG
    "你的杀伤力提高了!\n"
    NOR);
    me->add_temp("apply/attack", skill / 3);
    tell_object(me, HIG
    "你的攻击力提高了!\n"
    NOR);
    me->add_temp("apply/armor", skill);
    tell_object(me, HIG
    "你的防御力提高了!\n"
    NOR);
    me->set_temp("shield", 1);

    me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill  :), skill);

    if (me->is_fighting()) me->start_busy(2);

    return 1;
}

void remove_effect(object me, int amount) {
    if (me->query_temp("shield")) {
        me->add_temp("apply/dodge", -(amount / 3));
        me->add_temp("apply/damage", -(amount / 3));
        me->add_temp("apply/attack", -(amount / 3));
        me->add_temp("apply/armor", -amount);
        me->delete_temp("shield");
        tell_object(me, "你的九阳神功运行完毕，将内力收回丹田。\n");
    }
}

