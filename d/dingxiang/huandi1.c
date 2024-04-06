inherit ROOM;

void create()
{
	set("short", "荒路");
	set("long", @LONG
这是城东的一条荒路，路旁杂乱的长着齐膝的荒草，远近荒草，远
近荒无一人。两旁干枯的老树上落满了成群的乌鸦，凄凉的鸣叫声在荒
野上远远传去，一派凄凉的景象。
LONG );
	set("exits", ([
		"southwest" : __DIR__"dongcheng",
		"northeast" : __DIR__"huandi2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "dingxiang");
	setup();
	replace_program(ROOM);
}

