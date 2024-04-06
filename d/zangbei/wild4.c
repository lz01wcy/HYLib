 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "草原");
        set("long", @LONG
西部草原，辽阔而静寂。望山跑死马。朝着一片缓缓起伏的绿色平坡走，许久，
它仍然在天边诱人地等待。上了高处，前面又是伸向白云处的草原。远处的雪峰倒
映在蓝天白云下，近处，一排排高大的白杨树，象哨兵似傲然地立，连绵数十里。
LONG
        );
        set("long_night",@LONG
草原的夜是寂寞的，辽远清冷的高空，挂起无数的星点，在下面，夜行人的灯
笼摇摇摆摆，象是沼地中的鬼火跳舞，在道路两旁，全是黑沉沉的红杉树林，在前
面，无边的草原在风中瑟瑟作响，呜咽似地呻吟，令赶路的人毛骨悚然。
LONG
        );
        	set("objects", ([
"quest/skills2/wunon/non/nontian" : 2,
	])); 
        set("exits", ([ 
                "east" : __DIR__"wild3",
                "west" : __DIR__"wild5",
 //屏蔽树林
                "south" : __DIR__"woods1",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbian");
        set("coor/x",-1060);
        set("coor/y",160);
        set("coor/z",0);
        setup();
        
}  
