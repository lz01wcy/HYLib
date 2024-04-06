// sample master.c code
// xiake island master.c
#include <ansi.h>
inherit NPC;
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

#include <ansi.h>
void away();

void create()
{
   int i = random(sizeof(names));
  set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({ids[i]}));
        set("nickname", HIG"少年侠士"NOR);
//        set_name("少年侠士", ({ "xia shi","xia","shi" }));
        set("gender", "男性");
        set("age", 22);
        set("long", 
                "他是一个英俊的少年人，背负长剑，剑鞘上似乎有一个小小的字。\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 15);
        set("con", 20);
        set("dex", 25);
        set("bac", 15);

        set("qi", 300);
        set("max_qi", 300);
        set("jingli", 200);
        set("max_jingli", 200);
        set("neili", 100);
        set("max_neili", 100);
        
        set("combat_exp", 1000);
        
         set_skill("force", 100);
         set_skill("xuantian-wuji", 140);
         set_skill("dodge", 380 + random(30));
  
        set_skill("jinding-zhang", 340);
        set_skill("huifeng-jian", 280);
        set_skill("kunlun-shenfa", 240);
        set_skill("strike", 220 + random(30));
        set_skill("kunlun-zhang", 320 + random(30));
        set_skill("parry", 340);
        set_skill("sword", 340);
        set_skill("linji-zhuang", 280);
        set_skill("literate", 280);

        set_temp("apply/armor", 250);
        set_temp("apply/damage", 60);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.jue" :),
                (: perform_action, "sword.liaoyuan" :),
                 (: perform_action, "strike.bashi" :),
                (: perform_action, "strike.puzhao" :),                            
        }) );
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "kunlun-zhang");
  	prepare_skill("strike", "kunlun-zhang");
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        map_skill("dodge", "kunlun-shnfa");
   
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("sword","huifeng-jian");
        map_skill("parry","jinding-zhang");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 150);
 
        setup(); 
        carry_object("/clone/weapon/gangjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}

void away()
{
        if( living(this_object()) )
        {
                message_vision(this_object()->query("name") + "一纵身，已经从你的视线里消失了。\n", this_object());
                destruct(this_object());
        }
        return;
}

void die()
{
        object ob, me, corpse;
int exp,pot;        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;        
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
if (me && me->query("tzjob"))
{
        message_vision(WHT"$N惨叫一声,你这武林败类...倒地而亡。\n"NOR,ob,me);
        me->set("tzjob",0);
        me->add("score",50);
exp= random(280) + 180;
pot= random(280) + 150;
               me->add("combat_exp",exp);
               me->add("potential",pot);
   tell_object(me, "你被奖励了"+chinese_number(exp)+"点经验值！\n"+chinese_number(pot)+"点潜能\n");

        me->add("shen",-100);
}
        destruct(this_object());
        destruct(ob);
        return;
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
