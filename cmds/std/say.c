// say.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
if (me->query("combat_exp") < 2000 )
{
        if ( ((int)time() - (int)me->query_temp("say_time")) < 1 )
        return notify_fail("有话好好说哦。只有经验大于2000,才能无限制使用\n");
if ( strlen(arg)>40)
return notify_fail("你说那么多话做什么! 想刷屏?只有经验大于2000,才能无限制使用\n");

}
	if (!arg) {
		write("你自言自语不知道在说些什么。\n");
		message("sound", me->name() + "自言自语不知道在说些什么。\n",
			environment(me), me);
		return 1;
	}
	if( (int)me->query("qi") < (int)me->query("max_qi") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}
                     me->set_temp("say_time", time());
	write( CYN "你说道：" + arg + "\n" NOR);
	message("sound", CYN + me->name() + "说道：" +  arg + "\n" NOR,
		environment(me), me);

	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: say <讯息>
 
说话，所有跟你在同一个房间的人都会听到你说的话。
 
注: 本指令可用 ' 取代.
 
HELP
	);
	return 1;
}
