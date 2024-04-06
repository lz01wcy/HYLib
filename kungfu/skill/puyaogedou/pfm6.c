// chan.c 太极剑法「缠」字诀

#include <ansi.h>

inherit F_SSERVER;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
});
int perform(object me, object target)
{
        object weapon;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能对战斗中的对手使用。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧\n");
                
        if( (int)me->query_skill("puyaogedou", 1) < 40 )
                return notify_fail("你的等级不够娴熟，不会使用「毒雾」\n");
        if( me->query("up1") < 1 )
                return notify_fail("你现在不能使用此pfm.\n");
        if( me->query("pfm6") < 1 )
                return notify_fail("你现在不能使用此pfm.\n");


        msg = HIG "只见$N口一张，一团重重的毒雾喷向$n。\n";

if (me->query("up1")==1)
{
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR "$n不由一声惨嚎摔倒在地，身体已痛苦得蜷缩成一团！\n" NOR;
target->apply_condition("ill_dongshang",10 );
target->apply_condition("ill_fashao",10 );
target->apply_condition("ill_kesou",10 );
target->apply_condition("ill_shanghan",10 );
target->apply_condition("ill_zhongshu",10 );
	       target->apply_condition("snake_poison",10 );
	       target->apply_condition("wugong_poison",10 );
	       target->apply_condition("chanchu_poison",10);
target->apply_condition(du[random(sizeof(du))], 15);
            } else {
                msg += "可是$n早有准备，一个懒驴打滚，堪堪躲过了。\n" NOR;
                me->start_busy(random(3));
        }
        message_combatd(msg, me, target);
}
if (me->query("up1")==2)
{
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
                msg += HIR "$n不由一声惨嚎摔倒在地，身体已痛苦得蜷缩成一团！\n" NOR;
	       target->apply_condition("snake_poison",30 );
	       target->apply_condition("wugong_poison",30 );
	       target->apply_condition("zhizhu_poison",30 );
	       target->apply_condition("xiezi_poison",30 );
	       target->apply_condition("chanchu_poison",30);
            target->apply_condition(du[random(sizeof(du))], 35);
            target->apply_condition(du[random(sizeof(du))], 35);
            target->apply_condition(du[random(sizeof(du))], 35);
            } else {
                msg += "可是$n早有准备，一个懒驴打滚，堪堪躲过了。\n" NOR;
                me->start_busy(random(3));
        }
        message_combatd(msg, me, target);
}

        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}

