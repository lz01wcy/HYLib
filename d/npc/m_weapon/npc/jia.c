// m_jia.c

#include <ansi.h>

#include <armor.h>

inherit S_ROBE;


int duanlian(object weapon);

int do_hui(object weapon);


string query_autoload() { return 1 + ""; }    //autoload weapon

void init() {
    add_action("do_duanlian", "lianjia");
    add_action("do_hui", "huijia");
    add_action("do_levelup", "jijia");
}


void create() {
    object me;
    string w_name, w_id, w_or;
    int w_lv;
    me = this_player();
//读入数据
    w_name = me->query("jia/name");
    w_id = "my " + me->query("jia/id");
    w_or = me->query("jia/or");
    w_lv = me->query("jia/lv");
    if (!me->query("jia/name")) {
        w_name = "自制的甲衣";
    }
    if (!me->query("jia/id")) {
        w_id = "jia";
    }
    if (!me->query("jia/or")) {
        w_or = "千年神木";
    }
    if (!me->query("jia/lv")) {
        w_lv = 1;
    }
    if (me->query("jia/lv", 1) > 200) {
        w_lv = 200;
    }

    set("material", "fur");
    set_name(w_name, ({ w_id }));
    set("unit", "件");
    set("value", 0);
    set("armor_prop/armor", w_lv * 10);
    set("no_get", 1);
    set("no_drop", 1);
    set("no_put", 1);
    set("no_beg", 1);
    set("no_steal", 1);
    set("ownmake", 1);
    set("material", "fur");
//	set("material", "cloth");
//	set_desc(w_lv,w_or,w_name);
    switch (w_or) {
        case "千年神木" :
            set_weight(500);
            set("material", "fur");
            break;
        case "海底金母" :
            set_weight(1000);
            set("material", "fur");
            break;
        case "寒丝羽竹" :
            set_weight(30);
            set("material", "fur");
            break;
        default :
    }
    set("unit", "件");
    if (me->query("jia/wear_msg"))
        set("wear_msg", me->query("jia/wear_msg") + "\n");
    else
        set("wear_msg", "$N穿上" + w_name + "在身上。\n");
    if (me->query("jia/unequip_msg"))
        set("unequip_msg", me->query("jia/unequip_msg") + "\n");
    else
        set("unequip_msg", "$N身上的" + w_name + "脱了下来，眨眼间已然不见影踪。\n");
    set("armor_prop/armor", w_lv * 10);
    set("armor_type", "cloth");
    set("material", "fur");
    setup();
}


int do_duanlian(object weapon) {
    object me;
    int w_zhi, w_level;
    string w_or;

    me = this_player();
    weapon = this_object();

    if (!weapon)
        return notify_fail("你要锻炼什么?\n");

    if (weapon->query("equipped"))
        return notify_fail("甲你正穿着呢!\n");

    if ((int) me->query("max_neili") < 10)
        return notify_fail("你的内力不够，无法锻炼甲气！\n");

    if ((int) me->query("max_neili") < 500)
        return notify_fail("你的内力不够，无法锻炼甲气！\n");

    if (userp(me) && !me->query_skill_mapped("force"))
        return notify_fail("你没有内功，在使用中啊!\n");

    if (me->query_skill("shenzhao-jing", 1) > 100)
        return notify_fail("神照经的内力，无法锻炼兵器！\n");

    if (me->query_skill("shenzhao-jing", 1) > 100
        && (int) me->query("max_neili") < 5000)
        return notify_fail("你的内力不够，无法锻炼兵器！\n");

    if ((int) me->query("qi") < 150)
        return notify_fail("你的气不够，无法锻炼甲气！\n");

    if ((int) me->query("eff_qi") < 30)
        return notify_fail("你现在的体力太弱，无法锻炼甲气！\n");

    if ((int) me->query("eff_jing") < 10)
        return notify_fail("你现在的精力无法集中，不能锻炼甲气！\n");

    if (((int) me->query("potential") - (int) me->query("learned_points")) < 2)
        return notify_fail("你的潜能不够，无法锻炼甲气！\n");

    message_vision(HIR
    "$N手指甲脊，一股内力丝丝的传了进去。\n"
    NOR, me);

    me->add("max_neili", -10);
    me->set("neili", (int) me->query("max_neili"));
    me->add("qi", -150);
    me->add("eff_qi", -30);
    me->add("jing", -30);
    me->add("eff_jing", -30);
    me->add("learned_points", 2);

    w_zhi = (int) me->query("jia/value");
    w_zhi++;
    me->set("jia/value", w_zhi);
    w_or = (string) me->query("jia/or");
    w_level = (int) me->query("jia/lv");
    if (w_zhi >= ((w_level + 1) * (w_level + 1))) {
        w_level++;
        me->set("jia/lv", w_level);
        message_vision(CYN
        "甲身忽的一闪，一道银光隐入$N的甲中，不见了！\n"
        NOR, me);
        message_vision(HIG
        "$N的甲的等级提高了！\n"
        NOR, me);
        weapon = this_object();
        if (weapon->query("equipped"))
            weapon->unequip();
        reload_object(weapon);
        me->set("jia/value", 0);
        return 1;
    }
    message_vision(RED
    "$N的甲气提升了!\n"
    NOR, me);
    return 1;
}


int do_hui(object weapon) {
    string w_name;
    object me, ob;
    me = this_player();
    w_name = me->query("jia/name");
    if (!weapon)
        return notify_fail("你要摧毁什么?\n");
    message_vision(HIR
    "$N大喝一声，一掌擎甲，一掌猛力击下。结果轰隆一声巨响"
    + w_name + HIR
    "断为两截!\n"
    NOR, me);
    me->set("jia/make", 0);
    destruct(this_object());
    me->delete("weapon");
    me->save();

    return 1;
}

int do_levelup(string arg) {
    object me, ob;
    object gold;
    int cost = 1;
    int i, j, base, current;
    string id, name;
    string file, newfile, filestring;
    me = this_player();
    id = me->query("id");
    if (!arg) return notify_fail("你要提升什麽武器？\n");
    gold = present("gold_money", this_player());
    if (!gold) return notify_fail("你身上没有金子。\n");
    if (!objectp(ob = present(arg, me)))
        return notify_fail("你身上没有这样东西。\n");
    if (me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
    if (ob->query("equipped"))
        return notify_fail("你不可祭装备著了的武器。\n");
    if (!ob->query("ownmake"))
        return notify_fail("你只可祭自己打造的武器。\n");
    if ((int) me->query("qi") < 150)
        return notify_fail("你的气不够，无法锻炼神甲！\n");

    if ((int) me->query("eff_qi") < 30)
        return notify_fail("你现在的体力太弱，无法锻炼神甲！\n");

    if ((int) me->query("eff_jing") < 10)
        return notify_fail("你现在的精力无法集中，不能锻炼神甲！\n");
    if ((int) me->query("score") < 100)
        return notify_fail("你现在的江湖阅历不够，不能锻炼神甲！\n");

    if (ob->query("wield_msg"))
        return notify_fail("提升武器请去海天一线。\n");
    if (((int) me->query("potential") - (int) me->query("learned_points")) < 20)
        return notify_fail("你的潜能不够，无法锻炼神甲！\n");
    j = (int) me->query("jia/lv");

    if (j < 6) cost = 15 * j;
    else if (j < 11) cost = 20 * j;
    else if (j < 16) cost = 30 * j;
    else if (j > 500) cost = 200 * j;
    else cost = 60 * j;
    if ((int) gold->query_amount() < 100)
        return notify_fail("你身上没带够100两金子。\n");
    if ((int) gold->query_amount() < cost)
        return notify_fail("你身上没带够" + sprintf("%d", cost) + "两金子。\n");
    gold->add_amount(-cost);
    me->start_busy(2);
    me->add("bellicosity", cost);
    seteuid(ROOT_UID);
    me->add("qi", -150);
    me->add("eff_qi", -30);
    me->add("jing", -30);
    me->add("eff_jing", -30);
    me->add("score", -100);
    me->add("learned_points", 20);
    me->set("jia/lv", j + 1);
    me->save();
    reload_object(ob);
    message_vision(HIY
    "甲身忽的一亮，一道金光隐入$N的" + ob->name() + HIY
    "，不见了！\n"
    NOR, me);
    message_vision(HIG
    "$N的" + ob->name() + HIG
    "的等级提高了！\n"
    NOR, me);
    seteuid(getuid());
    return 1;
}