// /u/beyond/mr/cl5-5.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"长廊"NOR);
         set("long", @long
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉璃
瓦，使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟、家丁
们走来走去，都忙着自己的事情。西面是长廊的延伸，北面是赏月斋。
long);
         set("exits", ([
             "east" : __DIR__"cl5-4",
             "west" : __DIR__"cl5-6",
             "north" : __DIR__"shangyuezhai",
]));
         setup();
         replace_program(ROOM);
}
