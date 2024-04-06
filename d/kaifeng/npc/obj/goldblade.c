// goldblade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("御赐金刀", ({ "goldblade", "dao", "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 100000);
		set("material", "gold");
		set("long", "这是一把御赐金刀,约一尺长,闪闪发着今.\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
		set("shaolin",1);
	}
	init_blade(1500);
	setup();
}
