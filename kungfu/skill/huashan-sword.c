// huashan-sword.c
// Modified by Venus Oct.1997
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
    ([      "action":"$N一招" + (order[random(13)]) + "「白云出岫」"
    NOR
    "，剑势灵动轻盈，手中$w点向$n的$l",
            "force" : 150,
            "dodge" : 15,
            "parry" : 5,
            "damage": 115,
            "lvl" : 0,
            "skill_name" : "白云出岫",
            "damage_type":  "刺伤"
    ]),
    ([      "action":"$N使出" + (order[random(13)]) + "「有凤来仪」"
    NOR
    "，剑势飞舞而出，内藏五个后着，划向$n的$l",
            "force" : 180,
            "dodge" : 15,
            "parry" : 5,
            "damage": 125,
            "lvl" : 9,
            "skill_name" : "有凤来仪",
            "damage_type":  "割伤"
    ]),
    ([      "action":"$N吐气开声一招" + (order[random(13)]) + "「天绅倒悬」"
    NOR
    "，$w自上而下划出一个大弧，向$n劈砍下去",
            "force" : 220,
            "dodge" : 18,
            "parry" : 8,
            "damage": 130,
            "lvl" : 18,
            "skill_name" : "天绅倒悬",
            "damage_type":  "割伤"
    ]),
    ([      "action":"$N向前跨上一步，运足内劲，手中$w使出" + (order[random(13)]) + "「白虹贯日」"
    NOR
    "，急劲无踌地直刺$n",
            "force" : 250,
            "dodge" : 10,
            "parry" : 10,
            "damage": 135,
            "lvl" : 25,
            "skill_name" : "白虹贯日",
            "damage_type":  "刺伤"
    ]),
    ([      "action":"$N手中的$w自左而右地一晃，使出" + (order[random(13)]) + "「苍松迎客」"
    NOR
    "带着呼呼风声直削$n的$l",
            "force" : 280,
            "dodge" : 15,
            "parry" : 15,
            "damage": 140,
            "lvl" : 32,
            "skill_name" : "苍松迎客",
            "damage_type":  "割伤"
    ]),
    ([      "action":"$N飞身跃起，一式" + (order[random(13)]) + "「金雁横空」"
    NOR
    "，卷起漫天剑影，$w向$n电射而去",
            "force" : 310,
            "dodge" : 15,
            "parry" : 15,
            "damage": 145,
            "lvl" : 40,
            "skill_name" : "金雁横空",
            "damage_type":  "刺伤"
    ]),
    ([      "action":"$N凝气守中，$w逼出雪亮剑芒，挥出" + (order[random(13)]) + "「无边落木」"
    NOR
    "，一剑快似一剑底地攻向$n",
            "force" : 350,
            "dodge" : 10,
            "parry" : 10,
            "damage": 155,
            "lvl" : 48,
            "skill_name" : "无边落木",
            "damage_type":  "刺伤"
    ]),
    ([      "action":"$N驱剑中宫直进，剑尖颤动，中途忽然转而向上，" + (order[random(13)]) + "「青山隐隐」"
    NOR
    "端的是变幻无方",
            "force" : 390,
            "dodge" : 5,
            "parry" : 5,
            "damage": 265,
            "lvl" : 55,
            "skill_name" : "青山隐隐",
            "damage_type":  "刺伤"
    ]),
    ([      "action":"$N侧身斜刺一剑，一招" + (order[random(13)]) + "「古柏森森」"
    NOR
    "卷带着森然剑气，将$n包围紧裹",
            "force" : 410,
            "dodge" : 8,
            "parry" : 8,
            "damage": 275,
            "lvl" : 62,
            "skill_name" : "古柏森森",
            "damage_type":  "割伤"
    ]),
    ([      "action":"$N双手握起$w，剑芒暴长，一式" + (order[random(13)]) + "「无双无对」"
    NOR
    "，驭剑猛烈绝伦地往$n冲刺",
            "force" : 450,
            "dodge" : 10,
            "parry" : 10,
            "damage": 285,
            "lvl" : 70,
            "skill_name" : "无双无对",
            "damage_type":  "刺伤"
    ]),
});

int valid_learn(object me) {
    object ob;
//   if( (string)me->query("gender") != "女性" )
//   return notify_fail("九阴赤炼剑法是只有女子才能练的武功。\n");
    if ((int) me->query("max_neili") < 50)
        return notify_fail("你的内力不够，没有办法练华山剑法。\n");
    if ((string) me->query_skill_mapped("force") != "zixia-shengong")
        return notify_fail("华山剑法必须配合紫霞神功才能练。\n");
    if (!(ob = me->query_temp("weapon"))
        || (string) ob->query("skill_type") != "sword")
        return notify_fail("你必须先找一把剑才能练剑法。\n");

    return 1;
}

int valid_enable(string usage) {
    return usage == "sword" || usage == "parry";
}

mapping query_action(object me, object weapon) {
    return action[random(sizeof(action))];
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb) {
    int level, jiali, time, level2;
    object weapon;
    int damage;
    weapon = me->query_temp("weapon");
    level = (int) me->query_skill("zixia-shengong", 1);
    level2 = (int) me->query_skill("zixia-shengong", 1);


    if (random(8) == 0 && level >= 300 && me->query_skill_mapped("force") == "zixia-shengong") {
        if (random(2) == 0) {
            victim->start_busy(2);
        } else victim->receive_wound("qi", (random(damage_bonus)) + 200);
        return random(2) ? HIR "$N"
        HIR
        "运起紫霞神功，一剑攻出，剑气横飞，,$n双眼一花,不知如何是好!\n"
        NOR:
        HIR
        "$N"
        HIR
        "剑随意走,手中" + weapon->name() + HIR
        "犹如生了眼睛一般，随意挥出几剑,$n双眼一花,不知如何是好!\n"
        NOR;
    }
    weapon = me->query_temp("weapon");
    level2 = (int) me->query_skill("zixia-shengong", 1);
    if (random(3) == 1 && me->query_skill("zixia-shengong", 1) > 300) {
        if (damage_bonus > 50 && random(level2) > 100) {
            victim->receive_wound("qi", (random(damage_bonus)));
            return HIM
            "$N剑气纵横! 一道剑气划过了$n的$l。结果鲜血狂奔!\n"
            NOR;
        }
    }
}

int practice_skill(object me) {
    if ((int) me->query("qi") < 30
        || (int) me->query("neili") < 5)
        return notify_fail("你的内力或气不够，没有办法练习华山剑法。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    //write("你按著所学练了一遍华山剑法。\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill) {
}

/*
void skill_improved(object me)
{
    if( (int)me->query_skill("nine-moon-sword", 1)  % 10 == 0 ) {
   tell_object(me,
      RED "\n你突然觉得一股阴气冲上心头，只觉得想杀人....\n\n"NOR);
   me->add("bellicosity", 2000);
    } else
   me->add("bellicosity", 200);
}
string perform_action_file(string action)
{
    return CLASS_D("ninemoon") + "/ninemoonsword/" + action;
}
*/

string perform_action_file(string action) {
    return __DIR__
    "huashan-sword/" + action;
}
