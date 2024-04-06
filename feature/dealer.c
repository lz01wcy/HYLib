// dealer.c 商人
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands
// Modify by Yu Jue 98-8-5

#include <dbase.h>

static mapping armor = ([]);
static mapping book = ([]);
static mapping misc = ([]);
static mapping weapon = ([]);

int query_goods_value(object goods, string method)
{
        object me = this_player();
        int value, trade_level;

        value = goods->query("value");
        trade_level = me->query_skill("trade", 1) / 5;
        if (trade_level > 40) trade_level = 40;
        if (method == "buy")
                value = value * (140 - trade_level) / 100;
        else if (method == "sell" || method == "value")
                value = value * (50 + trade_level) / 100;
        return value;
}

string is_vendor_good(string arg)
{
        string *goods;
        int i;

        if (arrayp(goods = query("vendor_goods"))) 
                for (i = 0; i < sizeof(goods); i++) 
                        if (goods[i]->id(arg)) return goods[i];
        return "";
}

int do_value(string arg)
{
        object ob;
        int value;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要估什么价？\n");

        if (ob->query("money_id"))
                return notify_fail("你没用过钱啊？\n");

        value = query_goods_value(ob, "value");
        if (value < 30)
                write(ob->name() + "一文不值！\n");
        else 
                write(ob->name() + "值" + MONEY_D->price_str(value) + "。\n");
        return 1;
}

int do_sell(string arg)
{
        object ob;
         object me = this_player();
        int value, value1, improve;
        object nob;
        string my_id;
        int amount;
        int res;
        int max_count;

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");
        if (!arg || !(ob = present(arg, me)))
                return notify_fail("你要卖什么？\n");


        if (ob->query("money_id"))
                return notify_fail("你想卖「钱」？\n");

	if (stringp(ob->query("no_drop")))
		return notify_fail("这样东西不能卖。\n");

//        if (ob->query("no_drop") || ob->query("no_get"))
//                return notify_fail("这样东西我买了怕卖不掉。\n");

        if (ob->query("ownmake"))
                return notify_fail("这样的宝物我可买不起。\n");

        if (query_temp("busy"))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

        if (is_vendor_good(arg) != "") 
                return notify_fail("我卖给你好不好？\n");


        value = ob->query("value");
        value1 = query_goods_value(ob, "sell");
        if (value < 30)
                write(ob->name() + "一文不值！\n");
        else if (value >= 1000000)
                write(ob->name() + "我们可买不起。\n");
        else {
         if (value < 200 || ob->query_amount()
         || ob->query("yaocao")
         || ob->query("food_supply")) {
                        message_vision("$N卖掉了一" + ob->query("unit") + 
                                ob->name() + "给$n。\n", me, this_object());
                        message_vision("$N把$n随手一扔，说道：这么个不值钱的玩意也拿来当。\n",
                                this_object(), ob);
                        destruct(ob);
                } else {
                        if (ob->move(this_object())) {
                                message_vision("$N卖掉了一" + ob->query("unit") + 
                                        ob->name() + "给$n。\n", me, this_object());
                                ob->set("no_get", 1);
                                if (ob->query("armor_type")) armor[base_name(ob)]++;
                                else if (ob->query("skill")) book[base_name(ob)]++;
                                else if (ob->query("weapon_prop")) weapon[base_name(ob)]++;
                                else misc[base_name(ob)]++;
                        }
                        else return notify_fail("我这货物已经太多了，暂时停止收购。\n");
                }
                MONEY_D->pay_player(me, value1);
                improve = 40 - me->query("pur");
                me->improve_skill("trade", improve / 2 + random(improve));
        }
        return 1;
}

int do_list(string arg)
{
        string *goods;
        mapping ptr;
        object *inv;
        int i, j, flag = 0;

        if (arrayp(goods = query("vendor_goods"))) {
                write("目前出售以下货物：\n");
                for (i = 0; i < sizeof(goods); i++)
                        printf("%30-s：%s\n", goods[i]->short(),
                                MONEY_D->price_str(query_goods_value((object)goods[i], "buy")));
                return 1;
        }

        switch (arg) {
                case "armor": arg = "护具"; ptr = armor; break;
                case "book": arg = "书籍"; ptr = book; break;
                case "misc": arg = "杂物"; ptr = misc; break;
                case "weapon": arg = "武器"; ptr = weapon; break;
                default: return notify_fail("您想看哪一种货物(armor, book, misc, weapon)？\n");
        }

        
        i = sizeof(ptr);
        if (!i)
                return notify_fail("目前没有可以卖的"+arg+"。\n");
        
        goods = keys(ptr);
        inv = all_inventory();
        while (i--) {
                j = sizeof(inv);
                while (j--) {
                        reset_eval_cost();
                        if (inv[j]->query("no_get") && goods[i] == base_name(inv[j])) {
                                if (!flag) write("目前出售以下"+arg+"：\n");
                                printf("%-30s 单价：%s\n", inv[j]->short(),
                                        MONEY_D->price_str(query_goods_value(inv[j], "buy") * 6 / 5));
                                flag = 1;
                                break;
                        }
                        if (j<0) map_delete(ptr, goods[i]);
                }
        }
        if (!flag) write("目前没有可以卖的"+arg+"。\n");
        return 1;
}

int do_buy(string arg)
{
        int i, val_factor = 5, improve;
        string ob_file;
        object *inv;
        object ob;
        mapping goods;
        int     amount;
        int     value;
	object *obs;
	string  my_id;
        string  start_room;
        object  room;
        mapping room_obmap;

        object me = this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");

        if (query_temp("busy"))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

        if (!arg) return notify_fail("你想买什么？\n");
        if (! query("carried_goods"))
        {
                if (stringp(start_room = query("startroom")) &&
                    (room = find_object(start_room)) != environment())
                {
                        // I am not in start room.
                        message_vision("$N大叫一声：“不好，我怎么跑到这儿来了？”\n"
                                       "说罢头也不回的急急忙忙的溜走了。\n", this_object());
                        if (! objectp(room) ||
                            ! mapp(room_obmap = room->query_temp("objects")) ||
                            member_array(this_object(), values(room_obmap)) == -1)
                        {
                                destruct(this_object());
                        } else
                                this_object()->move(room);
                        return 1;
                }
        }

        if (sizeof(filter_array(all_inventory(me), (: ! $1->query("equipped") :))) >= 40)
        {
                write("你身上的东西太多了，先处理一下再买东西吧。\n");
                return 1;
        }

        inv = all_inventory();
        i = sizeof(inv);
        if (i)
                while (i--) if (inv[i]->id(arg) && inv[i]->query("no_get")) { ob = inv[i]; val_factor = 6; break; }

        if (!ob) {
                if ((ob_file = is_vendor_good(arg)) == "")
                        return notify_fail("你想买的东西我这里没有。\n");
                else ob = new(ob_file);
        }

        if( (int)me->query_encumbrance() + ob->weight()
                > (int)me->query_max_encumbrance() ) 
        return notify_fail( me->name() + ":你已经拿不动了啊!\n");

        switch (MONEY_D->player_pay(me, query_goods_value(ob, "buy") *  val_factor / 5)) {
                case 0:
                        if (val_factor == 5) destruct(ob);
                        return notify_fail("穷光蛋，一边呆着去！\n");
                case 2:
                        if (val_factor == 5) destruct(ob);
                        return notify_fail("您的零钱不够了，银票又没人找得开。\n");
                default:
                        if (!ob->move(me)) {
                                if (val_factor == 5) destruct(ob);
                                return 0;
                        }
                        ob->delete("no_get");
                        message_vision("$N从$n那里买下了一" + ob->query("unit") +
                                ob->name() + "。\n", me, this_object());
                        improve = 40 - me->query("pur");
                        me->improve_skill("trade", improve / 2 + random(improve));
        }
        set_temp("busy", 1);
        call_out("delete_temp", 1, "busy");

        return 1;
}

/*void reset()
{
	int i;
	object *obs;

	obs = all_inventory();
        for (i = 0; i < sizeof(obs); i++)
                if (i >= 100 || obs[i]->query_weight() >= 1000000)
                        destruct(obs[i]);
}
*/