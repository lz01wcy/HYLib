// Room: /u/zqb/tiezhang/shanlu-1.c
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", GRN"瓜架"NOR);
	set("long", @LONG
    转过一个小弯，忽然眼前一绿，面前是一片很大的瓜架。在高大
的木架旁，种植着一些蔬菜和瓜类，架子上已爬满了各种植物，从茂密的叶 
子中，垂下各种已经成熟的果实，丝瓜，苦瓜，葫芦...还有一些叫不出名
称的瓜果也缠杂在其中。
LONG	);
    set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 2 */
    "southeast" : __DIR__"shuijing.c",
"west" : __DIR__"guangchang.c",
]));
    set("objects", ([
     __DIR__"npc/qqzhang" : 1,
    ]));
	set("no_clean_up", 0);
    set("hulu_count", 5);
	setup();
}
void init()
{
        add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{
        object me = this_player();
        object ob;

        if (me->query_temp("marks/摘1") )
            return notify_fail("你已经摘过了，不要这么贪心！\n");

    if (!arg || (arg != "hulu" && arg != "葫芦"))
{
        if (query("hulu_count") < 1)
        {
        message_vision ("$N拨开枝叶找来找去，发现葫芦已经被别人摘没了！\n",this_player());
        return 1;
        }
        return notify_fail("你想摘什么？\n");
        return 1;
}

{
        write("你踮起脚尖，从架子上摘下了一个葫芦。\n");
        this_player()->set_temp("marks/摘1", 1);

            ob=new("/d/tiezhang/obj/qingshui-hulu");
            ob->move(this_player());
            add("hulu_count", -1);

        return 1;
       }
}
