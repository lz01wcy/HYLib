// muwu2.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "小木屋");
        set("long", @LONG
这是一间不是很大的木头屋子，这里看起来象个药室，室中摆放着各种
不同的配药的用具和一些已经配好了的药。
LONG );
	set("exits", ([
		"south" : __DIR__"xiaodao3",
	]));
	set("objects", ([
		__DIR__"npc/xuemuh" : 1,
//		__DIR__"npc/yaotong": 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
