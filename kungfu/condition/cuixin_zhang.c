//ice_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration) {
    int damage, damage2;
    damage = me->query("qi") / 18;
    damage2 = me->query("jing") / 18;
    if (damage > 5000) damage = 5000;
    if (damage2 > 5000) damage2 = 5000;

    if (duration < 1) return 0;
    if (!living(me)) {
        message("vision", me->name() + "一声惨嚎，内息逆流，“哇”的一声喷出一大口鲜血。\n", environment(me), me);
    } else {
        tell_object(me, HIB
        "你只感到五脏六腑翻腾不止，剧毒攻心，看来是中了催心掌掌劲的干扰！\n"
        NOR );
        message("vision", me->name() + "的身子突然晃了两晃，牙关格格地响了起来。\n",
                environment(me), me);
    }
    me->start_busy(3);
    me->receive_wound("qi", damage);
    me->receive_wound("jing", damage2);
    me->apply_condition("cuixin_zhang", duration - 1);

    if (duration < 1) return 0;
    return CND_CONTINUE;
}
