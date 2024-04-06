// Room: /d/quanzhou/zahuopu.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "尚武书店");
	set("long", @LONG
这里是一家专卖各种关于武功书的书店，听说店主是个好武的人。
LONG );
	set("exits", ([
		"north" : __DIR__"dong2",
	]));
	set("objects", ([
		__DIR__"npc/shopman2" : 1,
	]) );
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

