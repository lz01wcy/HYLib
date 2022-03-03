// mimicat@fy4
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int begin_perform(object me, object target, int extra, int skill);

int perform(object me, object target) {
    string msg;
    int extra, skill, resist;
    object weapon;


    if (me->query_skill("chixin-jian", 1) < 150)
        return notify_fail("你痴心情长剑的修为不够。\n");


    if (!target) target = offensive_target(me);
    if (!target
        || !target->is_character()
        || !me->is_fighting(target))
        return notify_fail("［暮雨飞虹］只能对战斗中的对手使用。\n");
    if (me->query_temp("muyu"))
        return notify_fail("你已经在使用［暮雨飞虹］了。\n");

    if (me->query_skill("bibo-shengong", 1) < 150)
        return notify_fail("你的碧涛玄功修为不够！\n");

    if (!objectp(weapon = me->query_temp("weapon")) ||
        (string) weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");

    if (me->query("neili") < 600)
        return notify_fail("你的真气不够，无法使用「夺命银龙」！\n");

    weapon = me->query_temp("weapon");

    extra = me->query_skill("sword");
    skill = me->query_skill("chixin-jian", 1);


    me->add_temp("apply/attack", 100);
    me->add_temp("apply/damage", 1000);
    msg = HIC
    "$N一剑挥出，如夕阳，又如烈日，如彩虹，又如乌云，如动又静，如虚又实，
    如在左，又在右，如在前，又在後，如快又慢，如空又实。 \n
    "NOR;
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
    me->add_temp("apply/attack", -100);
    me->add_temp("apply/damage", -1000);

    if ((!userp(me) || skill > 170)) {
        msg = HIW
        "剑光如飞虹，森寒的剑气，冷得深入骨髓。\n"
        NOR;

        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 1000);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1000);

        me->start_busy(3);
    } else {
        me->add("neili", -200);
        me->start_busy(3);
    }


    if ((!userp(me) || skill > 300)) {
        msg = HIG
        "～＊金玉良言＊～"
        NOR + "$N挥动手中$w，剑气狂风似地向$n的$l攻去！";
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIR
        "～＊风雨飘摇＊～"
        NOR + "$N快速移动身体，手中$w化做剑雨，将$n围在中间！";
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIC
        "～＊细水常流＊～"
        NOR + "$N错步上前，剑意若有若无，$w淡淡地向$n的$l挥去";
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIY
        "～＊雨过天晴＊～"
        NOR + "$N手中$w嗡嗡微振，幻成一条疾光刺向$n的$l";
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIG
        "～＊得天独厚＊～"
        NOR + "$N手中$w中宫直进，无声无息地对准$n的$l刺出一剑";
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIR
        "～＊天衣无缝＊～"
        NOR + "$N手中$w斜指苍天，剑芒吞吐，对准$n的$l斜斜击出";
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIC
        "～＊下马问路＊～"
        NOR + "$N一震手中的$w，内力顿时狂泻而出，对着$n的下盘猛然击出";
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        me->add("neili", -200);
    }

    return 1;
}   
