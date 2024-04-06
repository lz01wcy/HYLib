//ROOM men1.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "书房大门");
        set("long",@LONG
这是书房门口，只看见大门两旁贴着一副对联(duilian)，抬头上望。
门楣上一块大匾(bian)上写着几个大字。
LONG );
        set("outdoors", "lingjiu");
        set("exits", ([
		"east" : __DIR__"shufang",
		"west" : __DIR__"changl12",
        ]));
	set("objects",([
		__DIR__"npc/zhujian" : 1,
	]));
	set("item_desc", ([
	    "duilian" : "行到水穷处，坐看云起时.\n",
	    "bian" : HIC "任我逍遥\n" NOR,
        ]));
//        set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (  (dir == "east")
	   && ((string)me->query("family/family_name") != "灵鹫宫")
	   && objectp(present("zhu jian", environment(me))) )
	 return notify_fail
		("竹剑伸手拦住你，说道：“对不起，本门重地，请回！”\n");
	return ::valid_leave(me, dir);
}
