// huanyin-zhi.c
#include <ansi.h>

inherit SKILL;

mapping *action = ({
    ([      "action": "$N一直戳出，幻起一团指影，逼向$n的$l",
            "force" : 250,
            "attack": 19,
            "parry" : 22,
            "dodge" : 18,
            "damage": 228,
            "lvl"   : 0,
            "damage_type" : "刺伤"
    ]),
    ([      "action": "$N全身之力聚于一指，直指向$n的胸前",
            "force" : 270,
            "attack": 36,
            "parry" : 31,
            "dodge" : 28,
            "damage": 235,
            "lvl"   : 30,
            "skill_name" : "天似无情",
            "damage_type" : "刺伤"
    ]),
    ([      "action": "$N提身却步，右手忽的点出，向$n的$l划过",
            "force" : 290,
            "attack": 39,
            "parry" : 22,
            "dodge" : 38,
            "damage": 245,
            "lvl"   : 60,
            "skill_name" : "情根深种",
            "damage_type" : "刺伤"
    ]),
    ([      "action": "$N轻声吐气，双指飞似的刺向$n的额、颈、肩、臂、胸、背",
            "force" : 300,
            "attack": 47,
            "parry" : 42,
            "dodge" : 35,
            "damage": 248,
            "lvl"   : 90,
            "skill_name" : "情在天涯",
            "damage_type" : "刺伤"
    ]),
    ([      "action": "$N左掌掌心向外，右指蓄势点向$n的$l",
            "force" : 330,
            "attack": 55,
            "parry" : 50,
            "dodge" : 48,
            "damage": 55,
            "lvl"   : 120,
            "skill_name" : "独饮情伤",
            "damage_type" : "刺伤"
    ]),
    ([      "action": "$N右手伸出，十指叉开，小指拂向$n的太渊穴",
            "force" : 350,
            "attack": 70,
            "parry" : 60,
            "dodge" : 58,
            "damage": 260,
            "lvl"   : 150,
            "skill_name" : "无诉别情",
            "damage_type" : "刺伤"
    ]),
});

int valid_enable(string usage) { return usage == "finger" || usage == "parry"; }


int valid_learn(object me) {
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练幻阴指法必须空手。\n");

    if ((int) me->query_skill("force") < 200)
        return notify_fail("你的内功火候不够，无法学幻阴指法。\n");

    if ((int) me->query("max_neili") < 800)
        return notify_fail("你的内力太弱，无法练幻阴指法。\n");

    if ((int) me->query_skill("finger", 1) < (int) me->query_skill("huanyin-zhi", 1))
        return notify_fail("你的基本指法水平有限，无法领会更高深的幻阴指法。\n");

    return 1;
}

string query_skill_name(int level) {
    int i;
    for (i = sizeof(action) - 1; i >= 0; i--)
        if (level >= action[i]["lvl"])
            return action[i]["skill_name"];
}

mapping query_action(object me, object weapon) {
    int i, level;
    level = (int) me->query_skill("huanyin-zhi", 1);
    for (i = sizeof(action); i > 0; i--)
        if (level > action[i - 1]["lvl"])
            return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me) {
    if ((int) me->query("qi") < 80)
        return notify_fail("你的体力太低了。\n");

    if ((int) me->query("neili") < 75)
        return notify_fail("你的内力不够练幻阴指法。\n");

    me->receive_damage("qi", 72);
    me->add("neili", -69);
    return 1;
}

string perform_action_file(string action) {
    return __DIR__
    "huanyin-zhi/" + action;
}

mixed hit_ob(object me, object target) {
    string msg;
    int j;
    j = me->query_skill("huanyin-zhi", 1);

    if (random(3) == 0 && !target->is_busy() && j > 100 &&
        me->query("neili") > target->query("neili") &&
        me->query("neili") > 500 && me->query("max_neili") > 500 &&
        j > random(target->query_skill("dodge", 1))) {
        switch (random(2)) {
            case 0 :
                msg = HIC
                "$N"
                HIC
                "深吸一口气，全身之力聚于一指，挟待一股寒气，射向$n的全身要穴！\n"
                NOR;
                msg += RED
                "$n只觉全身一麻，全身一寒！\n"
                NOR;
                target->start_busy(3);
                break;
            case 1 :
                msg = HIC
                "$N"
                HIC
                "轻声吐气，双指 挟待一股寒气飞似的刺向$n的胸腹间！\n"
                NOR;
                msg += RED
                "结果$n气血一滞，全身一寒！\n"
                NOR;
                target->start_busy(3);
                break;

        }
        message_vision(msg, me, target);
    }
}