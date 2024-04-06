// Room: /d/gaochang/shulin8.c

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "高昌迷宫");
	set("long", @LONG
这是条黑沈沈的长甬道,甬道前出现了三条岔道。
迷宫之内并无足迹指引，你不知道要往哪条路走。
俯身细看，见左首，右首和前方三条路上都有淡淡的足迹。
你似乎迷失了方向，象没头苍蝇般到处乱闯。
LONG
	);

	set("exits", ([
		"west" : __DIR__"shulin7",
		"south" : __DIR__"shulin"+(random(10)+2),
		"east" : __DIR__"shulin14",
		"north" : __DIR__"shulin"+(random(10)+2),
	]));
set("objects",([
		__DIR__"npc/ghost" : 3,
		]));
	set("outdoors", "gaochang");
	setup();
//	replace_program(ROOM);
}

void init()
{

	object ob, room;
	mapping fam;

	int i = random(2);
	if( i == 0) return;

	ob = this_player();
	room = this_object();

	if (ob->query("id") == "gui" || !living(ob)) return;
	if (!userp(ob)) return;
	if (!ob) return;
	if (!userp(ob)) return;

	message_vision(HIR "\n$N一不小心，触动了迷宫的机关！\n
 $N只听得头上一阵巨响，原来是头上一块巨石落下。\n\n" NOR, ob);

	message_vision(HIR "\n$N痛得几乎失去了知觉......\n\n" NOR, ob);

	if((int)this_player()->query("qi")<250) this_player()->die();
        { this_player()->unconcious();
this_player()->move("/d/gaochang/road");}
}

