#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", YEL"岩洞"NOR);
	set("long", YEL @LONG
    周围都是黄褐色的岩石，感觉上已经在地下很深的地方了。 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong99",
		"south" : __DIR__"dong10",
                "east" : __DIR__"dong101",
                	]));
set("objects", ([
             "/d/migong/obj/npc1" : random(2),             
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
