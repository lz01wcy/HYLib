// Room: /d/jindezheng/songlin
#include <ansi.h>
inherit ROOM;
int i=0;
void create ()
{
  set ("short", "松林");
  set ("long", @LONG
一片好大的松林,有几个工人正有条不紊地伐木,又锯成相同大小的 
木料,一段段的堆成了一座小山,这里的松木是砖窑的主要燃料. 
LONG);

  set("outdoors", "jindezheng");
	set("no_clean_up", 1);
	set("no_sleep", 1);
	set("no_dazuo", 1);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zuanjiao",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/obj/axe.c" : 2,
  __DIR__"npc/famugong.c" : 1,
]));

  setup();
}
void init()
{  
   add_action("do_kan","kan");
}
int do_kan(string str)
{ 
      object me,ob;
      me=this_player();
    if ((!str)||(str!="wood")) return notify_fail("你要砍什么?\n");
    if (!(ob=me->query_temp("weapon"))||(string)ob->query("id")!= "famuaxe")
         return notify_fail("还是先去找把砍木斧子吧!\n");
if( me->query("qi") < 20)
return notify_fail("你干不动活了!\n");
if( me->query("jing") < 20)
return notify_fail("你干不动活了!\n");

//   if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("id")!= "famuaxe")
//	return notify_fail("你只能用专门的砍木头的斧子！\n");

    if (me->query_temp("work/kan")==1)
      {   
          message_vision("$N抡起大斧砍起树来!\n",me);
          i=++i;
          if (i<8)
           {
                 me->receive_damage("qi",(int)me->query("max_qi")*10/100);
                 me->receive_damage("jing",(int)me->query("max_jing")*2/100);
                 return 1;
           }
          me->set_temp("work/kan",2);
          me->start_busy(random(6));
          message_vision("$N看着堆得高高的松柴，吁出一口长气，终于干完了!\n",me);
          i=0;
            return 1;
       }
     if (me->query_temp("work/kan")==2) return notify_fail("你刚把活干完，还是先去领工钱吧!\n");
     return notify_fail("你觉得还是应该先向监工打个招呼!\n");
}
int valid_leave(object me, string dir)
{   object ob;
       ob=present("famuaxe",me);   
    if (dir=="east"&&ob)
            {   message_vision(HIR+"$N丢下一把大斧头，转身走出了松林!\n"+NOR,me);
                ob->move(environment(me));
                i=0;
                 return 1;
            }
	  return ::valid_leave(me, dir);
}

    