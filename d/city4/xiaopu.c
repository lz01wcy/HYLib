// /d/changan/xiaopu.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "小铺子");
	set  ("long",  @LONG
这是一家专卖旅游纪念品的小铺子。到了长安不买点纪念品，说不
过去吧......一个大嫂正站在铺前向游客招揽生意。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"north"  :  __DIR__"eastroad1",
	]));
	set("objects",  ([  //sizeof()  ==  4
		__DIR__"npc/dasao": 1,
	]));
	set("coor/x", -5020);
	set("coor/y", 990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
