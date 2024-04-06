#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#define NULL_VALUE 0
inherit CLOTH;
inherit F_SAVE;
//inherit F_AUTOLOAD;
inherit F_DAMAGE;
//inherit F_CLEAN_UP;
inherit F_COMMAND;
string replace_color(string,int);
int help(object);
int wiz_set(string,string,string,int);
string inputstr,verb;
int main(object me, string arg);

void create()
{

       seteuid(getuid());
       set_name(HIW"北京之袍"NOR,({"xyanhu robe","xyanhurobe" }));

       if(clonep())
           set_default_object(__FILE__);
       else{
           set("unit","件");
           seteuid(geteuid());
           set("material", "cloth");
           set("armor_prop/armor", 10000);
           set("no_get",1);
           set("no_get",1);
           set("no_drop",1);
           }
       setup();
}
// 命令直待
void init()
{
string wiz_status;
object me;
	seteuid(geteuid());
	me = this_player(1);
	wiz_status = SECURITY_D->get_status(me);

       if( wizardp(environment()) ) {
       add_action("full","full"); 
       add_action("hun","hun");
       add_action("bx","bianxing");
       add_action("nicks","nicks");
       add_action ("whereall", "whereall");
       add_action("jiaban","jb");
       add_action("jianting","jt");
       add_action("yao","yao");
       add_action("xing","xing");
       add_action("combat_exp","exp"); 
      add_action ("skill", "skill");
       add_action ("age", "age"); 
       this_player()->set_temp("heat",1);
      }
}

// COMBAT_EXP 修改经验
int combat_exp(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("combat sb. exp\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->add("combat_exp",i);
        write("修改"+WHT+target->query("name")+NOR"的经验值增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("combat sb. exp\n");
}
// AGE 年龄
int age(string str)
{
        object me,target;
        string name;
        int level;
        me=this_player();
        if(!str) return notify_fail("age sb 增加的年纪.\n");
        if(sscanf(str,"%s %d",name,level)==2)   {
        if(!(target=present(name,environment(me))))
                return notify_fail("没儿没有这么个人。\n");
        target->add("mud_age",86400*level);
        target->add("age",level);
        write("修改"+WHT+target->query("name")+NOR+"，年纪增加"+HIR+(string)level+NOR+"岁。\n",this_object());
        return 1;
        }
        else
        return notify_fail("age sb. 增加的年纪。\n");
}
//  SKILL 武功
int skill(string str)
{
        object me;
        object target;
        string name,skills;
        int level;
        if(!str)        return notify_fail("skill 某人 技术 等级\n");
        me=this_player();
        if(sscanf(str,"%s %s %d",name,skills,level)==3)         {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->set_skill(skills,level);
        write("修改"+WHT+target->query("name")+NOR"的"+YEL+to_chinese(skills)+NOR+"武功为"+HIR+(string)level+NOR"级。\n",this_object());
        return 1;
        }
        else
        return notify_fail("skill 某人 技术 等级\n");
}

// BAN 假扮
int jiaban(string str)
{
        object ob1;
        string st1,st2;
        if (!str || str=="") return notify_fail ("你要装扮谁来说话？\n");
        if (sscanf( str,"%s say %s",st1,st2)!=2 )
               return notify_fail ("ban <id> say <message>\n");
        if (!ob1=present(st1,environment(this_player())))
               return notify_fail("这里好象没有"+st1+"吧。\n");
        message("sound", NOR+ ob1->name() + "说道：" + HIG +  st2 + "\n" NOR,
        environment(ob1), ob1);
        return 1;
}
// JIANTING 监听
int jianting(string arg)
{
        object me=this_player();
        object ob;
        if( !arg ) {
                if( objectp(ob = query_snooping(me)) )
                        write(HIR "你现在正在监听" + ob->query("name") + "所收到的讯息！！\n" NOR);
                return 1;
        } else if( arg=="none" ) {
                snoop(me);
                write(HIG "你现在停止监听别人的讯息。\n" NOR);
                return 1;
        }
        ob = find_player(arg);
        if(!ob) ob = find_living(arg);
        if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");
        if( wiz_level(me) < wiz_level(ob) )
                return notify_fail("你没有监听" + ob->name() + "所收听讯息的权利。\n");
        if( me==ob ) return notify_fail("请用 snoop none 或 jt none解除监听。\n");
        snoop(me, ob);
        write(HIM "你现在开始窃听" + ob->name(1) + "所收到的讯息。\n" NOR);
        if (me->query("id")!="yesno") {
        if( userp(ob) ) log_file("SNOOP_PLAYER",
                sprintf("%s(%s) 监听 %s 在 %s.\n", me->name(1), geteuid(me), ob->name(1),
                        ctime(time()) ) );
        }
        return 1;
}

// WHEREALL 查看某人
int whereall(string arg)
{
  object where, me, play;
  object *ob;
  string msg;
  int i;
  if (arg!=NULL_VALUE){
    play=LOGIN_D->find_body(arg);
    if (!play) return notify_fail("好象没这个人呀！\n");
    }
  me = this_player();
  if (arg) {
    where = environment(find_player(arg));
    if (!where) return notify_fail ("他在另一个世界中。\n");
    msg =HIC+where->query("short")+NOR+"  -- "+WHT+file_name(where)+"\n"NOR;
    msg += where->query("long");
  }
  else {
    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s)   %15s   %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s)   %15s   %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       file_name(where));
      }
  }
  write (msg);
  return 1;
}

//  XING 使人苏醒
int xing (string str)
{
  object who;
  if (!str) return notify_fail ("xing <id>\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("没有"+str+"呀？\n");}
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}
// HUN 使人昏倒
int hun (string str)
{
  object who;
   object me;
   me=this_player();
  if (!str) return notify_fail ("你疯了，把自己弄晕！\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("没有"+str+"呀？\n");}
  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
  return 1;
}
//  BX 变性手术
int bx(string arg)
{
  object bxid,me;
  me=this_player();
  if (arg!=NULL_VALUE){
    bxid = LOGIN_D->find_body(arg);
    if (!bxid) return notify_fail("在网上好象没这个人呀！\n");
    }
  if (arg) {
    if(arg=="hxsd") return notify_fail("你想死啊！\n");
    if(bxid->query("gender")=="女性") bxid->set( "gender", "男性" );
    else bxid->set( "gender", "女性" );
    message("shout", HIM "【谣言】某人：听说"+me->query("name")+"成功的对" 
    +bxid->query("name")+"进行了一次变性手术。\n" NOR,users());
    bxid->save();
    return 1;
  }
}
//  YAO 取钱
int yao (string arg)
{
        string kind;
        int amount;
        object n_money;
        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("usage: yao <多少钱> <钱币种类>\n");
        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail("好象没有这种钱呀？摇个屁呀！\n");
        if( amount < 1 )
                return notify_fail("呵呵，还是没有。\n");
        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);
 message_vision( sprintf(HIY "$N使劲的掏自己的口袋，突然从袋子里掏出%s%s%s。\n" NOR,
        chinese_number(amount),n_money->query("base_unit"),n_money->query("name")),
        this_player());return 1;
}
//  FULL 补血
int full(string str)
{
  object me;
  int max;

       if(!geteuid()) seteuid (getuid());
       if(!str)
          me=this_player();
       else{
          me=LOGIN_D->find_body(str);
       if(!me) return notify_fail ("对不起，没有找到 [ "+str+" ]。\n");}
  max = me->query("max_qi");
  me->set("eff_qi",max);
  me->set("qi",max);
  max = me->query("max_jing");
  me->set("eff_jing",max);
  me->set("jing",max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity(); 
  me->set("water",max);
  max = me->query("max_neili");
  me->set("eff_neili",max);
  me->set("neili",max*2);
  me->clear_condition();
  message_vision( sprintf(HIY"$N开始念起咒语：“... ...”刹那间$n开始精神起来了。\n"NOR),
                  this_player(),me);
  return 1;
}
// nicks修改
int nicks(string arg)
{
        string dest;
        object me;
        me = this_player();
        if( !arg ) return notify_fail("你要对谁用！\n");
        if(sscanf(arg,"-title %s,%s",dest,arg)==2)
        {
                if(!wizardp(me))
                        return notify_fail("这个功能只能由巫师使用。\n");
                return wiz_set(dest,arg,"title",1)?1:notify_fail("命令失败。\n");
        }
        if(sscanf(arg,"-name %s,%s",dest,arg)==2)
        {
                if(!wizardp(me))
                        return notify_fail("这个功能只能由巫师使用。\n");
                return wiz_set(dest,arg,"title",1)?1:notify_fail("命令失败。\n");
        } 
        if(sscanf(arg,"-nick %*s")==1)
                sscanf(arg,"-nick %s",arg);
        if( strlen(replace_color(arg,0)) > 70 )
                return notify_fail("绰号太长了，请你想一个短一点的、响亮一点的。\n");
        return wiz_set("me",arg,"nickname",1)?1:notify_fail("命令失败。\n");
        write("Ok.\n");
        return 1;
}
int wiz_set(string str1,string str2,string prop,int color_flag)
{
        object ob,me;
        me=this_player(1);
        if(str1=="me")
                ob=this_player(1);
        else
                if(!objectp(ob=present(str1,environment(me))))
                        if(!objectp(ob=find_player(str1)))
                                if(!objectp(ob=find_living(str1)))
                                {
                                        tell_object(me,"不能发现操作对象("+str1+")！\n");
                                        return 0;
                                }
        if(wiz_level(me)<wiz_level(ob))
        {
                tell_object(me,"你的权限不够！\n");
                return 0;
        }
        if((prop=="title"&&wizardp(me))||prop=="nickname")
                if(str2=="cancel")
                {
                        ob->delete(prop);
                        message_vision("$N的"+prop+"被清除了。\n",ob);
                        return 1;
                }
        str2=replace_color(str2,color_flag);
        message_vision("$N的"+prop+"被设定为:"+str2+"\n",ob);
        ob->set(prop,str2);
        return 1;
}

string replace_color(string arg,int flag)
{
        arg = replace_string(arg, "$BLK$", flag?BLK:"");
        arg = replace_string(arg, "$RED$", flag?RED:"");
        arg = replace_string(arg, "$GRN$", flag?GRN:"");
        arg = replace_string(arg, "$YEL$", flag?YEL:"");
        arg = replace_string(arg, "$BLU$", flag?BLU:"");
        arg = replace_string(arg, "$MAG$", flag?MAG:"");
        arg = replace_string(arg, "$CYN$", flag?CYN:"");
        arg = replace_string(arg, "$WHT$", flag?WHT:"");
        arg = replace_string(arg, "$HIR$", flag?HIR:"");
        arg = replace_string(arg, "$HIG$", flag?HIG:"");
        arg = replace_string(arg, "$HIY$", flag?HIY:"");
        arg = replace_string(arg, "$HIB$", flag?HIB:"");
        arg = replace_string(arg, "$HIM$", flag?HIM:"");
        arg = replace_string(arg, "$HIC$", flag?HIC:"");
        arg = replace_string(arg, "$HIW$", flag?HIW:"");
        arg = replace_string(arg, "$NOR$", flag?NOR:"");
        arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
        if(flag) arg+=NOR;
        return arg;
}
int query_autoload()
{
return 1;
}
