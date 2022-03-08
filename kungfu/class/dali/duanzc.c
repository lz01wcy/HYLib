// duanzc.c 段正淳

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_save();

string ask_duan();

string fenglu();

void create() {
    set_name("段正淳", ({ "duan zhengchun", "duan" }));
    set("title", "大理镇南王");
    set("long", "他就是大理国的镇南王，当今皇太弟，是有名的爱情圣手。\n");
    set("gender", "男性");
    set("age", 45);
    set("class", "officer");
    set("attitude", "friendly");
    set("shen_type", 1);
    set("str", 50);
    set("int", 50);
    set("con", 55);
    set("dex", 50);

    set("max_qi", 12500);
    set("max_jing", 11220);
    set("neili", 35000);
    set("max_neili", 35000);
    set("jiali", 100);
    set("combat_exp", 7000000);
    set("score", 300000);

    set_skill("unarmed", 200);
    set_skill("force", 200);
    set_skill("dodge", 200);
    set_skill("parry", 150);
    set_skill("cuff", 200);
    set_skill("strike", 150);
    set_skill("sword", 200);
    set_skill("staff", 150);
    set_skill("finger", 220);
    set_skill("finger", 280);
    set_skill("kurong-changong", 301);
    set_skill("tiannan-step", 280);
    set_skill("jinyu-quan", 280);
    set_skill("wuluo-zhang", 280);
    set_skill("duanjia-sword", 380);
    set_skill("yiyang-zhi", 280);
//        set_skill("sun-finger", 100);
    set_skill("literate", 200);
    set_skill("wuluo-zhang", 200);
    set_skill("feifeng-whip", 300);
    map_skill("unarmed", "yiyang-zhi");
    map_skill("force", "kurong-changong");
    map_skill("dodge", "tiannan-step");
    map_skill("finger", "yiyang-zhi");
    map_skill("cuff", "jinyu-quan");
    map_skill("strike", "wuluo-zhang");
    map_skill("parry", "yiyang-zhi");
    map_skill("sword", "duanjia-sword");
    map_skill("staff", "duanjia-sword");
    prepare_skill("cuff", "jinyu-quan");
    prepare_skill("strike", "wuluo-zhang");
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: perform_action, "finger.sandie" :),
        (: perform_action, "finger.dian" :),
        (: perform_action, "finger.jian" :),
        (: perform_action, "finger.qian" :),
        (: perform_action, "finger.sandie" :),
        (: perform_action, "sword.fenglei" :),
        (: perform_action, "sword.jingtian" :),
        (: perform_action, "sword.feilong" :),
        (: perform_action, "sword.ailao" :),
        (: perform_action, "sword.xswy" :) ,
        (: perform_action, "dodge.huadie" :),

        (: exert_function, "powerup" :),
        (: exert_function, "ku" :),
        (: exert_function, "rong" :),
    }));
    set("inquiry",([
    "段誉" : (: ask_duan :),
    "name": "你问这干嘛，我就是段正淳，难道你又是我情人生的孩子？",
            "here": "这里便是镇南王府。",
            "天龙寺" : "天龙寺是我段家武学的最高之地，不过，想拜天龙寺可不是那么容易的.",
            "营救" : (: ask_save :),
    "搭救" : (: ask_save :),
    "俸禄" :  (: fenglu :),
    ]));
    set_temp("apply/attack", 200);
    set_temp("apply/defense", 200);
    set_temp("apply/armor", 200);
    set_temp("apply/damage", 200);
    setup();
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/clone/misc/cloth")->wear();
    add_money("silver", 50);

    create_family("大理段家", 18, "镇南王");
}

void attempt_apprentice(object ob) {
    string oldtitle;
    oldtitle = ob->query("title");
    if ((int) ob->query_skill("kurong-changong", 1) < 100) {
        command("say 你的本门内功心法太低了，还是努努力先提高一下吧。");
        return;
    }
    if ((int) ob->query("shen") < 10000) {
        command("say 我大理段氏向来行侠仗义，您请回吧！");
        return;
    }
    oldtitle = ob->query("title");
    if (strsrch(oldtitle, "大理镇南王府") >= 0) {
        command("say 很好，既然入我门来就得忠心为主。");
        command("recruit " + ob->query("id"));
        ob->set("title", oldtitle);
    } else {
        command("say 你是何人，如此大胆，假冒我府中厮仆！");
        return;
    }
}

string ask_save() {
    object ob;
    int i, j;
    i = random(5) + 2;
    j = random(4) + 3;
    ob = this_player();
    if ((int) ob->query("shen") < 0)
        return ("我看" + RANK_D->query_respect(ob) + "面带阴邪之气，恐怕是四大恶人一伙的奸细。");
    if ((int) ob->query("combat_exp") < 400000)
        return ("四大恶人都是绝顶高手," + RANK_D->query_respect(ob) + "似乎武功不够，和四大恶人相斗会有性命之忧。");
    if (ob->query_temp("duanyu/find2"))
        return ("你怎么还不快去啊?时间紧迫！");
    if (ob->query_temp("duanyu/ask")) {
        ob->set_temp("duanyu/step", -i);
        ob->set_temp("duanyu/steps", j);
        ob->set_temp("duanyu/find2", 1);
        return ("既然" + RANK_D->query_respect(ob) + "有意相助，定会如虎添翼。居我得知，誉儿被四大恶人之首\n" +
                "段延庆囚在正在无量山附近的一座石屋内，只是路上十分险恶，之前为了探明路线，\n" +
                "我已损失好几名手下。你先去大理北面去无量山路上的一个小溪那里，向北行五里，\n" +
                "再向西行" + chinese_number(j) + "里，再向北行" + chinese_number(i) + "里，然后会到一座高山，再往后就要见机行事了。\n" +
                "段正淳说道：好了，准备一下，为了不惊动对方，切记要在晚上行动，路上小心。");
    } else return ("此话从何谈起？");
}

string fenglu() {
    object ob = this_player();
    mapping fam = ob->query("family");
    int gold;
    if (!fam || fam["family_name"] != "大理段家")
        return "这位" + RANK_D->query_respect(ob) + "不是我大理国的臣民，难道也想来拿大理的俸禄？";
    if (fam["master_name"] == "褚万里")
        return "这位" + RANK_D->query_respect(ob) + "在大理时间还太短，等过段时间才来拿吧。";
    if (ob->query("age") < 18)
        return "这位" + RANK_D->query_respect(ob) + "年龄太少了，等长大成人了再来吧!";
    if (ob->query("fenglu") && ob->query("fenglu") >= ob->query("age"))
        return "这位" + RANK_D->query_respect(ob) + "今年不是已经拿过俸禄了，怎么还想来拿？";
    ob->set("fenglu", ob->query("age"));
    command("pat " + ob->query("id"));
    message_vision(NOR
    "段正淳给了$N一些"
    HIY
    "黄金"
    NOR
    "。\n"
    NOR, ob);
    gold = (int) (ob->query_skill("kurong-changong", 1) * 25000);
    MONEY_D->pay_player(this_player(), gold);
    return "这是你一年的俸禄，这位" + RANK_D->query_respect(ob) + "好好干啊！";
}

string ask_duan() {
    object ob = this_player();
    if (ob->query("dali/meet_dy1") && ob->query("dali/pass")) {
        if (ob->query("family") && ob->query("family/family_name") == "大理段家") {
            ob->set_temp("duanyu/find4", 1);
            return ("小儿日前身体不适，和他叔父保定帝去天龙寺了。");
        } else return ("上次多亏" + RANK_D->query_respect(ob) + "相救，现在小儿业已康复，真是多谢" + RANK_D->query_respect(ob) + "了。");
    }
    if (ob->query("dali/fail") > 6)
        return ("这位" + RANK_D->query_respect(ob) + "还是算了，多谢" + RANK_D->query_respect(ob) + "鼎立相助，我看还是换别人试试吧。");
    if (ob->query_temp("duanyu/find1")) {
        ob->set_temp("duanyu/ask", 1);
        return ("小儿日前被四大恶人的南海鳄神掳走了，我们正在设法营救他，唉，求佛祖保佑! ");
    } else return ("小儿不爱学武，和我吵了几句就离家出走了，唉。。家门不幸啊! ");
}
