// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(9)+3;
void create()
{
        set_name("维新文书", ({ "ft lingpai"}));
        set("long", "一张维新文书，一般负责守卫shouwei。");
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("value", 0);
                set("unit", "张");
        }
        setup();
}

void init()
{
        add_action("do_shouzhang","shouwei");
}
int do_shouzhang()
{
object ob,me=this_player();
string targ;
object obj;
int maxpot;
if (!environment(me))  return notify_fail("这里不是要你守卫的地方!\n");
if (environment(me)->query("short") !=me->query_temp("fthwjob"))
return notify_fail("不是叫你到"+me->query_temp("fthwjob")+"去守卫吗!\n");
if(!me->query_temp("fthw"))
return notify_fail("你不能用这张文书做任务。\n");
if (this_object()->query("usename")!=me->query("name"))
return notify_fail("这不是你的维新文书!!\n");

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

message_vision(HIY"\n$N在"+me->query_temp("fthwjob") + "站直立正，警惕的看着四周动像!\n"NOR,me);
me->add("jing",-10);
me->add("qi", -5);
me->start_busy(1);
me->add_temp("ftjob",1);
if( !environment(me)->query("no_fight")
&& random(3)==2)
{
obj=new(__DIR__"shiren"); 
obj->do_copy(me,maxpot,2);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N狂笑道：让你们见识是一下真真杀人的剑术?\n"NOR, obj);
me->start_busy(2);
me->kill_ob(obj);
obj->kill_ob(me);
}
if (me->query_temp("ftjob") >i && 
!me->is_fighting())
{
message_vision(HIY"$N守卫时间已经到了，你的任务完成了。\n"NOR,me);
message_vision(HIG"$N任务完成，把文书交给了别的弟子。\n"NOR,me,ob); 
me->start_busy(5);
call_out("destroying", 0, me);                       
}

        return 1;
}
void destroying(object me)
{   
int exp,pot;
if (!me) return;
exp=120+random(71);
pot=80+random(41);
	   tell_object(me,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战经验\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);
        me->delete_temp("ftjob");
        me->delete_temp("fthw");
        me->delete_temp("fthwjob");
 	me->add("combat_exp",exp);
	me->add("potential",pot);
        destruct(this_object());
}