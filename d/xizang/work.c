 // work.c
//#include "/feature/damage.c" 
inherit ROOM; 
void create()
{
        set("short", "石场");
        set("long", @LONG
恰克卜里山盛产各种上等石料。这里硝烟弥漫，很多人都在辛苦的劳动着。用
自己的汗水去换取一些收入。每个到这里工作的人都可以拿到一份很公平的报酬。
许多人正在忙忙碌碌的工作着，门口挂著一块牌子(sign)。
LONG
        ); 
    set("exits", ([ /* sizeof() == 1 */
                "west" : __DIR__"stoneroad",
                "north" : __DIR__"octo5",
                "south" : __DIR__"birdroad",
        ]));
        set("outdoors", "guanwai"); 
        set("item_desc", ([
                "sign": @TEXT
现在正紧缺人手，急需雇佣一批短工来干活。 
work     开始工作。 
TEXT
        ]) );
        set("no_fight", 1);
        set("no_magic", 1);
        set("coor/x",-1230);
        set("coor/y",-40);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_work", "work");
} 
int do_work(string arg)
{
        object ob;
        object me; 
        me = this_player();
   if(me->is_busy()) return notify_fail("你的动作还没有完成，不能工作。\n");
        message_vision("$N辛苦的工作终于结束了，可人也累的要死\n", me);
//      me->add("gin",-30);
//      me->add("sen",-30);
        me->receive_wound("qi",70);
        me->receive_wound("jing",70);
        ob = new("/clone/money/silver");
        ob->move(me);
        message_vision("老板对$N说：这是你的工钱。\n", me);
        me->start_busy(22);
        return 1;
} 
