//huilang.c 回廊

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIC"走廊"NOR);
        set("long", @LONG
这是一条幽静的回廊，两边种满了花卉，还有些药材，显得非常的幽静，
向前是长长的青石路，小路一端的尽头似乎有一道小圆门，路两侧是几间房
子。
LONG
        );
        set("exits", ([
        "south" : __DIR__"zhongting",
        "southwest" : __DIR__"caodi3",
        "southeast" : __DIR__"caodi4",
        "north" : __DIR__"houting",

        ]));
        
        set("no_death",1);set("bwdhpk",1);

        setup();
}

