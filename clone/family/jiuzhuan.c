// jiuzhuan.c 九转金丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY "九转金丹" NOR, ({ "jiuzhuan jindan", "dan" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗金色的仙丹，传说是太上老君"
                            "精心修炼的灵丹妙药。\n");
                set("value", 150000);
                set("unit", "颗");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        int effect;

/*
        log_file("static/using", sprintf("%s(%s) eat 九转金丹 at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));
*/

        effect = 0;
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
        if (me->query("gift/int/succeed") < 4 && random(2))
        {
                effect++;
                write(HIM "你觉得自己的头脑更清醒了。\n" NOR);
                me->add("gift/xiandan", 1);
                me->add("gift/int/succeed", 1);
                me->add("int", 1);
        }

        if (me->query("gift/dex/succeed") < 4 && random(2))
        {
                effect++;
                write(HIR "你觉得自己的腿脚更灵活了。\n" NOR);
                me->add("gift/unknowdan", 1);
                me->add("dex", 1);
                me->add("gift/dex/succeed", 1);
        }

        if (me->query("gift/con/succeed") < 4 && random(2))
        {
                effect++;
                write(HIC "你觉得自己的内息更通畅了。\n" NOR);
                me->add("gift/xisuidan", 1);
                me->add("con", 1);
                me->add("gift/con/succeed", 1);
        }

        if (me->query("gift/str/succeed") < 4 && random(2))
        {
                effect++;
                write(HIG "你觉得自己的膂力更强健了。\n" NOR);
                me->add("gift/shenliwan", 1);
                me->add("str", 1);
                me->add("gift/str/succeed", 1);
        }

        write(HIM "冥冥中你有所感悟。只觉得灵台一片空明，纯净无比。\n" NOR);
        me->add("magic_points", 1000 + random(1000));

        destruct(this_object());
        return 1;
}



