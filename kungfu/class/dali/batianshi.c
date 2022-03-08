// batianshi.c 巴天石

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create() {
    set_name("巴天石", ({ "ba tianshi", "ba" }));
    set("title", "大理司空");
    set("long", "他是大理国三公之一。一个又瘦又黑的汉子，但他的擅长轻功。\n");
    set("gender", "男性");
    set("age", 40);
    set("class", "officer");
    set("attitude", "friendly");
    set("shen_type", 1);
    set("str", 25);
    set("int", 25);
    set("con", 25);
    set("dex", 30);

    set("max_qi", 1500);
    set("max_jing", 500);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 100);
    set("combat_exp", 500000);
    set("score", 200000);

    set_skill("force", 80);
    set_skill("dodge", 120);
    set_skill("parry", 80);
    set_skill("cuff", 75);
    set_skill("sword", 70);
    set_skill("staff", 70);
    set_skill("kurong-changong", 70);
    set_skill("tiannan-step", 120);
    set_skill("jinyu-quan", 75);
    set_skill("duanjia-sword", 70);
    set_skill("literate", 80);

    map_skill("force", "kurong-changong");
    map_skill("dodge", "tiannan-step");
    map_skill("sword", "duanjia-sword");
    map_skill("staff", "duanjia-sword");
    map_skill("parry", "duanjia-sword");
    map_skill("cuff", "jinyu-quan");
    prepare_skill("cuff", "jinyu-quan");
    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
    add_money("silver", 20);

    create_family("大理段家", 19, "武将");
}

