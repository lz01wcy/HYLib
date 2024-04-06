// /u/beyond/mr/anbian3.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>

#define	SHIP_TO	__DIR__"hubian2"

inherit ROOM;
void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();
void create()
{	set("short",HIW"岸边"NOR);
	set("long", @long
这里是慕容家的家仆和丫鬟出入太湖的水上码头，只见人们来来往往，
一个个风尘仆仆，码头边的老船夫见到你走过来，马上笑呵呵的迎了上去。
湖面(humian)上有几只小舟正在游弋。
long);
        set("outdoors", "mr");
    set("exits",([
        "north" : __DIR__"houyuan1",
     ]));
    set("item_desc", ([
        "humian" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
    ]));

    set("outdoors", "suzhou");
    setup();
}

void init()
{
    add_action("do_yell", "yell");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"zhou4")) )
            room = load_object(__DIR__"zhou4");
        if( room = find_object(__DIR__"zhou4") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"zhou4");
                room->set("exits/out", __FILE__);
                message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
                    "板搭上堤岸，以便乘客\n上下。\n", this_object() );

                message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上"
                    "的阶梯。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "只听得湖面不远处隐隐传来：“别急嘛，"
                  "这儿正忙着呐……”\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "岸边一只小舟上的老艄公说道：正等着你呢，上来吧。\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向湖中驶去。\n",
        this_object() );

    if( room = find_object(__DIR__"zhou4") )
    {
        room->delete("exits/out");
       message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，扁舟向\n湖中驶去。\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"zhou4") )
    {
        room->set("exits/out", __DIR__"hubian2");
        message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板"
            "搭上堤岸。\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room, *ob;
	int i;

    if( room = find_object(__DIR__"zhou4") ) {
		tell_room(room, "艄公轻声说道：“都下船吧，我也要回去了。”\n", ({}));
		ob = all_inventory(room);
		for(i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i])) {
				if (!living(ob[i])) tell_room(room, "艄公把$N抬下了船。\n", ob[i]);
				else tell_room(room, "$N听了艄公的话，乖乖地下了船　\n", ob[i]);
				ob[i]->move(SHIP_TO);
				if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "被抬下了船。\n", ({ob[i]}));
				else tell_room(SHIP_TO, ob[i]->name() + "走下了船。\n", ({ob[i]}));
			}
		}
        room->delete("exits/out");
        message("vision","艄公把踏脚板收起来，把扁舟驶向湖中。\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
	string dir;
        object me = this_player();

	if (!arg) return 0;

	if (arg == "boat") arg = "船家";
	if (me->query("age") < 16 )
		message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n", me);
	else if (me->query("neili") > 500)
		message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传了出去。\n", me);
	else
		message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n", me);
	if( arg=="船家")
	{
		check_trigger();
		return 1;
	}
	else {
		message_vision("湖面上远远传来一阵回声：“" + arg + "～～～”\n", me);
		message_vision("忽然凌空飞来一脚，将$N踢了一个跟头，一个老艄公喝道：“此处禁止喧哗！”\n", me);
	}
	return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"zhou4") )
        room->delete("yell_trigger"); 
}

