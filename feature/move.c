// move.c

//#pragma optimize

#include <ansi.h>
#include <dbase.h>
#include <room.h>

static int weight = 0;
static int encumb = 0, max_encumb = 0;

nomask int query_encumbrance() { return encumb; }

nomask int over_encumbranced() { return encumb > max_encumb; }

nomask int query_max_encumbrance() { return max_encumb; }

nomask void set_max_encumbrance(int e) { max_encumb = e; }

nomask void add_encumbrance(int w) {
    object me = this_object();

    encumb += w;
    if (encumb < 0)
        log_file("move.bug", sprintf("%O encumbrance underflow.\n", me));
    if (encumb > max_encumb) me->over_encumbrance();
    if (environment()) environment()->add_encumbrance(w);
}

void over_encumbrance() {
    object me = this_object();

    if (!interactive(me)) return;
    tell_object(me, "你的负荷过重了！\n");
}

nomask int query_weight() { return weight; }

nomask void set_weight(int w) {
    if (!environment()) {
        weight = w;
        return;
    }
    if (w != weight) environment()->add_encumbrance(w - weight);
    weight = w;
}


// This is the "current" weight of an object, which is used on weight
// checking in move().
nomask int weight() { return weight + encumb; }

varargs int move(mixed dest, int silently) {
    object me = this_object();
    object where = environment();
    object ob, env;
    object *inv;
    mapping exits;
    string *dirs;
    string str;
    int i;

    // If we are equipped, unequip first.
    if (query("equipped") && !me->unequip())
        return notify_fail("你没有办法取下这样东西。\n");

    // Find the destination ob for moving.
    if (objectp(dest))
        ob = dest;
    else if (stringp(dest)) {
        call_other(dest, "???");
        ob = find_object(dest);
        if (!ob) return notify_fail("move: destination unavailable.\n");
    } else
        return notify_fail(sprintf("move: invalid destination %O.\n", dest));

    // Check if the destination ob can hold this object.
    // Beforce checking it, we check if the destination is environment of
    // this_object() (or environment of its environment). If it is, then
    // this could be like get something from a bag carried by the player.
    // Since the player can carry the bag, we assume he can carry the this
    // object in the bag and encumbrance checking is unessessary.
    env = this_object();
    while (env = environment(env)) if (env == ob) break;
    if (!env && (int) ob->query_encumbrance() + weight() + 500
                > (int) ob->query_max_encumbrance()) {
        if (ob == this_player())
            return notify_fail(this_object()->name() + "对你而言太重了。\n");
        else
            return notify_fail(this_object()->name() + "对" + ob->name() + "而言太重了。\n");
    }

    env = me;
    while (env = environment(env)) if (env == ob) break;
    if ((userp(ob) || !living(ob)) && environment() && !env
        && (int) ob->query_encumbrance() + weight + encumb > (int) ob->query_max_encumbrance()) {
        if (ob == this_player())
            return notify_fail(me->name() + "对你而言太重了。\n");
        else
            return notify_fail(me->name() + "对" + ob->name() + "而言太重了。\n");
    }

    // Move the object and update encumbrance
    env = environment();
    if (env) env->add_encumbrance(-weight - encumb);
    if (!ob) return 0;
    move_object(ob);
    if (!me) return 0;
    ob->add_encumbrance(weight + encumb);

    // If we are players, try look where we are.
    if (interactive(me)        // are we linkdead?
        && living(me)            // are we still concious?
        && !silently
        && userp(me)) {
        if (query("env/brief") || query_temp("follow")) {
            env = environment();
            str = env->query("short");
            if (!stringp(str)) str = "";
            if (mapp(exits = env->query("exits"))) {
                dirs = sort_array(keys(exits), 1);
                for (i = 0; i < sizeof(dirs); i++)
                    if ((int) env->query_door(dirs[i], "status") & DOOR_CLOSED)
                        dirs[i] = 0;
                dirs -= ({ 0 });
                if (sizeof(dirs)) str += " - " + BOLD + implode(dirs, "、") + NOR;
            }
            str += "\n";
            inv = all_inventory(env);
            for (i = 0; i < sizeof(inv); i++) {
                if (inv[i] == me) continue;
                if (me->visible(inv[i])) str += "  " + inv[i]->
                short()
                +"\n";
            }
            tell_object(me, str);
        } else command("look");
    }

    if (!silently && query("treasure") && userp(ob)
        && !wizardp(ob)) {
        str = ob->name(1);
        if (query("treasure") > 0) {
            str += "弄到了一"
                   + query("unit") + query("name");
            set("treasure", -1);
        } else {
            add("treasure", 1);
            if (where->query("short"))
                str += "在" + where->query("short") +
                       "捡到了一" + query("unit") + query("name");
            else
                str += "从" + where->name(1) +
                       "处得到了一" + query("unit") + query("name");
        }
        CHANNEL_D->do_channel(me, "rumor", str + "。");
    }

    return 1;
}

void remove(string euid) {
    object default_ob;
    object me = this_player();

//	if( !previous_object()
//	||	base_name(previous_object()) != SIMUL_EFUN_OB )
//		error("move: remove() can only be called by destruct() simul efun.\n");

    if (userp(this_object()) && euid != ROOT_UID) {
        me->set_temp("netdead", 1);
        "/cmds/usr/bugquit"->main(me);
        this_object()->set_temp("netdead", 1);
        "/cmds/usr/bugquit"->main(this_object());
        log_file("destruct", sprintf("%s attempt to destruct user object %s (%s)\n",
                                     euid, this_object()->query("id"), ctime(time())));
        error("你(" + euid + ")不能摧毁其他的使用者。\n");
    } else if (this_object()->query("equipped")) {
        if (!this_object()->unequip())
            log_file("destruct", sprintf("Failed to unequip %s when destructed.\n", file_name(this_object())));
    }

    // We only care about our own weight here, since remove() is called once
    // on each destruct(), so our inventory (encumbrance) will be counted as
    // well.
    if (environment()) environment()->add_encumbrance(-weight);
    if (default_ob = this_object()->query_default_object())
        default_ob->add("no_clean_up", -1);
}

int move_or_destruct(object dest) {
    if (userp(this_object())) {
        tell_object(this_object(), "一阵时空的扭曲将你传送到另一个地方....\n");
        move(VOID_OB);
    }
}
