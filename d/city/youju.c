// ROOM: /city/youju.c
// Date: 28/5/2000 by happy
#include <ansi.h>;
inherit ROOM;
void create()
{
  set ("short",HIC"扬州邮局"NOR);
set ("long",@LONG
这里是扬州邮局,熙熙攘攘的人很多,非常繁忙。近来邮局由于退
休人员过多，邮差人手不够，信件屡屡发不出去。有一些江湖人士见
此便无事时过来帮忙，以次获得一些报酬。墙上帖着一张布告(post)。
LONG
);
  set("objects",([
  "/quest/letter/foxmail.c":1,
]));
set("item_desc",([
"post":"布告上面写着:本邮局诚招邮递员。\n",
]));
  set("exits",([
  "north":__DIR__"ximen",
  "south":"quest/songhuo/huowo",
]));
set("no_steal", "1");
set("no_fight", "1");
set("no_sleep_room", "1");
setup();
replace_program(ROOM);
}
