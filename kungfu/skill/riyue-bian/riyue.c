// riyue 日月鞭-日月
// campsun

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg,dodge_skill;
object weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「日月轮转」只能在战斗中对对手使用。\n");

        if (!weapon || weapon->query("skill_type") != "whip")
                return notify_fail("手中没有武器,如何使用「日月轮转」！\n");

        if( (int)me->query_skill("riyue-bian", 1) < 200 )
                return notify_fail("你的日月鞭法不够娴熟，不会使用「日月轮转」。\n");

        if( (int)me->query_skill("yijinjing", 1) < 200 )
                return notify_fail("你的易筋经等级不够，不能使用「日月轮转」。\n");

if( (int)me->query_skill("buddhism", 1) < 200 )
                return notify_fail("你的禅宗心法等级不够，不能使用「日月轮转」。\n");
          
               
        if( (int)me->query("neili") < 1000 )
                return notify_fail("你现在内力太弱，不能使用「日月」。\n");

        msg = HIR "$N口中高宣佛号，使出日月鞭中「日月」绝技，手中长索滚动飞舞，宛若灵蛇乱颤，自上而下劈向$n,\n" NOR;
	msg += HIR "接着$N手腕一抖，便如张牙舞爪的墨龙相似，急升而上，又往$n扑到。\n";
        message_vision(msg, me, target);
me->set_temp("riyue", 1);
	me->add_temp("apply/attack", 60);	
	me->add_temp("apply/damage", 200);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
   	me->add_temp("apply/attack", -60);	
	me->add_temp("apply/damage", -200);
 if ((int)me->query_skill("riyue-bian", 1)>200) {          
        msg = HIY"紧跟着$N高宣“阿弥陀佛！”，使出「日」字诀，手中长索一扬，向$n的咽喉点去，索头未到，索上所挟
劲风犹如红日当空，令对方一阵气窒，只听见「啪啪」几声巨响，索头昂起，便如一条假死的毒蛇忽地反
噬挥动，带动无数风沙，呼啸而出。\n";     
        message_vision(msg, me, target);
	me->add_temp("apply/attack", 80);	
	me->add_temp("apply/damage", 300);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	me->add_temp("apply/attack", -80);	
	me->add_temp("apply/damage", -300);
        me->delete_temp("riyue");      
        

        me->add("neili", -400);

        me->start_busy(2);

        }
else { 
msg = BCYN "紧跟着$N又宣“我佛慈悲！”，使出「月」字诀，内力返照空明，功力精纯，不露棱角，手中长索舞动时
瞧不见半点影子无声无息，似缓实急，却又无半点风声，如鬼似魅，说不尽的诡异莫名。\n"NOR;
	message_vision(msg,me,target);
	if (random(10)>4) 
		{msg=HIR"结果$n一不小心，登时淹没在$N发出的漫天鞭影之中。\n"NOR;
message_vision(msg,me,target);        
me->delete_temp("riyue");      
              target->start_busy(3+random(5));
			me->add("neili",-400);}
	else {
         dodge_skill = target->query_skill_mapped("dodge");
	 if( !dodge_skill ) dodge_skill = "dodge";
         message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);

		
me->delete_temp("riyue");      
		me->add("neili",-200);
		}
	}
return 1;

}
