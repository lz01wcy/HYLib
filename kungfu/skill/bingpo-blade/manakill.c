// made by cii for snow
#include <command.h>
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target) {
    string msg;
    int ski_value, max_lv;
    object weapon;
    ski_value = random(me->query_skill("bingpo-blade", 1));
    max_lv = me->query_skill("bingpo-blade", 1);

    if (!target) target = offensive_target(me);
    if (!target
        || !target->is_character()
        || !me->is_fighting(target))
        return notify_fail("『魔气杀』只能对战斗中的对手使用。\n");
    if (!objectp(weapon = me->query_temp("weapon")) ||
        (string) weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对，难以施展。\n");

    if (me->query_skill("bingpo-blade", 1) < 300)
        return notify_fail("你的冰破寒刀技巧不足。 \n");
    if ((int) me->query_skill("huagong-dafa", 1) < 125)
        return notify_fail("你的化功大法火候不够.\n");
    if (me->query_skill("blade", 1) < 100)
        return notify_fail("你的刀法不够好。 \n");
    if (me->query("neili") < 1000)
        return notify_fail("你的内力不够。\n");
    //if( target->is_busy() )
    //   return notify_fail(target->name() + "为了躲避你的杀气,目前正自顾不暇!\n");
    msg = HIY
    "$N自残己身,以血气转换成杀气。\n
    ……$N身上发出一股强大的杀气……\n
    ■$N身上杀气逐渐地聚集在双手, 在双手上形成两团魔气■\n
    $N倏地大喝一声－－魔
            气
    杀－－\n\n
    " NOR;

    if (ski_value + 50 < random(max_lv) && me->query("combat_exp") > 2000000) {
        msg += HIR
        BLINK
        "$N突然喉头一动～～　只见$N口中喷出一道血柱往$n射去～～\n
        此乃魔气杀之
        最终杀招 『魔
                血
        气
        杀』\n\n
        $n遭到前所未有的打击, 但$N也受伤不轻。\n
        " NOR;
        target->start_busy((int) me->query_skill("bingpo-blade") / 60 + 3);
        if (userp(target)) {
            target->receive_damage("qi", target->query("max_qi") * 70 / 100);
            me->receive_damage("qi", me->query("qi") * 30 / 100);
        } else {
            target->receive_wound("qi", ski_value * 8);
            me->receive_damage("qi", me->query("qi") * 20 / 100);

        }
        me->add("neili", -50);
    } else if (ski_value < 20) {
        msg += "$N真气所转换的杀气不够大,对敌人毫无影响。\n";
        me->receive_damage("qi", me->query("qi") * 1 / 100);
        me->add("neili", -me->query("max_neili") * 3 / 10);
    }
    message_vision(msg, me, target);

    me->add_temp("apply/attack", 100);
    me->add_temp("apply/damage", 1000);

    if (ski_value > 70) {
        msg = HIM
        "第一招 『魔气无常』\n"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);

    }

    if (ski_value > 90) {
        msg = HIG
        "第二招 『火魔煞神』\n"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);

    }

    if (ski_value > 100) {
        msg = HIC
        "第三招 『商魂魔身』\n"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);

    }

    if (ski_value > 120) {
        msg = HIB
        "第四招 『剑魔灭世』\n"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);

    }

    if (ski_value > 140) {
        msg = HIW
        "第五招 『狂魔破空』\n"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);

    }


    if (ski_value > 160) {
        msg = CYN
        "第六招 『群魔乱舞』\n"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
    }

    if (ski_value > 180) {
        msg = YEL
        "第七招 『天极魔杀』\n"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);

    }

    if (ski_value > 200) {
        msg = BLU
        "第八招 『斗魔无生魂』\n"
        NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
    }

    if (ski_value > 300) {
        {
            msg = RED
            "第九招 『风魔狂转业』\n"
            NOR;
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);

        }

        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1000);
        me->start_busy(3);
        return 1;

    }
}
