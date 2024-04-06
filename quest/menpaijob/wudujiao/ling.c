// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(9)+3;
void create()
{
        set_name("五毒教令旗", ({ "wd lingqi"}));
        set("long", "一面五毒教令旗,有了它的弟子一般负责迎击任务yingji");
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("value", 0);
                set("unit", "面");
        }
        setup();
}

void init()
{
        add_action("do_shouzhang","yingji");
}
int do_shouzhang()
{
object ob,me=this_player();
string targ;
object obj;
int maxpot;
if (!environment(me))  return notify_fail("这里不是要你迎击的地方!\n");
if (environment(me)->query("short") !=me->query_temp("wdhwjob"))
return notify_fail("不是叫你到"+me->query_temp("wdhwjob")+"去迎击吗!\n");
if(!me->query_temp("wdhw"))
return notify_fail("你不能用这令旗做任务。\n");
if (this_object()->query("usename")!=me->query("name"))
return notify_fail("这不是你的令旗!!\n");

        if (me->is_busy())
        {
          tell_object(me,"你正忙着呢！\n");
          return 1;
        }
	if( me->is_fighting() )
        {
          tell_object(me,"等打完了，再说吧，！\n");
          return 1;
        }

        if ((me->query("jing") < 50))
        {  
          tell_object(me,"你的精力不能集中！\n");
          return 1;
        }
        if ((me->query("qi") < 50 ))
        {
          tell_object(me,"你的身体状态太差!\n");
          return 1;
        }

message_vision(HIY"\n$N在"+me->query_temp("wdhwjob") + "威风的一站，迎击敌人!\n"NOR,me);
me->add("jing",-10);
me->add("qi", -5);
me->start_busy(1);
me->add_temp("wdjob",1);
if( !environment(me)->query("no_fight"))
{
if (random(10)>7)
{
obj=new(__DIR__"taishan"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"泰山派弟子"NOR);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIR"$N说道：今天我们五岳剑派要消灭你们这些邪魔歪道！\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
else if (random(10)>7)
{
obj=new(__DIR__"henshan"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIG"衡山派弟子"NOR);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIR"$N说道：今天我们五岳剑派要消灭你们这些邪魔歪道！\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
else if (random(10)>7)
{
obj=new(__DIR__"hengshan"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"恒山派弟子"NOR);     
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIR"$N说道：今天我们五岳剑派要消灭你们这些邪魔歪道！\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
}
if (me->query_temp("wdjob") >i && 
!me->is_fighting())
{
message_vision(HIW"$N迎击任务时间已经到了，你的任务完成了。\n"NOR,me);
message_vision(HIG"$N任务完成，把令旗交给了别的弟子。\n"NOR,me,ob); 
me->start_busy(5);
call_out("destroying", 0, me);                       
}

        return 1;
}
void destroying(object me)
{   
int exp,pot;
if (!me) return;
exp=120+random(81);
pot=80+random(51);
	   tell_object(me,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战经验\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);

        me->delete_temp("wdjob");
        me->delete_temp("wdhw");
        me->delete_temp("wdhwjob");
	me->add("combat_exp",exp);
	me->add("potential",pot);

        destruct(this_object());
}