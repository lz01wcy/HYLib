//Cracked by Roath
// rose.c
#include <ansi.h>

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIC "马蹄莲" NOR, ({"mati lian", "ma"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一朵绽放着的马蹄莲，代表着永结同心，吉祥如意，圣洁虔诚。\n");
		set("unit", "朵");
		set("value", 35000);
		set("base_unit", "朵");
        set("base_weight", 100);
	set("flower_w",1);
			}
	set_amount(1);
}
#include "flower.h"