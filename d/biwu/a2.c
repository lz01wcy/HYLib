inherit ROOM;
void create()
{
	set("short", "混元塔第二层");
	set("long", @LONG
这是一个纠集了江湖上十大邪派高手的塔，共有十层之高。
LONG );
       set("no_sleep_room",1);
       set("no_clean_up", 0);
	set("exits", ([
		"down" : __DIR__"a1",
		"up":__DIR__"a3",
	]));
		set("objects", ([
			__DIR__"fawang": 1,
		]));
setup();
}

void init()
{
add_action("do_dazuo","dazuo");
add_action("do_dazuo","exercise");
add_action("do_dazuo","steal");
add_action("do_dazuo","beg");
add_action("do_dazuo","fight");
add_action("do_dazuo","ansuan");
add_action("do_dazuo","hit");
add_action("do_dazuo","get");
}

int do_dazuo()
{
   object me;
   me = this_player();
   tell_object(me,"这里不能用这个指令。\n");
return 1;
}
int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="up" && ob=present("jinlun fawang", this_object()))
return notify_fail( 
"你想硬闯？！\n");
return 1;
}

