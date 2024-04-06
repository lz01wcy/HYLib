// tuwu.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	string msg;
	object weapon;
	 if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("金蛇吐雾只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("id") != "jinshe zhui")
           return notify_fail("你没用金蛇锥，不能使用绝招！\n");

	if( (int)me->query_skill("jinshe-zhui", 1) < 100 )
		return notify_fail("你的金蛇锥法不够娴熟，不会使用金蛇吐雾。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你内力不够了。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧\n");

	skill = me->query_skill("jinshe-zhui", 1);

	me->add("neili", -200);
	target->receive_damage("qi", (int)skill/ 3+200);

    if (random(me->query_skill("force")) > target->query_skill("force")/3 && 
       random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
	message_combatd(
        HIY "只听一阵狂风扫叶般的声响中，$N手中的"YEL"金蛇锥"HIY"闪出夺目的光芒，闪耀得
$n眼冒金花，“金蛇吐雾”！除了眼前一重重的雾气外，$n啥也看不见了！\n" NOR, me, target);
	target->set_temp("block_msg/all",1);
	call_out("tuwu_end", (int) skill/30, me, target);
	target->start_busy(me->query_skill("jinshe-zhui",1)/40+2);
        me->start_busy(2);
    } else
    {
	message_combatd(
        HIY "只听一阵狂风扫叶般的声响中，$N手中的"YEL"金蛇锥"HIY"闪出夺目的光芒，闪耀得
$n眼冒金花，“金蛇吐雾”！除了眼前一重重的雾气外，$n啥也看不见了！\n" NOR, me, target);
        msg= HIY"$p情急智生，用剑气迫开了$P的雾气。\n"NOR;
        me->start_busy(2);
        message_combatd(msg, me, target);
    }
//    if(!target->is_fighting(me)) target->fight_ob(me);
//    if(userp(target)) target->fight_ob(me);
//    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}
void tuwu_end(object me, object target)
{
if (target)
{
	target->enable_player();
	message_combatd("$N抹了抹满脸的"HIR"鲜血"NOR"，终于睁开了眼。\n", target);
	target->set_temp("block_msg/all", 0);
}
	write(HIR"你终于抹掉了满脸的鲜血，看到了周围的情景。\n"NOR);
	return;
}
