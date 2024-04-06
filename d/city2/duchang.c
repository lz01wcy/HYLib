// Room: /city2/duchang.c

inherit ROOM;
string* npcs = ({
        "/d/city2/npc/wuliuqi",
});

void create()
{
	int i = random(sizeof(npcs));
	set("short", "赌场");
	set("long", @LONG
这里是赌场的大堂，四周的房间里传出来吆五喝六的赌博声。
北边是赌「大小」的房间，墙上挂着一块牌子(paizi)。楼上可以
拱猪. 一进门，只见房中人声嘈杂，十分混乱。有一桌围着一群人，
其中一胖一瘦两个头陀十分惹眼。一个老叫化正和他们赌得起劲。
LONG );

	set("item_desc", ([
		"paizi" : "二楼的拱猪房可以使用，为什么没人来呢?\n",
	]));
	set("exits", ([
//                "north" : "/d/city2/daxiao",
                "up" : __DIR__"duchang2",
		"west" : __DIR__"xidan1",
	]));
	set("no_clean_up", 0);
	set("objects", ([
        	CLASS_D("shenlong")+"/shou": 1,
		npcs[i] : 1,
 	]));
	setup();
}

int valid_leave(object me, string dir)
{
    int i;
   if(dir=="north")
   if(this_player()->query("weiwang")<50) 
   if(objectp(present("wu", environment(me)))&&living(present("wu", environment(me))))
   return notify_fail("\n吴六奇拦住你说道：对不起，非本帮弟子不得自由出入。\n");	
   return ::valid_leave(me, dir);
}        
