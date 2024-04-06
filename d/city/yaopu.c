// Room: /city/yaopu.c
// YZC 1995/12/04 
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "药铺");
	set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小
抽屉里散发出来的。神医平一指坐在茶几旁，独自喝着茶，看也不看你一眼。
一名小伙计站在柜台后招呼着顾客。柜台上贴着一张发黄的广告(guanggao)。
LONG );
	set("item_desc", ([
		"guanggao" : "本店出售以下药品：
金创药：\t五十两白银
无常丹由桃花岛黄药师所配，生死肉骨．
朱睛冰蟾救治百毒，无效包换．
其他神药与老板面议。\n",
	]));
//	set("item_desc", ([
//		"guanggao" : "本店老板平一指外出采药未归，今日暂停营业。\n",
//	]));
	set("objects", ([
	       __DIR__"npc/ping" : 1,
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"dongdajie2",
		"north" : "/quest/liandan/liandan1",
	]));
//          set("no_fight", 1);
         set("no_steal", 1);
//      set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}
void init()
{
	add_action("do_moyao","moyao");
}
int do_moyao(string arg)
{
       object me=this_player();
         if (me->is_busy() )
       return notify_fail("你还是认真的磨你的药吧！\n");
        if (me->query("job_moyao")<1)
       return notify_fail("没经过老板同意你可不能磨药哟＃\n");
       me->set("job_moyao",0);
       message_vision(HIY
      "$N擦了擦脸上的汗水，蹲在一边拿着药锤开始磨药了！！\n"NOR,me);
       message_vision(HIR
      "$N忽然看到药柜下有一些碎银，便趁没人注意偷偷藏进了怀了！！\n"NOR,me);
       MONEY_D->pay_player(this_player(), 500);
       me->set("potential", me->query("potential")+random(10));
       me->set("combat_exp", me->query("combat_exp")+random(30));
       me->add("jing",-60);
       me->start_busy(6);
       return 1;
}
