#include <ansi.h>
inherit NPC;

int do_copy(object me,int maxpot,int type);
// zhang.c 张三丰
string* names = ({
"赵","钱","孙","李","周","吴","郑","王","冯","陈","褚","卫",
"蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","张",
"孔","曹","严","华","金","魏","陶","姜","戚","谢","邹","喻",
"柏","水","窦","章","云","苏","潘","葛","奚","范","彭","郎",
"鲁","韦","昌","马","苗","凤","花","方","傻","任","袁","柳",
"邓","鲍","史","唐","费","廉","岑","薛","雷","贺","倪","汤",
"藤","殷","罗","华","郝","邬","安","常","乐","呆","时","付",
"皮","卞","齐","康","伍","余","元","卜","顾","盈","平","黄",
"和","穆","肖","尹","姚","邵","湛","汪","祁","毛","禹","狄",
"米","贝","明","藏","计","伏","成","戴","谈","宋","茅","庞",
"熊","纪","舒","屈","项","祝","董","梁","樊","胡","凌","霍",
"虞","万","支","柯","昝","管","卢","英","仇","候","岳","帅",
"司马","上官","欧阳","夏候","诸葛","闻人","东方","赫连","皇甫",
"尉迟","公羊","澹台","公治","宗政","濮阳","淳于","单于","太叔",
"申屠","公孙","仲孙","辕轩","令狐","钟离","宇文","长孙","幕容",
"司徒","师空","颛孔","端木","巫马","公西","漆雕","乐正","壤驷",
"公良","拓趾","夹谷","宰父","谷梁","楚晋","阎法","汝鄢","涂钦",
"段千","百里","东郭","南郭","呼延","归海","羊舌","微生","梁丘",
"左丘","东门","西门","佰赏","南官",
"缑","亢","况","后","有","琴","商","牟","佘","耳","墨","哈",
"谯","年","爱","阳","佟","第","五","言","福","蒯","钟","宗",
"林","石",
});

string* ids = ({
"zhao","qian","sun","li","zhou","wu","zhen","wang","feng","chen","zhu","wei",
"jiang","shen","han","yang","zhu","qing","you","xu","he","lu","shi","zhang",
"kong","cao","yan","hua","jin","wei","tao","jiang","qie","xie","zhou","yu",
"bo","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang",
"lu","wei","chang","ma","miao","feng","hua","fang","sha","ren","yuan","liu",
"deng","bao","shi","tang","fei","lian","chen","xue","lei","he","ni","tang",
"teng","yin","luo","hua","hao","wu","an","chang","le","dai","shi","fu",
"pi","bian","qi","kang","wu","yu","yuan","po","gu","ying","ping","huang",
"he","mu","xiao","yin","yao","shao","zhan","wang","qi","mao","yu","di",
"mi","bei","ming","zang","ji","fu","cheng","dai","tan","song","mao","pang",
"xiong","ji","su","qu","xiang","zhu","dong","liang","fan","hu","ling","ho",
"yu","wan","zhi","ke","jiu","guan","lu","ying","qiu","hou","yue","suai",
"sima","shangguan","ouyang","xiahou","zhuge","wenren","dongfang","helian","huangpu",
"weichi","gongyang","zhantai","gongye","zongzheng","puyang","chunyu","shanyu","taishu",
"shentu","gongshun","zhongshun","xuanyuan","linghu","zhongli","yuwen","changshun","murong",
"situ","shikong","zhuankong","duanmu","wuma","gongxi","qidiao","lezheng","xiangsi",
"gongliang","tuozhi","jiagu","zaifu","guliang","chujing","yanfa","ruye","tuqin",
"duanqian","baili","dongguo","nanguo","huyan","guihai","yangshe","weisheng","liangqiu",
"zuoqiu","dongmen","ximen","baishang","nangong",
"gou","kang","kuang","hou","you","qing","shang","mo","she","er","mo","ha",
"qiao","nian","ai","yang","dong","di","wu","yan","fu","kai","zong","zong",
"lin","shi",
});
//----以下欢迎添加，nm2需要一定的空字，以便产生出单名--------------
string* nm2 = ({
"忠","孝","礼","义","智","勇","仁","匡","宪","令","福","禄","大","小","晓",
"高","可","阿","金","世","克","叔","之","公","夫","时","若","庆","文","武",
"多","才","长","子","永","友","自","人","为","铁","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"霸","白","班","斌","宾","昌","超","诚","川","鼎","定","斗",
"法","飞","风","锋","钢","罡","贯","光","海","虎","华",
"浩","宏","济","坚","健","剑","江","进","杰","俊","康",
"良","麟","民","明","鸣","宁","培","启","强","荣","山",
"泰","涛","挺","伟","熙","祥","雄","旭",
"毅","瑜","羽","宇","岳","舟",
});

void create()
{
      string weapon;
   int i = random(sizeof(names));
  set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({ids[i]}));
	set("per", 35);
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
	set_skill("taiji-shengong", 300);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 300);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 300);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 300);
	set_skill("array",100);
	set_skill("taoism", 250);
	set_skill("literate", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 100);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
        }) );
        set("eff_qi", 4500); 
        set("qi", 4500); 
        set("max_qi", 4500); 
        set("eff_jing", 4500); 
        set("jing", 4500); 
        set("max_jing", 4500); 
        set("eff_jingli", 4000); 
        set("neili", 5000); 
        set("max_neili", 5000);

        set("jiali", 30);
        weapon = random(2)?"/clone/weapon/gangjian":"/clone/weapon/gangjian";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int do_copy(object me,int maxpot,int type)
{
        int i,j;
        object ob;
        ob = this_object();
if (!me->query_skill("force",1))
i=10;
else      i=me->query_skill("force",1);
//        if(type==1)
//		i = i - random(20);
//		else  
//	    i = i +10+ random(10);
//        if( i < 100) i = 100;
        
        ob->set("combat_exp", (me->query("combat_exp")*3/4));
        
        ob->set_skill("force", i*1/2);
        ob->set_skill("sword", i*1/2);
        ob->set_skill("unarmed", i*1/2);
        ob->set_skill("cuff",  i*1/2);
	ob->set_skill("blade", i*1/2);
        ob->set_skill("dodge", i*1/2);
        ob->set_skill("parry", i*1/2);
        ob->set_skill("taiji-shengong", i*1/2);       
        ob->set_skill("tiyunzong", i*1/2); 
        ob->set_skill("taiji-quan", i*1/2); 
        ob->set_skill("taiji-jian", i*1/2);         
        set_skill("taiji-shengong",i*1/2);
ob->set("jing",me->query("max_jing"));
ob->set("eff_jing",me->query("max_jing"));
ob->set("max_jing",me->query("max_jing"));
ob->set("qi",me->query("max_qi"));
ob->set("eff_qi",me->query("max_qi"));
ob->set("max_qi",me->query("max_qi"));

if (random(10)>8)
{
        ob->set_skill("force", i*3/4);
        ob->set_skill("sword", i*3/4);
        ob->set_skill("unarmed", i*3/4);
        ob->set_skill("cuff",  i*3/4);
	ob->set_skill("blade", i*3/4);
        ob->set_skill("dodge", i*3/4);
        ob->set_skill("parry", i*3/4);
        ob->set_skill("taiji-shengong", i*3/4);       
        ob->set_skill("tiyunzong", i*3/4); 
        ob->set_skill("taiji-quan", i*3/4); 
        ob->set_skill("taiji-jian", i*3/4);         
        set_skill("taiji-shengong",i*3/4);
}
        ob->set("eff_jingli", me->query("eff_jingli")*1/2); 
        ob->set("jiali", i/6);
	ob->set("max_qi",  me->query("qi")*2/3); 
        ob->set("eff_jingli", me->query("eff_jingli")*2/3); 
        ob->set("max_neili", me->query("max_neili")*2/3); 
        ob->set("jiali", i/10);
        if(type==3)
		{ob->set("max_qi",     me->query("qi")*2/3);
		 ob->set("max_neili",  me->query("max_neili")*2/3); 
		}
		if(type==2)
        ob->set("max_qi",     me->query("qi")*2/3); 
		ob->reincarnate(); 
        ob->set("qi",ob->query("max_qi")*2/3);
        ob->set("neili",ob->query("max_neili")*2/3);
        ob->set("qi",me->query("max_qi"));
        ob->set("eff_qi",me->query("max_qi"));
        ob->set("max_qi",me->query("max_qi"));        
        ob->set("neili",me->query("max_neili"));
        ob->set("max_neili",me->query("max_neili"));
        ob->set("jing",me->query("max_jing"));
        ob->set("eff_jing",me->query("max_jing"));
        ob->set("max_jing",me->query("max_jing"));

}
void die()
{
int i,pot,exp;
	object killer;
	exp= random(120)+80;
	pot= exp*2/3;
	if(!objectp(killer = query_temp("last_damage_from")))
	return;

	if(objectp(killer = query_temp("last_damage_from"))
	&& killer->query_temp("tmhwjob")
	&& this_object()->query("usename")==killer->query("name"))
        	tell_object(killer,"你被奖励了\n"+chinese_number(exp)+"点实战经验\n"
		+chinese_number(pot)+"点潜能\n");
if (killer && killer->query_temp("tmhwjob")
&& this_object()->query("usename")==killer->query("name"))
{
	killer->add("combat_exp",exp);
	killer->add("potential",pot);
}
	::die();

return ;
}
void init()
{
        remove_call_out("leave");
        call_out("leave",120);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "钻进路边的杂草，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}