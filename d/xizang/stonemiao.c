 // work.c
//#include "/feature/damage.c" 
inherit ROOM; 
void create()
{
        set("short", "石庙");
        set("long", @LONG
庙门早已因为日久失修而倒塌，庙内的装饰简陋，除了一张供奉的石几，四五
张石凳之外，几乎什么都没有。庙中安放了一座财神石像，石像的表情虽然栩栩如
生，但表面粗糙色彩黯淡，唯一值得欣慰的是，财神像面前的石几上，香火鼎盛。
石庙倚着圣母雪峰的山脚而起，地势略高，就算关了门都还是感觉到一阵冰凉。石
凳旁站着两男两女闲谈，隐约听见他们提到什么“金子”、“银子”、“赌局”。

LONG
        ); 
    set("exits", ([ /* sizeof() == 1 */
                "northdown" : __DIR__"stoneroad",
        ])); 
        set("objects", ([
                __DIR__"npc/master4" : 1,       
                __DIR__"npc/master3" : 1,       
                __DIR__"npc/master2" : 1,       
                __DIR__"npc/master1" : 1,       
        ]));
    set("indoors", "guanwai"); 
    set("coor/x",-1240);
        set("coor/y",-50);
        set("coor/z",10);
        setup();
}      
