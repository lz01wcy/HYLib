#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", BLU"山洞"NOR);
	set("long", BLU @LONG
 你越走越深，周围的墙壁似乎有些松软了。 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong03",
		"south" : __DIR__"dong60",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
