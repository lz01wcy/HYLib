#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"原始森林"NOR);
	set("long", GRN @LONG
这是一个黑漆漆石洞，周围都是坚硬的石壁,左面有阶梯
似乎可以一直往下去。 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong99",
		"south" : __DIR__"dong10",
                "out" : "/d/pingan/nan3"
                	]));
	set("no_npc",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
