// ruyi-dao.c 如意刀
#include <ansi.h>

inherit SKILL;
string *order = ({
    ""
    HIY
    "", ""
    HIG
    "", ""
    RED
    "", ""
    MAG
    "", ""
    YEL
    "", ""
    HIC
    "", ""
    HIW
    "", ""
    HIR
    "", ""
    HIB
    "", ""
    CYN
    "", ""
    WHT
    "", ""
    HIM
    "", ""
    BLU
    ""
});
mapping *action = ({
    ([      "action" : "$N$w随意轻挑，一式" + (order[random(13)]) + "「无约无束」"
    NOR
    ""
    NOR
    "，$w毫无章法地抖出几点金星，时隐时现地飘向$n",
            "force" : 170,
            "dodge" : 15,
            "parry" : 15,
            "damage": 120,
            "lvl" : 5,
            "skill_name" : "无约无束",
            "damage_type" : "刺伤"
    ]),
    ([      "action" : "$N行似流水，动似浮云，衣袖微扬，递出一招" + (order[random(13)]) + "「自由自在」"
    NOR
    "，$w锋划向$n的$l",
            "force" : 210,
            "dodge" : 25,
            "parry" : 15,
            "damage": 160,
            "lvl" : 16,
            "skill_name" : "自由自在",
            "damage_type" : "割伤"
    ]),
    ([      "action" : "$N手中$w一闪而出，正是一招" + (order[random(13)]) + "「随心所欲」"
    NOR
    "，心意所指，刀光即至，几经变换终不离$n的$l",
            "force" : 270,
            "dodge" : 25,
            "parry" : 20,
            "damage": 175,
            "lvl" : 36,
            "skill_name" : "随心所欲",
            "damage_type" : "刺伤"
    ]),
    ([      "action" : "一改刀法之飘逸，$N真气布满全身，将$w舞得大开大和，脚踏中宫，一式" + (order[random(13)]) + "「豪放不羁」"
    NOR
    "，$w带着风声朝$n的$l劈去。",
            "force" : 340,
            "dodge" : 20,
            "parry" : 20,
            "damage": 160,
            "lvl" : 46,
            "skill_name" : "豪放不羁",
            "damage_type" : "劈伤"
    ]),
    ([      "action" : "$N$w轻挥，一招" + (order[random(13)]) + "「心如山水」"
    NOR
    "泱出几层刀浪，翻江捣海一般涌向$n",
            "force" : 380,
            "dodge" : 20,
            "parry" : 20,
            "damage": 170,
            "lvl" : 56,
            "skill_name" : "心如山水",
            "damage_type" : "割伤"
    ]),
    ([      "action" : "$N一招" + (order[random(13)]) + "「志比霞烟」"
    NOR
    "，身行飘忽不定，$w现出一片霞光，裹住$N，身刀合一，飞向$n",
            "force" : 400,
            "dodge" : 30,
            "parry" : 20,
            "damage": 180,
            "lvl" : 66,
            "skill_name" : "志比霞烟",
            "damage_type" : "割伤"
    ]),
    ([      "action" : "$N左手刀决朝$n一引，$w化一招" + (order[random(13)]) + "「日月入怀」"
    NOR
    "，刀尖划出一大一小两个圆圈，拢向$n周身上下",
            "force" : 430,
            "dodge" : 20,
            "parry" : 30,
            "damage": 285,
            "lvl" : 76,
            "skill_name" : "日月入怀",
            "damage_type" : "割伤"
    ]),
    ([      "action" : "$N身行高纵，一招" + (order[random(13)]) + "「逍遥云天」"
    NOR
    "从上递出，$w幻为数十点银芒，恍恍惚惚，飘落向$n",
            "force" : 450,
            "dodge" : 30,
            "parry" : 30,
            "damage": 295,
            "lvl" : 85,
            "skill_name" : "逍遥云天",
            "damage_type" : "刺伤"
    ]),
    ([    "action" : "$N手中$w斜指，一招" + (order[random(13)]) + "「停车问路」"
    NOR
    "，反身一顿，一刀向$n的$l撩去",
            "force" : 120,
            "dodge" : 10,
            "damage" : 150,
            "lvl" : 0,
            "skill_name" : "停车问路",
            "damage_type" : "割伤"
    ]),
    ([    "action" : "$N一招" + (order[random(13)]) + "「童子挂画」"
    NOR
    "，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
            "force" : 130,
            "dodge" : 20,
            "damage" : 180,
            "lvl" : 8,
            "skill_name" : "童子挂画",
            "damage_type" : "割伤"
    ]),
    ([    "action" : "$N展身虚步，提腰跃落，一招" + (order[random(13)]) + "「推窗望月」"
    NOR
    "，刀锋一卷，拦腰斩向$n",
            "force" : 140,
            "dodge" : 25,
            "damage" : 150,
            "lvl" : 16,
            "skill_name" : "推窗望月",
            "damage_type" : "割伤"
    ]),
    ([    "action" : "$N一招" + (order[random(13)]) + "「开门见山」"
    NOR
    "，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
            "force" : 160,
            "dodge" : 25,
            "damage" : 150,
            "lvl" : 24,
            "skill_name" : "开门见山",
            "damage_type" : "割伤"
    ]),
    ([    "action" : "$N手中$w一沉，一招" + (order[random(13)]) + "「临溪观鱼」"
    NOR
    "，双手持刃拦腰反切，砍向$n的胸口",
            "force" : 180,
            "dodge" : 20,
            "damage" : 200,
            "lvl" : 33,
            "skill_name" : "临溪观鱼",
            "damage_type" : "割伤"
    ]),
    ([    "action" : "$N挥舞$w，使出一招" + (order[random(13)]) + "「张弓望的」"
    NOR
    "，上劈下撩，左挡右开，齐齐罩向$n",
            "force" : 210,
            "dodge" : 25,
            "damage" : 250,
            "lvl" : 42,
            "skill_name" : "张弓望的",
            "damage_type" : "割伤"
    ]),
    ([    "action" : "$N一招" + (order[random(13)]) + "「风送轻舟」"
    NOR
    "，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
            "force" : 240,
            "dodge" : 25,
            "damage" : 300,
            "lvl" : 51,
            "skill_name" : "风送轻舟",
            "damage_type" : "割伤"
    ]),
    ([    "action" : "$N盘身驻地，一招" + (order[random(13)]) + "「川流不息」"
    NOR
    "，挥出一片流光般的刀影，向$n的全身涌去",
            "force" : 280,
            "dodge" : 40,
            "damage" : 360,
            "lvl" : 60,
            "skill_name" : "停车问路",
            "damage_type" : "割伤"
    ]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me) {
    if ((int) me->query("max_neili") < 50)
        return notify_fail("你的内力不够。\n");
    if ((int) me->query_skill("beiming-shengong", 1) < 10)
        return notify_fail("你的北冥神功火候太浅。\n");
    if ((int) me->query_skill("qingyun-shou", 1) < 80)
        return notify_fail("你的青云手火候太浅。\n");
    if ((int) me->query_skill("panyang-zhang", 1) < 80)
        return notify_fail("你的攀阳掌火候太浅。\n");
    if ((int) me->query_skill("liuyue-jian", 1) < 80)
        return notify_fail("你的流月剑舞火候太浅。\n");


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
    level = (int) me->query_skill("ruyi-dao", 1);
    for (i = sizeof(action); i > 0; i--)
        if (level > action[i - 1]["lvl"])
            return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me) {
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string) weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");
    if ((int) me->query("qi") < 50)
        return notify_fail("你的体力不够练如意刀。\n");
    if ((int) me->query_skill("qingyun-shou", 1) < 80)
        return notify_fail("你的青云手火候太浅。\n");
    if ((int) me->query_skill("panyang-zhang", 1) < 80)
        return notify_fail("你的攀阳掌火候太浅。\n");
    if ((int) me->query_skill("liuyue-jian", 1) < 80)
        return notify_fail("你的流月剑舞火候太浅。\n");

    me->receive_damage("qi", 45);
    return 1;
}

string perform_action_file(string action) {
    return __DIR__
    "ruyi-dao/" + action;
}

mixed hit_ob(object me, object victim, int damage) {
    string msg;
    int ap, dp, zhencost, skill;
    string result;
    object weapon;
    int lvl;
    int flvl;
    int level, jiali, time, level2, damage2;
    level = (int) me->query_skill("beiming-shengong", 1);
    level2 = (int) me->query_skill("beiming-shengong", 1);

    damage2 = (int) victim->query("neili", 1) / 10;
    if (damage2 >= 3800) damage2 = 3800;

    if (random(8) == 0 && level >= 300 && me->query_skill_mapped("force") == "beiming-shengong") {

        if (victim->query("neili") >= damage2) {
            victim->add("neili", -damage2);
            me->add("neili", damage2);
        }
        return HIW
        "$N突然使出北冥神功,$n全身内力如流水般源源不绝地流入$N的身体!\n"
        NOR;
    }
    lvl = me->query_skill("ruyi-dao", 1);
    if (!objectp(weapon = me->query_temp("weapon")))
        return 0;
    if (me->query_skill_mapped("force") != "bahuang-gong" &&
        me->query_skill_mapped("force") != "beiming-shengong")
        return 0;
    if (lvl < 80 ||
        me->query("neili") < 300)
        return 0;

    if (random(6) == 0) {
        if (victim->query("neili") > 1500)
            victim->add("neili", -300);
        if (me->query("neili") < me->query("max_neili"))
            victim->add("neili", (random(lvl) + 50));

        return HIC
        "$n"
        HIC
        "全身功力如流水般源源不绝地流入$N的身体！\n"
        NOR;
    }

    skill = me->query_skill("ruyi-dao", 1);
    ap = me->query("combat_exp") / 1000;
    dp = victim->query("combat_exp") / 1000;

    if (random(ap) > dp / 4 && random(skill) > 120) {
        if (random(4) == 1) {
            result = HIW
            "\n$N身形飘忽不定，左手握了一个刀决，身子滴溜溜地一转，已经欺到$n身前，唰地一刀。\n"
            NOR;
            message_vision(result, me, victim);
            victim->add("qi", -(random(skill) + 50));
            victim->add("eff_qi", -(random(skill) + 50));
            if (!victim->is_busy()) {
                victim->start_busy(3);
            }
            damage = 0;

            return ([ "result" : result, "damage" : damage ]);
        } else if (random(4) == 0) {
            result = HIG
            "\n$N身形飘起，长啸一声，手中" + (string) weapon->query("name") + HIG
            "猛地刺向$n。\n"
            NOR;
            message_vision(result, me, victim);
            victim->add("qi", -(random(skill) + 50));
            victim->add("eff_qi", -(random(skill) + 50));
            if (!victim->is_busy()) {
                victim->start_busy(3);
            }
            damage = 0;

            return ([ "result" : result, "damage" : damage ]);
        } else if (random(4) == 2) {
            result = HIM
            "\n$N左一刀，右一刀，刀刀不离$n的要害，突然中宫直进，直取$n的胸膛。\n"
            NOR;
            message_vision(result, me, victim);
            victim->add("qi", -(random(skill) + 50));
            victim->add("eff_qi", -(random(skill) + 50));
            if (!victim->is_busy()) {
                victim->start_busy(3);
            }
            damage = 0;

            return ([ "result" : result, "damage" : damage ]);
        } else {
            result = HIY
            "\n但见" + weapon->name() + HIY
            "一闪，刀间已到$n身前，$n不由地手足无措。\n"
            NOR;
            message_vision(result, me, victim);
            victim->add("qi", -(random(skill) + 50));
            victim->add("eff_qi", -(random(skill) + 50));
            if (!victim->is_busy()) {
                victim->start_busy(3);
            }
            damage = 0;

            return ([ "result" : result, "damage" : damage ]);
        }
    }
}

