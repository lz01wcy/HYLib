// skybook.c

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;


void create()
{
        set_name(HIY"无字天书"NOR, ({"skybook","book"}) );
        set_weight(10);
        set("no_steal", 1);
        set("no_beg", 1);
        set("no_get", 1);
        set("no_drop","哇？天书都想丢掉,小心遭天谴。\n\n");
        set("long",@LONG
此乃当年仙人赠于"蛋生"的宝物,因为蛋生不识字,仙人施了法,
把天书变成了无字天书,呵呵!就是文盲也能读懂,快看看(kan)吧！
LONG );
        if( clonep() )
                        set_default_object(__FILE__);
        else
       {
                set("treasure",1);set("unit", "本");
                set("material", "unknow");
        }
}

