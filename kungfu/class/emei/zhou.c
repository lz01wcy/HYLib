// zhou.c 周芷若

#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int ask_zhang();
int ask_emei();

void create()
{
        set_name("周芷若", ({ "zhou zhiruo","zhiruo","zhou"}));
        set("long",
                "她是峨嵋派的第四代掌门弟子。\n"
                "一张脸秀丽绝俗。身着一身淡黄衣裳。\n"
                "略显清减的巧笑中带了些许无奈。\n"
                "她很寂寞。\n");
        set("gender", "女性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("class", "fighter");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
        }) );
        set("inquiry",([
                "剃度"    : "找我剃度？不对吧。",
                "出家"    : "要出家找我的师姐们去。",
                "还俗"    : "无聊。还俗也找我！",
                "赵敏"    : "不要问这个贱婢子！",
                "倚天剑"  : "师父把她交给纪师姊了。",
                "屠龙刀"  : "你想武林称雄？别做梦了。",
                "灭绝师太"  : "师父难得收徒。你先巴结我吧。",
                "张无忌"  : (: ask_zhang :),
                "光大峨嵋"  : (: ask_emei :),
        ]));
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("max_qi", 13500);
        set("jing", 12000);
        set("max_jing", 12000);
        set("neili", 13500);
        set("max_neili", 13500);
        set("jingli", 12000);
        set("max_jingli", 11000);

        set("combat_exp", 3500000);
        set("score", 1000);
        set_skill("persuading", 280);
        set_skill("force", 100);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("strike", 100);
        set_skill("sword", 100);
        set_skill("claw", 100);
        set_skill("literate", 100);
        set_skill("mahayana", 100);
        set_skill("jinding-zhang", 200);
        set_skill("jiuyin-baiguzhao", 300);
        set_skill("tiangang-zhi", 200);
        set_skill("huifeng-jian", 290);
        set_skill("zhutian-bu", 100);
        set_skill("linji-zhuang", 320);
        set_skill("feiyu-bian", 200);
        set_skill("bagua-dao", 180);
        set_skill("bagua-zhang", 180);

        set_skill("huixin-strike", 380);
        set_skill("piaoxue-hand", 380);
        set_skill("yinlong-whip", 380);
        set_skill("yitian-jian", 380);
        set_skill("whip", 220);
        set_skill("hand", 220);
        
        map_skill("force","linji-zhuang");
        map_skill("claw","jiuyin-baiguzhao");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        map_skill("whip","yinlong-whip");

	        map_skill("hand","piaoxue-hand");
        map_skill("strike","huixin-strike");
        map_skill("parry","yinlong-whip");
        map_skill("sword","yitian-jian");
        prepare_skill("strike", "huixin-strike");
        prepare_skill("hand", "piaoxue-hand");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "whip.duoming" :),
                (: perform_action, "whip.zhu" :),
                (: perform_action, "strike.cuixin" :),
                (: perform_action, "strike.gu" :),
                (: perform_action, "hand.yun" :),
                (: perform_action, "hand.zhao" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "juemie" :), 
        }) );

        create_family("峨嵋派", 4, "掌门弟子");

        setup();
        carry_object("/clone/weapon/changbian")->wield();
        carry_object("/d/emei/obj/ycloth.c")->wear();
}

void attempt_apprentice(object ob)
{

   if (ob->query("shen")<100)
   {
       command("heng");
       command("say " + ob->query("name") + "！你是什么东西？偷睹我面容，打扰我清修！");
       command("!!! " + ob->query("id"));
       kill_ob(this_player());
   }
   else
      if ( ob->query_temp("marks/宋夫人") )
      {

        if ((int)ob->query("per") < 22 )
        {
            command("giggle");
            command("say 这位"+RANK_D->query_respect(ob)+"容貌太也...，哎！还是请回吧！");
           return ;
        }
        if ((int)ob->query_dex() < 26  && (int)ob->query_int() < 28 )
        {
           command("say 这位"+RANK_D->query_respect(ob)+"恐怕资质差了一点。");
           command("say 不过尚大有潜力，还是先回去磨练磨练。");
           return ;
        }
        command("say" + ob->query("name") + "看你这么可怜，勉为其难收下你吧。\n");
        command("recruit " + ob->query("id"));
        ob->delete_temp("marks/宋夫人");
      } 
      else command("say " + this_player()->query("name") + "你没事就可以走了。\n\n");
   return;
}

int ask_zhang()
{
    object me=this_player();
    if( me->query_temp("jiuyin/emei") >= 2 ) {
        command("blush");
        command("say 虽然我已经发誓不再喜欢他，但他的影子无时无刻不出现在我的脑海里。");
        command("say 我终究不能欺骗自己，更不能欺骗师父，师傅教给我的倚天屠龙的秘密和光大我派的想法终究是不能实现了。");
        command("sigh");
        me->set_temp("jiuyin/emei", 3 );
        return 1;
    }
    return 0;
}

int ask_emei()
{
    object me=this_player();
    if( me->query_temp("jiuyin/emei") >= 3 ) {
        command("say 既然如此你到我师傅那里询问倚天屠龙的秘密吧。");
        command("say 光大峨嵋的希望只能寄托与你了。");
        command("sigh");
        me->set_temp("jiuyin/emei", 4 );
        return 1;
    }
    return 0;
}
