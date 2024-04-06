//Cracked by Roath
// road: /zhongnan/shulin2.c

inherit ROOM;

void create()
{
        set("short","树林");

        set("long",@LONG
这位於终南山间的一大片树林，生的颇为茂密。走在其间，只听得脚
下沙沙的落叶声，四周昏昏暗暗的，不时几道日光穿过浓密的枝头，投射
而下。偶而远处几声兽吼声，更添了一份神密感。往西北和往东各有一条
小径。
LONG);

        set("exits",([ 
        "south" : __DIR__"shulin3",
        "north" : __DIR__"shulin1",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

}

#include "caiyao.h"

