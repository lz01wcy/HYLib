//jianzhen.c 【七星剑阵】csy 99.05.26

#include <ansi.h>

inherit F_SSERVER;

void npc_attack(object invoker, object target, string npc, object where);

int perform(object me, object target)
{
        string msg;
        string npc_dir = "/d/quanzhen/npc/";
        object where;

        if( !target ) target = offensive_target(me);

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me
        ||   !me->is_fighting(target))
                return notify_fail("你想请全真七子对付谁呀？\n");

        if((string)me->query("family/family_name") != "全真教" )
                return notify_fail("你又不是全真教弟子，全真七子哪里会帮你？\n");

        if((string)target->query("family/family_name") == "全真教" )
                return notify_fail("同门相斗叫师傅帮忙？\n");

        if((int)me->query_skill("qixing-array", 1) < 150)
                return notify_fail("你的北斗七星阵修为不深，无法和全真七子组合剑阵。\n"); 

        if((int)me->query_skill("quanzhen-jian", 1) < 150)
                return notify_fail("你的全真剑法修为不深，不能和全真七子相配合。\n");        

        if((int)me->query("neili") < 300 )
                return notify_fail("你的内力不够，没办法和全真七子相配合。\n"); 
       
        if((int)me->query("jing") < 60 )
                return notify_fail("你现在神智不清，不被人拿已是万幸了！\n");

        me->add("neili", -200);
        me->receive_damage("jing", 10);

        if( random(me->query("max_qi")) < 60 ) 
        {
                write("咦？全真七子好象不在附近。\n");
                return 1;
        }

     msg = HIR "\n$N袍袖一展，一道火光冲天而起，只听见$N大喝一声：全真七子现在何处？\n" NOR +
              HIY "\n只听四周一连串的声音答道：「广宁子」郝大通！"+
               "．「长生子」刘处玄！．「长春子」丘处机！．．在此！\n"NOR +
              HIR "\n$N一指$n：此人无恶不作，罪大恶极，请师父师叔替弟子拿人！\n\n" NOR;      
        message_vision(msg, me, target);
        msg = HIC "$n对着$N高声骂道：好家伙，一拥而上了，我宰了你！\n\n" NOR;     
        message_vision(msg, me, target);
//        target->kill_ob(me);
        
        where=environment(target);
        call_out("npc_attack", 2, me, target, npc_dir+"hao", where);
        call_out("npc_attack", 3, me, target, npc_dir+"liu", where);
        call_out("npc_attack", 5, me, target, npc_dir+"ma", where);
        call_out("npc_attack", 6, me, target, npc_dir+"qiu", where);
        call_out("npc_attack", 8, me, target, npc_dir+"sun", where);
        call_out("npc_attack", 9, me, target, npc_dir+"tan", where);
        call_out("npc_attack", 11, me, target, npc_dir+"wangchuyi", where);
        me->start_busy(2);
        return 30+random(30);
}

void npc_attack(object invoker, object target, string npc, object where)
{
        object attacker;
        int rd;
        string tid;

        if(!invoker || !target) return;

        if( environment(invoker) != environment(target) ) return;
        if( environment(target) != where) return;

        seteuid(getuid());
        attacker = new(npc);
        attacker->move(environment(invoker));

        //do not attack too weak ppls...
        if( (int)target->query("combat_exp") < 10000 )
        {
                tid = (string)target->query("id");
                rd = random(7);
                if( rd == 0 ) attacker->command_function("wait " + tid);
                else if( rd == 1 ) attacker->command_function("kick " + tid);
                else if( rd == 2 ) attacker->command_function("kok " + tid);
                else if( rd == 3 ) attacker->command_function("slogan " + tid);
                else if( rd == 4 ) attacker->command_function("tx " + tid);
                else if( rd == 5 ) attacker->command_function("hammer " + tid);
                else attacker->command_function("pei " + tid);
        }
        else
        {
                COMBAT_D->do_attack(attacker, target, attacker->query_temp("weapon"));
        
                // give the killing credit to the invoker.
                // so this would be counted as PK if the invoker is user.
                if(target->query_temp("last_damage_from")==attacker)
                        target->set_temp("last_damage_from", invoker);
        
                if(target->query_temp("last_fainted_from")==attacker)
                        target->set_temp("last_fainted_from", invoker->query("id"));
        }
        destruct(attacker);
}


