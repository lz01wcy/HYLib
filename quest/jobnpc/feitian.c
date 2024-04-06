// jianxin.c
// 青云(diabio)版权所有
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_fail();
string  ask_job();
string ask_me();
string ask_dao();
string ask_give();
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
        set("nickname", HIW"拔刀R"NOR);
              set("title", HIR"前维新志士"NOR);
        set("gender", "男性");
        set("age", 26);
        set("attitude", "peaceful");
        set("str", 47);
        set("int", 42);
        set("con", 45);
        set("per", 45);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));
        set("qi",10000);
        set("eff_jing",5000);
        set("jing",5000);
        set("eff_qi",10000);
        set("max_qi",10000);
        set("max_jing",5000);
        set("neili", 10000);
        set("max_neili", 15000);
        set("jiali", 50);
        set("shen",5000000);

        set("combat_exp", 3000000);

        set_skill("unarmed", 250);
        set_skill("force", 260);
        set_skill("parry", 280);
        set_skill("dodge", 250);
                set_skill("cuff",200);
        set_skill("blade", 300);
        set_skill("literate", 250);
        set_skill("xuanhualiu-quanfa", 250);
        set_skill("feitian-yujianliu",300);
        set_skill("wuxing-dun", 250);
        set_skill("shayi-xinfa", 320);
        set_skill("shayi", 300);
//        set_skill("bearart", 1100);
       

        map_skill("force", "shayi-xinfa");
        map_skill("parry", "feitian-yujianliu");
        map_skill("blade", "feitian-yujianliu");
        map_skill("dodge", "wuxing-dun");
        map_skill("unarmed", "xuanhualiu-quanfa");

        create_family("飞天御剑流", 6, "掌门");
        set("book_count",1);
        set("inquiry", ([
           "逆刃刀": (: ask_me :),
           "铸刀": (: ask_dao :),
           "逆刃刀真打": (: ask_give :),
           "十刃":     "那是志志奇召集的十大高手。",
           "九头龙闪": "这是本门除了天翔龙闪外的最高剑决,如没有扎实的根底别轻易尝试。你想试试(accept test)？\n",
           "逆刃刀": (: ask_me :),
   	    "维新"  : (: ask_job :),
	    "shirenjob"  : (: ask_job :),
            "jobfail" : (: ask_fail() :),
            "任务失败" : (: ask_fail() :),
            ]));
        setup();
      carry_object("/clone/cloth/cloth")->wear();
      carry_object("/d/feitian/npc/obj/shoes")->wear();
          carry_object("/d/feitian/npc/obj/nirendao")->wield();
}


void die()
{
int i,pot,exp;
	object killer;
	exp= random(80)+80;
	pot= exp/3;
	if(objectp(killer = query_temp("last_damage_from")))
        	tell_object(killer,"你被奖励了\n"+chinese_number(exp)+"点实战经验\n"
		+chinese_number(pot)+"点潜能\n");
if (killer)
{
	killer->add("combat_exp",exp);
	killer->add("potential",pot);
}
	::die();

return ;
}