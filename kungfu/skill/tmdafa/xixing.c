// xi.c
// 吸星大法 吸.c    By poopoo
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int exert(object me, object target)
{

        int sp, dp;
        int my_max, tg_max;
        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("tmdafa",1)/2;
        dp = target->query_skill("force") + target->query_skill("dodge");

        if ( !target ) target = offensive_target(me);

        if( environment(me)->query("no_fight") )
                return notify_fail("在这里不能攻击他人。\n");
        if( !objectp(target) || target->query("id") == "mu ren" )
                return notify_fail("你要吸取谁的内力？\n");
        if (target->query("race") != "人类")
                return notify_fail("搞错了！这不是人！\n");

        my_max = me->query("max_neili");
        tg_max = target->query("qi");

        if ( me->query_temp("sucked") )
                return notify_fail("你正在运功之中！\n");

        if( !me->is_fighting() || !target->is_fighting())

        if( (int)me->query_skill("tmdafa",1) < 100 )
                return notify_fail("你的天魔大法功力不够，不能吸取对方的内力！\n");
	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过内力！\n");

        if( (int)me->query("neili") < 100 )
                return notify_fail("你的内力不够，不能使用吸星大法。\n");
	if( (int)me->query("neili") > 20000 )
		return notify_fail("你的内力已太多，不能吸取了。\n");
	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过内力！\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用吸星大法！\n");
        if ( !wizardp(this_player()) && (me->query("family/family_name") != "日月神教"))
                return notify_fail("你不是日月神教弟子，不能使用吸星大法。\n");
        if ( !wizardp(this_player()) && (me->query("family/master_name") != "任我行"))
                return notify_fail("只有任教主亲传弟子才能使用吸星大法。\n");

	if( (int)target->query("max_neili") < 100 )
		return notify_fail( target->name() +
			"丹元涣散，功力未聚，你无法从他体内吸取任何东西！\n");

        if( (int)target->query("max_neili") < (int)me->query("max_neili")/10 )
		return notify_fail( target->name() +
			"的内功修为远不如你，你无法从他体内吸取丹元！\n");
			
      if( target->query_temp("no_kill") )
        return notify_fail("不能打，打不得啊！\n");

        if(target==me)
        return notify_fail("用 suicide 指令会比较快:P。\n");

       if(me->is_busy())
        return notify_fail("你现在正忙。\n");
     message_vision(
        HIR "$N凝神一聚，运起吸心大法，全身骨节发出一阵爆豆般的声响，似乎要杀人了。\n" NOR, me);

        message_combatd(
                HIB "$N全身骨节爆响，双臂暴长数尺，掌缘猛地向$n的天灵拍了下去！\n\n" NOR,
                me, target );
        if ( living(target) )
        {
                if( !target->is_killing(me) ) target->kill_ob(me);
        }
        me->set_temp("sucked", 1);              
        if (( random(sp) > random(dp) ) || !living(target) )
        {
                tell_object(target, HIB "你只觉天顶骨裂，全身功力贯脑而出，如融雪般消失得无影无踪！\n" NOR);
                tell_object(me, HIR "你觉得" + target->name() + "的丹元自手掌源源不绝地流了进来。\n" NOR);
        if( (int)me->query_skill("force") < (int)me->query("max_neili") /18 )
{
                target->add("qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)) );
                target->add("eff_qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)/5) );
                call_out("del_sucked", 10, me);
                return notify_fail("你的内功太低了，已经吸不到内力了。\n");
}
        if( (int)target->query("qi") < 50 )
{
                target->add("qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)) );
                target->add("eff_qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)/5) );
                call_out("del_sucked", 10, me);
                return notify_fail( target->name() +
                        "丹元涣散，功力未聚，你无法从他体内吸取任何东西！\n");
}
        if( (int)target->query("qi") < (int)me->query("max_neili")/18 )
{
                target->add("qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)) );
                target->add("eff_qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)/5) );
                call_out("del_sucked", 10, me);
                return notify_fail( target->name() +
                        "的内功修为远不如你，你无法从他体内吸取丹元！\n");
}
                target->add("qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)) );
                target->add("eff_qi",  -1*(1+(me->query_skill("tmdafa", 1)-90)/6) );
                call_out("del_sucked", 10, me);
                me->add("max_neili",  1*(1+(me->query_skill("tmdafa", 1)-90)/6) );
 if ( target->query("max_neili") <1) target->set("max_neili",0);
                me->start_busy(7);
                target->start_busy(random(7));
                me->add("neili", -10);
                call_out("del_sucked", 10, me);
        }
        else
        {       
                message_combatd(HIY "可是$p看破了$P的企图，内力猛地一震，借势溜了开去。\n" NOR, me, target);
                me->start_busy(7);
                call_out("del_sucked", 20, me);
        }
        return 1;
}
void del_sucked(object me)
{
if (!me) return;
        if ( me->query_temp("sucked") )
        me->delete_temp("sucked");
}
