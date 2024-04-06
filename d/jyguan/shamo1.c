// shamo1.c 沙漠
// shamo can to shaqiu
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIY "沙漠");
	set("long", HIY @LONG
这里四面是茫茫沙海，沙丘起伏，到处都是同样的景色，很容易迷失方向。
你很快就会干渴难耐。
LONG
NOR	);	
        set("outdoors", "jyguan");


	set("exits", ([
		"west" : __DIR__"shamo",
		"east" : __DIR__"shamo",
                "south" : __DIR__"shamo",
                "north" : __DIR__"shamo",
                "northwest" : __DIR__"shamo",
                "northeast" : __DIR__"shamo",
                "southwest" : __DIR__"shaqiu",
                "southeast" : __DIR__"shamo",
	]));
	
		
	setup();
	replace_program(ROOM);
}

