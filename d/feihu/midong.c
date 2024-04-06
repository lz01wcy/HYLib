//闯王宝藏
//by steel
#include "ansi.h"
//#include <mimi.h>
inherit ROOM;
void create()
{
     set("short",HIR"闯王宝藏"NOR);
     set("long",@LONG
     你走进了一个密洞,洞内异常的干燥,四周光线昏暗,地上有几具骷髅,
周围散落着一些兵刃,显然这些人死前搏斗过。洞南边的石壁(bi)上似乎
刻着几行小字。洞的北壁上好象有个转盘(pan)似的。
LONG
       );                 
     set("item_desc",([
        "bi":HIB"余自起事以来，纵横天下十数载，誓杀天下之污吏。后苟居帝\n"
"位，然不意用人不淑，以至满人犯吾华夏，心何憾哉！乃遣密臣藏宝于此\n"
"以备东山再起之用，然不知吾能再斩满狗于漠北否。天若亡我，如之奈何!\n"
"此间金银，皆取于中原之豪富，不可谓之不义。后世小子进得此洞，可尽\n"
"取之，以济天下。若存私窥之心，必遭天遣！\n"NOR,
   ]) ); 
    set_temp("breaken",0); 
    set("objects",([
          __DIR__"npc/corpse":5,
    ]) ); 
  setup();        
}

void init()
{
   add_action("do_break","break");
   add_action("do_turn","turn");
}

int do_break(string str)
{
   object ob;//room,gold
   ob=this_player();  
   if(!str||str!="bi") return 0; 
   if(this_object()->query_temp("breaken")) return notify_fail("石壁已破!\n");
   if((int)ob->query("neili")<5000)
   {
     message_vision(HIR"结果只听一声闷哼，$N被石壁的反弹力震得眼前一黑....\n"NOR, this_player());
                this_player()->set("neili",0);
                this_player()->unconcious();
        return 0; 
   }
   this_object()->set_temp("breaken",1);
   message_vision(HIW"$N只听一声轰响，石壁被捅穿了，原来里面有一个大洞\n"NOR, this_player());
if((int)this_player()->query("闯王")<1){
this_player()->add("combat_exp",5000);
this_player()->set("闯王",1);
}
    this_object()->set("exits/south", __DIR__"midong2");
   
    this_player()->add("neili",-1000);

  return 1;
}
int do_turn(string arg)
{
    object ob;
    ob=this_player();
    if(!arg) return 0;
    if(arg=="pan"){
    this_object()->set("exits/up",__DIR__"bingya");
    message_vision(YEL"$N听见轧轧声响，头顶上露出个大洞!\n"NOR,ob);
    call_out("close",5);
    return 1;
    }
}
int close()
{
   this_object()->delete("exits/up");
   write(YEL"你听见轧轧声响，大洞又合上了!\n"NOR);
   return 1;
}

