//Map here功能  By JackyBoy 1999/11/19
//由于严重影响速度（递归调用导致！），所以进行此命令的使用应该减少玩家的精力或者气息
#include <ansi.h>
#define MaxX 7
#define MaxY 30
inherit F_CLEAN_UP;
int X=7,Y=10;
static mixed m;
static string *rfile;
int draw_room(int,int,object);

void realtime_map(object me,object env)
{
        object room_obj;
        mapping exits;
    int i;
        string map_room, map_room2,jiantou,fname;
     string *dirs;
        mapping alldirs=([      
                        "northwest" : "          ",
                        "north"     : "          ",
                        "northup"   : "          ",
                        "northeast" : "          ",
                        "west"      : "          ",
                        "east"      : "          ",
                        "southeast" : "          ",
                        "south"     : "          ",
                        "southwest" : "          ",
                        "southdown" : "          ",
                        "eastup" : "          ",
                        "southup" : "          ",
                        "northdown" : "          ",
                        "eastdown" : "          ",
                        "westup" : "          ",
                        "westdown" : "          ",
                        "enter" : "          ",
                        "out" : "          ",
                        "up" : "          ",
                        "down" : "          ",
                        "left" : "          ",
                        "right" : "          ",
                        ]);  
       if( mapp(exits = env->query("exits")) ) 
        {                       
                dirs=keys(exits);
                for(i=0;i< sizeof(dirs);i++)
                {
                        if(!room_obj=find_object(exits[dirs[i]]))
                                room_obj=load_object(exits[dirs[i]]);
                        if(room_obj){

		fname=file_name(room_obj);
		fname=replace_string(fname, "/d/migong/lev", "");
		fname=replace_string(fname, "/dong/", "");
		fname=replace_string(fname, "dong", "");
                                
                                if (room_obj->query("short"))
                                alldirs[dirs[i]]=room_obj->query("short")+"["+fname+"]";                              ;
                                }
        
                }
        
                jiantou="  ";
                map_room2=alldirs["enter"];
                if(alldirs["enter"]!="          "){
                        map_room2=alldirs["enter"];
                        jiantou=HIR+"∧"+NOR;
                        }
                if(alldirs["up"]!="          "){
                        map_room2=alldirs["up"];
                        jiantou=HIC+"〓"+NOR;
                        }
                if(alldirs["northdown"]!="          "){
                        map_room2=alldirs["northdown"];
                        jiantou="↓";
                        }
                if(alldirs["northup"]!="          "){
                        map_room2=alldirs["northup"];
                        jiantou="↑";
                        }
                if(alldirs["north"]!="          "){
                        map_room2=alldirs["north"];
                        jiantou="｜";
                        }
                map_room=map_room2;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                map_room =map_room+" ";
                                map_room =" "+map_room;
                        }
                printf("             %10s  %-10s  %-10s\n",
                alldirs["northwest"],map_room,alldirs["northeast"]);
                
                printf("                        %s   %s   %s\n",
                alldirs["northwest"]=="          " ? "  ":"＼",
                jiantou,
                alldirs["northeast"]=="          " ? "  ":"／");
                
                jiantou="  ";
                map_room2=alldirs["westdown"];
                if(map_room2!="          ")
                                jiantou="→";
                if(alldirs["left"]!="          "){
                        map_room2=alldirs["left"];
                        jiantou="〈";
                        }
                if(alldirs["westup"]!="          "){
                        map_room2=alldirs["westup"];
                        jiantou="←";
                        }
                if(alldirs["west"]!="          "){
                        map_room2=alldirs["west"];
                        jiantou="--";
                        }
                printf("             %10s%s",map_room2,jiantou);        
                map_room2=env->query("short") ? env->query("short"): "----------";
                map_room=HIG+map_room2+NOR;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                if(alldirs["east"]=="          ")
                                map_room =map_room + " ";
                                else map_room=map_room + "-";
                                if(alldirs["west"]=="          ")
                                map_room =" "+ map_room;
                                else map_room ="-"+map_room;
                        }
                printf("%s",map_room);
                
                jiantou="  ";
                map_room2=alldirs["eastup"];
                if(map_room2!="          ")
                                jiantou="→";
                if(alldirs["right"]!="          "){
                        map_room2=alldirs["right"];
                        jiantou="〉";
                        }
                if(alldirs["eastdown"]!="          "){
                        map_room2=alldirs["eastdown"];
                        jiantou="←";
                        }
                if(alldirs["east"]!="          "){
                        map_room2=alldirs["east"];
                        jiantou="--";
                        }
                
                printf("%s%-10s\n",jiantou,map_room2);
                
                jiantou="  ";
                map_room2=alldirs["out"];
                if(alldirs["out"]!="          "){
                        map_room2=alldirs["out"];
                        jiantou=HIR+"∨"+NOR;
                        }
                if(alldirs["down"]!="          "){
                        map_room2=alldirs["down"];
                        jiantou=HIC+"〓"+NOR;
                        }
                
                if(alldirs["southdown"]!="          "){
                                map_room2=alldirs["southdown"];
                                jiantou="↑";
                                }
                if(alldirs["southup"]!="          "){
                        map_room2=alldirs["southup"];
                        jiantou="↓";
                        }
                if(alldirs["south"]!="          "){
                        map_room2=alldirs["south"];
                        jiantou="｜";
                        }
                map_room=map_room2;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                map_room =map_room + " ";
                                map_room =" "+map_room;
                        }
                printf("                        %s   %s   %s\n",
                alldirs["southwest"]=="          " ? "  ":"／",
                jiantou,
                alldirs["southeast"]=="          " ? "  ":"＼");
                printf("             %10s  %-10s  %-10s\n",
                alldirs["southwest"],map_room,alldirs["southeast"]);
                
                        
        }       
        else
        {
                map_room2=env->query("short") ? env->query("short"): "----------";
                map_room=HIG+map_room2+NOR;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                if(alldirs["east"]=="          ")
                                map_room =map_room + " ";
                                else map_room=map_room + "-";
                                if(alldirs["west"]=="          ")
                                map_room =" "+ map_room;
                                else map_room ="-"+map_room;
                        }
                printf("\n                            %s\n",map_room);
                
        }
        return;
}


string clean_color(string arg)
{
	if(!arg)
		return "";
	arg = replace_string(arg, BLK, "");
	arg = replace_string(arg, RED, "");
	arg = replace_string(arg, GRN, "");
	arg = replace_string(arg, YEL, "");
	arg = replace_string(arg, BLU, "");
	arg = replace_string(arg, MAG, "");
	arg = replace_string(arg, CYN, "");
	arg = replace_string(arg, WHT, "");
	arg = replace_string(arg, HIR, "");
	arg = replace_string(arg, HIG, "");
	arg = replace_string(arg, HIY, "");
	arg = replace_string(arg, HIB, "");
	arg = replace_string(arg, HIM, "");
	arg = replace_string(arg, HIC, "");
	arg = replace_string(arg, HIW, "");
	arg = replace_string(arg, NOR, "");
	arg = replace_string(arg, BLINK,"");
	return arg;
}
int main(object me, string arg)
{
	object where,nroom;
	int i,j,f1,f2;
	string tmp,fname,*dirs;
mapping dir;
    if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
    if (me->is_busy()) 
        return notify_fail("你正热闹着呢!\n");
    if (me->query("neili")<800)
	return notify_fail("你的内力不足!\n");
    if (me->is_busy())
    return notify_fail("你正忙着呢!\n");
    if(me->query("qi")<40)
		return notify_fail("你的体力不太好了，先休息一下吧！\n");
	me->add("qi",-20);
    if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR
||environment(me)->query("magicroom"))
{
	if(arg)
	{
		//允许在指定范围内自定义房间搜索范围！
		arg=lower_case(arg);
		sscanf(arg,"%*sx=%d%*s",X);
		sscanf(arg,"%*sy=%d%*s",Y);
		if(X>MaxX||X==0) X=MaxX;
		if(Y>MaxY||Y==0) Y=MaxY;
	}
		//name=name+fname[0..3];
		fname=file_name(environment(me));
		fname=replace_string(fname, "/d/migong/lev", "");
		fname=replace_string(fname, "/dong/", "");
		fname=replace_string(fname, "dong", "");
	tmp="即时地图  v1.0\n所在房间："+fname+"""\n";
	m=allocate(2*X+1);
	rfile=({});
	for(i=0;i<2*X+1;i++)
	{
		m[i]=allocate(2*Y+1);
		for(j=0;j<2*Y+1;j++)
			m[i][j]=" ";
	}
	where=environment(me);
	if(!objectp(where))
		return notify_fail("对不起，不知道你到底在哪里呀！找巫师吧！\n");
	draw_room((2*X+1)/2,(2*Y+1)/2,where);
	for(i=0;i<2*Y+1;i++)
	{
		for(j=0;j<2*X+1;j++)
		{
			if(m[j][i]==" "&&i%2&&j%2)
				tmp+="        ";
			else
			{
				//如果此项为空，并且此时j为偶数列，则输出空格
				if(m[j][i]==" "&&!(j%2))
					tmp+="  ";
				else
				if(m[j][i]==" ")
					tmp+="        ";
				else
				{
					tmp+=m[j][i];
					//if(!(i%2)&&!(j%2))
					if(m[j][i]!="─")
						for(int d=8-sizeof(clean_color(m[j][i]));d>0;d--)
							tmp+=" ";
				}
			}
		}
		tmp+="\n";
	}


      
	me->start_more(tmp);

	

if (me->query("combat_exp") > 8000000)
        me->add("neili",-me->query("max_neili")/4);
if (me->query("combat_exp") > 3000000)
        me->add("neili",-me->query("max_neili")/5);
if (me->query("combat_exp") > 1000000)
        me->add("neili",-me->query("max_neili")/6);
else    me->add("neili",-100);
if (random(6)==0)
  realtime_map(me,environment(me));        

	me->start_busy(6);
	return 1;
}	
else 
{
        message_vision(HIG "$N这里不能使用!\n" NOR, me);
	return 1;
}
}

object find_room(string path)
{
	object ob;
	if(objectp(ob=find_object(path))||objectp(ob=load_object(path)))
		return ob;
	return 0;
}

//←↑→↓IJKL
int draw_path(int x,int y,string direc)
{
	string str;
	int xx=0,yy=0;
	switch(direc)
	{
		case "south":
		case "north":str="   │   ";break;
		case "southdown":
		case "northup":str="   ↑   ";break;
		case "southup":
		case "northdown":str="   ↓   ";break;
		case "east":
		case "west":str="─";break;
		case "eastup":
		case "westdown":str="→";break;
		case "westup":
		case "eastdown":str="←";break;
		case "southeast":
		case "northwest":str="J";break;
		case "shothwest":
		case "northeast":str="I";break;
		default:
			return 0;
	}
	if(sscanf(direc,"%*ssouth%*s"))
		yy++;
	if(sscanf(direc,"%*snorth%*s"))
		yy--;
	if(sscanf(direc,"%*seast%*s"))
		xx++;
	if(sscanf(direc,"%*swest%*s"))
		xx--;
	if(x+xx<0||y+yy<0||x+xx>2*X||y+yy>2*Y)
		return 0;
	//write("设置第 "+(x+xx)+ " "+(y+yy)+" 项\n");
	m[x+xx][y+yy]=str;
	return 1;
}
	
int draw_room(int x,int y,object room)
{
	int i,nst=0,xx,yy,f1,f2;
	string name,fname,*dirs;
	string tmp;
	object nroom;
	mapping dir;
	reset_eval_cost();
	if(x<0||y<0||!objectp(room)||x>2*X||y>2*Y)
		return 0;
	name=clean_color(room->query("short"));//求取无颜色的房间short描述
	//write("坐标："+x+" / "+ y+ "处理 "+name+" 文件名："+base_name(room)+"\n");
	rfile=rfile + ({ base_name(room) });
	dir=room->query("exits");
	if(!mapp(dir)||sizeof(dir)<1)
		return 0;
	dirs=keys(dir);
	for (i=0;i<sizeof(dirs);i++)
	{
		xx=0;yy=0;
		if(sscanf(dirs[i],"%*ssouth%*s"))
			yy+=2;
		if(sscanf(dirs[i],"%*snorth%*s"))
			yy-=2;
		if(sscanf(dirs[i],"%*seast%*s"))
			xx+=2;
		if(sscanf(dirs[i],"%*swest%*s"))
			xx-=2;
		if(!draw_path(x,y,dirs[i])||(xx==0&&yy==0))
			nst=1;
		nroom=find_room(dir[dirs[i]]);
		//避免重复调用
		if(!objectp(nroom)||nst)
			continue;
		fname=file_name(nroom);
		fname=replace_string(fname, "/d/migong/lev", "");
		fname=replace_string(fname, "/dong/", "");
		fname=replace_string(fname, "dong", "");
		//name=name+fname;
		if(member_array(base_name(nroom),rfile)==-1)
			draw_room(x+xx,y+yy,nroom);
	}
	if(strlen(name)>8)
		name=name[0..7];
	if(strlen(name)<7)//对不足4个汉字的房间名进行居中处理
	{
		int d=8-strlen(name);
		if(d%2)
		{
			name+=" ";
			d--;
		}
		for(i=0;i<d/2;i++)
			name=" "+name+" ";
	}
	if(nst)
		name=HIY+name;
	if((x==(2*X+1)/2)&&(y==(2*Y+1)/2))
		name=BLINK+name;
	name+=NOR;
	m[x][y]=name;
	return 1;
}


int help()
{
	write(@HELP
	即时地图 v1.0 (Write By JackyBoy 99/11/20)
	命令用法：map [x=1-7] [y=1-30]
本命令帮助玩家了解周围的房间地图的分布状况，并标志出房间之间的连接情况。
理论上讲，该命令应该能完全正确地反应地图，但是由于巫师设计地图不规范等多
种原因（比如迷宫、有不规范出口比如enter之类的，房间之间无法双向关联等），
导致地图可能在显示时与行走方向上有一定区别，甚至会出现走一步路，地图就完
全变样的情况。比如，房间A可以从south走到B房间，但是B房间走north却走到C房
间，这时在A用该命令与在B用该命令效果完全不一样！
此外，连接标志中箭头所指方向地势更高，有不规范出口的房间以黄色标志，你所
处的房间以闪烁来标志！
本命令默认以x=7,y=10 的地图大小显示，你可以在命令行手动指定地图大小。
HELP);
	return 1;
}



