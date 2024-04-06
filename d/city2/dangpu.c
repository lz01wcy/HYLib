// Room: /city2/dangpu.c

inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，
柜台上摆着一个牌子(paizi)，柜台后坐着贾老板，一双精明的眼睛上上
下下打量着你。
LONG );
	set("no_fight", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : "\n公平交易\n",
	]));
	set("objects", ([
		"/d/city2/npc/jia" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"nandaj1",
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

