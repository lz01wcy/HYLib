#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

void create() {
    set_name(HIW
    "神照经"
    NOR, ({ "shenzhao jing", "jing" }));
    set_weight(50);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "张");
        set("long", HIG
        "这是一本失落已久的武学秘籍，上面记载着天下内功中威力最强、最奥妙的法门。\n"
        NOR);
        set("treasure", 1);
        set("value", 0);
        set("material", "skin");
        set("no_put", 1);
        set("no_give", 1);
        set("no_drop", 1);
        set("no_get", 1);
        set("no_steal", 1);
    }
}

void init() {
    add_action("do_yandu", ({ "yandu" }));
}

int do_yandu(string arg) {
    int cost, my_skill;
    string book;
    object me = this_player();
    object where = environment(me);

    if (!me->query("szj/passed"))
        return 0;
    if (!arg)
        return notify_fail("你要读什么？\n");
    if (sscanf(arg, "%s", book) != 1)
        return notify_fail("你要读什么？\n");
    if (!(book == "shenzhao jing" || book == "jing"))
        return notify_fail("你要读什么？\n");

    if (me->is_busy())
        return notify_fail("你现在正忙着呢。\n");
    if (where->query("sleep_room"))
        return notify_fail("卧室不能读书，会影响别人休息。\n");
    if (me->is_fighting())
        return notify_fail("你无法在战斗中专心下来研读新知！\n");
    if (!me->query_skill("literate", 1))
        return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
    if (!random(5))
        message("vision", me->name() + "正专心地研读" + this_object()->name() + "。\n", environment(me), me);

    if ((int) me->query("learned_points") < 1)
        return notify_fail("你的潜能已经用完了，再怎么读也没用。\n");
    if ((int) me->query("potential") - (int) me->query("learned_points") < 200)
        return notify_fail("你的潜能太少了!\n");

    if ((int) me->query("potential") < 1)
        return notify_fail("你的潜能已经用完了，再怎么读也没用。\n");
    if ((int) me->query("combat_exp") < 1000000)
        return notify_fail("你的实战经验不足，再怎么读也没用。\n");
    if (me->query("int") < 30 || me->query_int() < 60)
        return notify_fail("以你目前的领悟能力，还没有办法学这个技能。\n");
    notify_fail("依你目前的能力，没有办法学习这种技能。\n");
    if (!SKILL_D("shenzhao-jing")->valid_learn(me))
        return 0;
    cost = 100 * (3 + random(3));
    if (me->query("szj/over200"))
        cost = cost / 5;
    if ((int) me->query("jing") < cost) {
        me->start_busy(1);
        return notify_fail("你的精不够用了。\n");
    }
    my_skill = me->query_skill("shenzhao-jing", 1);
    if (!me->query("szj/over200") && my_skill > 200)
        return notify_fail("你按照神照经心法试图打通任督二脉，却始终没有任何进展。\n");
    if (my_skill * my_skill * my_skill / 10 > (int) me->query("combat_exp"))
        return notify_fail("也许是缺乏实战经验，你对帛卷上面所说的东西总是无法领会。\n");
    else
        write("你研读着有关神照经的技巧，似乎有些心得。\n");
    me->improve_skill("shenzhao-jing", ((int) me->query_skill("literate", 1) / 5 + 1));
    me->receive_damage("jing", cost);
    me->add("potential", -(1 + random(2)));
    return 1;
}

int query_autoload() { return 1; }
