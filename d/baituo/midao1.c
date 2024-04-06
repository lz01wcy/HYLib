#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"秘道"NOR);
        set("long", @LONG
这条阴暗的秘道在山腹中曲折延伸，不知通往何处。这里的石壁非常
潮湿，看来附近有水源。
LONG);
        set("objects", ([
                    __DIR__"npc/hama" : 1,
        ]));
        set("exits", ([
              "westdown" : __DIR__"midao2",
              "east" : __DIR__"midao",
        ]));
        setup(); 
}

void init()
{    
  	object me = this_player();
     	if (random(me->query("kar")) <8 && me->query_con() < 35){ 
        	tell_object(me, HIB "你忽然感到呼吸一紧，原来是这里的空气污浊、流通不畅。\n" NOR );      
             	tell_room(environment(me), me->name()+"突然脸色变得极为难看，并深深地吸了口气。\n" NOR,({ me }));
//             	me->receive_damage("neili", 50);
             	me->receive_damage("jing", 50);
             	me->receive_wound("jing", 20);
             	}           
}
