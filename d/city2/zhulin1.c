
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "竹林小道");
	set("long", @LONG
四周都是密密的竹林，一踏进这里你就迷了路。这里人迹罕至，
惟闻足踏草坪之声。偶尔有微风轻拂竹叶，又如簌簌禅唱，令人尘
心为之一涤，真是绝佳的清修所在。
LONG );
	set("exits", ([
		"northeast" : __FILE__,
		"southwest" :  __DIR__"chaoyang",
		"east" : __FILE__,
		"west" : __FILE__,
		"south" :__FILE__,
		"north" : __DIR__"zhulin2",
	]));
	set("outdoors", "city2");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}



