//
// mingwang-jian.c 不动明王剑
// Designed by secret(秘密)
//
#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([      "action" : "$N怒目圆睁，使出一招「不动」，手中$w一抖，直刺$n的$l  ",
        "skill_name" : "不动",
        "force" : 100,
        "dodge" : 10,
        "lvl" : 0,
        "damage" : 230,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一式「起手出剑」，足下一滑，剑芒闪向$n的$l  ",
        "skill_name" : "起手出剑",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 8,
        "damage" : 230,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「山崩」，纵身跃入半空，$w如山崩般劈向$n的$l  ",
        "skill_name" : "山崩",
        "force" : 180,
        "dodge" : 10,
        "lvl" : 16,
        "damage" : 240,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出「千旋转」，将$w舞得如纺车一般，忽然一剑刺向$n的$l  ",
        "skill_name" : "千旋转",
        "force" : 220,
        "dodge" : 10,
        "lvl" : 24,
        "damage" : 248,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「降魔舞」，全身劲气贯于$w中，剑气直指$n的$l  ",
        "skill_name" : "降魔舞",
        "force" : 250,
        "dodge" : 10,
        "lvl" : 32,
        "damage" : 254,
        "damage_type" : "刺伤",
]),
([      "action" : "$N单足独立，使出一式「鹤舞」，一道剑光如白影般向$n的$l扫去  ",
        "skill_name" : "鹤舞",
        "force" : 280,
        "dodge" : 15,
        "lvl" : 40,
        "damage" : 260,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出一招「龙腾」，手中$w如游龙般扑向$n的$l  ",
        "skill_name" : "龙腾",
        "force" : 300,
        "dodge" : 20,
        "lvl" : 48,
        "damage" : 166,
        "damage_type" : "割伤",
]),
([      "action" : "$N飞身一跃，居高临下使出「花雨满天」，顿时剑尖如雨刺向$n的$l  ",
        "skill_name" : "花雨漫天",
        "force" : 320,
        "dodge" : 25,
        "lvl" : 80,
        "damage" : 280,
        "damage_type" : "刺伤",
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_combine(string combo) { return combo=="xue-dao"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("longxiang", 1) >= 20 ||
	    (int)me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if ((int)me->query_skill("longxiang", 1) < 20)
		return notify_fail("你的龙象般若功火候太浅。\n");
	else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("你的小无相功火候太浅。\n");
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("mingwang-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够，练不了不动明王剑。\n");
	me->receive_damage("qi", 20);
	return 1;
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("longxiang",1);
        skill = me->query_skill("longxiang", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "longxiang" || me->query_skill_mapped("force") == "xiaowuxiang"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIM"$N 口中喃喃念起「降妖伏魔咒」，内力汹涌而至，一层一层的加强。$n心神一乱，内力尽然提不起来！\n"NOR;
ob->set_temp("apply/attack", 0);
ob->set_temp("apply/defense", 0);
if (random(2)==0)
{
msg += HIM"$N"+HIM+"默念大明六字真言，手结摩利支天愤怒印! $n心神一荡，吐出一口鲜血!"+NOR;
if (ob->query("qi") > damage2)
{
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}

           message_vision(msg, me, ob);
           return j;
}      
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if(  me->query("jiali") > me->query_skill("force") 
          && me->query_skill_mapped("force") == "longxiang") 

if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("mingwang-jian",1)) > 150  || random(8)==0) 
{
	  victim->receive_wound("qi", damage_bonus/2+30);
        return HIG "$N右手于胸前展成莲花之状，左手折腕向上势若莲台，沉于右手下，面容肃静念道：“恕保 
只见淡淡的绿光包围$n。！\n" NOR;
}
}

string perform_action_file(string action)
{
        return __DIR__"mingwang-jian/" + action;
}