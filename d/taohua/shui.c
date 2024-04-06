// Room: /u/jpei/thd/shui.c

#include <ansi.h>
#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", HIB"水"NOR);
	set("long", @LONG
这里是五行层的水，你一走下来，往上的铁梯就被撤掉了。五行层的构局
互相连通，进入后就迷失了方向。每一行与其他四行的关系是生、被生、克、
被克。
LONG
	);
	set("exits", ([ 
		"tu" : __DIR__"tu",
		"huo" : __DIR__"huo",
		"mu" : __DIR__"mu",
		"jin" : __DIR__"jin",
	]) );

	set("no_clean_up", 0);
	setup();
}

void init()
{
	mixed *local;
	string tempstr;
	object me = this_player();
	int *month_map = ({2,2,-1,-1,-1,-1,1,1,1,1,2,2});

	add_action("do_save", "save");
	add_action("do_quit", "quit");
	if (me->query_temp("wuxing_leave"))
		me->delete_temp("wuxing_leave");
	if (!me->query_temp("liangyi")) 
		me->set_temp("liangyi", -1);
	if (!me->query_temp("sixiang")) 
		me->set_temp("sixiang", -1);
	if (!me->query_temp("wuxing")) {
		local = localtime(time() * 60);
		me->set_temp("wuxing", month_map[local[LT_MON]]);
		me->set_temp("wuxing_total", 6);
		me->set_temp("wuxing_step", 1);
		me->set_temp("wuxing_error", 1);
		tempstr = "由于";
		if (me->query_temp("liangyi") < 0) tempstr += "误断两仪";
		if (me->query_temp("sixiang") < 0) tempstr += "乱入四象";
		if (me->query_temp("wuxing") < 0) tempstr += "错踏五行";
		me->set_temp("last_damage_from", tempstr + "，触发阵中机关而被射");
	}
	if (me->query_temp("sixiang") < 0 || me->query_temp("liangyi") < 0) 
		me->set_temp("wuxing", -1);
	if (me->query_temp("wuxing_error") == 6) {
		tempstr = "由于你";
		if (me->query_temp("liangyi") < 0) tempstr += "误断两仪";
		if (me->query_temp("sixiang") < 0) tempstr += "乱入四象";
		if (me->query_temp("wuxing") < 0) tempstr += "错踏五行";
		write(tempstr + "，被一股大力甩出了阵，正好摔到一块岩石上！\n"); 
		me->delete_temp("wuxing");
		me->delete_temp("liangyi");
		me->delete_temp("sixiang");
		me->delete_temp("wuxing_total");
		me->delete_temp("wuxing_step");
		me->delete_temp("wuxing_error");
		me->unconcious();
		me->move(__DIR__"dongkou", 1);
		return;
	}
	if (me->query_temp("wuxing_step") == me->query_temp("wuxing_total")) {
		write("你将五行踏遍，终于从迷阵走了出来。\n"); 
		me->delete_temp("wuxing");
		me->delete_temp("liangyi");
		me->delete_temp("sixiang");
		me->delete_temp("wuxing_total");
		me->delete_temp("wuxing_step");
		me->delete_temp("wuxing_error");
		me->move(__DIR__"dong", 1);
		return;
	}
}

int do_save()
{
	write("这里不准存盘！\n");
	return 1;
}

int do_quit()
{
	write("这里不准退出！\n");
	return 1;
}

int valid_leave(object me, string dir)
{
	int wuxing = me->query_temp("wuxing");

	if (!me->query_temp("wuxing_leave") && (dir == "tu" || dir == "huo" || dir == "mu" || dir == "jin")) {
		me->set_temp("wuxing_leave", 1);
		if (wuxing < 0) {
			write("阵中机关忽然大作，数道青芒红芒击中了你，你只觉全身痛楚，意识也有些模糊了！\n");
			me->receive_wound("jing", 200);
			me->receive_wound("qi", 500);
			me->add_temp("wuxing_error", 1);
		}
		else {
			switch (dir) {
				case "huo":
					if (wuxing == 1) {
						write("阵中机关忽然发作，一道红芒击中了你，你只觉一阵痛楚！\n");
						me->receive_damage("qi", 100);
						me->add_temp("wuxing_error", 1);
					}
					else
						me->add_temp("wuxing_step", 1);
					break;

				case "jin":
					if (wuxing == 1) {
						me->add_temp("wuxing_total", 1);
					}
					else {
						write("阵中机关忽然大作，数道青芒红芒击中了你，你只觉全身痛楚，意识也有些模糊了！\n");
						me->receive_wound("jing", 100);
						me->receive_wound("qi", 100);
						me->add_temp("wuxing_error", 1);
					}
					break;

				case "tu":
					if (wuxing == 1) {
						write("阵中机关忽然大作，数道青芒红芒击中了你，你只觉全身痛楚，意识也有些模糊了！\n");
						me->receive_wound("jing", 100);
						me->receive_wound("qi", 100);
						me->add_temp("wuxing_error", 1);
					}
					else {
						me->add_temp("wuxing_total", 1);
					}
					break;

				case "mu":
					if (wuxing == 1) 
						me->add_temp("wuxing_step", 1);
					else {
						write("阵中机关忽然发作，一道青芒击中了你，你只觉一阵晕眩！\n");
						me->receive_damage("jing", 100);
						me->add_temp("wuxing_error", 1);
					}
					break;
			}
		}
	}
	
	return ::valid_leave(me, dir);
}
