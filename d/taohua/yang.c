// Room: /u/jpei/thd/yang.c

#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "阳");
	set("long", @LONG
这里是两仪层的阳。阳是太极的一端，古人以光明为阳，以生命为阳，又
以地理而认为南方属阳，山之南水之北为阳。
LONG
	);
	set("exits", ([ 
		"northeast" : __DIR__"liangyi",
	]) );

	set("no_clean_up", 0);
	setup();
}

void init()
{
	mixed *local;
	object me = this_player();

	add_action("do_save", "save");
	add_action("do_quit", "quit");
	if (!me->query_temp("liangyi")) {
		local = localtime(time() * 60);
		if (local[LT_MDAY] > 15)
			me->set_temp("liangyi", 1);
		else
			me->set_temp("liangyi", -1);
	}
}

int do_save()
{
	write("这里不准存盘！\n");
	return 1;
}

int do_quit()
{
	write("这里不准退出！\n");
	return 1;
}

