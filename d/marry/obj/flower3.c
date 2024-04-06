//bosijv.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name(YEL "波斯菊" NOR, ({ "chrysanthemum","flower" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一朵娇艳美丽的波斯菊。\n");
                set("unit", "朵");
                set("value", 6);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
                set("female_only", 1);

        }
        setup();
}
