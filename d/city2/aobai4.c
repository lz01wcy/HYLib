// Room: /city2/aobai4.c


inherit ROOM;
void close_gate();
int do_open(string arg);
int do_close(string arg);

void create()
{
	set("short", "鳌府后院");
	set("long", @LONG
这里是鳌府后院，中心是一个大花园。西边一条长廊走道直
通往鳌拜的卧房，有几个官兵把守。北边是书房。南边是鳌拜私
设的牢房,牢门(men)是锁着的。
LONG );
	set("item_desc", ([
		"men":"这是一扇很结实的铁门。\n",
	]));
	set("exits", ([
		"west" : __DIR__"aobai6",
		"east" : __DIR__"aobai3",
		"north" : __DIR__"aobai7",
	]));

	set("objects", ([
		"/d/city2/npc/guanjia" : 1,
		"/d/city/npc/jiading" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_open", "unlock");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"aobai8")) )
		room = load_object(__DIR__"aobai8");
	if(objectp(room))
	{
		delete("exits/south");
		message("vision","只听乒地一声，暗门自动关了起来。\n",this_object());
                message("vision","你脑海中闪过一个念头：哎哟！又进不去了！\n" ,
			 this_object());
		room->delete("exits/north");
		message("vision","只听乒地一声，暗门自动关了起来。\n",room);
	        message("vision","你脑海中闪过一个念头：坏了！出不去了！\n" ,
			room );
	}
}

int do_open(string arg)
{
	object room;
        object ob;

	if (query("exits/south"))
		return notify_fail("暗门已经是开着了。\n");

	if (!arg || (arg != "men" && arg != "south"))
		return notify_fail("你要开什么？\n");
	if (!(ob = present("lfkey", this_player())))
		return notify_fail("你不会撬锁。\n");
	message_vision(
	"$N用一把钥匙打开了秘门，可是钥匙却断了.\n", this_player());
	destruct(ob);

       if(!( room = find_object(__DIR__"aobai8")) )
		room = load_object(__DIR__"aobai8");
	if(objectp(room))
	{
		set("exits/south", __DIR__"aobai8");
		message_vision("$N使劲把暗门打了开来。\n",this_player());
		room->set("exits/north", __FILE__);
		message("vision","里面有人把暗门打开了。\n",room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}

int valid_leave(object me, string dir)
{
if (!me) return 1;
	if (objectp(present("guan jia", environment(me))) && 
                     (dir == "south"||dir == "north")&& living(present("guan jia", environment(me))))
		return notify_fail("女官家挡住了你。\n");
	return ::valid_leave(me, dir);
}

