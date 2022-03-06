// xue-dao.c 血刀
// Designed by secret(秘密)
//
#include <ansi.h>;

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
    ([      "action" : "$N高举手中$w,使出一招" + (order[random(13)]) + "「磨牙吮血」"
    NOR
    "，一刀斜劈$n的$l  ",
            "skill_name" : "磨牙吮血",
            "force" : 100,
            "dodge" : 35,
            "parry" : 35,
            "lvl" : 0,
            "damage" : 320,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N就地一滚，使一招" + (order[random(13)]) + "「刺血满地」"
    NOR
    "，手中$w卷向$n的大腿  ",
            "skill_name" : "刺血满地",
            "force" : 140,
            "dodge" : 35,
            "parry" : 35,
            "lvl" : 8,
            "damage" : 225,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N足尖一点，使出" + (order[random(13)]) + "「血海茫茫」"
    NOR
    "，刀锋自上而下直插$n的$l  ",
            "skill_name" : "血海茫茫",
            "force" : 180,
            "dodge" : 30,
            "parry" : 35,
            "lvl" : 16,
            "damage" : 230,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N使出一招" + (order[random(13)]) + "「呕心沥血」"
    NOR
    "，将$w舞得如白雾一般压向$n  ",
            "skill_name" : "呕心沥血",
            "force" : 220,
            "dodge" : 55,
            "parry" : 55,
            "lvl" : 24,
            "damage" : 240,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N低吼一声，使出" + (order[random(13)]) + "「血口喷人」"
    NOR
    "，举$w直劈$n的$l  ",
            "skill_name" : "血口喷人",
            "force" : 250,
            "dodge" : 55,
            "parry" : 55,
            "lvl" : 32,
            "damage" : 250,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N使出" + (order[random(13)]) + "「血迹斑斑」"
    NOR
    "，飞身斜刺，忽然反手一刀横斩$n的腰部  ",
            "skill_name" : "血迹斑斑",
            "force" : 280,
            "dodge" : 50,
            "parry" : 55,
            "lvl" : 40,
            "damage" : 260,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N使一式" + (order[random(13)]) + "「以血还血」"
    NOR
    "，挥刀直指$n的胸口  ",
            "skill_name" : "以血还血",
            "force" : 300,
            "dodge" : 55,
            "parry" : 50,
            "lvl" : 48,
            "damage" : 280,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N刀锋虚点，使出一招" + (order[random(13)]) + "「血流满面」"
    NOR
    "，转身举$w横劈$n的面门  ",
            "skill_name" : "血流漫面",
            "force" : 320,
            "dodge" : 50,
            "parry" : 50,
            "lvl" : 56,
            "damage" : 300,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N一招" + (order[random(13)]) + "「磨牙吮血」"
    NOR
    "，将$w衔在嘴里，等$n走进了，突然间左手抓住刀柄，顺手一挥，砍向$p$l",
            "skill_name" : "磨牙吮血",
            "force" : 100,
            "dodge" : 55,
            "parry" : 55,
            "lvl" : 5,
            "damage" : 250,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N嘿嘿一笑，一式" + (order[random(13)]) + "「批纸削腐」"
    NOR
    "，一刀横削过去，$n只觉眼前红光闪动，$l上微微一凉",
            "skill_name" : "批纸削腐",
            "force" : 140,
            "dodge" : 55,
            "parry" : 55,
            "lvl" : 25,
            "damage" : 275,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N衔$w在口，空手在$n身旁穿来插去，蓦地里右手从口中抽出刀来，" + (order[random(13)]) + "「血海茫茫」"
    NOR
    "一挥之下，刀锋直劈$p$l",
            "skill_name" : "血海茫茫",
            "force" : 180,
            "dodge" : 65,
            "parry" : 55,
            "lvl" : 35,
            "damage" : 360,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N嘿嘿冷笑声中，一招" + (order[random(13)]) + "「血洗天河」"
    NOR
    "，突见那$w红影闪闪，迎头弯转，竟如一根软带一般曲了下来，刀头削向$n$l",
            "skill_name" : "血洗天河",
            "force" : 220,
            "dodge" : 55,
            "lvl" : 55,
            "damage" : 390,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N身子向前一探，一招" + (order[random(13)]) + "「血蛇逐电」"
    NOR
    "，$w颤动，刀刃便如一条赤练蛇一般，迅速无伦地在$n身上爬行而过，随即收刀入鞘，哈哈大笑",
            "skill_name" : "血蛇逐电",
            "force" : 250,
            "dodge" : 55,
            "parry" : 55,
            "lvl" : 75,
            "damage" : 300,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N低吼一声，凛然生威，将手中$w刀柄反拿，一式「血痕累累」"
    NOR
    "，卷起片片刀风斩向$n的$l",
            "skill_name" : "血痕累累",
            "force" : 280,
            "dodge" : 50,
            "parry" : 55,
            "lvl" : 95,
            "damage" : 360,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N气透刀尖，卷起刺骨寒风，一招" + (order[random(13)]) + "「血风刺骨」"
    NOR
    "向前直劈而下，一道红光从上至下剖向$n的$l",
            "skill_name" : "血风刺骨",
            "force" : 300,
            "dodge" : 55,
            "parry" : 55,
            "lvl" : 105,
            "damage" : 380,
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N一式" + (order[random(13)]) + "「血雨空鸣」"
    NOR
    "，一口$w越使越快，一团团红影笼罩了全身，向$n连砍数刀，都是只攻不守，极其凌厉的招数",
            "skill_name" : "血雨空鸣",
            "force" : 320,
            "dodge" : 50,
            "parry" : 55,
            "lvl" : 125,
            "damage" : 320,
            "damage_type" : "割伤",
    ]),
});

string *parry_msg = ({
    "$n反手一刺，$w象一条盘蛇，直扑$N的手腕.",
            "$n向左侧进一步，手中的$w顺势滑下，急削$N握的手指。\n",
            "$n刀法一变，将手中的$w向上一撩,将$N的攻势引偏出去.",
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo == "mingwang-jian"; }

int valid_learn(object me) {
    if ((int) me->query("max_neili") < 50)
        return notify_fail("你的内力不够。\n");
    if ((int) me->query_skill("longxiang", 1) >= 20 ||
        (int) me->query_skill("xiaowuxiang", 1) >= 20)
        return 1;
    else
        return notify_fail("你的内功火候太浅。\n");
    if ((int) me->query_skill("mingwang-jian", 1) < 80)
        return notify_fail("你的不动明王剑火候太浅。\n");
    if ((int) me->query_skill("lamaism", 1) < 80)
        return notify_fail("你的密宗心法火候太浅。\n");

}

string query_skill_name(int level) {
    int i;
    for (i = sizeof(action) - 1; i >= 0; i--)
        if (level >= action[i]["lvl"])
            return action[i]["skill_name"];
}

mapping query_action(object me, object weapon) {
    int i, level;
    level = (int) me->query_skill("xue-dao", 1);
    for (i = sizeof(action); i > 0; i--)
        if (level > action[i - 1]["lvl"])
            return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me) {
    object weapon;

    if (!me->query_skill("longxiang", 1)
        && !me->query_skill("xiaowuxiang", 1))
        return notify_fail("练" + (order[random(13)]) + "「血刀」"
    NOR
    "必须要有雪山派的内功作为根基。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string) weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");

    if ((int) me->query_skill("mingwang-jian", 1) < 80)
        return notify_fail("你的不动明王剑火候太浅。\n");
    if ((int) me->query_skill("lamaism", 1) < 80)
        return notify_fail("你的密宗心法火候太浅。\n");

    if ((int) me->query("qi") < 150)
        return notify_fail("你的体力不够，练不了" + (order[random(13)]) + "「血刀」"
    NOR
    "。\n");

    me->receive_damage("qi", 50);
    return 1;
}

string perform_action_file(string action) {
    return __DIR__
    "xue-dao/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor) {
    if (me->query("jiali") > me->query_skill("force")
        && me->query_skill_mapped("force") == "longxiang")
        me->set_temp("xiuluo", 1);
    if (damage_bonus < 10) damage_bonus = 10;
    if (me->query_skill("xue-dao", 1) > 200) {
        if (random(me->query_str()) > victim->query_str() || random(8) == 0) {
            victim->receive_wound("qi", random(me->query_skill("xue-dao", 1) / 2) + 10);
            return HIW
            "$N邪气大发，顿时光芒大胜。挥着大刀向着$n身上挥来，$n"
            BLINK +
            HIR
            "鲜血"
            NOR + HIW
            "狂喷而出！\n"
            NOR;
        }
    }

    if (random(me->query_skill("xue-dao", 1)) > 90 || random(2) == 0) {
        victim->receive_wound("qi", damage_bonus);
        return HIR
        "$n被刀风扫中，顿时一飙鲜血飞溅出去！\n"
        NOR;
    }


}


int ob_hit(object ob, object me, int damage) {
    object wp1, weapon;
    string msg;
    int p, j, skill, neili, neili1;
    int level, level2, damage2;
    level = (int) me->query_skill("unarmed", 1);
    level2 = (int) me->query_skill("longxiang", 1);
    skill = me->query_skill("longxiang", 1);
    neili = me->query("neili");
    neili1 = ob->query("neili");
    if (level2 <= 0) level2 = (int) me->query_skill("xiaowuxiang", 1);
    damage2 = (int) ob->query("neili", 1) / 10;
    if (random(8) == 0 && level2 >= 300 &&
        (me->query_skill_mapped("force") == "longxiang" || me->query_skill_mapped("force") == "xiaowuxiang")) {
        j = -damage / 2;
        if (damage2 > 5000) damage2 = 5000;
        msg = HIM
        "$N 口中喃喃念起「降妖伏魔咒」，内力汹涌而至，一层一层的加强。$n心神一乱，内力尽然提不起来！\n"
        NOR;
        ob->set_temp("apply/attack", 0);
        ob->set_temp("apply/defense", 0);
        if (random(2) == 0) {
            msg += HIM
            "$N" + HIM + "默念大明六字真言，手结摩利支天愤怒印! $n心神一荡，吐出一口鲜血!" + NOR;
            if (ob->query("qi") > damage2) {
                ob->receive_damage("qi", damage2 / 2);
                ob->receive_wound("qi", damage2 / 2);
            }
            if (!ob->is_busy() && random(3) == 0) ob->start_busy(2);
        }

        message_vision(msg, me, ob);
        return j;
    }
}