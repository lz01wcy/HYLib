 // garrison.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("小衙役", ({ "yayi", "ya" }) );
        set("long",
                "正在上堂的衙役，千万不要惹他们\n"); 
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
//      set("pursuer", 1); 
        set("str", 27);
        set("cor", 26);
        set("cps", 25); 
        set("combat_exp", random(10000)); 
        set_skill("unarmed", 70+random(100));
        set_skill("staff", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100)); 
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/parry", 70);
        set_temp("apply/damage", random(100));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
"衙役低声宣道：威～～～～武～～～～\n"
        }) ); 
        setup(); 
        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(__DIR__"obj/sawei")->wield();
}   
