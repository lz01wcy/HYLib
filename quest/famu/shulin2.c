// Room: /d/jindezheng/shulin2.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
一片杂树林,地上铺了厚厚一层落叶.有一条小径隐约穿过树林,前 
方似乎还升起一缕青烟. 
LONG
	);
	set("no_sleep", 1);
	set("no_dazuo", 1);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/songque.c" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zuanjiao",
  "north" : "d/city/jiaowai4",
//  "southwest" : __DIR__"x",
]));
	set("outdoors", "jindezheng");

	setup();
	replace_program(ROOM);
}
