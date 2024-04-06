// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(9)+3;
void create()
{
        set_name("凌霄灭敌令", ({ "lx lingpai"}));
        set("long", "一块凌霄灭敌令,有了它的弟子一般负责护卫任务huwei");
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("value", 0);
                set("unit", "块");
        }
        setup();
}

void init()
{
        add_action("do_shouzhang","huwei");
}
int do_shouzhang()
{
object ob,me=this_player();
string targ;
object obj;
int maxpot;
if (!environment(me))  return notify_fail("这里不是要你护卫的地方!\n");
if (environment(me)->query("short") !=me->query_temp("lxhwjob"))
return notify_fail("不是叫你到"+me->query_temp("lxhwjob")+"去护卫吗!\n");
if(!me->query_temp("lxhw"))
return notify_fail("你不能用这块令牌做任务。\n");
if (this_object()->query("usename")!=me->query("name"))
return notify_fail("这不是你的凌霄灭敌令!!\n");

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

message_vision(HIW"\n$N在"+me->query_temp("lxhwjob") + "来回走动，寻找敌人!\n"NOR,me);
me->add("jing",-10);
me->add("qi", -5);
me->start_busy(1);
me->add_temp("lxjob",1);
if( !environment(me)->query("no_fight"))
{
if (random(10)>7)
{
obj=new(__DIR__"shaolin"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIW"少林派弟子"NOR);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N狂笑道：今天我要见识见识你们凌霄城有什么厉害?\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
else if (random(10)>7)
{
obj=new(__DIR__"emei"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIG"峨嵋派弟子"NOR);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N狂笑道：今天我要见识见识你们凌霄城有什么厉害?\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
else if (random(10)>7)
{
obj=new(__DIR__"wudang"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"武当派弟子"NOR);     
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N狂笑道：今天我要见识见识你们凌霄城有什么厉害?\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
}
if (me->query_temp("lxjob") >i && 
!me->is_fighting())
{
message_vision(HIW"$N护卫时间已经到了，你的任务完成了。\n"NOR,me);
message_vision(HIG"$N任务完成，把令牌交给了别的弟子。\n"NOR,me,ob); 
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
pot=90+random(61);
	   tell_object(me,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战经验\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);
        me->delete_temp("lxjob");
        me->delete_temp("lxhw");
        me->delete_temp("lxhwjob");
 	me->add("combat_exp",exp);
	me->add("potential",pot);
        destruct(this_object());
}