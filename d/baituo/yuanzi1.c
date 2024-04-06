#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "院子");
        set("long", @LONG
这个院子里虽只有几颗小树，却堆放着上百堆的石头。这些石头有大
有小，大如一间房屋，小如一个鸭蛋。你发现旁边矮墙下有一条深沟，下
面水花盈盈看不清有什么东西。身后有道铁门(tiemen)，不过已经关上了。
一股股的腥臭味飘来，使你快要做呕了。
LONG);
        set("exits", ([
              "northwest" : __DIR__"yuanzi2",
              "jumpdown" : __DIR__"shetan",
        ]));
        set("outdoors", "白陀山");
        setup(); 
}

void init()
{
     	object me = this_player();
      	if(me->query_skill("poison", 1) < 50)
      		me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
        add_action("do_fan", "fan");
        add_action("do_fan", "pa");
        add_action("do_fan", "climb");
        add_action("do_push", "push");
        add_action("do_push", "tui");
        add_action("do_push", "strike");                  
}

int do_fan(string arg)
{
        int dex;
        object me = this_player();

        dex = me->query_dex();

        if (me->is_busy() || me->is_fighting() )
        	return notify_fail("你正忙着呢。\n");
        	
       	if (dex < 18 )
        	return notify_fail("这矮墙虽矮，你却怎么也翻不过去。\n");
       	if (dex > 17 ){  
           	message_vision("$N双手在矮墙上一按，一翻身便纵了过去。\n", me);
           	me->move(__DIR__"yuanzi");
           	message("vision", me->name() + "从院子里面翻了过来。\n",environment(me), ({me}) );
           	return 1;
           	}     
}

int do_push(string arg)
{
        int str;
        object me = this_player();
        str = me->query_str();

       	if( !arg ) return 0;
       	if (arg == "tiemen" ){        
       		if( (int)me->query_skill("hamagong", 1)){
           		message_vision("$N蹲下身子，双掌平伸推向铁门。\n", me);
           		message_vision("铁门突然打开，$N一没留神滚了进去。铁门却又合上了。\n", me);
//           		me->receive_damage("neili", 100);
           		me->receive_damage("jing", 50);
           		me->move(__DIR__"yuanzi");
           		message("vision", "只听啪的一声，一个人影从铁门出滚了过来！\n",environment(me), ({me}));
           		}
       		if (str < 21 )
               		return notify_fail("你使出了吃奶的力气，可就是推不动这铁门。\n");
      		else {  	
           		message_vision("$N使出全身力气推向铁门，可铁门却纹丝不动。\n", me);
//			me->receive_damage("neili", 300);
           		me->receive_damage("jing", 150);
           		}       
       		}
       return 1;        
}