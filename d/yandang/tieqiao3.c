// Room: /d/yandang/tieqiao3.c

inherit ROOM;

void create()
{
	set("short", "铁索桥");
	set("long", @LONG
这是一座宽仅两尺的铁索桥,由十三根铁索组成,上面摆了一块块
景,由于风吹日晒,年代久远,有的地方已经破缺,桥下就是万丈深谷,
据说常有人调下去.你已经走了一半了,看着脚下不断摇晃的铁索,你害
怕极了,还是返回吧.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tieqiao4",
  "south" : __DIR__"tieqiao2",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
