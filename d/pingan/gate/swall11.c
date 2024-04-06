inherit ROOM;
void create()
{
        set("short", "南城墙4");
        set("long", @LONG
丈许宽的城墙又高又厚，给人一种安全的感觉。遥望城外，绿色的田野一望无垠，
一座座小小的农房星星点点的点缀着宽广的田野，傍晚时，炊烟袅袅，夕阳斜照，美
不胜收。远处连绵的群山更是令人感到威武壮观。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"supgate",
  "west"  : __DIR__"swall10", 
]));
        set("outdoors", "pingan");
        set("coor/x",-30);
	set("coor/y",-60);
	set("coor/z",30);
	setup();
}
 int valid_leave(object me, string dir) 
{
        object badguy;
 	if ( random(10)>8 && dir == "east" )
{		badguy=new("d/pingan/feizi/feizei");
		badguy->move("d/pingan/gate/swall11");
        badguy->kill_ob(me);
        badguy->set_leader(me);
        badguy->set("combat_exp",me->query("combat_exp"));
if (me->query_skill("force")>10)
{
        badguy->set_skill("unarmed",me->query_skill("force")*1/2);
        badguy->set_skill("parry",me->query_skill("force")*1/2);
        badguy->set_skill("dodge",me->query_skill("force")*1/2);
        badguy->set_skill("sword",me->query_skill("force")*1/2);
}
        me->fight_ob(badguy);
        me->start_busy(1);
 	return notify_fail("忽然从城中爬上一个黑影！\n");
}
	else 
	{ 
 	return ::valid_leave(me, dir);
	}
}

