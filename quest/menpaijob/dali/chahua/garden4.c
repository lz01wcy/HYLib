//Cracked by Kafei
// Room: /d/dali/garden4.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIB"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有
蜜蜂采蜜其间。碎石路边却长了一，两品异种茶花(flower)。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : HIB"八仙过海
八仙过海，是八朵茶花开于一株，八色各不相同，其中必
须有深紫和淡红的各一朵，那是铁拐李与何仙姑。没有那两种
特别颜色的，及便是八花异色也不能算是“八仙过海”了，叫
做“八宝妆”，就次了一品。
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"garden5",
  "southeast" : __DIR__"garden2",
]));
	set("objects", ([
		__DIR__"npc/chahua" : random(2),
		]));

	set("no_clean_up", 0);

	setup();
//	replace_program(ROOM);
}
void init()
{
	add_action("do_get","get");
}

int do_get(string arg)
{
	object me, ob, weapon;
	me=this_player();

	if (arg=="cha" || arg=="chahua" || arg=="all" || arg=="cha hua") {
		if (!objectp(ob=present("cha", environment(me)))) {
			tell_object(me, "这里没什么好品种的茶花值得挖走。\n");
			return 1;
		}
		if (!objectp(weapon=me->query_temp("weapon"))
			|| weapon->query("id")!="huachu") {
			tell_object(me, "你没有称手的工具来移植这株茶花！\n");
			return 1;
		}
		if (random(2)==1) {
			message_vision("$N小心翼翼地用花锄掘出茶花的根，把整株茶花移了起来。\n", me);
			ob->move(me);
		}
		else {
			message_vision("$N急急忙忙地挖茶花，一不小心把根挖断了，好好的一株茶花，完了。\n", me);
			destruct(ob);
		}
		return 1;
	}
	return 0;
}
