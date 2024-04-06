// baby.c
#include <ansi.h>
#include <combat.h>
inherit NPC;
string *cmds = ({"wield", "unwield", "wear", "remove", "enable", "jifa", "prepare", "bei", "exert",
"yun", "perform", "yong", "enforce", "jiali", "eat", "drink", "kill", "hit", "say"});

void try_move();
void exec_cmd(object me, string arg);
void create()
{
        set_name("宝宝", ({"xiao baobao","baby"}) );
if (random(10)>5)
{
        set("gender", "女性");
}
else {
        set("gender", "男性");
}
set("str",30);
set("dex",30);
set("int",30);
set("con",30);
set("per",30);
set("kar",30);
        set("jing",1000);
        set("max_jing",1000);
        set("eff_jing",1000);
        set("qi",1000);
        set("max_qi",1000);
        set("eff_qi",2000);
        set("neili",3000);
        set("max_neili",3000);
	set_skill("unarmed", 260);
	set_skill("force", 260);
	set_skill("blade", 260);
	set_skill("dodge", 260);
	set_skill("parry", 260);
 
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 50);

        set("age", 1);
        set_temp("no_kill",1);
        set("attitude", "friendly");
        set("long","乖宝宝。你可以用nie,shua命令来和他玩\n");
        set("combat_exp", 1);
        set("str",3);
        set("parents",({"dad","mom"}));
   
        set("chat_chance", 2);
        set("chat_msg", ({
           (: random_move :)
        }));

        set("is_baby",1);
        // to allow the identification of baby. by mon.

        setup();
	carry_object(__DIR__"candy");
carry_object(__DIR__"candy2");
carry_object(__DIR__"candy3");
}

void init()
{
	object ob;
	ob = this_object();
       add_action("do_kill",({"kill","fight","hit","steal"}));
  add_action ("do_setid", "setid");
  add_action ("do_setname", "setname");
  add_action ("do_nie", "nie");
  add_action ("do_shua", "shua");
  add_action("do_get","get");
  add_action("do_drop","drop");
  add_action("do_shape", "ck");
  add_action("do_cun", "cundang"); 
  add_action("do_teach", "jiaoyang");   
  add_action("do_order", "minglin");
//add_action("do_make", "makebb");
}


int do_drop(string arg)
{
      object me=this_object(),who=this_player(),env;
      if(!arg) return 0;
      env = environment(who);
      if(present(arg,who)!=me) return 0;
      if(me->move(env))
      {
             message_vision("$N把$n从怀里放了下来。\n",who,me);
             return 1;
      }
      return 0;
}

int do_get(string arg)
{
      object me=this_object(),who=this_player(),env;

      if(!arg) return 0;
      env = environment(who);
      if(present(arg,env)!=me) return 0;
      if(member_array(who->query("id"),
             me->query("parents"))>-1)
      {
             if(me->move(who))
             {
                   message_vision("$N弯下腰把$n抱了起来，搂在怀里。\n",who,me);
             }
             else
             {
                   message_vision("$N弯下腰一抱却没把$n抱起来，小家伙好沉哪！\n",who,me);
             }
      }
      else
      {
             message_vision("$N蹲下身朝$n伸开双手，$n却一下子闪开了．．．\n",who,me);
      }
      return 1;
}

int do_kill(string arg)
{       
      object me,who;
      string name,verb,what,obj;
      if (!arg) return 0;
      verb=query_verb();
      me=this_player();
   
      if(verb=="steal")
      {
             if(sscanf(arg, "%s from %s", what, obj)!=2 ) 
             return 0;
      }
      else obj=arg;

      if(!objectp(who=present(obj,environment(me))) 
            || !living(who)) return 0;
//    if(who->query("is_baby")) {
      if(who==this_object())
      {
             switch(verb)
             {
                    case "kill":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"拼命地哭了起来：爹～～，娘～～，"+
                             me->query("name")+"要杀我．．．快回来呀！\n");
                         break;
                    case "hit":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"大哭了起来：爹～～，娘～～，"+
                             me->query("name")+"欺负我．．．快回来呀！\n");
                         break;
                    case "fight":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"哭了起来：爹～～，娘～～，"+
                             me->query("name")+"要抢我的糖吃．．．快回来呀！\n");
                         break;
                    case "steal":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"哭了起来：爹～～，娘～～，"+
                             me->query("name")+"要偷吃我的糖！\n");
                         break;
                    case "beg":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"小嘴一歪哭了起来：爹～～，娘～～，"+
                             me->query("name")+"要骗我的糖吃！\n");
                         break;
             }
      }
      command(verb);
      return 0;
}

void relay_emote(object ob, string verb)
{
      if( !userp(ob) ) return;

      switch(verb)
      {
            case "kick":
                 command("say 爹～～，娘～～，"  + ob->query("name") + "踢我耶！");
                 command("kick " + ob->query("id"));
                 break;
            case "slap":
                 command("say 爹～～，娘～～，"  + ob->query("name") +
                 "打我耶，好痛啊～～～～");
                 command("slap " + ob->query("id"));
                 break;
            case "hit":
                 command("pain " + ob->query("id"));
                 break;
            case "bite":
                 command("face " + ob->query("id"));
                 break;  
            case "papaya":
                 command("angry");
                 break;  
      }
}

void relay_whisper(object me, string msg)
{
      if (member_array(me->query("id"),query("parents"))==-1)
      {
            message_vision((string)this_object()->query("name")
                        + "疑惑地看着$N。\n", me);
            return;
      }

      //note, do not allow the order contain "chat", "tell"...
      //may need disable more later...
      if( strsrch(msg, "chat") != -1 ||
          strsrch(msg, "tell") != -1 ||
          strsrch(msg, "follow") != -1 ||
          strsrch(msg, "apprentice") != -1 ||
          strsrch(msg, "recruit") != -1 )
            return;

      if (msg)
      {
            remove_call_out ("relaying");
            call_out ("relaying", 1+random(3), msg);
      }
}

void relaying (string msg)
{
//execute the order.
      command (msg);
}

int do_setid (string arg)
{
  object me = this_player();
  string name = this_object()->query("name");

  if (!wizardp(me))
    return 0;
  this_object()->set_name(name, ({ arg }) );
  return 1;
}

int do_setname (string arg)
{
  object me = this_player();

  if (!wizardp(me))
    return 0;

this_object()->set("name"," "+ arg+" ");
//  this_object()->set("name",arg);
  this_object()->set("long","一"+this_object()->query("unit")+arg+"。\n");
  return 1;
}

int do_setunit (string arg)
{
  object me = this_player();

  if (!wizardp(me))
    return 0;

  this_object()->set("unit",arg);
  this_object()->set("long","一"+arg+this_object()->query("name")+"。\n");
  return 1;
}

string rdm(string *strs)
{
  return strs[random(sizeof(strs))];
}

int do_nie (string arg)
{
  string *dos = ({
    "用手指轻轻一捏",
    "轻轻捏了一下",
    "小心地捏一捏",
    "捏一捏",
    "轻碰了一下",
    "碰碰",
    "用手指点一点",
  });

  string *parts = ({
    "脑袋",
    "头发",
    "脸蛋",
    "胖腮帮",
    "嘴嘴",
    "小嘴唇",
    "耳朵",
    "眉心",
    "长睫毛",
    "鼻子",
    "小鼻尖",
    "下巴",
    "小脖子",
    "手",
    "胳膊",
    "腿",
    "脚",
    "肚肚",
    "小屁屁",
  });

  string *actions = ({
    "张开小口吱吱地叫了两声。",
    "张开嘴啊哟了一声。",
    "天真地呀呀叫出了声音。",
    "睁开大眼睛吧嗒吧嗒地眨了几下。",
    "睡意朦胧地慢慢睁开一对大眼睛。",
    "睁开眼睛，又满意地合上眼睛睡着了。",
    "摇了摇硕大的脑袋。",
    "东倒西歪地努力抬起大脑袋。",
    "认真地点点脑袋。",
    "瞪着大眼睛看着$N。",
    "呆呆地看着$N，吃吃地笑出声来。",
    "把胖胖的手指放到嘴里，一边吮吸一边看着$N。",
    "把脑袋往两边一转看了看，又抬头看看$N。",
    "害羞地把脑袋往$N怀里一钻。",
    "甜甜地把大脑袋贴在$N身上。",
    "皱了一皱月儿眉。",
    "小老头儿般地皱了一皱额头。",
    "高兴地把眼睛眯成一条缝。",
    "咧开小嘴哇地一声哭了出来。",
    "摆出一副可爱的小苦瓜脸。",
    "张开小嘴哭得喘不过气来。",
    "眯着眼睛，张开小嘴笑了出来。",
    "甜蜜一笑。",
    "笑呀笑呀笑呀。",
    "呀呀哟哟地唱了几句。",
    "高兴地唱了起来：咿噜啊哈哩……",
    "唱起摇篮曲：睡睡吧，乖乖耶……",
    "不高兴地噘了噘小嘴。",
    "满脸不高兴嘟囔着小嘴儿。",
    "噘起小嘴儿眼儿一翻扭过头去不理人了。",
    "用小手揪住$N的袖口。",
    "一把揪住$N的衣服死死不放。",
    "揪住$N的手眼巴巴地望着$N。",
    "伸出两条小腿胡乱踢了几下。",
    "抬起一条小腿伸在$N的脸上。",
    "高兴地拍打着两条小腿儿。",
    "扭了扭腰肢。",
    "撅了撅小屁屁。",
    "把小屁屁向$N一歪。",
    "笑了起来。",
    "咯咯咯笑个不停。",
    "搂着$N的脖子笑了起来。",
    "甜甜地一笑：叔叔阿姨，我要撒娇娇……",
    "天真地问：我撒个娇娇好不好呀？",
    "问$N：要是我撒个娇娇你是不是更喜欢我呀？",
    "突然开口说：咦，那个叔叔有小胡子，我怎么没有呢？",
    "说：哟，阿姨头发真长，挠在宝宝的脸上痒痒耶。",
    "问道：小宝宝我什么时候能长成大宝宝老宝宝？",
    "说道：阿姨，要不要听我唱支歌？",
    "说道：宝宝想唱支儿歌，哪一支呢？我想不起来哪支最好听的。",
    "嘟嘟囔囔地说：叔叔阿姨，我是个最好的小乖乖耶。",
    "一字一句地说：我最乖乖耶，叔叔阿姨只喜欢我一个小乖乖好吗？",
    "自言自语地说：我是小乖乖，小乖乖是我。",
    "细声细气地说：小乖乖我……想吃糖糖耶。",
    "说：往我嘴里放一颗糖糖好不好？",
    "说：叔叔阿姨能变魔术吗？变出糖糖来好不好？",
  });

  string str1 = "$N"+rdm(dos)+"$n的"+rdm(parts)+"。\n";  
  string str2 = "$n"+rdm(actions)+"\n";
  
  if (arg != this_object()->query("id"))
    return 0;

  remove_call_out ("delayed_action");
  call_out ("delayed_action",1,str1,this_player(),this_object());
  remove_call_out ("delayed_reaction");
  call_out ("delayed_reaction",3,str2,this_player(),this_object());
  return 1;
}

int do_shua (string arg)
{
  object me = this_object();
  object who;
  string my_name = me->query("name");
  string *dos = ({
    "飞快地从$N手中跑下来，爬到$n的",
    "从$N身上滑下来，蹿到$n的",
    "从$N手中使劲往$n身上一跳，贴在$n的",
    "朝$N点点头，一转身扒在$n的",
    "会意地爬到$n的",
    "老练地扑到$n的",
    "鬼鬼祟祟地蹦到$n的",
    "一个弹跳扑到$n的",
    "跳上$n的",
    "呼地一跳，跃在$n的",
    "一个小飞身跃在$n的",
    "身子一闪，已站在$n的",
    "巧巧地一翻身，抓在$n的",
    "机灵地抓在$n的",
  });

  string *parts = ({
    "后脑勺",
    "扁脑门",
    "乱头发",
    "秃顶",
    "水泡眼",
    "老鼠眼",
    "腮帮",
    "黄脸蛋",
    "厚嘴唇",
    "咧开的嘴巴",
    "肥耳朵",
    "大暴牙",
    "酒糟鼻子",
    "宽鼻梁",
    "肥下巴",
    "斜酒窝",
    "歪脖子",
    "瘦喉结",
    "塌肩膀",
    "鸡胸",
    "短拇指",
    "肥掌",
    "左手",
    "右手",
    "胳膊肘",
    "瘦排骨",
    "小腿",
    "短腿",
    "大腿",
    "火柴棍大腿",
    "罗圈腿",
    "哈吧腿",
    "水桶腰",
    "南瓜腰",
    "水蛇腰",
    "水萝卜腰",
    "麻花腰",
    "搓板儿背",
    "脚后跟",
    "裹脚背",
    "大脚趾",
    "细脚肘",
    "大肚皮",
    "啤酒肥肚",
    "瘪肚皮",
    "驼背",
    "肥臀",
    "臀尖",
  });

  string *actions = ({
    "不客气地迅速尿了一小滩尿。",
    "端起小水枪就狂浇一气。",
    "呸了一小口。",
    "吐出一小堆粘粘的口香糖渣。",
    "张口就舔了几口。",
    "将$n舔得死去活来。",
    "张开小嘴咬了一口。",
    "张开小嘴咬住$n死死不放。",
    "咬下一小砣肉。",
    "咬下一大块疙瘩肉。",
    "咬得$n捶胸顿足哭爹喊娘。",
    "咬出两排红牙印儿。",
    "咬出一大块瘀血紫疤。",
    "揪下一撮毛。",
    "揪下一层老皮。",
    "扯住一撮细毛不放。",
    "硬是扯出一个血囊葫芦。",
    "吧嗒吧嗒使劲捶了几拳。",
    "捶出一个大囊肿。",
    "胡乱踢了几下。",
    "踢得$n上吐下泄。",
    "砰地一声踢中要害。",
    "踢得$n直翻白眼。",
    "用大脑袋轰地一撞。",
    "用小指扎出几个绣花窟窿。",
    "使劲地抓出五道血痕。",
    "抓出五串水泡。",
    "伸出双手玩命地一掐。",
    "咬牙切齿地掐住$n的人中。",
    "伸出手掐出好大一个肿块。",
    "拽着悠秋千。",
    "啪啪左右开弓扇了十几下。",
    "扇了个两面红。",
    "毫不客气地挠起痒痒儿。",
    "挠出一大片粉头痱子。",
    "用小手指抠出一小肿疱。",
    "用手指抠出一沙疮。",
    "掏出一块红疤。",
    "抓出一大片青春美丽豆。",
  });

  string *returns = ({
    "然后跑回$N身上。",
    "然后悄悄地回到$N手中。",
    "再回头一本正经地爬到$N身上。",
    "再纵身跃回到$N手中。",
    "再回头一跳，跃到$N身上。",
    "然后高兴地回到$N手中。",
    "然后得意地钻回$N身上。",
    "然后十分满意地钻回$N手中。",
    "然后兴奋地蹦回$N身上。",
    "然后欣喜若狂地蹦回$N手中。",
  });

  string str1 = my_name+rdm(dos)+rdm(parts)+"上，"+rdm(actions)+"\n";
  
  if (! arg)
    return 0;

  who = present(arg,environment(this_player()));
  if (! who)
    return notify_fail ("耍谁？\n");

  message_vision ("$N向"+my_name+
                  "使了一个眼色，然后若无其事地看了$n一眼。\n",
                  this_player(),who);
  remove_call_out ("delayed_action");
  call_out ("delayed_action",3,str1,this_player(),who);
  remove_call_out ("delayed_reaction");
  call_out ("delayed_reaction",4,rdm(returns)+"\n",
            this_player(),who);
  return 1;
}

void delayed_action (string str, object ob1, object ob2)
{
  message_vision (str,ob1,ob2);
}

void delayed_reaction (string str, object ob1, object ob2)
{
  message_vision (str,ob1,ob2);
}



void die()
{	
	int i;
	object owner, *enemy;
	int jing,qi,exp;
owner=this_player();
	exp = (int) query("combat_exp");
	jing = (int) query("max_jing");
	qi = (int) query("max_qi");

	if(!environment()->query("no_death_penalty"))
		set("combat_exp", exp/10 * 8);
	set("eff_qi", qi);
	set("eff_jing", jing);
	set("qi", qi);
	set("jing", jing);
if(member_array(owner->query("id"),
owner->query("parents"))>-1)
{
owner->set("baby/exp",(int)query("combat_exp"));
owner->save();
}
	::die();
}
string status_color(int current, int max)
{
        int percent;


        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}

int do_shape(string arg)
{	mapping my;
	string shape;
	int at_pt,pa_pt,do_pt;
if (!arg)
return notify_fail("你要看谁的状态？\n");
if (arg !=query("id"))
return notify_fail("你要看谁的状态？\n");
if(member_array(this_player()->query("id"),
this_object()->query("parents"))<0)
return notify_fail("你是谁啊？\n");
	my = query_entire_dbase();
	 printf(HIC"≡"HIY"──────────────────────────────"HIC"≡\n"NOR);
printf(HIC"精力："NOR"%s%3d/ %3d %s(%3d%%)   "HIC"气血："NOR"%s%3d/ %3d %s(%3d%%)\n",
                status_color(my["jing"], my["eff_jing"]), my["jing"],my["eff_jing"],
                status_color(my["eff_jing"], my["max_jing"]),     my["eff_jing"] * 100 / my["max_jing"],
                status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
                status_color(my["eff_qi"], my["max_qi"]),     my["eff_qi"] * 100 / my["max_qi"]            
	);		
	printf(HIW"性名： "HIG"%s"NOR"\t\t"HIW"经验： "HIG"%d"NOR"\t\t"HIW"年龄： "HIG"%d"NOR"\n"NOR,
	my["name"], my["combat_exp"],my["age"]
	);
        printf(HIY"悟性： "HIG"%d"NOR"\t\t"HIY"根骨： "HIG"%d"NOR"\t\t"HIY"容貌： "HIG"%d"NOR"\n"NOR,
        query_int(), query_con(),query_per()
        );
        printf(HIY"身法： "HIG"%d"NOR"\t\t"HIY"臂力： "HIG"%d"NOR"\t\t"HIY"福缘： "HIG"%d"NOR"\n"NOR,
        query_dex(), query_str(),query_kar()
        );
        printf(HIY"内力： "HIG"%d"NOR"\t\t"HIY"内力上限： "HIG"%d"NOR"\t\t\n"NOR,
        query("neili"), query("max_neili")
        );

        at_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_ATTACK);
        pa_pt= COMBAT_D->skill_power(this_object(), "parry", SKILL_USAGE_DEFENSE);
        do_pt= COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);
        printf(HIR"攻击力： %d\t"NOR+HIR"防御力： %d\t\n"NOR,
        at_pt+1, pa_pt/2+do_pt/2+1
        );
	printf("/cmds/skill/skills"->pet_skill(this_object()));
	 printf(HIC"≡"HIY"──────────────────────────────"HIC"≡\n"NOR);
 return 1;
}

int do_cun(string arg)
{
	object me, ob;
	me = this_player();
	ob = this_object();
if (!arg)
return notify_fail("你要让谁存档？\n");
if (arg !=query("id"))
return notify_fail("你要让谁存档？\n");
if(member_array(this_player()->query("id"),
this_object()->query("parents"))<0)
		return notify_fail ("自己的孩子自己管，你不用担这份心啦。\n");        
        if ( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n");

        if ( me->is_fighting() )
                return notify_fail("你还是专心作战吧！\n");

	me->set("baby/age",(int)this_object()->query("age"));
        me->set("baby/exp",(int)this_object()->query("combat_exp"));
//        me->set("baby/skills",this_object()->query("skills"));
        me->set("baby/skills",this_object()->query_skills());
        
        if (!wizardp(me)) me->start_busy(8);
//	write("年龄"+(int)this_object()->query("age")+"\n");
//	write("经验"+(int)this_object()->query("combat_exp")+"\n");
//	write("武功"+this_object()->query("skills")+"\n");
//	write("年龄"+(int)me->query("baby/age")+"\n");
//	write("经验"+(int)me->query("baby/exp")+"\n");
//	write("武功"+me->query("baby/skills")+"\n");

	write("孩子的情况已经储存完毕。\n");
	return 1;
}

int do_teach(string arg)
{
	object me, ob;
	int gin_cost,amount, myskill, itskill;
	string student, skill;

	me = this_player();
	ob = this_object();

        if ( me->is_busy()) return notify_fail("你现在正忙着呢。\n");

        if ( me->is_fighting() ) return notify_fail("你不能在战斗中教人知识。\n");

	if ( !arg || (sscanf(arg, "%s about %s", student, skill) != 2) )
		return notify_fail("指令格式：jiao <某人> about <技能>\n");

	if ( student != ob->query("id") ) return notify_fail("你要教谁？\n");

	if ( !myskill = me->query_skill(skill, 1)) return notify_fail("这项技能你好象还不会呢！\n");

if( !SKILL_D(skill)->valid_learn(ob) ) return notify_fail("宝宝显然无法学会这项技能！\n");

if(member_array(this_player()->query("id"),
this_object()->query("parents"))<0)
		return notify_fail ("自己的孩子自己教，你不用担这份心啦。\n");

	if ( !living(ob) ) return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");

	if ( ! ob->query("is_baby") ) return notify_fail("人家也有师傅，有得着你来教？\n");

	itskill = ob->query_skill(skill, 1);

	if(myskill <= itskill) return notify_fail( ob->name()+"以嘲笑的目光望着你。\n");

	if( (int)me->query("potential") < 1 ) return notify_fail("你的潜能不够！\n");

	if((int)me->query("potential") - (int)me->query("learned_points") < 100 ) 
         return notify_fail("你的潜能太少了!\n");	

	gin_cost = (int)ob->query_int();

	if( (int)me->query("jing") < gin_cost) return notify_fail("你显然太累了没有办法教！\n");

	me->receive_damage("jing", gin_cost);
	amount = (int)me->query("int") + (int)ob->query("int");

	message_vision(sprintf("$N不厌其烦地教$n「%s」。\n", to_chinese(skill)), me, ob);

	if(ob->query("age") < 5) {
ob->add( "combat_exp", 1);
		me->start_busy(1);
if (random(2)==1)
me->add("potential",-1);
		if (ob->query("age") < 5)
			message_vision("$n哇哇地大哭起来，$N说什么也哄不住。\n", me, ob);
		else
			message_vision("$n大哭大闹，说什么也不听$N话。\n", me, ob);
	}
	else {
		ob->add_skill(skill, amount);
		ob->add( "combat_exp", amount/20+random(amount/20) );
		message_vision(sprintf("$N似乎真的学会了一些「%s」！\n", to_chinese(skill)), ob);
me->add("potential",-1);
		me->start_busy(1);
	}
	return 1;
}

varargs void add_skill(string skill, int amount)
{
	if( !find_object(SKILL_D(skill)) && file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) ) skills = ([]);
	if( undefinedp(skills[skill]) ) skills[skill] = 0;

	if( !amount ) amount = 1;

	if( !mapp(learned) ) learned = ([ skill : amount ]);
	else (int)learned[skill] += amount;

	if( learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) ) {
		skills[skill]++;
		learned[skill] = 0;
		this_object()->improve_skill(skill, skills[skill]+1);
	}
}

int accept_object(object me, object obj)
{
	object ob;
	ob = this_object();
if(member_array(this_player()->query("id"),
this_object()->query("parents"))<0)
		return notify_fail ("人家父母会照顾自己的孩子啦。\n");
if (obj->is_character())
	return notify_fail("你想把活人送人??\n");

        return 1;
}




int do_make(string arg)
{
    object baby;
    int number;
object me,obj;
me=this_player();
obj=this_player();
if (!arg)
return notify_fail("你要看谁的状态？\n");
if (arg !=query("id"))
return notify_fail("你要看谁的状态？\n");

    baby=new("/d/taohuacun/npc/baby2");
    baby->set("long", baby->query("long")+"这是"+obj->query("name")+"和"+me->query("name")+"的孩子。\n");
    if (random(100)<50)
    {
        baby->set("gender","男性");
        baby->set_name("小"+obj->query("name"),({"xiao "+obj->query("id"),"baby"}));
    }
    else
    {
        baby->set("gender","女性");
        baby->set_name("小"+me->query("name"),({"xiao "+me->query("id"),"baby"}));
    }
    me->add("child",1);
    baby->set("parents",({me->query("id"),me->query("id")}));
    number=me->query("child");
    me->set("child_"+number+"/gender",baby->query("gender"));
    me->set("child_"+number+"/long",baby->query("long"));
    me->set("child_"+number+"/name",baby->query("name"));
    me->set("child_"+number+"/id",({baby->query("id"),"baby"}));
    me->set("child_"+number+"/parents",baby->query("parents"));
    me->delete_temp("is_bearing");
    me->save();
    obj->save();
   //this needs to be put at the last since
   //can only move the baby after it's parameters are set.
    if(!baby->move(environment(me)))
        baby->move(environment(environment(me)));
return 1;
}



int do_order(string arg)
{
	object me = this_player();
	string type, cmd;
	int i;
	
	seteuid(getuid());

	if( !arg ) 
		return notify_fail("你想让宝宝做什么？\n");
	if ((sscanf(arg, "%s %s", type, cmd) < 2 ))
		return notify_fail("指令格式：order [un]accept object | [un]accept fight | <指令>\n");

	if (!living(this_object()))
		return notify_fail("现在不可能啦？\n");

if(member_array(this_player()->query("id"),
this_object()->query("parents"))<0)
		return notify_fail ("自己的孩子自己管，你不用担这份心啦。\n");        

	for (i = 0; i < sizeof(cmds); i++)
		if (cmds[i] == type) {
			exec_cmd(me, arg);
			return 1;
		}
	return notify_fail("你只能对她下达战斗指令！\n");
}
void exec_cmd(object me, string arg)
{
	if (!command(arg))
		write("宝宝现在无法正确执行你的命令！\n");
	else
		command("nod");
}
