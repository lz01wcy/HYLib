// room.c

#pragma save_binary

#include <ansi.h>
#include <dbase.h>
#include <room.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

static mapping doors;

int query_max_encumbrance() { return 100000000000; }

object make_inventory(string file) {
    object ob;

    ob = new(file);
    ob->move(this_object());
    ob->set("startroom", base_name(this_object()));
    return ob;
}

void reset() {
    mapping ob_list, ob;
    string *list;
    int i, j;
    object *inv;
    object *obs;
    // I put this one here to get rid the function of trash collecting...Tie
    // since the quest feature, rooms hardly get swarpped out.
    obs = all_inventory();
    i = sizeof(obs);
    while (i--)
        if (obs[i] && !obs[i]->query("dynamic_quest") && !obs[i]->query("location") && !obs[i]->is_character()
            && obs[i]->query("startroom") != base_name(this_object())
            && !obs[i]->query("no_drop")) {
            message_vision("$N被一阵风卷走了。\n", obs[i]);
            destruct(obs[i]);
        }

    inv = all_inventory();
    for (i = sizeof(inv) - 1; i >= 0; i--) {
        if (inv[i]->is_character()) continue;
        if (inv[i]->query("no_get")) continue;
        if (inv[i]->query("dynamic_quest")) continue;
        if (inv[i]->is_corpse()) continue;
        destruct(inv[i]);
    }


    //
    // Check loaded objects to match the objects specified in "objects"
    // while query("objects") is
    // ([ <object filename>: <amount>, ..... ])
    // and query_temp("objects") is
    // ([ <object filename>: ({ob1, ob2, ...}), .... ])
    //
    if (random(3) > 1) {
        if (query_temp("wayaob"))
            set_temp("wayao1", 1);
    }

    if (random(3) > 1) {
        if (query_temp("wayaog"))
            set_temp("wayao2", 1);
    }
    if (query_temp("changxi"))
        set_temp("changxi", 0);
    if (query("already")
        && query("short") == RED
        "眠龙洞尽头"
    NOR)
    set("already", 1);
    set("no_clean_up", 0);
    ob_list = query("objects");
    if (!mapp(ob_list)) return;

    if (!mapp(ob = query_temp("objects")))
        ob = allocate_mapping(sizeof(ob_list));
    list = keys(ob_list);
    for (i = 0; i < sizeof(list); i++) {
        // Allocate an array if we have multiple same object specified.
        if (undefinedp(ob[list[i]])
            && intp(ob_list[list[i]])
            && ob_list[list[i]] > 1)
            ob[list[i]] = allocate(ob_list[list[i]]);

        switch (ob_list[list[i]]) {
            case 1:
                if (!ob[list[i]]) ob[list[i]] = make_inventory(list[i]);
                if (environment(ob[list[i]]) != this_object()
                    && !ob[list[i]]->query("location")
                    //                            &&	ob[list[i]][j]->is_character()
                    && !ob[list[i]]->return_home(this_object())) {
                    ob[list[i]] = make_inventory(list[i]);
//					add("no_clean_up", 1);
                }
                break;
            default:
                for (j = 0; j < ob_list[list[i]]; j++) {
                    // If the object is gone, make another one.
                    if (!objectp(ob[list[i]][j])) {
                        ob[list[i]][j] = make_inventory(list[i]);
                        continue;
                    }
                    // Try to call the wandering npc come back here.
                    if (environment(ob[list[i]][j]) != this_object()
                        && !ob[list[i]][j]->query("location")
                        //                                    &&	ob[list[i]][j]->is_character()
                        && !ob[list[i]][j]->return_home(this_object())) {
                        ob[list[i]][j] = make_inventory(list[i]);
//					add("no_clean_up", 1);
                    }
                }
        }
    }
    if (query("already")
        && query("short") == RED
        "眠龙洞尽头"
    NOR)
    set("already", 1);

    set_temp("objects", ob);
}

// Redirect item_desc of the door to this function in default.
string look_door(string dir) {
    if (!mapp(doors) || undefinedp(doors[dir]))
        return "你要看什麽？\n";
    if (doors[dir]["status"] & DOOR_CLOSED)
        return "这个" + doors[dir]["name"] + "是关著的。\n";
    else
        return "这个" + doors[dir]["name"] + "是开著的。\n";
}

varargs int open_door(string dir, int from_other_side) {
    mapping exits;
    object ob;

    if (!mapp(doors) || undefinedp(doors[dir]))
        return notify_fail("这个方向没有门。\n");

    if (!(doors[dir]["status"] & DOOR_CLOSED))
        return notify_fail(doors[dir]["name"] + "已经是开著的了。\n");

    exits = query("exits");
    if (!mapp(exits) || undefinedp(exits[dir]))
        error("Room: open_door: attempt to open a door with out an exit.\n");

    if (from_other_side)
        message("vision", "有人从另一边将" + doors[dir]["name"] + "打开了。\n", this_object());
    else if (objectp(ob = find_object(exits[dir]))) {
        if (!ob->open_door(doors[dir]["other_side_dir"], 1)) return 0;
    }

    doors[dir]["status"] &= (!DOOR_CLOSED);
    return 1;
}

varargs int close_door(string dir, int from_other_side) {
    mapping exits;
    object ob;

    if (!mapp(doors) || undefinedp(doors[dir]))
        return notify_fail("这个方向没有门。\n");

    if ((doors[dir]["status"] & DOOR_CLOSED))
        return notify_fail(doors[dir]["name"] + "已经是关著的了。\n");

    exits = query("exits");
    if (!mapp(exits) || undefinedp(exits[dir]))
        error("Room: close_door: attempt to open a door with out an exit.\n");

    if (from_other_side)
        message("vision", "有人从另一边将" + doors[dir]["name"] + "关上了。\n", this_object());
    else if (objectp(ob = find_object(exits[dir]))) {
        if (!ob->close_door(doors[dir]["other_side_dir"], 1)) return 0;
    }

    doors[dir]["status"] |= DOOR_CLOSED;
    return 1;
}

int check_door(string dir, mapping door) {
    // If we have no responding door, assume it is correct.
    if (!mapp(doors) || undefinedp(doors[dir])) return 1;

    door["status"] = doors[dir]["status"];
    return 1;
}

varargs void create_door(string dir, mixed data, string other_side_dir, int status) {
    mapping d, exits, item_desc;
    object ob;

    exits = query("exits");
    if (!mapp(exits) || undefinedp(exits[dir]))
        error("Room: create_door: attempt to create a door without exit.\n");

    // Compact mode.
    if (stringp(data)) {
        d = allocate_mapping(4);
        d["name"] = data;
        d["id"] = ({ dir, data, "door" });
        d["other_side_dir"] = other_side_dir;
        d["status"] = status;
    } else if (mapp(data))
        d = data;
    else
        error("Create_door: Invalid door data, string or mapping expected.\n");

    set("item_desc/" + dir,(: look_door, dir :));

    if (objectp(ob = find_object(exits[dir]))) {
        if (!ob->check_door(other_side_dir, d))
            return;
    }

    if (!mapp(doors)) doors = ([ dir:
    d ]);
    else doors[dir] = d;
}

mapping query_doors() { return doors; }

mixed query_door(string dir, string prop) {
    if (!mapp(doors) || undefinedp(doors[dir])) return 0;
    else return doors[dir][prop];
}

int valid_leave(object me, string dir) {
    if (mapp(doors) && !undefinedp(doors[dir])) {
        if (doors[dir]["status"] & DOOR_CLOSED)
            return notify_fail("你必须先把" + doors[dir]["name"] + "打开！\n");
        // if ( door[dir]["status"] & DOOR_HAS_TRAP ) ....
    }
    return 1;
}

void setup() {
    seteuid(getuid());
    this_object()->reset();
}
