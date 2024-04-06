// by mayue

inherit ROOM;
string* npcs = ({
	__DIR__"npc/qiandu1",
	__DIR__"npc/qiandu2",
	__DIR__"npc/qiandu3",
	__DIR__"npc/qiandu4",
	__DIR__"npc/qiandu5",

});

void create()
{
	set("short", "千毒窟");
	set("long", @LONG
这里是一个天然形成的石洞，里面深邃广大。洞顶悬挂着许多
钟乳石，不时传来几声滴答的水声。走在洞中，洞内阴暗潮湿，身
旁忽然传来一阵“咝咝”的声音。
LONG
	);
//        set("outdoors", "wudujiao");

	set("exits", ([
//		"eastup" : __DIR__"wdsl5",
              "south" : __DIR__"qiandu1",
//		"westdown" : __DIR__"wdsl3",
//		"north" : __DIR__"baidu1",
	]));
        set("objects", ([
	        npcs[random(sizeof(npcs))] : 1,
	        npcs[random(sizeof(npcs))] : 1,
	]));
    

	setup();
	replace_program(ROOM);
}

