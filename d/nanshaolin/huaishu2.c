// Room: /d/nanshaolin/huaishu2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "槐树林");
	set("long", @LONG
眼前一暗你走进一片槐树林，枝头鸟语轻鸣，荫下清风荡漾。好一
个清净禅修之所在。林中一 条小径曲折伸向前方。
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"west"      : __DIR__ "huaishu1",
		"north"     : __DIR__"huaishu4",
		"southeast" : __DIR__ "celang1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

