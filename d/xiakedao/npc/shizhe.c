//NPC /npc/shizhe.c

inherit NPC;
#include <ansi.h>

void greeting(object);
void init();

void create()
{
        set_name("黄衣使者", ( { "shi zhe", "zhe" }) );
        set("gender", "男性" );
        set("age", 30);
        set("long",
              "这是个身着黄衣的三十几岁汉子，手持木浆，面无表情。\n"
             );
        set("attitude", "friendly");
        set("shen_type", 1);

        set("str", 30);
        set("int", 39);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 330);
        set("max_jing", 320);
        set("neili", 300);
        set("max_neili", 300);

        set("combat_exp", 16000);
        set("score", 10000);

        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 50);

        set_temp("ling",0);
        set_temp("times",5);
        create_family("侠客岛", 2, "弟子");

        set("inquiry", ([
            "侠客岛" : "小人在这活了一辈子，还从没听说过。\n",
            "出海"   : "南边还有几艘船，你自己看看去吧！\n",
        ]));
        setup();
}

void init()
{
        object ob;

        ::init();

        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{

        if( !ob || environment(ob) != environment() ) return;
        say("黄衣使者说道：这位" + RANK_D->query_respect(ob)
                + "你把我叫过来，有什么事吗。\n");
             return;
}

int accept_object(object who, object ob)
{
    object ling1;
    object ling2;
    object room, myenv;
 
    if( !who || environment(who) != environment() ) return 0;
    if ( !objectp(ob) ) return 0;
    if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

    if ( (string)ob->query("id") != "shan pai"
         && (string)ob->query("id") !="e pai" )
    {
          return notify_fail("我不需要这件东西。\n");
    }
    if ( query_temp("times")==0 )
    {
          return notify_fail("我太累了，不想出海。\n");
    }
    if ( (string)ob->query("id") == "shan pai" )
    {
          if ( (string)ob->query_temp("own") != (string)who->query("id") )
          {
message_vision("这不是你的牌子。你这样欺骗我，不是想害我家破人亡吗？\n",who);
                return 0;
          }
          if (query_temp("ling")==2)
          {
message_vision("使者一看是赏善铜牌，满脸歉意地对$N说：上岛的铜牌共两块，你还缺一块罚恶铜牌。\n",who);
              return 0;
          }
          add_temp("ling",2);
          if(!( room = find_object("/d/xiakedao/duchuan")) )
              room = load_object("/d/xiakedao/duchuan");

          room = find_object("/d/xiakedao/duchuan");
          room->add_temp("pai",2);

          if( query_temp("ling")==2 )
          { message_vision("使者一看是赏善铜牌，满脸欣喜地对$N说：你还有一块罚恶铜牌吗？\n",who);
              return 1;
          }
     }

     if ( (string)ob->query("id") == "e pai" )
     {
          if ( (string)ob->query_temp("own") != (string)who->query("id") )
          {
message_vision("这不是你的牌子。你这样欺骗我，不是想害我家破人亡吗？\n",who);
              return 0;
          }
          if(query_temp("ling")==1)
          {
message_vision("使者一看是罚恶铜牌，满脸遗憾地对$N说：本岛铜牌一共两块，你还缺赏善铜牌。\n",who);
              return 0;
          }
          add_temp("ling",1);
          if(!( room = find_object("/d/xiakedao/duchuan")) )
              room = load_object("/d/xiakedao/duchuan");
          room = find_object("/d/xiakedao/duchuan");
          room->add_temp("pai",1);
          //command("say " +(string)room->query_temp("pai") +"haha");
          if( query_temp("ling")==1 )
          {
message_vision("使者一看是罚恶铜牌，满脸欣喜地对$N说：你还有赏善铜牌吗？\n",who);
              return 1;
          }
     }

     command("smile "+(string)who->query("id"));
     message_vision("原来是侠客岛的贵宾，这就随我上岛去吧。\n",who);
     ling1 = new("/d/xiakedao/obj/tongpai1");
     ling1->set_temp("own",who->query("id"));
     ling1->move(who);
     ling2 = new("/d/xiakedao/obj/tongpai2");
     ling2->set_temp("own",who->query("id"));
     ling2->move(who);
     set_temp("ling",0);
     add_temp("times",-1);
     myenv = environment (who) ;
     who->move("/d/xiakedao/duchuan");
     tell_room(myenv,
     "黄衣使者招了招手，一只小舟靠岸，"+who->query("name")+"跨步上船。\n");
     tell_object(who, BLU "你在海上航行了三天三夜.......\n"NOR);
     call_out("goto_xiake",10,who) ;
     return 1;
}

void goto_xiake(object ob)
{
     tell_object(ob , "大船终于停在了一个小岛边。你走下船来。\n" ) ;
     ob->move ("/d/xiakedao/haitan") ;
}
