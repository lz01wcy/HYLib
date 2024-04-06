#include <ansi.h>
inherit NPC;

string *nm1_jp =({
"山本","龟田","姿三","大岛","松下","横田","东芝","候本","川野","山口",
"铃木","岗仓","小岛","井上","安奈","浅田","佐藤","广末","大竹","大村",
"伯佐","富冈","东乡",
});

string *id_jp =({
"shanben","guitian","zisan","dadao","songxia","hengtian","dongzhi","houben","chuangye","shankou",
"lingmu","gangcang","xiaodao","jinshang","annai","qiantian","zuoteng","guangmu","dazhu","dachun",
"bozuo","fugang","dongxiang",
});    
    
string *nm2_jp =({
"太郎","次郎","三郎","四郎","五郎","十一郎","十四郎","二十六","俊树",
"宁次","英机","冶字","俊雄","牧夫","光夫","敬一","英世","漱石","渝吉",
"一叶","子规","稻造","伊冲","松园","深水","大观","丰国","孝和","茂",
"川","卫","岛寿","光云","安治","山乐","梦二",
});

void create()
{
   int i = random(sizeof(nm1_jp));
    set_name(nm1_jp[i]+nm2_jp[random(sizeof(nm2_jp))], ({id_jp[i]}));
    set("gender", "男性" );//性别与上面对应
//        set_name("倭寇曹长", ({ "wokou", "japan wokou" }) );
        set("long",
"一个身长不足四尺满脸又是伤疤加横肉的小日本。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("nickname",HIW"倭寇曹长"NOR);
  set("force_factor",2+random(390));
  set("max_qi",300+random(590));
  set("max_jing",300+random(590));
  set("max_sen",300+random(590));
  set("max_neili",300+random(590));
  set("max_mana",300+random(590));
  set("eff_neili",300+random(390));
  set("neili",300+random(590));
        set("per", 1);
        set("age", 22);
        set("shen", -5000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 150000+random(1300000));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
		            (: random_move :),
        }) );
        set("chat_chance", 10);
        set("chat_msg", ({
                "倭寇曹长喝道：男人的,统统的杀啦,杀啦的！！\n",
                "倭寇曹长笑道：花姑娘的,留下,让皇军快活,快活的!\n",
                "倭寇曹长笑道：杀!统统的杀啦,杀啦的！！\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 50+random(150));
        set_skill("blade", 50+random(150));
        set_skill("parry", 50+random(150));
        set_skill("dodge", 50+random(150));
        set_skill("wind-blade", 50+random(350));
        
        map_skill("blade", "wind-blade");
        map_skill("parry", "wind-blade");
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

        setup();

        carry_object(__DIR__"obj/japancloth")->wear();
        carry_object(__DIR__"obj/japanblade")->wield();
	add_money("silver", random(50));
}
void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if( userp(ob[i]) && ob[i]->query("combat_exp") < 80000) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
if (me)
{
        message_vision(WHT"$N大叫一声,天皇万岁!!倒地而亡。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 600000)   {
        message("vision", me->name() + "由于成功的保卫了祖国,增加了600经验和300潜能。\n", me);
        me->add("combat_exp",600);
        me->add("potential",300);
        destruct(ob);
        }
        message("vision", me->name() + "成功的保卫了祖国。\n", me);
        me->add("score",2);
        me->add("shen",10);
        destruct(ob);
        return;
}
}
