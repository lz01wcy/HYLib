// yang-rou.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"yang rou", "rou"}));
        set_weight(900);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���ַ���������⡣\n");
                set("unit", "��");
                set("food_remaining", 3);
                set("food_supply", 40);
        }
}
