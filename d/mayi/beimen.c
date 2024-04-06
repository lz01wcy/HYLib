inherit ROOM;
void create()	
{
	set("short", "北门");
	set("long", @LONG
这里是马邑的北门。由于马邑的经济多集中的城市南部，所以这里
显得非常冷清。正值战乱，所以这里的气氛更是悲凉。
LONG);
set("outdoors", "mayi");
set("exits", ([
                "south": __DIR__"center",
                "north" : "/d/dingxiang/xiaolu3", 
  	]));
set("objects",([
  __DIR__"npc/bing":2,
  __DIR__"npc/wujiang":1,
  ]));
       setup();
	replace_program(ROOM);
}	
