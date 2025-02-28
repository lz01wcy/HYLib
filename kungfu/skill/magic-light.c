// magic-light

inherit SKILL;

int valid_enable(string usage) {
    return usage == "spells";

}

int valid_learn(object me) {
    if (!me->query("zhuanbest", 1))
        return notify_fail("你没有资格使用魔法！\n");
    if (me->query_skill("magic-dark"))
        return notify_fail("你已经学习了黑暗魔法！这两种魔法无法共存!!\n");

    if ((int) me->query_skill("spells", 1) < (int) me->query_skill("magic-light", 1))
        return notify_fail("你的基本魔法修为不够，无法领悟更高深的光明魔法。\n");
    return 1;
}

string perform_action_file(string action) {
    return __DIR__
    "magic-light/" + action;
}

int practice_skill(object me) {
    return notify_fail("魔法无法通过练习来成长。\n");
}

