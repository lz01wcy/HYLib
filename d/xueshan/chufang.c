//      chufang.c 厨房
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void init();
int work();

void create()
{
        set("short","厨房");
        set("long",@LONG
这里是雪山寺的厨房，新来的僧人可以在此打杂。房
中醒目的位置有一块牌子（paizi）。
LONG );
        set("item_desc",([
                "paizi" : "本厨房招收杂工。工作(work)一次付银十两。\n",
        ]));
        set("no_fight",1);
        set("no_steal",1);
        set("no_clean_up", 0);
        set("objects", ([
                "/d/wudang/obj/xiangcha" : 2,
                "/d/wudang/obj/mitao" : 3,
        ]));

        set("exits",([
                "south" : __DIR__"xiaoyuan",
        ]));
        set_temp("times" , 10);
        setup();
}

void init()
{
	add_action("do_work","work");
}

int do_work()
{
	object me=this_player();
        object ob;

        if (query_temp("times")==0)
                return notify_fail("今天的活干完了，明天再来吧！\n");
        if(me->query("qi")<me->query("max_qi")/10)
		return notify_fail("你的气太虚弱，不能工作！\n");
	me->add("qi",-me->query("max_qi")/10);
	message_vision("$N干了一些杂活，累得够呛。\n" , me);
	add_temp("times",-1);
        ob=new("/clone/money/silver");
        ob->set_amount(10);
        ob->move(me);
	return 1;
}
