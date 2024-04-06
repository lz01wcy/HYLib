// Room: /d/sandboy/daotian3.c

inherit ROOM;

void create()
{
	set("short", "稻田");
	set("long", @LONG
金灿灿的一片稻田,微风轻送,谷浪涟涟,远望去,一片金色,直连到天的
尽头.稻草人手中摇晃着破扇子,守卫着今年的好收成.向北去有条田埂通向
小村庄.向南是一片山坡.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
        set("exits", ([
                "north" : __DIR__"daotian2",
                "west" : __DIR__"liechang3",
                "east" : __DIR__"yutian3",
        ]));
//        set("no_fight",1);
//        set("no_beg",1);
//        set("no_steal",1);
	set("objects", ([
		__DIR__"non/nontian" : 1,
	])); 

	setup();
	replace_program(ROOM);
}
