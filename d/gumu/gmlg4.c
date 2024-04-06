// Room: /u/xdd/gumu/gmlg4.c
// by shang and xdd  97/6
// Modify By River 98/08/30
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
     set("short", HIC"石室"NOR);
     set("long", @LONG
这石室比之先前捉麻雀的石室长阔均约大了一倍，室中已有六只麻雀在内。
地方大了这麽多，捕捉麻雀自然远为艰难。石室密闭，墙上两只火把照得整个
石室灯火通明。
LONG
        );

     set("exits", ([
         "north" : __DIR__"gmlg3",          
         "south" : __DIR__"gmlg5",          
     ]));

     setup();
}

void init()
{
     add_action("do_zhuo", "zhuo");
}

int do_zhuo(string arg)
{
          mapping fam;
          object me = this_player();
          int i;
          if (!living(me)) return 0;
          if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
           return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");
          if ( arg == "maque") {
          if ((int)me->query_skill("dodge",1 ) < 50)
            return notify_fail("你轻功身法太低，捉不住这么多麻雀的。\n");
          if ( (int)me->query_skill("dodge", 1) > 101 )
            return notify_fail("你不用在这里浪费时间精力了。\n");  
          if ( (int)me->query("jing") < 30 )
            return notify_fail("你太累了, 先休息一下。\n");
//          if ( me->query("potential") > me->query("max_pot"))   
//             me->set("potential", me->query("max_pot"));   
          i = me->query_skill("dodge", 1) / 10;
          me->receive_damage("jing", 10 + random(15));
          me->receive_damage("jing", 10 + random(15));
          if ( random(i) > 2 ) {
                 write("你气喘吁吁，累得满头大汗，别说捉到，连羽毛也碰不到一根。\n");
                 }
          else {
                 write("你累得满头大汗，终於抓到了麻雀。\n");
                 me->improve_skill("dodge", (int)(me->query_int()/2) + (int)(me->query_int()/2) );
                 if (me->query("combat_exp") < 100000) {
                 me->add("potential", random(2));
//               me->add("combat_exp", random(5));
                 return 1;
                 }
               }
          return 1;
          }
       return notify_fail("你要捉什么？\n");       
}

