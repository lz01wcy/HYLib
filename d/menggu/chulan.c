// Room: /d/menggu/chulan.c

inherit ROOM;

void create()
{
	set("short", "牲畜栏");
	set("long", @LONG
畜栏精心分成几格,分别圈了几头牛羊,一边的木桩上,还系了三匹马,
圈栏中不时响起牛羊的叫声,间或骏马长嘶.一边是间很破烂的小茅草屋.
门口,畜栏中都打扫得很干净.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"byriver",
]));
	set("outdoors", "menggu");

	setup();
	replace_program(ROOM);
}
