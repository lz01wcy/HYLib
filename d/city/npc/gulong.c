// gulong.c
inherit NPC;
#include <ansi.h>;

int do_bihua(string arg);
int do_setname(string arg);
int do_setcan(string arg);
int clear_title(string arg);
void add_title(object me,string arg);
void clear();
string ask_home();
string ask_me(string arg);
string ask_candidate();
string ask_nowcan();
int do_halt();

void create()
{
        set_name("古龙", ({ "gu long"}) );
        set("gender", "男性");
        set("nickname", HIR"至公无私"NOR);
        set("title", HIY"天外飞龙"NOR);
        set("age", 65);
        set("long",
            "这是一位不修边幅的狂放中年人，一张胖胖的脸，十分惹人亲近。\n");
        set("combat_exp",1);
        set("class","scholar");
        set("shen_type", 1);
        set("attitude", "friendly");

        set("apply/attack", 200);
        set("apply/defense", 200);

        set("max_qi", 2800);
        set("max_neili", 1800);
        set("neili", 1800);
        set("max_jing", 800);

        set("win_times", 0);

        set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("sword",80);
        set_skill("parry",80);
        set_skill("dodge", 80);
        set("inquiry", ([
                "比武大会"     : (: ask_me :),
                "候选人"       : (: ask_candidate :),
                "当前候选人"   : (: ask_nowcan:),
                "回家"         : (: ask_home:),
        ]));

        setup();
        set("candidate",this_object());
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/changjian")->wield();
}

void init()
{
        ::init();
        add_action("ask_me", "start");
        add_action("ask_candidate", "can");
        add_action("ask_nowcan", "nowcan");
        add_action("do_setname", "setname");
        add_action("do_setcan", "setcan");
        add_action("do_clearname", "clear");

        add_action("do_bihua", "fight");
        add_action("do_bihua", "hit");
        add_action("do_bihua", "kill");
        add_action("do_bihua", "bihua");
        add_action("do_bihua", "bi");
        add_action("do_halt", "halt");
}

int ask_me(string arg)
{
        string faction;
        object* ob;
        int i;
        ob = users();

        if ( !wizardp(this_player()) )
        {
            write("你无权召开比武大会!! \n");
            return 1;
        }
        switch (arg)
        {
            case "bt": 
                 faction="白驼山派";
                 break; 
            case "em": 
                 faction="峨嵋派";
                 break; 
            case "gb": 
                 faction="丐帮";
                 break; 
            case "hs": 
                 faction="华山派";
                 break; 
            case "lj": 
                 faction="灵鹫宫";
                 break; 
            case "mj": 
                 faction="明教";
                 break; 
            case "sl": 
                 faction="少林派";
                 break; 
            case "th": 
                 faction="桃花岛";
                 break; 
            case "wd": 
                 faction="武当派";
                 break; 
            case "xx": 
                 faction="星宿派";
                 break; 
            case "xs": 
                 faction="雪山寺";
                 break; 
            case "xy": 
                 faction="逍遥派";
                 break; 
            case "yl": 
                 faction="云龙门";
                 break; 
            default: 
                 return 1;
        }
        command("chat 好，现在四海擂台开擂，"+faction+"全体集合! \n");
        for ( i=0;i<sizeof(ob); i++ )
            if((!wizardp(ob[i])) && (ob[i]->query("family/family_name")==faction))
            {
                this_object()->set("candidate",ob[i]);
                break;
            }
        for ( i=sizeof(ob); i>0; i-- )
        {
            if (ob[i-1]->query("family/family_name")==faction)
            {
                ob[i-1]->move("/d/city/wudao2");
                if(!wizardp(ob[i-1]))
                   if(ob[i-1]->query("combat_exp")>this_object()->query("candidate")->query("combat_exp"))
                     set("candidate",ob[i-1]);
            }
        }
        command("chat 现在, 本门第一的候选人是"+this_object()->query("candidate")->query("name")+"!\n");
        command("chat 大家可以自由挑战。任何人连胜五场或者无人再向其挑战即可获得本门第一的称号。\n");
        command("chat 任何战败或中途弃权者均只能争夺下一称号。\n");
        tell_object(this_player(),"古龙告诉你: 可以用setname somebody 指定某人为当前胜者。\n"+
               "也可以用setcan somebody 指定某人为当前候选人。\n");
        return 1;
}

int do_clearname()
{
        object* ob;
        int i;
        ob = users();

        if ( !wizardp(this_player()) )
        {
             write("你无权取消称号!! \n");
             return 1;
        }
        for ( i=0;i<sizeof(ob); i++ )
             add_title(ob[i],"");
        write("已取消所有称号!! \n");
        return 1;
}

string ask_home()
{
        this_player()->move("/d/city/guangchang");
        return("好的，我送你回扬州吧。\n");
}

int do_bihua(string arg)
{
        object ob1, ob2;
        object old_target;

        ob1 = this_player();

        if( !arg || arg=="" ) return 0;

        if ( arg == "gu long" )
        {
             command("say " + "你不能跟我比划！\n");
             return 1;
        }
        if (strsrch(ob1->query("title"), "本派") >= 0)
                return notify_fail("你想包揽啊！给别人也留点。\n");

        if ( this_object()->query_temp("busy") )
                return notify_fail("每次只能有两人参加比武。\n");

        if (!ob2 = present(arg,environment(ob1)) )
                return notify_fail("你想跟谁比划？\n");

        if(wizardp(ob1)) return notify_fail("巫师瞎掺合个什么劲啊? \n");

        if (ob1 == ob2)  return notify_fail("你不能攻击自己。\n");

        if (ob1->query("name")!=query("candidate")->query("name"))
        if (ob2->query("name")!=query("candidate")->query("name"))
                return notify_fail("你只能向候选人挑战。\n");

        if (ob2->query("family/family_name")!=ob1->query("family/family_name"))
                return notify_fail("又不是你门派的嚷嚷个啥劲呢。\n");

        if (ob1->query_temp("lose")*5>query("win_times"))
                return notify_fail("你已经输过一次了只能向下一候选人挑战。\n");

        if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
                message_vision("\n$N对着$n说道"
                        + RANK_D->query_self(ob1)
                        + ob1->name() + "领教"
                        + RANK_D->query_respect(ob2)+"的高招\n\n", ob1, ob2);
                if( objectp(old_target = ob1->query_temp("pending/fight")) )
                        tell_object(old_target, YEL + ob1->name() + "取消了和你比试的念头。\n" NOR);
                ob1->set_temp("pending/fight", ob2);
                tell_object(ob2, YEL "如果你愿意和对方进行比试请你也对" + ob1->name() + "("+(string)ob1->query("id")+")"+ "下一次 bihua 指令。\n" NOR);

                write(YEL "由於对方是由玩家控制的人物你必须等对方同意才能进行比试。\n" NOR);
                return 1;
        }

        ob1->delete_temp("halted");
        ob2->delete_temp("halted");

        remove_call_out("check");
        call_out("check",2, ob1, ob2);

        ob1->set("qi",(int)ob1->query("max_qi"));
        ob2->set("qi",(int)ob2->query("max_qi"));

        remove_call_out("fighting");
        call_out("fighting",2, ob1, ob2);

        return 1;
}

void fighting(object ob1, object ob2)
{
        ob1->fight_ob(ob2);
        ob2->fight_ob(ob1);
}

void check(object ob1, object ob2)
{
        this_object()->set_temp("busy",1);
        command("chat " + ob1->query("name")
                + "与" + ob2->query("name") + "，现在四海擂开始比武论剑！\n");
        command("chat 当前候选人"+query("candidate")->query("name")+"已获胜"+(string)(query("win_times")%5)+"次.\n");
        call_out("observe",1,ob1,ob2);
}

int observe(object ob1,object ob2)
{

        if(ob2->query("name")!=query("candidate")->query("name"))
        {
                call_out("observe",0,ob2,ob1);
                return 1;
        }

        if(ob1->is_fighting())
        {
                call_out("observe",1,ob1,ob2);
                return 1;
        }

        this_object()->delete_temp("busy");
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");

        if ( !present(ob1, environment()) )
        {
                command("chat " + ob1->query("name") + "落荒而逃了！\n");
                command("chat " + ob2->query("name")
                        + "比武战胜" + ob1->query("name") + "！\n");

                add("win_times",1);
                if(this_object()->query("win_times")==10)
                {
                        command("chat " + ob2->query("name")
                                + "获得本次比武大会本门第二的称号！\n");
                        add_title(ob2,"本门第二");

                        command("chat 比武大会结束！\n");
                        this_object()->delete("candidate");
                        this_object()->delete("win_times");
                        return 1;
                }
                if(this_object()->query("win_times")==5)
                {
                        command("chat "+ob2->query("name")
                                + "获得本次比武大会本门第一的称号！\n");
                        add_title(ob2,"本门第一");
                        command("chat 现在, 本门第二的候选人是"
                                + ob1->query("name")+"！\n");
                        command("chat 大家可以自由挑战。任何人连胜五场或者无人
再向其挑战即可获得本门第二的称号。\n");
                        set("candidate",ob1);
                }
                return 1;
        }

        if ( !present(ob2, environment()) )
        {
                command("chat " + ob2->query("name") + "落荒而逃了！\n");
                command("chat " + ob1->query("name")
                        + "比武战胜" + ob2->query("name") + "！\n");
                if(query("win_times")<5)
                {
                        command("chat "+ob1->query("name")
                                + "成为本门第一之候选人！\n");
                        set("win_times",0);
                }
                else
                {
                        command("chat "+ob1->query("name")
                                + "成为本门第二之候选人！\n");
                        set("win_times",5);
                }
                set("candidate",ob1);
                ob2->add_temp("lose",1);
                return 1;
        }

        if (ob1->query_temp("halted"))
        {
                ob1->delete_temp("halted");
                command("chat " + ob1->query("name") +
                        "中途放弃比武！\n");
                command("chat " + ob2->query("name")
                        + "比武战胜" + ob1->query("name") + "！\n");
                add("win_times",1);
                ob1->add_temp("lose",1);
                if(this_object()->query("win_times")==10)
                {
                        command("chat " + ob2->query("name")
                                + "获得本次比武大会本门第二的称号！\n");
                        add_title(ob2,"本门第二");
                        command("chat 比武大会结束！\n");
                        this_object()->delete("candidate");
                        this_object()->delete("win_times");
                        return 1;
                }
                if(this_object()->query("win_times")==5)
                {
                        command("chat " + ob2->query("name")
                                + "获得本次比武大会本门第一的称号！\n");
                        add_title(ob2,"本门第一");
                        command("chat 现在, 本门第二的候选人是"
                                + ob1->query("name")+"！\n");
                        command("chat 大家可以自由挑战。任何人连胜五场或者无人
再向其挑战即可获得本门第二的称号。\n");
                        set("candidate",ob1);
                }
                return 1;
        }
        if (ob2->query_temp("halted"))
        {
                ob2->delete_temp("halted");
                command("chat " + ob2->query("name") +
                        "中途放弃比武！\n");
                command("chat " + ob1->query("name")
                        + "比武战胜" + ob2->query("name") + "！\n");
                if(query("win_times")<5)
                {
                        command("chat "+ob1->query("name")
                                + "成为本门第一之候选人！\n");
                        set("win_times",0);
                }
                else
                {
                        command("chat "+ob1->query("name")
                                + "成为本门第二之候选人！\n");
                        set("win_times",5);
                }
                set("candidate",ob1);
                ob2->add_temp("lose",1);
                return 1;
         }

        if ( ob1->query("qi")*2 > ob1->query("max_qi"))
        {
                if  (ob2->query("qi")*2 > ob2->query("max_qi"))
                {
                        command("chat " + ob1->query("name")
                                + "与" + ob2->query("name") + "比武不分胜负！\n");
                        return 1;
                }
                command("chat " + ob1->query("name")
                        + "比武战胜" + ob2->query("name") + "！\n");
                if(query("win_times")<5)
                {
                        command("chat "+ob1->query("name")
                                + "成为本门第一之候选人！\n");
                        set("win_times",0);
                }
                else
                {
                        command("chat "+ob1->query("name")
                                + "成为本门第二之候选人！\n");
                        set("win_times",5);
                }
                set("candidate",ob1);
                ob2->add_temp("lose",1);
                return 1;
        }
        else
        {
                command("chat " + ob2->query("name")
                        + "比武战胜" + ob1->query("name") + "！\n");
                add("win_times",1);
                ob1->add_temp("lose",1);
                if(this_object()->query("win_times")==10)
                {
                        command("chat " + ob2->query("name")
                                + "获得本次比武大会本门第二的称号！\n");
                        add_title(ob2,"本门第二");
                        command("chat 比武大会结束！\n");
                        this_object()->delete("candidate");
                        this_object()->delete("win_times");
                        return 1;
                }
                if(this_object()->query("win_times")==5)
                {
                        command("chat " + ob2->query("name")
                               +"获得本次比武大会本门第一的称号！\n");
                        add_title(ob2,"本门第一");
                        command("chat 现在, 本门第二的候选人是"
                                + ob1->query("name")+"！\n");
                        command("chat 大家可以自由挑战。任何人连胜五场或者无人
再向其挑战即可获得本门第二的称号。\n");
                        set("candidate",ob1);
                        return 1;
                }
        }
        return 1;
}

int do_halt()
{
        object me = this_player();
        if (me->is_fighting()) me->set_temp("halted",1);
        return 0;
}


int do_setcan(string arg)
{
        object ob;
        if(!wizardp(this_player())) return notify_fail("你无权设定候选人!\n");
        if(!arg||!objectp(ob=present(arg,environment(this_player()))))
                return notify_fail("古龙说: 对不起，此人不在这里。\n");
        set("candidate",ob);
        command("nod");
        command("chat 当前候选人是"+query("candidate")->query("name")+"。\n");
        return 1;
}

int ask_nowcan()
{
        write("当前候选人是"+(query("candidate")->query("name"))+"。\n");
        return 1;
}

int ask_candidate()
{
        object* ob,obj;
        int i;
        ob = users();

        if ( !wizardp(this_player()) )
        {
            write("你无权查询候选人! \n");
            return 1;
        }
        for ( i=0;i<sizeof(ob); i++ )
            if(!wizardp(ob[i]))
            {
                if(!(strsrch(ob[i]->query("title"), "本门") >= 0))
                {
                    obj=ob[i];
                    break;
                }
            }
        for ( i=sizeof(ob); i>0; i-- ) {
                if(!wizardp(ob[i-1]))
                if(!(strsrch(ob[i-1]->query("title"), "本门") >= 0))
                if(ob[i-1]->query("combat_exp")>query("candidate")->query("combat_exp"))
                obj=ob[i-1];
        }
        write("下一候选人是"+obj->query("name")+"。\n");
        return 1;
}

string clear_title(string arg)
{
        if( (strsrch(arg, "本门第一") >= 0) ||
            (strsrch(arg, "本门第二") >= 0) )
                {
                arg = replace_string(arg, "本门第一","");
                arg = replace_string(arg, "本门第二","");
        }
        return arg;
}

void add_title(object me,string arg)
{
        string title;
        title=arg+clear_title(me->query("title"));
        me->set("title",title);
}

int do_setname(string arg)
{
        object dest,*all;
        int i,losetime;

        if (!wizardp(this_player())) return notify_fail("你无权设定称号! \n");
        all = users();

        for(i=0; i<sizeof(all); i++)
        {
                if(arg == all[i]->name() || arg == all[i]->query("id") )
                        dest = all[i];
        }
        if( !dest )
                return notify_fail("古龙说：对不起，此玩家不在这里。\n");
        if (dest->is_ghost())
                return notify_fail("古龙说：对不起，此人已经死了。\n");
        if(this_object()->query("win_times")==5)
        {
                command("chat " + dest->query("name")
                        + "获得本次比武大会本门第二的称号!\n");
                add_title(dest,"本门第二");
                command("chat 比武大会结束!\n");
                this_object()->delete("candidate");
                this_object()->delete("win_times");
        }
        else if(this_object()->query("win_times")==0)
        {
                command("chat " + dest->query("name")
                        + "获得本次比武大会本门第一的称号!\n");
                add_title(dest,"本门第一");
                set("win_times",5);
                command("chat 现在大家可以自由挑战。争夺本门第二。\n");
                losetime=1;
        }
        for(i=0; i<sizeof(all); i++)
                all[i]->set_temp("lose",losetime);
        return 1;
}

