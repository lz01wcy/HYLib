//   xuetong.c
//  by victori
inherit NPC;
void create()
{
        set_name("小学童", ({ "xue tong","tong" }) );
        set("gender", "男性" );
        set("age", 14);
	set("per", 30);
        set("long", "这是一个十三四岁的小童，正心不在焉的跟着先生胡乱念着．\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
//      set("env/wimpy", 60);
	set_skill("dodge", 5);
	set_skill("unarmed", 5);
	set_skill("parry", 5);
	set("max_qi", 200);

  	set("chat_chance",10);
  	set("chat_msg",({
        "只听小学童断断续续的念道：人之初...zzzz，性本....zzzzz，..~~~~。\n",
        "小学童摇头晃脑的跟着念道：蝈蝈鸠鸠，在河洲洲，窈窕是你，君子高逑。\n",
	"小学童自言自语道：生生死死，死死生生，先生先死，先死先生。\n",
	"小学童随声附和道：春眠不觉晓，所以睡懒觉,.....。\n",
 //       (:random_move:)
    	}));
        setup();
        add_money("coin", 50);
set("inquiry", ([
//        "name": "大家都叫我阿牛．平常上山打柴，有时也采些药材．\n",
//        "here": "此乃卧龙岗．听说山上有位卧龙先生．\n",
]) );
       carry_object("/d/city/obj/cloth")->wear();
}
