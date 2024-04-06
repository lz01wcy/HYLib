//Cracked by Roath
// pine_forest4.c 松林
// by Marz@XKX 11/11/96

inherit ROOM;


void create()
{
	set("short", "松林");
	set("long", @LONG
	这是松林深处，暗无天日，朦胧中只感觉到左右前后到处
都是树影。地上有一两个死人骷髅，发着绿荧荧的磷光。你惊骇之
间，一脚踩在钢针般的松针上！
LONG
	);
		set("objects", ([
			__DIR__"obj/pine" : 3,
			__DIR__"obj/snake" : 1]));

	switch(random(13)){
	case 1:
		set("objects", ([
			__DIR__"obj/pine" : 3,
			__DIR__"obj/snake" : 1]));
		break;
	case 3:
		set("objects", ([ __DIR__"obj/snake" : 1]));
		break;
	case 5:
		set("objects", ([
			__DIR__"obj/pine" : 3,
			__DIR__"obj/snake" : 1]));
		break;
	case 7:
		set("objects", ([ __DIR__"obj/snake" : 2]));
		break;
	case 9:
		set("objects", ([ __DIR__"obj/pine" : 2]));
		break;
	}	          	
	
	set("exits", ([
		"south" : __DIR__"pine_forest"+(4+random(6)),
		"north" : __DIR__"pine_forest"+(3+random(7)),
		"west" : __DIR__"pine_forest"+(random(6)),
		"east" : __DIR__"pine_forest"+(random(4)),
	]));
	
	set("cost", 3);
	setup();
}


void init()
{
	object me = this_player();
	
	if ( !objectp(me->query_temp("armor/boots")) )
		me->receive_damage("qi", 10);  

}

