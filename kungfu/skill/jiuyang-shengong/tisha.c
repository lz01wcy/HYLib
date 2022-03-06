// tisha.c 踢沙 
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

void remove_effect(object me, int f, int j);

int exert(object me, object target) {
    object weapon;
    int damage, p;
    string msg, dodge_skill;
    int f = me->query_skill("jiuyang-shengong", 1) / 4;
    int j = me->query("jiali") / 5 + 20;

    if (!target)
        return notify_fail(WHT
    "你要对谁使用「圣火绝学」。\n"
    NOR);

    if (!target) target = offensive_target(me);


    if (!target
        || !me->is_fighting(target)
        || !living(target)
        || environment(target) != environment(me))
        return notify_fail(WHT
    "「圣火绝学」只能对战斗中的对手使用。\n"
    NOR);

    if ((int) me->query_skill("shenghuo-ling", 1) < 180)
        return notify_fail(WHT
    "你的圣火令法功力太浅，不能使用。\n"
    NOR);

    if ((int) me->query_skill("jiuyang-shengong", 1) < 120)
        return notify_fail(WHT
    "你的九阳神功功力太浅，不能使用。\n"
    NOR);

    if (!me->query("jiuyangok"))
        return notify_fail("你虽然听说过九阳神功可以破敌，但不会用。\n");

    if ((int) me->query_skill("qiankun-danuoyi", 1) < 180)
        return notify_fail(WHT
    "你的乾坤大挪移功力太浅，不能使用。\n"
    NOR);

    if ((int) me->query("max_neili") < 2500)
        return notify_fail(WHT
    "你的内力太浅，不能使用。\n"
    NOR);

    if ((int) me->query("jing") < 100)
        return notify_fail(WHT
    "你的精不够，不能使用。\n"
    NOR);

    if ((int) me->query("neili") < 500)
        return notify_fail(WHT
    "你的真气不够，不能使用。\n"
    NOR);

    if (me->query_temp("shlf_ji", 1))
        return notify_fail(WHT + target->name() + "已经被你的「击」字诀所迷惑，你可以放心的攻击了。\n"
    NOR);

    if (!objectp(weapon = me->query_temp("weapon"))
        || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "shenghuo-ling"
        || me->query_skill_mapped("force") != "jiuyang-shengong"
        || me->query_skill_mapped("parry") != "qiankun-danuoyi"
            )
        return notify_fail(WHT
    "你不能使用这个绝招！\n"
    NOR);


    me->add("neili", -400);
    me->add("jing", -20);
    if (!me->query_temp("ling")) {
        me->set_temp("shlf/sh", 1);
        me->add_temp("apply/attack", f);
        me->add_temp("apply/damage", j);
    }


    message_vision(HIM
    "\n$N突然横腿疾扫，卷起地下大片沙石，身子一分为二，前后夹击、连攻四招！\n"
    NOR, me);
    msg = YEL
    "$N横腿疾扫 一分为二！\n"
    NOR;
    if (!target->is_busy()) target->start_busy(2);
    COMBAT_D->do_attack(me, target, weapon, TYPE_REGULAR, msg);
//        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
    if (present(target, environment(me)) && me->is_fighting(target))
        msg = HIY
    "$N卷起沙石 前后夹击！\n"
    NOR;
    COMBAT_D->do_attack(me, target, weapon, TYPE_REGULAR, msg);
//        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

    if (present(target, environment(me)) && me->is_fighting(target)) {
        msg = CYN
        "\n$n在霎时之间，但觉飞雪扑面，双眼不能见物，茫然不知所措，$N趁势用"
        YEL
        "肩部"
        CYN
        "从背后向$n撞去！\n"
        NOR;
        if (random(me->query("combat_exp")) > target->query("combat_exp") / 3 && living(target)) {
            damage = (int) me->query_skill("force");  //以基本内功和九阳神功的高低，取决杀伤力的大小！
            damage = damage + random(damage);
            damage += (int) me->query_skill("jiuyang-shengong", 1);
            if (damage < target->query("qi") || userp(target)) {
                target->receive_damage("qi", damage * 2);
                target->receive_wound("qi", damage);
            }
            msg += HIR
            "结果$n被$N的"
            YEL
            "肩部"
            HIR
            "一撞，后心有如受到一记重锤，向前急冲了五六步！\n"
            NOR;
            p = (int) target->query("qi") * 100 / (int) target->query("max_qi");
            msg += "( $n" + eff_status_msg(p) + " )\n";
        } else {
            dodge_skill = target->query_skill_mapped("dodge");
            if (!dodge_skill) dodge_skill = "dodge";
            msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        message_vision(msg, me, target);
    } else {

        if (me->query_temp("shlf/sh")) {
            me->add_temp("apply/attack", -f);
            me->add_temp("apply/damage", -j);
            me->delete_temp("shlf/sh");
        }
        me->start_busy(2);

        return 1;
    }
    if (present(target, environment(me)) && me->is_fighting(target)) {
        msg = CYN
        "\n$N随着$n的去式，巧运"
        HIR
        "乾坤大挪移神功"
        CYN
        "，钻到$n的身前，将手中令牌向$n的腹部插去！\n"
        NOR;
        if (random(me->query("combat_exp")) > target->query("combat_exp") / 3 && living(target)) {
            me->start_busy(2);
            damage = (int) me->query_skill("force");  //以基本内功和九阳神功的高低，取决杀伤力的大小！
            damage += (int) me->query_skill("shenghuo-ling", 1);
            damage += (int) me->query_skill("jiuyang-shengong", 1);
            damage = damage + random(damage / 2);
            if (damage < target->query("qi") || userp(target)) {
                target->receive_damage("qi", damage * 2);
                target->receive_wound("qi", damage);
            }
            msg += HIR
            "结果$n一声惨嚎，$N已将$n的"
            HIY
            "护体真气"
            HIR
            "打碎，武器插入$n的"
            HIY
            "小腹"
            HIR
            "，将$n的肋骨根根绞断！\n"
            NOR;
            p = (int) target->query("qi") * 100 / (int) target->query("max_qi");
            msg += "( $n" + eff_status_msg(p) + " )\n";
        } else {
            me->start_busy(1);
            dodge_skill = target->query_skill_mapped("dodge");
            if (!dodge_skill) dodge_skill = "dodge";
            msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        message_vision(msg, me, target);
    } else {

        if (me->query_temp("shlf/sh")) {
            me->add_temp("apply/attack", -f);
            me->add_temp("apply/damage", -j);
            me->delete_temp("shlf/sh");
        }
        me->start_busy(2);

        return 1;
    }

    if (me->query_temp("shlf/sh")) {
        me->add_temp("apply/attack", -f);
        me->add_temp("apply/damage", -j);
        me->delete_temp("shlf/sh");
    }
    me->start_busy(2);
    return 1;
}
