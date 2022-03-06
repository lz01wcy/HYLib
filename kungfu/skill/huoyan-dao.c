//
// huoyan-dao.c 火焰刀
// Designed by secret(秘密)
//
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
    ([      "action" : "$N凝眉立目，深吸一口气，全身骨节一阵暴响，一招「无坚不摧」，缓缓向$n劈出一掌，掌力笼罩了$n的全身。",
            "skill_name" : "无坚不摧",
            "force" : 250,
            "lvl" : 5,
            "dodge" : 5,
            "damage" : 200,
            "parry" : 0,
            "weapon" : random(2) ? "无形刀气" : "火焰刀风",
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N使出一招「乱刃分尸」，绕着$n身周左右奔得犹似足不沾地，双掌此起彼伏，一掌掌地打向$n，一掌将将击出，身形已变。",
            "skill_name" : "乱刃分尸",
            "force" : 280,
            "lvl" : 35,
            "dodge" : 7,
            "damage" : 200,
            "parry" : 0,
            "weapon" : random(2) ? "无形刀气" : "火焰刀风",
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N左手虚招，将$n双手掠在外门，脚下一滑，已飘到$n的身后，右掌使出一招「魂飞魄散」，拍向$n的后脑。",
            "skill_name" : "魂飞魄散",
            "force" : 300,
            "lvl" : 65,
            "damage" : 200,
            "dodge" : 15,
            "parry" : 5,
            "weapon" : random(2) ? "无形刀气" : "火焰刀风",
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N跨前一大步，双掌一错，使出一招「披肝沥胆」，双掌一前一后劈向$n的$l，掌风凌厉之极。",
            "skill_name" : "披肝沥胆",
            "damage" : 260,
            "force" : 360,
            "lvl" : 95,
            "dodge" : 10,
            "parry" : 3,
            "weapon" : random(2) ? "无形刀气" : "火焰刀风",
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N双掌挥动之际竟带起一股热浪，一招「流金铄石」，双掌发出两道内力，夹带着热浪交叉扑向$n的$l。",
            "skill_name" : "流金铄石",
            "force" : 420,
            "lvl" : 125,
            "dodge" : 10,
            "parry" : 0,
            "damage" : 400,
            "weapon" : random(2) ? "无形刀气" : "火焰刀风",
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N脸露狞笑，一招「火虐风饕」，双掌犹如狂风一般发出，$n被掌风逼得一阵气窒，眉发竟被$N带起的热浪烤得焦黑。",
            "skill_name" : "火虐风饕",
            "force" : 460,
            "lvl" : 155,
            "dodge" : 20,
            "parry" : 5,
            "damage" : 400,
            "weapon" : random(2) ? "无形刀气" : "火焰刀风",
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N使出一招" + (order[random(13)]) + "「钻木取火」"
    NOR
    "，飞身急转，双掌向前平平拍向$n",
            "skill_name" : "钻木取火",
            "force" : 100,
            "lvl" : 0,
            "damage" : 160,
            "damage_type" : "瘀伤",
    ]),
    ([      "action" : "$N使出一招" + (order[random(13)]) + "「祝融怀焰」"
    NOR
    "，手掌如刀，斜斜劈向$n的$l",
            "skill_name" : "祝融怀焰",
            "force" : 150,
            "lvl" : 10,
            "damage" : 180,
            "damage_type" : "瘀伤",
    ]),
    ([      "action" : "$N使出一招" + (order[random(13)]) + "「风火无边」"
    NOR
    "，双掌一拍，一道内力自掌中攻向$n的$l",
            "skill_name" : "风火无边",
            "force" : 200,
            "lvl" : 20,
            "damage" : 200,
            "damage_type" : "瘀伤",
    ]),
    ([      "action" : "$N使出一招" + (order[random(13)]) + "「六道轮回」"
    NOR
    "，双手合十，当头劈向$n",
            "skill_name" : "六道轮回",
            "force" : 250,
            "lvl" : 30,
            "damage" : 200,
            "damage_type" : "瘀伤",
    ]),
    ([      "action" : "$N使出一招" + (order[random(13)]) + "「双龙吐焰」"
    NOR
    "，双掌一错，两道内力交叉攻向$n的$l",
            "skill_name" : "双龙吐焰",
            "force" : 300,
            "lvl" : 40,
            "damage" : 200,
            "damage_type" : "瘀伤",
    ]),
    ([      "action" : "$N使出一招" + (order[random(13)]) + "「刀山火海」"
    NOR
    "，双掌向下斜拍，顿时万千道内力从四面八方攻向$n",
            "skill_name" : "刀山火海",
            "force" : 350,
            "lvl" : 60,
            "damage" : 200,
            "damage_type" : "瘀伤",
    ]),
    ([      "action" : "$N使出一招" + (order[random(13)]) + "「白佛光度」"
    NOR
    "，左臂回收，右掌引内力直刺$n的$l",
            "skill_name" : "白佛光度",
            "force" : 400,
            "lvl" : 80,
            "damage" : 200,
            "damage_type" : "瘀伤",
    ]),
    ([      "action" : "$N使出一招" + (order[random(13)]) + "「火内莲花」"
    NOR
    "，双掌微并，两臂前伸，一道内劲如排山倒海般攻向$n",
            "skill_name" : "火内莲花",
            "force" : 500,
            "lvl" : 100,
            "damage" : 200,
            "damage_type" : "瘀伤",
    ]),
    ([      "action" : "$N内息转动，运劲于双臂，全身骨节一阵暴响，起手一式" + (order[random(13)]) + "「示诞生」"
    NOR
    "向$n劈出，将$n全身笼罩在赤热的掌风下",
            "skill_name" : "示诞生",
            "force" : 300,
            "lvl" : 15,
            "damage" : 300,
            "dodge" : 15,
            "damage_type" : "瘀伤",
    ]),
    ([      "action" : "$N面带轻笑，一招" + (order[random(13)]) + "「始心镜」"
    NOR
    "，火焰刀内劲由内及外慢慢涌出，$P双掌如宝像合十于胸前，向着$n深深一鞠",
            "skill_name" : "始心镜",
            "force" : 350,
            "lvl" : 25,
            "damage" : 300,
            "dodge" : 10,
            "damage_type" : "震伤",
    ]),
    ([      "action" : "$N双掌合十而又打开，这招" + (order[random(13)]) + "「现宝莲」"
    NOR
    "以火焰刀无上功力聚出一朵红莲，盛开的花瓣飞舞旋转，漫布在$n四周",
            "skill_name" : "现宝莲",
            "force" : 400,
            "lvl" : 55,
            "dodge" : 5,
            "damage" : 300,
            "weapon" : "红莲刀气",
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N面带金刚相，双掌搓圆，使无数炙热的刀气相聚，这招" + (order[random(13)]) + "「破法执」"
    NOR
    "犹如一只巨大的手掌，凌空向$n飞抓而下",
            "skill_name" : "破法执",
            "force" : 340,
            "lvl" : 75,
            "damage" : 380,
            "dodge" : 1,
            "damage_type" : "内伤",
    ]),
    ([      "action" : "$N暴喝一声，竟然使出伏魔无上的" + (order[random(13)]) + "「开显圆」"
    NOR
    "，气浪如飓风般围着$P飞旋，炎流将$n一步步向着$P拉扯过来",
            "skill_name" : "开显圆",
            "force" : 450,
            "lvl" : 125,
            "damage" : 400,
            "dodge" : 10,
            "damage_type" : "震伤",
    ]),
    ([      "action" : "$N口念伏魔真经，双掌连连劈出，将$n笼罩在炙焰之下，这如刀切斧凿般的" + (order[random(13)]) + "「显真常」"
    NOR
    "气浪似乎要将$p从中劈开",
            "skill_name" : "显真常",
            "force" : 380,
            "lvl" : 145,
            "damage" : 400,
            "dodge" : 15,
            "weapon" : "无形刀气",
            "damage_type" : "割伤",
    ]),
    ([      "action" : "$N现宝相，结迦兰，右手" + (order[random(13)]) + "「归真法」"
    NOR
    "单掌拍出，半空中刀气凝结不散，但发出炙灼的气浪却排山倒海般地涌向$n",
            "skill_name" : "归真法",
            "force" : 450,
            "lvl" : 160,
            "damage" : 400,
            "dodge" : 15,
            "damage_type" : "瘀伤",
    ]),
    ([      "action" : "$N虚托右掌，一式" + (order[random(13)]) + "「吉祥逝」"
    NOR
    "，内力运转，跟着全身衣物无风自动，$P身体微倾，手掌闪电一刀，斩向$n$l",
            "skill_name" : "吉祥逝",
            "force" : 500,
            "lvl" : 180,
            "damage" : 400,
            "dodge" : 55,
            "weapon" : "无形气浪",
            "damage_type" : "割伤",
    ]),

});


int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

void skill_improved(object me) {
    int skill = me->query_skill("huoyan-dao", 1);
    if (skill >= 200 && !me->query("hyd_add")) {
        me->set("hyd_add", 1);
        tell_object(me, HIW
        "\n忽然，你感道体内内息越转越快，瞬时间功力已经上升到了一个新的境界！\n你的内力增加了！\n你的根骨增加了！\n"
        NOR);
        me->add("max_neili", skill + random(skill));
        me->add("con", 1);
    }
}


int valid_learn(object me) {
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练火焰刀必须空手。\n");

    else if ((int) me->query("max_neili") < 300)    //  火焰刀要有很高的内力才能学
        return notify_fail("你的内力不够。\n");

    if ((int) me->query_skill("longxiang", 1) >= 60 ||
        (int) me->query_skill("xiaowuxiang", 1) >= 60)
        return 1;
    else if ((int) me->query_skill("longxiang", 1) < 60)
        return notify_fail("你的龙象般若功火候太浅。\n");
    else if ((int) me->query_skill("xiaowuxiang", 1) < 60)
        return notify_fail("你的小无相功火候太浅。\n");
    if ((int) me->query_skill("dashou-yin", 1) < 80)
        return notify_fail("你的密宗大手印功火候太浅。\n");
    if ((int) me->query_skill("yujiamu-quan", 1) < 80)
        return notify_fail("你的金刚瑜迦母拳火候太浅。\n");
}


string query_skill_name(int level) {
    int i;
    for (i = sizeof(action) - 1; i >= 0; i--)
        if (level >= action[i]["lvl"])
            return action[i]["skill_name"];
}

mapping query_action(object me, object weapon) {
    int i, level;
    level = (int) me->query_skill("huoyan-dao", 1);
    if (random(level) > 200
        && random(10) > 5) {
        return ([
        "action": HIR
        "$N双掌夹刀合十，手中" + HIR
        "顿时升起一团火焰将自己包围，$N猛宣一声佛号，一刀直劈向$n！"
        NOR,
                "force" : 800,
                "dodge" : 10,
                "damage": 800,
                "damage_type": "割伤"]);
    }

    for (i = sizeof(action); i > 0; i--)
        if (level > action[i - 1]["lvl"])
            return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me) {
    object weapon;

    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练火焰刀必须空手。\n");
    if ((int) me->query("qi") < 140)
        return notify_fail("你的体力不够，练不了火焰刀。\n");
    if ((int) me->query_skill("dashou-yin", 1) < 80)
        return notify_fail("你的密宗大手印功火候太浅。\n");
    if ((int) me->query_skill("yujiamu-quan", 1) < 80)
        return notify_fail("你的金刚瑜迦母拳火候太浅。\n");
    me->receive_damage("qi", 50);
    return 1;
}


string perform_action_file(string action) {
    return __DIR__
    "huoyan-dao/" + action;
}

int ob_hit(object ob, object me, int damage) {
    string msg;
    int j, skill, neili, neili1;
    object wp1, weapon;
    int p;
    int level, level2, damage2;
    level = (int) me->query_skill("unarmed", 1);
    level2 = (int) me->query_skill("longxiang", 1);
    skill = me->query_skill("longxiang", 1);
    if (level2 <= 0) level2 = (int) me->query_skill("xiaowuxiang", 1);
    neili = me->query("neili");
    neili1 = ob->query("neili");
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
    skill = me->query_skill("huoyan-dao", 1);
    neili = me->query("neili");
    neili1 = ob->query("neili");

    if (me->query("jiali") && random(skill) > 180
        && me->query("combat_exp") > ob->query("combat_exp") / 3
        && me->query_skill_mapped("parry") == "huoyan-dao"
        && me->query_skill("longxiang", 1) > 150
        && neili > 1000
        && skill > 150
        && living(me)
        && !me->query_temp("weapon")
        && !ob->query("env/invisibility")) {
        msg = HIR
        "只听得$N身前嗤嗤声响，‘火焰刀’威势大盛，"
        NOR;
        if (neili >= neili1 + random(neili1) + damage * 2) {
            msg += HIR
            "将$n招式上的内力都逼将回来！\n"
            NOR,
                    j = -5000;
        } else if (neili >= neili1 + damage) {
            msg += RED
            "$P手掌扬处，挡住了一些$n攻来的内力！\n"
            NOR,
                    j = -(damage / 2 + random(damage / 2));
        } else {
            msg += HIR
            "$P展开火焰刀法，封住了一些$n的攻击！\n"
            NOR,
                    j = -damage / 3;
        }
        if (wizardp(me)) tell_object(me, "Target damage = " + damage + " 。\n");
        message_vision(msg, me, ob);
        return j;
    }
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor) {
    if (me->query("jiali") > me->query_skill("force")
        && me->query_skill_mapped("force") == "longxiang")
        me->set_temp("xiuluo", 1);
    if (damage_bonus < 10) damage_bonus = 10;
    if (random(me->query_skill("huoyan-dao", 1)) > 100) {
        victim->receive_wound("qi", damage_bonus / 2);
        return HIM
        "$n被掌风扫中，感觉伤口烧了起来！\n"
        NOR;
    }
}
