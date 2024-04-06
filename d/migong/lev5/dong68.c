#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", BLU"山洞入口"NOR);
	set("long", BLU @LONG
 你越走越深，周围的墙壁似乎有些松软了。 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong67",
		"south" : __DIR__"dong6",
                	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong6",
		"west" : __DIR__"dong67",
                "down" : "/d/migong/lev6/dong04",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
