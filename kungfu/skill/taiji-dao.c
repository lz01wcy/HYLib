// taiji-dao.c 太极刀
// modified by Venus Oct.1997
// cleansword 2/15/96

inherit SKILL;

mapping *action = ({
    ([      "action" : "$N手中$w斜指，一招「停车问路」，反身一顿，一刀向$n的$l撩去",
            "force" : 120,
            "dodge" : -10,
            "parry" : 5,
            "damage" : 15,
            "damage_type" : "割伤"
    ]),
    ([      "action" : "$N一招「童子挂画」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
            "force" : 130,
            "dodge" : -10,
            "parry" : 10,
            "damage" : 20,
            "damage_type" : "割伤"
    ]),
    ([      "action" : "$N展身虚步，提腰跃落，一招「推窗望月」，刀锋一卷，拦腰斩向$n",
            "force" : 140,
            "dodge" : -5,
            "parry" : 5,
            "damage" : 25,
            "damage_type" : "割伤"
    ]),
    ([      "action" : "$N一招「开门见山」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
            "force" : 160,
            "dodge" : 5,
            "parry" : 5,
            "damage" : 30,
            "damage_type" : "割伤"
    ]),
    ([      "action" : "$N手中$w一沉，一招「临溪观鱼」，双手持刃拦腰反切，砍向$n的胸口",
            "force" : 180,
            "dodge" : 10,
            "parry" : 5,
            "damage" : 35,
            "damage_type" : "割伤"
    ]),
    ([      "action" : "$N挥舞$w，使出一招「张弓望的」，上劈下撩，左挡右开，齐齐罩向$n",
            "force" : 210,
            "dodge" : 15,
            "parry" : 15,
            "damage" : 45,
            "damage_type" : "割伤"
    ]),
    ([      "action" : "$N一招「风送轻舟」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
            "force" : 240,
            "dodge" : 5,
            "parry" : 15,
            "damage" : 50,
            "damage_type" : "割伤"
    ]),
    ([      "action" : "$N盘身驻地，一招「川流不息」，挥出一片流光般的刀影，向$n的全身涌去",
            "force" : 280,
            "dodge" : 20,
            "parry" : 10,
            "damage" : 60,
            "damage_type" : "割伤"
    ]),
});


int valid_enable(string usage) {
    return (usage == "blade") || (usage == "parry");
}

int valid_learn(object me) {
    if ((int) me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if ((int) me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的太极神功火候太浅。\n");
    if ((int) me->query_skill("taiji-quan", 1) < 20)
        return notify_fail("你的太极拳火候太浅。\n");
    return 1;
}

mapping query_action(object me, object weapon) {
    int zhaoshu, level;

    zhaoshu = sizeof(action) - 1;
    level = (int) me->query_skill("taiji-dao", 1);

    if (level < 60)
        zhaoshu--;
    if (level < 55)
        zhaoshu--;
    if (level < 50)
        zhaoshu--;
    if (level < 40)
        zhaoshu--;
    if (level < 30)
        zhaoshu--;
    if (level < 20)
        zhaoshu--;
    if (level < 10)
        zhaoshu--;

    return action[random(zhaoshu)];
}

int practice_skill(object me) {
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string) weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");
    if ((int) me->query("qi") < 50)
        return notify_fail("你的体力不够练太极刀法。\n");
    me->receive_damage("qi", 30);
    return 1;
}

