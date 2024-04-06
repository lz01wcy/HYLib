#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"天下第一峰"NOR); 
        set("long", @LONG
这里便是天下第一峰――珠穆朗玛峰！！
天下群山，远方的大草原尽在脚下。白色的布达拉宫在骄阳下看来亮如纯银，但见
天蓝色的冰川，像彩缎一样，从峰顶向四面八方撒下去，镶嵌在洁白的山坡上。狂
风虽劲，冰雪骇人，但望着这大好山河，豪情在胸，壮志凌云，你顿生睥睨天下之
心，长啸连连，击掌放歌。
    想到得意之处便想对着群峰大喊(aload)：“天下武林，唯我独...
LONG); 
        set("type","street");
        set("exits",([
        "down":__DIR__"bingao",
        ]) );
	set("objects", ([
"quest/skills2/wakuang/kuang/kuangmai" : 6,
	]));          
        set("outdoors", "guanwai");
        set("no_death_penalty",1);
        set("coor/x",-1280);
        set("coor/y",-110);
        set("coor/z",888); 
        setup();
       
}     


void init()
{
	object ob;
	
	ob = this_player();
	remove_call_out("haoqing");
	call_out("haoqing",0,ob);

	add_action("do_aload", "aload");
}

void haoqing(object ob)
{
if (userp(ob))
{
	int imqi,ioqi;
		
	imqi = (int)ob->query("max_qi");
	ioqi = (int)ob->query("qi");
//	ob->receive_damage("qi", ioqi );
        if(ioqi < imqi) 
                 tell_object(ob,HIR"    忽然风云突变，风雪扑面而来！刹时寒刺骨，飞雪割面，\n"
                                     "你被冻得龇牙咧嘴、鼻涕直流，刚才的一番豪情壮志早被这副\n"
                                     "这副狼狈相清扫的踪迹全无了！\n"
                                     "    你只想找个避风处躲起来！\n"NOR);

	ob->improve_skill("dodge", 0.1 * (int)ob->query_skill("dodge", 1));        
}
}
		
int do_aload(string arg)
{
        object me;
        me = this_player();
	if( random((int)me->query_skill("force")) <= 180) 
	{
//		me->receive_damage("qi", 50);
//		me->receive_wound("qi",  50);
		message_vision(HIR"$N这一喊可了不得了，只见山蹦地裂，乾坤倒转...雪崩了！！！  啊...\n"NOR, me);
		switch ( random(2) )
		{
			case 0 :
				me->move(__DIR__"bingao0");
				break;
			case 1 	:
				me->move(__DIR__"bingao3");
				break;
		}
		tell_object(me, HIR"你随积雪一起从山上滚了下来，只觉得浑身无处不疼，在雪中无法喘息，重伤之下...\n"NOR);
		message("vision", HIR"只见" + me->query("name") + "从山上与崩塌的大雪一同骨碌碌地滚了下来，一头插在雪堆里只见两脚朝天，半天爬不起来！\n"NOR, environment(me), me);
		if((int)this_player()->query("qi")<250) this_player()->die();
       		else this_player()->unconcious();
		return 1;
	}
        if (!arg||arg!="天下武林，唯我独尊！") return notify_fail("你瞎喊什么？\n");
	message_vision(HIY
		"\n$N这一声喊过，天地为之动容，山风为之喝彩，想必$N将成就一番大事业！\n"NOR, this_player());
        if (me->query("shen") > 0)  me->set("shen",(int)me->query("shen") + 1000);
        else me->set("shen",(int)me->query("shen") - 1000);
	message_vision(HIC
		"\n$N感动了上天，神增加了！\n"NOR, this_player());
	return 1;
}
