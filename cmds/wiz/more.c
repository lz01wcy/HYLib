// cat.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string file;
	object ob;

	seteuid(geteuid(me));
	if (!arg) return notify_fail("指令格式 : more <档名>|<物件名> \n");
	file = resolve_path(me->query("cwd"), arg);
if( sscanf(file, "/log/%*s") ) 
return notify_fail("log目录下文件，请不要随便查看!!\n");

	//记录查看的文件/log/cmds/more   山猫(adx)
	log_file("cmds/more",
	sprintf("%s(%s) more %s on %s\n",
	me->name(1), //记录使用命令的人名
	geteuid(me), //记录使用命令的ID
	file,        //记录读取文件的路径
	ctime(time()) ) ); //记录使用命令的时间

	if( file_size(file) < 0 ) {
		ob = present(arg, me);
		if( !ob ) ob = present(arg, environment(me));
		if( !ob ) return notify_fail("没有这个档案。\n");
		file = base_name(ob) + ".c";
	}
	me->start_more( read_file(file));
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : topten rich <物件名>
HELP
    );
    return 1;
}
