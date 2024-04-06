// hengshan-sword.c 衡山剑法
// Last Modified by sir 10.22.2001
// Modified by Java Sep.1998
//重进攻轻防守

#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

int yunwu(object me, object victim, object weapon, int damage);
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([      "skill_name" :"衡山云雾",
	"action":  "$N右手$w慢慢指出，突然间在空中一颤，发出嗡嗡之声，跟着便是嗡嗡两剑，一招"HIW"「衡山云雾」"NOR"手中$w剑光暴长，向$n的$l刺去",
        "lvl" : 0
]),
([      "skill_name" :"百变千幻",
	"action":  "$N一招"HIC"「百变千幻」"NOR"手中$w如鬼如魅，竟然已绕到了$n背后，$n急忙转身，耳边只听得嗡嗡两声",
	"lvl" : 10
]),
([      "skill_name":    "泉鸣芙蓉",
	"action":  "$N不理会对方攻势来路，手中$w刷的一剑"MAG"「泉鸣芙蓉」"NOR"，向$n小腹刺去",
	"lvl" : 20
]),
([      "skill_name":    "鹤翔紫盖",
	"action":  "$N不理会对方攻势来路，手中$w刷的一剑"HIM"「鹤翔紫盖」"NOR"，向$n额头刺去",
	"lvl" : 30
]),
([      "skill_name":    "石廪书声",
	"action":  "$N手中$w倏地刺出，剑势穿插迂回，如梦如幻，正是一招" HIG"「石廪书声」"NOR"，向$n$l刺去",
	"lvl" : 40
]),
([      "skill_name":    "天柱云气",
	"action":  "$N手中$w倏地刺出，极尽诡奇之能事，动向无定，不可捉摸。正是一招"RED"「天柱云气」"NOR"，指向$n$l",
	"lvl" : 50
]),
([      "skill_name":    "雁回祝融",
	"action" : "$N飞身跃起，"HIR"『雁回祝融』"NOR"！，$w发出一声龙吟从半空中洒向$n的$l",
	"lvl" : 60
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力不够，没有办法练衡山剑法。\n");
	if( (string)me->query_skill_mapped("force")!= "huiyan-xinfa")
		return notify_fail("衡山剑法必须配合回雁心法才能练。\n");

	if ((int)me->query_skill("huiyan-xinfa", 1) < 20)
		return notify_fail("你的回雁心法火候太浅。\n");

	if ((int)me->query_skill("luoyan-hand", 1) < 50)
		return notify_fail("你的大落雁手火候太浅。\n");

	if ((int)me->query_skill("qiuyan-nanhui", 1) < 50)
		return notify_fail("你的秋雁南回火候太浅。\n");

	if ((int)me->query_skill("biluo-zhang", 1) < 50)
		return notify_fail("你的碧罗掌火候太浅。\n");		

	if( !(ob = me->query_temp("weapon"))
		|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够，没有办法练习衡山剑法。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 5;
	int d_e2 = 30;
	int p_e1 = 20;
	int p_e2 = 5;
	int f_e1 = 100;
	int f_e2 = 250;
	int m_e1 = 210;
	int m_e2 = 390;
	int i, lvl, seq, ttl = sizeof(action);
        int level;
        string *msg1,*msg2;
        msg1 = ({
		HIW"$N手中$w"+HIW"连连挥舞，声东击西，虚虚实实，幻人耳目，变化古怪之极，$n不禁心下骇然！"NOR,
		HIW"$N手中$w"+HIW"越使越快，一套「百变千幻衡山云雾十三式」有如云卷雾涌，$n不由得目为之眩！"NOR,
		HIW"＜$N手上$w"+HIW"剑招变幻，犹如鬼魅，五花八门，层出不穷，$n＞跹矍熬∈且黄剑光飞舞来去！"NOR,
        });
        msg2 = ({
		HIR"但见一点点鲜血从$w"+HIR"下溅了出来，$n腾挪闪跃，竭力招架，始终脱不出$N的剑光笼罩，鲜血渐渐在身周溅成了一个红圈，$N又已刺出一剑！"NOR,
		HIY"$N一剑既占先机，後着绵绵而至，一柄$w"+HIY"犹如灵蛇，颤动不绝，在$n的攻势中穿来插去，只逼得$n连连倒退！"NOR,
		HIY"$n中了一剑，大骇之下，急向後退，$N手中$w"+HIY"已如狂风骤雨般连攻，当真是兔起鹘落，变化快极！"NOR,

        });
	if(me->query_temp("yunwu") && me->query_temp("yunwu_hit") ){
        me->add("neili", -20);
	me->delete_temp("yunwu_hit");
        return ([
        "action":msg2[random(sizeof(msg2))] ,
        "force" : 500,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 500,
        "damage_type":"刺伤"]);
        }
        else if (me->query_temp("yunwu") ){
        me->add("neili", -20);
        return ([
        "action":msg1[random(sizeof(msg1))] ,
        "force" : 580,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 550,
	"post_action": (: yunwu :),	
        "damage_type":"刺伤"]);
        }



	lvl = (int) me->query_skill("hengshan-sword", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	seq = random(seq);       /* 选择出手招数序号 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "割伤" : "刺伤",
	]);
}

int yunwu(object me, object victim, object weapon, int damage)
{

if (!victim) return 0;
if (!me) return 0;

        if(damage==RESULT_DODGE || damage==RESULT_PARRY) return 1;

	   else if ( !living(victim) && victim->query_skill("force") > 100 ) {
                message_vision(HIR"\n＜$n伤口中一道血箭如涌泉般向上喷出，原来$p中剑后内力未消，将鲜血逼得从伤口中急喷而出，既诡异，又可怖。\n" NOR, me,victim);
		me->delete_temp("yunwu");
                return 1;
	   }
	else{
if (!victim) return 0;
if (!me) return 0;
if (me->is_busy() ) return 0;
//if (victim=me) return 0;
	me->add("neili", -30);
        victim->start_busy(2);
        victim->receive_damage("qi", random(30)+30);
	me->set_temp("yunwu_hit", 1);
	if(victim && me)
        {
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
}
	}
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("hengshan-sword",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 180)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        return HIY "「云雾十三式!!」寒光陡闪，$N猛地反刺中了$n。\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(12)==1 || random(level) > 120)
	{

        victim->receive_wound("qi", damage_bonus );	
        return RED "$N手中的剑越使越快，如梦如幻! 一股鲜血从$n的身上刺出 ！\n" NOR;
  }
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"hengshan-sword/" + action;
}
int help(object me)
{
	write(HIC"\n衡山剑法："NOR"\n");
	write(@HELP

    衡山剑法为衡山武功。

	学习要求：
		本门基础武功50
		回雁心法50
		内力50
HELP
	);
	return 1;
}

