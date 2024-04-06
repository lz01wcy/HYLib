// by mayue

inherit ROOM;

void create()
{
	set("short", "千毒窟外");
	set("long", @LONG
这里是五毒教饲养毒物的地方，山壁旁有一个天然的石洞，里
面黑漆漆的看不清楚。一阵山风吹来，你闻到一股腥味。洞口站着
几个五毒教弟子。 
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"eastup" : __DIR__"wdsl5",
		"south" : __DIR__"wdsl4",
//		"westdown" : __DIR__"wdsl3",
		"north" : __DIR__"qiandu2",
	]));
        set("objects", ([
                  __DIR__"npc/dizi": 4,
	]));
    

	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
    me=this_player();
   if(dir=="north")
      {
  if ((string)me->query("family/family_name")!="五毒教"
        & objectp(present("di zi", environment(me))))
          return notify_fail("五毒教弟子忽然挡住你，厉声喝道：这位" +
           RANK_D->query_respect(me) + "鬼头鬼脑的想干什么？\n");
      }
  return ::valid_leave(me, dir);
}
