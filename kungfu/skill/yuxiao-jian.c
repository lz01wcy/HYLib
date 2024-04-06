// yuxiao-jian.c 玉箫剑法
// modified by Venus Oct.1997
// Made by deaner
#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *parry_msg = ({
	"却见$n身子微转，轻描淡写的以$W轻轻挡开$w，口唇未离箫边，乐声竟未有片刻停滞。\n",
});

mapping *action = ({
([      "action" : "$N身形一闪，手中$w一振，使出一招"+(order[random(13)])+"「山外清音」"NOR"，圈转手中$w，拦腰横削，陡然呼地一声，$w反撩，风驰电挚般疾刺$n的$l",
	"force" : 100,
	"dodge" : 10,
	"parry" : -15,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "山外清音",
	"damage_type" : "刺伤"
]),
([      "action" : "$N$w一横，使出一式"+(order[random(13)])+"「金声玉振」"NOR"，身随剑走，寓守于攻，对$n的招式竟是不闪不避，径直削向$n的$l",
	"force" : 120,
	"dodge" : -10,
	"parry" : 15,
	"damage": 30,
	"lvl" : 5,
	"skill_name" : "金声玉振",
	"damage_type" : "劈伤"
]),
([      "action" : "$N手中$w盘旋飞舞，使出一招"+(order[random(13)])+"「响隔楼台」"NOR"，反手一剑刺出，半途中已连变好几个方位，刺向$n的$l",
	"force" : 140,
	"dodge" : 10,
	"parry" : -5,
	"damage": 25,
	"lvl" : 10,
	"skill_name" : "响隔楼台",
	"damage_type" : "刺伤"
]),
([      "action" : "$N手中$w蓦然一立，使出一招"+(order[random(13)])+"「月射寒江」"NOR"，$w如新月般成弧圈转，倏地一展，电光石火般刺向$n的$l",
	"force" : 170,
	"dodge" : 5,
	"parry" : -10,
	"damage": 35,
	"lvl" : 10,
	"skill_name" : "月射寒江",
	"damage_type" : "刺伤"
]),
([      "action" : "$N挺手中$w，向$n上盘刺到，正是一招"+(order[random(13)])+"「凤曲长鸣」"NOR"，剑光闪烁，剑尖微颤，手中$w发出嗡嗡之声，点向$n上盘诸处大穴",
	"force" : 190,
	"dodge" : -10,
	"parry" : -5,
	"damage": 40,
	"lvl" : 15,
	"skill_name" : "凤曲长鸣",
	"damage_type" : "刺伤"
]),
([      "action" : "$N袍袖一拂，顺势使出一招"+(order[random(13)])+"「潇湘水云」"NOR"，剑势连绵，泠若御风，身形一沾即走，宛如翩翩起舞，飘然刺向$n的$l",
	"force" : 210,
	"dodge" : 20,
	"parry" : -5,
	"damage": 45,
	"lvl" : 20,
	"skill_name" : "潇湘水云",
	"damage_type" : "刺伤"
]),
([      "action" : "$N伸指在$w上一弹，铮的一声清响，一招"+(order[random(13)])+"「棹歌中流」"NOR"，$w中宫直进，更无丝毫花巧，凌厉无前的刺向$n的$l",
	"force" : 230,
	"dodge" : 0,
	"parry" : 45,
	"damage": 55,
	"lvl" : 20,
	"skill_name" : "棹歌中流",
	"damage_type" : "刺伤"
]),
([      "action" : "$N身形展动，使出一式"+(order[random(13)])+"「萧史乘龙」"NOR"，手中$w矫夭飞舞，如神龙破空一般，刺向$n的$l，姿态飘逸，大有仙气",
	"force" : 250,
	"dodge" : 10,
	"parry" : 0,
	"damage": 45,
	"lvl" : 25,
	"skill_name" : "萧史乘龙",
	"damage_type" : "刺伤"
]),
([      "action" : "$N剑法一变，身形急趋急退，一式"+(order[random(13)])+"「飞花点翠」"NOR"，剑气森森，剑势如满天花雨一般，向四面八方铺洒开来，实在令人避无可避",
	"force" : 280,
	"dodge" : 0,
	"parry" : 10,
	"damage": 50,
	"lvl" : 30,
	"skill_name" : "飞花点翠",
	"damage_type" : "刺伤"
]),
([      "action" : "$N逆踏先天八卦方位，剑交左手，徐徐使出一招"+(order[random(13)])+"「猗兰履霜」"NOR"，手中$w斜指，刺向$n，剑势虚虚实实，应左则右，与通常剑理大相径庭",
	"force" : 300,
	"dodge" : -5,
	"parry" : 5,
	"damage": 50,
	"lvl" : 35,
	"skill_name" : "猗兰履霜",
	"damage_type" : "刺伤"
]),
([      "action" : "$N手中$w成弧，一招"+(order[random(13)])+"「玉漏催银箭」"NOR"，刺向$n，去势虽不甚急，但却占尽先机，将$n身周三尺方圆之地尽数封住",
	"force" : 320,
	"dodge" : 0,
	"parry" : 5,
	"damage": 55,
	"lvl" : 40,
	"skill_name" : "玉漏催银箭",
	"damage_type" : "刺伤"
]),
([      "action" : "$N脚步踉踉跄跄，看似已摇摇欲坠，实则足踩九宫，一招"+(order[random(13)])+"「酒阑闻塞笛」"NOR"，剑势平平淡淡，若有若无地刺向$n的$l",
	"force" : 350,
	"dodge" : 0,
	"parry" : 5,
	"damage": 65,
	"lvl" : 45,
	"skill_name" : "酒阑闻塞笛",
	"damage_type" : "刺伤"
]),
([      "action" : "$N移步换形，一招"+(order[random(13)])+"「歧山别鹤」"NOR"，$w脱手飞出，疾射$n的$l，接着使出分身捉影，后发先至，紧贴$w飞撩过来，骈指为剑，刺向$n",
	"force" : 380,
	"dodge" : 10,
	"parry" : -10,
	"damage": 75,
	"lvl" : 50,
	"skill_name" : "歧山别鹤",
	"damage_type" : "刺伤"
]),
([      "action" : "$N一声长啸，内力源源不绝注入剑身，剑上青芒大盛，一式"+(order[random(13)])+"「广陵止息」"NOR"，剑发龙吟，一道匹练也似的剑光挟着森森剑气破空而起，宛如天河倒泻，沛然莫御",
	"force" : 400,
	"dodge" : -10,
	"parry" : -20,
	"damage": 120,
	"lvl" : 60,
	"skill_name" : "广陵止息",
	"damage_type" : "刺伤"
]),
([      "action" : "$N脚踩伏羲六十四卦方位，剑势加快，使出一招"+(order[random(13)])+"「星河千帆舞」"NOR"，只见一片茫茫剑气中，无数青色光圈潮涌而至，倾刻之间$n已没入剑光之中",
	"force" : 420,
	"dodge" : 10,
	"parry" : 10,
	"damage": 95,
	"lvl" : 70,
	"skill_name" : "星河千帆舞",
	"damage_type" : "劈伤"
]),
([      "action" : "$N跨上一步，$w向前递出，其势增之一分嫌太急，减之一分嫌太缓，正是一式"+(order[random(13)])+"「天际识归舟」"NOR"，剑势尤如青天白云，无暇无垢",
	"force" : 450,
	"dodge" : 0,
	"parry" : 20,
	"damage": 100,
	"lvl" : 90,
	"skill_name" : "天际识归舟",
	"damage_type" : "刺伤"
]),
([      "action" : "$N漫步提腰，一招"+(order[random(13)])+"「英雄潇洒我独行」"NOR"，飘然来至$n面前，随即手中$w微震，
剑尖疾点向$n的$l",
        "force" : 150,
        "dodge" : 20,
        "damage" : 30,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N斜跨一步，使出一式"+(order[random(13)])+"「儿女情长只恨短」"NOR"，挥剑舞出两道一长一短的光影
直刺$n的$l",
        "force" : 175,
        "dodge" : 15,
        "damage" : 35,
        "lvl" : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「翩然离去不思归」"NOR"，$w骤然出鞘又立刻回到剑鞘中，随即转身翩然
离去。$n这时才感觉到有一股劲气逼向自己的$l",
        "force" : 200,
        "dodge" : 25,
        "damage" : 40,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N双手举剑向天，一招"+(order[random(13)])+"「傲立群雄无所惧」"NOR"，$w带起阵阵惊雷，自上而下向
$n的头颅剁去",
        "force" : 225,
        "dodge" : 10,
        "damage" : 45,
        "lvl" : 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N施展出"+(order[random(13)])+"「倾城一笑万人醉」"NOR"，手握$w颔首微微一笑，$n只看得一呆，却见
一道剑影犹如龙游般袭向自己的$l，而自己却没看清$N何时出的手！！",
        "force" : 250,
        "dodge" : 20,
        "damage" : 50,
        "lvl" : 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左脚踏实，右脚虚点，一招"+(order[random(13)])+"「一曲奏毕愁肠结」"NOR"，$w带着一团剑花，飘浮
不定地逼向$n的$l",
        "force" : 270,
        "dodge" : 55,
        "damage" : 85,
        "lvl" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「处子弄箫亦多情」"NOR"，左手轻抚$w，随即猛地一弹，右手向前一递，
只见一道闪烁不定的剑影迅速刺向$n的$l",
        "force" : 290,
        "dodge" : 55,
        "damage" : 100,
        "lvl" : 60,
        "damage_type" : "刺伤"
]),
([      "action" : "$N回身低首，神色黯然，一招"+(order[random(13)])+"「闻声哀怨断人肠」"NOR"，$w剑尖游移不定地刺向
$n的$l",
        "force" : 310,
        "dodge" : 55,
        "damage" : 120,
        "lvl" : 70,
        "damage_type" : "刺伤"
]),
([      "action" : "$N坐手掩面，一招"+(order[random(13)])+"「彼将离兮泪涟涟」"NOR"，右手$w斜向下划出，$n微觉奇怪，正迟
疑间，却见$N手中的$w已反挑而上，直刺自己的咽喉",
        "force" : 330,
        "dodge" : 55,
        "damage" : 180,
        "lvl" : 80,
        "damage_type" : "刺伤"
]),
([  "action" : "$N忽然面露微笑，一招"+(order[random(13)])+"「随音而舞笑开颜」"NOR"，右手$w一闪，舞出三团剑花刺向$n
的上中下三路",
        "force" : 360,
        "dodge" : 55,
        "damage" : 200,
        "lvl" : 90,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左手食指疾点$w，一招"+(order[random(13)])+"「箫音有情人无情」"NOR"，$w发出一声龙吟，余音缭绕，$n
只觉得的胸前一闷，一阵刚猛的劲气迫向自己",
        "force" : 390,
        "dodge" : 55,
        "damage" : 220,
        "lvl" : 100,
        "damage_type" : "刺伤"
]),
([      "action" : "$N右手微震，一招"+(order[random(13)])+"「箫声响毕情两断」"NOR"，手中$w急颤，发出一阵震耳欲聋的轰鸣，
刹那间飞沙走石，$n已在一团剑光的笼罩下，正勉力支撑着",
        "force" : 420,
        "dodge" : 55,
        "damage" : 350,
        "lvl" : 110,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if (((int)me->query("max_neili") < 500) ||
        ((int)me->query_skill("bibo-shengong", 1) < 100) ||
        !(me->query("couple/have_couple")))
       return notify_fail("黄药师说道: 玉箫剑法，只付有缘。你不是性情中人。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("yuxiao-jian",1);
        if (random(level) > 240 && me->query_skill("force") > 200 && me->query("neili") >= 500)
         {
	return ([
	"action":HIG"$N身子滴溜溜的打了半个圈子，$w"NOR+HIG"一挺，丹田中提一口真气，$w"+HIG"上所附真力递增，青芒犹似长蛇般伸缩不定，蓦地剑芒突盛，刺向$n的$l！"NOR,
	"force" : 500,
	"dodge" : 140,
	"parry" : 140,
	"damage": 500,
	"weapon": HIG"剑芒"NOR,
	"damage_type":  "刺伤"
]);
}
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
       return notify_fail("你的体力不够练玉箫剑法。\n");
    me->receive_damage("qi", 30);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"yuxiao-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
       string msg;
       int j, k;
 int level;
       j = me->query_skill("yuxiao-jian", 1);
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
        && me->query_skill_mapped("parry") == "yuxiao-jian"
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
