#include <ansi.h> 
inherit F_SSERVER;
int bbqthem(object me, object obj);

int perform(object me, object target)
{
        int lvl,i,j,k, bonus;
        object env, *inv, *myteam;

        if((int) me->query_skill("kwan-yin-spells",1) < 150)
                return notify_fail("你的真言法术修为不够高深！\n");
        if (!me->is_fighting())
                return notify_fail("“恕敝荒茉谡蕉分惺褂谩\n");
                        
        lvl = (int) me->query_skill("magic");
        bonus = (me->query("combat_exp")-4000000)/15000;
        if (bonus<0) bonus=0;
        if (bonus>200) bonus = 200; 
        if( me->query("neili") < (300 - bonus) )
                return notify_fail("你的法力不够！\n");
        if( me->query("jing") <= 200 )
                return notify_fail("你的神不够！\n"); 
        me->add("neili", bonus-300);
        me->receive_damage("jing", 100);
        
        message_vision(HIW "$N右手于胸前展成莲花之状，左手折腕向上势若莲台，沉于右手下，面容肃静念道：“恕 \n" NOR, me);
        message_vision(HIY "．．．只见$N双手一瞬间发出比太阳还要耀眼的光芒！！！\n" NOR, me); 
        env = environment(me);
        inv = all_inventory(env); 
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( inv[i]->is_corpse() ) continue;
                if( !inv[i]->is_character()) continue;
                if( !me->is_fighting(inv[i])) continue;
                bbqthem(me, inv[i]);
        }
        me->start_busy(2);
        return 1; 
}  
int bbqthem(object me, object obj) 
{
        int spells, busy_num;
        string id_enemy;
        spells = (int) me->query_skill("magic");
        spells = spells+ random(spells*2);
        if(obj->query("combat_exp")>random(me->query("combat_exp")/100*spells))
        {
                message_vision(HIB"$N连忙转过头去，不看$n。\n"NOR,obj,me);
                //obj->kill_ob(me);
                //me->kill_ob(obj);
                return 1;
        }
        if(userp(obj))
        {
                tell_object(obj,HIW"你只觉得眼前白茫茫的一片，什么都看不到了。。。\n"NOR);
                obj->set_temp("block_msg/all",1);
                obj->start_busy(5);
                message_vision(CYN"$N痛苦地捂住眼睛，直在地上打滚。\n"NOR,obj);
                call_out ("recover",10, obj);
        }
        else
        {
                if (obj->query("no_busy")) {
                        busy_num = obj->query("no_busy");
                        obj->delete("no_busy");
                         obj->start_busy(8);
                        call_out ("busy_recover",12, busy_num, obj);
                        }
                obj->start_busy(3+random(2));
                message_vision(CYN"$N痛苦地捂住眼睛，直在地上打滚。\n"NOR,obj);
        }
        return 1;
}  
int recover (object obj)
{
        obj->delete_temp("block_msg/all");
        tell_object(obj, HIG"慢慢慢慢的，你的眼睛开始可以分辨周围的事物了。\n" NOR);
        return 1;
}        
int busy_recover (int busy_num, object obj)
{
   obj->set("no_busy",busy_num);
        return 1;
}         
