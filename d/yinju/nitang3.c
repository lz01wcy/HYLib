inherit ROOM;

void create()
{
  set("short","泥潭");
  set("long",@LONG
你置身泥潭中，四周静悄悄的四处散发着腐败的气味，
赶紧早找出路，离开泥潭为好。
LONG);
  set("outdoors","yinju");
set("exits",([
   "south" : __FILE__,
    "north" : __FILE__,
  "west"  : __DIR__"nitang2",
  "east"  : __DIR__"shenglin",
   ]));
  
  setup();
}
