// wudu-yanluobu 五毒烟萝步
// inherit F_CLEAN_UP;
inherit SKILL;

#include <ansi.h>

mapping *action = ({
    ([    "action" : "$n不慌不忙，一式「江水横流」，身行倏的向一旁平移数尺,堪堪躲过了$N的功势。\n",
            "dodge"  : 20
    ]),
    ([    "action" : "$n身行如鬼魅般一晃，刹那间已远去数丈之外，$N顿时扑了个空。\n",
            "dodge"  : 40
    ]),
    ([    "action" : "$n身行忽的加快，如一缕青烟般绕着$N飞快旋转，看得$N一阵头晕眼花，\n急忙收招跳开。\n",
            "dodge"  : 60
    ]),
    ([    "action" : "$n怪异的一笑，身行忽的变得朦胧不清，$N的凌厉招式竟然透体而过，原来竟是一具幻影。\n",
            "dodge"  : 80
    ]),
    ([    "action" : "$n的身行顿时变得如蛇一般柔软，随着$N的招式左右摆动，竟使得$N招招落空。\n",
            "dodge"  : 100
    ]),
});

mapping query_action(object me, object weapon) {
    int zhaoshu, level;

    zhaoshu = sizeof(action);
    level = (int) me->query_skill("wudu-yanluobu");


    return action[random(zhaoshu)];
}

int valid_enable(string usage) {
    return usage == "dodge" || usage == "move";
}

int valid_learn(object me) {
    return 1;
}

string query_dodge_msg(string limb) {
    object me, ob;
    mapping action;

    me = this_player();
    action = query_action(me, ob);

    return action["action"];
}

int practice_skill(object me) {
    if ((int) me->query("qi") < 40)
        return notify_fail("你的体力太差了，不能练五毒烟萝步。\n");
    me->receive_damage("qi", 20);
    return 1;
}

int valid_effect(object me, object weapon, string action_name, int skill) {
    message_vision("你的体力太差了，不能练五毒烟萝步。\n", me);
}

string perform_action_file(string action) {
    return __DIR__
    "wudu-yanluobu/" + action;
}
