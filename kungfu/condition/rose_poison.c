// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration) {
    me->start_busy(random(3));
    me->receive_wound("qi", 20);
    me->receive_damage("qi", 10);
    me->apply_condition("rose_poison", duration - 1);
    tell_object(me, HIG
    "你中的"
    HIR
    "火玫瑰毒"
    HIG
    "发作了！\n"
    NOR );
    if (duration < 1) return 0;
    return 1;
}
