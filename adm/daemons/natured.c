//侠客行100海洋II
//星星(lywin)由前人的natured.c为基础！加入夜间出现的飞贼和通告。2000/5/30

// natured.c
#include <ansi.h>

#define TIME_TICK (time()*60)
#define TIME_TICK1 (time()*60)
//#define TIME_TICK (time()*60-890000000)
//#define TIME_TICK1 (time()*60-900000000)
//#define TIME_TICK ((time()-900000000)*24)
//#define TIME_TICK1 ((time()-900000000)*24)
static int current_day_phase, current_month;
static string ppl;
mapping *day_phase;

string *month_desc = ({
    "「隆冬」:",
            "「寒冬」:",
            "「初春」:",
            "「早春」:",
            "「阳春」:",
            "「初夏」:",
            "「盛夏」:",
            "「仲夏」:",
            "「初秋」:",
            "「高秋」:",
            "「深秋」:",
            "「初冬」:",
});

string *weather_msg = ({
    "天空中万里无云",
            "几朵淡淡的云彩妆点著清朗的天空",
            "白云在天空中飘来飘去",
            "厚厚的云层堆积在天边",
            "天空中乌云密布",
});

mapping *read_table(string file);

void init_day_phase();

void create() {
//        day_phase = read_table("/adm/etc/nature/day_phase");
//        init_day_phase();
    string get_month, get_day;
    mixed *local;
    local = localtime(TIME_TICK1);
    get_day = CHINESE_D->chinese_number(local[3]);
    get_month = CHINESE_D->chinese_number(local[4]);
    switch (get_month) {
        //spring weather
        case "三":
        case "四":
        case "五":
            switch (random(3)) {
                case 0:
                    day_phase = read_table("/adm/etc/nature/spring_rain");
                    break;
                case 1:
                    day_phase = read_table("/adm/etc/nature/spring_sun");
                    break;
                case 2:
                    day_phase = read_table("/adm/etc/nature/spring_wind");
                    break;
            }
            break;
            //summer weather
        case "六":
        case "七":
        case "八":
            switch (random(3)) {
                case 0:
                    day_phase = read_table("/adm/etc/nature/summer_rain");
                    break;
                case 1:
                    day_phase = read_table("/adm/etc/nature/summer_sun");
                    break;
                case 2:
                    day_phase = read_table("/adm/etc/nature/summer_wind");
                    break;
            }
            break;
            //autumn weather
        case "九":
        case "十":
        case "十一":
            switch (random(3)) {
                case 0:
                    day_phase = read_table("/adm/etc/nature/autumn_rain");
                    break;
                case 1:
                    day_phase = read_table("/adm/etc/nature/autumn_sun");
                    break;
                case 2:
                    day_phase = read_table("/adm/etc/nature/autumn_wind");
                    break;
            }
            break;
            //winter weather
        case "零":
        case "二":
            switch (random(3)) {
                case 0:
                    day_phase = read_table("/adm/etc/nature/winter_rain");
                    break;
                case 1:
                    day_phase = read_table("/adm/etc/nature/winter_sun");
                    break;
                case 2:
                    day_phase = read_table("/adm/etc/nature/winter_wind");
                    break;
            }
        case "一":
            if (get_day == "一") {
                day_phase = read_table("/adm/etc/nature/spring");
                break;
            }
            else
                switch (random(3)) {
                    case 0:
                        day_phase = read_table("/adm/etc/nature/winter_rain");
                        break;
                    case 1:
                        day_phase = read_table("/adm/etc/nature/winter_sun");
                        break;
                    case 2:
                        day_phase = read_table("/adm/etc/nature/winter_wind");
                        break;
                }

            break;
        default:
            day_phase = read_table("/adm/etc/nature/day_phase");
    }


    init_day_phase();
}

/*
void init_day_phase()
{
        mixed *local;
        int i, t;

        // Get minutes of today.
        local = localtime(TIME_TICK1);
        t = local[2] * 60 + local[1];           // hour * 60 + minutes

        // Find the day phase for now.
        for( i=0; i < sizeof(day_phase); i++)
                if( t >= day_phase[i]["length"] )
                        t -= (int)day_phase[i]["length"];
                else
                        break;

        current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);

        // Since in our time scale, 1 minute == 1 second in RL, so we don't need
        // any conversion before using this number as call_out dalay, if you
        // changed the time scale, be sure to convert it.

        call_out("update_day_phase",
      (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}*/
void init_day_phase() {
    mixed *local;
    int i, t;


    local = localtime(TIME_TICK1);
    t = local[2] * 60 + local[1];


    for (i = 0; i < sizeof(day_phase); i++)
        if (t >= day_phase[i]["length"])
            t -= (int) day_phase[i]["length"];
        else
            break;

    current_day_phase = (i == 0 ? sizeof(day_phase) - 1 : i - 1);
    current_month = local[4];


    remove_call_out("init_day_phase");
    call_out("init_day_phase", 180);


    remove_call_out("update_day_phase");


    call_out("update_day_phase",
             (int) day_phase[(current_day_phase + 1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase() {
    remove_call_out("update_day_phase");

    current_day_phase = (++current_day_phase) % sizeof(day_phase);
    switch (day_phase[current_day_phase]["outcolor"]) {
        case "BLK":
            message("channel:chat", HIG
            "【窗外】"
            BLK + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        case "RED":
            message("channel:chat", HIG
            "【窗外】"
            RED + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        case "HIR":
            message("channel:chat", HIG
            "【窗外】"
            HIR + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        case "GRN":
            message("channel:chat", HIG
            "【窗外】"
            GRN + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        case "HIG":
            message("channel:chat", HIG
            "【窗外】"
            HIG + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        case "YEL":
            message("channel:chat", HIG
            "【窗外】"
            YEL + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        case "HIY":
            message("channel:chat", HIG
            "【窗外】"
            HIY + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        case "BLU":
            message("channel:chat", HIG
            "【窗外】"
            BLU + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        case "HIB":
            message("channel:chat", HIG
            "【窗外】"
            HIB + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        case "MAG":
            message("channel:chat", HIG
            "【窗外】"
            MAG + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        case "HIM":
            message("channel:chat", HIG
            "【窗外】"
            HIM + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        case "CYN":
            message("channel:chat", HIG
            "【窗外】"
            CYN + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        case "HIC":
            message("channel:chat", HIG
            "【窗外】"
            HIC + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        case "WHT":
            message("channel:chat", HIG
            "【窗外】"
            WHT + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        case "HIW":
            message("channel:chat", HIG
            "【窗外】"
            HIW + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
        default:
            message("channel:chat", HIG
            "【窗外】"
            HIG + day_phase[current_day_phase]["time_msg"] + "\n"
            NOR, users());
            break;
    }
//        message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
    if (!undefinedp(day_phase[current_day_phase]["event_fun"]))
        call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

    call_out("update_day_phase", day_phase[current_day_phase]["length"]);
//	call_out("test_robot", 5+random(20));
}

void test_robot() {
    object *obs = users(), ob, robot;
    int i = sizeof(obs), j = 10;

    if (i < 1) return;
    while (j--) {
        ob = obs[random(i)];
        if (wiz_level(ob)) continue;
        if (!living(ob)) continue;
        if (!interactive(ob)) continue;
        if (query_idle(ob) > 30) continue;
        if (!environment(ob)) continue;
        break;
    }
    if (j < 0) return;
    ppl = ob->query("id");
    if (!ob->is_fighting()
        && interactive(ob) && living(ob)
        || ob->query("combat_exp") > 1000000)
        ob->set_temp("testrobot", 1);
    call_out("ok_robot", 1, ob);
}

void ok_robot(object ob) {
    if (ob) {
        ob->set_temp("testrobot", 0);
        ob->delete_temp("testrobot");
    }
}

void event_morning() {
    object badguy;
    object room;
    if (random(12) == 1) {
        if (objectp(room = load_object("/d/city/guangchang")) &&
            objectp(badguy = new("/quest/weiguo/japan/japan4")))
            badguy->move(room);
        badguy = new("/quest/weiguo/japan/japan2");
        badguy->move(room);
        badguy = new("/quest/weiguo/japan/japan2");
        badguy->move(room);
        message("channel:chat", HIY
        "【朝廷急报】"
        HIR + "在扬州城中发现日本奸细！\n"
        NOR, users());
    }
    if (random(12) == 2) {
        if (objectp(room = load_object("/d/city2/di_anmen")) &&
            objectp(badguy = new("/quest/weiguo/japan/japan4")))
            badguy->move(room);
        badguy = new("/quest/weiguo/japan/japan2");
        badguy->move(room);
        badguy = new("/quest/weiguo/japan/japan2");
        badguy->move(room);
        message("channel:chat", HIY
        "【朝廷急报】"
        HIM + "在北京城中发现日本奸细！\n"
        NOR, users());
    }
    if (random(12) == 3) {
        if (objectp(room = load_object("/d/city3/guangchang")) &&
            objectp(badguy = new("/quest/weiguo/japan/japan4")))
            badguy->move(room);
        badguy = new("/quest/weiguo/japan/japan2");
        badguy->move(room);
        badguy = new("/quest/weiguo/japan/japan2");
        badguy->move(room);
        message("channel:chat", HIY
        "【朝廷急报】"
        HIM + "在成都城中发现日本奸细！\n"
        NOR, users());
    }
    if (random(12) == 4) {
        if (objectp(room = load_object("/d/quanzhen/zhongxin")) &&
            objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
            badguy->move(room);
        badguy = new("/quest/weiguo/jinbing/jin2");
        badguy->move(room);
        badguy = new("/quest/weiguo/jinbing/jin2");
        badguy->move(room);
        message("channel:chat", HIB
        "【朝廷急报】"
        GRN + "在武功镇中发现金国奸细！\n"
        NOR, users());
    }
    if (random(12) == 5) {
        if (objectp(room = load_object("/d/dali/taihejiekou")) &&
            objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
            badguy->move(room);
        badguy = new("/quest/weiguo/jinbing/jin2");
        badguy->move(room);
        badguy = new("/quest/weiguo/jinbing/jin2");
        badguy->move(room);
        message("channel:chat", HIB
        "【朝廷急报】"
        GRN + "在大理城中发现金国奸细！\n"
        NOR, users());
    }
    if (random(12) == 6) {
        if (objectp(room = load_object("/d/foshan/street3")) &&
            objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
            badguy->move(room);
        badguy = new("/quest/weiguo/jinbing/jin2");
        badguy->move(room);
        badguy = new("/quest/weiguo/jinbing/jin2");
        badguy->move(room);
        message("channel:chat", HIB
        "【朝廷急报】"
        GRN + "在佛山镇中发现金国奸细！\n"
        NOR, users());
    }
    if (random(12) == 7) {
        if (objectp(room = load_object("/d/fuzhou/dongjiekou")) &&
            objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
            badguy->move(room);
        badguy = new("/quest/weiguo/menggu/mengu2");
        badguy->move(room);
        badguy = new("/quest/weiguo/menggu/mengu2");
        badguy->move(room);
        message("channel:chat", HIG
        "【朝廷急报】"
        CYN + "在福州城中发现蒙古奸细！\n"
        NOR, users());
    }
    if (random(12) == 8) {
        if (objectp(room = load_object("/d/hangzhou/road13")) &&
            objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
            badguy->move(room);
        badguy = new("/quest/weiguo/menggu/mengu2");
        badguy->move(room);
        badguy = new("/quest/weiguo/menggu/mengu2");
        badguy->move(room);
        message("channel:chat", HIG
        "【朝廷急报】"
        CYN + "在杭州城中中发现蒙古奸细！\n"
        NOR, users());
    }
    if (random(12) == 9) {
        if (objectp(room = load_object("/d/lingzhou/center")) &&
            objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
            badguy->move(room);
        badguy = new("/quest/weiguo/menggu/mengu2");
        badguy->move(room);
        badguy = new("/quest/weiguo/menggu/mengu2");
        badguy->move(room);
        message("channel:chat", HIG
        "【朝廷急报】"
        CYN + "在灵州城中中发现蒙古奸细！\n"
        NOR, users());
    }
    if (random(12) == 10) {
        if (objectp(room = load_object("/d/quanzhou/zhongxin")) &&
            objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
            badguy->move(room);
        badguy = new("/quest/weiguo/xixiabing/xixia2");
        badguy->move(room);
        badguy = new("/quest/weiguo/xixiabing/xixia2");
        badguy->move(room);
        message("channel:chat", HIR
        "【朝廷急报】"
        BLU + "在泉州城中发现西夏奸细！\n"
        NOR, users());
    }
    if (random(12) == 11) {
        if (objectp(room = load_object("/d/suzhou/baodaiqiao")) &&
            objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
            badguy->move(room);
        badguy = new("/quest/weiguo/xixiabing/xixia2");
        badguy->move(room);
        badguy = new("/quest/weiguo/xixiabing/xixia2");
        badguy->move(room);
        message("channel:chat", HIR
        "【朝廷急报】"
        BLU + "在苏州城中发现西夏奸细！\n"
        NOR, users());
    }
    if (random(12) == 12) {
        if (objectp(room = load_object("/d/xiangyang/guangchang")) &&
            objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
            badguy->move(room);
        badguy = new("/quest/weiguo/xixiabing/xixia2");
        badguy->move(room);
        badguy = new("/quest/weiguo/xixiabing/xixia2");
        badguy->move(room);
        message("channel:chat", HIR
        "【朝廷急报】"
        BLU + "在襄阳城中发现西夏奸细！\n"
        NOR, users());
    }
    if (random(16) == 1) {
        if (objectp(room = load_object("/d/huanghe/yongdeng")) &&
            objectp(badguy = new("/quest/weiguo/xixiabing/xixia3")))
            badguy->move(room);
        badguy = new("/quest/weiguo/xixiabing/xixia2");
        badguy->move(room);
        badguy = new("/quest/weiguo/xixiabing/xixia2");
        badguy->move(room);
        badguy = new("/quest/weiguo/xixiabing/xixia1");
        badguy->move(room);
        badguy = new("/quest/weiguo/xixiabing/xixia1");
        badguy->move(room);
        badguy = new("/quest/weiguo/xixiabing/xixia1");
        badguy->move(room);
        badguy = new("/quest/weiguo/xixiabing/xixia1");
        badguy->move(room);
        message("channel:chat", HIR
        "【前线告急】"
        HIW + "西夏大军攻打西北的军事重镇永登！\n"
        NOR, users());
    }
    if (random(16) == 2) {
        if (objectp(room = load_object("/d/quanzhou/zhongxin")) &&
            objectp(badguy = new("/quest/weiguo/japan/japan3")))
            badguy->move(room);
        badguy = new("/quest/weiguo/japan/japan2");
        badguy->move(room);
        badguy = new("/quest/weiguo/japan/japan2");
        badguy->move(room);
        badguy = new("/quest/weiguo/japan/japan1");
        badguy->move(room);
        badguy = new("/quest/weiguo/japan/japan1");
        badguy->move(room);
        badguy = new("/quest/weiguo/japan/japan1");
        badguy->move(room);
        badguy = new("/quest/weiguo/japan/japan1");
        badguy->move(room);
        message("channel:chat", HIR
        "【前线告急】"
        HIW + "倭寇大军在泉州附近登陆！杀我百姓!!\n"
        NOR, users());
    }
    if (random(16) == 4) {
        if (objectp(room = load_object("/d/xiangyang/eastgate1")) &&
            objectp(badguy = new("/quest/weiguo/menggu/mengu3")))
            badguy->move(room);
        badguy = new("/quest/weiguo/menggu/mengu2");
        badguy->move(room);
        badguy = new("/quest/weiguo/menggu/mengu2");
        badguy->move(room);
        badguy = new("/quest/weiguo/menggu/mengu1");
        badguy->move(room);
        badguy = new("/quest/weiguo/menggu/mengu1");
        badguy->move(room);
        badguy = new("/quest/weiguo/menggu/mengu1");
        badguy->move(room);
        badguy = new("/quest/weiguo/menggu/mengu1");
        badguy->move(room);
        message("channel:chat", HIR
        "【前线告急】"
        HIW + "蒙古大军进军事重镇襄阳！襄阳告急!!\n"
        NOR, users());
    }
    if (random(16) == 7) {
        if (objectp(room = load_object("/d/city2/di_anmen.")) &&
            objectp(badguy = new("/quest/weiguo/jinbing/jin3")))
            badguy->move(room);
        badguy = new("/quest/weiguo/jinbing/jin2");
        badguy->move(room);
        badguy = new("/quest/weiguo/jinbing/jin2");
        badguy->move(room);
        badguy = new("/quest/weiguo/jinbing/jin1");
        badguy->move(room);
        badguy = new("/quest/weiguo/jinbing/jin1");
        badguy->move(room);
        badguy = new("/quest/weiguo/jinbing/jin1");
        badguy->move(room);
        badguy = new("/quest/weiguo/jinbing/jin1");
        badguy->move(room);
        message("channel:chat", HIR
        "【前线告急】"
        HIW + "金国完颜氏的部队杀入了京城！京城告危!!\n"
        NOR, users());
    }
}

void event_night() {
    object badguy;
    object room;
    if (random(12) == 1) {
        if (objectp(room = load_object("/d/city/guangchang")) &&
            objectp(badguy = new("/quest/feizei/feizei")))
            badguy->move(room);
        message("channel:chat", HIW
        "【官府通告】"
        HIR + "扬州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"
        NOR, users());
    }
    if (random(12) == 2) {
        if (objectp(room = load_object("/d/city2/di_anmen")) &&
            objectp(badguy = new("/quest/feizei/feizei")))
            badguy->move(room);
        message("channel:chat", HIW
        "【官府通告】"
        HIR + "北京城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"
        NOR, users());
    }
    if (random(12) == 3) {
        if (objectp(room = load_object("/d/city3/guangchang")) &&
            objectp(badguy = new("/quest/feizei/feizei")))
            badguy->move(room);
        message("channel:chat", HIW
        "【官府通告】"
        HIR + "成都城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"
        NOR, users());
    }
    if (random(12) == 4) {
        if (objectp(room = load_object("/d/quanzhen/zhongxin")) &&
            objectp(badguy = new("/quest/feizei/feizei")))
            badguy->move(room);
        message("channel:chat", HIW
        "【官府通告】"
        HIR + "长安城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"
        NOR, users());
    }
    if (random(12) == 5) {
        if (objectp(room = load_object("/d/dali/taihejiekou")) &&
            objectp(badguy = new("/quest/feizei/feizei")))
            badguy->move(room);
        message("channel:chat", HIW
        "【官府通告】"
        HIR + "大理城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"
        NOR, users());
    }
    if (random(12) == 6) {
        if (objectp(room = load_object("/d/foshan/street3")) &&
            objectp(badguy = new("/quest/feizei/feizei")))
            badguy->move(room);
        message("channel:chat", HIW
        "【官府通告】"
        HIR + "佛山城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"
        NOR, users());
    }
    if (random(12) == 7) {
        if (objectp(room = load_object("/d/fuzhou/dongjiekou")) &&
            objectp(badguy = new("/quest/feizei/feizei")))
            badguy->move(room);
        message("channel:chat", HIW
        "【官府通告】"
        HIR + "福州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"
        NOR, users());
    }
    if (random(12) == 8) {
        if (objectp(room = load_object("/d/hangzhou/road13")) &&
            objectp(badguy = new("/quest/feizei/feizei")))
            badguy->move(room);
        message("channel:chat", HIW
        "【官府通告】"
        HIR + "杭州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"
        NOR, users());
    }
    if (random(12) == 9) {
        if (objectp(room = load_object("/d/lingzhou/center")) &&
            objectp(badguy = new("/quest/feizei/feizei")))
            badguy->move(room);
        message("channel:chat", HIW
        "【官府通告】"
        HIR + "灵州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"
        NOR, users());
    }
    if (random(12) == 10) {
        if (objectp(room = load_object("/d/quanzhou/zhongxin")) &&
            objectp(badguy = new("/quest/feizei/feizei")))
            badguy->move(room);
        message("channel:chat", HIW
        "【官府通告】"
        HIR + "泉州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"
        NOR, users());
    }
    if (random(12) == 11) {
        if (objectp(room = load_object("/d/suzhou/baodaiqiao")) &&
            objectp(badguy = new("/quest/feizei/feizei")))
            badguy->move(room);
        message("channel:chat", HIW
        "【官府通告】"
        HIR + "苏州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"
        NOR, users());
    }
    if (random(12) == 12) {
        if (objectp(room = load_object("/d/xiangyang/guangchang")) &&
            objectp(badguy = new("/quest/feizei/feizei")))
            badguy->move(room);
        message("channel:chat", HIW
        "【官府通告】"
        HIR + "襄阳城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"
        NOR, users());
    }

}

void event_afternoon() {
    object *ob_list;
    int i;
    ob_list = children("/quest/weiguo/japan/japan1");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，撤兵！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/japan/japan2");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，撤兵！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/japan/japan3");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，撤兵！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/japan/japan4");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，东西也到手了，我闪！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/jinbing/jin1");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，撤兵！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/jinbing/jin2");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，撤兵！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/jinbing/jin3");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，撤兵！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/jinbing/jin4");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，东西也到手了，我闪！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/menggu/mengu1");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，撤兵！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/menggu/mengu2");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，撤兵！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/menggu/mengu3");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，撤兵！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/menggu/mengu4");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，东西也到手了，我闪！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/xixiabing/xixia1");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，撤兵！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/xixiabing/xixia2");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，撤兵！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/xixiabing/xixia3");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，撤兵！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
    ob_list = children("/quest/weiguo/xixiabing/xixia4");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N说道：天要黑了，东西也到手了，我闪！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
}

void event_dawn() {
    object *ob_list;
    int i;
    ob_list = children("/quest/feizei/feizei");
    for (i = 0; i < sizeof(ob_list); i++)
        if (environment(ob_list[i])) {
            message_vision("$N笑道：天亮了，东西也到手了，我闪！\n", ob_list[i]);
            destruct(ob_list[i]);
        }
}

void event_midnight() {
    string get_month, get_day;
    get_day = CHINESE_D->chinese_monthday(TIME_TICK1);
    get_month = CHINESE_D->chinese_month(TIME_TICK1);
    switch (get_month) {
        //spring weather
        case "三":
        case "四":
        case "五":
            switch (random(3)) {
                case 0:
                    day_phase = read_table("/adm/etc/nature/spring_rain");
                    break;
                case 1:
                    day_phase = read_table("/adm/etc/nature/spring_sun");
                    break;
                case 2:
                    day_phase = read_table("/adm/etc/nature/spring_wind");
                    break;
            }
            break;
            //summer weather
        case "六":
        case "七":
        case "八":
            switch (random(3)) {
                case 0:
                    day_phase = read_table("/adm/etc/nature/summer_rain");
                    break;
                case 1:
                    day_phase = read_table("/adm/etc/nature/summer_sun");
                    break;
                case 2:
                    day_phase = read_table("/adm/etc/nature/summer_wind");
                    break;
            }
            break;
            //autumn weather
        case "九":
        case "十":
        case "十一":
            switch (random(3)) {
                case 0:
                    day_phase = read_table("/adm/etc/nature/autumn_rain");
                    break;
                case 1:
                    day_phase = read_table("/adm/etc/nature/autumn_sun");
                    break;
                case 2:
                    day_phase = read_table("/adm/etc/nature/autumn_wind");
                    break;
            }
            break;
            //winter weather
        case "十二":
        case "一":
        case "二":
            switch (random(3)) {
                case 0:
                    day_phase = read_table("/adm/etc/nature/winter_rain");
                    break;
                case 1:
                    day_phase = read_table("/adm/etc/nature/winter_sun");
                    break;
                case 2:
                    day_phase = read_table("/adm/etc/nature/winter_wind");
                    break;
            }
            break;
        default:
            day_phase = read_table("/adm/etc/nature/day_phase");
    }
//        switch(get_day)
//        {
//                case "一月一日":
//                     day_phase = read_table("/adm/etc/nature/spring");
//                     break;
//                case "五月五日":
//                case "七月七日":
//                case "八月十五日":
//                case "九月九日":
//                case "十二月八日":
//        }
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

void event_noon() {
    object *ob;
    int i, skill, con, con1, con2, con3;
    string get_month, ill, msg;
    get_month = CHINESE_D->chinese_month(TIME_TICK1);
    switch (get_month) {
        case "三":
        case "四":
        case "五":
            ill = "ill_kesou";
            msg = HIG + "忽然喉头一阵痕痒，你感觉似乎要咳嗽了。\n" + NOR;
            break;
        case "六":
        case "七":
        case "八":
            ill = "ill_zhongshu";
            msg = HIG + "突然你胸臆之间一阵翻腾，你中暑了。\n" + NOR;
            break;
        case "九":
        case "十":
        case "十一":
            ill = "ill_shanghan";
            msg = HIG + "陡的你打了个冷战，头昏沉沉的，你得伤寒病了。\n" + NOR;
            break;
        case "十二":
        case "一":
        case "二":
            ill = "ill_dongshang";
            msg = HIG + "你肢体末端一阵僵直，看来你被冻伤了。\n" + NOR;
            break;
    }
    if (random(2)) {
        ill = "ill_fashao";
        msg = HIG + "你偶感风寒，竟而发起烧来。\n" + NOR;
    }
    ob = users();
    for (i = 0; i < sizeof(ob); i++) {
        if (!environment(ob[i])) continue;
        if (!environment(ob[i])->query("outdoors")) continue;
        if (ob[i]->query("age") == 14) continue;
        con1 = ob[i]->query("qi");
        con2 = ob[i]->query("max_qi");
        (int) con = con1 / con2 * 50;//形成第一个生病判断条件
        con3 = ob[i]->query("neili");
        con2 = ob[i]->query("max_neili");
        if (con2 == 0) con2 = 1;
        (int) con1 = con3 / con2 * 50;//形成第二个生病判断条件
        if (random(con) + random(50) + random(con1) < 25) {
            ob[i]->apply_condition(ill, 10);
            tell_object(ob[i], msg);
        }
    }
}

string outdoor_room_description() {
    return "    " + sprintf(
            day_phase[current_day_phase]["desc_msg"],
            month_desc[current_month]) + "。\n";
}

string outdoor_room_outcolor() {
    return day_phase[current_day_phase]["outcolor"];
}

string game_time() {
    return CHINESE_D->chinese_date(TIME_TICK1);
}

mapping *read_table(string file) {
    string *line, *field, *format;
    mapping *data;
    int i, rn, fn;

    line = explode(read_file(file), "\n");
    data = ({});
    for (i = 0; i < sizeof(line); i++) {
        if (line[i] == "" || line[i][0] == '#') continue;
        if (!pointerp(field)) {
            field = explode(line[i], ":");
            continue;
        }
        if (!pointerp(format)) {
            format = explode(line[i], ":");
            continue;
        }
        break;
    }

    for (rn = 0, fn = 0; i < sizeof(line); i++) {
        if (line[i] == "" || line[i][0] == '#') continue;
        if (!fn) data += ({ allocate_mapping(sizeof(field)) });
        sscanf(line[i], format[fn], data[rn][field[fn]]);
        fn = (++fn) % sizeof(field);
        if (!fn) ++rn;
    }
    return data;
}

mapping *query_day_phase() { return day_phase; }

