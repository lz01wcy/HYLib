// Room: /d/yandang/shulin.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
路边的一片杂树林,无数的藤蔓绕着树木,密密地把林子遮了起来,地
上浓密的杂草提醒你,可能有危险.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"to_yandang2",
  "north" : __DIR__"river",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
