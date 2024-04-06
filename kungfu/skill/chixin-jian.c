// chixin-jian.c 痴心情长剑
// Made by deaner
// Modified by Venus Oct.1997

#include <ansi.h>
#include <combat.h>
inherit SKILL;

int yunwu(object me, object victim, object weapon, int damage);

mapping *action = ({
   (["skill_name" : "情投意合展欢颜",
     "action" : "$N使一式"+HIC"『情投意合展欢颜』"NOR+"，面露微笑，手中$w一抖，剑光"
                "暴长，洒向$n的$l",
     "dodge"  : 10,
     "force"  : 250,
     "damage" : 310,
     "lvl"    : 0,
     "damage_type":  "刺伤"]),
   (["skill_name" : "突来横祸阴阳隔",
     "action" : "$N使一式"+HIC"『突来横祸阴阳隔』"NOR+"，身形骤闪，剑招陡变，手中$w"
                "从一个绝想不到的方位斜斜刺向$n的$l",
     "dodge"  : 20,
     "force"  : 170,
     "damage" : 335,
     "lvl"    : 10,
     "damage_type":  "刺伤"]),
   (["skill_name" : "朝朝暮暮频思忆",
     "action" : "$N使一式"+HIC"『朝朝暮暮频思忆』"NOR+"，暴退数尺，低首抚剑片刻，随"
                "后手中$w骤然穿上，刺向$n的$l",
     "dodge"  : 20,
     "force"  : 175,
     "damage" : 320,
     "lvl"    : 20,
     "damage_type":  "刺伤"]),
   (["skill_name" : "千里婵娟只是空",
     "action" : "$N使一式"+HIC"『千里婵娟只是空』"NOR+"，身形一晃，疾掠而上，手中$w"
                "龙吟一声，对准$n的$l连递数剑",
     "dodge"  : 40,
     "force"  : 190,
     "damage" : 325,
     "lvl"    : 30,
     "damage_type":  "刺伤"]),
   (["skill_name" : "生生世世长相伴",
     "action" : "$N使一式"+HIC"『生生世世长相伴』"NOR+"，一闪而上扑向$n，如影相随，"
                "手中$w“铮”然有声，往$n的$l刺去",
     "dodge"  : 60,
     "force"  : 100,
     "damage" : 325,
     "lvl"    : 40,
     "damage_type":  "刺伤"]),
   (["skill_name" : "却恨天公不作美",
     "action" : "$N使一式"+HIC"『却恨天公不作美』"NOR+"，一个侧身，手中$w疾往斜上挑"
                "起，直指$n的$l",
     "dodge"  : 50,
     "force"  : 130,
     "damage" : 30,
     "lvl"    : 50,
     "damage_type":  "刺伤"]),
   (["skill_name" : "聚日无多相思苦",
     "action" : "$N使一式"+HIC"『聚日无多相思苦』"NOR+"，微微一个转身，手中$w却已自"
                "肋下穿出，罩向$n的$l",
     "dodge"  : 40,
     "force"  : 150,
     "damage" : 30,
     "lvl"    : 60,
     "damage_type":  "刺伤"]),
   (["skill_name" : "此恨绵绵无绝期",
     "action" : "$N使一式"+HIC"『此恨绵绵无绝期』"NOR+"，神色微变，剑招陡然变得凌厉无"
                "比，手中$w如匹链般洒向$n的$l",
     "dodge"  : 30,
     "force"  : 180,
     "damage" : 340,
     "lvl"    : 70,
     "damage_type":  "刺伤"]),
   (["skill_name" : "黯然神伤泪满面",
     "action" : "$N使一式"+HIC"『黯然神伤泪满面』"NOR+"，缓缓低首，暗自叹了口气，眼中"
                "莹光流动，接着手中$w中宫直进，迅捷无比地往$n的$l刺去",
     "dodge"  : 20,
     "force"  : 200,
     "damage" : 335,
     "lvl"    : 80,
     "damage_type":  "刺伤"]),
   (["skill_name" : "愿人长久空遗恨",
     "action" : "$N使一式"+HIC"『愿人长久空遗恨』"NOR+"，腾身飞跃，手中$w于半空中闪下，"
                "化作一道白色长弧洒向$n的$l",
     "dodge"  : 30,
     "force"  : 220,
     "damage" : 345,
     "lvl"    : 90,
     "damage_type":  "刺伤"]),
   (["skill_name" : "今世未能偕白头",
     "action" : "$N使一式"+HIC"『今世未能偕白头』"NOR+"，矮身侧步，手中$w反手疾挑而出，"
                "“唰”的一声往$n的$l刺去",
     "dodge"  : 65,
     "force"  : 240,
     "damage" : 350,
     "lvl"    : 100,
     "damage_type":  "刺伤"]),
   (["skill_name" : "来生还盼续前缘",
     "action" : "$N使一式"+HIC"『来生还盼续前缘』"NOR+"，蓦地疾退一步，又冲前三步，手中"
                "$w化为光弧往$n的$l刺去",
     "dodge"  : 40,
     "force"  : 260,
     "damage" : 350,
     "lvl"    : 110,
     "damage_type":  "刺伤"]),
   (["skill_name" : "此情不移坚似钢",
     "action" : "$N使一式"+HIC"『此情不移坚似钢』"NOR+"，纵身跃起，不见踪影，接着却又从"
                "半空中穿下，双手握着$w，声势逼人地刺向$n的$l",
     "dodge"  : 60,
     "force"  : 280,
     "damage" : 365,
     "lvl"    : 120,
     "damage_type":  "刺伤"]),
   (["skill_name" : "质问天公不开眼",
     "action" : "$N使一式"+HIC"『质问天公不开眼』"NOR+"，手中$w“嗤”的一声斜刺向天空，"
                "随即向下“唰唰”两下，划出一个叉字，往$n的$l刺去",
     "dodge"  : 45,
     "force"  : 300,
     "damage" : 360,
     "lvl"    : 130,
     "damage_type":  "刺伤"]),
   (["skill_name" : "痴痴伤怀动情时",
     "action" : "$N使一式"+HIC"『痴痴伤怀动情时』"NOR+"，左腿微抬，手中$w自下方挑起，"
                "激起一股劲风反挑$n的$l",
     "dodge"  : 50,
     "force"  : 310,
     "damage" : 370,
     "lvl"    : 140,
     "damage_type":  "刺伤"]),
   (["skill_name" : "但舞痴心情长剑",
     "action" : "$N倾尽全力舞出"+HIC"『但舞痴心情长剑』"NOR+"，神色十分激动，眼中泪珠"
                "滚动，手中$w疾舞不停，全身都已笼罩在迫人的剑气中，$n不由骇然，只见$N"
                "身形微变，无数道剑气已逼向$n的$l",
     "dodge"  : 70,
     "damage" : 380,
     "force"  : 320,
     "lvl"    : 150,
     "damage_type":  "刺伤"])
});

int valid_enable(string usage){return usage=="sword" || usage=="parry";}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 900)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("你的内功火候太浅。\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 120)
                return notify_fail("你的碧波神功火候太浅。\n");
        if ((int)me->query_skill("anying-fuxiang", 1) < 120)
                return notify_fail("你的暗影浮香火候太浅。\n");
        if ((int)me->query_skill("lanhua-shou", 1) < 120)
                return notify_fail("你的兰花拂穴手火候太浅。\n");
        if ((int)me->query_skill("luoying-shenjian", 1) < 120)
                return notify_fail("你的落英神剑火候太浅。\n");
        if ((int)me->query_skill("luoying-zhang", 1) < 120)
                return notify_fail("你的落英神剑掌火候太浅。\n");
        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("你的弹指神通火候太浅。\n");
        if ((int)me->query_skill("xuanfeng-leg", 1) < 120)
                return notify_fail("你的旋风扫叶腿火候太浅。\n");
        if ((int)me->query_skill("chixin-jian", 1) < 120)
                return notify_fail("你的玉箫剑法火候太浅。\n");
       if ((int)me->query_skill("count", 1) < 120)
                return notify_fail("你的阴阳八卦火候太浅。\n");
       if ((int)me->query_skill("qimen-wuxing", 1) < 120)
                return notify_fail("你的奇门五行火候太浅。\n");
        if ((int)me->query_skill("sword", 1) < 100)
                return notify_fail("你的基本剑法火候不够，无法学习痴心情长剑。\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("chixin-jian", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的痴心情长剑。\n");

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

    level   = (int) me->query_skill("chixin-jian",1);
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

    if( (int)me->query("qi") < 50)
        return notify_fail("你的体力目前没有办法练习痴心情长剑。\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 120)
                return notify_fail("你的碧波神功火候太浅。\n");
        if ((int)me->query_skill("anying-fuxiang", 1) < 120)
                return notify_fail("你的暗影浮香火候太浅。\n");
        if ((int)me->query_skill("lanhua-shou", 1) < 120)
                return notify_fail("你的兰花拂穴手火候太浅。\n");
        if ((int)me->query_skill("luoying-shenjian", 1) < 120)
                return notify_fail("你的落英神剑火候太浅。\n");
        if ((int)me->query_skill("luoying-zhang", 1) < 120)
                return notify_fail("你的落英神剑掌火候太浅。\n");
        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("你的弹指神通火候太浅。\n");
        if ((int)me->query_skill("xuanfeng-leg", 1) < 120)
                return notify_fail("你的旋风扫叶腿火候太浅。\n");
        if ((int)me->query_skill("chixin-jian", 1) < 120)
                return notify_fail("你的玉箫剑法火候太浅。\n");
       if ((int)me->query_skill("count", 1) < 120)
                return notify_fail("你的阴阳八卦火候太浅。\n");
       if ((int)me->query_skill("qimen-wuxing", 1) < 120)
                return notify_fail("你的奇门五行火候太浅。\n");
    if( (int)me->query("neili") < 60)
        return notify_fail("你的内力不够，无法练习痴心情长剑。\n");
        
    me->receive_damage("qi", 40);
    me->add("neili", -55);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"chixin-jian/" + action;
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
        victim->receive_damage("qi", random(30)+20);
	me->set_temp("yunwu_hit", 1);
	if(victim && me)
        {
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
}
	}
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
       string msg;
       int j, k;
 int level;
       j = me->query_skill("chixin-jian", 1);
       k = me->query_skill("qimen-wuxing",1);
 level = (int) me->query_skill("bibo-shengong",1);
if (random(6)==0 && level>=300 && me->query_skill_mapped("force") == "bibo-shengong")
        {
if (victim->query("qi") > 600)
victim->add("qi",-250+random(200));
victim->add("eff_qi",-(50+random(200)));
                me->add("neili", -20);
if (!victim->is_busy()) victim->start_busy(1);
return HIR "$N施展开奇门五行,$n心神一乱,被打中$l。结果鲜血狂奔!!\n";
        }
 
 
       if( random(10) >= 5 
        && !me->is_busy() 
        && !victim->is_busy() 
        && j > 120
        && k > 120
        && me->query_skill_mapped("parry") == "chixin-jian"
        && j > random(victim->query_skill("dodge",1))){
          switch(random(3)){
            case 0 :
               msg = HIW"$N施展开奇门剑路，剑剑不依照常规！\n"NOR;
               msg+= HIW"$n连连後退，全力招架，无力还招！\n"NOR;
               victim->start_busy(3);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 2);
               break;
            case 1 :
               msg = HIW"$N脚下踩著奇门步法，一下子刺出好几剑！\n"NOR;
               msg+= HIW"$n根本分不清楚那一剑是虚，那一剑是实，：猛Ｏ鹿ナ疲严守门户。\n"NOR;
               victim->start_busy(2);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 0);
               break;
            case 2 :
               msg = HIW"$N风驰电掣的绕著$n快跑，忽东忽西，简直像是足不点地的飞行一般！\n"NOR;
               msg+= HIW"$n随着$N转来转去，Ｅ得眼花缭乱，摇摇欲坠。\n"NOR;
               victim->start_busy(3);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
               break;
          }         
       }
}