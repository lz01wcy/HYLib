// demongorgon.c
#include <ansi.h>
inherit NPC;
void create()
{
     int skill;
        set_name( HIW "海洋之神" NOR, ({ "demogorgon" }) );
        set("long",
                "海洋之神神情倨傲地站在你面前，他高大的身躯跟一股令人窒息的\n"
                "可怕杀气正压得你几乎喘不过气来，你的心里似乎有一个声音在告\n"
                "诉你：「 快 逃 ！！」\n");
        set("age", 7006);
        set("pursuer", 1);
    set("attitude", "peaceful");
        set("max_jing", 5000);
         set("max_qi", 500000);
        set("max_jingli", 9999);
        set("jingli", 9999);
        set("max_neili", 100000);
          set("neili", 8000000);
         set("demogorgon",1);
         set("str", 100);
        set("dex", 100+random(100));
     set("title",HIR "杀人魔" NOR);
        set("int", 100);
        set("no_suck", 1);
        set("con", 100);
        set("jiali",50000);
        set("kar", 0);
        set("per", 0);
        skill=400+random(1000);
         set("combat_exp", 200000000);
        set_skill("staff", skill/2);
        set_skill("unarmed", skill);
        set_skill("parry", skill);
        set_skill("dodge", skill);
        set_temp("apply/attack", 400);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 1200);
        set("chat_chance_combat", 10);
        set_temp("apply/parry", 300);
        set("chat_msg_combat", ({
           (: command("wield staff") :),
                CYN "海洋之神说：小王八蛋好的不学，学人干扰网络负担？看招！\n" NOR,
                CYN "海洋之神骂道：天天都有混蛋干扰网络负担，害得我连觉也睡不好！\n" NOR,
           (: command("unwield staff") :),
        }) );


        setup();
        set("water",max_water_capacity());
        set("food",max_food_capacity());
        carry_object(__DIR__"obj/demon_staff")->wield();
//        carry_object("/clone/misc/red_cloth")->wear();
}
void start_shutdown()
{
        if( geteuid(previous_object()) != ROOT_UID ) return;
        set_temp("time",-10000);
        message("system",
                HIR "\n你听到天空中传来一阵可怕的咆哮 ....\n\n"
                HIW     "海洋之神" HIR "用震耳欲聋的声音喝道：\n\n"
                        "\t\t全 天 下 的 众 生 给 我 听 著 ！\n\n"
                        "\t\t限你们三分钟内把我的头颅交出来 ！\n\n"
                        "\t\t不 然 的 话 ..... 哼 .. 哼 ！\n\n" NOR,
                users() );
        call_out("countdown", 60, 3);
}
protected void countdown(int min)
{
        min--;
        if( min ) {
                message("system",
                        HIW "\n海洋之神" HIR "用震耳欲聋的声音喝道：\n\n"
                                "\t\t你们还有" + chinese_number(min) + "分钟的时间交出我的头颅！\n\n"
                                "\t\t―不―要―命―的―就―给―我―慢―慢―拖―吧―！\n\n" NOR,
                        users() );
                call_out("countdown", 60, min);
        } else {
                message("system",
                        HIW "\n海洋之神" HIR "用震耳欲聋的声音喝道：\n\n"
                                "\t\t可恨.....真是可恨....\n\n"
                                "\t\t苍天啊～ 大地啊～  海洋啊～  众生啊～\n\n" NOR,
                        users() );
                call_out("do_shutdown", 3);
        }
}
protected void do_shutdown()
{
        object *ob;
        int i;
        message("system",
                HIW "\n\n海洋之神" HIR "用震耳欲聋的声音喝道：\n\n"
                HIW "\t\t通 通 和 我 一 起 下 地 狱 吧 ～～～～ ！\n\n"
                HIR "\t\t声音一毕，天空立刻变得血红，不....你眼前的一切都变得血红...\n\n"
                        "\t\t所有的一切都在瞬间陷入火海....\n\n"
                        "\t\t然後你的眼前是一片黑暗....无止尽的黑暗....\n\n" NOR,
                users() );
        ob = users();
        for(i=0; i<sizeof(ob); i++) {
                ob[i]->save();
        }
     NATURE_D->auto_shutdown(1);
}

void unconcious()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) return;
        message("vision",
                HIR "\n\n你听到一声带著愤恨、惊恐、与野兽般的咆哮声响彻整个天空。\n\n"
                HIW "海洋之神" HIR "嘶哑地吼著：可恶的" + ob->name(1) + "，我一定会报仇的～～～\n\n"
                        "然後一道黑色火焰呼啸著冲上云端，大地又恢复了宁静。\n\n" NOR,
          environment() );
        destruct(this_object());
}

void die()
{
   unconcious();
}

int heal_up()
{
        if (!living(this_object()))    return ::heal_up() + 1;
        if( environment() && !is_fighting() ) {
                  if (query_temp("time")>5){
                        call_out("leave", 1);
                        return 1;
                }
                if (query_temp("time")%3)
                        message_vision("$N"+"拿着探测器，到处找他要杀的人。\n",this_object());
        add_temp("time",1);
        }
        return ::heal_up() + 1;
}
void leave()
{
        message_vision("$N"+GRN+"左右看了看，发现目标已经不见了，于是迈开大步，头也不回地走了。\n"+NOR,this_object());
        this_object()->move(VOID_OB);
        destruct(this_object());
}
void killed_enemy(object obj)
{
    if (query("kill_ob")) delete("demogorgon");
       call_out("leave",1);
}
void init()
{
    ::init();
    add_action("do_go","go");
    add_action("do_kill","kill");
    add_action("do_kill","hit");
    add_action("do_kill","fight");
}

int do_go(string arg)
{
        mapping exit;
        if( !mapp(exit = environment()->query("exits")) || undefinedp(exit[arg]) )
                return 0;
        if (is_killing(this_player()))
                if (random(10)<=2) {
                        message_vision(YEL "$N见势不好，转身要走，被$n"+YEL+"一把拦在面前。想走？没那么容易！\n"NOR, this_player(), this_object());
                        return 1;
                        }
        return 0;
}

int do_kill(string arg)
{
    if (!arg) return 0;
   if (id(arg))
  {
    set("kill_ob",1);
    if (!is_killing(this_player()))
    message_vision("$N"+CYN+"恶狠狠地瞪了$n一眼：想和我打？你活腻了？\n" NOR,this_object(),this_player());
    set("eff_qi",query("max_qi"));
    set("eff_jing",query("max_jing"));
    set("jing",query("max_jing"));
    set("qi",query("max_qi"));
    add("neili",1000);
    kill_ob(this_player());
   }
    return 0;
}
