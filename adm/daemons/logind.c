// logind.c

#define VISITORS "/log/mud/MUDVISITOR"
#define GIFTCARD "/log/mud/GIFTCARD"

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_DBASE;
static string loginnip;
static int loginntime;

int check_legal_password(object ob, string arg);

int wiz_lock_level = WIZ_LOCK_LEVEL;
//tentop
int mad_lock = 0;
//10
string Rname;
string *banned_name = ({
    "你", "你", "我", "他", "她", "它", "它", "爸", "　",
            "翔少爷", "方舟子", "草鱼", "时空", "丁",
            "江泽民", "邓小平", "李鹏", "朱榕基",
            "自己", "某人", "尸体", "我们", "你们", "他们", "大家",
            "他妈的", "去你的", "毛泽东", "巫师", "他奶奶的",
            "仙子", "天马行空", "迪阳", "风儿", "星星", "小人物", "曹斌", "胡锦涛", "温家保"
});

string random_name(int gender) //gender ==2 日本人 gender==1 女人 gender==0 男人
{
    string sname, sid;
    int i;
    string *first_name = ({
        "赵", "钱", "孙", "李", "周", "吴", "郑", "王", "冯", "陈", "褚", "卫", "蒋", "沈", "韩", "杨",
                "朱", "秦", "许", "何", "吕", "施", "张", "孔", "曹", "严", "华", "金", "魏", "陶", "姜", "戚",
                "谢", "邹", "水", "章", "苏", "潘", "葛", "范", "彭", "鲁", "韦", "马", "苗", "方", "任", "袁",
                "柳", "邓", "鲍", "史", "唐", "费", "岑", "薛", "雷", "贺", "倪", "汤", "殷", "罗", "郝", "邬",
                "常", "乐", "卞", "齐", "康", "伍", "余", "元", "卜", "顾", "黄", "穆", "肖", "尹", "姚", "邵",
                "汪", "祁", "毛", "狄", "米", "贝", "藏", "成", "戴", "宋", "茅", "庞", "纪", "舒", "项", "董",
                "梁", "樊", "胡", "凌", "霍", "虞", "柯", "管", "卢", "岳",
                "司马", "上官", "欧阳", "夏候", "诸葛", "东方", "赫连", "皇甫", "尉迟", "宗政", "太叔", "公孙",
                "仲孙", "辕轩", "令狐", "钟离", "宇文", "长孙", "慕容", "司徒", "师空", "巫马", "拓趾", "夹谷",
                "楚晋", "呼延", "微生", "梁丘", "左丘", "东门", "西门", "南宫",
    });
    string *second_name1 = ({
        "忠", "孝", "礼", "义", "智", "勇", "仁", "匡", "宪", "令", "福", "禄", "大", "小", "晓",
                "高", "可", "阿", "金", "世", "克", "叔", "之", "公", "夫", "时", "若", "庆", "文", "武",
                "多", "才", "长", "子", "永", "友", "自", "人", "为", "铁", "", "", "", "", "", "", "", "",
                "", "", "", "", "", "", "", "", "", "", "", "", "", "",
    });
    string *second_name2 = ({
        "霸", "白", "班", "斌", "宾", "昌", "超", "诚", "川", "鼎", "定", "斗",
                "法", "飞", "风", "锋", "钢", "罡", "贯", "光", "海", "虎", "华",
                "浩", "宏", "济", "坚", "健", "剑", "江", "进", "杰", "俊", "康",
                "良", "麟", "民", "明", "鸣", "宁", "培", "启", "强", "荣", "山",
                "泰", "涛", "挺", "伟", "熙", "祥", "雄", "旭",
                "毅", "瑜", "羽", "宇", "岳", "舟",
    });
    string *girl_name = ({ //女性专用
        "爱", "春", "丹", "芳", "芬", "凤", "姑", "红", "虹", "娇", "娟",
                "菊", "兰", "岚", "丽", "莉", "莲", "玲", "琳", "娜", "琴", "芹",
                "倩", "萍", "婷", "霞", "香", "艳", "燕", "英", "瑛", "玉", "珍",
                "珠",
    });
    string *japan_name1 = ({
        "山本", "龟田", "姿三", "大岛", "松下", "横田", "东芝", "候本", "川野", "山口",
                "铃木", "岗仓", "小岛", "井上", "安奈", "浅田", "佐藤", "广末", "大竹", "大村",
                "伯佐", "富冈", "东乡", "柴田"
    });
    string *japan_name2 = ({
        "太郎", "次郎", "三郎", "四郎", "五郎", "十一郎", "十四郎", "二十六", "俊树",
                "宁次", "英机", "冶字", "俊雄", "牧夫", "光夫", "敬一", "英世", "漱石", "渝吉",
                "一叶", "子规", "稻造", "伊冲", "松园", "深水", "大观", "丰国", "孝和", "茂",
                "川", "卫", "岛寿", "光云", "安治", "山乐", "梦二", "长秀", "成政"
    });
    gender = random(3);
    switch (gender) {
        case 0:
            i = random(sizeof(first_name));
            sname = first_name[i] + second_name1[random(sizeof(second_name1))] +
                    second_name2[random(sizeof(second_name2))];
            break;
        case 1:
            i = random(sizeof(first_name));
            sname = first_name[i] + second_name1[random(sizeof(second_name1))] + girl_name[random(sizeof(girl_name))];
            break;
        case 2:
            i = random(sizeof(japan_name1));
            sname = japan_name1[i] + japan_name2[random(sizeof(japan_name2))];
            break;
    }
    return sname;
}

void get_id(string arg, object ob);

void confirm_id(string yn, object ob);

object make_body(object ob);

init_new_player(object
user);

varargs void enter_world(object ob, object user, int silent);

varargs void reconnect(object ob, object user, int silent);

object find_body(string name);

int check_legal_id(string arg);

int check_legal_name(string arg);

int howmany_user();

int howmany_visitor();

int howmany_card();

void set_visitor(int num);

void set_card(int num);

// tentop
int howmuch_money(object ob);

void random_gift(mapping my, int select) {
    int i = 10, j;
    int tmpstr, tmpint, tmpcon, tmpdex;

    tmpstr = tmpint = tmpcon = tmpdex = 10;

    switch (select) {
        case 1:
            tmpstr = i = my["str"];
            break;
        case 2:
            tmpint = i = my["int"];
            break;
        case 3:
            tmpcon = i = my["con"];
            break;
        case 4:
            tmpdex = i = my["dex"];
    }
    i = 50 - i;
    while (i--) {
        j = random(4);
        if (j == select - 1) {
            i++;
            continue;
        }
        switch (j) {
            case 0:
                tmpstr++;
                break;
            case 1:
                tmpint++;
                break;
            case 2:
                tmpcon++;
                break;
            case 3:
                tmpdex++;
                break;
        }
    }
    if (tmpstr <= 30) my["str"] = tmpstr; else my["str"] = 30;
    if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
    if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;
    if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;
    // next 3 are randomly selected
    my["kar"] = 10 + random(21);
    my["per"] = 10 + random(31);
}

void create() {
    seteuid(getuid());
    set("channel_id", "连线精灵");
}

void logon(object ob) {
    object * usr;
    int i, login_cnt;
    string welcome_msg;

// 防止有恶意的玩家用 KMUD 等工具捣乱
    usr = filter_array(children(LOGIN_OB),(: interactive :));
    i = sizeof(usr);
    login_cnt = 0;
    while (i--) if (query_ip_number(usr[i]) == query_ip_number(ob)) login_cnt++;
    if (login_cnt > 3) {
        destruct(ob);
        return;
    }
//welcome_msg = "/adm/etc/welcome";
//write(read_file(welcome_msg));

// Add by Yu Jue 1997.8.6
    write("\n我们建议使用 800 * 600 的分辨率进入" + MUD_NAME + "。\n");
    write(HIW
    "Best view with 800 * 600    "
    NOR);
    write("\n可以使用5555,2000,2002,2003,2004多个端口进入" + MUD_NAME + "。");
    write(HIW
    "\nCan use port 5555,2000,2002,2003,2004 telnet this Game      。"
    NOR);
    write("\nPlease select 国标码 〖GB〗 or き絏 〖Big5〗 (GB/Big5):\n");
//    write("\nAre you using BIG5 font [Y|N]?");
    ob->add_temp("input", 1);
    if (ob->query_temp("input") > 120) {
        write("\n你输入的指令过多了!!\n");
        destruct(ob);
        return;
    }

    input_to("gb_big5", ob);
}

void gb_big5(string arg, object ob) {
    int encode;
    object * usr, *usert;
    int i, inv_wiz_cnt, wiz_cnt, ppl_cnt, login_cnt;
    int iplimit, max_online, avg_online, ipl;
    int user_num;
//add by login
    mapping mud_list;
    mapping mud_svc;
    mixed *muds;
    string output, online_num, avg_num;
    int loop, size, total, count = 0, p_count = 0;
//
//	if( arg[0]=='y' || arg[0]=='Y' ) ob->set_temp("big5", 1);
//	if( arg[0]=='n' || arg[0]=='N' ) ob->set_temp("big5", 0);
    if (!arg || arg == "") {
        write("\nPlease select 国标码 〖Gb〗 or き絏 〖Big5〗 (Gb/Big5):");
        input_to("gb_big5", ob);
        return;
    } else if (arg[0..0] == "g" || arg[0..0] == "G")
        encode = 0;
    else if (arg[0..0] == "b" || arg[0..0] == "B")
        encode = 1;
    else {
        write("\nPlease select 国标码 〖Gb〗 or き絏 〖Big5〗 (Gb/Big5):");
        input_to("gb_big5", ob);
        return;
    }

    if (encode == 0)
        write("\n欢迎您进入"
    HIG
    "〖海洋II〗"
    NOR
    "的传奇世界。\n\n");
    else
    write("\n舧眤秈"
    HIG
    "〖MUD〗"
    NOR
    "肚。\n\n");
    ob->set_encoding(encode);
    write(read_file("/adm/etc/welcome"));

    if (BAN_D->is_banned(query_ip_name(ob)) == 1) {
        write("你的地址在本 MUD 不受欢迎。\n");
        destruct(ob);
        return;
    }

//add by login
//      if( !find_object(DNS_MASTER) )
//		write("网路精灵并没有被载入。\n");
    mud_list = (mapping) DNS_MASTER->query_muds();

    mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

    if (!mud_list)
        write(MUD_NAME + "目前并没有跟网路上其他 Mud 取得联系。\n");

    muds = keys(mud_list) - ({ "DEFAULT" });

    muds = sort_array(muds, 1);

    output =
            "Mud                  中文名称                国际网路位址     埠号  人数\n" +
            "────────────────────────────────────\n";

    for (loop = 0, size = sizeof(muds); loop < size; loop++) {
        if (mud_list[muds[loop]]["VERSION"] != MUDLIB_VERSION)
            continue;
        if (mud_list[muds[loop]]["_dns_no_contact"] > 0) {
            continue;
        }
        count = loop;
        if (htonn(upper_case(muds[loop])) == htonn(upper_case(INTERMUD_MUD_NAME)))
            output += BBLU + HIW;
        else
            output += WHT;

        if (undefinedp(mud_list[muds[loop]]["MUDNAME"])) {
            output += sprintf("%-43s  %-15s  %4s",
                              upper_case(muds[loop]),
                              mud_list[muds[loop]]["hy.21sun.net"],
                              mud_list[muds[loop]]["PORT"]);
        } else {
            output += sprintf("%-20s %-23s %-15s  %4s",
                              upper_case(muds[loop]),
                              undefinedp(mud_list[muds[loop]]["MUDNAME"]) ?
                              "" : mud_list[muds[loop]]["MUDNAME"],
                    //mud_list[muds[loop]]["HOSTADDRESS"],
                              mud_list[muds[loop]]["hy.21sun.net"],
                              mud_list[muds[loop]]["PORT"]);
        }
        if (!undefinedp(mud_list[muds[loop]]["USERS"])) {
            output += sprintf("  %-4s", mud_list[muds[loop]]["USERS"]);
            if (sscanf(mud_list[muds[loop]]["USERS"], "%d", count) == 1)
                p_count += count;
        } else
            output += sprintf("  ----", mud_list[muds[loop]]["USERS"]);

        output += NOR
        "\n";
        total++;
    }
    output += "────────────────────────────────────\n";
    output += sprintf("共有 %d 个站点与本站连线中。共有 %d 个玩家在线。\n", total == 0 ? 0 : total - 1, p_count);
//add end

    write("\n");
    write(output);
//write(HIC"任何意见或建议，请到星星的约会论坛发表  \n"NOR);
//write("\n");
//write(output);

    UPTIME_CMD->main();

    usert = filter_array(children(LOGIN_OB),(: interactive :));
//	usr = filter_array(children(LOGIN_OB), (: interactive :));
    usr = users();
    wiz_cnt = 0;
    inv_wiz_cnt = 0;
    ppl_cnt = 0;
    login_cnt = 0;
    ipl = 0;
    iplimit = 0;
    for (i = 0; i < sizeof(usr); i++) {
        if (query_ip_name(usr[i]) == query_ip_name(ob)) iplimit++;
        if (!environment(usr[i])) login_cnt++;
        else if (wizardp(usr[i]) && usr[i]->query("env/invisibility")) inv_wiz_cnt++;
        else if (wizardp(usr[i]) && !usr[i]->query("env/invisibility")) wiz_cnt++;
        else ppl_cnt++;
    }

//目前暂时限制每IP最多连接15 ID
    if (iplimit > 50 && query_ip_name(ob) != "NATSERV") {
        write("对不起，" + MUD_NAME + "你的IP连接超过12用户，谢谢你对海洋的支持，我们会尽快处理。\n");
        destruct(ob);
        return;
    }

//目前暂时限制每IP最多连接15 ID
    if (iplimit > 80 && query_ip_name(ob) == "NATSERV") {
        write("对不起，" + MUD_NAME + "你的IP连接超过80用户，谢谢你对海洋的支持，我们会尽快处理。\n");
        destruct(ob);
        return;
    }

// 计数 Start

/*        user_num=howmany_user();
        if(user_num!=0)
        {
            write(HIG"海洋II总共有："+HIW+chinese_number(user_num)+HIW"个用户。\n"+NOR);
        }

        user_num=howmany_visitor();
*/
    max_online = atoi(read_file(__DIR__
    "maxonline", 1));

    avg_online = atoi(read_file(__DIR__
    "avguser", 1));

    if (ppl_cnt + login_cnt + inv_wiz_cnt + wiz_cnt > max_online) {

        online_num = sprintf("%d", ppl_cnt + login_cnt + inv_wiz_cnt + wiz_cnt);

        write_file(__DIR__
        "maxonline", online_num, 1);

    }

    avg_num = sprintf("%d", max_online - 40);

    write_file(__DIR__
    "avguser", avg_num, 1);


    set_visitor(user_num + 1);
    if (iplimit > 1)
        write(HIG
    "您的地址已有："
    HIW + chinese_number(iplimit - 1) + NOR + HIW
    "个用户。");
// 计数 End
//	write(HIG"总共访问人次：" HIW + chinese_number(user_num));
    write(HIG
    "目前人数限制："
    HIW + chinese_number(MAX_USERS) + HIG + "                        用MUDOS版本： "
    HIW + "MUDOS pre11 \n" + NOR);
    write(HIG
    "游戏主页网址："
    HIW
    "Http://hy.21sun.net         "
    HIG
    "星月传奇主页："
    HIW
    "Http://www.21sun.net  \n"
    NOR);
//	write("\n");
//	UPTIME_CMD->main(1);
    printf(HIG
    "最高在线数目："
    HIW
    "%s"
    HIG
    "人                "
    HIG
    "平均在线数目："
    HIW
    "%s"
    HIG
    "人工\n"
    NOR, chinese_number(max_online), chinese_number(avg_online));
    printf(HIG
    "游戏目前共有："
    HIW
    " %s "
    HIG
    "位世外高人、"
    HIW
    "%s "
    HIG
    "位江湖儿女在线上，以及"
    HIW
    " %s"
    HIG
    " 位使用者尝试连线中。\n"
    NOR,
            chinese_number(wiz_cnt),
            chinese_number(ppl_cnt + login_cnt + inv_wiz_cnt + wiz_cnt),
            chinese_number(login_cnt + inv_wiz_cnt));

    write("您的英文名字(新玩家可以选择一喜欢的名字)：");
    ob->add_temp("input", 1);
    if (ob->query_temp("input") > 120) {
        write("\n你输入的指令过多了!!\n");
        destruct(ob);
        return;
    }
    input_to("get_id", ob);
}

void set_visitor(int num) {
    if (num > 0)
        write_file(VISITORS, sprintf("VISITORS %d", num), 1);
    else
        write("巫师请注意访问者数目不对!\n");
    return;
}

void set_card(int num) {
    if (num > 0)
        write_file(GIFTCARD, sprintf("GIFTCARD %d", num), 1);
    else
        write("巫师请注意访问者数目不对!\n");
    return;
}

int howmany_user() {
    int i, j, ppl_cnt;
    string *dir, *ppls, name;
    mixed info;
    seteuid(getuid());
    ppl_cnt = 0;
    dir = get_dir(DATA_DIR + "login/");
    for (i = 0; i < sizeof(dir); i++) {
        reset_eval_cost();
        ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
        ppl_cnt += sizeof(ppls);
    }
    return ppl_cnt;
}

int howmany_visitor() {
    int num = 0;
    string content, format;
    content = read_file(VISITORS);
    sscanf(content, "%s %d", format, num);
    if (format != "VISITORS")
        write(format + "\n巫师请注意访问者数目不对!\n");
    return num;
}

int howmany_card() {
    int num = 0;
    string content, format;
    content = read_file(GIFTCARD);
    sscanf(content, "%s %d", format, num);
    if (format != "GIFTCARD")
        write(format + "\n巫师请注意访问者数目不对!\n");
    return num;
}

void get_id(string arg, object ob) {
    object * usr;
    int i, login_cnt;
    object ppl;

    arg = lower_case(arg);

    if (!check_legal_id(arg)) {
        write("您的英文名字(新玩家可以选择一喜欢的名字)：");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("get_id", ob);
        return;
    }

#ifdef MAX_USERS
                                                                                                                            if( (string)SECURITY_D->get_status(arg)=="(player)"
//	&& sizeof(users()) >= MAX_USERS ) {
	&& sizeof(users()) > 400 ) {
		ppl = find_body(arg);
		// Only allow reconnect an interactive player when MAX_USERS exceeded.
		if( !ppl || !interactive(ppl) ) {
			write("对不起，" + MUD_NAME + "的使用者已经太多了，请待会再来。\n");
			destruct(ob);
			return;
		}
	}
#endif
    if (wiz_level(arg) < wiz_lock_level) {
        write("对不起，" + MUD_NAME + "目前限制巫师等级 " + WIZ_LOCK_LEVEL
              + " 以上的人才能连线。\n");
        destruct(ob);
        return;
    }
    if ((string) ob->set("id", arg) != arg) {
        write("Failed setting user name.\n");
        destruct(ob);
        return;
    }

/*
if (arg!="hxsd")
{
        write("\n系统维护中，请等二小时再来!!\n");
         destruct(ob);
return;
}*/

    if (arg == "guest") {
        // If guest, let them create the character.
        confirm_id("Yes", ob);
        return;
    } else if (file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0) {
        if (ob->restore()) {
            write("请输入密码：");
            ob->add_temp("input", 1);
            if (ob->query_temp("input") > 120) {
                write("\n你输入的指令过多了!!\n");
                destruct(ob);
                return;
            }
            input_to("get_passwd", 1, ob);
            return;
        }
        write("您的人物储存挡出了一些问题，请利用 guest 人物通知巫师处理。\n");
        destruct(ob);
        return;
    }

// 防止两个以上的玩家用同一 id
    usr = filter_array(children(LOGIN_OB),(: interactive :));
    i = sizeof(usr);
    while (i--) if (usr[i] != ob && usr[i]->query("id") == arg) break;
    if (i >= 0) {
        write("有其他玩家正在使用这个 ID，请重新输入。\n");
        write("您的英文名字：");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("get_id", ob);
        return;
    }
//同一IP login 1人
    usr = filter_array(children(LOGIN_OB),(: interactive :));
    i = sizeof(usr);
    while (i--) if (usr[i] != ob && query_ip_number(usr[i]) == query_ip_number(ob)) break;
    if (i >= 0) {
        write("有同一IP,的其他玩家正在登陆游戏,请等一会再登陆。\n");
        destruct(ob);
        return;
    }

// Add by Yu Jue 1998.8.24

    write("使用 " + (string) ob->query("id") + " 这个名字将会创造一个新的人物，您确定吗(y/n)？");
    ob->add_temp("input", 1);
    if (ob->query_temp("input") > 120) {
        write("\n你输入的指令过多了!!\n");
        destruct(ob);
        return;
    }
    input_to("confirm_id", ob);
}

void get_passwd(string pass, object ob) {
    string my_pass;
    string ip = query_ip_number(ob);
    int time_rl;
    int time_pwd;
    object user;
    string temps;
    write("\n");
    my_pass = ob->query("password");
    time_rl = time() - ob->query("last_on");
    time_pwd = time() - ob->query("lastpwd");
    if (time_rl >= 0 && time_rl <= 60) {
        temps = sprintf("你距上次退出仅 %d 秒?\n", time_rl);
        write(temps);
        write("对不起，为了降低系统负荷，请稍后再login，多谢您的合作。\n");
        destruct(ob);
        return;
    }
    if (ob->query("last_from") == ip) {
        if (time_pwd >= 0 && time_pwd <= 10) {
            temps = sprintf("你距上次打错密码,仅 %d 秒?\n", time_pwd);
            write(temps);
            write("对不起，为了保证系统安全，请一分钟后再login，多谢您的合作。\n");
            destruct(ob);
            return;
        }
    }
    if (crypt(pass, my_pass) != my_pass) {
        write("密码错误！\n");
        ob->set("last_from", ip);
        ob->set("lastpwd", time());
        ob->save();
        destruct(ob);
        return;
    }


    // Check if logout recently

    // Check if we are already playing.
    user = find_body(ob->query("id"));
    if (user) {
        if (user->query_temp("netdead")) {
            reconnect(ob, user);
            return;
        }
        write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("confirm_relogin", ob, user);
        return;
    }

    if (ob->query("wizpwd")) {
        write(HIR
        "№"
        WHT
        "『"
        HIG
        "请输入相应的WIZ密码"
        WHT
        "』"
        NOR
        "");
        input_to("get_wizpwd", 1, ob);
    }

    if (objectp(user = make_body(ob))) {
        if (user->restore()) {
            log_file("USAGE", sprintf("%s loggined from %s (%s)\n", user->query("name"),
                                      query_ip_name(ob), ctime(time())));
            enter_world(ob, user);
            return;
        } else {
            destruct(user);
        }
    }
    write("请您重新创造这个人物。\n");
    confirm_id("y", ob);
}

private void get_wizpwd(string pass, object user, object ob) {
    string old_pass;
    object userp;
    write("\n");
    old_pass = user->query("wizpwd");
    userp = find_body(user->query("id"));

    if (!user->query("wizpwd")) {
        write(HIW
        "你没有设定WIZ密码，请用WIZPWD来设定！\n"
        NOR);
    }

    if (user->query("wizpwd")) {
        if (crypt(pass, old_pass) == old_pass) {
            write(HIG
            "密码正确！\n"
            NOR);
            return;
        } else {
            write(HIR
            "密码错误！\n"
            NOR);
            write(HIY
            "请重新输入你的ID和密码！\n"
            NOR);
            destruct(userp);
            input_to("get_id", user);
            return;
        }
    }
}


void confirm_relogin(string yn, object ob, object user) {
    object old_link;

    if (yn == "") {
        write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("confirm_relogin", ob, user);
        return;
    }

    if (yn[0] != 'y' && yn[0] != 'Y') {
        write("好吧，欢迎下次再来。\n");
        destruct(ob);
        return;
    } else {
        if (user) {
            tell_object(user, BLINK
            HIW
            "有人从别处( " + query_ip_number(ob)
            + " )连线取代你所控制的人物。\n"
            NOR);
            log_file("USAGE", sprintf("%s replaced by %s (%s)\n", user->query("name"),
                                      query_ip_name(ob), ctime(time())));
        }
    }

    // Kick out tho old player.
    old_link = user->query_temp("link_ob");
    if (old_link) {
        exec(old_link, user);
        destruct(old_link);
    }

    reconnect(ob, user);
}

void confirm_id(string yn, object ob) {
    if (query_ip_name(ob) == loginnip
        && (time() - loginntime) <= 60) {
        write("\n本MUD注册同一IP新玩家60秒内只能进行一次!!,请稍后再注册!\n");
        destruct(ob);
        return;
    }
    if (ob) {
        loginnip = query_ip_name(ob);
        loginntime = time();
    }
    if (yn == "") {
        write("使用这个名字将会创造一个新的人物，您确定吗(y/n)？");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }

        input_to("confirm_id", ob);
        return;
    }

    if (yn[0] != 'y' && yn[0] != 'Y') {
        write("好吧，那么请重新输入您的英文名字：");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("get_id", ob);
        return;
    }
    write( @TEXT
    [2J
    [33m────────────────────────────────
    [41;
    33m
    星月传奇新人注册向导——第一步            [2;
    37;
    0m
    [33m────────────────────────────────[2;
    37;
    0m
    [35m
    请输入您的高姓大名，由于这个名字代表你的人物，而且以后不能更改，
    务必慎重择名（不雅观的姓名将被删除）。另：请不要选择金庸小说中
    已有人物姓名。
    [37m
    [31m
    如果你有困难输入中文名字，请直接敲回车键［ＲＥＴＵＲＮ］。
    [37m
    TEXT
    );
    write("您的中文名字(使用Big5的玩家可请求巫师修改)：");
    ob->add_temp("input", 1);
    if (ob->query_temp("input") > 120) {
        write("\n你输入的指令过多了!!\n");
        destruct(ob);
        return;
    }
    input_to("get_name", ob);
}

string display_attr(int gift) {
    if (gift > 24) return HIY + gift + NOR;
    if (gift < 16) return CYN + gift + NOR;
    return "" + gift;
}

private void get_resp(string arg, object ob) {
    if (arg == "") {
        write(WHT
        "您满意(y)不满意(n)这个中文名字？"
        NOR);
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("get_resp", ob);
        return;
    }

    if (arg[0] == 'y' || arg[0] == 'Y') {
        ob->set("name", Rname);
        write( @TEXT
        [2J
        [33m────────────────────────────────
        [44;
        33m
        星月传奇新人注册向导——第二步            [2;
        37;
        0m
        [33m────────────────────────────────[2;
        37;
        0m
        [35m
        新人注册的第二步是设定好你的密码，请不要以为设定一个密码
        是很简单的事，密码关系到你生存的安全，假如密码给人盗用的话，
        这是一件非常危险的事，不要以为这不可能发生。所以你一定要认真
        想一个不容易被猜到的密码才好哦！
        [32m
        为了保护玩家档案的安全，星月传奇的密码监测系统非常严格，
        其中的要求如下：
        [36m
        一、密码至少六个字符以上。
        二、密码中必须包含至少一个大写字母。
        三、密码中必须包含至少一个小写字母。
        四、密码中必须包含至少一个数字。
        五、密码不能与你的英文名字过于相像。
        [33m
        请按照以上要求设定你的密码，如果你在以后的游戏过程中不慎丢失
        了密码，请发送E - mail至hxsd@citiz.net以取回密码。
        [37m
        TEXT
        );
        write(WHT
        "好的，下面请设定您的密码："
        NOR);
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("new_password", 1, ob);
        return;
    } else if (arg[0] == 'n' || arg[0] == 'N') {
        Rname = random_name(random(2));
//	Rname = random_name();
        write(WHT
        "您满意(y)不满意(n)这个中文名字？"
        NOR);
        printf(HIY
        " -- %s ："
        NOR, Rname);
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }

        input_to("get_resp", ob);
        return;
    } else {
        write(WHT
        "对不起，您只能选择满意(y)不满意(n)： "
        NOR);
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("get_resp", ob);
        return;
    }


}

private void get_name(string arg, object ob) {
    string name;
    if (arg == "") {
        Rname = random_name(random(2));
//	Rname = random_name();
        write("看来您要个随机产生的中文名字．．\n");
        write("您满意(y)不满意(n)这个中文名字？");
        printf(HIY
        " -- %s ："
        NOR, Rname);
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("get_resp", ob);
    } else {
        if (!check_legal_name(arg)) {
            write("您的中文名字(使用Big5的玩家可请求巫师修改)：");
            ob->add_temp("input", 1);
            if (ob->query_temp("input") > 120) {
                write("\n你输入的指令过多了!!\n");
                destruct(ob);
                return;
            }
            input_to("get_name", ob);
            return;
        }

//        printf("%O\n", ob);
        ob->set("name", arg);
        write( @TEXT
        [2J
        [33m────────────────────────────────
        [44;
        33m
        星月传奇新人注册向导——第二步            [2;
        37;
        0m
        [33m────────────────────────────────[2;
        37;
        0m
        [35m
        新人注册的第二步是设定好你的密码，请不要以为设定一个密码
        是很简单的事，密码关系到你生存的安全，假如密码给人盗用的话，
        这是一件非常危险的事，不要以为这不可能发生。所以你一定要认真
        想一个不容易被猜到的密码才好哦！
        [32m
        为了保护玩家档案的安全，星月传奇的密码监测系统非常严格，
        其中的要求如下：
        [36m
        一、密码至少六个字符以上。
        二、密码中必须包含至少一个大写字母。
        三、密码中必须包含至少一个小写字母。
        四、密码中必须包含至少一个数字。
        五、密码不能与你的英文名字过于相像。
        [33m
        请按照以上要求设定你的密码，如果你在以后的游戏过程中不慎丢失
        了密码，请发送E - mail至hxsd@citiz.net以取回密码。
        [37m
        TEXT
        );
        write(WHT
        "好的，下面请设定您的密码："
        NOR);
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("new_password", 1, ob);
    }
}

void new_password(string pass, object ob) {
    write("\n");
    if (!check_legal_password(ob, pass)) {
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
    }
    if (strlen(pass) < 5) {
        write("密码的长度至少要五个字元，请重设您的密码：");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("new_password", 1, ob);
        return;
    }
    ob->set("password", crypt(pass, 0));
    write("请再输入一次您的密码，以确认您没记错：");
    ob->add_temp("input", 1);
    if (ob->query_temp("input") > 120) {
        write("\n你输入的指令过多了!!\n");
        destruct(ob);
        return;
    }
    input_to("confirm_password", 1, ob);
}

void confirm_password(string pass, object ob) {
    mapping my;
    string old_pass;
    write("\n");
    old_pass = ob->query("password");
    if (crypt(pass, old_pass) != old_pass) {
        write("您两次输入的密码并不一样，请重新设定一次密码：");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }

        input_to("new_password", 1, ob);
        return;
    }

    write(@TEXT
    [2J
    [33m────────────────────────────────
    [45;
    33m
    星月传奇新人注册向导——第三步            [2;
    37;
    0m
    [33m────────────────────────────────[2;
    37;
    0m
    [35m

    一个人物的天赋对于他或她所修习的武艺息息相关。侠客行中的人物大多具有
    以下四项天赋：

    [36m
    膂力：影响攻击能力及负荷量的大小。
    悟性：影响学习武功秘籍的速度及理解师傅的能力。
    根骨：影响体力恢复的速度及升级后所增加的体力。
    身法：影响防御及躲避的能力。
    [33m
    您可以自己指定其中一项的值，或者输入
    0
    交由系统随机产生。
    请输入您的选择(0 - 4)：
    [37m
    TEXT);

    ob->add_temp("input", 1);
    if (ob->query_temp("input") > 120) {
        write("\n你输入的指令过多了!!\n");
        destruct(ob);
        return;
    }
    input_to("select_gift", ob);
}

void get_gift(string yn, object ob, mapping my, int select) {
    if (yn[0] != 'y' && yn[0] != 'Y') {
        random_gift(my, select);
        printf("\n膂力[%s]，悟性[%s]，根骨[%s]，身法[%s]\n",
               display_attr(my["str"]),
               display_attr(my["int"]),
               display_attr(my["con"]),
               display_attr(my["dex"]));
        write("您同意这一组天赋吗？");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("get_gift", ob, my, select);
        return;
    }
    write("\n您的电子邮件地址：");
    ob->add_temp("input", 1);
    if (ob->query_temp("input") > 120) {
        write("\n你输入的指令过多了!!\n");
        destruct(ob);
        return;
    }
    input_to("get_email", ob, my);
}

void select_gift(string yn, object ob) {
    int i;
    mapping
    my = ([]);

    if (!sscanf(yn, "%d", i) || i < 0 || i > 4) {
        write("\n输入错误，请重新选择：");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("select_gift", ob);
        return;
    }
    if (i) {
        write("\n请输入您想要的数值(10-30)：");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("set_gift", ob, my, i);
    } else get_gift(" ", ob, my, i);
}

void set_gift(string yn, object ob, mapping my, int select) {
    int i;

    if (!sscanf(yn, "%d", i) || i < 10 || i > 30) {
        write("\n数值错误，请重新输入：");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("set_gift", ob, my, select);
        return;
    }
    switch (select) {
        case 1:
            my["str"] = i;
            break;
        case 2:
            my["int"] = i;
            break;
        case 3:
            my["con"] = i;
            break;
        case 4:
            my["dex"] = i;
    }
    get_gift(" ", ob, my, select);
}

/*	my = ([]);
	random_gift(my);
	printf("\n膂力[%d]， 悟性[%d]， 根骨[%d]， 身法[%d]\n",
                my["str"], my["int"], my["con"], my["dex"]);
        write("您接受这一组天赋吗？");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n你输入的指令过多了!!\n");
         destruct(ob);
return;
}
        input_to("get_gift", ob, my);
}
void get_gift(string yn, object ob, mapping my)
{
	if (yn[0] != 'y' && yn[0] != 'Y') {
		random_gift(my);
		printf("\n膂力[%d]， 悟性[%d]， 根骨[%d]， 身法[%d]\n",
                      my["str"], my["int"], my["con"], my["dex"]);
                write("您同意这一组天赋吗？");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n你输入的指令过多了!!\n");
         destruct(ob);
return;
}
		input_to("get_gift", ob, my);
	}
	if (yn[0] == 'y' || yn[0] == 'Y') {
          	write("\n您的电子邮件地址：");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n你输入的指令过多了!!\n");
         destruct(ob);
return;
}
        	input_to("get_email", ob, my);
	}
}
*/
void get_email(string email, object ob, mapping my) {
    object user;
    string id, address;

    write("\n");
    if (email == "" || strsrch(email, "@") == -1 ||
        sscanf(email, "%s@%s", id, address) != 2 || strsrch(address, ".") == -1) {
        write("电子邮件地址需要是 id@address 的格式。\n");
        write("您的电子邮件地址：");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
        }

        input_to("get_email", ob, my);
        return;
    }
    ob->set("email", email);
    ob->set("registered", 1);

    // If you want do race stuff, ask player to choose one here, then you can
    // set the user's body after the question is answered. The following are
    // options for player's body, so we clone a body here.
    ob->set("body", USER_OB);
    if (!objectp(user = make_body(ob)))
        return;
    user->set("str", my["str"]);
    user->set("dex", my["dex"]);
    user->set("con", my["con"]);
    user->set("int", my["int"]);
    ob->set("registered", 1);
    user->set("registered", 1);

    write("您要扮演男性(m)的角色或女性(f)的角色？");
    ob->add_temp("input", 1);
    if (ob->query_temp("input") > 120) {
        write("\n你输入的指令过多了!!\n");
        destruct(ob);
        return;
    }
    input_to("get_gender", ob, user);
}

void get_gender(string gender, object ob, object user) {
    write("\n");
    if (gender == "") {
        write("您要扮演男性(m)的角色或女性(f)的角色？");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("get_gender", ob, user);
        return;
    }

    if (gender[0] == 'm' || gender[0] == 'M')
        user->set("gender", "男性");
    else if (gender[0] == 'f' || gender[0] == 'F')
        user->set("gender", "女性");
    else {
        write("对不起，您只能选择男性(m)或女性(f)的角色：");
        ob->add_temp("input", 1);
        if (ob->query_temp("input") > 120) {
            write("\n你输入的指令过多了!!\n");
            destruct(ob);
            return;
        }
        input_to("get_gender", ob, user);
        return;
    }

    log_file("USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
                              query_ip_name(ob), ctime(time())));
    init_new_player(user);
    enter_world(ob, user);
    write("\n");
}

object make_body(object ob) {
    string err;
    object user;
    int n;

    if (!ob) return 0;
    if (!ob->query("body")) return 0;
    user = new(ob->query("body"));
    if (!user) {
        write("现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
        write(err + "\n");
        return 0;
    }
    seteuid(ob->query("id"));
    export_uid(user);
    export_uid(ob);
    seteuid(getuid());
    user->set("id", ob->query("id"));
    user->set_name(ob->query("name"), ({ ob->query("id") }));
    return user;
}

init_new_player(object
user)
{
user->set("title", "普通百姓");
user->set("birthday",

time()

);
user->set("potential", 99);
user->set("food", (user->query("str")+10)*10);
user->set("water", (user->query("str")+10)*10);

user->set("channels", ({
"chat", "rumor", "party", "es" }));
//	user->set("balance", 1000);
}


varargs void enter_world(object ob, object user, int silent) {
    object cloth, shoe, room, mailbox, gift, fly, login_ob, weapon;
    string startroom;
    object link_ob;
    int card_num;
    int i, temp, maxexp;
    object obj;
    mapping hp_status, skill_status, map_status, prepare_status;
    mapping my;
    string *sname, *mname, *pname;
    string wiz_status;
    user->set_temp("link_ob", ob);
    ob->set_temp("body_ob", user);
    user->set("registered", ob->query("registered"));
    user->set_encoding(ob->query_encoding());
//	user->set_temp("big5", ob->query_temp("big5"));
    exec(user, ob);

    write("\n目前权限：" + wizhood(user) + "\n");
    user->setup();
    if (!user->query("food") && !user->query("water") && ob->query("age") == 14) {
        user->set("food", user->max_food_capacity());
        user->set("water", user->max_water_capacity());
    }

    // In case of new player, we save them here right aftre setup
    // compeleted.
    user->save();
    ob->save();
    // Use condition to auto save user file
    user->apply_condition("autosave", 1);

    mailbox = new("/clone/misc/mailbox");
    mailbox->move(user);
    gift = new("/clone/book/rules");
    gift->move(user);
    if (!user->query("flybag") && (user->query("age") < 19)) {
        fly = new("/clone/misc/fly");
        fly->move(user);
    }
//	if (user->query("weapon/type")) {
//		switch((string)user->query("weapon/type"))
//		{
//			case "剑":
//			weapon = new("/d/npc/m_weapon/weapon/m_sword");
//			weapon->move(user);
//			break;
//			case "刀":
//			weapon = new("/d/npc/m_weapon/weapon/m_blade");
//			weapon->move(user);
//			break;
//			case "鞭":
//			weapon = new("/d/npc/m_weapon/weapon/m_whip");
//			weapon->move(user);
//			break;
//			case "杖":
//			weapon = new("/d/npc/m_weapon/weapon/m_staff");
//			weapon->move(user);
//			break;
//			case "棍":
//			weapon = new("/d/npc/m_weapon/weapon/m_club");
//			weapon->move(user);
//			break;
//			default:
//		}
//	}
    //    if(this_player()->quary(age)>==15)
    //    {
    //  if (!user->query("giftcard"))
    //   if(!user->query("giftcard") && (user->query("age") >= 15) )
    //  {
    //          card_num=howmany_card();
    //          set_card(card_num+1);
    //        gift = new("/clone/misc/card");
    //	gift->move(user);
    //        user->set("giftcard", card_num);
    // }
    //      }
//	if (wizhood(user) == "(player)")
    {
        if (user->query("class") == "bonze") {
            if (user->query("gender") == "女性") {
                cloth = new("/clone/cloth/ni-cloth.c");
                shoe = new("/clone/cloth/ni-xie.c");
            } else {
                cloth = new("/clone/cloth/seng-cloth.c");
                shoe = new("/clone/cloth/seng-xie.c");
            }
        } else {
            if (user->query("class") == "taoist") {
                if (user->query("gender") == "女性") {
                    cloth = new("/clone/cloth/daogu-cloth.c");
                    shoe = new("/clone/cloth/dao-xie.c");
                } else {
                    cloth = new("/clone/cloth/dao-cloth.c");
                    shoe = new("/clone/cloth/dao-xie.c");
                }
            } else {
                if (user->query("gender") == "女性") {
                    shoe = new("/clone/cloth/female-shoe.c");
                    switch (random(8)) {
                        case 1:
                            cloth = new("/clone/cloth/female1-cloth.c");
                            break;
                        case 2:
                            cloth = new("/clone/cloth/female2-cloth.c");
                            break;
                        case 3:
                            cloth = new("/clone/cloth/female3-cloth.c");
                            break;
                        case 4:
                            cloth = new("/clone/cloth/female4-cloth.c");
                            break;
                        case 5:
                            cloth = new("/clone/cloth/female5-cloth.c");
                            break;
                        case 6:
                            cloth = new("/clone/cloth/female6-cloth.c");
                            break;
                        case 7:
                            cloth = new("/clone/cloth/female7-cloth.c");
                            break;
                        default:
                            cloth = new("/clone/cloth/female8-cloth.c");
                    }
                } else {
                    shoe = new("/clone/cloth/male-shoe.c");
                    switch (random(8)) {
                        case 1:
                            cloth = new("/clone/cloth/male1-cloth.c");
                            break;
                        case 2:
                            cloth = new("/clone/cloth/male2-cloth.c");
                            break;
                        case 3:
                            cloth = new("/clone/cloth/male3-cloth.c");
                            break;
                        case 4:
                            cloth = new("/clone/cloth/male4-cloth.c");
                            break;
                        case 5:
                            cloth = new("/clone/cloth/male5-cloth.c");
                            break;
                        case 6:
                            cloth = new("/clone/cloth/male6-cloth.c");
                            break;
                        case 7:
                            cloth = new("/clone/cloth/male7-cloth.c");
                            break;
                        default:
                            cloth = new("/clone/cloth/male8-cloth.c");
                    }
                }
            }
        }
        cloth->move(user);
        cloth->wear();
        shoe->move(user);
        shoe->wear();
    }

    if (!silent) {
        if (ob->query("registered") == 0)
            write(read_file(UNREG_MOTD));
        else
            write(read_file(MOTD));
        if (ob->query("new_mail")) {
            write(GRN + "\n绿林邮差跑来对你说：这是人家留给您的信！\n\n" + NOR);
            user->set("new_mail", 0);
        }
        if (user->is_ghost())
            startroom = DEATH_ROOM;
        else if (!stringp(startroom = user->query("startroom")))
            startroom = START_ROOM;

        if (!catch(load_object(startroom)))
            user->move(startroom);
        else {
            user->move(START_ROOM);
            startroom = START_ROOM;
            user->set("startroom", START_ROOM);
        }
        tell_room(startroom, user->query("name") + "连线进入这个世界。\n",
                  ({ user }));
    }
    login_ob = new(LOGIN_OB);
    login_ob->set("id", user->query("id"));
    login_ob->restore();
//	login_ob->set("last_on", time());
//	login_ob->set("last_from", query_ip_name(user));
    login_ob->save();

    write(HIW
    "\n你上次光临海洋II是 " + HIG + ctime(login_ob->query("last_on")) + NOR + " 从 " + HIR + login_ob->query("last_from") + NOR +
    " 连接的。\n\n"
    NOR);
    if (login_ob->query("new_mail")) {
        write(HIY + "\n有您的信！快看您的信箱吧！\n\n" + NOR);
        login_ob->set("new_mail", 0);
    }
    destruct(login_ob);

    wiz_status = SECURITY_D->get_status(user);
    if (wiz_status != "(admin)" && wiz_status != "(arch)") {
        CHANNEL_D->do_channel(this_object(), "sys",
                              sprintf("%s(%s)由%s连线进入。共清除 " + reclaim_objects() + " 个变数。\n", user->name(),
                                      user->query("id"), query_ip_name(user)));
    }
    UPDATE_D->check_user(user);
    user->set_temp("temp_exp", user->query("combat_exp"));
    user->set_temp("temp_time", time());
    user->set_temp("mud_age", user->query("mud_age"));
    if (user->query("lastChangeSize") != file_size("/doc/help/whatsnew")) {
        user->set("lastChangeSize", file_size("/doc/help/whatsnew"));
        write(BLINK
        HIW
        "\n 海洋II 有最新变动！请用 help whatsnew 来查看。\n\n"
        NOR);
    }
//if(wizardp(user)) {

    if (user->query("str") > 60 && !user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("str", 60);
    }
    if (user->query("dex") > 60 && !user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("dex", 60);
    }
    if (user->query("int") > 60 && !user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("int", 60);
    }
    if (user->query("con") > 60 && !user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("con", 60);
    }
    if (user->query("per") > 60 && !user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("per", 60);
    }
    if (user->query("kar") > 60 && !user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("kar", 60);
    }
//4转
    if (user->query("str") > 70 && user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("str", 70);
    }
    if (user->query("dex") > 70 && user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("dex", 70);
    }
    if (user->query("int") > 70 && user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("int", 70);
    }
    if (user->query("con") > 70 && user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("con", 70);
    }
    if (user->query("per") > 70 && user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("per", 70);
    }
    if (user->query("kar") > 70 && user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("kar", 70);
    }

    if (user->query("str") > 60 && !user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("str", 60);
    }
    if (user->query("dex") > 60 && !user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("dex", 60);
    }
    if (user->query("int") > 60 && !user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("int", 60);
    }
    if (user->query("con") > 60 && !user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("con", 60);
    }
    if (user->query("per") > 60 && !user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("per", 60);
    }
    if (user->query("kar") > 60 && !user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("kar", 60);
    }
//4转
    if (user->query("str") > 70 && user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("str", 70);
    }
    if (user->query("dex") > 70 && user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("dex", 70);
    }
    if (user->query("int") > 70 && user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("int", 70);
    }
    if (user->query("con") > 70 && user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("con", 70);
    }
    if (user->query("per") > 70 && user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("per", 70);
    }
    if (user->query("kar") > 70 && user->query("4zhuan") && !user->query("5zhuan")) {
        user->set("kar", 70);
    }
//4转 ,5转 EXP限制

    if (user->query("4zhuan") || user->query("5zhuan")) {
        maxexp = 6000000 + (user->query("expmax", 1) * 500000);
        if (user->query("combat_exp", 1) > maxexp) {
            user->set("combat_exp", maxexp);
        }
        write(HIR
        "目前经验长限:" + maxexp + "!\n"
        NOR);
    }
//自动二转
    if ((user->query("combat_exp", 1) >= 50000000 && !user->query("zhuanbest") && !user->query("4zhuan") &&
         !user->query("5zhuan"))) {
        obj->set("guard/flag", 1);
        obj->set("tforceok", 2);
        obj->set("zhuanshen", 1);
        user->clear_condition();
        user->set("betrayer", 0);
        user->set("title", "普通百姓");
        user->set("class", "0");
        user->set("score", 0);
        user->set("shen", 0);
        user->set("max_neili", 0);
        user->set("max_qi", 100);
        user->set("max_jing", 100);
        user->delete("family");
        user->delete("party");
        user->delete("work/wakuang");
        user->delete("work/wunon");
        user->delete("work/penlen");
        user->delete("work/zhujian");
        user->delete("work/zhudao");
        user->delete("work/zhubanzi");
        user->delete("work/buyu");
        user->delete("work/dalie");
        user->delete("work/zhaojiu");
        user->delete("work/zhujia");
        user->delete("work");
        user->delete("breakup");
        user->delete("last_getzhen");
        user->delete("blade_get");
        user->delete("szj/failed");
        user->delete("jiuyin/shang-failed");
        user->delete("jiuyin/xia-failed");
        user->delete("zhou/fail");
        user->delete("zhou/jieyi");
        user->delete("jiuyin/gumu-failed");
        user->delete("zhou/failed");
        user->set("killbyname", 0);
        user->set("MKS", 0);
        user->set("PKS", 0);
        user->set("zhuanshen", 1);
        user->set("meili", 0);
        user->set("dietimes", 0);
        user->set("normal_die", 0);
        user->set("weiwang", 0);
        user->set("mud_age", 400000);
        user->set("combat_exp", 0);
        user->set("eff_qi", user->query("max_qi"));
        user->set("qi", user->query("max_qi"));
        user->set("eff_jing", user->query("max_jing"));
        user->set("jing", user->query("max_jing"));
        user->set("jingli", user->query("max_jingli"));
        user->set("neili", user->query("max_neili"));
        user->set("food", user->max_food_capacity());
        user->set("water", user->max_water_capacity());
        if (mapp(skill_status = user->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
        {
            skill_status = user->query_skills();
            sname = keys(skill_status);//传回所有自己的功夫阵列

            temp = sizeof(skill_status);
            for (i = 0; i < temp; i++)
                user->delete_skill(sname[i]);//删除自己所有功夫
        }


        user->map_skill("unarmed");
        user->map_skill("hammer");
        user->map_skill("blade");
        user->map_skill("stick");
        user->map_skill("staff");
        user->map_skill("club");
        user->map_skill("throwing");
        user->map_skill("parry");
        user->map_skill("dodge");
        user->map_skill("magic");
        user->map_skill("spells");
        user->map_skill("leg");
        user->map_skill("axe");
        user->map_skill("array");
        user->map_skill("whip");
        user->map_skill("finger");
        user->map_skill("hand");
        user->map_skill("cuff");
        user->map_skill("claw");
        user->map_skill("strike");

        user->prepare_skill("unarmed");
        user->prepare_skill("hammer");
        user->prepare_skill("blade");
        user->prepare_skill("stick");
        user->prepare_skill("staff");
        user->prepare_skill("club");
        user->prepare_skill("throwing");
        user->prepare_skill("parry");
        user->prepare_skill("dodge");
        user->prepare_skill("magic");
        user->prepare_skill("spells");
        user->prepare_skill("leg");
        user->prepare_skill("axe");
        user->prepare_skill("array");
        user->prepare_skill("whip");
        user->prepare_skill("finger");
        user->prepare_skill("hand");
        user->prepare_skill("cuff");
        user->prepare_skill("claw");
        user->prepare_skill("strike");
        user->reset_action();
        if (user->query("per") < 60) {
            user->set("per", user->query("per") + 10);
        }
        if (user->query("str") < 60) {
            user->set("str", user->query("str") + 10);
        }
        if (user->query("dex") < 60) {
            user->set("dex", user->query("dex") + 10);
        }
        if (user->query("int") < 60) {
            user->set("int", user->query("int") + 10);
        }
        if (user->query("con") < 60) {
            user->set("con", user->query("con") + 10);
        }
        if (user->query("kar") < 60) {
            user->set("kar", user->query("kar") + 10);
        }
    }


//自动三转
    if ((user->query("combat_exp", 1) >= 60000000 && user->query("guard/flag") && !user->query("4zhuan") &&
         !user->query("5zhuan"))) {
        obj->set("guard/flag", 1);
        obj->set("tforceok", 2);
        user->clear_condition();
        user->set("betrayer", 0);
        user->set("title", "普通百姓");
        user->set("class", "0");
        user->set("score", 0);
        user->set("shen", 0);
        user->set("max_neili", 0);
        user->set("max_qi", 100);
        user->set("max_jing", 100);
        user->delete("family");
        user->delete("party");
        user->delete("work/wakuang");
        user->delete("work/wunon");
        user->delete("work/penlen");
        user->delete("work/zhujian");
        user->delete("work/zhudao");
        user->delete("work/zhubanzi");
        user->delete("work/buyu");
        user->delete("work/dalie");
        user->delete("work/zhaojiu");
        user->delete("work/zhujia");
        user->delete("work");
        user->delete("breakup");
        user->delete("last_getzhen");
        user->delete("blade_get");
        user->delete("szj/failed");
        user->delete("jiuyin/shang-failed");
        user->delete("jiuyin/xia-failed");
        user->delete("zhou/fail");
        user->delete("zhou/jieyi");
        user->delete("jiuyin/gumu-failed");
        user->delete("zhou/failed");
        user->set("killbyname", 0);
        user->set("MKS", 0);
        user->set("PKS", 0);
        user->set("zhuanshen", 1);
        user->set("meili", 0);
        user->set("dietimes", 0);
        user->set("normal_die", 0);
        user->set("weiwang", 0);
        user->set("mud_age", 400000);
        user->set("combat_exp", 0);
        user->set("eff_qi", user->query("max_qi"));
        user->set("qi", user->query("max_qi"));
        user->set("eff_jing", user->query("max_jing"));
        user->set("jing", user->query("max_jing"));
        user->set("jingli", user->query("max_jingli"));
        user->set("neili", user->query("max_neili"));
        user->set("food", user->max_food_capacity());
        user->set("water", user->max_water_capacity());
        if (mapp(skill_status = user->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
        {
            skill_status = user->query_skills();
            sname = keys(skill_status);//传回所有自己的功夫阵列

            temp = sizeof(skill_status);
            for (i = 0; i < temp; i++)
                user->delete_skill(sname[i]);//删除自己所有功夫
        }

        user->set("jiuyin/full", 1);
        user->set("szj/passed", 1);
        user->set("zhuanbest", 1);
        user->delete("last_alert");

        user->map_skill("unarmed");
        user->map_skill("hammer");
        user->map_skill("blade");
        user->map_skill("stick");
        user->map_skill("staff");
        user->map_skill("club");
        user->map_skill("throwing");
        user->map_skill("parry");
        user->map_skill("dodge");
        user->map_skill("magic");
        user->map_skill("spells");
        user->map_skill("leg");
        user->map_skill("axe");
        user->map_skill("array");
        user->map_skill("whip");
        user->map_skill("finger");
        user->map_skill("hand");
        user->map_skill("cuff");
        user->map_skill("claw");
        user->map_skill("strike");

        user->prepare_skill("unarmed");
        user->prepare_skill("hammer");
        user->prepare_skill("blade");
        user->prepare_skill("stick");
        user->prepare_skill("staff");
        user->prepare_skill("club");
        user->prepare_skill("throwing");
        user->prepare_skill("parry");
        user->prepare_skill("dodge");
        user->prepare_skill("magic");
        user->prepare_skill("spells");
        user->prepare_skill("leg");
        user->prepare_skill("axe");
        user->prepare_skill("array");
        user->prepare_skill("whip");
        user->prepare_skill("finger");
        user->prepare_skill("hand");
        user->prepare_skill("cuff");
        user->prepare_skill("claw");
        user->prepare_skill("strike");
        user->reset_action();
        if (user->query("per") < 60) {
            user->set("per", user->query("per") + 10);
        }
        if (user->query("str") < 60) {
            user->set("str", user->query("str") + 10);
        }
        if (user->query("dex") < 60) {
            user->set("dex", user->query("dex") + 10);
        }
        if (user->query("int") < 60) {
            user->set("int", user->query("int") + 10);
        }
        if (user->query("con") < 60) {
            user->set("con", user->query("con") + 10);
        }
        if (user->query("kar") < 60) {
            user->set("kar", user->query("kar") + 10);
        }
    }

//自动四转
    if ((user->query("combat_exp", 1) >= 100000000 && user->query("zhuanbest") == 1 && !user->query("4zhuan"))) {
        user->set("tforceok", 2);
        user->set("double_attack", 1);
        user->clear_condition();
        user->set("betrayer", 0);
        user->set("title", "普通百姓");
        user->set("class", "0");
        user->set("score", 0);
        user->set("shen", 0);
        user->set("max_neili", 0);
        user->set("max_qi", 100);
        user->set("max_jing", 100);
        user->delete("family");
        user->delete("party");
        user->delete("work/wakuang");
        user->delete("work/wunon");
        user->delete("work/penlen");
        user->delete("work/zhujian");
        user->delete("work/zhudao");
        user->delete("work/zhubanzi");
        user->delete("work/buyu");
        user->delete("work/dalie");
        user->delete("work/zhaojiu");
        user->delete("work/zhujia");
        user->delete("work");
        user->delete("breakup");
        user->delete("last_getzhen");
        user->set("killbyname", 0);
        user->set("MKS", 0);
        user->set("PKS", 0);
        user->set("zhuanshen", 1);
        user->set("meili", 0);
        user->set("dietimes", 0);
        user->set("normal_die", 0);
        user->set("weiwang", 0);
        user->set("mud_age", 400000);
        user->set("combat_exp", 0);
        user->set("eff_qi", user->query("max_qi"));
        user->set("qi", user->query("max_qi"));
        user->set("eff_jing", user->query("max_jing"));
        user->set("jing", user->query("max_jing"));
        user->set("jingli", user->query("max_jingli"));
        user->set("neili", user->query("max_neili"));
        user->set("food", user->max_food_capacity());
        user->set("water", user->max_water_capacity());
        if (mapp(skill_status = user->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
        {
            skill_status = user->query_skills();
            sname = keys(skill_status);//传回所有自己的功夫阵列

            temp = sizeof(skill_status);
            for (i = 0; i < temp; i++)
                user->delete_skill(sname[i]);//删除自己所有功夫
        }
        user->map_skill("unarmed");
        user->map_skill("hammer");
        user->map_skill("blade");
        user->map_skill("stick");
        user->map_skill("staff");
        user->map_skill("club");
        user->map_skill("throwing");
        user->map_skill("parry");
        user->map_skill("dodge");
        user->map_skill("magic");
        user->map_skill("spells");
        user->map_skill("leg");
        user->map_skill("axe");
        user->map_skill("array");
        user->map_skill("whip");
        user->map_skill("finger");
        user->map_skill("hand");
        user->map_skill("cuff");
        user->map_skill("claw");
        user->map_skill("strike");

        user->prepare_skill("unarmed");
        user->prepare_skill("hammer");
        user->prepare_skill("blade");
        user->prepare_skill("stick");
        user->prepare_skill("staff");
        user->prepare_skill("club");
        user->prepare_skill("throwing");
        user->prepare_skill("parry");
        user->prepare_skill("dodge");
        user->prepare_skill("magic");
        user->prepare_skill("spells");
        user->prepare_skill("leg");
        user->prepare_skill("axe");
        user->prepare_skill("array");
        user->prepare_skill("whip");
        user->prepare_skill("finger");
        user->prepare_skill("hand");
        user->prepare_skill("cuff");
        user->prepare_skill("claw");
        user->prepare_skill("strike");
        user->reset_action();

        if (!user->query("4zhuan")) {
            if (user->query("per") < 70) {
                user->set("per", user->query("per") + 10);
            }
            if (user->query("str") < 70) {
                user->set("str", user->query("str") + 10);
            }
            if (user->query("dex") < 70) {
                user->set("dex", user->query("dex") + 10);
            }
            if (user->query("int") < 70) {
                user->set("int", user->query("int") + 10);
            }
            if (user->query("con") < 70) {
                user->set("con", user->query("con") + 10);
            }
            if (user->query("kar") < 70) {
                user->set("kar", user->query("kar") + 10);
            }
            if (random(6) == 0) {
                user->set("zhuanfinal/6", 1);
                write(HIY
                "获得能力【国士无双】【银仙决】!\n"
                NOR);
            } else if (random(6) == 1) {
                user->set("zhuanfinal/2", 1);
                write(HIY
                "获得能力【遁影擒踪】【破仙决】!\n"
                NOR);
            } else if (random(6) == 2) {
                user->set("zhuanfinal/3", 1);
                write(HIY
                "获得能力【神魔金身】【乱仙决】!\n"
                NOR);
            } else if (random(6) == 3) {
                user->set("zhuanfinal/4", 1);
                write(HIY
                "获得能力【缚骨缠身】【妙仙决】!\n"
                NOR);
            } else if (random(6) == 4) {
                user->set("zhuanfinal/5", 1);
                write(HIY
                "获得能力【破元大法】【动仙决】!\n"
                NOR);
            } else {
                user->set("zhuanfinal/1", 1);
                write(HIY
                "获得能力【元气无穷】【斩仙决】!\n"
                NOR);
            }
            if (random(2) == 0) {
                user->set("zhuanfinal/7", 1);
                write(HIY
                "获得武功【阴阳十二重天】!\n"
                NOR);
            } else {
                user->set("zhuanfinal/8", 1);
                write(HIY
                "获得武功【不败神功】!\n"
                NOR);
            }
            message("channel:chat", HIW
            "【江湖传言】："
            HIW
            "听说  "
            + user->query("name") + "(" + user->query("id") + ")完成了四转！\n"
            NOR, users());

        }

        user->set("4zhuan", 1);
        user->save();
        write(HIR
        "自动转生成功,请重新登陆!\n"
        NOR);
        write(HIR
        "转生成功,请找无名居士获取转身特殊能力!\n"
        NOR);

    }
//自动五转
    if (user->query("4zhuan") && user->query("combat_exp", 1) >= 200000000 && !user->query("5zhuan")) {
        user->set("tforceok", 2);
        user->clear_condition();
        user->set("betrayer", 0);
        user->set("title", "普通百姓");
        user->set("class", "0");
        user->set("score", 0);
        user->set("shen", 0);
        user->set("max_neili", 0);
        user->set("max_qi", 100);
        user->set("max_jing", 100);
        user->delete("family");
        user->delete("party");
        user->delete("work/wakuang");
        user->delete("work/wunon");
        user->delete("work/penlen");
        user->delete("work/zhujian");
        user->delete("work/zhudao");
        user->delete("work/zhubanzi");
        user->delete("work/buyu");
        user->delete("work/dalie");
        user->delete("work/zhaojiu");
        user->delete("work/zhujia");
        user->delete("work");
        user->delete("breakup");
        user->delete("last_getzhen");
        user->set("killbyname", 0);
        user->set("MKS", 0);
        user->set("PKS", 0);
        user->set("zhuanshen", 1);
        user->set("meili", 0);
        user->set("dietimes", 0);
        user->set("normal_die", 0);
        user->set("weiwang", 0);
        user->set("mud_age", 400000);
        user->set("combat_exp", 0);
        user->set("eff_qi", user->query("max_qi"));
        user->set("qi", user->query("max_qi"));
        user->set("eff_jing", user->query("max_jing"));
        user->set("jing", user->query("max_jing"));
        user->set("jingli", user->query("max_jingli"));
        user->set("neili", user->query("max_neili"));
        user->set("food", user->max_food_capacity());
        user->set("water", user->max_water_capacity());
        if (mapp(skill_status = user->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
        {
            skill_status = user->query_skills();
            sname = keys(skill_status);//传回所有自己的功夫阵列

            temp = sizeof(skill_status);
            for (i = 0; i < temp; i++)
                user->delete_skill(sname[i]);//删除自己所有功夫
        }
        user->map_skill("unarmed");
        user->map_skill("hammer");
        user->map_skill("blade");
        user->map_skill("stick");
        user->map_skill("staff");
        user->map_skill("club");
        user->map_skill("throwing");
        user->map_skill("parry");
        user->map_skill("dodge");
        user->map_skill("magic");
        user->map_skill("spells");
        user->map_skill("leg");
        user->map_skill("axe");
        user->map_skill("array");
        user->map_skill("whip");
        user->map_skill("finger");
        user->map_skill("hand");
        user->map_skill("cuff");
        user->map_skill("claw");
        user->map_skill("strike");

        user->prepare_skill("unarmed");
        user->prepare_skill("hammer");
        user->prepare_skill("blade");
        user->prepare_skill("stick");
        user->prepare_skill("staff");
        user->prepare_skill("club");
        user->prepare_skill("throwing");
        user->prepare_skill("parry");
        user->prepare_skill("dodge");
        user->prepare_skill("magic");
        user->prepare_skill("spells");
        user->prepare_skill("leg");
        user->prepare_skill("axe");
        user->prepare_skill("array");
        user->prepare_skill("whip");
        user->prepare_skill("finger");
        user->prepare_skill("hand");
        user->prepare_skill("cuff");
        user->prepare_skill("claw");
        user->prepare_skill("strike");
        user->reset_action();


        user->set("5zhuan", 1);
        if (user->query("per") < 80) {
            user->set("per", user->query("per") + 10);
        }
        if (user->query("str") < 80) {
            user->set("str", user->query("str") + 10);
        }
        if (user->query("dex") < 80) {
            user->set("dex", user->query("dex") + 10);
        }
        if (user->query("int") < 80) {
            user->set("int", user->query("int") + 10);
        }
        if (user->query("con") < 80) {
            user->set("con", user->query("con") + 10);
        }
        if (user->query("kar") < 80) {
            user->set("kar", user->query("kar") + 10);
        }
        user->delete("zhuanfinal");
        if (random(4) == 0) {
            user->set("zhuanfinal/6", 1);
            write(HIY
            "获得能力【国士无双】【银仙决】!\n"
            NOR);
            user->set("zhuanfinal/5", 1);
            write(HIY
            "获得能力【破元大法】【动仙决】!\n"
            NOR);
            user->set("zhuanfinal/1", 1);
            write(HIY
            "获得能力【元气无穷】【斩仙决】!\n"
            NOR);
        } else if (random(4) == 1) {
            user->set("zhuanfinal/2", 1);
            write(HIY
            "获得能力【遁影擒踪】【破仙决】!\n"
            NOR);
            user->set("zhuanfinal/6", 1);
            write(HIY
            "获得能力【国士无双】【银仙决】!\n"
            NOR);
            user->set("zhuanfinal/3", 1);
            write(HIY
            "获得能力【神魔金身】【乱仙决】!\n"
            NOR);
        } else if (random(4) == 2) {
            user->set("zhuanfinal/3", 1);
            write(HIY
            "获得能力【神魔金身】【乱仙决】!\n"
            NOR);
            user->set("zhuanfinal/4", 1);
            write(HIY
            "获得能力【缚骨缠身】【妙仙决】!\n"
            NOR);
            user->set("zhuanfinal/5", 1);
            write(HIY
            "获得能力【破元大法】【动仙决】!\n"
            NOR);

        } else {
            user->set("zhuanfinal/4", 1);
            write(HIY
            "获得能力【缚骨缠身】【妙仙决】!\n"
            NOR);
            user->set("zhuanfinal/1", 1);
            write(HIY
            "获得能力【元气无穷】【斩仙决】!\n"
            NOR);
            user->set("zhuanfinal/2", 1);
            write(HIY
            "获得能力【遁影擒踪】【破仙决】!\n"
            NOR);
        }


        user->set("zhuanfinal/7", 1);
        write(HIY
        "获得武功【阴阳十二重天】!\n"
        NOR);
        user->set("expmax", 1);
        user->set("zhuanfinal/8", 1);
        write(HIY
        "获得武功【不败神功】!\n"
        NOR);

        message("channel:chat", HIW
        "【江湖传言】："
        HIW
        "听说  "
        + user->query("name") + "(" + user->query("id") + ")完成了五转！\n"
        NOR, users());
        user->save();
        write(HIR
        "自动转生成功,请重新登陆!\n"
        NOR);
        write(HIR
        "转生成功,请找无名居士获取转身特殊能力!\n"
        NOR);
    }

//}
    if (wizardp(user)) {
        if (!ob->query("wizpwd")) {
            write(HIR
            "№"
            WHT
            "『"
            HIG
            "请用WIZPWD设定相应的WIZ密码"
            WHT
            "』"
            NOR
            "");
        }

        if (wiz_status != "(admin)" && wiz_status != "(arch)") {
            CHANNEL_D->do_channel(this_object(), "wiz",
                                  sprintf(NOR
            "%s"
            HIY
            " 从 "
            HIG
            "%s"
            HIY
            " 进入连线。", user->
            short(
            1), query_ip_name(user)));
        }
        tell_object(user, BLINK
        HIG
        "上次连入时间( " + ctime(ob->query("last_on"))
        + " )请校对。\n"
        NOR);
        tell_object(user, BLINK
        HIG
        "上次连入IP地址( " + ob->query("last_from")
        + " )请校对。\n"
        NOR);

        if (wizhood(user) == "(admin)") {
            if (user->query("wiz_check/FILES") != file_size("/log/FILES")) {
                user->set("wiz_check/FILES", file_size("/log/FILES"));
                write(HIW
                "有巫师有非法写操作，立即查看 /log/FILES 。\n"
                NOR);
            }
            if (user->query("wiz_check/CALL_PLAYER") != file_size("/log/static/CALL_PLAYER")) {
                user->set("wiz_check/CALL_PLAYER", file_size("/log/static/CALL_PLAYER"));
                write(HIW
                "有巫师修使用过call，立即查看 /log/static/CALL_PLAYER 。\n"
                NOR);
            }
            if (user->query("wiz_check/log") != file_size("/log/log")) {
                user->set("wiz_check/log", file_size("/log/log"));
                write(HIW
                "有新文件update错误，立即查看 /log/log 。\n"
                NOR);
            }
            if (user->query("wiz_check/PURGE_PLAYER") != file_size("/log/static/PURGE")) {
                user->set("wiz_check/PURGE_PLAYER", file_size("/log/static/PURGE"));
                write(HIW
                "有人使用过PURGE错误，立即查看 /log/static/PURGE 。\n"
                NOR);
            }
            if (user->query("wiz_check/promotion_PLAYER") != file_size("/log/static/PURGE")) {
                user->set("wiz_check/promotion_PLAYER", file_size("/log/static/promotion"));
                write(HIW
                "有人使用过权限命令，立即查看 /log/static/promotion 。\n"
                NOR);
            }
        }
        return;
    } else {
        if (user->query("mud_age") <= 0) {
            user->set("last_on", time());
            user->set("last_from", query_ip_name(user));
            user->save();
            message("channel:chat", HIW
            "【江湖通告】："
            HIW
            "热烈欢迎新玩家  "
            + user->query("name") + "(" + user->query("id") + ")来到" + MUD_NAME + "！请各位多多关照！\n"
            NOR, users());
        } else {
            message("channel:chat", HIW
            "【江湖通告】："
            + user->query("name") + "(" + user->query("id") + ")再次来到了海洋II，欢迎你回来！\n"
            NOR, users());
            tell_object(user, BLINK
            HIG
            "上次连入时间( " + ctime(ob->query("last_on"))
            + " )请校对。\n"
            NOR);
            tell_object(user, BLINK
            HIG
            "上次连入IP地址( " + ob->query("last_from")
            + " )请校对。\n"
            NOR);

            user->delete("vendetta/authority");
//           user->set("food",ob->max_food_capacity());
//           user->set("water",ob->max_water_capacity());
            if (user->query("food") < 100) {
                user->add("food", 50);
            }
            if (user->query("water") < 100) {
                user->add("water", 50);
            }
//             message("channel:chat",HIW"【江湖通告】："
//             +user->query("name")+"("+user->query("id")+")由于save的损坏,现在用10.24的save恢复,玩家到gc,用yaoshu可得一定的补偿！\n"NOR,users());
        }

    }
    return;
}

varargs void reconnect(object ob, object user, int silent) {
    string temps;
    object userp;
    int time_rl;
    string wiz_status;

    userp = find_body(user->query("id"));
    user->set_temp("link_ob", ob);
    ob->set_temp("body_ob", user);
    ob->set_encoding(ob->query_encoding());
    ob->set("last_on", time());
    ob->save();
    exec(user, ob);
//        time_rl = time() - user->query("last_on");
//	if (time_rl >= 0 && time_rl <= 10)
//	{
//		temps = sprintf("你距上次退出仅 %d 秒?\n", time_rl);
//		write(temps);
//			write("对不起，为了降低系统负荷，请稍后再login，多谢您的合作。\n");
//	                destruct(userp);
//	                return 0;
//	}
    user->set("last_on", time());
    user->reconnect();
    if (!silent) {
        tell_room(environment(user), user->query("name") + "重新连线回到这个世界。\n",
                  ({ user }));
    }
    wiz_status = SECURITY_D->get_status(user);
    if (wiz_status != "(admin)" && wiz_status != "(arch)") {
        CHANNEL_D->do_channel(this_object(), "sys",
                              sprintf("%s由%s重新连线进入。", user->query("name"), query_ip_name(user)));
    }
    UPDATE_D->check_user(user);

}

int check_legal_id(string id) {
    int i;

    i = strlen(id);


    if (id == "all") {
        write("对不起，不能使用all作为id。\n");
        return 0;
    }
    if (id == "corpse") {
        write("对不起，不能使用corpse作为id。\n");
        return 0;
    }
    if (id == "admin") {
        write("对不起，不能使用admin作为id。\n");
        return 0;
    }
    if (id == "guest") {
        write("对不起，不能使用guest作为id。\n");
        return 0;
    }
    if (id == "root") {
        write("对不起，不能使用root作为id。\n");
        return 0;
    }
    if (id == "gold") {
        write("对不起，不能使用gold作为id。\n");
        return 0;
    }
    if (id == "bing") {
        write("对不起，不能使用bing作为id。\n");
        return 0;
    }
    if (id == "none") {
        write("对不起，不能使用none作为id。\n");
        return 0;
    }
    if (id == "silver") {
        write("对不起，不能使用silver作为id。\n");
        return 0;
    }
    if (strsrch(id, "none") >= 0) {
        write("对不起，不能使用none作为id。\n");
        return 0;
    }
    if (strsrch(id, "robber") >= 0) {
        write("对不起，不能使用robber作为id。\n");
        return 0;
    }

    if ((strlen(id) < 3) || (strlen(id) > 12)) {
        write("对不起，你的英文名字必须是 3 到 12 个英文字母。\n");
        return 0;
    }
    while (i--)
        if (id[i] < 'a' || id[i] > 'z') {
            write("对不起，你的英文名字只能用英文字母。\n");
            return 0;
        }

    return 1;
}

int check_legal_name(string name) {
    int i;

    i = strlen(name);


    if ((strlen(name) < 4) || (strlen(name) > 10)) {
        write("对不起，你的中文名字必须是 2 到 5 个中文字。\n");
        return 0;
    }

    while (i--) {
        if (i % 2 == 0 && !is_chinese(name[i..< 0])) {
//		if( name[i]<=' ' ) {
            write("对不起，你的中文名字不能用控制字元。\n");
            return 0;
        }
//		if( i%2==0 && !is_chinese(name[i..<0]) ) {
//			write("对不起，请您用「中文」取名字。\n");
//			return 0;

        if ((strsrch(name, "　") >= 0) ||
            (strsrch(name, "爸") >= 0)) {
            write("对不起，你的中文名字不能用引起误会的单字。\n");
            return 0;
        }
        if (i % 2 == 0 && !is_chinese(name[i..< 0])) {
            write("对不起，请您用「中文」取名字。\n");
            return 0;
        }
    }
    if (member_array(name, banned_name) != -1) {
        write("对不起，这种名字会造成其他人的困扰。\n");
        return 0;
    }

    return 1;
}

object find_body(string name) {
    object ob, *body;

    if (objectp(ob = find_player(name)))
        return ob;
    body = children(USER_OB);
    for (int i = 0; i < sizeof(body); i++)
        if (clonep(body[i])
            && getuid(body[i]) == name)
            return body[i];

    return 0;
}

int set_wizlock(int level) {
    if (wiz_level(this_player(1)) <= level)
        return 0;
    if (geteuid(previous_object()) != ROOT_UID)
        return 0;
    wiz_lock_level = level;
    return 1;
}

// add for ten top.
int set_madlock(int setmark) {
    if (wiz_level(this_player(1)) < wiz_level("(arch)"))
        return 0;
    if (setmark == 1) mad_lock = 1;
    else mad_lock = 0;
    return 1;
}

int get_madlock() {
    return mad_lock;
}

int howmuch_money(object ob) {
    int total;
    int total2;
    object gold, silver, coin;

    total = 0;
    total2 = 0;

    gold = present("gold_money", ob);
    silver = present("silver_money", ob);
    coin = present("coin_money", ob);

    if (gold) total += gold->value();
    if (silver) total += silver->value();
    if (coin) total += coin->value();

    total2 = (int) ob->query("balance");
    if (!total2 || total2 < 0) {
        ob->set("balance", 0);
    }
    total = total + total2;
    return total;
}

// 10
int check_legal_password(object ob, string pass) {
    int i;
    int bigletter = 0;
    int smlletter = 0;
    int number = 0;
    string id;
    i = strlen(pass);
    if (strlen(pass) <= 5) {
        write(WHT
        "对不起，你的密码必须最少六个字符。\n\n");
        return 0;
    }
    id = ob->query("id");
    if (strsrch(id, pass) != -1 || strsrch(pass, id) != -1) {
        write(WHT
        "对不起，你的密码和你的英文名字太象了。\n"
        NOR);
        return 0;
    }

    while (i--) {
        if (pass[i] <= 'Z' && pass[i] >= 'A') bigletter++;
        if (pass[i] <= 'z' && pass[i] >= 'a') smlletter++;

    }
    if (bigletter == 0 || smlletter == 0 ||
        bigletter + smlletter == strlen(pass)) {
        write(WHT
        "您的密码必需包含大写" + RED
        "和" + WHT
        "小写英文字母"
        + RED
        "和" + WHT
        "其它特殊符号（数字，标点）。\n"
        NOR);
        return 0;
    }
    return 1;
}
