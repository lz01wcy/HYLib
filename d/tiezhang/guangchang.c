// Room: /u/zqb/tiezhang/guangchang.c

inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
    山路行到这里，忽然变得开阔，你眼前出现了一片很大的广场。一
些铁掌帮的弟子来回穿梭于其间，显得很忙碌。在广场的周围有很多岩石建
的房子。正面的这间尤其显得高大雄伟。左面的房子中不时的涌出阵阵热气
，其间还加杂着鼓风的声音。
LONG	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"shanlu-2.c",
  "west" : __DIR__"lgfang",
  "east" : __DIR__"guajia",
  "northup" : __DIR__"wztang",
]));
    set("objects", ([ /* sizeof() == 3 */
    __DIR__"npc/huiyi" : 1,
    __DIR__"npc/heiyi" : 2,
    "/d/biwu/champion_tz":1,
    "quest/menpai/tiezhang/shi" : 1,
    __DIR__"obj/axe" : 5,
    ]));
    set("valid_startroom", 1);
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	setup();
	replace_program(ROOM);
    "/clone/board/tiezhang_b"->foo();
}
