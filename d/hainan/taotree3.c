// Room: /d/hainan/taotree3
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "桃花林");
  set ("long", @LONG
一片绚烂的桃花林,正中有一个大理石砌成的水池,四边是绿茵草地, 
白色的蒸汽从水池中冒出来,把这地方弄得蒙蒙胧胧,看来是[31m温泉[37m了,在白 
雾中,似乎有几个窈窕身影. 
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "温泉" : "蒙蒙的雾气笼罩着温泉水池,看来洗个澡是个好主意!
想着,你都快忍不住要跳下去了(jump down)!
",
]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ziyun.c" : 1,
]));
  set("outdoors", "/d/hainan");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"outtree2",
  "south" : __DIR__"taotree1",
]));

  setup();
}
void init()
{
    add_action("do_jump", "jump");
}

int do_jump(string sss)
{object ob;
 ob=this_player();
  if (sss!="down") return 0;
  message_vision("$N飞快地脱掉衣服,噗通一声跳下了"+RED+"温泉!\n"+NOR,ob);
  tell_room("/d/hainan/wenquan.c",ob->query("name")+"跳了下来,溅起一片水花!\n");
  ob->move("/d/hainan/wenquan.c");
return 1;
}
