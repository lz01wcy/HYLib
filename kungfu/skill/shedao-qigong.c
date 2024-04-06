// shedao-qigong  蛇岛奇功
#include <ansi.h>;
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
([	"action" : "$N使一招"+(order[random(13)])+"「仙鹤梳翎」"NOR"手中$w一提，插向$n的$l",
	"damage" : 150,
	"parry": 40,
	"force": 150,
	"damage_type" : "挫伤",
	"skill_name" : "仙鹤梳翎"
]),
([	"action": "$N使出"+(order[random(13)])+"「灵蛇出洞」"NOR"，身形微弓，手中$w倏的向$n的$l戳去",
	"damage" : 150,
	"dodge": 80,
	"parry": 10,
	"force": 250,
	"damage_type": "刺伤",
	"skill_name" : "灵蛇出洞"
]),
([	"action": "$N身子微曲，左足反踢，乘势转身，使一招"+(order[random(13)])+"「贵妃回眸」"NOR"，右手$w已戳向$n$l",
	"damage" : 160,
	"dodge": 80,
	"parry": 20,
	"force": 250,
	"damage_type": "刺伤",
	"skill_name" : "贵妃回眸"
]),
([	"action" : "$N使一式"+(order[random(13)])+"「飞燕回翔」"NOR"，背对着$n，右足一勾，顺势在$w上一点，$w陡然向自己咽喉疾射，接着$N身子往下一缩，$w掠过其咽喉，急奔$n急射而来",
	"damage" : 170,
	"force" : 350,
        "dodge" : 50,
	"lvl" : 40,
        "damage_type" : "刺伤",
	"skill_name" : "飞燕回翔"
]),
([	"action": "$N忽的在地上一个筋斗，使一招"+(order[random(13)])+"「小怜横陈」"NOR"，从$n胯下钻过，手中$w直击$n",
	"damage" : 180,
	"dodge": 70,
	"parry": 130,
	"force": 350,
	"damage_type": "刺伤",
	"skill_name" : "小怜横陈"
]),
([	"action": "$N大吼一声，使一招"+(order[random(13)])+"「子胥举鼎」"NOR"，反手擒拿$n极泉要穴，欲将$n摔倒在地",
	"damage" : 200,
	"dodge": 25,
	"parry": 110,
	"damage" : 70,
	"force": 400,
	"damage_type": "内伤",
	"skill_name" : "子胥举鼎"
]),
([	"action": "$N双腿一缩，似欲跪拜，一招"+(order[random(13)])+"「鲁达拨柳」"NOR"左手抓向$n右脚足踝，右手$w直击$n"+(order[random(13)])+"「",
	"dodge": 180,
	"damage" : 180,
	"parry": 110,
	"force": 400,
	"damage_type": "内伤",
	"skill_name" : "鲁达拨柳"
]),
([	"action": "$N突然一个倒翻筋斗，一招"+(order[random(13)])+"「狄青降龙」"NOR"，双腿一分，跨在肩头，双掌直击$n",
	"dodge": 190,
	"damage" : 250,
	"parry": 130,
	"force": 400,
	"damage_type": "内伤",
	"skill_name" : "狄青降龙"
]),
});

int valid_enable(string usage) { return usage=="sword"|| usage=="staff"|| usage=="parry"; }

int valid_learn(object me)
{
	object weapon;

	if (objectp(weapon = me->query_temp("weapon")))
	if ((string)weapon->query("skill_type") != "staff"&&(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query_skill("shenlong-xinfa", 1) < 30)
		return notify_fail("你的神龙心法火候不够，无法学蛇岛奇功.\n");
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候不够，无法学蛇岛奇功。\n");
	if ((int)me->query_skill("shenlong-bashi", 1) < 30)
		return notify_fail("你的神龙八式火候不够，无法学蛇岛奇功。\n");
	if ((int)me->query_skill("shenlong-xinfa",1) <(int)me->query_skill("shedao-qigong",1))
		return notify_fail("你的神龙心法火候不够，无法继续学蛇岛奇功。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练蛇岛奇功。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"shedao-qigong/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("shenlong-xinfa",1);
        level2= (int) me->query_skill("shenlong-xinfa",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "shenlong-xinfa")
{
	victim->apply_condition("snake_poison",15);
	victim->apply_condition("chanchu_poison",15);
	victim->apply_condition("ill_fashao",10);
	victim->apply_condition("ill_kesou",10);
	victim->apply_condition("ill_shanghan",10);
	victim->apply_condition("ill_zhongshu",10);
	victim->apply_condition("ill_dongshang",10);
 victim->apply_condition("xuanming_poison",10);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIR "$N高声狂叫：战无不胜，攻无不克，无坚不摧，无敌不破！$n头一晕,鲜血喷出!\n";
}

 

}