//ouyangfeng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create() {
    set_name("欧阳锋", ({ "ouyang feng", "ouyang", "feng" }));
    set("long", "他是白驼山庄主，号称“西毒”的欧阳锋。\n"
                + "由于习练「九阴真经」走火入魔，已变得精\n"
                + "神错乱，整日披头散发。\n");
    set("title", "白驼山庄主");
    set("gender", "男性");
    set("age", 53);
    set("nickname", HIR
    "西毒"
    NOR);
    set("shen_type", -1);
    set("shen", -150000);
    set("attitude", "peaceful");

    set("str", 60);
    set("int", 69);
    set("con", 60);
    set("dex", 68);

    set("qi", 19500);
    set("max_qi", 19500);
    set("jing", 16900);
    set("max_jing", 16900);
    set("neili", 58000);
    set("max_neili", 58000);
    set("jiali", 150);

    set("combat_exp", 9500000);
    set("score", 200000);
    set_skill("qixian-wuxingjian", 380);
    set_skill("cuff", 300);
    set_skill("cuff", 300);
    set_skill("lingshe-quan", 380);
    set_skill("zhaosheshu", 380);
    set_skill("yangsheshu", 380);
    set_skill("sword", 280);
    set_skill("force", 250);
    set_skill("unarmed", 250);
    set_skill("dodge", 250);
    set_skill("parry", 250);
    set_skill("strike", 320);
    set_skill("hand", 320);
    set_skill("training", 380);
    set_skill("staff", 250);
    set_skill("hamagong", 380);
    set_skill("chanchu-bufa", 380);
    set_skill("shexing-diaoshou", 380);
    set_skill("lingshe-zhangfa", 380);
    set_skill("hamashengong", 380);
    set_skill("xiyu-tiezheng", 380);
    set_skill("shentuo-zhang", 380);
    map_skill("strike", "hamagong");
    map_skill("force", "hamagong");
    map_skill("dodge", "chanchu-bufa");
    map_skill("unarmed", "shexing-diaoshou");
    map_skill("hand", "xiyu-tiezheng");
    map_skill("parry", "hamagong");
    map_skill("staff", "lingshe-zhangfa");
    prepare_skill("strike", "hamagong");
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: exert_function, "powerup" :),
        (: exert_function, "reserve" :),
        (: perform_action, "staff.saoluoye" :),
        (: perform_action, "staff.shewu" :),
        (: perform_action, "staff.shoot" :),
        (: perform_action, "staff.saoluoye" :),
        (: command("unwield shengzhang") :),
        (: command("wield shengzhang") :),
        (: command("zhaoshe") :),
        (: perform_action, "strike.hama" :),
        (: perform_action, "strike.puji" :),
        (: perform_action, "strike.tui" :),
        (: perform_action, "strike.zhen " :),
        (: perform_action, "hand.shewu" :),

    }));
    create_family("白驼山派", 1, "开山祖师");
    set("chat_chance", 2);
    set("chat_msg", ({
        "欧阳锋自言自语道：何日白驼山派才能重霸江湖呢…\n",
                "欧阳锋道：我儿欧阳克必能够重振白驼山派雄风！\n",
                "欧阳锋道：江湖险恶，困难重重哪！\n",
    }));
    set_temp("apply/attack", 200);
    set_temp("apply/defense", 200);
    set_temp("apply/armor", 600);
    set_temp("apply/damage", 650);
    setup();
    carry_object("/d/baituo/obj/shenshezhang")->wield();
    carry_object("/clone/misc/cloth")->wear();
    add_money("silver", 20);
}

void attempt_apprentice(object ob) {
    if ((int) ob->query("combat_exp") < 100000) {
        message_vision("欧阳锋对$N笑道：你的经验太低了,我还不能收你！\n", ob);
        return;
    }
    message_vision("欧阳锋拍拍$N的头，微微点了点头。\n", ob);
    command("recruit " + ob->query("id"));
    return;
}

