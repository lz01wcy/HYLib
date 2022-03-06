// jiuyang-shengong.c 九阳神功
// cleansword
// Modified by Venus Oct.1997
#include <ansi.h>
#include <combat.h>

inherit FORCE;

string check() { return "force"; }

int valid_enable(string usage) {
    object me = this_player();
    int lvl;
    lvl = (int) this_player()->query_skill("jiuyang-shengong", 1);

    if (lvl >= 280 && me->query("jiuyangok"))
        return usage == "force" || usage == "unarmed" || usage == "parry"
               || usage == "sword" || usage == "blade";
    else
        return usage == "force";

}

int valid_learn(object me) {
    int lvl = (int) me->query_skill("jiuyang-shengong", 1);

    if ((int) me->query_skill("force", 1) < 10)
        return notify_fail("你的基本内功火候还不够，还不能学习九阳神功。\n");

    if (
            me->query_skill("bahuang-gong", 1)
            || me->query_skill("beiming-shengong", 1)
            || me->query_skill("bibo-shengong", 1)
            || me->query_skill("hamagong", 1)
            || me->query_skill("huagong-dafa", 1)
            || me->query_skill("huntian-qigong", 1)
            || me->query_skill("hunyuan-yiqi", 1)
            || me->query_skill("kuihua-xinfa", 1)
            || me->query_skill("kurong-changong", 1)
            || me->query_skill("linji-zhuang", 1)
            || me->query_skill("longxiang", 1)
            || me->query_skill("shenlong-xinfa", 1)
            || me->query_skill("taiji-shengong", 1)
            || me->query_skill("xiantian-qigong", 1)
            || me->query_skill("xiaowuxiang", 1)
            || me->query_skill("yijinjing", 1)
            || me->query_skill("yunv-xinfa", 1)
            || me->query_skill("yunlong-shengong", 1) ||
            me->query_skill("bingxue-xinfa", 1) ||
            me->query_skill("wudu-shengong", 1) ||
            me->query_skill("shenyuan-gong", 1) ||
            me->query_skill("huashan-neigong", 1) ||
            me->query_skill("zixia-shengong", 1) ||
            me->query_skill("xuantian-wuji", 1) ||
            me->query_skill("shayi-xinfa", 1) ||
            me->query_skill("biyun-xinfa", 1) ||
            me->query_skill("guiyuan-tunafa", 1))
        return notify_fail("你不先散了别派内功，怎能学九阳神功？！\n");
    return 1;
}

mapping *actionf = ({
    ([      "action": "$N飞身一跃而起，身法陡然加快，朝着$n$l快速攻出数十拳",
            "force" : 510,
            "attack": 190,
            "dodge" : 100,
            "parry" : 90,
            "damage": 280,
            "weapon": HIR
    "九阳无极劲"
    NOR,
            "damage_type":  "刺伤"
    ]),
    ([      "action": "$N沉身运气，一拳击向$n，刹那间，$N全身竟浮现出一道金光",
            "force" : 510,
            "attack": 185,
            "dodge" : 90,
            "parry" : 120,
            "damage": 275,
            "weapon": HIR
    "九阳无极劲"
    NOR,
            "damage_type":  "刺伤"
    ]),
    ([      "action": "$N将九阳神功运劲于臂，一掌凌空劈斩而出，划出一道炽热的黄芒",
            "force" : 530,
            "attack": 175,
            "dodge" : 90,
            "parry" : 110,
            "damage": 200,
            "weapon": HIR
    "九阳无极劲"
    NOR,
            "damage_type":  "割伤"
    ]),
    ([      "action": "$N跨步上前，身形微微一展，双掌对准$n$l一并攻出",
            "force" : 525,
            "attack": 185,
            "dodge" : 85,
            "parry" : 115,
            "damage": 285,
            "weapon": HIR
    "九阳无极劲"
    NOR,
            "damage_type":  "刺伤"
    ]),
    ([      "action": "$N急催九阳神功内劲，猛的一拳在呼啸声中陡然挥击而出",
            "force" : 530,
            "attack": 165,
            "dodge" : 90,
            "parry" : 115,
            "damage": 300,
            "weapon": HIR
    "九阳无极劲"
    NOR,
            "damage_type":  "刺伤"
    ]),
    ([      "action": "$N一声暴喝，十指暮的张开，一股雄厚的内劲澎湃而出",
            "force" : 540,
            "attack": 200,
            "dodge" : 115,
            "parry" : 120,
            "damage": 280,
            "weapon": HIR
    "九阳无极劲"
    NOR,
            "damage_type":  "割伤"
    ]),
});

mapping *actionw = ({
    ([      "action" : "$N攻势忽缓而不疏，$w变化无常，捉摸不定向$n慢慢卷去",
            "force" : 330,
            "attack": 140,
            "dodge" : 35,
            "parry" : 85,
            "damage": 325,
            "damage_type": "内伤"
    ]),
    ([      "action":"$N手中的$w突焕气象森严，便似千军万马奔驰而来，$w幻作一道红芒贯向$n",
            "force" : 310,
            "attack": 120,
            "dodge" : 25,
            "parry" : 25,
            "damage": 310,
            "damage_type": "刺伤"
    ]),
    ([      "action":"$N卷起手中的$w，霎时剑芒暴涨，宛如骄阳烈火直射向$n而去",
            "force" : 340,
            "attack": 115,
            "dodge" : 20,
            "parry" : 25,
            "damage": 365,
            "damage_type": "刺伤"
    ]),
    ([      "action":"$N运用$w幻化做一个一个圆圈，顿时无数火圈将$n团团包围",
            "force" : 285,
            "attack": 110,
            "dodge" : 25,
            "parry" : 25,
            "damage": 390,
            "damage_type": "内伤"
    ]),
    ([      "action":"$N回转$w遥指$n，顿时$w顶端顿时透出一道吞吐不定的火光，电射而出",
            "force" : 330,
            "attack": 118,
            "dodge" : 10,
            "parry" : 20,
            "damage": 420,
            "damage_type": "刺伤"
    ]),
});

mapping query_action(object me, object weapon) {
    return weapon ? actionw[random(sizeof(actionw))] :
           actionf[random(sizeof(actionw))];
}

int practice_skill(object me) {
    return notify_fail("九阳神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func) {
    return __DIR__
    "jiuyang-shengong/" + func;
}

mixed ob_hit(object me, object victim, int damage, int damage_bonus, int factor) {
    object weapon1 = me->query_temp("weapon");
    object weapon2 = victim->query_temp("weapon");

    int ap, dp;
    string result;

    ap = (int) me->query("combat_exp", 1) + (int) victim->query_skill("parry", 1);

    dp = victim->query("combat_exp", 1);
    if (objectp(weapon1))
        dp += victim->query_skill("dodge");
    if (random(me->query_skill("jiuyang-shengong", 1)) > 120
        && me->query("neili") < me->query("max_neili")
        && me->query_skill_mapped("force") == "jiuyang-shengong"
            ) {
        message_vision(HIR
        "$N运起九阳神功，全身内力源源不断的涌出!\n"
        NOR, me, victim);
        me->add("neili", random(me->query_skill("jiuyang-shengong", 1)) + 100);
    }

    if (random(me->query_skill("jiuyang-shengong", 1)) > 120
        && me->query("qi") < me->query("max_qi")
        && me->query_skill_mapped("force") == "jiuyang-shengong"
            ) {
        message_vision(RED
        "$N运起九阳神功，身上的伤好了很多!\n"
        NOR, me, victim);
        me->add("qi", random(me->query_skill("jiuyang-shengong", 1)) + 180);
        if (me->query("eff_qi") < me->query("max_qi"))
            me->add("eff_qi", random(me->query_skill("jiuyang-shengong", 1)) + 180);
    }


    if (random(me->query_skill("qiankun-danuoyi", 1)) > 120
        && me->is_busy()
        && me->query_skill_mapped("force") == "jiuyang-shengong"
        && random(2) == 0
            ) {
        message_vision(HIC
        "$N暗运乾坤大挪移，本来忙乱的动作快了起来!\n"
        NOR, me, victim);
        me->start_busy(1);
    }
    if (random(ap) > dp / 3
        && me->query("jiuyangok")
        && (int) me->query_temp("shield")
        && me->query_skill_mapped("force") == "jiuyang-shengong"
            ) {
        if (objectp(weapon1)) {
            if (damage + damage_bonus > 0) {
                damage_bonus = -damage / 3;
                result = HIM
                "$n身子一侧，将$N兵刃上的力道卸去大半。\n"
                NOR;
            } else {
                result = MAG
                "$n身子一侧，将$N兵刃上的力道卸去大半。\n"
                NOR;
                damage_bonus = -damage / 3;
            }
        } else if (!objectp(weapon1)) {
            if (damage + damage_bonus > 0) {
                damage_bonus = -damage / 2;
                result = HIG
                "$n九阳神功自然而然发出抗力，将$N的力道一挡。\n"
                NOR;
            } else {
                result = MAG
                "$n九阳神功自然而然发出抗力，将$N的力道一挡。\n"
                NOR;
                damage_bonus = -damage / 2;
            }
        }

    }
    if (result)
        message_vision(result, me, victim);
    return damage;
}


string perform_action_file(string action) {
    return __DIR__
    "jiuyang-shengong/perform/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus) {
    int lvl;

    lvl = me->query_skill("jiuyang-shengong", 1);

    if (damage_bonus < 50
        || lvl < 150
        || me->query("neili") < 300
        || me->query_skill_mapped("force") != "jiuyang-shengong"
        || me->query_skill_mapped("unarmed") != "jiuyang-shengong"
        || !me->query("jiuyangok"))
        return 0;

    if (damage_bonus / 5 > victim->query_con() || random(10) == 0) {
        me->add("neili", -50);
        victim->receive_wound("qi", (damage_bonus - 80) / 2 + 10, me);
        return random(2) ? HIR "只见$N"
        HIR
        "九阳内劲自体内迸发，真气随招式"
        "而荡漾，摧毁了$n"
        HIR
        "的真元！\n"
        NOR:

        HIR
        "$N"
        HIR
        "九阳神功的潜力发挥了出来，突然间$n"
        HIR
        "只感喉咙一甜，喷出一口鲜血！\n"
        NOR;
    }
}