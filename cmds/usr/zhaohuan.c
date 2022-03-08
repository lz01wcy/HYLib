// 召唤随从 (by xbd)

#include <ansi.h>

inherit SKILL;

string *ns = ({
    "force",
            "dodge",
            "parry",
            "unarmed",
            "strike",
            "cuff",
            "finger",
            "claw",
            "hand",
            "leg",
            "sword",
            "blade",
            "whip",
            "hammer",
            "staff",
            "axe",
            "throwing",
            "literate",
            "shenzhao-jing",
});

object clone_guard(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg) {
    object ob;
    int load = 0;


    if (!me->query("guard/flag"))
        return notify_fail("凭你现在的条件，还没有资格拥有随从呢！\n");

    if (!me->query("guard/active"))
        return notify_fail("你现在还没有收过随从，如果需要的话，可以到无名居士那里去要一个！\n");

    if (me->query_condition("killer"))
        return notify_fail("通辑中，你无权使用。\n");

    if (me->is_busy())
        return notify_fail("你现在正忙。\n");
    if (me->query("neili") < 1000)
        return notify_fail("你的内力太低了，无法发出长啸。\n");

    if (me->query("jing") < 100)
        return notify_fail("你的精气太低了，无法发出长啸。\n");
    if (me->query("last_alert") > me->query("mud_age")) {
        me->set("last_alert", me->query("mud_age"));
    }
    if (!objectp(ob = me->query_temp("guard_ob"))) {
        if (!wizardp(me) && me->query("last_alert")
            && (me->query("mud_age") - me->query("last_alert")) < 900)
            return notify_fail(sprintf("你刚召唤过她，必须再过%d秒才能继续召唤！\n",
                                       900 + me->query("last_alert") - me->query("mud_age")));
        if (!objectp(ob = clone_guard(me)))
            return notify_fail("随从文件正在修改中，请稍候！\n");
        load = 1;
        me->set("last_alert", me->query("mud_age"));
        me->set_temp("guard_ob", ob);
    } else if (environment(me) == environment(ob))
        return notify_fail("她不是正在你身边吗？\n");
    else if (!living(ob))
        return notify_fail("以她目前的状态，怎么可能听你的命令呢？\n");
    else if (ob->is_busy())
        return notify_fail("她正忙着，无法接受你的召唤。\n");
    else if (!environment(ob))
        return notify_fail("以她目前的状态，怎么可能听你的命令呢？\n");

    me->add("neili", -500);
    me->add("jing", -50);
    me->start_busy(3);
    message_vision(HIM
    "$N纵声长啸，啸音忽高忽低，似乎是在打什么暗号。\n"
    NOR, me);
    if (!load) message("vision", HIG + ob->name() + "似乎听到了" + me->name() + "的呼唤，匆匆地离去了。\n"
    NOR, environment(ob));
    ob->move(environment(me));
    ob->set_leader(me);
    message_vision(HIG
    "$N隐隐听到一阵啸声和$P相互呼应，只转眼间$n就来到$N的身边。\n"
    NOR, me, ob);
    write(HIW
    "你现在可用指令："
    NOR
    "
    "HIW"
    set_name < 名字 > \t为她换名字
    set_long < 描述 > \t修改她的描述
    set_title < 称号 > \t修改他的称号
    ticks \t\t\t查看战斗指令阵列
    [1 - 5 < 指令 > ] \t设置战斗指令
    [-d
    1 - 5 | all] \t删除战斗指令
    注：一旦设定了指令阵列，预设的战斗模式将不起作用
    att < 某人 > \t\t攻击某人
    sha < 某人 > \t\t杀死某人
    ting \t\t\t停止战斗
    heji < 某人 > \t\t合击某人
    order[un]
    accept
    object
    设定[不]
    接受物品
    [un]
    accept
    fight \t设定[不]
    接受比武
    < 指令 > \t\t下达战斗指令
    control < 命令 > \t\t以天心通遥控执行某指令
    set
    save_me < 百分比 > \t设置气血小于多少启动自动保护
    hulian < 技能 > \t\t互练某武功
    taolun < 技能 > \t\t讨论某武功
    lianxi < 技能 > \t\t指导某武功
    mache < 地点 > \t\t叫马车去某地
    shape < ID > \t\t\t看状态\n
    "NOR);

    return 1;

}

object clone_guard(object me) {
    object ob, weapon;
    mapping status;
    string *ks;
    int i, n;

    if (me->query("guard/gender") == "girl")
        ob = new("/clone/guard/long2");
    else
        ob = new("/clone/guard/baoer");
    if (!ob) return ob;

    status = me->query("guard/status");
    if (mapp(status)) {
        ks = keys(status);
        for (i = 0; i < sizeof(status); i++)
            ob->set(ks[i], status[ks[i]]);
    }
    if (me->query("guard/gender") == "girl") {
        ob->set("id", me->query("id") + "'s shinu");
        if (!(stringp(me->query("guard/name"))))
            ob->set_name(me->name() + "的侍女", ({ me->query("id") + "'s shinu", "shi nu" }));
        else
            ob->set_name(me->query("guard/name"), ({ me->query("id") + "'s shinu", "shi nu" }));
    } else {
        ob->set("id", me->query("id") + "'s shitong");
        if (!(stringp(me->query("guard/name"))))
            ob->set_name(me->name() + "的侍童", ({ me->query("id") + "'s shitong", "shi tong" }));
        else
            ob->set_name(me->query("guard/name"), ({ me->query("id") + "'s shitong", "shi tong" }));
    }
    if (stringp(me->query("guard/long")))
        ob->set("long", me->query("guard/long"));
    if (stringp(me->query("guard/title")))
        ob->set("title", me->query("guard/title"));
    ob->set("possessed", me);
    ob->set("host_id", me->query("id"));
    ob->set("marry", me->query("id"));
    ob->set("couple/have_couple", 1);
    ob->set("couple/couple_name", me->name());
    ob->set("baohu", me->query("id"));

    ob->set("double_attack", me->query("double_attack"));
    ob->set("szj", me->query("szj"));

    ob->set("str", (me->query("str") > 50 ? 50 : me->query("str")));
    ob->set("int", (me->query("int") > 50 ? 50 : me->query("int")));
    ob->set("con", (me->query("con") > 50 ? 50 : me->query("con")));
    ob->set("dex", (me->query("dex") > 50 ? 50 : me->query("dex")));
    ob->set("kar", (me->query("kar") > 50 ? 50 : me->query("kar")));
//	ob->set("per", (me->query("per") > 50 ? 50 : me->query("per")));

    ob->set("combat_exp", (int) me->query("combat_exp") * 3 / 4);

    for (n = 0; n < 1000; n++)
        if (n * n * n / 10 >= ob->query("combat_exp"))
            break;
    ob->set_skills(me->query("guard/skills"));
    if (n < 10) n = 10;
    for (i = 0; i < sizeof(ns); i++)
        ob->set_skill(ns[i], n);
    if (!me->query_skill("literate", 1))
        ob->delete_skill("literate");
    else
        ob->set_skill("literate", me->query_skill("literate", 1));
    if (!me->query_skill("shenzhao-jing", 1))
        ob->delete_skill("shenzhao-jing");

    ob->set_learned(me->query("guard/learned"));
    ob->set_skill_map(me->query("guard/skill_map"));
    ob->set_skill_prepare(me->query("guard/skill_prepare"));

    ob->set("max_neili", (int) ob->query_skill("force") * 15);
    ob->set("neili", ob->query("max_neili"));
    ob->set("max_qi", (int) ob->query_skill("force") * 20);
    ob->set("eff_qi", ob->query("max_qi"));
    ob->set("qi", ob->query("max_qi"));
    ob->set("max_jing", (int) ob->query_skill("force") * 5);
    ob->set("eff_jing", ob->query("max_jing"));
    ob->set("jing", ob->query("max_jing"));
    ob->set("food", (ob->query("str") + 10) * 10);
    ob->set("water", (ob->query("str") + 10) * 10);

    if ((i = ob->query("combat_exp")) > 2000000)
        i = 200 + (i - 2000000) / 15000;
    else
        i = 200;
    ob->add_temp("apply/damage", i);
    ob->add_temp("apply/armor", i);

    if (ob->query("no_weapon"))
        i = 1;
    else
        i = 0;
    if (stringp(ob->query_skill_mapped("sword"))) {
        weapon = new("/clone/weapon/gangjian");
        weapon->move(ob);
        if (!i) weapon->wield();
        i = 1;
    }
    if (stringp(ob->query_skill_mapped("blade"))) {
        weapon = new("/clone/weapon/gangdao");
        weapon->move(ob);
        if (!i) weapon->wield();
        i = 1;
    }
    if (stringp(ob->query_skill_mapped("whip"))) {
        weapon = new("/clone/weapon/changbian");
        weapon->move(ob);
        if (!i) weapon->wield();
        i = 1;
    }
    if (stringp(ob->query_skill_mapped("hammer"))) {
        weapon = new("/clone/weapon/hammer");
        weapon->move(ob);
        if (!i) weapon->wield();
        i = 1;
    }
    if (stringp(ob->query_skill_mapped("staff"))) {
        weapon = new("/clone/weapon/gangzhang");
        weapon->move(ob);
        if (!i) weapon->wield();
        i = 1;
    }
    if (stringp(ob->query_skill_mapped("axe"))) {
        weapon = new("/clone/weapon/axe");
        weapon->move(ob);
        if (!i) weapon->wield();
        i = 1;
    }

    ob->change_combat_mode(me, ob->query("combat_mode"));

    return ob;
}

int help(object me) {
    write(@HELP
    指令格式 :
    zhaohuan

    这个指令可以用来召唤你的随从。

    HELP
    );
    return 1;
}
