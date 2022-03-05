//ice_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration) {
    int damage, damage2;
    damage = me->query("qi") / 8;
    damage2 = me->query("jing") / 8;
    if (damage > 5000) damage = 5000;
    if (damage2 > 5000) damage2 = 5000;

    if (duration < 1) return 0;
    if (!living(me)) {
        message("vision", me->name() + "浑身颤抖，痛苦地哼了一声。\n", environment(me), me);
    } else {
        tell_object(me, HIB
        "忽然一阵奇寒从丹田升起，沁入四肢百骸，你中的寒冰绵掌发作了！\n"
        NOR );
        message("vision", me->name() + "的身子突然晃了两晃，牙关格格地响了起来。\n",
                environment(me), me);
    }
    me->start_busy(3);
    me->receive_wound("qi", 85 + random(100));
    me->receive_wound("jing", 80);
    me->apply_condition("ice_poison", duration - 1);

    if (duration < 1) return 0;
    return CND_CONTINUE;
}
