#include <ansi.h>

// xiantian-qigong.c 先天气功
inherit FORCE;

mapping *action = ({
    ([      "action" : "$N单掌一抖，运聚先天功功力，呼啸着向$n的$l处拍去",
            "dodge"  : 87,
            "force"  : 430,
            "attack" : 163,
            "parry"  : 81,
            "damage" : 383,
            "damage_type": "内伤"
    ]),
    ([      "action" : "$N右掌平伸，左掌运起先天功的劲力，猛地拍向$n的$l",
            "dodge"  : 85,
            "force"  : 440,
            "attack" : 147,
            "parry"  : 77,
            "damage" : 281,
            "damage_type": "内伤"
    ]),
    ([      "action" : "$N身形一展，右掌护住心脉，左掌中攻直进，贯向$n$l",
            "dodge"  : 75,
            "force"  : 450,
            "attack" : 182,
            "parry"  : 67,
            "damage" : 293,
            "damage_type": "内伤"
    ]),
    ([      "action" : "$N运转先天真气，双掌回圈，顿时一波澎湃的气劲直袭$n",
            "dodge"  : 87,
            "force"  : 480,
            "attack" : 183,
            "parry"  : 85,
            "damage" : 305,
            "damage_type": "内伤"
    ]),
});

int valid_enable(string usage) {
    int lvl;
    lvl = (int) this_player()->query_skill("xiantian-qigong", 1);

    if (lvl >= 180)
        return usage == "force" || usage == "unarmed" || usage == "parry";
    else
        return usage == "force";

}


mapping query_action(object me, object weapon) {
    return action[random(sizeof(action))];
}

mixed hit_ob(object me, object victim, int damage_bonus) {
    int lvl;

    lvl = me->query_skill("xiantian-qigong", 1);

    if (damage_bonus < 50
        || lvl < 180
        || random(5) == 0)
        return 0;

    if (damage_bonus > victim->query_con() || random(8) == 0) {
        me->add("neili", -30);
        victim->receive_damage("qi", (damage_bonus - 50) / 2 + 10, me);
        victim->receive_wound("qi", (damage_bonus - 50) / 2 + 10, me);
        return HIR
        "随着""$N""的攻击,一股先天纯阳真力瞬间爆发了出来，$n"  //return HIW "$N" HIW "先天功的潜力发挥了出来，突然间$n"
        HIR
        "只感五内俱焚，喉咙沙哑无比，不禁咳一口鲜血！\n"
        NOR;// HIW "只感喉咙一甜，喷出一口鲜血！\n" NOR;
    }
}


int difficult_level() {
    return 500;
}

int valid_learn(object me) {
    int lvl = (int) me->query_skill("xiantian-qigong", 1);
    int t = 1, j;
    if (lvl <= 100)
        for (j = 1; j < lvl / 10; j++)
            t *= 2;

    if (me->query("gender") == "无性")
        return notify_fail("你无根无性，阴阳不调，难以修行玄门正宗的先天气功。\n");

    if (me->query("class") == "bonze")
        return notify_fail(RANK_D->query_respect(me) + "欲修我道家玄门气功，怎又去入了佛门？\n");

    if ((int) me->query_skill("force", 1) < 10)
        return notify_fail("你的基本内功火候还不够。\n");

    if (lvl <= 100) {
        if (lvl > 10 && (int) me->query("shen") < t * 100)
            return notify_fail("你的侠义正气太低了。\n");
    } else {
        if ((int) me->query("shen") < (51200 + (lvl - 100) * 1000))
            return notify_fail("你的侠义正气太低了。\n");
    }
    if (
            me->query_skill("bahuang-gong", 1)
            || me->query_skill("beiming-shengong", 1)
            || me->query_skill("bibo-shengong", 1)
            || me->query_skill("hamagong", 1)
            || me->query_skill("huagong-dafa", 1)
            || me->query_skill("huntian-qigong", 1)
            || me->query_skill("hunyuan-yiqi", 1)
            || me->query_skill("jiuyang-shengong", 1)
            || me->query_skill("kuihua-xinfa", 1)
            || me->query_skill("kurong-changong", 1)
            || me->query_skill("linji-zhuang", 1)
            || me->query_skill("longxiang", 1)
            || me->query_skill("shenlong-xinfa", 1)
            || me->query_skill("taiji-shengong", 1)
            || me->query_skill("xiaowuxiang", 1)
            || me->query_skill("yijinjing", 1)
            || me->query_skill("yunv-xinfa", 1)
            || me->query_skill("yunlong-shengong", 1) ||
            me->query_skill("bingxue-xinfa", 1) ||
            me->query_skill("wudu-shengong", 1) ||
            me->query_skill("shenghuo-shengong", 1) ||
            me->query_skill("shenyuan-gong", 1) ||
            me->query_skill("huashan-neigong", 1) ||
            me->query_skill("zixia-shengong", 1) ||
            me->query_skill("shayi-xinfa", 1) ||
            me->query_skill("biyun-xinfa", 1) ||
            me->query_skill("xuantian-wuji", 1) ||
            me->query_skill("guiyuan-tunafa", 1))
        return notify_fail("你不先散了别派内功，怎能学习先天气功？！\n");

    return 1;
}

int practice_skill(object me) {
    return notify_fail("先天气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func) {
    return __DIR__
    "xiantian-qigong/" + func;
}

string perform_action_file(string action) {

    return __DIR__
    "xiantian-qigong/perform/" + action;
}

mixed ob_hit(object ob, object me, int damage) {
    int ap, dp, cost;
    mapping result;
    string msg;
    if (me->query_skill("xiantian-qigong", 1) < 200 ||
        me->query_skill_mapped("force") != "xiantian-qigong" ||
        me->query("neili") < 1000 ||
        !living(me))
        return 1;

    cost = damage / 2;
    if (cost > 100) cost = 100;

    ap = ob->query_skill("force") * 12 + ob->query("max_neili");
    dp = me->query_skill("force") * 12 + me->query("neili");

    if (ap / 2 + random(ap) < dp) {
        me->add("neili", -100);
        result = ([ "damage": -damage ]);

        switch (random(2)) {
            case 0:
                msg = HIR
                "只见$N"
                HIR
                "先天护体神功自然而"
                "然发动，将$n"
                HIR
                "的力道尽数反震回"
                "去。\n"
                NOR;
                ob->start_busy(3);
                break;
            case 1:
                msg = HIR
                "只见$N"
                HIR
                "先天护体神功自然而"
                "然发动，将$n"
                HIR
                "的攻击化为无形。\n"
                NOR;
                break;
            default:
                msg = HIR
                "只见$N"
                HIR
                "先天护体神功自然而"
                "然发动，抵抗$n"
                HIR
                "的攻击。\n"
                NOR;
                break;
        }
//msg += damage_msg(damage, "瘀伤");
        damage = damage / 3;
        message_vision(msg, me, ob);

    }
    return damage;
}
