// zhuge.c
inherit NPC;
int ask_me();
#include <ansi.h>

void create()
{
        set_name("诸葛不亮", ({ "zhuge" }) );
        set("gender", "男性" );
        set("age", 35);
	 set("per", 30);
        set("long", "一位羽扇纶巾，仙风道骨的文士．\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
//      set("env/wimpy", 50);
	 set_skill("dodge", 80);
	 set_skill("unarmed",80);
	 set_skill("parry", 80);
	 set_skill("literate", 150);

  	set("chat_chance",10);
  	set("chat_msg",({
	WHT"诸葛不亮叹道：本人上知天文，下晓地理，有经天纬地之才，奈何无人知晓。唉......。\n"NOR,

//        (:random_move:)
    	}));
        setup();
        add_money("silver", 20);
set("inquiry", ([
"name": "在下乃诸葛武候之第二十三代孙诸葛不亮是也．\n",
"here": "此乃卧龙岗．乃我先祖读书之地也．\n",
"诸葛亮": "阁下怎好直呼我先祖名讳？\n",
"孔明先生": "此乃吾之先祖也，曾七擒孟获，平定了南疆。\n
故而阁下若去南疆，或许鄙人能助君一臂之力",
"瘴气": (: ask_me :),
"桃花峪": (: ask_me :),
"诸葛行军散": (: ask_me :),
]) );
        carry_object("/d/city/obj/cloth")->wear();
}
int ask_me()
{
 //       mapping fam; 
        object ob;
//        if ((this_player()->query("shen")) < -1000)
//              return notify_fail("这个么...,在下不知也。\n");
  
       command("say 苗疆桃花峪瘴气险恶异常，但若带有我先祖所创之《诸葛行军散》当可无恙。\n");
 command("say 这包药要随身携带，切末离身啊，切记，切记！");
        ob = new(__DIR__"obj/xingjunsan");
        ob->move(this_player());
         this_player()->start_busy(8);
 //       return "拿去吧。";
         return 1;
}
