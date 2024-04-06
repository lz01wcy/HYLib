// /u/beyond/mr/npc/feng.c 风波恶
// this is made by beyond
// update 1997.6.24
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("风波恶",({"feng boe","feng","boe"}));
        set("title","玄霜庄庄主");
        set("nickname","一阵风");
  	set("long", 
              "他就是姑苏慕容玄霜庄的庄主。\n");
        set("age", 25);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 26);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 12000);
	set("max_jing", 12000);
	set("neili", 12500);
	set("max_neili", 12500);
	set("jiali", 100);
	set("combat_exp", 1850000);
	set("score", 85000);

        set_skill("strike",130);
        set_skill("blade",130);
        set_skill("dodge",130);
        set_skill("force", 130);
	set_skill("shenyuan-gong", 130);
	set_skill("yanling-shenfa", 230);
        set_skill("parry", 130);
	set_skill("xingyi-zhang", 330);
        set_skill("literate", 130);
        set_skill("murong-daofa", 350);
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("force", "shenyuan-gong");
         map_skill("strike", "xingyi-zhang");
        map_skill("finger", "canhe-zhi");
	map_skill("dodge", "yanling-shenfa");
       map_skill("parry", "murong-daofa");
       map_skill("blade", "murong-daofa");  
       prepare_skill("finger", "canhe-zhi");
        prepare_skill("strike", "xingyi-zhang");
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.riyue" :),
                	(: perform_action, "strike.xingdian" :),
                (: perform_action, "parry.xingyi" :),
                (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "blade.yingzhang" :),
                 (: perform_action, "dodge.yanling" :),                
        }));
        setup(); 
        carry_object(__DIR__"obj/cloth2")->wear();
         carry_object(__DIR__"obj/blade")->wield();   
       
        create_family("姑苏慕容",3,"弟子");
        set("inquiry", ([
            "name" : "我就是姑苏慕容玄霜庄庄庄主风波恶。\n",
            "here" : "这里是大名鼎鼎的燕子坞，难道你没有听说过？\n",
            "rumors" : "慕容公子的以彼之道，还施彼身天下闻名。\n",
            "阿珠" : "阿珠住在听香水榭，是慕容公子的贴身丫鬟，跟阿碧两个人一同侍奉公子。\n",
            "阿碧" : "阿碧姑娘住在琴韵小筑，所有要拜见慕容公子的人都要由她那里经过。\n",
            "王语嫣" : "王姑娘是慕容公子的表妹，不知道什么时候他们成亲。\n",
            "邓百川" : "邓百川是我大哥，是燕子坞青云庄的庄主。\n",
            "公孙乾" : "公孙乾是我二哥，是燕子坞赤霞庄的庄主。\n",
            "包不同" : "包不同是我三哥，是燕子坞金凤庄的庄主，他老是喜欢说“非也，非也”。\n",
            "听香水榭" : "听香水榭是阿珠姑娘住的地方，离这里不远。\n",
            "琴韵小筑" : "琴韵小筑是阿碧姑娘住的地方，坐小舟有三九水路就到了。\n",
            "曼佗罗山庄" : "曼佗罗山庄是公子的姑妈住的地方，平时连我都不敢去。\n",
            "还施水阁" : "这是燕子坞的秘密之所在，我可不便对你说。\n",       
       ]));
         set("chat_chance",15);
         set("chat_msg",({
"风波恶道：“语嫣姑娘真是天下无不知，那天真是让我开了眼界。”\n",
 "风波恶道：“要不是公子的玉露清新散三哥的女儿包不靓的命就没了。”\n",
                              
        }) );
         
}
void attempt_apprentice(object ob)
{
        command("say 嗯，看你还是个学武的料，我就收下你吧！");
	command("recruit " + ob->query("id"));
	ob->set("title","姑苏慕容第四代弟子");
}
