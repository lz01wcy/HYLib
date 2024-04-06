// room: dong-2.c
// zqb


inherit ROOM;
#include <ansi.h>
string look_bei();
void create()
{
        set("short", HIR"天然洞穴"NOR);
        set("long", @LONG
    这石洞系天然生成，较之外面人工开凿的石室大了十来倍。放眼望
去，洞内共有十余具骸骨，或做或卧，神态各有不同，有的骸骨散开在地，
有的却仍具完好人形，更有些骨坛灵位之属。每具骸骨之旁都放着兵刃，暗
器，用具，珍宝等物。洞口处立着一座石碑(bei)。
LONG
        );
        set("exits", ([
            "out" : __DIR__"dong-3",
        ]));
        set("item_desc",([
        "bei"         :       (: look_bei :),
    ]));

        set("objects", ([
           
        __DIR__"obj/haigu" : 1,  
        __DIR__"obj/ycj" : 1,      
        ]));

        set("no_clean_up", 0);

        setup();
        //replace_program(ROOM);
}
string look_bei()
{
        return
        "\n"
"       擅动室内物品者\n"    
        "\n"
RED"        死伤莫怪！    \n"NOR
        "\n";
}
void init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
      object me;
      me=this_player();

      if ((int)me->query_temp("marks/baowu")) 
      {
      if ((int)me->query_str() < 30)
          return notify_fail("你的力量不够，无法将石碑推开。\n");
      if (arg !="bei") 
          return notify_fail("你要推什么？？\n");
      write("你扎下马步，深深的吸了口气，将石碑缓缓的向旁推开。\n");
      message("vision",me->name() + "双膀用力，气沉丹田，石碑缓缓向后移开，下面露出一个黑洞洞的入口。\n", environment(me),({me}));
      set("exits/enter", __DIR__"taijie-1");
      remove_call_out("close_passage");
      call_out("close_passage", 5);
      return 1;
      }
      return notify_fail("找死啊！\n");
}


void close_passage()
{
      object room;

      if( !query("exits/enter") ) return;
      message("vision", "石碑发出隆隆的声音，缓缓移回原处。\n", this_object() );
      delete("exits/enter");
}


