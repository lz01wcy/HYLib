// Room: /u/wsl/changan/boshulin5.c
// This is a room made by Wsl.

inherit ROOM;

void create()
{
	set("short", "柏树林");
	set("long", @LONG
这里是一片枝繁叶茂的柏树林，花草长得便地都是，看着这原始
的密林，你似乎迷失了方向。
LONG
);
	set("exits", ([ /* sizeof() == 8 */
  "southwest" : __DIR__"boshulin5",
  "south" : __DIR__"boshulin5",
  "east" : __DIR__"boshulin6",
  "southeast" : __DIR__"boshulin5",
  "west" : __DIR__"boshulin5",
  "northwest" : __DIR__"boshulin5",
  "north" : __DIR__"boshulin4",
  "northeast" : __DIR__"boshulin5",
]));

	setup();
	replace_program(ROOM);
}
