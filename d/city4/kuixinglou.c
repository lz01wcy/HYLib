// /d/changan/kuixinglou.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "奎星楼");
	set  ("long",  @LONG
这是永宁门上的一个城楼，极目四望，可以看到南边青青的终南山。
旁边几个官兵正在休息。不过这里是军事重地，你最好还是赶快离开。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"down"  :  __DIR__"southgate",
	]));
	set("objects",  ([  //sizeof()  ==  4
		"/d/city/npc/wujiang" : random(3),
		"/d/city/npc/bing" : random(3),
	]));
	set("outdoors",  "changan");
	set("coor/x", -5040);
	set("coor/y", 970);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
