inherit ROOM;

void create()
{
	set("short", "地安门西大街");
	set("long", @LONG
这是一条东西走向的大道。东边通往地安门。西边通往西四。
不知道为什么，这里总是冷冷清清，见不到几个行人。
LONG );
        set("outdoors", "city2");
	set("exits", ([
		"east" : __DIR__"di_anmen",
		"west" : __DIR__"di_an4",
	]));
	set("objects", ([
		"/d/city/npc/liumangtou" : 1,
		"/d/city/npc/liumang" :  2,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


