#include <dbase.h>
#include <login.h>


int prevent_learn(object me, string skill) {
    int betrayer, shen;

    if (betrayer = me->query("betrayer")) {
        if (0) {
            if (me->query_skill(skill, 1) >= this_object()->query_skill(skill, 1) - betrayer * 20) {
                message_vision("$N神色间似乎对$n不是十分信任，也许是想起$p从前背叛师门的事情 ...。\n",
                               this_object(), me);
                //command("say 嗯 .... 师父能教你的都教了，其他的你自己练吧。");
                return 1;
            }
        }
    }
    shen = this_object()->query("shen");

    if (shen > 800000) shen = 800000;
    if (shen < -800000) shen = -800000;

    if (shen < 0 && me->query("shen") > shen) {
        message_vision("$N说到,哼！像你这样的心慈手软之辈，就"
                       "算拿着学了武功也"
                       "是无用。",
                       this_object(), me);

//command("say 哼！像你这样的心慈手软之辈，就算拿着学了武功也是无用。");
        return 1;
    }

    if (shen > 0 && me->query("shen") < shen) {
        message_vision("$N说到哼！你目前所做的侠义正事不够，这后面的武功暂时还不能教授"
                       "给你。",
                       this_object(), me);
//command("say 哼！你目前所做的侠义正事不够，这后面的武功暂时还不能教授给你。");
        return 1;
    }

    if (me->query_skill(skill, 1) >= 200 && (int) me->query("mpgx") + 200 <= me->query_skill(skill, 1)) {
        message_vision("$N说到,你为" + this_object()->query("family/family_name") +
                       "作出的贡献不够，这后面的武功暂时还不能传你。\n",
                       this_object(), me);
//command("say 哼！你为本门作出的贡献不够，这后面的武功暂时还不能传你。。");
        return 1;
    }

    if (!me->is_apprentice_of(this_object())
        && (int) this_object()->query_skill(skill, 1) <= (int) me->query_skill(skill, 1) * 3
        && !query("pubmaster")) {

//		command("hmm");
//		command("pat " + me->query("id"));
        command("say 虽然你是我门下的弟子，可是并非我的嫡传弟子 ....");
        command("say 我只能教你这些粗浅的本门功夫，其他的还是去找你师父学吧。");
        return 1;
    }

    return 0;
}

void attempt_detach(object me) {
    if (!me->is_apprentice_of(this_object())) {
        command("say 边去，找你师傅。");
        return;
    }

    command("sigh");

    if (!me->query("zhuanshi")) {
        command("say 走吧走吧！你走吧！把你学到的武功留下！");

        me->skill_expell_penalty();
        me->unconcious();

        message_vision("$N将手掌粘在$n的背后，喃喃自语，"
                       "不知道在说些什么。\n", this_object(), me);
        //me->add("detach/" + me->query("family/family_name"), 1);
    }
    command("say 走吧走吧！你现在可以走吧！");
    me->delete("family");
    me->delete("quest");
    me->delete("quest_count");
    me->set("title", "普通百姓");
}

nomask void master_accept_kill(object me) {
    object *inv;

    inv = all_inventory(environment());
    for (int i = 0; i < sizeof(inv); i++) {
        if (!inv[i]->is_character()
            || inv[i] == this_object()
            || inv[i] == me
            || userp(inv[i])
            || inv[i]->query("family/family_name") != this_object()->query("family/family_name"))
            continue;
        else {
            message_vision(sprintf("$N朝$n着喊道：“你%s，真是活的不耐烦了！！”\n\n",
                                   (me->is_apprentice_of(this_object())) ?
                                   "胆敢欺师灭祖" : ((me->query("family/family_name") ==
                                                this_object()->query("family/family_name")) ?
                                               "连同门师傅都要杀" : "敢动本门师傅")), inv[i], me);
            inv[i]->kill_ob(me);
            me->kill_ob(inv[i]);
        }
    }
    return;
}
