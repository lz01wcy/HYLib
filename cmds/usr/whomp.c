// who.c
// Change By 武林列传之烽火再起 蝴蝶君[Robert] Mail:robert_st@sina.com
/*
　　重新编译过的who指令，增加了可查询在线男、女、无性玩家，断线状态的玩家和简略的
　　在线玩家总数。并可识别并整理帮派、玩家帮会的在线玩家。
*/

#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>
inherit F_CLEAN_UP;

int sort_user(object,object);
int help();

private void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
        string name, str, *option;
        object *list, *ob, ob1;
        int i, ppl_cnt,player_cnt;
        int opt_long, opt_wiz, opt_party,opt_male,opt_female,opt_normal,opt_number;
        int opt_dead,opt_banghui;

        if(remote && sizeof(arg)<2) arg="";
           if (!me)
                 return notify_fail("你现在正忙着呢。\n");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
        if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
        me->start_busy(3);
        if( arg )
        {
                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- )
                        switch(option[i])
                        {
                                case "-h": return help();
                                case "-l": opt_long = 1;break;
                                case "-w": opt_wiz = 1;break;
                                case "-b": opt_banghui = 1;break;
                                case "-p": opt_party = 1;break;
                                case "-f": opt_female = 1;break;
                                case "-m": opt_male = 1;break;
                                case "-n": opt_normal = 1;break;
                                case "-a": opt_number = 1;break;
                                case "-d": opt_dead = 1;break;
                                default:
//                                        if(option[i][0]=='@' )
//                                        {
//                                                RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],me, opt_long);
//                                                write("网路讯息已送出，请稍候。\n");
//                                                return 1;
//                                        }
//                                        ob1 = present(option[i], environment(me));
                                        if (!ob1 ) ob1 = find_player(option[i]);
                                        if (!ob1) ob1 = find_living(option[i]);
                                        if ((!ob1) && (option[i] =="me")) ob1=me;
//&&!find_player(ob1)->query("env/invisibility")
                                        if (!ob1) return notify_fail("没有这个玩家或参数错误。\n指令格式 : who [-h] [-l] [-w] [-b] [-p] [-f] [-m] [-a] [-d][<ID>]\n");
                                        if (!ob1 || wizardp(ob1) )  return notify_fail("没有这个玩家或参数错误。\n指令格式 : who [-h] [-l] [-w] [-b] [-p] [-f] [-m] [-a] [-d][<ID>]\n");
//                                        if ( ob1 && find_player(ob1)->query("env/invisibility")  return notify_fail("没有这个玩家或参数错误。\n指令格式 : who [-h] [-l] [-w] [-b] [-p] [-f] [-m] [-a] [-d][<ID>]\n");
                                        me = ob1; opt_party = 1;
                        }
        }

        str = HIY"\n海洋II"HIW"目前";
        if(opt_banghui)
                if(me->query("faction/name"))
                        str += me->query("faction/name")+"的玩家有：";
                else
                        return notify_fail("你目前还没有加入任何帮会。\n");
        else if(opt_party)
                if(me->query("family/family_name"))
                        str += me->query("family/family_name")+"的玩家有：";
                else str += "普通百姓有：";
        else if(opt_male)
                str += "男性玩家有：";
        else if(opt_female)
                str += "女性玩家有：";
        else if(opt_normal)
                str += "太监有：";
        else if(opt_wiz)
                str += "巫师有：";
        else if(opt_long) str += "玩家有：";

        else str += "总人物有：";

        str += HIY"\n─────────────────────────────────────\n"NOR;
        ob = filter_array(children(USER_OB),(: userp :));
        if(opt_banghui)
                ob = filter_array(ob, (: $1->query("faction/name") ==      $2->query("faction/name") :), me);
        else if (opt_party)
                ob = filter_array(ob, (: $1->query("family/family_name") ==      $2->query("family/family_name") :), me);
        list = sort_array(ob, (: sort_user :));
//        list = sort_array(ob,"sort_user");
        ppl_cnt = 0;
        if(opt_long || opt_wiz)
        {
                i = sizeof(list);
                while ( i-- )
                {
                        // Skip those users in login limbo.
                        if( !environment(list[i])) continue;
                        if( !wizardp(me) && !me->visible(list[i]) ) continue;
                        if( opt_wiz && !wizardp(list[i]) && wizhood(list[i]) != "(immortal)" ) continue;
                        if( interactive(list[i]) )
                                ppl_cnt++;
                                player_cnt++;
                        str = sprintf("%s%12s%s%s\n",str,RANK_D->query_rank(list[i]),
                                interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
                                list[i]->short(1));

                }
        }
        else {
                ppl_cnt = 0;
                i = sizeof(list);
                while( i-- ){
                        if(!environment(list[i])) continue;
                        if(!me && wizardp(list[i]) && list[i]->query("env/invisibility")) continue;
                        if(!remote && !wizardp(me) && !me->visible(list[i])) continue;
                        if(opt_wiz && !wizardp(list[i]) ) continue;
                        if(opt_male && list[i]->query("gender")!="男性") continue;
                        if(opt_female && list[i]->query("gender")!="女性") continue;
                        if(opt_normal && list[i]->query("gender")!="无性") continue;
                        if(opt_dead && !list[i]->query_temp("netdead")) continue;
                        name=interactive(list[i])?(query_idle(list[i])>120?HIG"*"NOR + WHT:" "):HIR "#"NOR + WHT;
                        if( wizardp(list[i])){
                        name = sprintf( HIG"%s%-10s(%-11s"HIY"│"NOR + HIG,name,list[i]->name(1),
                                capitalize(list[i]->query("id"))+")");
                        }
                        else if(list[i]->query("gender") == "女性"){
                        name = sprintf( HIC"%s%-10s(%-11s"HIY"│"NOR + HIC,name,list[i]->name(1),
                                capitalize(list[i]->query("id"))+")");
                        }
                        else {
                        name = sprintf(NOR + WHT"%s%-10s(%-11s"HIY"│"NOR + WHT,name,list[i]->name(1),
                                        capitalize(list[i]->query("id"))+")");
                        }
                        str = sprintf("%s%25s%s", str, name,ppl_cnt%3==2?"\n":"");
                        ppl_cnt++;
                        player_cnt++;
                }
                if ( ppl_cnt%3 ) str += "\n";
        }
        str += HIY"─────────────────────────────────────\n"NOR;
        if(opt_number)
                
                str = HIY"海洋II"NOR + WHT"目前当前共有"+chinese_number(player_cnt)+"位使用者连线中。\n";
        else if(player_cnt)
        str = sprintf("%s共有 %s 位使用者连线中，系统负担：%s\n "HIG"*"NOR" 表示发呆中，"HIR"#"NOR" 表示断线中。\n\n", str, CHINESE_D->chinese_number(player_cnt),
        query_load_average());
        else
        str = sprintf("目前游戏中并没有符合该条件的玩家。\n");
        if( remote ) return str;
        else
        me->start_more(str);

        return 1;
}
int sort_user(object ob1, object ob2)
{
	string name1, name2;

	reset_eval_cost();
	if( wiz_level(ob1) != wiz_level(ob2) )
		return wiz_level(ob2)
			- wiz_level(ob1);
	
	name1 = ob1->query("family/family_name");
	name2 = ob2->query("family/family_name");

	if (intp(name1)) name1 = "";
	if (intp(name2)) name2 = "";
	if (name1 > name2) return -1;
	if (name1 < name2) return 1;

	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int help()
{
        write("

指令格式 : who [-h] [-l] [-w] [-p] [-f] [-m] [-a] [-d] [<ID>]

这个指令可以列出所有在游戏中的玩家及其等级。

-h 列出帮助屏幕。
-l 选项列出较长的讯息。
-b 只列出同帮会的玩家。
-p 只列出同门派的玩家。
-w 只列出游戏中的巫师。
-f 只列出游戏中的女玩家。
-m 只列出游戏中的男玩家。
-n 只列出游戏中的无性玩家。
-a 只列出当前游戏中玩家的总人数。
-d 只列出当前游戏中处于断线状态中的玩家。

<ID> 列出<ID>代表玩家所属门派的玩家。

"HIG"*"NOR" 表示"HIG"发呆"NOR"中，"HIR"#"NOR" 表示"HIR"断线"NOR"中。

相关指令： finger \n\n");
        return 1;
}

