// Room: zizhulin
// congw 980829
inherit ROOM;

void create()
{
	set("short", "紫竹林");
	set("long", @LONG
你来到一片翠绿的包围之中，仿似迷失了方向。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
	"southdown" : __DIR__"zizhulin3",
	"northup" : __DIR__"zizhulin",
	"southup" : __DIR__"zizhulin2",
	"northdown" : __DIR__"zizhulin3",
]));
	setup();
	replace_program(ROOM);
}

