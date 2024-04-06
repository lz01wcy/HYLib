 // work.c
//#include "/feature/damage.c" 
inherit ROOM; 
void create()
{
        set("short", "石山");
        set("long", @LONG
这里的山峰多是光秃秃的，不同于江南黛青色秀丽的山峦，青灰色的山上只生
长着一些矮小的灌木，有些小山峰甚至被削去的一半，一路过来，山路两侧不时堆
集着刚采下来的巨型石料。一条小路顺着山势蜿蜒的伸向远方，路的尽头是一栋青
色的小石屋，石屋附近有家简陋的石庙，石屋前有一个水缸，想来是供过路的人解
渴的。
LONG
        ); 
    set("resource/water", 1);
    set("liquid/container", "水缸");    
    set("exits", ([ /* sizeof() == 1 */
                "southup" : __DIR__"stonemiao",
                "east" : __DIR__"work",
                "west" : __DIR__"stonehouse",
        ]));
    set("resource/water", 1);
    set("liquid/container", "水缸");    
    set("outdoors", "guanwai"); 
    set("coor/x",-1240);
        set("coor/y",-40);
        set("coor/z",0);
        setup();
}
/*void init()
{
        add_action("do_fillwater","fill");
}       
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir; 
        if( !arg || arg=="" ) return 0; 
        if( arg=="skin" || arg=="wineskin" || arg == "jiudai") {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "干净的食水",
                                "remaining": 5,
                                "drunk_apply": 0,
                        ]) );
                        write("你从水缸里装满了干净的食水！\n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？\n");
        }
        return 1;
}*/