//      chanshi.c 禅室
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","禅室");
        set("long",@LONG
这里是僧人门参禅打坐的地方。侧壁一列禅床让人看
了就想到该想的事。
LONG );
        set("no_fight",1);
        set("sleep_room",1);
        set("no_steal",1);
        set("exits",([
                "southwest" : __DIR__"dating",
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
