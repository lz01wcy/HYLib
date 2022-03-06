// roar.c 佛门狮子吼

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target) {
    object *ob;
    int i, skill, damage;

    if (environment(me)->query("no_fight"))
        return notify_fail("这里不能攻击别人! \n");

    if (!wizardp(this_player()) && (me->query("family/family_name") != "明教"))
        return notify_fail("你不是明教教众不能使用九阳神功。\n");

    if (((int) me->query("neili") < 600) || ((int) me->query_skill("jiuyang-shengong") < 20))
        return notify_fail("你鼓足真气\"喵\"的吼了一声, 结果吓走了几只老鼠。\n");

    if (!me->is_fighting())
        return notify_fail("你不在打架，用这个做什么?\n");

    skill = me->query_skill("force");

    me->add("neili", -150);
    me->receive_damage("qi", 10);

    me->start_busy(1);
    message_combatd(
            HIY
    "$N深深地吸一囗气，真力迸发，发出一声惊天动地的巨吼。\n"
    NOR, me);

    ob = all_inventory(environment(me));
    for (i = 0; i < sizeof(ob); i++) {
        if (!living(ob[i]) || ob[i] == me) continue;
        if (!ob[i]->is_fighting(me)) continue;
        if (ob[i] == me) continue;
        if (!ob[i]->is_character() || ob[i]->is_corpse()) continue;

        if (skill / 2 + random(skill / 2) < (int) ob[i]->query("con") * 2) continue;

        damage = skill - ((int) ob[i]->query("max_neili") / 10);
        if (damage > 0) {
            ob[i]->receive_damage("jing", damage / 2);
            if ((int) ob[i]->query("neili") < skill * 2)
                ob[i]->receive_wound("jing", damage / 2);
            tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样。\n");
            if (!me->is_killing(ob[i]))
                me->fight_ob(ob[i]);

            if (!ob[i]->is_killing(me))
                ob[i]->fight_ob(me);

        }
    }

    return 1;
}

