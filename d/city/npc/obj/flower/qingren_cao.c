//Cracked by Roath
// rose.c
#include <ansi.h>

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIG "情人草" NOR, ({"qingren cao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一株蓬松轻盈，状如云雾的情人草，象征着爱意永恒。\n");
		set("unit", "株");
		set("value", 15000);
		set("base_unit", "株");
        set("base_weight", 100);
		set("flower_w",1);
			}
	set_amount(1);
}
#include "flower.h"