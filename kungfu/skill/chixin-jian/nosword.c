#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target, object weapon) {
    int damage, myexp, yourexp, cpexp, lvl, sword;
    string msg;
    int res_kee, res_gin, res_sen, max_exp;
    int no_busy, x;

    no_busy = 0;

    lvl = me->query_skill("chixin-jian", 1);
    sword = me->query_skill("sword", 1);
    if (lvl < 300)
        return notify_fail("你的痴心情长剑未能达到「无剑」的境界！\n");
    if (sword < 280)
        return notify_fail("你的基本剑法未能达到「无剑」的境界！\n");
    if ((int) me->query_skill("bibo-shengong", 1) < 120)
        return notify_fail("你的碧波神功火候太浅。\n");
    if ((int) me->query_skill("anying-fuxiang", 1) < 120)
        return notify_fail("你的暗影浮香火候太浅。\n");
    if ((int) me->query_skill("lanhua-shou", 1) < 120)
        return notify_fail("你的兰花拂穴手火候太浅。\n");
    if ((int) me->query_skill("luoying-shenjian", 1) < 120)
        return notify_fail("你的落英神剑火候太浅。\n");
    if ((int) me->query_skill("luoying-zhang", 1) < 120)
        return notify_fail("你的落英神剑掌火候太浅。\n");
    if ((int) me->query_skill("tanzhi-shentong", 1) < 120)
        return notify_fail("你的弹指神通火候太浅。\n");
    if ((int) me->query_skill("xuanfeng-leg", 1) < 120)
        return notify_fail("你的旋风扫叶腿火候太浅。\n");
    if ((int) me->query_skill("yuxiao-jian", 1) < 120)
        return notify_fail("你的玉箫剑法火候太浅。\n");
    if ((int) me->query_skill("count", 1) < 120)
        return notify_fail("你的阴阳八卦火候太浅。\n");
    if ((int) me->query_skill("qimen-wuxing", 1) < 120)
        return notify_fail("你的奇门五行火候太浅。\n");
    if ((int) me->query_skill("canglang-bian", 1) < 120)
        return notify_fail("你的沧浪鞭法火候太浅。\n");

    x = (lvl - 170) / 2;
    if (x == 0) x = 1;
    if (x >= 50) x = 50;
    if (!target) target = offensive_target(me);
    if (!target
        || !target->is_character()
        || !me->is_fighting(target))
        return notify_fail("「无剑」只能在战斗中使用。\n");

    if (me->query_skill("bibo-shengong", 1) < 250)
        return notify_fail("你的碧涛玄功修为不够！\n");

    if (!objectp(weapon = me->query_temp("weapon")) ||
        (string) weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");

    if (me->query("neili") < 600)
        return notify_fail("你的真气不够，无法使用！\n");

    if ((int) me->query("jing") < 100)
        return notify_fail("你的精力不够！\n");
    if ((int) me->query("neili") < 100)
        return notify_fail("你的内力不够！\n");

    me->receive_damage("jing", 100);
    me->add("neili", -100);

    if (target->query("no_busy"))
        no_busy = target->query("no_busy");
    if (me->query_temp("weapon")) {
        //return notify_fail ("「无剑心法」必须空手才能使出。\n");
        weapon = me->query_temp("weapon");
        //if(weapon->query("equipped") == "wielded")
        msg = HIC
        "\n$N" + HIC
        "随手一扬，将兵器插回身后，腕臂急转，并指为剑，蓄势待发！\n"
        NOR;
        msg += HIW
        "只觉漫天剑意。一丝丝剑气撕裂空气，直刺$n要害，骇然正是无招无式的「无剑心法」。\n\n"
        NOR;
        message_vision(msg, me, target);
        //weapon->unequip();
        //return 2;
    } else {
        msg = HIC
        "\n$N" + HIC
        "双手并指为剑，指尖笔直，左手手腕一曲，右手掌心向下，蓄势待发！\n"
        NOR;
        msg += HIW
        "只觉漫天剑意。一丝丝剑气撕裂空气，直刺$n要害，骇然正是无招无式的「无剑心法」。\n\n"
        NOR;
        message_vision(msg, me, target);
        //return 2;
    }

    if (me->query_skill("force") < random((target->query_skill("force"))) / 2) {
        message_vision(HIY
        "但是$N听声辨位，避过所有无形剑气，直击$n的脉门！\n"
        NOR, target, me);
        me->start_busy(2);
        return 1;
    }

    damage = sword + lvl;
    damage = damage + random(damage);

    yourexp = (int) target->query("combat_exp");
    myexp = (int) me->query("combat_exp");
    cpexp = random(myexp / 2);
    if (yourexp < 10000000) yourexp = yourexp * 2 / 3;
    if (yourexp * 2 < myexp) {
        message_vision(HIR
        "凌厉的剑气贯穿$N的身体，剑芒混杂着血花，弥漫在方圆十丈之内。\n"
        NOR, target);
        target->receive_damage("qi", damage * 3);
        target->receive_damage("jing", damage);

        target->receive_wound("qi", damage * 3);
        target->receive_wound("jing", damage);

        COMBAT_D->win_lose_check(me, target, 1);
    } else {
        if (target->query_busy()) {

            message_vision(HIR
            "凌厉的剑气贯穿$N的身体，剑芒混杂着血花，弥漫在方圆十丈之内。\n"
            NOR, target);
            if (random((int) me->query_skill("magic")) > 50) {
                target->receive_damage("qi", damage * 3);
                target->receive_damage("jing", damage);

                target->receive_wound("qi", damage * 3);
                target->receive_wound("jing", damage);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me, target, 1);
            } else message_vision(HIY
            "但是$N"
            HIY
            "一个箭步蹿开丈许，躲开了这一击！\n"
            NOR, target);
        } else if (yourexp > cpexp) {
            if (random(4) == 0) target->delete("no_busy");
            message_vision(HIG
            "上叁十六路下叁十六路剑气都打在$N的全身穴道上，$N顿时动弹不得。\n"
            NOR, target);
            target->receive_damage("qi", damage);
            target->start_busy(6);
            // target->set("no_busy",no_busy);
        } else {
            message_vision(HIY
            "但是一招用尽，$N气息不受控制，身前露出空门！\n"
            NOR, me);
        }
    }
    me->add_temp("apply/attack", 100);
    me->add_temp("apply/damage", 2000);
    msg = HIW
    "天地合其德－－" + WHT
    "$N" + WHT
    "闪身一剑撇出，人也到了天枢空档，手中利刃直指$n！"
    NOR;
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
    msg = HIW
    "日月合其明－－" + WHT
    "$N" + WHT
    "脚踩地极位，左手诀一指一引，剑在右手振出一朵剑花刺向$n。"
    NOR;
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
    msg = HIW
    "四时合其序－－" + WHT
    "$N" + WHT
    "一剑挥出,看似缓慢而平平无奇，剑剑皆虚，又似剑剑皆实。"
    NOR;
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
    msg = HIG
    "\n鬼神合其吉凶－－" + HIM
    "森森剑影漫天飞舞，忽聚忽分八方游走，疾如迅雷狂泻，分打$n" + HIM
    "各处要害！\n"
    NOR;
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
    me->add_temp("apply/attack", -100);
    me->add_temp("apply/damage", -2000);

    message_vision(HIR + "\n\n$N" + HIR
    "手中本静止着的长剑，忽如灵蛇交剪而出，化作一片光幕，立时发动了三才剑阵！\n"
    NOR, me);


    if (random(target->query("combat_exp")) < max_exp) {
        message_vision(BLU
        "$N" + BLU
        "大惊失色，只觉无数剑影如山崩海啸汹涌而来，剑气迫人肤发，劲道直迫内腑。\n", target);
        target->receive_damage("qi", damage * 2);
        target->receive_wound("qi", damage);
        target->receive_wound("jing", damage / 2);
    }

    message_vision(HIR
    "\n\n$N" + HIR
    "突然化作数个人影，忽聚忽分八方游走，竟以一己之力发动了三才剑阵！\n"
    NOR, me);

    max_exp = me->query("combat_exp");

    if (random(target->query("combat_exp")) < max_exp) {
        message_vision(BLU
        "$N" + BLU
        "大惊失色，只觉剑影山崩海啸，剑气逼人肤发，直迫内腑。\n"
        NOR, target);
        target->receive_damage("qi", damage * 2);
        target->receive_wound("qi", damage);
        target->receive_wound("jing", damage / 2);
    } else {
        message_vision(YEL
        "$N" + YEL
        "不慌不忙，身形晃动，正是剑阵之空门。\n"
        NOR, target);
        me->start_busy(2);
        return 1;
    }
    me->add("neili", -580);
    me->start_busy(5);
    return 1;
}      
