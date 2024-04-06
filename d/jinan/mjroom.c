 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","麻将馆");
  set("long",@LONG
一进门，一个长着大兔牙的妙龄少女笑着迎了上来，把你带到座位上，并帮你脱
下大衣挂好，你细心的观察着周围，真是气派啊，墙上挂着几副书画，虽然你看不出
是谁人作品，但肯定是出于名家之手。居中一桌四椅，桌椅都是红檀木所制，四张椅
子上分别铺着虎，豹，貂，狐四兽之皮，再看那已经摆好的四方围城，你看着那副麻
将像是以象牙所制，上面的各色图标都是以宝石镶嵌，但背面一行小字写道：海洋麻
将，正当你惊讶之际，刚才那少女已经奉上茶水点心，并问大家道：可以开始了吗？
详细的规则请看看布告栏（ｂｏａｒｄ）和麻将指南（ｂｏｏｋ）。
LONG
  );
  set("exits",([
         "east" : __DIR__"mjgate",
               ]));
set("no_fight",1);
        set("objects", ([
//            __DIR__"npc/jiaoqi" : 1,
//            __DIR__"npc/east" : 1,
//            __DIR__"npc/west" : 1,
//            __DIR__"npc/south" : 1, 
            __DIR__"npc/mj" : 1,                                        
       ]) );
        set("item_desc",([
"board":"
                       基  本  设  定
            setmj 可用的有自动胡、  、碰、听、显式方法。
--------------------------------------------------------------------
例子1: setmj pon 1w        设定会自动碰1w 当别人打出一万时会自动碰一万。
       setmj gon 1w                                         自动  一万。
       setmj tin 1w                                         自动胡一万。
例子2: setmj show 代码        设定为只显示代码。
       setmj show color 设定为彩色显示。
例子3: setmj tin none        取消会自动胡牌设定。
       setmj gon none
       setmj pon none
例子4: setmj auto tin        设定自动听牌。
--------------------------------------------------------------------
",
"book":"
      指  令         例          子                说    明
    ┌―――――――――――――――――――――――――――――――┐
    │ look  l mj或.看自己牌,l 1p或.1看玩家1的牌                │
    │       l all或..看全部,l end看流局l dump。      看牌      │
    │ mo    如果刚摸完就按会打掉刚摸的牌，方便听胡      摸牌      │
    │ dump         dump <代码>。                     打牌     │
    │ eat          eat <代码1> <代码2>。             吃牌     │
    │addin  加入排局   pon    碰牌    hu  胡牌  start 牌局开始  │
    │ gon          gon 或 gon <代码>(暗杠用)。       杠牌      │
    │ setmj        help setmj。                     设定参数  │
    │ restart   restart 或 restart mj。             重新开始  │
    │ continue     催NPC或玩家出牌，特殊情况时特别有用。         │
    │ top   top aip,top -p,top -w,top -h,top -d              │
    │       top -l看全部,-lw,-lh,-ld。               查资料    │
    └――――――――――――――――――――――――――――――――┘
",
]));       
        set("coor/x",10);
        set("coor/y",1910);
        set("coor/z",0);
    set("no_magic",1);
    set("no_cast",1);
    set("no_usemark",1);
    set("no_usemark1",1);
    set("no_usemark2",1);
    set("no_fight",1);
    set("NONPC",1);
    set("no_spells",1);
    setup(); 
} 
void init()
{
    object *ob,me;
    int i;
    me=this_player();
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) 
        {
            if( !interactive(ob[i]) || ob[i]==me ) continue;
                if(query_ip_number(ob[i]) == query_ip_number(me))
            return notify_fail("想作弊呀！你已经有个人在里面了。\n");   
    }   
    add_action("do_give", "give");
    add_action("do_leave", "leave");
} 
int valid_leave(object me, string dir)
{       object room;
        room=this_object();
        
        if(userp(me) && me->query_temp("playing_mj") && dir="east")
                return notify_fail("赌局正在进行中，不可随便走动！\n");         
        return 1;
} 
int do_give()
{
    if(userp(this_player()))
    write("这里不能转移什么物品。\n");
    return 1;
}
 
int do_leave()
{
    if(interactive(this_player()) && this_player()->query_temp("playing_mj"))
    {
    this_player()->delete_temp("playing_mj");
    tell_room(environment(),this_player()->name()+"不想玩了。\n");
    }
    return 1;
}       
