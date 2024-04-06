
// tmduan.c 天魔断
// 99.2.1  by Bless
 
#include <ansi.h>
inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon2, target;
        int skill, ap, dp, damage;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("tmzhang",1);

        if( !(me->is_fighting() ))
                return notify_fail("〖天魔断〗只能对战斗中的对手使用。\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("〖天魔断〗只能空手使用。\n");		

    if (me->query("family/family_name") != "日月神教" )
        return notify_fail("你不是日月神教弟子，不能使用这项绝技！\n");
        
        if (!objectp(weapon2 = target->query_temp("weapon"))
        || (string)weapon2->query("skill_type") != "sword")
         {
        if (!objectp(weapon2 = target->query_temp("weapon"))
        || (string)weapon2->query("skill_type") != "axe")
         {
        if (!objectp(weapon2 = target->query_temp("weapon"))
        || (string)weapon2->query("skill_type") != "blade")
         {
        if (!objectp(weapon2 = target->query_temp("weapon"))
        || (string)weapon2->query("skill_type") != "staff")         
                return notify_fail("看清楚！他用的兵器不对，你无法使出〖天魔断〗！\n");
}
}
}

        if( skill < 140)
                return notify_fail("你的天魔掌等级不够, 尚不能使用〖天魔断〗！\n");

        if ( (int)me->query_str() < 30 )
                return notify_fail("你的膂力不够，不能使出〖天魔断〗！\n");

        if( me->query("max_neili") < 1500 )
                return notify_fail("你的内力不够，无法使用〖天魔断〗！\n");

        if( me->query("neili") < 800 )
                return notify_fail("你的内力不够，无法使用〖天魔断〗！\n");

        msg = HIC "$N身如鬼魅，突然出现在$n面前，右掌画了个大弧，幻起千百掌影，向着$n的兵器砍去。\n";
        message_vision(msg, me, target);
 
        damage = 10 + random(skill / 2)+ 500;
        ap = me->query_skill("strike") + skill;
        dp = target->query_skill("parry");
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                        me->add("neili",-500);
                msg = "$n顿时觉得眼前一花，只听“当啷”一声，手中";
                msg += weapon2->name();
                msg += "断为两截！\n" NOR;

                target->receive_damage("qi", damage);
                target->start_busy(2);
                weapon2->move(environment(me));
                weapon2->set("name","断了的"+weapon2->query("name"));
                weapon2->unequip();
                weapon2->set("value",0);
                weapon2->set("weapon_prop", 0);
        }
        else
        {
                if(userp(me))
                        me->add("neili",-300);
                msg = "$n冷哼一声，骈指向着$N掌心一点，$N忙不迭将手一缩，远远地避了开去。\n"NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}
