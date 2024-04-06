// yuyin.c 余音绕梁
// Last Modified by winder on Aug. 13 2000

#include <ansi.h>
#define PNAME "「余音绕梁」"
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];


	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
		
	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顾不暇，放胆攻击吧！\n");

	fskill = "baiyun-xinfa";
	bskill = "sword";


	if( (int)me->query_skill(fskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(sskill)+"不娴熟，使不出"+PNAME+"。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你的内力不够，不能使用"PNAME"。\n");

	msg = HIG"$N"HIG"使出「余音绕梁」，将手中剑搭在$n"HIG"兵刃上，剑随意转，连绵不绝，使$n"HIG"一时无法变招。\n";

	me->add("neili", -200);

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		msg += HIR "结果$p被$P闹个手忙脚乱，惊慌失措，呆在当场，不知如何应对！\n" NOR;
		target->start_busy((int)me->query_skill(bskill, 1)/60+3);
	} else {
		msg +=HIY"可是$p看破了$P的企图，镇定逾恒，一振振开了$P的剑，全神应对自如。\n" NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		迟滞对方出手

	出手要求：
		白云心法50级
		恒山剑法40级
		内力300
HELP
	);
	return 1;
}

