/*  <SecCrypt CPL V3R05>  */
 
//  Room:  /d/city/club3
inherit  ROOM;

void  create  ()
{
    set  ("short",  "聚义厅");
    set  ("long",  @LONG
这是一间宽敞明亮的大厅，厅的正中间是一根圆形的柱子。柱
子上贴满了各种广告：有换房的，有卖家具的，但其中最多的还是
找打牌搭档的广告。厅的东南西北各有个门，里面传出“拱啊！”
“毙了！”等的叫声。
LONG);

    set("light_up",  1);
    set("no_magic",  1);
    set("no_fight",  1);
    set("exits",  ([  /*  sizeof()  ==  2  */
        "down"  :  __DIR__"clubpoem",
        "north":  __DIR__"piggy",
        "south":  __DIR__"qishi",
        "east":  __DIR__"mj1",
    ]));
//       set("objects",  ([  //sizeof()  ==  1
//                __DIR__"obj/mj"  :  1,
//       ]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
