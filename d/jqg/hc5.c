// Room: /u/dubei/u/gumu/jqg/hc5
// by dubei

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "花丛");
	set("long", @LONG
这里是一片花丛，你感到已经很难辨清道路了。
LONG
	);

	set("exits", ([
		"south" : __DIR__"hc6",
		"east" : __DIR__"hc"+(random(10)+1),
		"north" : __DIR__"hc"+(random(10)+1),
		"west" : __DIR__"hc"+(random(10)+1),
		"northeast" : __DIR__"hc4",
                "southwest" : __DIR__"hc"+(random(10)+1),
	]));

      set("outdoors", "襄阳");
        replace_program(ROOM);

	setup();

}
 
