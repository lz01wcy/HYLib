
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","青石官道");
  set ("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆
匆而过。大道两旁有一些小货摊，似乎是一处集市。往西面就是南昌城
了。你已看到一片春绿色，那里正是南昌方向。
LONG);

  set("exits", ([ 
  "west":__DIR__"dongmen",
  "east":__DIR__"guandao2",
        ]));
 
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

