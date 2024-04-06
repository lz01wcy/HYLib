#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "庄府大厅");
    set("long", @LONG
这是一间灵堂。堂上供了七八个牌位.看来一座灵堂上供的
是一家死人.一阵阴风吹过,蜡烛突然灭了.
LONG );
    set("exits", ([
		"east" : "/d/city2/zhuang5",
    ]));
    set("objects", ([
		"/d/city2/npc/dizi": 1,
    ]));
//    set("no_clean_up", 0);
    set("outdoors", "city2");
    setup();
    replace_program(ROOM); 
}


