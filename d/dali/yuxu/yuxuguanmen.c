// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "玉虚观门");
	set("long", @LONG
走到近处，见那黄墙原来是所寺观，匾额上写的似乎是‘玉虚观’三字，
黄墙红瓦，这观看起来很是简陋，门口站着两个小道童。
LONG
	);
        set("outdoors", "大理");
	set("exits", ([ /* sizeof() == 1 */
	    "enter" : __DIR__"yuxuguan",
	    "east" : __DIR__"dadao5",
        ]));
        set("objects", ([
	__DIR__"npc/daotong" : 2 ]) );

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
