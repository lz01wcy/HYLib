//ROOM qiushi.c

inherit ROOM;
void create()
{
        set("short", "囚室");
        set("long",@LONG
这是『灵鹫宫』关押犯人的地方，屋中光线昏暗，气味难闻。屋角隐
隐约约有个人影。
LONG );
        set("exits", ([
		"east" : __DIR__"men1",
        ]));
	set("objects",([
		__DIR__"npc/wulaoda" : 1,
	]));
//	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
