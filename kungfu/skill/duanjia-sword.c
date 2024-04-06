// duanjia-sword.c 段家剑

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",}); 

mapping *action = ({
([      "action" : "$N左手捏了个剑诀，右手$w平平递出，一式"+(order[random(13)])+"「其利断金」"NOR"直刺$n的前胸",
        "force" : 150,
        "dodge" : 15,
        "damage" : 160,
        "lvl" : 5,
        "damage_type" : "刺伤"
]),
([      "action" : "$N纵身向前，$w从一个想不到的角度突然弹出，一式"+(order[random(13)])+"「碧鸡报晓」"NOR"直刺$n的左肋",
        "force" : 180,
        "dodge" : 15,
        "damage" : 185,
        "lvl" : 25,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「金马腾空」"NOR"，身形跃在半空，$w横削而出 ，直向$n的头部",
        "force" : 220,
        "dodge" : 20,
        "damage" : 105,
        "lvl" : 35,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑身斜挥，剑尖指向$n的腹部，一招"+(order[random(13)])+"「碧渊腾蛟」"NOR"，自下而上，剖向$n",
        "force" : 270,
        "dodge" : 15,
        "damage" : 170,
        "lvl" : 45,
        "damage_type" : "刺伤"
]),
([      "action" : "$N双脚离地，斜飞而出，$w射向$n的$l,好一招"+(order[random(13)])+"「笑指天南」"NOR"",
        "force" : 330,
        "dodge" : 15,
        "damage" : 190,
        "lvl" : 55,
        "damage_type" : "刺伤"
]),
([      "action" : "$N长啸一声，横剑轻挥隐隐透出王道之意，正是段家不传之秘"+(order[random(13)])+"「逐鹿中原」"NOR"，剑风罩住$n的全身",
        "force" : 380,
        "dodge" : 15,
        "damage" : 300,
        "lvl" : 65,
        "damage_type" : "刺伤"

]),
([  "action" : "$N向前跨上一步，一招"+(order[random(13)])+"「云横秦岭」"NOR"，手中$w自左向右向$n的$l
缓缓划去",
    "force" : 150,
    "dodge" : 130,
    "damage" : 125,
    "lvl" : 0,
    "skill_name" : "云横秦岭",
    "damage_type" : "刺伤"
]),
([  "action" : "$N向上跃起，左手剑诀，右手一抖，$w剑光缦妙如瀑，一式"+(order[random(13)])+"「飞流
直下」"NOR"直刺$n的$l",
    "force" : 200,
    "dodge" : 115,
    "damage" : 140,
    "lvl" : 9,
    "skill_name" : "飞流直下",
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招"+(order[random(13)])+"「雪涌兰关」"NOR"，$w闪起数道寒光，自下而上反挑$n的$l",
    "force" : 220,
    "dodge" : 115,
    "damage" : 165,
    "lvl" : 19,
    "skill_name" : "雪涌兰关",
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招"+(order[random(13)])+"「奇兵突起」"NOR"，手中$w看似横扫实则斜劈，刺向$n的$l",
    "force" : 250,
    "dodge" : 110,
    "damage" : 85,
    "lvl" : 29,
    "skill_name" : "奇兵突起",
    "damage_type" : "刺伤"
]),
([  "action" : "$N使出"+(order[random(13)])+"「夜叉探海」"NOR"，$w挽出三个剑花，绵绵不断划向$n的$l",
    "force" : 280,
    "dodge" : 115,
    "damage" : 100,
    "lvl" : 39,
    "skill_name" : "夜叉探海",
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招"+(order[random(13)])+"「泰山压顶」"NOR"，左手一捏剑诀，右手$w自上而下雷霆万钧
般直向$n的$l劈乐下去",
    "force" : 300,
    "dodge" : 115,
    "damage" : 120,
    "lvl" : 89,
    "skill_name" : "泰山压顶",
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招"+(order[random(13)])+"「雨打梨花」"NOR"，身在半空，$w回抽，反手勾向$n的$l",
    "force" : 350,
    "dodge" : 110,
    "damage" : 140,
    "lvl" : 99,
    "skill_name" : "雨打梨花",
    "damage_type" : "刺伤"
]),
([  "action" : "$N身影一晃, 绕到$n背后，一招"+(order[random(13)])+"「逐鹿中原」"NOR"，剑尖向$n的$l疾挑",
    "force" : 400,
    "dodge" : 115,
    "damage" : 250,
    "lvl" : 100,
    "skill_name" : "逐鹿中原",
    "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
       return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("kurong-changong", 1) < 20)
       return notify_fail("你的枯荣禅功火候太浅。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("duanjia-sword",1);
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
       return notify_fail("你的体力不够练段家剑。\n");
    me->receive_damage("qi", 20);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"duanjia-sword/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("kurong-changong",1);
        skill = me->query_skill("kurong-changong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "kurong-changong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;

if (me->query("qi") <= me->query("max_qi"))
{
me->add("qi",damage2);
}

if (me->query("eff_qi") <= me->query("max_qi"))
{
me->add("eff_qi",damage2);
}



msg = HIG"$N 深吸一口气！施展开一阳指诀，以纯阳指力遍布全身! 脸色红润多了。\n"NOR;
           if (!ob->is_busy() && random(3)==0)
{
msg += HIY"$n"+HIY+"被$N的纯阳指力反点! 结果点中了 "+ xue_name[random(sizeof(xue_name))] +NOR;
                ob->apply_condition("yyz_damage",30);
                ob->start_busy(3);  
}

//msg += "$n的力道被太极拳借力打力反击回来！\n",  
           message_vision(msg, me, ob);
           return j;
}      
}
