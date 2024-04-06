// ss_poison.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration) {
    int damage, damage2;
    if (duration < 1) return 0;
    if (!living(me)) {
        message("vision", me->name() + HIG
        "凄惨地哼了一声。\n", environment(me), me);
    } else {
        tell_object(me, HIB
        "忽然一股寒流夹着一阵灼热涌上心来，你中的生死符发作了！\n"
        NOR );
        message("vision", me->name() + "突然倒在地上，双手在身上一阵乱抓。\n",
                me);
    }

    damage = me->query("qi") / 10;
    damage2 = me->query("jing") / 10;
    if (damage > 5000) damage = 5000;

    if (me->query("qi") < 100000)
        me->receive_wound("qi", 80 + damage);
    else me->receive_wound("qi", 80 + 1000);
    if (me->query("jing") < 100000)
        me->receive_wound("jing", 80 + damage2);
    else me->receive_wound("jing", 80 + 1000);

    me->start_busy(4);
    me->apply_condition("ss_poison", duration - 1);

    if (duration < 1) return 0;
    return CND_CONTINUE;
}
