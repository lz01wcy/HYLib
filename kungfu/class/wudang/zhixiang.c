// zhixiang.c 制香道长

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("制香道长", ({ "zhixiang daozhang", "zhixiang", "daozhang" }));
        set("long",
                "他就是武当的制香道长。每天来武当烧香的人太多了，他和\n"
                "他手下的几个伐木道士都忙不过来了。\n"
                "他今年四十岁。\n");
        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 800);
        set("max_jing", 400);
        set("neili", 700);
        set("max_neili", 700);
        set("jiali", 30);
        set("combat_exp", 50000);
        set("score", 5000);

        set_skill("force", 70);
        set_skill("taiji-shengong", 60);
        set_skill("dodge", 70);
        set_skill("tiyunzong", 70);
        set_skill("unarmed", 70);
        set_skill("taiji-quan", 70);
        set_skill("parry", 70);
        set_skill("sword", 70);
        set_skill("wudang-jian", 60);
        set("inquiry", 
                ([
                        "job" :  "去松林小路附近找我师兄。\n",
                        "砍树" :  "去松林小路附近找我师兄。\n",
                        "伐木" :  "去松林小路附近找我师兄。\n",
                        "工作" : "去松林小路附近找我师兄。\n",
                        "干活" : "去松林小路附近找我师兄。\n",
                ]));

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");

        create_family("武当派", 3, "弟子");
        set("class", "taoist");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +
                        "你对我武当派尽了多少心力，有几分忠心呢？");
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，贫道就收下你了。");
        command("recruit " + ob->query("id"));
}
