// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,damage;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("【弹梅.落雪.散花香】只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	lvl = (int) me->query_skill("zhemei-shou") / 10 + 1;
	damage = (int)me->query_skill("zhemei-shou", 1)/4;  
         if( (int)me->query_skill("bahuang-gong", 1) < 150 )
                 return notify_fail("你的八荒六合功等级还不够。\n");
         if( (int)me->query_skill("force") < 150 )
                 return notify_fail("你的内功等级不够。\n");

 if( (int)me->query_skill("zhemei-shou", 1) < 120 )
                return notify_fail("你的天山折梅手不够娴熟，不会使用【弹梅.落雪.散花香】。\n");

        if( (int)me->query_skill("bahuang-gong", 1) < 150 )
                return notify_fail("你的唯我独尊尊功等级不够，不能使用【弹梅.落雪.散花香】。\n");  if (me->query_skill_prepared("hand") != "zhemei-shou"
        || me->query_skill_mapped("hand") != "zhemei-shou")
                return notify_fail("你现在无法使用【弹梅.落雪.散花香】进行攻击。\n");            
	if( (int)me->query("neili") < 500 )
    return notify_fail("你的内力不够。\n");
  
	if( (int)me->query("max_neili") < 2000 )
    return notify_fail("你的内力修为太差。\n");
  if( (int)me->query("jing") < 200 )
    return notify_fail("你的精力不够。\n");
  
me->add_temp("apply/damage", damage);
 me->add_temp("apply/strength", damage);
  me->add_temp("apply/attack", damage); 
msg = YEL "$N微微一笑，左手向$n轻轻弹出，好像是要弹去梅花上面的露珠！" NOR;
COMBAT_D->do_attack(me,target, weapon, 1,msg);                                             message_vision(HIW"                                          【弹 梅】"NOR, me, target); 
msg = YEL "$N双手急挥，左右摇摆，幻出漫天梅花，飞雪似的向$n落来！" NOR;
COMBAT_D->do_attack(me,target, weapon, 2,msg);                                           message_vision(HIW"                                          【落 雪】"NOR, me, target); 
msg = YEL "$n突然闻到一股若有若无的香味，心猿意马之中$N的双手已向$p胸口拍来！" NOR;
COMBAT_D->do_attack(me,target, weapon, 3,msg);                                             message_vision(HIW"                                          【散花香】\n"NOR, me, target); 
me->add_temp("apply/damage", -damage);
 me->add_temp("apply/strength", -damage);
  me->add_temp("apply/attack", -damage); 
  me->start_busy(2);
  me->add("neili",-350);

if( ( random(me->query("combat_exp")) > target->query("combat_exp")/3 ) 
)
	{msg = HIR "$N双手幻出漫天手影，宛若朵朵梅花，将$n笼罩在一片梅海之中！" NOR;
		message_vision(msg + "\n", me, target);
		msg = HIY"结果$n被$N攻了个手忙脚乱！\n"NOR;
                message_vision(msg, me, target);

if (!target->is_busy())
{
		target->start_busy(3+random(2));
		me->add("neili",-100);
}
	} else
{
me->start_busy(2);
}
	return 1;
}
