// /kungfu/class/xueshan/gelunbu.c  葛伦布
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_fashi();
void create()
{
        set_name("卡内沛巴", ({ "kaneiba", "kaneiba" }));
        set("long",@LONG
卡内沛巴是雪山寺中护寺僧兵的副头领。同时向本寺第子传授武功。
身穿一件黑色袈裟，头带僧帽。
LONG
        );
        set("title", HIY "喇嘛" NOR);
        set("nickname", HIG "僧兵头领" NOR);
        set("gender", "男性");
        set("age", 30);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 200);
        set("int", 20);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 10000);
        set("max_jing", 5000);
        set("neili", 10000);
        set("max_neili", 1000);
        set("jiali", 20);
        set("combat_exp", 800000);
        set("score", 40000);

        set_skill("lamaism", 280);
        set_skill("literate", 130);
        set_skill("force", 180);
        set_skill("xiaowuxiang", 180);
        set_skill("dodge", 175);
        set_skill("shenkong-xing", 170);
        set_skill("parry", 160);
        set_skill("cuff", 100);
        set_skill("staff", 180);
        set_skill("xiangmo-chu", 370 );
        set_skill("unarmed", 160);
        set_skill("yujiamu-quan", 160);
        set_skill("sword", 160);
        set_skill("mingwang-jian", 160);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "xiangmo-chu");
        map_skill("staff", "xiangmo-chu");
        map_skill("sword","mingwang-jian");
        map_skill("unarmed","yujiamu-quan");


        create_family("雪山寺", 5, "喇嘛");
        set("class", "bonze");

        setup();

        carry_object("/d/xueshan/obj/b-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        carry_object("/d/xueshan/obj/senggun")->wield();

        add_money("silver",100);
}


void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "男性") {
                command("say 修习密宗内功需要纯阳之体。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }

        command("say 我就传你一些武功吧！");
        command("recruit " + ob->query("id"));

        if((string)ob->query("class") != "bonze")       {
                ob->set("title","雪山派俗家弟子");
        }
        else    {
                ob->set("title",HIY"小喇嘛"NOR);
        }
}
