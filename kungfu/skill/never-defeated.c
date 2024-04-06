// never-defeated.c 不败神功
#include <ansi.h>
inherit FORCE;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *dodge_msg = ({
        "$n移开数步，恰好躲过了$N的攻击。\n",
        "$n忽然反击，直指$N的破绽，逼得$N只能回守。\n",
        "$n轻身闪避，将$N的实招全部躲过。\n",
        "$n脚下一个跄踉，似乎无意，却刚好躲过$N这一击。\n",
});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("never-defeated", 1);
        return lvl * lvl * 20 * 15 / 100 / 200;
}

mapping *action_default = ({
([      "action":"$N左手捏着剑诀，右足踏开一招"+(order[random(13)])+"“定阳针”"NOR"向上斜刺，$w锵然跃出倏的化作几点星光射向$n的$l",
        "force" : 610,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 695,
        "damage_type":  "震伤"
]),
([      "action" : "$N运剑如风，剑光霍霍中反攻$n的$l，尝试逼$n自守，剑招似是"+(order[random(13)])+"「伏
魔剑」"NOR"的"+(order[random(13)])+"「龙吞式」"NOR"。",
        "force" : 610,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type":  "擦伤"
]),
([      "action" : "$N手中$w越转越快，使的居然是衡山的"+(order[random(13)])+"「百变千幻云雾十三式」"NOR"，剑
式有如云卷雾涌，旁观者不由得目为之眩！",
        "force" : 630,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 695,
        "damage_type":  "割伤"
]),
([      "action" : "但见$N挺身而上，$w一旋，一招仿佛泰山剑法的"+(order[random(13)])+"「来鹤清泉」"NOR"直刺$n
的$l！",
        "force" : 625,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type":  "内伤"
]),
([      "action" : "$N奇诡地向$n挥出"+(order[random(13)])+"「泉鸣芙蓉」"NOR"、"+(order[random(13)])+"「鹤翔紫盖」"NOR"、"+(order[random(13)])+"「石廪书声」"NOR"、"+(order[random(13)])+"「
天柱云气」"NOR"及"+(order[random(13)])+"「雁回祝融」"NOR"衡山五神剑！",
        "force" : 630,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type":  "刺伤"
]),
([      "action": HIG"$N眼中射出一道青芒，手中$w使出"RED"「天下无狗」"NOR""HIG"，劈天盖地般攻向$n"NOR,
        "force" : 640,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type":  "割伤"
]),
([      "action" : HIW"「 飞翔龙闪! 」"+HIY"$N突然消失了！随后$w的反光出现在了$n的头上。"+HIY"$N尽然在办空使出了拔刀术。 "NOR,
        "force" : 610,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type":  "内伤"
]),
([      "action" : HIC"「回天剑舞六连!」"+HIW"$N反握小太刀,运用流水招式刺出,左右再变两招,瞬间出六招。 "NOR,
        "force" : 620,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type":  "内伤"
]),
([      "action":HIY"$N满场游走，$w"+HIY"上一招未毕，二招至，剑招初出时人尚在左，剑招抵敌时身已转右，竟似剑是剑，人是人，两者殊不相担$n望之不禁骇然！"NOR,
        "force" : 610,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 695,
        "damage_type":  "割伤"
]),
([      "action":HIW"$N急退急趋，纵上连刺三剑，$w"+HIW"飘忽来去，东刺西击，这一路玉女剑法更见使得英气爽朗，顾盼生姿！"NOR,
        "force" : 630,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 695,
        "damage_type":  "瘀伤"
]),
([      "action" : HIW "$N身法飘逸，神态怡然，剑意藏于胸中，手中$w" HIW "随意挥洒而出，独孤"
                   "九剑已到了收发自如的境界",
        "force" : 620,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 990,
        "damage_type":  "刺伤"
]),
});

mapping *action_whip = ({
([      "action" : "$N鞭上内劲不绝催动，内功施展到了淋漓尽致，$w呼啸而出，向$n面门点去，鞭身未到，$w上所挟劲风已令$n一阵气窒",
        "force" :630,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 695,
        "damage_type": "擦伤"
]),
([      "action": "$N鞭上内劲不绝催动，内功施展到了淋漓尽致，$w呼啸而出，向$n面门点去，鞭身未到，$w上所挟劲风已令$n一阵气窒",
        "force" : 610,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type": "擦伤"
]),
([      "action": "$N含胸拔背、沉肩坠肘，一式"+(order[random(13)])+"「弘忍能刺」"NOR"，力道灵动威猛，虚实分明，劲力从四面八方向$n挤压出去",
        "force" : 640,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 695,
        "damage_type": "割伤"
]),
([       "action": HIR "$N手腕一抖，但见飞舞的$w从天而下和$n缠在一起，一股排山倒海的内劲无声息的向$n胸口撞去！"NOR,
        "force" : 625,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type": "内伤"
]),
([     "action": HIR "$N把手中$w抖动成圈，绕着$n越转越急，越转越快，$p登时身不由主，被套得连转了几身，眼看就要摔倒！"NOR,
        "force" : 610,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 990,
        "damage_type": "刺伤"
]),
});

string *usage_skills = ({ "sword", "blade", "dagger",
                          "staff", "hammer", "club", "whip",  
                          "dodge", "parry", "force", "throwing" });

int valid_enable(string usage)
{
        return (member_array(usage, usage_skills) != -1);
}

int valid_combo(string combo)
{
        return combo == "never-defeated";
}

int valid_force(string force) { return 1; }

int double_attack() { return 1; }

mapping query_action(object me, object weapon)
{
        switch (weapon ? weapon->query("skill_type") : "default")
        {
        case "whip":
                return action_whip[random(sizeof(action_whip))];
        default:
                return action_default[random(sizeof(action_default))];
        }
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        int level;
        int i;

//       if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");

       if( me->query("zhuanfinal/8",1) != 1)
        return notify_fail("你没有资格使用这项技能！\n");

        
        if (me->query("int") < 38)
                return notify_fail("你觉得不败神功过于深奥，绝"
                                   "非自己的智力所能理解。\n");

	if (me->query("gender") == "无性" &&
	    (int)me->query_skill("never-defeated", 1) > 239)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的不败神功。\n");

        level = me->query_skill("never-defeated", 1);


        if (me->query_skill("force", 1) < level)
                return notify_fail("你对基本内功的理解还不够，无法继续"
                                   "领会更高深的不败神功。\n");

        if (me->query_skill("parry", 1) < level)
                return notify_fail("你对基本招架的理解还不够，无法继续"
                                   "领会更高深的不败神功。\n");

        if (me->query_skill("dodge", 1) < level)
                return notify_fail("你对基本轻功的理解还不够，无法继续"
                                   "领会更高深的不败神功。\n");

        if (me->query_skill("sword", 1) < level)
                return notify_fail("你对基本剑法的理解还不够，无法继续"
                                   "领会更高深的不败神功。\n");

        if (me->query_skill("blade", 1) < level)
                return notify_fail("你对基本刀法的理解还不够，无法继续"
                                   "领会更高深的不败神功。\n");

        if (me->query_skill("whip", 1) < level)
                return notify_fail("你对基本鞭法的理解还不够，无法继续"
                                   "领会更高深的不败神功。\n");

        if (me->query_skill("throwing", 1) < level)
                return notify_fail("你对基本暗器的理解还不够，无法继续"
                                   "领会更高深的不败神功。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("不败神功博大精深，无法简单的通过练习进步。\n");
}

int difficult_level()
{
        return 500;
}

string perform_action_file(string action)
{
        return __DIR__"never-defeated/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"never-defeated/exert/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("never-defeated",1);
        level2= (int) me->query_skill("never-defeated",1);
	jiali = me->query("jiali");
if (!me) return;
if (!victim) return;
if (!weapon) return;
if( me->is_busy() && random(3)==0) return;
//if (!level) return;
if (!level2) return;
if (!jiali) jiali=10;

if (me->query("zhuanfinal/1") ==1 && random(3)==0)
{
	if (userp(victim))
	victim->receive_wound("qi", victim->query("qi")/8);
        if (!userp(victim))
         victim->receive_wound("qi", 500);
	return RED"$N使用了斩仙决!!$n突然胸口一痛鲜血狂奔!\n"NOR;
}
else
if (me->query("zhuanfinal/2") ==1 && random(3)==0)
{
	if (userp(victim))
	victim->add("neili", -victim->query("neili")/8);
        if (!userp(victim))
         victim->add("neili", -500);
	return HIY"$N使用了破仙决!!$n突然内力消失!\n"NOR;
}
else
if (me->query("zhuanfinal/3") ==1 && random(3)==0)
{
	if (!victim->is_busy())
	victim->start_busy(4);
	return HIY"$N使用了乱仙决!!$n突然手忙脚乱!\n"NOR;
}
else

	if( random(level2)>40 
	&& random(2)==0 ) {
	victim->receive_damage("qi", (random(jiali)+150));
	victim->receive_wound("qi", (random(jiali)+150));
	return RED"只见$n$l上鲜血狂奔，已被"+weapon->name()+HIR"斩出的无形气劲切了开来!\n"NOR;
        }
}
       
       
       
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
                       string result;
       int ap, dp;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("never-defeated", 1);

        if( !weapon) return damage;
if (me->query_skill_mapped("parry") != "never-defeated") return damage;
        if( me->is_busy() && random(2)==0)  return damage;
        //if( damage < 10 )  return damage;

if (me->query("zhuanfinal/4") ==1 && random(3)==0)
{
                if (me->query("qi") < me->query("max_qi") )
                me->add("qi", me->query("max_qi") / 8);
                if (me->query("eff_qi",1) < me->query("max_qi",1) )
                me->add("eff_qi",me->query("max_qi")/8);
                if (me->query("qi") < me->query("max_qi") )

	result = HIY"$N使用了妙仙决!!$N全身的伤好了很多!\n"NOR;
}
else
if (me->query("zhuanfinal/5") ==1 && random(3)==0)
{
if (me->is_busy() )
me->start_busy(1);
if (!ob->is_busy() )
ob->start_busy(2);
	result = HIY"$N使用了动仙决!!$N突然动作又快了!\n"NOR;
}
else
if (me->query("zhuanfinal/6") ==1 && random(3)==0)
{
                if (me->query("neili") < me->query("max_neili") )
                me->add("neili", me->query("max_neili") / 8);
	result = HIY"$N使用了银仙决!!$N突然内力恢复了!\n"NOR;
}

else
 if ( random(8)==1)
        {
                damage=30;
                switch (random(4))
                {
                case 0:
                        result = HIW "$n" HIW "面含微笑，轻轻一格，已将天"
                                            "下所有进攻招数全部封死。\n" NOR;
                        break;
                case 1:
                        result = HIW "$n" HIW "眉头微微一皱，动也不动，将"
                                            "$N" HIW "震到一边。\n" NOR;
                        break;
                case 2:
                        result = HIW "$n" HIW "身形微微一抖，已将$N" HIW 
                                            "迫退至丈许开外。\n" NOR;
                        break;
                default:
                        result = HIW "$n" HIW "一声轻哼，身形微微一动，已"
                                            "飘然远去，使$N" HIW "的进攻全无用处。\n" NOR;
                        break;
                }
if (ob && me)
message_vision(result,ob,me);
            return damage;
        }
}
