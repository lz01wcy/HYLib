inherit ROOM;
string look_gaoshi();
void create()
{
        set("short", "塘沽南城门");
        set("long", @LONG
这是就是塘沽口的南城门了，城门口一队队官兵正在盘查过往的百姓。一
个手持长剑身穿铁甲武将正在门口巡视。城门的墙上张贴着一纸告示(gaoshi)。
LONG );
        set("exits", ([
                "north" : __DIR__"stnanjie1",
	]));

        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

	set("outdoors", "塘沽");

	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n塘沽知府\n";
}
