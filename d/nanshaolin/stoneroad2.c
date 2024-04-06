// Room: /d/nanshaolin/stoneroad2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long",@LONG
一条平整宽阔的石路，路边是两长溜僧棚，可供大家休息之用。香
客们手执线香，缓步通过。一些忙碌的僧侣，急匆匆的奔驰而去，似乎
有什么要事在身。一队护寺僧兵手执戒刀，正自来往巡视。
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"east"  : __DIR__ "stoneroad3",
		"west"  : __DIR__ "stoneroad4",
		"south" : __DIR__ "xianglu",
		"north" : __DIR__ "miaofadian",
	]));
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("coor/x", 1820);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

