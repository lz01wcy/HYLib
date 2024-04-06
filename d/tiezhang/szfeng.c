// Room: /u/zqb/tiezhang/szfeng.c

inherit ROOM;

void create()
{
	set("short", "食指峰");
	set("long", @LONG
    你终于爬上了峰顶，已经累得气喘吁吁了。这里只有丈许方圆的
地方，寸草不生，到处都是光秃秃的岩石，滑不留脚。一阵狂风呼啸而过，
吹得你一个趔趄，差点摔倒，看来还是赶快离开这里的好。
LONG	);
	set("no_clean_up", 0);
    set("outdoors", "tiezhang");
	setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me;
        me=this_player();

    me->receive_damage("qi", 40);
    if ((int)me->query_skill("dodge",1)<100)
    me->improve_skill("dodge",me->query("int"));

    if (arg =="down") 
    {
    write("你攀缘着石壁，缓缓向下爬去。\n");
    message("vision",me->name() + "向下爬去。\n",
            environment(me), ({me}) );
    me->move(__DIR__"juebi-5");
    message("vision",me->name() + "爬了下来。\n",   
            environment(me), ({me}) );
    }
    return 1;
}
