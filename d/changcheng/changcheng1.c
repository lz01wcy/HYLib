// Room: /d/wizhome/incahome/changcheng1.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT "长城");
        set("long", WHT@LONG
这里就是举世闻名的--长城。站在长城上你可以看到四周群山环绕，山上
到处都是矮矮的灌木丛，你举目望去你脚下的长城顺着山顶象一条巨龙般蜿蜒
的向北延伸出去。
LONG
NOR        );

        set("outdoors", "changcheng");

        set("exits", ([
                "west" :__DIR__"changcheng2.c",
                "east" :__DIR__"juyguan.c",
        ]));

        setup();
        replace_program(ROOM);
}
