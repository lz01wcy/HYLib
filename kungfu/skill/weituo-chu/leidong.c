#include <ansi.h>
#include <combat.h>
inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill,improve;
int extra;string msg;
        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("「雷动九天」只能对战斗中的对手使用。\n");

        if( !objectp(weapon = me->query_temp("weapon"))
         || weapon->query("skill_type") != "club" )
                return notify_fail("你手中无棍，怎能运用「雷动九天」？！\n");

        if( me->query_temp("sl_leidong"))
                return notify_fail("你刚使完「雷动九天」，目前气血翻涌，无法再次运用！\n");

        if( me->query_temp("fumo"))
                return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");


        if((int)me->query_skill("weituo-chu", 1) < 150
         ||(int)me->query_skill("weituo-chu", 1) < 150
         ||(int)me->query_str() <=30 )
                return notify_fail("你修为还不够，还未能领悟「雷动九天」！\n");

        if( me->query_skill("yijinjing", 1) < 150 )
                return notify_fail("你的内功修为火候未到，施展只会伤及自身！\n");

        if( me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("你所用的内功与「雷动九天」心法相悖！\n");

        if (me->query_skill_mapped("club") != "weituo-chu"
         )
                return notify_fail("你现在无法使用「雷动九天」进行攻击。\n");

        if( me->query("max_neili") <= 2000 )
                return notify_fail("你的内力修为不足，劲力不足以施展「雷动九天」！\n");

        if( me->query("neili") <= 600 )
                return notify_fail("你的内力不够，劲力不足以施展「雷动九天」！\n");

        if( me->query("jing") <= 200 )
                return notify_fail("你的精力有限，不足以施展「雷动九天」！\n");

        message_vision(BLU"\n突然$N大喝一声：「雷动九天」，面色唰的变得通红，须发皆飞，真气溶入"+weapon->name()+BLU"当中，“嗡”的一声，发出"HIW"闪闪光亮"BLU"！\n" NOR, me);

        if(userp(me)){
           me->add("neili", -300);
           me->add("jing", -50);
           if(weapon->query("rigidity")<10)
                weapon->add("rigidity", 1);
        }
        skill = me->query_skill("club");
      	improve = skill/5 + random(skill/5);
      	if ( improve > 100 ) improve = 100 + random(improve-100) / 5;

        me->set_temp("sl_leidong", improve);
        me->add_temp("apply/damage", improve);//
        me->add_temp("apply/club", improve);//
        me->add_temp("apply/strength", improve);//
	extra = me->query_skill("weituo-chu",1) / 20;
	extra += me->query_skill("weituo-chu",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
target->start_busy(2);
	msg = HIR  "雷！\n" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIR  "  动！ \n" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIR  "    九！ \n" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIR  "      天！ \n" NOR;
if (!target->is_busy())
{
	target->start_busy(1);
}
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
        call_out("remove_effect", 1,  me, weapon, skill);
        me->start_perform(5, "「雷动九天」");
        return 1;
}

void remove_effect(object me,object weapon,int count)
{
        int i;
        if(!me) return;
        if(! me->is_fighting()
         || !weapon
         || me->query_skill_mapped("club") != "weituo-chu"
         || count < 1 ){
          i = me->query_temp("sl_leidong");
          me->add_temp("apply/club", -i);
          me->add_temp("apply/damage", -i);
          me->add_temp("apply/strength", -i);
          me->delete_temp("sl_leidong");
	if (weapon)
		message_vision(HIY"\n$N一套「雷动九天」使完，手中"NOR+weapon->name()+HIY"上的光芒渐渐也消失了。\n"NOR, me);
          return;
        }
        else {
          call_out("remove_effect", 1, me, weapon, count -1);
        }
}

int help(object me)
{
        write(
@HELP
雷动九天
       是佛门神功－－韦陀杵的特殊攻击，将一身佛门内功注入手中所用禅杖中，
       斩妖伏魔，无坚不摧，刚猛无，乃是佛门第一等的伏魔神功。
HELP
        );
        return 1;
}
