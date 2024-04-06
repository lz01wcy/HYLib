// by mayue

inherit ROOM;

void create()
{
        set("short", "松树林");
	set("long", @LONG
这里是一片浓密的松树林，前面已经没有了道路，你必须不时砍断
横在你面前的枝桠。不远处一株千年的古松直插云霄，它下面纵横交错
的树根似乎在向人诉说它悠久的岁月。林内光线黑暗，静的能听到你自
己的心跳声 ，只有你踩在地上厚厚的松针和枯枝上发出的沙沙声。前面
依稀透着一丝光亮，你不由高兴的紧走几步。
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
                "north" : __DIR__"sl5",
 //               "southwest" : __DIR__"sl4",
                "west" : __DIR__"sl7",
 //               "southeast" : __DIR__"sl5",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

