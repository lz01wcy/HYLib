// Room: d/kyoto/longandao3.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "龙安道");
set("long", @LONG
这是龙安道，是京都城北的交通要冲，人来人往好不繁华，此地因
龙安寺而得名。
LONG );
set("exits",  ([
        "north"  : __DIR__"longandao2",
        "south"  : __DIR__"heyuan1",
      ]));
        setup();
        replace_program(ROOM);
}