//famu.c 武当伐木道士

inherit NPC;

void create()
{
        set_name("伐木道士", ({ "famu", "fa mu"}));
        set("long",
                "他是武当山的伐木道士。\n");
        set("gender", "男性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");

        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("dex", 25);

        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);

        set("combat_exp", 2000);
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);

        create_family("武当派", 4, "弟子");

        setup();

        carry_object("/d/wudang/obj/greyrobe")->wear();
}
