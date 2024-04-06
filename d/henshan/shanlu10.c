// Room: /d/henshan/shanlu10.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭
绕，不觉心胸大快。山路向西通向方广寺。东面是天柱峰。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "eastup"    : __DIR__"tianzhu",
           "westdown"  : __DIR__"fangguangsi",
        ]));
		set("objects", ([

"quest/skills2/wakuang/kuang/kuangmai" : 1,
	])); 
	set("wayao1", 1);
        set("outdoors", "henshan");
	set("coor/x", -360);
	set("coor/y", -1050);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
