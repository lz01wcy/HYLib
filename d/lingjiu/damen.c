//ROOM damen.c

inherit ROOM;

void create()
{
	set("short", "独尊厅大门");
        set("long",@LONG
这就是通向『灵鹫宫』独尊厅的大门。大门左右各有一头石雕的猛鹫
，高达三丈有余，尖喙巨爪，神骏非凡，栩栩如生，似乎随时要腾空而去。
LONG );
        set("outdoors", "lingjiu");
        set("exits", ([
		"north" : __DIR__"dating",
		"south" : __DIR__"dadao2",
        ]));
	set("objects",([
		CLASS_D("lingjiu") + "/meijian" : 1,
		CLASS_D("lingjiu") + "/zhoupopo" : 1,
		CLASS_D("lingjiu") + "/qiupopo" : 1,		
		__DIR__"npc/lanjian" : 1,
	]));
//        set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (  (dir == "north")
           && ((string)me->query("family/family_name") != "灵鹫宫")
	   && ( objectp(present("mei jian", environment(me)))
	   ||   objectp(present("lan jian", environment(me))) ) )
        return notify_fail
		("梅兰双姝伸手拦住你，说道：“非灵鹫宫弟子请回！”\n");
	return ::valid_leave(me, dir);
}
