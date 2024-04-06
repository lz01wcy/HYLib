#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("萧秋水传奇上册"NOR, ({ "shangbook" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "本");
            set("no_put", 1);
            set("material", "paper");
            set("long", "一本由神书合并成的卷册，你可以用(chayue)来查阅它。另外如果你有。。。的话，可以用(try)试试\n");
          }

    setup();
}
void init()
{
   add_action("do_cha","chayue");
   add_action("do_try","try");
}
int do_cha()
{
	object me,corpse,ob;
	int exp,pot,score;
	me =this_player();
	exp = 3900+random(2900);
	             pot = exp*2/3;
             score = random(20)+50;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
     	      message_vision("$N仔细地查阅了一遍"+this_object()->query("name")+"。\n", me);
tell_object(me,"你被奖励了：\n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n");
if (random(3)==0)
{
        corpse=new("/clone/gem/gem");
if (corpse->query("level") >4
&& random(3)>0)
{
        corpse=new("/clone/gem/gem");
}


message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "通过神书任务找到了一颗"+corpse->query("name")+HIM"!"NOR"。\n", users());
             corpse->move(me);
}

if (random(3)==1)
{
        ob=new(__DIR__"sdan");
        ob->move(me);
message("channel:chat", HIC"【江湖传闻】"GRN + me->query("name")+"得到一颗"+HIY":" + ob->query("name")+HIG"啦！\n"NOR,users() );
}


	destruct(this_object());
return 1;
}
int do_try()
{
	object me,newbook,ob;
		object *inv;
	int sizeinv;
	me = this_player();
	newbook =new(__DIR__"zong");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你先把身上的人放下吧!!\n");
       		
		}
// if (!present("xiabook", me))
    if (!(ob = present("tfyizhan", me)) ||
        !(ob = present("sdmingbu", me)))
    return notify_fail("缺少四大名捕和唐方一战上的拼书方法!\n");

    if (!(ob = present("xiabook", me)) ||
        !(ob = present("tfyizhan", me))||
        !(ob = present("sdmingbu", me)))
	tell_object(me,"书好象没齐.\n");
   else{
        if( ob->query("ownmake"))
	return notify_fail("这里面有假货吧。\n");
        if(userp(ob))
	return notify_fail("这里面有假货吧。\n");
        if( ob->is_character() || ob->is_corpse() )
	return notify_fail("这里面有假货吧。\n");
        message_vision("$N试着把上下两册重新组合成一本，不料竟然成功了。\n", me);
	newbook->move(me);
	destruct(present("xiabook",me));
	destruct(present("tfyizhan",me));
	destruct(present("sdmingbu",me));
	destruct(this_object());}return 1;
}
