 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","舜耕山庄");
  set("long",@LONG
这便是赫赫有名的舜耕山庄，舜耕山又称历山，传说是舜―虞重华的出身地。
是真是假已不得而知，但这里的房子确实千金难求。能在此有一处房产是许多人
一生的梦。而丐帮褴褛衣衫之下，其实是富甲天下。
LONG
  );
  set("exits",([
         "east":__DIR__"street2",
                 "north":__DIR__"private",
               ]));

        set("valid_startroom", 1);
        set("coor/x",10);
        set("coor/y",1950);
        set("coor/z",0);
        setup();
        create_door("north", "紫雕门", "south", DOOR_CLOSED);
}
int valid_leave(object me, string dir)
{
        object ob;
        if( dir == "north" && ob=present("master nangong", this_object()))
                return notify_fail("这个方向的路被"+ob->name()+"挡住了 。\n");
        if( dir == "north" && !query("exits/north"))
                return notify_fail("你必须先把紫雕门打开！\n");
        return 1;
}      
