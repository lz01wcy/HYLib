// 发礼物房
// idea@yqyl
inherit ROOM;
#include <ansi.h>

void yyy(string arg);
string file;

void create()
{
	set("short", "礼品房");
	set("long", @LONG
这里是巫师送礼品给玩家的房子(song)。
LONG
	);
	
	set("exits", ([
		"east" : __DIR__"wizard_room"
	]));
	
	setup();
}

void init()
{
	add_action("do_song", "song");
	add_action("do_sheding", "sheding");
}

int do_song()
{
	object who = this_player();
	object present;
	if ( wiz_level(who)<wiz_level("(wizard)") && who->query("id")!="xyanhu") 
		return notify_fail("要wizard及以上巫师执行。\n");
	if (!file) return notify_fail("请设定送啥(sheding <file>)\n");
	
	present = load_object(file);
	if (!present) return notify_fail("没有"+file+"这个东西。\n");
	if (!present->query("liwu")) return notify_fail("这类东西不能发送。\n");	
	write(present->query("name")+"("+present->query("id")+")给每个人，确定吗？[Y/N]\n");
	input_to ((: yyy :));
	return 1;
}

void yyy(string arg)
{
	object *allp = users();
	object present;
	int i;
	
          log_file("liwu",sprintf("%s  本次礼物%s，%s\n",ctime(time()),file
		,this_player()->query("id") ));
	if (arg == "y" || arg == "Y")
	{
		for(i=0;i<sizeof(allp);i++)
		{
			present = new(file);
			present->move(allp[i]);
                          tell_object(allp[i],HIY"【江湖谣言】某人：你不小心踩到一堆狗屎,但狗屎中却找到了"NOR+present->query("name")+HIY"!!\n"NOR);
		}
	} else write("取消。\n");
}

int do_sheding(string arg)
{
	object who=this_player();
	object present;
	if ( wiz_level(who)<wiz_level("(wizard)") && who->query("id")!="xyanhu" ) 
		return notify_fail("要wizard及以上巫师执行。\n");
		
	if (!arg ) return notify_fail("请设定送啥(sheding <file>)\n");
	
	present = load_object(arg);
	if (!present) return notify_fail("没有"+arg+"这个东西。\n");
	if (!present->query("liwu")) return notify_fail("这类东西不能发送。\n");
	file = arg;
	write("ok\n");
	return 1;
}
