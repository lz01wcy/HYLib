#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([      "action":"$N使一式"+(order[random(13)])+"「风兮破地」"NOR"，手中$w带出一股猛烈气旋攻向$n",
        "force" : 120,
        "dodge" : 10,
        "damage": 280,
        "lvl" : 0,
        "skill_name" : "风兮破地",
        "damage_type":  "刺伤"
]),
([      "action":"$N错步上前，使出"+(order[random(13)])+"「水兮滔天」"NOR"，只见漫天剑影有如排山倒海般的向$n压去",
        "force" : 140,
        "dodge" : 10,
        "damage": 260,
        "lvl" : 9,
        "skill_name" : "水兮滔天",
        "damage_type":  "割伤"
]),
([      "action":"$N一式"+(order[random(13)])+"「火兮焚野」"NOR"，猛地运发剑气，手中$w如火龙般向$n卷噬而下",
        "force" : 160,
        "dodge" : 5,
        "damage": 260,
        "lvl" : 18,
        "skill_name" : "火兮焚野",
        "damage_type":  "割伤"
]),
([      "action":"$N催动内力，一式"+(order[random(13)])+"「山兮鬼神惊」"NOR"，剑势挟带着如山般的巨大力量压向$n",
        "force" : 180,
        "dodge" : 10,
        "damage": 220,
        "lvl" : 27,
        "skill_name" : "山兮鬼神惊",
        "damage_type":  "刺伤"
]),
([      "action":"$N仰天长啸，一式"+(order[random(13)])+"「雷兮天地碎」"NOR"，天上骇然显现出无数的剑影如雷球般向$n电击而下",
        "force" : 220,
        "dodge" : 15,
        "damage": 220,
        "lvl" : 36,
        "skill_name" : "雷兮天地碎",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w现出剑芒万丈，一式"+(order[random(13)])+"「天罗魔罟」"NOR"，漫天交缠着的剑芒将$n重重围住",
        "force" : 260,
        "dodge" : 5,
        "damage": 300,
        "lvl" : 44,
        "skill_name" : "天罗魔罟",
        "damage_type":  "刺伤"
]),
([      "action":"$N一跃而起，一式"+(order[random(13)])+"「魔动九天」"NOR"，$w发出耀眼光茫，剑身幻成万道金光罩向$n的全身",
        "force" : 380,
        "dodge" : 5,
        "damage": 360,
        "lvl" : 60,
        "skill_name" : "魔动九天",
        "damage_type":  "刺伤"
]),
([      "action":"$N使出天魔剑终极境界"+(order[random(13)])+"「人剑合一」"NOR"，人与剑彼此连成一体，化作一道光芒射向$n",
        "force" : 480,
        "dodge" : 5,
        "damage": 380,
        "lvl" : 80,
        "skill_name" : "人剑合一",
        "damage_type":  "刺伤"
]),
        ([      "action":               "$N手中$w一闪，$n根本没有看清出$N的出剑！",
        "force" : 480,
                "damage":               200,
                "dodge":                60,
                "parry":                50,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N人未动，剑已出，$n只觉阴风拂面。。。。。。",
                "dodge":                50,
                "parry":                50,
                "damage":               240,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N身形一折，$w剑光不定，$n全身上下顿时被笼罩其中！",
                "damage":               220,
                "dodge":                50,
                "parry":                40,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中$w竟如圆月一般弯转，无论速度还是角度都令$n难以闪躲。",
                "dodge":                50,
                "parry":                50,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$n眼前一花，$N的$w竟已到了$n的面前！",
                "damage":               340,
                "dodge":                50,
                "parry":                50,
                "damage_type":  "割伤"
        ]), 

});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_combine(string combo) { return combo=="tmdao"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        return 1;
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
        level   = (int) me->query_skill("tmjian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,i;
	object weapon;
	string name;
	weapon = me->query_temp("weapon");
	
        level = (int) me->query_skill("kuihua-xinfa",1);
        level2= (int) me->query_skill("kuihua-xinfa",1);
        if (me->query_temp("weapon"))
	        name = "手中" + weapon->name();
        else
	        name = "双掌";
if ( !me->query_temp("action_flag") && random(6)==0 && level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"	))
{

	        message_vision(HIW "\n霎时间只见$N" HIW "身子猛摆，顿时化分为无数身影，" + name +
        	               HIW "\n宛若流星般分从不同的方位同时攻向$n" HIW "！\n"
                	       NOR, me, victim);
        me->set_temp("action_flag", 1);
        for (i = 0; i < 3; i++)
        {
                if (! me->is_fighting(victim))
                        break;
  if (random(2)==0) victim->start_busy(2);
                COMBAT_D->do_attack(me, victim, weapon, 0);
        }
        me->delete_temp("action_flag");
}
        lvl  = me->query_skill("tmdafa", 1);
        if (lvl==0)
        lvl  = me->query_skill("tmdafa", 1);
        flvl = me->query("jiali");
if (me->query_skill_mapped("force") != "tmdafa" )
                return;
        if (lvl < 120 || ! damage_bonus ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
if (random(5)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-300);
if (me->query("neili") < me->query("max_neili"))
victim->add("neili",(random(lvl)+50));
return HIC "$n" HIC "全身功力如流水般源源不绝地吸入$N的身体！\n" NOR;
        }
}
int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练天魔剑法。\n");
        me->receive_damage("qi", 25);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"tmjian/" + action;
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("tmdafa",1);
        level2= (int) me->query_skill("tmdafa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/8;
if (random(8)==0 && level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"))
{
ob->add("neili",-damage2);
me->add("neili",damage2);
msg = HIC "$N" HIC "一声冷笑! 吸星大法!! " HIC "$n" HIC "全身功力如流水般源源不绝地吸入$N的身体！\n" NOR;

           message_vision(msg, me, ob);
           return j;
}       
}