//ban.c 打狗棒法「绊」字诀
// fear 12/99

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
                string* msgsuccess;
                string* msgfail;
                string* msgloop, msg;
                int random_text;
                int duration;
                int dodge;
                int speed;
                string weapon;
        int skill, att;
                int nskill;
                int ndamage;
        int hits;
        int i;
        int ban_count=0;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("绊字诀只能对战斗中的对手使用。\n");

        if( target->is_busy() ) {
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧\n");
        }

        if( me->query_temp("ban",1) )
                return notify_fail("你已在使用绊字诀！\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("你所用的并非混天气功，无法施展绊字诀！\n");

        if( me->query_skill("force") < 199 )
                return notify_fail("你的混天气功火候未到，无法施展绊字诀！\n");

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("你的内力不够。\n");

        if (me->query_skill("huntian-qigong", 1)<70)
                return notify_fail("你的本门内功火候未到，！\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
			return notify_fail("你使用的武器不对。\n");

        if( me->query_skill("staff") < 199 )
                return notify_fail("你的打狗棒法修为不足，还不会使用绊字诀！\n");

        skill =  ( me->query_skill("dagou-bang")
                + me->query_skill("force") ) / 5;

                nskill = ( me->query_skill("dagou-bang") ) /4;

                me->set_temp("apply/speed", me->query_temp("apply/speed",1)+skill*3/2);
                speed = target->query_temp("apply/speed",1);
                dodge = target->query_temp("apply/dodge",1);
                
        if( me->query("neili") <= skill*3 )
                return notify_fail("你的内力不够使用绊字诀！\n");

        weapon = me->query_temp("weapon");

        if( me->query_skill("dagou-bang") < 300 ) { hits=3; }
        else if( me->query_skill("dagou-bang") < 400 ) { hits=4; }
        else if( me->query_skill("dagou-bang") < 500 ) { hits=5; }
        else { hits=6; }

                if( random(2)) {
                        message_vision(HIG "突然$N"+ weapon->name()+HIG"挥出，以打狗棒的「绊」字诀着地扫去，有如长江大河，绵绵而至。\n\n" NOR, me, target); }
                else {
                        message_vision(HIG "$N"+ weapon->name()+HIG"伸出，施展打狗棒法的「绊」字诀，连环钩盘，虽只一个「绊」字，中间却蕴藏着千变万化。\n\n" NOR, me, target);}


        for(i=0;i<=hits;i++) {
                if (random(me->query("combat_exp"))  > random((int)target->query("combat_exp")) ) { 
                                        msgsuccess = ({
                                                "$n纵身稍慢，被"+ weapon->name()+HIY"在左胫上一拨，右踝上一钩，扑地倒了。",
                                                "$n立足不住，被"+ weapon->name()+HIY"绊了一交，仰天摔倒。",
                                                weapon->name()+HIY"腾的一下，$n登时措手不及，被绊得一交摔倒。",
                                                weapon->name()+HIY"猛然翻转，击中$n的脚胫。$p立足不稳，一个踉跄，扑地跌倒。"
                                        });
                        msg = HIY"\n"+ msgsuccess[random(sizeof(msgsuccess))] +"\n" NOR;
                                message_vision(msg, me, target);

                                if(nskill > 100) { ndamage=100;}
                                else {
                                        ndamage = nskill; }

                        ban_count++;
                        me->start_busy(2);
                                target->start_busy(1 + random(3));
                        target->add("qi",-ban_count * ndamage);
                            target->add("qi",-me->query_skill("dagou-bang")/2+random(300));
                        target->add("eff_qi",-me->query_skill("dagou-bang")/2+random(300));
                        target->add_temp("apply/dodge", -skill/10 );
                                target->add_temp("apply/attack", -skill/10 );
                }
                else
                {
                                        msgfail = ({
                                                "$n微感劲风袭向下盘，急忙涌身跃起，总算躲过了一招。",
                                                "$n轻跃相避，立时躲开了这一招。" ,
                                                "$n纵身跃起，避过了这惊险的一棒。",
                                                "$n凌空窜起，将跌势变为跃势，再稳稳落下。"
                                        });
                        msg = CYN"\n"+ msgfail[random(sizeof(msgfail))] +"\n" NOR;
                                message_vision(msg, me, target);

                        me->start_busy(2);
                }
            if (i < hits) { 
                                        msgloop = ({
                                                "$n刚跃起，尚未落地，那"+ weapon->name()+HIG"又是一挑一打。",
                                                "$p越跃越快，但见地下一片绿竹化成的碧光盘旋飞舞。",
                                                "那「绊」字诀乃是一棒快似一棒，$N一绊不中，二绊续至，决不容$n有丝毫喘息时机。",
                                                "$n纵身上跃，但觉得脚下犹如陷入了泥沼，又似缠在无数藤枝之中。"
                                        });
                        msg = HIG"\n"+ msgloop[random(sizeof(msgloop))] +"\n" NOR;
                                message_vision(msg, me, target);

                                }
                        me->add("neili", -150 );
                        me->add("qi", -55 );
        }

        me->set_temp("ban",1);
                duration = 15 - me->query_skill("dagou-bang") / 50;
                if (duration < 5) { duration = 5; }
        call_out("remove_effect",duration,me,target,speed , dodge);
        return 1;
}

void remove_effect(object me, object victim, int speed, int dodge)
{
        if (objectp(victim)) {
                victim->set_temp("apply/attack", speed);
                victim->set_temp("apply/dodge", dodge);
        }
        if (objectp(me)) {
                me->set_temp("apply/speed",0);
        me->delete_temp("ban");
        }

        if( objectp(me) && objectp(victim) && victim->is_fighting(me) )
                message_vision(HIG "\n$N吸了一口气，将内力收回丹田，棒招也恢复正常！\n\n" NOR, me);

        return 0;
}
