// /guanwai/chuanchang.c

inherit ROOM;
#define TIME_TICK1 (time()*60)
void create()
{
	set("short", "船厂");
	set("long", @LONG
这里是古镇船厂。船厂是位于关外大平原中部的一个古老的小镇，此镇
西、南、北、三面是以高墙垒筑，利于坚守。东面临松花江天成天险，乃兵
家必争的要地。松花江在冬春时结冰可通行，夏秋化冻你只好找船家帮忙了。
LONG );
	set("exits", ([
		"south"  : __DIR__"xuedi3",
		"east"   : __DIR__"bingmian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	string chn_month;
	object obj, *ob;
        int i,j;
	mixed *local;
	local = localtime(TIME_TICK1);

	if (dir=="east")
	{
//get_month = CHINESE_D->chinese_number(local[4]);
		chn_month = CHINESE_D->chinese_number(local[4]);
//		chn_month = CHINESE_D->chinese_month(time()*60);
		if (chn_month=="十二" || chn_month=="一" || chn_month=="二" ||
		 chn_month=="三" || chn_month=="四" || chn_month=="五")
		{
			message_vision("$N见江面结冻，便壮起胆子踩冰而过。\n\n", me);
			if (random(me->query_dex())<20)
			{
				me->receive_wound("qi",20);
				me->receive_damage("qi",20);
			message_vision(chn_month+"$N只觉得脚下一滑，全身腾空而起，结结实实的摔在了冰面上！\n", me);
			}
			return 1;
		}
		else
		{
			j = 0;
			ob = all_inventory(environment(me));
			for(i=0; i<sizeof(ob); i++)
			{
				if ( (!userp(ob[i])) && (ob[i]->query("id")=="chuan fu"))
					j = 1;
			}
			if (j == 0)
			{
				obj = new(__DIR__"npc/chuanfu");
				obj -> move(environment(me));
			message_vision("船厂里走出一个船夫，瞪着眼看着$N。", me);
			}
			else
			message_vision("船夫在旁边拿眼瞪着$N看。", me);
			return notify_fail("冰面化冻，还是乘船吧！\n");
		}
	}
	return 1;
}

