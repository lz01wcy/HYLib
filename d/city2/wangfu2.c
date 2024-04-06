

inherit ROOM;

void create()
{
	set("short", "王府井大街");
	set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。南边北边都是长长的
街道，西边是著名的‘全聚德’酒楼，东边通往朝阳门。
LONG );
        set("outdoors", "city2");
//	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"jiulou1",
		"south" : __DIR__"wangfu1",
		"east" : __DIR__"chaoyan1",
		"north" : __DIR__"wangfu3",
	]));
	set("objects", ([
		"/d/city2/npc/flowerg": 2,
	]));
	setup();
	replace_program(ROOM);
}

