// /u/beyond/mr/duchuan2.c
// this is made by beyond
// update 1997.6.20
inherit ROOM;
void create()
{
	set("short", "渡船");
	set("long", @LONG
一叶小舟，最多也就能载七、八个人。一名六十多岁的老艄公
手持长竹篙，正在船尾吃力地撑着船。
LONG
	);
        set("no_fight",1);

	setup();
}
void run(object ob)
{
if(!ob) return;
       	if (environment(ob) == this_object())
       	ob->move(__DIR__"duchuan3", 1);
//	write("\n小船在荷花溏中缓缓而行,不一会你变看到小岛的轮廓了。\n\n");
}

void init()
{
       object ob = this_player();

    call_out("run", 10, ob);
}
