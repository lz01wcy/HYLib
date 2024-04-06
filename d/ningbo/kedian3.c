// /u/beyond/ningbo/kedian3.c
// Beyond make 1997.6.8
inherit ROOM;

void create()
{
	set("short", "客店二楼");
	set("long", @LONG
这是一间很大的客房，陈设十分简陋。靠墙放了十几张小木床，不少客
人正和衣而卧，满屋子都是呼呼的打酣声。西边有张床是空的，你蹑手蹑脚
地走了过去。
LONG
	);

	set("sleep_room", "1");
	set("no_fight", "1");

	set("exits", ([
		"out" : __DIR__"kedian2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}

