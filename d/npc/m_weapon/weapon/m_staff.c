// m_staff.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
inherit S_WEAPON;

int duanlian(object weapon);

int do_hui(object weapon);


string query_autoload() { return 1 + ""; }    //autoload weapon

void init() {
    add_action("do_duanlian", "duanlian");
    add_action("do_hui", "hui");
}


void create() {
    object me;
    string w_name, w_id, w_or;
    int w_lv;
    me = this_player();
//读入数据
    w_name = me->query("weapon/name");
    w_id = "my " + me->query("weapon/id");
    w_or = me->query("weapon/or");
    w_lv = me->query("weapon/lv");
    if (!me->query("weapon/name")) {
        w_name = "自制的钢杖";
    }
    if (!me->query("weapon/id")) {
        w_id = "staff";
    }
    if (!me->query("weapon/or")) {
        w_or = "千年神木";
    }
    if (!me->query("weapon/lv")) {
        w_lv = 5;
    }
    if (me->query("weapon/lv", 1) > 150) {
        w_lv = 150;
    }
    set_name(w_name, ({ w_id }));
    set("unit", "柄");
    set("value", 0);
    set("no_put", 1);
    set("no_get", 1);
    set("no_drop", 1);
    set("no_beg", 1);
    set("no_steal", 1);
    set("ownmake", 1);
    set_desc(w_lv, w_or, w_name);
    switch (w_or) {
        case "千年神木" :
            set_weight(500);
            set("material", "iron");
            break;
        case "海底金母" :
            set_weight(1000);
            set("material", "steel");
            break;
        case "寒丝羽竹" :
            set_weight(30);
            set("material", "bamboo");
            break;
        default :
    }
    if (me->query("weapon/wield_msg"))
        set("wield_msg", me->query("weapon/wield_msg") + "\n");
    else
        set("wield_msg", "$N往背后一摸，掏出了一杆" + w_name + "握在手中。\n");
    if (me->query("weapon/unwield_msg"))
        set("unwield_msg", me->query("weapon/unwield_msg") + "\n");
    else
        set("unwield_msg", "$N手中" + w_name + "一挥，眨眼间已然不见影踪。\n");
    init_staff(w_lv * 10);
    setup();
}


int do_duanlian(object weapon) {
    object me;
    int w_zhi, w_level;
    string w_or;

    me = this_player();
    if (!weapon)
        return notify_fail("你要锻炼什么?\n");
    if (me->is_fighting())
        return notify_fail("你打着呢?\n");

    if (me->is_busy())
        return notify_fail("你忙着呢?\n");
    if ((int) me->query("max_neili") < 10)
        return notify_fail("你的内力不够，无法锻炼杖体！\n");

    if ((int) me->query("max_neili") < 500)
        return notify_fail("你的内力不够，无法锻炼兵器！\n");

    if (userp(me) && !me->query_skill_mapped("force"))
        return notify_fail("你没有内功，在使用中啊!\n");

    if (me->query_skill("shenzhao-jing", 1) > 100)
        return notify_fail("神照经的内力，无法锻炼兵器！\n");

    if (me->query_skill("shenzhao-jing", 1) > 100
        && (int) me->query("max_neili") < 5000)
        return notify_fail("你的内力不够，无法锻炼兵器！\n");

    if ((int) me->query("qi") < 150)
        return notify_fail("你的气不够，无法锻炼杖体！\n");

    if ((int) me->query("eff_qi") < 30)
        return notify_fail("你现在的体力太弱，无法锻炼杖体！\n");

    if ((int) me->query("eff_jing") < 10)
        return notify_fail("你现在的精力无法集中，不能锻炼杖体！\n");

    if (((int) me->query("potential") - (int) me->query("learned_points")) < 2)
        return notify_fail("你的潜能不够，无法锻炼杖体！\n");

    message_vision(HIR
    "$N手握杖端，一股内力丝丝的传了进去。\n"
    NOR, me);

    me->add("max_neili", -10);
    me->set("neili", (int) me->query("max_neili"));
    me->add("qi", -150);
    me->add("eff_qi", -30);
    me->add("jing", -30);
    me->add("eff_jing", -30);
    me->add("eff_jing", -30);
    me->add("learned_points", 2);

    w_zhi = (int) me->query("weapon/value");
    w_zhi++;
    me->set("weapon/value", w_zhi);
    w_or = (string) me->query("weapon/or");
    w_level = (int) me->query("weapon/lv");
    if (w_zhi >= ((w_level + 1) * (w_level + 1))) {
        w_level++;
        me->set("weapon/lv", w_level);
        message_vision(HIY
        "杖身忽的一亮，一道金光隐入$N的杖体，不见了！\n"
        NOR, me);
        message_vision(HIG
        "$N的杖的等级提高了！\n"
        NOR, me);
        weapon = this_object();
        if (weapon->query("equipped"))
            weapon->unequip();
        reload_object(weapon);
        me->set("weapon/value", 0);
        return 1;
    }
    message_vision(RED
    "$N的杖的硬度提高了!\n"
    NOR, me);
    return 1;
}


int do_hui(object weapon) {
    string w_name;
    object me, ob;
    me = this_player();
    w_name = me->query("weapon/name");
    if (!weapon)
        return notify_fail("你要摧毁什么?\n");
    message_vision(HIR
    "$N大喝一声，一掌擎杖，一掌猛力击下。结果轰隆一声巨响"
    + w_name + HIR
    "断为两截!\n"
    NOR, me);
    me->set("weapon/make", 0);
    destruct(this_object());
    me->delete("weapon");

    me->save();

    return 1;
}
/*void owner_is_killed()
{
        write(HIY"只见一声清脆的响声，"+query("name")+HIY"落在地上，断成数截。\n"NOR);
        this_object()->unequip();
        this_object()->reset_action();
        this_object()->set("name", query("name") + "的碎片");
        this_object()->set("value", 0);
        this_object()->set("weapon_prop", 0);
}*/

