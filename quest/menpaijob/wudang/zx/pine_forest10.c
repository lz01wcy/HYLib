//Cracked by Roath
// pine_forest10.c 松林小溪
// by Marz@XKX 11/11/96
#include <localtime.h>
#include <ansi.h>

inherit ROOM;


void create()
{
	mixed *local;
        object *ob;
        local = localtime(time()*60);

	set("short", HIM"松中草地"NOR);
	set("long", @LONG
	眼前霍豁然开朗，密林中露出一片空地，中间一条溪水潺
潺流过。溪边奇花异草，长得特别鲜艳。
LONG
	);
	
	switch(random(6)){
	case 1:
		set("objects", ([ __DIR__"obj/songguo" : 2]));
		break;
	case 2:
		set("objects", ([ __DIR__"obj/snake" : 1]));
		break;
	case 3:
		set("objects", ([ __DIR__"obj/pine" : 1]));
		break;
	case 4:
		set("objects", ([ __DIR__"obj/pine" : 1]));
		break;
	case 5:
		set("objects", ([ __DIR__"obj/pine" : 1]));
		break;
	}	          	
	
	set("exits", ([
		"east" : __DIR__"pine_forest"+(random(2)),
		"west" : __DIR__"pine_forest"+(random(2)),
	]));
	
	set("invalid_startroom", 1);
	
	set("cost", 3);
	setup();
}


void init()
{
	object me = this_player();
	
	if ( !objectp(me->query_temp("armor/boots")) )
		me->receive_damage("qi", 10);  

}

