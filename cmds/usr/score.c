// score.c
#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string bar_string = "■■■■■■■■■■■■■■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□□□□□□□□□□□□□□";

string display_attr(int gift, int value);

string status_color(int current, int max);

string date_string(int date);

string tribar_graph(int val, int eff, int max, string color);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg) {
    object ob, obt;
    mapping my;
    string line, str, skill_type, zs, zs1, zs2;
    object weapon;
    int attack_points, dodge_points, parry_points, btmp, t, d, r, money, i, zs3, zs4;
    int a, b, c;
    seteuid(getuid(me));
    btmp = 1;
    if (!arg)
        ob = me;
    else if (wizardp(me)) {
        ob = present(arg, environment(me));
        obt = find_player(arg);
        if (!obt) btmp = 0;
        if (!ob) ob = obt;
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要察看谁的状态？\n");
    } else
        return notify_fail("只有巫师能察看别人的状态。\n");
    my = ob->query_entire_dbase();

    if (objectp(weapon = ob->query_temp("weapon")))
        skill_type = weapon->query("skill_type");
    else
        skill_type = "unarmed";

    attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
    parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
    dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
    if (ob->query("mud_age") > 86400) {
        t = ob->query("t");
        d = ob->query("d");
        r = ob->query("r");
    }
    write(HIC
    "≡" + HIY
    "───────────────────────────────"
    HIC
    "≡\n"
    NOR);
    write(NOR + RANK_D->query_rank(ob) + "" + ob->
    short(
    1)+"\n");
    write(HIY
    "────────────────────────────────\n"
    NOR);
    write(HIW
    "【"
    HIM
    "年岁"
    HIW
    "】"
    HIY + chinese_number(ob->query("age")) + "岁" +
    chinese_number((ob->query("mud_age") - (ob->query("age") - 14) * 86400) / 7200 + 1) + "月" + "\n");
    write(HIW
    "【"
    HIM
    "生日"
    HIW
    "】"
    HIY + CHINESE_D->chinese_date((ob->query("birthday") - 14 * 365 * 24 * 60) * 60 - 890000000) + "\n");
    write(HIW
    "【"
    HIM
    "性别"
    HIW
    "】"
    HIY + ob->query("gender") + "\n");
    if (ob->query("couple/couple_name")) {
        write(HIW
        "【"
        HIM
        "伴侣"
        HIW
        "】"
        HIY + ob->query("couple/couple_name") + "\n");
    } else write(HIW
    "【"
    HIM
    "伴侣"
    HIW
    "】"
    HIY + "无\n");
    if (mapp(my["family"])) {
        if (my["family"]["master_name"]) {
            write(HIW
            "【"
            HIM
            "师傅"
            HIW
            "】"
            HIY + my["family"]["master_name"] + "\n");
        } else write(HIW
        "【"
        HIM
        "师傅"
        HIW
        "】"
        HIY + "无\n");
    }
    if (mapp(my["family"])) {
        if (my["family"]["family_name"]) {
            write(HIW
            "【"
            HIM
            "师门"
            HIW
            "】"
            HIY + my["family"]["family_name"] + "");
            write(HIW
            "【"
            HIM
            "师门贡献"
            HIW
            "】"
            HIY + chinese_number(my["mpgx"]) + "\n");
        } else write(HIW
        "【"
        HIM
        "师门"
        HIW
        "】"
        HIY + "无\n");
    }

    zs = "无";
    zs1 = "无";
    zs2 = "";
    if (ob->query("zhuanshen"))
        zs = "一转";
    if (ob->query("guard/flag"))
        zs = "二转";
    if (ob->query("zhuanbest"))
        zs = "三转";
    if (ob->query("4zhuan"))
        zs = "四转";
    if (ob->query("5zhuan"))
        zs = "五转";
    if (ob->query("zhuanfinal/7"))
        zs1 = "【阴阳十二重天】";
    if (ob->query("zhuanfinal/8"))
        zs1 = zs1 + " 【不败神功】";
    if (ob->query("zhuanfinal/1"))
        zs2 = "【元气无穷】";
    if (ob->query("zhuanfinal/2"))
        zs2 = zs2 + " 【遁影擒踪】";
    if (ob->query("zhuanfinal/3"))
        zs2 = zs2 + " 【神魔金身】";
    if (ob->query("zhuanfinal/4"))
        zs2 = zs2 + " 【缚骨缠身】";
    if (ob->query("zhuanfinal/5"))
        zs2 = zs2 + " 【破元大法】";
    if (ob->query("zhuanfinal/6"))
        zs2 = zs2 + " 【国士无双】";
    zs3 = 6000000 + (ob->query("expmax", 1) * 500000);
    zs4 = ob->query_temp("menpaijob", 1);
    write(HIW
    "【"
    HIM
    "转身"
    HIW
    "】"
    HIY + zs + "");
    if (!ob->query("4zhuan")) {
        write("\n");


    }
    if (ob->query("4zhuan")) {
        write(HIW
        "【"
        HIM
        "连续任务"
        HIW
        "】"
        HIY + zs4 + "");
        write(HIW
        "【"
        HIM
        "武功上限"
        HIW
        "】"
        HIY + zs3 + "\n");
        write(HIW
        "【"
        HIM
        "转身武功"
        HIW
        "】"
        HIY + zs1 + "\n");
        write(HIW
        "【"
        HIM
        "转身技能"
        HIW
        "】"
        HIY + zs2 + "\n");


    }
    write(HIY
    "────────────────────────────────\n"
    NOR);
    write(HIW
    "【"
    HIM
    "臂力"
    HIW
    "】"
    HIY + display_attr(my["str"], ob->query_str()) + HIW
    "【"
    HIM
    "武器攻击"
    HIW
    "】"
    NOR + HIC + "(+" + ob->query_temp("apply/damage") + ")\n"
    NOR);
    write(HIW
    "【"
    HIM
    "悟性"
    HIW
    "】"
    HIY + display_attr(my["int"], ob->query_int()) + HIW
    "【"
    HIM
    "防具防御"
    HIW
    "】"
    NOR + HIC + "(+" + ob->query_temp("apply/armor") + ")\n"
    NOR);
    write(HIW
    "【"
    HIM
    "根骨"
    HIW
    "】"
    HIY + display_attr(my["con"], ob->query_con()) + HIW
    "【"
    HIM
    "杀死人数"
    HIW
    "】"
    NOR + HIR + chinese_number(my["MKS"] + my["PKS"]) + NOR + "\n"
    NOR);
    write(HIW
    "【"
    HIM
    "身法"
    HIW
    "】"
    HIY + display_attr(my["dex"], ob->query_dex()) + HIW
    "【"
    HIM
    "杀玩家数"
    HIW
    "】"
    NOR + HIR + chinese_number(my["PKS"]) + NOR + "\n"
    NOR);
    if (wizardp(me)) {
        write(HIW
        "【"
        HIM
        "福缘"
        HIW
        "】"
        HIY + display_attr(my["kar"], ob->query_kar()) + HIW
        "【"
        HIM
        "死亡次数"
        HIW
        "】"
        NOR + HIR + chinese_number(my["dietimes"]) + "\n"
        NOR);
    } else write(HIW
    "【"
    HIM
    "福缘"
    HIW
    "】"
    HIY + "???" + HIW
    "【"
    HIM
    "死亡次数"
    HIW
    "】"
    NOR + HIR + chinese_number(my["dietimes"]) + "\n"
    NOR);
    if (wizardp(me)) {
        write(HIW
        "【"
        HIM
        "容貌"
        HIW
        "】"
        HIY + display_attr(my["per"], ob->query_per()) + HIW
        "【"
        HIM
        "离奇死亡"
        HIW
        "】"
        NOR + HIR + chinese_number(my["dietimes"] - my["normal_die"]) + "\n"
        NOR);
    } else write(HIW
    "【"
    HIM
    "容貌"
    HIW
    "】"
    HIY + "???" + HIW
    "【"
    HIM
    "离奇死亡"
    HIW
    "】"
    NOR + HIR + chinese_number(my["dietimes"] - my["normal_die"]) + "\n"
    NOR);
    write(HIY
    "────────────────────────────────\n"
    NOR);
    write(HIW
    "【"
    HIM
    "精神"
    HIW
    "】"
    HIY + tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], HIC) + HIW
    "【"
    HIM
    "判师次数"
    HIW
    "】"
    NOR + HIB + chinese_number(ob->query("betrayer")) + NOR + "\n");
    write(HIW
    "【"
    HIM
    "气血"
    HIW
    "】"
    HIY + tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], HIR) + HIW
    "【"
    HIM
    "风度魅力"
    HIW
    "】"
    HIC + chinese_number(ob->query("meili")) + "\n");
    write(HIW
    "【"
    HIM
    "饮水"
    HIW
    "】"
    HIY + tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN) + HIW
    "【"
    HIM
    "江湖威望"
    HIW
    "】"
    HIC + chinese_number(ob->query("weiwang")) + "\n");
    write(HIW
    "【"
    HIM
    "食物"
    HIW
    "】"
    HIY + tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL) + HIW
    "【"
    HIM
    "江湖阅历"
    HIW
    "】"
    HIC + ob->query("score") + "\n");
    write(HIW
    "【"
    HIM
    "攻击"
    HIW
    "】"
    NOR + HIY + "/cmds/std/looksj.c"->getatt(ob, 1) + NOR + "\n");
    write(HIW
    "【"
    HIM
    "防御"
    HIW
    "】"
    NOR + HIY + "/cmds/std/looksj.c"->getdef(ob, 1) + NOR + "\n");
    write(HIW
    "【"
    HIM
    "躲闪"
    HIW
    "】"
    NOR + HIY + "/cmds/std/looksj.c"->getdog(ob, 1) + NOR + "\n");
    if (wizardp(me))write(HIW
    "【"
    HIM
    "攻击力"
    HIW
    "】"
    NOR + HIC + attack_points / 100 + 1 + "(+" + ob->query_temp("apply/damage") + ")\n"
    NOR);
    if (wizardp(me))write(HIW
    "【"
    HIM
    "防御力"
    HIW
    "】"
    NOR + HIC + (dodge_points + (weapon ? parry_points : (parry_points / 10))) / 100 + 1 + "(+" +
    ob->query_temp("apply/armor") + ")\n"
    NOR);
    write(HIY
    "────────────────────────────────\n"
    NOR);
    write(HIW
    "【"
    HIM
    "侠义正气"
    HIW
    "】"
    NOR + RED + ob->query("shen") + NOR
    "\n");
    write(HIW
    "【"
    HIM
    "学习潜力"
    HIW
    "】"
    NOR + HIY + (ob->query("potential") - ob->query("learned_points")) + NOR + "\n");
    write(HIW
    "【"
    HIM
    "实战经验"
    HIW
    "】"
    NOR + HIY + ob->query("combat_exp") + NOR + "\n");
    if (ob->query("killbyname") && ob->query("killbyname") != "死因不明") {
        write(HIW
        "【"
        HIM
        "上次死因"
        HIW
        "】"
        HIY + "被" + ob->query("killbyname") + "杀死\n");
    }
    if (ob->query("killbyname") && ob->query("killbyname") == "死因不明") {
        write(HIW
        "【"
        HIM
        "上次死因"
        HIW
        "】"
        HIY + "死因不明\n");
    }
    if (me->query("age") == 14) money = 100;
    if (me->query("age") > 14) money = 100 + (me->query("age") - 15) * 20;
    if (me->query("age") > 20) money = 200 + (me->query("age") - 20) * 20;
    if (me->query("age") > 30) money = 400 + (me->query("age") - 30) * 30;
    if (me->query("age") > 40) money = 800 + (me->query("age") - 40) * 40;
    write(HIW
    "【"
    HIM
    "存款上限"
    HIW
    "】"
    NOR + HIY + money + HIY + "两黄金" + "\n"
    NOR);
    if (!ob->query("killbyname")) {
        write(HIW
        "【"
        HIM
        "上次死因"
        HIW
        "】"
        HIY + "无\n");
    }
    if (ob->query_temp("temp_exp")) {
        if (ob->query("mud_age") - ob->query_temp("mud_age") > 1) {
            if (ob->query("combat_exp") > ob->query_temp("temp_exp")) {
                if ((i = (ob->query("combat_exp") - ob->query_temp("temp_exp")) * 60
                         / (ob->query("mud_age") - ob->query_temp("mud_age"))) > 100)
                    i = i * 60;
                write(HIW
                "【"
                HIM
                "成长速度"
                HIW
                "】"
                HIY + i + "/小时\n");
            }
        }
    }
    if (me->query_temp("apply/strength") > 800)
        me->set_temp("apply/strength", 800);
    if (me->query_temp("apply/intelligence") > 800)
        me->set_temp("apply/intelligence", 800);
    if (me->query_temp("apply/constitution") > 800)
        me->set_temp("apply/constitution", 800);
    if (me->query_temp("apply/dexerity") > 800)
        me->set_temp("apply/dexerity", 800);
    if (me->query_temp("apply/attack") > 800)
        me->set_temp("apply/attack", 800);
    if (me->query_temp("apply/defense") > 800)
        me->set("apply/defense", 800);
    if (me->query_temp("apply/damage") > 4000)
        me->set_temp("apply/damage", 4000);
    if (me->query_temp("apply/armor") > 4000)
        me->set_temp("apply/armor", 4000);
    if (me->query_temp("apply/dodge") > 800)
        me->set_temp("apply/dodge", 800);

    write(HIC
    "≡" + HIY
    "─────────────────────海 洋 II─────"
    HIC
    "≡\n"
    NOR);
    return 1;

}

string display_attr(int gift, int value) {
    if (value > gift) return sprintf(HIY
    "%3d"
    NOR, value );
    else if (value < gift) return sprintf(CYN
    "%3d"
    NOR, value );
    else return sprintf("%3d", value);
}

string status_color(int current, int max) {
    int percent;

    if (max) percent = current * 100 / max;
    else percent = 100;

    if (percent > 100) return HIC;
    if (percent >= 90) return HIG;
    if (percent >= 60) return HIY;
    if (percent >= 30) return YEL;
    if (percent >= 10) return HIR;
    return RED;
}

string tribar_graph(int val, int eff, int max, string color) {
    return color + bar_string[0..(val * 10 / max) * 2 - 1]
           + ((eff > val) ? blank_string[(val * 10 / max) * 2..(eff * 10 / max) * 2 - 1] : "") + NOR;
}

int help(object me) {
    write(@HELP
    指令格式 :
    score
    score<对象名称>(巫师专用)

    这个指令可以显示你(你)
    或指定对象(含怪物)
    的基本资料。
    基本资料的设定请参阅
    'help setup'。

    see
    also :
    hp
    HELP
    );
    return 1;
}
