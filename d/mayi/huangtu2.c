// rich 99/04/05
inherit ROOM;
void create()
{
	set("short", "黄土路");
	set("long", @LONG
你漫步在黄土高原上，这里是一望无际的平原，黄色的土，绿色的
草，蓝蓝的天，天底下，草原上有一群群的牲畜，偶尔还有有一群野马
跑过。
LONG
	);
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
                "eastup" : __DIR__"changcheng2",
                "southwest" : __DIR__"dukou1",
	]));
       setup();
	replace_program(ROOM);
}
