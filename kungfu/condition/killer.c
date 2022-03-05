// killer.c

#include <ansi.h>

int update_condition(object me, int duration) {
    object ob;
    if (duration < 1) {
        tell_object(me, "官府不再通缉你了！\n");
        return 0;
    }
    if (random(3) == 0) me->start_busy(5);
    me->apply_condition("killer", duration - 1);
    return 1;
}
