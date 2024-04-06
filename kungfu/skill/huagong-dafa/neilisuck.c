// neilisuck.c

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;

	if ( target == me ) target = offensive_target(me);
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
 return notify_fail("只有在战斗中才能使用。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能攻击他人。\n");
	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("你要吸取谁的内力？\n");
	if (target->query("race") != "人类")
		return notify_fail("搞错了！只有人才能有内力！\n");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过内力！\n");

	if( (int)me->query("neili") > 20000 )
		return notify_fail("你的内力已太多，不能吸取了。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用化功大法吸人内力！\n");

        if( !me->is_fighting() || !target->is_fighting())

	if( (int)me->query_skill("huagong-dafa",1) < 60 )
		return notify_fail("你的化功大法功力不够，不能吸取对方的内力！\n");

	if( (int)me->query("neili",1) < 20 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if( (int)target->query("max_neili") <= 0 )
		return notify_fail( target->name() +
			"没有任何内力！\n");

        if( (int)target->query("neili") < 60 )
		return notify_fail( target->name() +
			"已经内力涣散，你已经无法从他体内吸取任何内力了！\n");

       if( target->query_temp("no_kill") )
        return notify_fail("不能打，打不得啊！\n");

        if(target==me)
        return notify_fail("用 suicide 指令会比较快:P。\n");

       if(me->is_busy())
        return notify_fail("你现在正忙。\n");
        
	message_combatd(
		HIR "$N一张脸突然变得惨白，右掌直出，猛地对准$n的膻中大穴按了上去！\n\n" NOR,
		me, target );

	if ( living(target) )
	{
me->kill_ob(target);
target->fight_ob(me);
//		if( !target->is_killing(me) ) target->kill_ob(me);
	}

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
        dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

        if (( random(sp) > random(dp) ) || !living(target) )
	{
		tell_object(target, HIR "你顿觉膻中微痛，如同被尖针刺了个小孔，全身内力如水银般循孔飞泄而出！\n" NOR);
		tell_object(me, HIG "你觉得" + target->name() + "的内力自手掌源源不绝地流了进来。\n" NOR);

		target->add("neili", -1*((int)me->query_skill("huagong-dafa", 1) + target->query("jiali")) );
            if ( target->query("neili") <1 ) target->set("neili",0);
		me->add("neili", (int)me->query_skill("huagong-dafa", 1)/2 + target->query("jiali") );

		if( target->query("combat_exp") >= me->query("combat_exp") ) {		
			if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
				me->add("potential", 1);
			me->add("combat_exp", 1);
		}

                me->start_busy(4);
		target->start_busy(random(4));
                me->add("neili", -7);

		call_out("del_sucked", 2, me);
	}
	else
	{	
		message_combatd(HIY "可是$p看破了$P的企图，内力猛地一震，借势溜了开去。\n" NOR, me, target);
		me->start_busy(4);
		call_out("del_sucked", 4, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked"))
	me->delete_temp("sucked");
}

