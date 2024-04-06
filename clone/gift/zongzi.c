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
"栗子粽子","鲜肉粽子","蛋黄粽子","香菇粽子","烤鸭粽子","香菇粽子","蛋黄粽子","米仁粽子","碱水粽子","豆沙粽子",
"赤豆粽子","白米粽子","火腿粽子","咸肉粽子","风鸡粽子","赤豆红枣粽","松仁白米粽","罗汉粽子","牛肉粽子","咖喱鸡粽子",
"冰皮粽子",
});
string *nm2_jp =({
"zong zi","zong zi",
});
void create()
{
int i = random(sizeof(nm1_jp));
	set_name(order[random(13)]+nm1_jp[random(sizeof(nm1_jp))]+NOR,({nm2_jp[0]}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个漂亮的粽子。\n");
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
        this_player()->start_busy(20);

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
	destruct(this_object());
}
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
