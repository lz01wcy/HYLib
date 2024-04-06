// Room: /jingzhou/lckumen.c
// congw  890830
inherit ROOM;

void create()
{
	set("short", "粮仓大门");
	set("long", @LONG
你正站在荆州粮仓的门口，可以看到两个穿着制服的官兵正在巡逻，不时地传来呐
喊声。老百姓是不允许在此观看的，你最好赶快走开。
LONG
	);

	set("exits", ([
		"west" : __DIR__"nandajie2",
		"east" : __DIR__"liangcang",
	]));

	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("官兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}

