// qiangdao.c 强盗
// lag.2000/3/17

inherit NPC;
#include <ansi.h>
void move();

void create()
{       object me;
        int myskill;
        me=this_player();
        myskill=me->query_skill("force");
        set_name(HIC "昆仑派叛徒" NOR, ({ me->query("id")+"-pantu"}));
        set("title",me->query("name")+"定下的");
        set("gender", "男性");
        set("age", 28);
        set("long", "他是一个昆仑派叛徒。\n");
        
        set("attitude", "peaceful");
        set("qi", me->query("max_qi")* 4 / 5);
        set("eff_qi", me->query("max_qi")* 4 / 5);
        set("max_qi", me->query("max_qi")* 4 / 5);
        set("jing", me->query("max_jing")* 4 / 5);
        set("eff_jing", me->query("max_jing")* 4 / 5);
        set("max_jing", me->query("max_jing")* 4 / 5);
        set("neili", me->query("neili")* 4 / 5);
        set("max_neili", me->query("max_neili")* 4 / 5);

        set("str", me->query("str")* 4 / 5);
        set("dex", me->query("dex")* 4 / 5);
        set("per", me->query("per")* 4 / 5);
        set("killer",me->query("id"));
        set("combat_exp", me->query("combat_exp")* 4 / 5);
// 加下面5句是让强盗自动走，增添玩家做机器人的困难！-糖圆SMILE
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "strike.yixing" :),
                (: perform_action, "strike.diezhang" :),
                (: command("unwield qin") :),
                (: command("wield qin") :),
                (: perform_action, "sword.jianqin" :),
                (: perform_action, "sword.ren" :),
                (: perform_action, "sword.feixue" :),
              (: random_move :),
              (: random_move :),
        }) );
             set("chat_chance", 30);
             set("chat_msg", ({
              (: random_move :)
        }) );


        set_skill("strike", myskill * 1/ 2);
        set_skill("dodge", myskill * 1 / 2);
        set_skill("unarmed", myskill* 1 / 2);
        set_skill("parry", myskill* 1 / 2);
        set_skill("force", myskill* 1 / 2);
        set_skill("blade", myskill* 1 / 2);
        set_skill("lingboweibu", myskill* 4 / 5);
        set_skill("ruyi-dao", myskill* 4 / 5);
        set_skill("liuyang-zhang", myskill* 4 / 5);
        set_skill("zhemei-shou", myskill* 4 / 5);
        set_skill("xuantian-wuji", myskill* 4 / 5);
        set_skill("kunlun-shenfa", myskill* 4 / 5);
        set_skill("kunlun-zhang", myskill* 4 / 5);
        set_skill("liangyi-jian", myskill* 4 / 5);
        set_skill("art", myskill* 4 / 5);
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("strike", "kunlun-zhang");
	map_skill("parry", "art");
	map_skill("sword", "liangyi-jian");
	prepare_skill("strike", "kunlun-zhang");
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 250);
        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/kunlun/obj/jwqin.c")->wield();

}

void init()
{
        remove_call_out("leave");
        call_out("leave",100);
}


void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "昆仑派叛徒钻进路边的杂草，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

void unconcious()
{
    die();
}

void die()
{
        object me = this_object()->query_temp("last_damage_from");
        object corpse,zhi;      
if (!me) return;

if (me)
{
        message_vision(HIR "\n昆仑派叛徒倒在地上，挣扎了几下就死了。\n" NOR,me);
        message_vision(HIG "\n你从叛徒的身上找到了奇药。\n" NOR,me);
        if (me->query("kill_kunlun") == 1 && this_object()->query_temp("owner/id") == me->query("id")) {
               zhi=new(__DIR__"zhi");
               zhi->set("byname",me->query("name"));
               zhi->move(me);
                me->add("score",2);
                }

        corpse = new("/clone/misc/corpse");
        corpse->set("name",HIW "昆仑派叛徒的尸体" NOR);
        corpse->set("long","他是一个曾经无恶不做的昆仑派叛徒，\n然而，他已经死了，剩下一具丑陋的尸体。\n");
        corpse->move(environment(this_object()));
        corpse->set_max_encumbrance(1000);        
        me->add("MKS", 1);
}
        destruct(this_object());
}


