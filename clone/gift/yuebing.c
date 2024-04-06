// lingzhi.c 千年雪莲
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *nm1_jp =({
"五仁月饼","豆沙月饼","冰糖月饼","芝麻月饼","火腿月饼","花边月饼","老寿星月饼","果蔬月饼","冰皮月饼","酥皮月饼",
"茶叶月饼","椰奶月饼","海味月饼","药膳月饼","音乐月饼","迷你月饼","清真月饼","椰蓉月饼","水晶豆蓉月饼","葡萄软馅月饼",
"稻香村月饼","水晶月饼","人肉月饼","水果月饼",
});
string *nm2_jp =({
"yue bing","yue bing",
});
void create()
{
int i = random(sizeof(nm1_jp));
	set_name(order[random(13)]+nm1_jp[random(sizeof(nm1_jp))]+NOR,({nm2_jp[0]}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个漂亮的月饼。\n");
    set("no_give","每个人只有一个，你都这么大方！\n");
    set("value", 0);
    set("no_get","每个人只有一个，不要这么贪心！\n");
    set("no_drop","这么珍贵的东西你也扔？！\n");
set("liwu",1);
set("no_drop", 1);
set("no_put", 1);
    set("no_get", 1);
    set("no_give", 1);
set("no_steal",1);
set("no_beg",1);
set("eat",5);
    set("no_put",1);
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	int exp,pot,score;
object corpse;
        object me = this_player();
	if (!id(arg))
	return notify_fail("你要吃什么？\n");
	if (me->is_busy())
	return notify_fail("你正忙着呢？\n");

if (query("eat")>1)
{
message_vision(HIW "$N吃了一口"+query("name")+HIW"好吃极了!\n" NOR, me);
me->add("food",10);
me->start_busy(2);
add("eat",-1);
}
else
{
        this_player()->start_busy(50);

//	exp = 88888+random(8888);
	exp = 888+random(888);
	             pot = exp*2/3;
             score = random(20)+10;
        me->add("max_neili", 8);
        me->add("combat_exp", exp);
        me->add("potential", pot);
tell_object(me,HIY"你被奖励了：8点内力上限\n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);

        message_vision(HIW "$N吃下一个"+query("name")+HIW"好吃极了，只觉得体内真力源源滋生，你好像变了一个人似的!\n" NOR, me);
/*
if (me->query("weapon/lv") &&
(int)me->query("weapon/lv",1)<100)
{
  me->add("weapon/lv",2);
if (me->query("weapon/lv",1)>100)
me->set("weapon/lv",100);
message_vision(HIW"$N的自造武器等级增加了！重新登陆后有效!!\n"NOR, this_player());
}
if (me->query("jia/lv")&&
me->query("jia/lv",1)<150)
{
  me->add("jia/lv",2);
if (me->query("jia/lv",1)>150)
me->set("jia/lv",150);
message_vision(HIW"$N的自造甲衣等级增加了！重新登陆后有效!!\n"NOR, this_player());
}
me->delete("last_getzhen");
message_vision(HIW"$N再次获得拿银针的机会！\n"NOR, this_player());
*/
	destruct(this_object());
}
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
