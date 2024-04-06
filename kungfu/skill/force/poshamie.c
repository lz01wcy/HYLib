// posha 破杀灭
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
void remove_effect(object me, int f, int j);

int exert(object me)
{
        object weapon,victim_w,armor,ring;
        int damage,p,i;
        string msg,dodge_skill;
object target;        

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
 return notify_fail(RED"你要对谁使用「破杀灭」。\n"NOR);


	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("force", 1) < 300)
		return notify_fail("你的内功修为还不够。\n");

	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("你的内力修为不够。\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");
	if(!wizardp(me) && (int)me->query_skill("jiuyin-shenzhang", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");
	if(!wizardp(me) && (int)me->query_skill("dafumo-quan", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");		        

        if (target->is_busy()) 
		return notify_fail("对方正忙着呢，赶快攻击吧！\n");		        
        msg = HBWHT "$N斗气暴发，贯通武学之精髓，使出了破气之绝学！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);

        msg = HIR "$N使出「破杀灭」，五道真气，刺向$n的全身！\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
        msg += HIR "\n 破穴灭 ！$p被真气点中全身穴位！\n" NOR;
                target->start_busy( (int)me->query_skill("force",1) / 60 + 3 );
        i=(int)me->query_skill("force",1) / 60 + 3;
       if (wizardp(me)) msg += HIR "\n 点穴时间"+i+"秒。\n" NOR;
if (random(3)==0) target->start_busy(5);
if (userp(target))
{
	
        msg += HIY " 破防灭 ！$p全身的防御完全被破坏！\n" NOR;
       if (target->query_temp("apply/armor") > 1)
        target->set_temp("apply/armor", target->query_temp("apply/armor")/2);
        if (target->query_temp("apply/dodge") > 1)
        target->set_temp("apply/dodge", target->query_temp("apply/dodge")/2);
        if (target->query_temp("apply/defense") > 1)
        target->set_temp("apply/defense", target->query_temp("apply/defense")/2);

        msg += HIW " 破攻灭 ！$p使用的招式完全被封死！\n" NOR;
       if (target->query_temp("apply/attack") > 1)
        target->set_temp("apply/attack", target->query_temp("apply/attack")/2);
        if (target->query_temp("apply/damage") > 1)
        target->set_temp("apply/damage", target->query_temp("apply/damage")/2);

        msg += HIB " 破体灭 ！$p的力量和速度完全被打乱！\n" NOR;
        if (target->query_temp("apply/strength") > 1)
        target->set_temp("apply/strength",target->query_temp("apply/strength")/2);
        if (target->query_temp("apply/dexerity") > 1)
        target->set_temp("apply/dexerity",target->query_temp("apply/dexerity")/2);
}
        msg += HIC " 破器灭 ！$p的武器和防具失去了作用！\n\n" NOR;
        if( target->query_temp("armor/cloth")){
        armor = target->query_temp("armor/cloth");
	armor->unequip();
	armor->reset_action();
        }

        if( target->query_temp("armor/shield")){
        ring = target->query_temp("armor/shield");
	ring->unequip();
	ring->reset_action();
        }

        if( target->query_temp("armor/ring")){
        ring = target->query_temp("armor/ring");
	ring->unequip();
	ring->reset_action();
        }

        if( target->query_temp("armor/gem")){
        ring = target->query_temp("armor/gem");
	ring->unequip();
	ring->reset_action();
        }

        if( target->query_temp("armor/armor")){
        ring = target->query_temp("armor/armor");
	ring->unequip();
	ring->reset_action();
        }
        
	if (target->query_temp("weapon")){
	victim_w = target->query_temp("weapon");
        victim_w->unequip();
	victim_w->reset_action();
        }
        
        } else {
                msg += HIG"可是$p认识$P的历害，逃出了攻击范围。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}

