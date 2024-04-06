// /d/xingxiu/nanjiang.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "南疆沙漠");
        set("long", @LONG
这就是浩瀚的塔克拉马干大沙漠，一走进来，你仿佛迷失了方向。
你感到口内十分焦渴，还是快些离开吧。
LONG );
        set("exits", ([
            "northeast" : __DIR__"nanjiang",
            "southeast" : __DIR__"nanjiang3",
            "southwest" : __FILE__,
            "northwest" : __FILE__,
            "north" : __FILE__,
            "west" : "/d/npc/m_weapon/m_room1",
            "south" : __FILE__,
            "east" : __FILE__,
        ]));
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        int current_water;

        current_water = me->query("water");
        if (current_water==0) {
        }

        if (current_water>0 && current_water<20) {
            me->set("water",0);
        }

        if (current_water>20) {
            me->set("water",current_water-20);
        }
        if (dir=="east" || dir=="south" || dir=="north") 
           return notify_fail("你向那边走去，结果发现那是沙漠中的海市蜃楼。\n");
        return ::valid_leave(me, dir);
}

