 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "白杨树林");
        set("long", @LONG
无边无际的荒原上一排傲然地立，象哨兵似的淠荆不很浓密，是西北最常
见的白杨树林。P直的乾，P直的枝。乾通常是丈把高，象是加以人工似的，一丈
以龋^o旁枝；丫枝一律向上，而且oo靠n，也象是加以人工似的，成橐皇，
^oM斜逸出。
LONG
        );
        set("exits", ([ 
                "northeast" : __DIR__"wild2",
                "west" : __DIR__"woods2",
                "southeast":    __DIR__"forest1",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
