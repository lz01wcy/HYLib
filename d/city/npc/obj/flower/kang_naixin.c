//Cracked by Roath
// rose.c
#include <ansi.h>

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIW "康乃馨" NOR, ({"kangnaixin", "kang"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一朵素净端立的康乃馨，代表温馨，真挚的情感。\n");
		set("unit", "朵");
		set("value", 35000);
		set("base_unit", "朵");
        set("base_weight", 100);
	set("flower_w",1);
			}
	set_amount(1);
}

#include "flower.h"