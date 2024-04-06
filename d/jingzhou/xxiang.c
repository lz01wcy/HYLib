// Room: /jingzhou/xxiang.c
// congw 98/08/30

inherit ROOM;

void create()
{
	set("short", "小巷");
	set("long", @LONG
这是一条又深又黑的巷子，散发出一阵阵污水的味道和食物发霉的味道，
又脏又臭。

LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"south" : __DIR__"xxend",
		"north" : __DIR__"dongdajie2",
	]));

	setup();
	replace_program(ROOM);
}

