// sanxiao_poison.c

#include <ansi.h>

int update_condition(object me, int duration) {
    int damage, damage2;
    damage = me->query("qi") / 3;
    damage2 = me->query("jing") / 3;
    if (damage > 5000) damage = 5000;
    if (damage2 > 5000) damage2 = 5000;
    if ((int) me->query("qi") < 100000) {
        me->receive_wound("qi", damage);
        me->receive_damage("qi", damage);
    } else {
        me->receive_wound("qi", damage);
        me->receive_damage("qi", damage);
    }
    me->start_busy(3);
    me->apply_condition("sanxiao_poison", duration - 1);
    message_vision(HIG
    "$N脸上忽然露出诡异的一笑，看来是"
    HIB
    "三笑逍遥散"
    HIG
    "发作了！\n"
    NOR, me);
    if (duration < 1) return 0;
    return 1;
}
