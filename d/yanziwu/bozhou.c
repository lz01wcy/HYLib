//ROOM: /d/yanziwu/bozhou.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "泊舟坞");
        set("long",@LONG
一片芦苇，茭白丛中现出一座船坞，大小船只依次排开。菱花荷叶
丛中条条水道四通八达，由此可乘船离开燕子坞。湖面正系着一尾小舟
(zhou)。
LONG );
        set("outdoors", "yanziwu");
        set("exits", ([
            "east"  : __DIR__"pindi",
        ]));
        set("item_desc", ([
            "zhou" : "这是燕子坞和湖外联系的小舟。舟上一个绿衫少女。岛上的客人只要登
舟(enter)就可以出湖了。\n",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
       add_action("do_enter", "enter");
}
int do_enter(string arg)
{
       object ob ;
       string dir;
       if( !arg || arg !="zhou" ) 
       {
             tell_object(this_player() , "你要投水？\n" ) ;
             return 1 ;
       }
       ob = this_player();
message_vision("船上一个秀美温柔的江南少女看到$N登舟，竹篙轻点，舟已离岸，
燕子坞渐渐在视野里远去。\n", ob);
       ob ->move(__DIR__"taihu") ;
       tell_object(ob, HIG "你在湖上飘流，四周看不尽的江南美景。\n" NOR ) ;
       call_out("home", 10 , ob );
       return 1 ;
}
void home( object ob )
{
       tell_object(ob , "小舟终于恋恋不舍地靠岸了。你走下小舟来。少女挥手道别。\n" ) ;
       ob->move (__DIR__"hupan") ;
}
