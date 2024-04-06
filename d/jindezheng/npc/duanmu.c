inherit NPC;
inherit F_VENDOR;

string query_save_file() { return DATA_DIR+"npc/端木良庸";}
void create()
{
	set_name("端木良庸", ({ "duanmu" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位端木良庸正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

	set("vendor_goods", ({
		__DIR__"obj/guijia",

	}));


	set("area_name","景德镇藏珍阁");
	set("area_file","/d/jindezheng/gudong-shop.c");

        setup();
carry_object("/clone/misc/cloth")->wear();        
}
void init()
{
::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");

}
