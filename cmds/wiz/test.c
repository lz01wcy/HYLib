// test.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
if (!arg) return notify_fail("<Syntax>: test <id>\n");

	ob = present(arg, environment(me));
	if (!ob) return notify_fail("咦... 有这个人吗?\n");
//	SKILL_D("celestial")->hit_ob(me, ob, 50, 20);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
    printf("wizard level: %d   status: %s\n", wiz_level(ob), wizhood(ob));
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : test <某人>

用来测试武功技能的强弱。
HELP
    );
    return 1;
}
