//yihun.c

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
        int skill = (int)me->query_skill("jiuyin-zhengong", 1), i;
        string msg;
	
	if( !target || target == me ) target = offensive_target(me);

	if( environment(me)->query("citybiwu") )
		return notify_fail("这里不准打架。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准打架。\n");
	if( !target || target==me || !target->is_character() )
		return notify_fail("移魂大法只能对对手使用。\n");
		
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「移魂大法」只能对战斗中的对手使用。\n");
        		
	if (!me->query("jiuyin/full") && !me->query("jiuyin/shang") && !me->query("jiuyin/gumu"))
		return notify_fail("你无法使用九阴真功。\n");
	if (!me->query("jiuyin/full") && !me->query("jiuyin/shang") && me->query("jiuyin/gumu") && (int)me->query_skill("jiuyin-zhengong", 1) > 100)
		return notify_fail("你无法使用九阴真功。\n");
	if (skill < 200 || (int)me->query_skill("daode-jing", 1) < 200)
		return notify_fail("以你目前的修为来看，还不足以运用移魂大法！\n");

        if (userp(me) && userp(target)
         && target->query_temp("nokill") )
        return notify_fail("那人启用了免战牌！\n");

        if (userp(me) && userp(target)
         && me->query_temp("nokill") )
        return notify_fail("你启用了免战牌！\n");

    if( userp(me) && userp(target) && target->query_condition("nokill")
    && !target->query_condition("killer"))
        return notify_fail("那个人刚被杀过，放过他吧！\n");
if( !living(target) && userp(target) && target->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("你想要杀此人，但他比你强太多，你不敢动手。\n");
	
//pk
    if( userp(target) && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");
    if( userp(target) && target->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");	
        if (me->query_temp("yihun"))
                return notify_fail("你已在运用移魂大法了。\n");
        if (me->query("max_neili") < 2000)
                return notify_fail("你的内力修为不够运用移魂大法所需！\n");
        if (me->query("neili") < 1000)
                return notify_fail("你的内力不够运用移魂大法所需！\n");

	me->start_busy(1);
	msg = HIW"$N眼神莹然有光，脸上突然开始做出各样奇怪的表情。\n";
	
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	){
		msg += "$n看了┍溉⌒$N，却不知不觉的学起$N的表情。\n"NOR;
		msg += CYN"\n$N猛然做出向自己攻击的动作，$n立刻向自己发疯似的攻击起来，出手越来越重！\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili", - 600);
		if (random(skill) > (int)target->query_skill("dodge", 1)/3)
			target->start_busy(random(skill/50) + 3);
		if (!target->is_busy())
			target->start_busy(random(2) + 1);
		target->add_temp("apply/attack", skill/2);
		target->add_temp("apply/damage", skill/2);
		target->add_temp("apply/dodge", -skill/2);
		for (i=0; i<random(skill/100)+3; i++)
			COMBAT_D->do_attack(target, target, target->query_temp("weapon"));
		target->add_temp("apply/attack", -skill/2);
		target->add_temp("apply/damage", -skill/2);
		target->add_temp("apply/dodge", skill/2);
		target->add_temp("apply/attack", -skill/20);
		target->add_temp("apply/dodge", -skill/20);
	} else {
		msg += HIY"不管$N怎么变化表情，$n总是冷冷的无动于衷。\n"NOR;
		message_vision(msg, me, target);
		me->add("neili", -600);
	}
	if(!me->is_fighting(target)) me->fight_ob(target);
	if(!target->is_fighting(me)) target->fight_ob(me);

        me->set_temp("yihun", 1);
	remove_call_out("checking");
        call_out("checking", 1, me);
        return 1;
}

void checking(object me)
{
	object target;
        int skill = (int)me->query_skill("jiuyin-zhengong", 1), i;
        string msg;
        target = offensive_target(me);

        if (!me || !me->query_temp("yihun")) return;
        if (!target ) return;
        if (me->is_ghost() || !living(me)){
                me->delete_temp("yihun");
                return;
                }
        if (!me->is_fighting() || me->query("neili") < 600) {
        	message_vision("\n$N眼神逐渐浑浊，脸上恢复了原来的神情。\n\n", me);
        	me->delete_temp("yihun");
        	return;
        	}
	if( !target || !target->is_character() ) {
	        call_out("checking", 1, me);
	        return;
	}

	if (userp(target))
{
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
		msg = CYN"\n$N猛然做出向自己攻击的动作，$n立刻向自己发疯似的攻击起来，出手越来越重！\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili", - 400);
		if (!target->is_busy())
			target->start_busy(random(2) + 1);
		target->add_temp("apply/attack", skill/2);
		target->add_temp("apply/damage", skill/2);
		target->add_temp("apply/dodge", -skill/2);
		for (i=0; i<(random(skill/100)+3)/2; i++)
			COMBAT_D->do_attack(target, target, target->query_temp("weapon"));
		target->add_temp("apply/attack", -skill/2);
		target->add_temp("apply/damage", -skill/2);
		target->add_temp("apply/dodge", skill/2);
		target->add_temp("apply/attack", -skill/20);
		target->add_temp("apply/dodge", -skill/20);
}
}
else {
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	){
		msg = CYN"\n$N猛然做出向自己攻击的动作，$n立刻向自己发疯似的攻击起来，出手越来越重！\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili", - 400);
		if (!target->is_busy())
			target->start_busy(random(2) + 1);
		target->add_temp("apply/attack", skill/2);
		target->add_temp("apply/damage", skill/2);
		target->add_temp("apply/dodge", -skill/2);
		for (i=0; i<(random(skill/100)+3)/2; i++)
			COMBAT_D->do_attack(target, target, target->query_temp("weapon"));
		target->add_temp("apply/attack", -skill/2);
		target->add_temp("apply/damage", -skill/2);
		target->add_temp("apply/dodge", skill/2);
		target->add_temp("apply/attack", -skill/20);
		target->add_temp("apply/dodge", -skill/20);
	}
}
        call_out("checking", 1, me);
}       
