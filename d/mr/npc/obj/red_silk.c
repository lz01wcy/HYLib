// /u/beyond/mr/obj/red_silk.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
        set_name(RED"红丝巾"NOR, ({ "red silk", "silk" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一条如烟如雾的红丝巾，放在手上有一种若有若无的感觉。\n");
		set("unit", "条");
                set("value", 0);
                set("material", "cloth");
                set("armor_type", "cloth");       
                set("armor_prop/armor", 5);
                
        }
setup();
}
