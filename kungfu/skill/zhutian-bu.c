// zhutian-bu.c 诸天化身步
// modified by Venus Oct.1997
// written by That

inherit SKILL;

string *dodge_msg = ({
    "$n突然拔地而起，在空中一叠一转，飞到$N身后，实和武当绝技「梯云纵」有同工异曲之妙。\n",
            "$n脚下连登，一招「升龙式」接连跃起三此，远远飘了开去。\n",
            "$n做了个「凤点头」的姿势，却又双袖挥动，轻轻向后滑出。\n",
            "$n一个「凤凰双飞」，身形随着$N的攻势轻轻飘起，从容躲过这一招。\n",
            "$n使出一招「玉凤穿云」，脚尖一点，身子拔高丈余，结果$N扑了个空。\n",
            "$n身形一摇，幻出无数个人影，一招「百鸟朝凤」躲过了$N的攻势。\n",
            "$n一招「飞凤天翔」纵身跃起，在空中一转，倏忽已落至$N身后。\n",
            "$n左一摇，右一晃，一招「云凤雾凰」已轻松闪过$N的攻击。\n",
            "却见$n的身形顺着$N的招式幻化不定，跟着「凤凰展翅」一转便到了$N的身后\n",
            "$n脚下猛力一登，「天龙飞升」拔起丈高，逼开了$N的招式。\n",
            "$n双掌连拍，一式「龙飞九天」跃起三丈高，远远飘了开去。\n",
            "$n身子连续翻滚，一式「神龙降世」，跳出了$N的攻击范围。\n",
            "$n一招「海底游龙」，身子一弯，贴着地面平平滑开。\n"
            "只见$n一招「天地钩」，身体腾空，双足向上，笔直地纵起丈余，躲过了$N这一招。\n",
            "$n身随意转，一式「凤点头」头部前挺，侧身收腹，倏地往一旁挪开了三尺，避过了这一招。\n",
            "$n双足抓地，身形微晃，一招「鹰爪松」有惊无险地避开了$N这一招。\n"
            "但是$n身形飘忽，一式「风摆柳」，轻轻一纵，早已避开。\n",
            "$n一个「阴阳箭」，向后纵出数丈之远，避开了$N的凌厉攻势，立即又欺近$N身旁。\n",
            "$n使出「日月扣」，双手如钩向一旁飘然纵出，轻轻着地。\n"
});

int valid_enable(string usage) {
    return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb) {
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {
    if ((int) me->query("qi") < 40)
        return notify_fail("你的体力太差了，不能练诸天化身步。\n");
    me->receive_damage("qi", 30);
    return 1;
}
