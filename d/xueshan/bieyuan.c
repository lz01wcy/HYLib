//      bieyuan.c 雪山别院
//      Designed by secret (秘密)
//      97/05/25

inherit ROOM;

void create()
{
        set("short","雪山别院");
        set("long",@LONG
这里是雪山寺的分部，当年贡唐仓大喇嘛不远万里进
京面圣，被封为国师，就在此处宣扬佛法。
LONG );
        set("exits",([
                "east" : "/d/beijing/road5",
        ]));
        set("objects" , ([
                __DIR__"npc/seng-bing1"  : 2 ,
                CLASS_D("xueshan") + "/guoshi" : 1 ,
        ]));
//        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "east" ) return 0;

	return ::valid_leave(me, dir);
}
