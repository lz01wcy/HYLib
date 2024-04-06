// by mayue

inherit ROOM;

void create()
{
        set("short", "松树林");
	set("long", @LONG
这里是一片浓密的松树林，前面已经没有了道路，你必须不时砍断
横在你面前的枝桠。林内光线黑暗，静的能听到你自己的心跳声 ，只有
你踩在地上厚厚的松针和枯枝上发出的沙沙声。前面依稀透着一点光亮，
你不由长长的吁了一口气。
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
 //               "east" : __DIR__"sl3",
                "west" : __DIR__"sl2",
                "north" : __DIR__"pubu",
                "south" : __DIR__"sl5",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

