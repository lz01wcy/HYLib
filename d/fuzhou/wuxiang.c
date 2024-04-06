// Room: /d/fuzhou/wuxiang.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "无相庵");
	set("long", @LONG
一个小小庵堂。
LONG );
	set("exits", ([
                "south" : __DIR__"shulin",
	]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

