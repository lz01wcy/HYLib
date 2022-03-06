// yijinjing.c 少林 易筋经神功
// Feb.21 1998 by Java
#include <ansi.h>

inherit FORCE;

#include "/kungfu/skill/eff_msg.h";

int valid_enable(string usage) {
    return usage == "force";
}

int valid_learn(object me) {
    int i, nb, nf, oh, nh, ns, ts;
    nb = (int) me->query_skill("buddhism", 1);
    nf = (int) me->query_skill("force", 1);
    oh = (int) me->query_skill("hunyuan-yiqi", 1);
    nh = (int) me->query_skill("yijinjing", 1);
    ns = (int) me->query("guilty");

    if (oh < 100)
        return notify_fail("你的混元一气太低，无法学习易筋经神功！\n");
    if (me->query("couple/have_couple"))
        return notify_fail("你已经破了色戒，无法再学习易筋经神功！\n");

    if (me->query("gender") != "男性")
        return notify_fail("你非童男之体，不能练习易筋经神功。\n");

    if (nb < 100 && nb <= nh)
        return notify_fail("你的禅宗心法修为不够，无法领会更高深的易筋经神功。\n");

    if (nf < 10)
        return notify_fail("你的基本内功火候还不够，无法领会易筋经神功。\n");

    if (ns > 0)
        return notify_fail("你屡犯僧家数戒，无法领会更高深的易筋经神功。\n");

    if (
            me->query_skill("bahuang-gong", 1)
            || me->query_skill("bingxue-xinfa", 1)
            || me->query_skill("wudu-shengong", 1)
            || me->query_skill("beiming-shengong", 1)
            || me->query_skill("bibo-shengong", 1)
            || me->query_skill("hamagong", 1)
            || me->query_skill("huagong-dafa", 1)
            || me->query_skill("huntian-qigong", 1)
            || me->query_skill("jiuyang-shengong", 1)
            || me->query_skill("kuihua-xinfa", 1)
            || me->query_skill("kurong-changong", 1)
            || me->query_skill("linji-zhuang", 1)
            || me->query_skill("longxiang", 1)
            || me->query_skill("shenlong-xinfa", 1)
            || me->query_skill("taiji-shengong", 1)
            || me->query_skill("xiantian-qigong", 1)
            || me->query_skill("xiaowuxiang", 1)
            || me->query_skill("yunv-xinfa", 1)
            || me->query_skill("yunlong-shengong", 1) ||
            me->query_skill("shenghuo-shengong", 1) ||
            me->query_skill("shenyuan-gong", 1) ||
            me->query_skill("huashan-neigong", 1) ||
            me->query_skill("zixia-shengong", 1) ||
            me->query_skill("shayi-xinfa", 1) ||
            me->query_skill("biyun-xinfa", 1) ||
            me->query_skill("xuantian-wuji", 1) ||
            me->query_skill("guiyuan-tunafa", 1))
        return notify_fail("你不先散了别派内功，怎能学易筋经神功？！\n");

    return 1;
}


int practice_skill(object me) {
    return notify_fail("易筋经神功只能用学(learn)的来增加熟练度。\n");
}

mapping exercise_msg(object me) {
    return ([
    "status_msg" : HIR + me->name() + "脸上红光隐现，气象庄严"
    NOR,
            "start_my_msg" : "你五心向天，排除一切杂念，内息顺经脉缓缓流动。\n",
            "start_other_msg" : me->name() + "五心向天，一会工夫，从口鼻处缓缓吐出白气，白气越吐越浓，渐渐笼罩了全身。\n",
            "halt_msg" : "$N长出一口气，将内息急速退了回去，站了起来。\n",
            "end_my_msg" : "你将内息走了个小周天，流回丹田，收功站了起来。\n",
            "end_other_msg" : "只见笼罩" + me->name() + "的白气渐渐消散，又从口鼻处吸了回去。\n",
            "heal_msg" : HIY
    "$N双手合什，盘膝而坐，口中念起“往生咒”，开始运功疗伤。\n"
    NOR,
            "heal_finish_msg" : HIY
    "$N缓缓站起，只觉全身说不出的舒服畅快，便道：“善哉！善哉！本门筋经当真是天下绝学！”\n"
    NOR,
            "heal_unfinish_msg" : "$N吐出瘀血，缓缓站起，但脸色苍白，看来还有伤在身。\n",
            "heal_halt_msg" : "$N一声：“阿弥陀佛”双袖挥动，压下内息，站起身来。\n",
    ]);
}

string *fanzhen_msg = ({
    "只震得$n胸内腹中，有如五脏一齐翻转！\n",
            "抢先反震，将$n震得脸如白纸，全无血色！\n",
            "震得$n心肺欲裂，腾腾腾连退数步！\n",
            "功力已布满全身，将$n的力量反震回去！\n",
            "震得$n天旋地转，腾腾腾连退七八步！\n",
            "和$n一撞，只震的$p胸口气血翻涌！\n",
            "$n便如撞在一堵棉花作面，钢铁为里的厚墙上一般，震退数步！\n",
            "$n刚碰到$P，突然身子一震，登时飞了出去！\n",
});


int ob_hit(object ob, object me, int damage) {
    string msg;
    int p, skill, neili, neili1, i = 1;
    object weapon;
    skill = me->query_skill("yijinjing", 1);
    neili = me->query("neili") + 1;
    neili1 = ob->query("neili") + 1;

    if (skill > 300)
        i += me->query_temp("combat_yield");

    if (living(me)
        && me->query_temp("fanzhen")
        && random(skill) * i + 30 > ob->query_skill("parry", 1) / 2
        && me->query("combat_exp") > ob->query("combat_exp") / 2
        && skill > 199
        && neili > 500
        && living(ob)
        && !ob->query("env/invisibility")
        && random(3) == 0) {
        if (!objectp(weapon = ob->query_temp("weapon"))) {
            me->add("neili", -(10 + random(70)));
            msg = random(2) ? HIR"$N身上生出一股反震之力，":HIR
            "$N身上金刚不坏体神功随心而起，";
            if (neili1 > neili * 4 * i || random(damage) > (5000 + me->query_con() * 40 * i)) {
                msg += "但却被$n的劲力一招震碎！\n"
                NOR;
                damage = random(damage / 2);
            } else if (neili1 > neili * 3 * i) {
                msg += "但却根本无法阻挡$n的劲力！\n"
                NOR;
                damage = 0;
            } else if (neili1 > neili * 3 / 2 * i) {
                msg += "结果抵消了部分$n的劲力！\n"
                NOR;
                damage = -damage / 2;
            } else {
                msg += fanzhen_msg[random(sizeof(fanzhen_msg))] + NOR;
                p = (neili / neili1) * i;
                if (damage < 1) damage = 1;
                if (p < 1) p = 1;
                p *= damage / 2;
                if (ob->query_skill("force") > me->query_skill("force") * 3 / 2) p = p * 2 / 3;
                if (p < 10) p = 10;

                if (ob->query("qi") > p) {
                    ob->receive_damage("qi", p, me);
                    ob->receive_wound("qi", p / 5 * i, me);
                }
                if (wizardp(me)) tell_object(me, "Fanzhen damage: " + p + "。\n");

                p = ob->query("qi") * 100 / ob->query("max_qi");
                msg += "( $n" + eff_status_msg(p) + " )\n";

                damage = -8000 + (-damage);
            }
            message_vision(msg, me, ob);
        } else {
            msg = HIR
            "好似有一堵无形的墙在$N面前阻挡着，";
            switch (weapon->query("skill_type")) {
                case "whip"   :
                    p = 10;
                    break;
                case "sword"  :
                    p = 8;
                    break;
                case "hook"   :
                    p = 6;
                    break;
                case "blade"  :
                    p = 5;
                    break;
                case "club"   :
                case "stick"  :
                    p = 2;
                    break;
                case "staff"  :
                case "axe"    :
                case "hammer" :
                    p = 1;
                    break;
                default       :
                    p = 3;
                    break;
            }
            p *= weapon->query("rigidity");
            if (random(me->query("str") + p) * i > (ob->query("str") + p) / 2 && neili * i > neili1 * 2 / 3) {
                message_vision(HIR
                "结果$N身上生出一股反震之力，$n只觉虎口一热，" + weapon->name() + HIR
                "顿时脱手而出，飞出丈外！\n\n"
                NOR, me, ob);
                weapon->unequip();
                weapon->move(environment(ob));
                ob->reset_action();
                ob->start_busy(2 + random(3));
                return -8000 + (-damage);
            } else if (neili * i > neili1 * 2) {
                msg += "结果$n"
                HIR
                "一下子被反弹，震得" + ob->name() + HIR
                "手臂发麻！\n"
                NOR;
                ob->start_busy(1 + random(3));
                damage = -8000 + (-damage);
            } else if (neili * i > neili1 * 3 / 2) {
                msg += "结果$n"
                HIR
                "不能前进一丝一毫！\n"
                NOR;
                damage = -5000 + (-damage);
            } else if (neili * i > neili1) {
                msg += "结果减缓了$n"
                HIR
                "前进的速度！\n"
                NOR;
                damage = -damage * 3 / 2;
            } else if (neili * 2 * i > neili1) {
                msg += "但并没有起到什么作用！\n"
                NOR;
                damage = 0;
            } else {
                msg += "但却被$n"
                HIR
                "一下打破！\n"
                NOR;
                damage = random(damage / 2);
            }
            message_vision(msg, me, weapon);
        }
        return damage;
    }
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string attack_skill) {
    int skill;
    int i = 1, j;

    if (!me->query_temp("fanzhen") && !me->query_temp("sl/jiuyang"))
        return 1;

    skill = me->query_skill("force");

    i = damage_bonus * (skill + 1) / 1000;
    i = i / 2 + random(i);
    if (me->query_temp("weapon"))
        i = i * 3;
    if (me->query_temp("apply/damage") >= 100)
        i = i / 3;
    if (i < 1) i = 1;
    if (wizardp(me)) tell_object(me, sprintf("hit_ob: %d  ", i));
    j = me->query_skill("yijinjing", 1) / 20;
    if (j < 1) j = 1;
    if (random(2) == 0) {
        message_vision(HIR
        "$N" + HIR + "高喧一声佛号，将体内九阳真气聚于双臂，狭雷霆之势攻向$n！\n"
        NOR, me, victim);
        victim->receive_damage("qi", 10 + 3 * random(j), me);
        victim->receive_wound("qi", 10 + 3 * random(j), me);
    }
    //i = i + ::force_hit(me,victim,damage_bonus,factor,attack_skill);

    return i;
}


string exert_function_file(string func) {
    return __DIR__
    "yijinjing/" + func;
}
