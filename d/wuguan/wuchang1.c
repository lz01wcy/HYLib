//cool 98.4.18

#include <ansi.h>
inherit ROOM;
int do_da(string arg);

void create()
{
	set("short", "西练武场");
	set("long", @LONG
这是间大大的房子，十分宽阔，不少人在这里汗流浃背的苦练着功夫，
地上有一些练武用的工具，墙边摆者一排木人桩(muren zhuang)。
LONG);
	set("exits", ([
	       "north" : __DIR__"wuchang3",
	       "east" : __DIR__"lang1",
        ]));
        set("item_desc", ([
	  "muren zhuang" : "一个木桩，做成木人的样子固定在地上，供人击打(da)练功。\n",
	]));
        set("outdoors", "武馆");
        set("objects", ([
           __DIR__"npc/xxdizi" : 1,
        ]));
	setup();
}

void init()
{
        add_action("do_da", "da");
        
}
int do_da(string arg)
{
        object me;
        int costj, costq;

        me = this_player();
        if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
        if (me->is_fighting()) return notify_fail("你正在战斗中，无法专心练功！\n");
        if ( !living(me)) return notify_fail("你发疯了？\n");
        if( objectp( me->query_temp("weapon")) ) return notify_fail("只有空手才能打木人桩。\n");
        if (!arg || arg != "muren zhuang") return notify_fail("你要打什么？打人吗？\n");
        costj = random((int)me->query("con"))+1;
        costq = random((int)me->query("str"))+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
              message_vision("$N马步一松，一不小心脑袋撞在了木人桩上！\n",me);
              me->unconcious();
              return 1;
              }
        me->receive_damage("jing", costj);
        me->receive_damage("qi", costq);       
        message_vision("$N站好马步，运气于拳，开始和木人桩对打起来。\n", me);
        if ( (int)me->query_skill("cuff", 1) < 30 && random(10)>6 ){  
              write(HIM"你在和木人桩的对打中领悟了不少基本拳法！\n"NOR);
              me->improve_skill("cuff", (int)(me->query("int") / 5));
              }
        if ( (int)me->query("combat_exp") < 30000) {
        if ( (int)me->query("potential") <  10000) {
	     me->add("potential",random(2));
             }           
             me->add("combat_exp",random((int)(me->query("str") / 10)));
             }
        return 1;
}
