#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#define __THD__ "/d/taohua/"

void consider();
string ask_me();
int ask_marry();
int ask_test1();
int ask_test2();
int ask_test3();
int ask_nvxu();

int ask_zhou();

void create()
{
    set_name("黄药师", ({"huang yaoshi", "huang", "yaoshi"}));
    set("title", "桃花岛主");
    set("nickname", HIY "东邪" NOR );
    set("gender", "男性");
    set("age", 42);
        set("long", 
                "他就是桃花岛的岛主，江湖上人人闻名变色的东邪黄药师。\n"
                "他身穿一件青色长袍，腰带上斜插着一只玉箫。\n"
                "他形相清癯，丰姿隽爽，萧疏轩举，湛然若神。\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 61);
    set("int", 60);
    set("con", 66);
    set("dex", 60);
    set("per", 60);

    set("chat_chance", 1);
    set("chat_msg", ({
        "黄药师叹了口气道：“唉 …… 蓉儿这苦命的孩子，从小就没了娘 ……”\n",
        "黄药师低头沉思，悠然不语。\n",
    }));
/*    set("inquiry", ([
        "黄蓉"     : "你敢直称我女儿的闺名？ \n",
        "九阴真经" : "如果你能帮我取得真经上册，我一定重重谢你。\n",
    ]));*/

    set("qi", 29000);
    set("max_qi", 29000);
    set("jing", 18000);
    set("max_jing", 18000);
    set("neili", 53500);
    set("max_neili", 53500);
    set("jiali", 100);

    set("book_count", 1);
    set("combat_exp", 9000000);
    set("score", 0);
	 
    set_skill("leg", 380);             // 基本内功
    set_skill("force", 280);             // 基本内功
    set_skill("bibo-shengong", 380);     // 碧波神功
    set_skill("claw", 200);              // 基本爪法
    set_skill("hand", 320);              // 基本手法
    set_skill("finger", 320);            // 基本指法
    set_skill("tanzhi-shentong", 380);   // 弹指神通
    set_skill("unarmed", 280);           // 基本拳脚
    set_skill("strike", 280);            // 基本拳脚
    set_skill("luoying-zhang", 380);     // 落英神剑掌
    set_skill("xuanfeng-leg", 380);      // 旋风扫叶腿
    set_skill("dodge", 280);             // 基本躲闪
    set_skill("anying-fuxiang", 380);    // 暗影浮香
    set_skill("parry", 200);             // 基本招架
    set_skill("sword", 320);             // 基本剑法
    set_skill("luoying-shenjian", 380);  // 落英神剑
    set_skill("yuxiao-jian", 380);       // 玉箫剑法
    set_skill("lanhua-shou", 380);       // 兰花拂穴手
    set_skill("qimen-wuxing",380);       // 奇门五行
    set_skill("count",380);              // 阴阳八卦
    set_skill("literate",380);           // 读书识字
	  set_skill("chixin-jian", 380);             // 基本内功
    set_skill("canglang-bian", 380);             // 基本内功
    set_skill("whip", 380);             // 基本内功
    map_skill("strike"  , "luoying-zhang");
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("whip"   , "canglang-bian");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("leg" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "chixin-jian");
    map_skill("parry"  , "luoying-zhang");    	

if (random(3)==0)
{
    	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-leg");
}
else
{
	prepare_skill("finger", "tanzhi-shentong");
	prepare_skill("hand", "lanhua-shou");	
}
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "qimenzhen" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "strike.pikong" :),                
                (: perform_action, "leg.wuying" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
		(: command("unwield yuxiao") :),
		(: command("wield yuxiao") :),
		(: command("unwield bian") :),
(: command("wield bian") :),
(: perform_action, "finger.ding" :), 
	(: perform_action, "finger.zhuan" :), 
(: perform_action, "sword.muyu" :),                
	(: perform_action, "sword.nosword" :),                
		(: perform_action, "sword.trhy" :),                
		(: perform_action, "whip.duoming" :),                
		(: perform_action, "whip.lang" :),                
		(: perform_action, "whip.tlyj" :),                
		(: perform_action, "whip.yljx" :),                									
 
        }));
    set("inquiry", ([
                "name": "难道天底下就没人知道我东邪黄药师的名字了吗？",
                "rumors": "听说全真教那帮牛鼻子在到处找周伯通，哼！",
                "东邪": "那都是江湖上那班满嘴仁义道德的家伙给我起的绰号。",
                "西毒": "以前的西毒是欧阳锋那只臭蛤蟆，除了会耍两手蛇外，没什么真功夫。",
                "欧阳锋": "那只臭蛤蟆，除了会耍两手蛇外，没什么真功夫。",
                "南帝": "以前的南帝是大理的王爷段智兴，现在出家做和尚，改叫一灯啦。",
                "一灯": "以前是大理的王爷段智兴，现在出家做和尚，改叫一灯啦。",
                "段智兴": "以前是大理的王爷，现在出家做和尚，改叫一灯啦。",
                "北丐": "以前的北丐是洪七公那个老叫化，几手降什么十八掌倒还使得。",
                "洪七公": "那个老叫化是丐帮帮主，几手降什么十八掌倒还使得。",
                "中神通": "以前的中神通是全真教的臭道士王重阳，要不是老夫一时失手，武林第一的称号也不会被他抢走。",
                "王重阳": "是全真教的臭道士，要不是老夫一时失手，武林第一的称号也不会被他抢走。",
                "周伯通": "这个大傻瓜，被我骗了都不知道，你如果想找他，嘿嘿嘿....",
                "老顽童": "这个大傻瓜，被我骗了都不知道，你如果想找他，嘿嘿嘿....",
                "黄蓉": "唉，从小就对她娇生惯养，现在她调皮任性，我也没办法了。",
                "蓉儿": "唉，从小就对她娇生惯养，现在她调皮任性，我也没办法了。",
                "郭靖": "别提我这个傻女婿了。",
                "女婿": (: ask_nvxu :),
                "乘风": "是我的四弟子，现在住在归云庄。",
                "陆乘风": "是我的四弟子，现在住在归云庄。",
                "黄药师": "就是老夫我。怎么，不服吗？咱俩练练？",
                "九宫": "九宫之义，法以灵龟。二四为肩，六八为足；左三右七，戴九履一；五居中间。",
                "八卦": "乾三连，坤六段；离中虚，坎中满；震仰盂，艮覆碗；兑上缺，巽下断。",
                "五行": "金生水，水生木，木生火，火生土，土生金。金克木，木克土，土克水，水克火，火克金。",
                "易经": "是一本讲解伏羲六十四卦的奇书，一般人难得看懂。",
                "周易": "是一本讲解伏羲六十四卦的奇书，一般人难得看懂。",
                "九阴真经": "你打听这个干什么？！",
                "和尚": "老夫我对和尚就是瞧不惯！",
                "求婚": (: ask_marry :),
                "第一关": (: ask_test1 :),
                "test1": (: ask_test1 :),
                "第二关": (: ask_test2 :),
                "test2": (: ask_test2 :),
                "第三关": (: ask_test3 :),
                "test3": (: ask_test3 :),
        "秘籍" : (: ask_me :),
        "旋风扫叶腿法" : (: ask_me :),
      	"周伯通": (: ask_zhou :),
    ]));


    create_family("桃花岛", 1, "岛主");
    setup();
	
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
if (random(3)==0)
{	
	 carry_object(__DIR__"obj/yuxiao")->wield();
carry_object(__DIR__"obj/hlbian");
}
else
{
carry_object(__DIR__"obj/hlbian")->wield();
carry_object(__DIR__"obj/yuxiao");
}
    carry_object(__DIR__"obj/bupao")->wear();
//    carry_object("clone/book/jiuyin2");
    
}

void attempt_apprentice(object ob)
{
        string old_name, new_name;
    if (ob->query_int() < 30) {
        command("say 我不收资质差的弟子，您请回吧！");
		return;
    }
        if (ob->query("gender") != "男性" && ob->query("gender") != "女性") {
                command("say 你不男不女的算什么东西？快滚！");
                return;
        }
        if (ob->query("shen") <= -200000) {
                command("say 我生平最讨厌两种人，你们这种无恶不作的邪魔外道就是其一，哼！");
                return;
        }
        if (ob->query("shen") >= 200000) {
                command("say 我生平最讨厌两种人，你们这种自命大侠的沽名钓誉之徒就是其一，哼！");
                return;
        }
        if (ob->query_int() < 28) {
                command("say 看你这副模样，比我那傻女婿还笨，还想拜我为师？");
                return;
        }
        if (!ob->query_skill("literate")) {
                command("say 你这个文盲也想来学功夫？先去学点文化吧。");
                return;
        }


        if (ob->query("class") == "bonze") {
                if (ob->query("family/family_name") == "少林派")
                        command("say 你们自命天下武功出少林，我这里的庙小，可不敢收你。");
                else
                        command("say 我东邪最讨厌和尚，看到光头就有气，所以连尼姑、喇嘛一起都不收。");
                return;
        }

    if ((int)ob->query_skill("bibo-shengong",1) < 50 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
		return;
    }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say 我桃花岛与世隔绝，向来不与您这种成名人物打交道，您请回吧！");
		return;
	}

    command("say 很好，很好。");
    command("recruit " + ob->query("id"));
                command("chat 哈哈哈哈！！！！");
                command("chat 想不到我东邪误逐弟子之后，还能得此良才美质，真是可喜可贺。");
                command("recruit " + ob->query("id"));
                old_name = ob->query("name");
                new_name = old_name[0..3] + "风";
                ob->set("name", new_name);
                say(old_name + "拜入黄药师门下，位列二代弟子“风”字辈，起名为" + new_name + "。\n");

}

int recognize_apprentice(object ob)
{
	mapping myfam;
       	myfam = (mapping)ob->query("family");
        if ( myfam["family_name"] == "桃花岛") return 1 ;
	if ((int)ob->query_temp("tmark/黄") == 1 )
        message_vision("黄药师看了看$N，说道：咱们现在是谁也不欠谁,\n"
                          "你不要再找我学习技艺了。\n", ob);
	if (!(int)ob->query_temp("tmark/黄"))
		return 0; 
	ob->add_temp("tmark/黄", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	
	if ( (string) ob->query("id") =="jiuyin zhenjing1" ) {
 		if (!(int)who->query_temp("tmark/黄")) who->set_temp("tmark/黄", 0);
		message_vision("黄药师看了看$N送来的秘籍，点了点头，说道：\n"
                               "难得你将真经送回。你送我的东西我就收下了。\n"
                               "作为补偿,你可以从我这里学点功夫。\n", who);
		who->add_temp("tmark/黄", 120);
		return 1;
	}
	return 0;
}
string ask_me()
{
	object ob;
	
	if (this_player()->query("family/master_id")!="huang yaoshi")
		return RANK_D->query_respect(this_player()) + 
		"非我弟子，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本派的秘籍不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/xuanfeng_book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到旋风扫叶腿法啦。\n");
	return "好吧，这本「旋风扫叶腿法」你拿回去好好钻研。";
}
//void die()
//{
//message("channel:rumor", MAG"【谣言】某人："+this_player()->query("name")+"抢了九阴真经下卷啦。\n"NOR, users());
//	::die();
//}
int ask_zhou()
{
	command("say 这家伙有九阴真经的上卷，就是死也不肯交出来。");
	command("sneer");
	command("say 我将他困在岛上，看他能撑到几时！");
	this_player()->set_temp("jiuyin/huang", 1);
	return 1;
}
void init()
{
        object ob = this_player();

        add_action("do_answer","answer");
        add_action("do_answer","huida");
        ::init();

}


int ask_marry()
{
        object nvxu, user;
        object ob = this_player();
        string id;
        int user_load = 0, user_exist = 1;

        if (ob->query("gender") != "男性" && ob->query("gender") != "女性") {
                command("sneer " + ob->query("id"));
                command("say 你也想娶老婆？下辈子吧！");
                return 1;
        }
        if (ob->query("gender") == "女性") {
                command("say 你当我女儿是同性恋啊？快滚！");
                return 1;
        }
        if (ob->query("class") == "bonze") {
                command("sneer " + ob->query("id"));
                command("say 和尚也动了凡心，想娶老婆？先还俗再说吧！");
                return 1;
        }
        if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
                nvxu = load_object("/clone/npc/huang-son-in-law");
        id = nvxu->query("winner");
        if (id) {
                if (id == ob->query("id") && nvxu->query("death_count") == ob->query("death_count")) {
                        say(CYN"黄药师笑道：" + RANK_D->query_rude(ob) + "，还不快叫岳父？！\n"NOR);
                        return 1;
                }
                if (!(user = find_player(id))) {
                        user = new(USER_OB, id);
                        user->set_name("", ({ id }));
                        if (!user->restore()) {
                                destruct(user);
                                user_exist = 0;
                        }
                        else user_load = 1;
                }
/*                if (user_exist && nvxu->query("death_count") == user->query("death_count")) {
                        command("say 小女已经许配给" + nvxu->query("name") + "了。");
                        if (user_load) destruct(user);
                        return 1;
                }*/
                if (user_load) destruct(user);
        }
        if (ob->query("marry")) {
                command("sneer " + ob->query("id"));
                command("say 你不是已经娶了妻子了吗？我最恨负心薄幸的人，再来罗嗦，休怪老夫无理！");
                return 1;
        }
        if ((int)ob->query("shen") <= -200000) {
                command("say 我生平最讨厌两种人，你们这种无恶不作的邪魔外道就是其一，哼！");
                return 1;
        }
        if ((int)ob->query("shen") >= 200000) {
                command("say 我生平最讨厌两种人，你们这种自命大侠的沽名钓誉之徒就是其一，哼！");
                return 1;
        }
        if (ob->query("age") > 49) {
                command("sneer " + ob->query("id"));
                command("say 你这么个糟老头也想做我女婿？干脆我做你女婿算了。\n");
                return 1;
        }
        if (ob->query("class") == "taoist") {
       command("say 我东邪最讨厌道士，看到道士就有气！");
                return 1;
        }

        if (ob->query("age") < 20) {
                command("say 你还小，等长大了再来吧。\n");
                command("pat " + ob->query("id"));
                return 1;
        }
        command("say 好吧，不过我要出三道试题考考你。");
        command("say 第一道是武功，第二道是音律，第三道是默写。");
        command("say 必须三阵都不输掉才行！");
        command("say 要是准备好了就来过第一关吧！");
        ob->set_temp("thd_marry", 1);
        return 1;
}

int ask_test1()
{
        object ob=this_player();
        object me=this_object();
        object obj;

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") > 1) {
                command("say 已经过了这关还来罗嗦什么！");
                return 1; 
        }
        
        set("combat_exp", 2000000);
        set("jiali", 100);
        if (present("yuxiao",me))
                command("unwield yuxiao");
        prepare_skill("strike");
        prepare_skill("leg");
        prepare_skill("hand");
        prepare_skill("finger");
        prepare_skill("sword");
        me->reset_action();
        prepare_skill("strike", "luoying-zhang");
        say("\n黄药师喝道：第一招是落英神剑掌，小心接招了！\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
          if (!present("yuxiao",me))
        if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
        else
                command("wield yuxiao");
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat 如此不济，也想做我的女婿？！");
                if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
                else
                        command("wield yuxiao");
                prepare_skill("finger");
                me->reset_action();
                prepare_skill("strike", "luoying-zhang");
                prepare_skill("leg", "xuanfeng-leg");
                set("combat_exp", 2500000);
                set("jiali", 120);
                return 1;
        }
        prepare_skill("strike");
        me->reset_action();
        prepare_skill("strike", "luoying-zhang");
        say("\n黄药师喝道：第二招是玉箫剑法，小心接招了！\n");
        if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
                command("wield yuxiao");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat 如此不济，也想做我的女婿？！");
                if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
                else
                        command("wield yuxiao");
                prepare_skill("finger");
                me->reset_action();
                prepare_skill("strike", "luoying-zhang");
                prepare_skill("leg", "xuanfeng-leg");
                set("combat_exp", 2600000);
                set("jiali", 200);
                return 1;
        }
        if (present("yuxiao",me))
                command("unwield yuxiao");
        prepare_skill("strike");
        me->reset_action();
        prepare_skill("hand", "lanhua-shou");
        say("\n黄药师喝道：第三招是兰花拂穴手，小心接招了！\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat 如此不济，也想做我的女婿？！");
                if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
                else
                        command("wield yuxiao");
                prepare_skill("finger");
                me->reset_action();
                prepare_skill("strike", "luoying-zhang");
                prepare_skill("leg", "xuanfeng-leg");
                set("combat_exp", 3000000);
                set("jiali", 200);
                return 1;
        }
        prepare_skill("hand");
        me->reset_action();
        prepare_skill("finger", "tanzhi-shentong");
        say("\n黄药师喝道：第四招是弹指神通，小心接招了！\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
        else
                command("wield yuxiao");
        prepare_skill("finger");
        me->reset_action();
        prepare_skill("strike", "luoying-zhang");
        prepare_skill("leg", "xuanfeng-leg");
        set("combat_exp", 3200000);
        set("jiali", 200);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat 如此不济，也想做我的女婿？！");
                return 1;
        }

command("wield yuxiao");
        write("黄药师说道：好吧，这第一关就算你过了。\n");
        write("黄药师说道：你要是准备好了就来过第二关吧！\n");
        tell_room(environment(ob), "黄药师对" + ob->name() + "说道：好吧，这第一关就算你过了。\n", ({ob}));
        ob->set_temp("thd_marry", 2);
        return 1;
}

int ask_test2()
{
        object ob=this_player();

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") < 2) {
                say("黄药师喝道：怎么，想作弊么？！\n");
                return 1; 
        }
        if (ob->query_temp("thd_marry") > 2) {
                command("say 已经过了这关还来罗嗦什么！");
                return 1; 
        }
        
        command("say 所谓五音，除了宫商角徵外，还有一个是什么？");
        return 1;
}

int ask_test3()
{
        object ob=this_player();

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") < 3) {
                say("黄药师喝道：怎么，想作弊么？！\n");
                return 1; 
        }
        command("say 九阴真经言道：天之道，损有余而补不足，是故....，后面的三个字是什么？");
        return 1;
}

int ask_nvxu()
{
        object nvxu, user;
        object ob = this_player();
        string id;
        int user_load = 0;

        if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
                nvxu = load_object("/clone/npc/huang-son-in-law");
        id = nvxu->query("winner");
        if (id == ob->query("id")) {
                if (nvxu->query("death_count") < ob->query("death_count"))
                        command("say 小女现在仍然待字闺中。");
                else
                        say(CYN"黄药师笑道：" + RANK_D->query_rude(ob) + "，还不快叫岳父？！\n"NOR);
        }
        else {
                if (id) {
                        if (!(user = find_player(id))) {
                                user = new(USER_OB, id);
                                user->set_name("", ({ id }));
                                if (!user->restore()) {
                                        command("say 小女现在仍然待字闺中。");
                                        destruct(user);
                                        return 1;
                                }
                                user_load = 1;
                        }
                }
                if (!id || nvxu->query("death_count") < user->query("death_count"))
                        command("say 小女现在仍然待字闺中。");
                else
                        command("say 我已把小女许配给" + nvxu->query("name") + "为妻了。");
                if (user_load) destruct(user);
        }
        return 1;
}

int do_answer(string arg)
{
        object ob = this_player();
        object nvxu;
        object obj;
    int payed;

        if (ob->query_temp("thd_marry") == 2) {
                tell_room(environment(ob), ob->name() + "在黄药师的耳边小声嘀咕了一句。\n", ({ob}));
                if (arg == "羽") {
                        if (!present("yuxiao",this_object()))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
command("wield yuxiao");
                        command("say 好小子，不错，再听听我的《碧海潮生曲》。\n");
                        write("黄药师从怀中取出一支玉箫，放到嘴边吹了起来。你仿佛置身大海之中，海潮汹涌而来，似乎要将你吞没。\n");
                        write("再撑得一阵，你但觉寒冬酷暑，交替而来。\n");
                        ob->delete_temp("thd_marry");
                        ob->unconcious();
                        message("vision", "黄药师喊过几个仆役来：把这个昏迷不醒的家伙丢到海里去！\n", environment(ob), ob);
                        ob->move(__THD__"haitan");
                        message("vision","忽然一个大潮涌了过来，将一个被水泡得半死的家伙冲到了岸边。\n",environment(ob),ob);
                        return 1;
                }
                else
                        if (arg == "我不知道" || arg == "不知道" || arg == "dunno") {
                                if (!present("yuxiao",this_object()))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
command("wield yuxiao");
                                command("sneer " + ob->query("id"));
                                command("say 这都答不出？！\n");
                                write("黄药师从怀中取出一支玉箫，放到嘴边吹了起来。你茫然不知所奏为何，胡乱击起节拍来。\n");
                                write("黄药师似乎受了你的影响，吹了一会就不再继续了。\n");
                                write("黄药师说道：好吧，这第二关就算是个平手。\n");
                                write("黄药师说道：你要是准备好了就来过第三关吧！\n");
                                tell_room(environment(ob), "黄药师对" + ob->name() + "说
道：好吧，这第二关就算是个平手。\n", ({ob}));
                                ob->set_temp("thd_marry", 3);
                                return 1;
                        }
                say("黄药师怒道：不对！\n");
                return 1;
        }
        if (ob->query_temp("thd_marry") == 3)  {
                say(ob->name() + "在黄药师的耳边小声嘀咕了一句。\n");
                if (arg == "虚胜实") {
                        command("chat* 抬头望天，喃喃说道：“阿衡，阿衡，你对我如此情重，借这少年之口来把真经授我，怎么不让我见你一面？我晚晚吹箫给你听，你可听见么！”");
                        write("黄药师说道：好吧，这第三关就算你过了。\n");
                        tell_room(environment(ob), "黄药师对" + ob->name() + "说道：好吧，这第三关就算你过了。\n", ({ob}));
                        write("黄药师笑眯眯地看着你，仿佛在期待什么。\n");
                        write("你登时醒悟，跪下来对着黄药师恭恭敬敬地磕了三个头，喊了声：“岳父”！\n");
                        tell_room(environment(ob), ob->name() + "跪下来对着黄药师恭恭敬敬地磕了三个头，喊了声：“岳父”！\n", ({ob}));
                        command("chat 从今天起，" + ob->name() + "就是我黄药师的女婿了！");
                        payed = 0;
                        if (!ob->query("benefit/yaoshi") && !payed) {
                                write("黄药师说道：小兄弟能做得我的女婿，老夫无以为赠，就给你讲些武学的高深道理吧。\n");
                                write("你听着黄药师的讲解，与心中所知的一加印证，登时领悟了许多的武学道理！\n");
                                if (ob->query("family/family_name") == "桃花岛")
                                        ob->add("combat_exp", 18000);
                                else
                                        ob->add("combat_exp", 15000);
                                ob->set("benefit/yaoshi", 1);
                                payed = 1;
                        }
//                        write("黄药师说道：你已经够资格跟我学习兰花拂穴手了，这本图解送给你。\n");
//                        new(__THD__"obj/shoufa.c")->move(ob);
                        ob->delete_temp("thd_marry");
                        if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
                                nvxu = load_object("/clone/npc/huang-son-in-law");
                        nvxu->do_copy(nvxu, ob);
                        return 1;
                }
                say("黄药师怒道：不对！\n");
                return 1;
        }
        return 0;
}
void unconcious()
{
        command("chat* 长叹一声：我纵横江湖几十载，人人听到东邪都闻名丧胆，没想到也有今天！");
        ::unconcious();
}
