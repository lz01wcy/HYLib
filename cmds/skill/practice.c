// practice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object where = environment(me);
	string skillname;
	int skill, skill_basic, times, pertimes;

	seteuid(getuid());

        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

	if( (int)me->query("qi") < 50 )
		return notify_fail("你没有那么多的气!\n");

	if( (int)me->query("jing") < 50 )
		return notify_fail("你现在精不够!\n");

        if (where->query("sleep_room"))
                return notify_fail("卧室不能练功，会影响别人休息。\n");

       if( environment(me)->query("no_beg") &&
       environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n不要影响别人，还是找一个别的地方吧。\n"NOR);

	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

//       if( environment(me)->query("outdoors") ) 
//          return notify_fail(HIY"\n不要影响别人，还是找一个室内的地方吧。\n"NOR);

	if( !arg ) return (__DIR__"enable")->main(me, arg);

	if ( (sscanf(arg, "%s %d", arg, times)!=2 ))
		return notify_fail("指令格式：practice|lian <技能种类> <次数>\n");

	if ( times < 1 || times > 30)
		return notify_fail("练习次数必须大于一次，但不能超过三十次。\n");

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("你只能练习用 enable 指定的特殊技能。\n");


	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);
	if( skill < 1 )
		return notify_fail("你好像还没有学过这项技能吧？最好先去请教别人。\n");
	if( skill_basic < 1 )
		return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");
	if( skill_basic/2 <= skill/3 )
		return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

	notify_fail("你现在不能练习这项技能。\n");

	if (skill*skill*skill/10 > (int)me->query("combat_exp")) 
//	{
		return notify_fail("也许是缺乏实战经验，你的练习总没法进步。\n");
//		return 1;
//	}

	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

	notify_fail("你试着练习" + to_chinese(skillname) + "，但是并没有任何进步。\n");

	write( HIC "你试着把" + to_chinese(skillname) + "练了"+chinese_number(times)+"趟。\n" NOR);
	if (skill*skill*skill/10 > (int)me->query("combat_exp")) 
	{
                me->start_busy(1);
		return notify_fail("也许是缺乏实战经验，你的练习总没法进步。\n");
		return 1;
	}

	for (pertimes = 1; pertimes <= times; pertimes ++)
	{
		if( SKILL_D(skillname)->practice_skill(me) )
			me->improve_skill(skillname, (skill_basic/5 +1), skill_basic > skill? 0: 1);
		else return 0;
	}
	write( HIY "你的" + to_chinese(skillname) + "进步了！\n" NOR);
	return 1;
}

int help(object me)
{
	write(@TEXT
指令格式：practice|lian <技能种类> <次数>

这个指令让你练习某个种类的技能，这个技能必须是经过 enable 的专业技能。

如果你对这方面的基本技能够高，可以经由练习直接升级，而且升级的上限只跟
你基本技能的等级有关，换句话说，勤加练习是使你的所学「青出于蓝胜于蓝」
的唯一途径，当然，在这之前你必须从实际运用中获得足够的经验以提升你的基
本技能。
TEXT
	);
	return 1;
}
