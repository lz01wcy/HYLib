#include <ansi.h>
#include <weapon.h>

inherit M_WEAPON;
inherit F_GEMS;
string *du = ({
    "ice_poison",
            "ill_dongshang",
            "ill_fashao",
            "ill_kesou",
            "ill_shanghan",
            "ill_zhongshu",
            "xx_poison",
            "cold_poison",
            "flower_poison",
            "rose_poison",
            "x2_poison",
            "sanpoison",
            "scorpion_poison",
            "qx_snake_poison",
            "anqi_poison",
            "yf_poison",
            "nx_poison",
            "chilian_poison",
            "yufeng_poison",
            "insect_poison",
            "xscold_poison",
});

void init_sockets(object me) {
    set("max_sockets", 3);
    if (me->query("combat_exp") > 10000000)
        add("max_sockets", 1);

    if (me->query("combat_exp") < 10000000 && (int) query("sockets/max", 1) >= 3)
        set("sockets/max", 3);

    if (me->query("combat_exp") < 20000000 && (int) query("sockets/max", 1) >= 4)
        set("sockets/max", 4);

    if ((int) query("sockets/max", 1) > 5)
        set("sockets/max", 5);

    if (me->query("diablo/weapon/id") != query("id")) return;

    set("sockets", me->query("diablo/weapon/sockets"));
    set_weapon_desc();
}

void setup() {
    init_sockets(this_player());
    ::setup();
}

void spec_prop(object me, string socket, int socket_level, int mode) {
    int i;
    if (!valid_gem(socket, socket_level)) return;
    if (me->query("diablo/weapon/id") != query("id")) return;
    if (query("weapon_prop/damage") < 20) return;
    switch (socket) {
        case "ruby":
            break;
        case "topaz":
            break;
        case "sapphire":
            break;
        case "emerald":
            break;
        case "amethyst":
            if (mode == 1)
                message_vision(MAG + query("name") + MAG
            "发出柔和的光芒围绕着$N，激发了$P的战斗力！\n"
            NOR, me);
            else
            message_vision(MAG
            "随着紫色光芒慢慢的散去，$N的战斗力又复原了。\n"
            NOR, me);
            me->add_temp("apply/attack", 30 * socket_level * mode);
            break;
        case "diamond":
            if (mode == 1)
                message_vision(HIW
            "只见一道白光直透" + query("name") + HIW
            "，威力猛然大增！\n"
            NOR, me);
            else
            message_vision(HIW
            "白光渐渐隐入了" + query("name") + HIW
            "。\n"
            NOR, me);
            me->add_temp("apply/damage", query("weapon_prop/damage") * socket_level * mode / 16);
            break;
        case "skull":
            break;
    }
    return;
}

int wield() {
    int i, sockets, ret;
    object me = environment();

    if (!(ret = ::wield())) return 0;
    sockets = query("sockets/max");
    for (i = 1; i <= sockets; i++)
        spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), 1);
    return ret;
}

int unequip() {
    int i, sockets, ret;
    object me = environment();

    if (!(ret = ::unequip())) return 0;
    sockets = query("sockets/max");
    for (i = 1; i <= sockets; i++)
        spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), -1);
    return ret;
}

string spec_effect(object me, object victim, int damage_bonus, string socket, int socket_level) {
    int damage;
    string msg = "";
    object weapon;

    if (!valid_gem(socket, socket_level)) return msg;
    if (random(100) + me->query_temp("apply/magic") < 70) return msg;
    if (me->query("diablo/weapon/id") != query("id")) return msg;
    switch (socket) {
        case "ruby":
            msg = HIR
            "一道红光猛的击中了$n，$p只觉得浑身一阵巨痛！\n"
            NOR;
            damage = damage_bonus * socket_level / 7;
            if (damage < 1) damage = 1;
            if (damage > 300 * socket_level / 7)
                damage = 300 * socket_level / 7;
            if (damage > (int) victim->query("qi") / 7) damage = (int) victim->query("qi") / 7;
            if ((int) victim->query("qi") + 50 > damage)
                victim->receive_wound("qi", damage);
            if (wizardp(me))
                tell_object(me, sprintf("气血受伤：%d\n", damage));
            break;
        case "topaz":
            msg = HIY
            "一道黄光猛的击中了$n，$p只觉得意思越来越模糊！\n"
            NOR;
            damage = damage_bonus * socket_level / 15;
            if (damage > 300 * socket_level / 15)
                damage = 300 * socket_level / 15;
            if (damage < 1) damage = 1;
            if (damage > (int) victim->query("jing") / 5) damage = (int) victim->query("jing") / 5;
            if ((int) victim->query("jing") + 50 > damage) {
                victim->receive_damage("jing", damage);
                victim->receive_wound("jing", random(damage));
            }
            if (wizardp(me))
                tell_object(me, sprintf("jing damage is: %d\n", damage));
            break;
        case "sapphire":
            if (!victim->is_busy())
                msg = HIB
            "一道奇异的蓝光包围着$n，$p只觉天旋地转，身体无法动弹！\n"
            NOR;
            victim->start_busy(random(socket_level) + 3);
            break;
        case "emerald":
            if (!victim->query_condition("emerald_poison")) {
                msg = HIG
                "$n只见一道绿气迅速的从伤口渗入了$p的经脉！\n"
                NOR;
                victim->apply_condition("emerald_poison", victim->query_condition("emerald_poison") + random(5) + 8);
                victim->set("emerald_poison", socket_level);
                victim->apply_condition("snake_poison", victim->query_condition("snake_poison") + random(5) + 8);
                victim->apply_condition("zhizhu_poison", victim->query_condition("zhizhu_poison") + random(5) + 8);
                victim->apply_condition("wugong_poison", victim->query_condition("wugong_poison") + random(5) + 8);
                victim->apply_condition("xiezi_poison", victim->query_condition("xiezi_poison") + random(5) + 8);
                victim->apply_condition("chanchu_poison", victim->query_condition("chanchu_poison") + random(5) + 8);

            }
            break;
        case "amethyst":
            break;
        case "diamond":
            if (objectp(weapon = victim->query_temp("weapon"))) {
                if (random(query("weapon_prop/damage")) > weapon->query("weapon_prop/damage") / 2
                    && random(me->query("str")) > victim->query("str") / 2
                    && random(6) == 0) {
                    victim->start_busy(random(socket_level) + 3);
                    if (query("skill_type") == "sword" || query("skill_type") == "blade" ||
                        query("skill_type") == "axe") {
                        message_vision(HIW
                        "只听见「哐」地一声轻响，$N手中的" + weapon->query("name") + HIW
                        "已经被" + query("name") + HIW
                        "削为两截！\n"
                        NOR, victim);
                        weapon->unequip();
                        weapon->move(environment(victim));
                        weapon->set("name", "断掉的" + weapon->query("name"));
                        weapon->set("value", 0);
                        weapon->set("weapon_prop", 0);
                        victim->reset_action();
                    };
                    if (query("skill_type") == "staff" || query("skill_type") == "hammer" ||
                        query("skill_type") == "club") {
                        message_vision(HIW
                        "$N只觉得手中" + weapon->query("name") + HIW
                        "把持不定，脱手飞出！\n"
                        NOR, victim);
                        weapon->unequip();
                        weapon->move(environment(victim));
                        victim->reset_action();
                    };
                    if (query("skill_type") == "whip") {
                        message_vision(HIW
                        "只听见「唰」地一声轻响，$N手中的" + weapon->query("name") + HIW
                        "已经被" + query("name") + HIW
                        "卷为两截！\n"
                        NOR, victim );
                        weapon->unequip();
                        weapon->move(environment(victim));
                        weapon->set("name", "断掉的" + weapon->query("name"));
                        weapon->set("value", 0);
                        weapon->set("weapon_prop", 0);
                        victim->reset_action();
                    };
                } else if (random(3) == 0) {
                    victim->start_busy(random(socket_level) + 3);
                    damage = damage_bonus * socket_level / 8;
                    if ((int) victim->query("qi") + 100 > damage)
                        victim->receive_damage("qi", damage + socket_level * 30);
                    if ((int) victim->query("jing") + 100 > damage)
                        victim->receive_damage("jing", random(damage));
                    message_vision(HIW
                    "只见白光一闪，$N被划出了很长的一道伤口！\n"
                    NOR, victim);

                }
            }
            break;
        case "skull":
            msg = WHT
            "忽然间，$n只觉鬼哭狼嚎声不绝于耳，三魂六魄都给吸了出去！\n"
            NOR;
            damage = damage_bonus * socket_level / 15;
            if (damage > 300 * socket_level / 15)
                damage = 300 * socket_level / 15;
            if (victim->query("qi") < damage)
                damage = victim->query("qi");
            if (damage > 0) {
                if ((int) victim->query("qi") + 100 > damage) {
                    if (damage > (int) victim->query("qi") / 5) damage = (int) victim->query("qi") / 5;
                    victim->receive_damage("qi", damage + socket_level * 30);
                    victim->receive_wound("qi", random(damage) + socket_level * 30);
                    me->add("qi", damage / 2);
                }
                if (me->query("qi") > me->query("eff_qi"))
                    me->set("qi", me->query("eff_qi"));
                if (wizardp(me))
                    tell_object(me, sprintf("suck qi: %d\n", damage));
            }
            damage = damage_bonus * socket_level / 25;
            if (victim->query("neili") < damage)
                damage = victim->query("neili");
            if (damage > 0) {
                if ((int) victim->query("neili") + 100 > damage) {
                    if (damage > (int) victim->query("qi") / 5) damage = (int) victim->query("qi") / 5;
                    victim->add("neili", -damage);
                    me->add("neili", damage / 2);
                }
                if (me->query("neili") > me->query("max_neili") * 2)
                    me->set("neili", me->query("max_neili") * 2);
                if (wizardp(me))
                    tell_object(me, sprintf("suck neili: %d\n", damage));
            }
            break;
        case "windjade":
            if (!victim->is_busy()) {
                msg = GRN
                "飞舞在空中的无形之利刃包围着$n，$p只觉寸步难行！\n"
                NOR;
                victim->start_busy(random(socket_level) + 2);
                if (victim->query("apply/dodge", 1) >= -200)
                    victim->add_temp("apply/dodge", -(6 * socket_level));
                if (victim->query("apply/defense", 1) >= -200)
                    victim->add_temp("apply/defense", -(6 * socket_level));
            }
            break;
        case "firejade":
            msg = RED
            "一道火光一闪，划过了$n，$p只觉得伤口一阵烫痛！\n"
            NOR;
            damage = damage_bonus * socket_level / 8;
            if (damage < 1) damage = 1;
            if (damage > 300 * socket_level / 8)
                damage = 300 * socket_level / 8;
            if (damage > (int) victim->query("qi") / 8) damage = (int) victim->query("qi") / 8;
            if ((int) victim->query("qi") + 10 > damage)
                victim->receive_wound("qi", damage + socket_level * 30);
            victim->add_temp("apply/defense", -(6 * socket_level));
            break;
        case "icejade":
            msg = CYN
            "冲天的寒气突然包围了$n，$p只觉得全身都冻僵了！\n"
            NOR;
            damage = damage_bonus * socket_level / 8;
            if (damage < 1) damage = 1;
            if (damage > 300 * socket_level / 8)
                damage = 300 * socket_level / 8;
            if (damage > (int) victim->query("qi") / 8) damage = (int) victim->query("qi") / 8;
            if ((int) victim->query("qi") + 10 > damage)
                victim->receive_damage("qi", damage + socket_level * 30);
            victim->receive_wound("qi", random(damage) + socket_level * 30);
            if ((int) victim->query("jing") + 10 > damage)
                victim->receive_damage("jing", damage);
            victim->start_busy(random(socket_level) + 2);
            victim->add_temp("apply/attack", -(6 * socket_level));
            break;
        case "thunderjade":
            msg = MAG
            "一道闪电一闪而过击中了$n，$p只觉得全身又痛又麻！\n"
            NOR;
            damage = damage_bonus * socket_level / 8;
            if (damage < 1) damage = 1;
            if (damage > 300 * socket_level / 8)
                damage = 300 * socket_level / 8;
            if (damage > (int) victim->query("qi") / 8) damage = (int) victim->query("qi") / 8;
            victim->add("neili", -damage + socket_level * 30);
            if ((int) victim->query("jing") + 10 > damage)
                victim->start_busy(random(socket_level) + 3);
            victim->receive_wound("jing", damage);
            break;
        case "earthjade":
            if (!victim->is_busy())
                msg = YEL
            "黄色的烟雾从地上出现包围了$n，$p只觉气血一阵逆流！\n"
            NOR;
            victim->start_busy(random(socket_level) + 1);
            victim->apply_condition(du[random(sizeof(du))], socket_level * 3);
            victim->apply_condition(du[random(sizeof(du))], socket_level * 3);
            victim->apply_condition(du[random(sizeof(du))], socket_level * 3);
            victim->apply_condition(du[random(sizeof(du))], socket_level * 3);
            victim->apply_condition(du[random(sizeof(du))], socket_level * 3);
            victim->apply_condition(du[random(sizeof(du))], socket_level * 3);
            break;
    }
    return msg;
}

mixed hit_ob(object me, object victim, int damage_bonus) {
    int i, sockets;
    string msg = "";

    sockets = query("sockets/max");
    for (i = 1; i <= sockets; i++)
        msg += spec_effect(me, victim, damage_bonus,
                           query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)));
    return msg;
}
