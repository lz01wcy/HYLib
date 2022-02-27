// Deamon:/adm/daemons/autorebootd.c
/* 这个是由jjgod为模拟华附大幅度改写原waiwai的自动重启系统，
    自动重启看起来还是必要的，当巫师平时不在线的时候，可以通过
    重启恢复原来的状态。原先waiwai的那个系统太过繁琐，15分钟
    倒计时居然要写15个函数！假如200分钟倒计时岂不是要写200个
    函数？真是好笑。我现在改为只需要2个函数就够了，无论多长的
    倒计时都可以自己设置。*/

#include <ansi.h>
#include <net/daemons.h>

inherit F_DBASE;

private void count_time(int min);

void auto_reboot_start();

void auto_reboot_done();

void create() {
//	object *ob = users();本来想实现有天神在线时就不启动此程序来占用资源，当游戏中一个天神都没有的时候，
//	int i;		 重启工作就交由此程序托管的，但越做越麻烦，还是算了，有兴趣的用这里的代码自己做吧。
    seteuid(ROOT_UID);
    set("channel_id", "自动定时启动精灵");
/*	for(i=0; i<sizeof(ob); i++){
		if (wizhood(ob[i])=="(admin)")
		{
		tell_object(ob[i],ob[i]->name()+"，因为作为天神的你还在线，所以自动重启精灵不被加载！\n");
		log_file("AUTOREBOOT", sprintf("autoreboot启动失败！\n"));
		return;
		}
		else {*/
    CHANNEL_D->do_channel(this_object(), "sys", "自动定时重启精灵已经启动。");
    call_out("auto_reboot_start", 86400 + random(500));// 2天自动重启
//		call_out("auto_reboot_start", 2);// 2天自动重启
/*		call_out("auto_reboot_start",20);
		log_file("AUTOREBOOT", sprintf("autoreboot启动成功！\n"));
		return;
		}
	}*/
}

void auto_reboot_start() {
    remove_call_out("auto_reboot_start");
    message("system", RED
    "【重启精灵】"
    BLU
    "现在开始海洋II自动重启倒计时，还有5分钟！\n"
    NOR, users());
    call_out("count_time", 60, 5); // "15"是指整个倒计时时间15分钟，可以自己修改
}

private void count_time(int min) {
    min--;
    if (min) {
        message("system", RED
        "【重启精灵】"
        BLU
        "各位玩家，离海洋II自动重启还有" + chinese_number(min) + "分钟的时间！\n"
        NOR, users());
        call_out("count_time", 60, min); // 告诉大家还有几分钟时间
    } else {
        message("system", RED
        "【重启精灵】"
        BLU
        "各位玩家，海洋II现在自动重启！！！\n"
        NOR, users());
        call_out("auto_reboot_done", 3 + random(8)); // 到点啦
    }
}

void auto_reboot_done() {
    int i, j;
    object *ob, link_ob;
    string id;
    j = 0;
    seteuid(getuid());
//	set("channel_id", "存盘精灵"); // 这段存盘的代码看上去就不大顺眼，肯定写的不太好，但太晚了我就不改它了
//	ob=users();
//	i=sizeof(ob);
//	for( i=0;i<sizeof(ob);i++) {
//	id = (string) ob[i]->query("id");
//	if (!id) continue;
//	if(!environment(ob[i]) )        continue;
//	if( !objectp(link_ob = ob[i]->query_temp("link_ob")) ) continue;
//	if( (int)link_ob->save() && (int)ob[i]->save() ) j = 1;
//	else CHANNEL_D->do_channel( this_object(), "sys", ob[i]->query("name")+"档案自动存盘失败。");
//	}
//	CHANNEL_D->do_channel( this_object(), "sys", "档案自动存盘成功。");
    shutdown(0);
    return;
}
