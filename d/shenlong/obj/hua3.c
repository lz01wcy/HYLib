inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR "断肠花" NOR, ({"hua3","duanchang"}));
        set("unit", "朵");
	set("long", "这是一朵断肠花,通体通红,鲜嫩欲滴,美丽异常。\n");
        set("no_get", "你根本不敢近前.\n");
        setup();
}

int do_eat(string arg)
{
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if(arg=="hua3") 
	{
		if(random(2)==0) this_player()->unconcious();
		else this_player()->die();
		destruct(this_object());
	}
	return 1;
}
