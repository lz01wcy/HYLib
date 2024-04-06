#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "院子");
        set("long", @LONG
这里堆放着上百堆的石头。这些石头有大有小，大如一间房屋，小如
一个鸭蛋，形状大多都呈圆球形。你发现从有些石头之间的缝隙(fengxi)
中飘出一股股的腥臭味，使你快要做呕了。
LONG);
        set("exits", ([
              "southeast" : __DIR__"yuanzi1",
              "northwest" : __DIR__"yuanzi4",
              "northeast" : __DIR__"yuanzi3",
        ]));
         set("item_desc", ([                    
                "fengxi": "\n缝隙里面漆黑一片，隐隐约约有沙沙的声响。\n",
        ]));
        set("outdoors", "白陀山");
        setup(); 
}

void init()
{
      	object me = this_player();
      	if(me->query_skill("poison", 1) < 50)
      		me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");      
}

int do_enter(string arg)
{
        object me = this_player();
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("你正忙着呢。\n");
        	
        if (arg == "fengxi" ){   
               message_vision("$N刨开缝隙口的乱石子，一弯腰往缝隙里钻了进去。\n",me);
               me->move(__DIR__"fengxi");
               message("vision",me->name() + "从外面钻了进来。\n",environment(me), ({me}) );
               return 1;
        }     
}