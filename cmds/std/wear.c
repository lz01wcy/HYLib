// wear.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("你要穿戴什么？\n");
   if (me->is_busy()) return notify_fail("你正忙着呢!\n");
	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wear(me, inv[i]) ) count ++;
		}
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经装备着了。\n");

	return do_wear(me, ob);
}

int do_wear(object me, object ob)
{
	string str;

	if( ob->query("id") == "jinsi jia" && me->query("age") >= 20)
		return notify_fail("你长大了，穿不上金丝甲了。\n");

	if( ob->query("female_only")
	&&      (string)me->query("gender") =="男性")
		return notify_fail("这是女人的衣衫，你一个大男人也想穿，羞也不羞？\n");

	if( ob->wear() ) {
		if( !stringp(str = ob->query("wear_msg")) )
			switch( ob->query("armor_type") ) {
				case "cloth":
				case "armor":
				case "boots":
					str = YEL "$N穿上一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "head":
				case "neck":
				case "wrists":
				case "finger":
				case "hands":
					str = YEL "$N戴上一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "waist":
					str = YEL "$N束起一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "wrists":
					str = YEL "$N套起一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "surcoat":
					str = YEL "$N扎起一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "shield":
					str = YEL "$N拿起一" + ob->query("unit") + "$n。\n" NOR;
					break;

				default:
					str = YEL "$N装备$n。\n" NOR;
			}
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
指令格式：wear <装备名称>
 
这个指令让你装备某件防具。
 
HELP
    );
    return 1;
}
