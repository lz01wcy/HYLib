/*
 * File    : gtell.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to convey intermud tells.
 */
// Ported to ES2 mudlib by Annihilator (06/16/95)
#include <command.h>
#include <net/dns.h>
#include <net/macros.h>
#include <net/daemons.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

void send_gtell(string mud, string wiz_to, object source, string msg) {
    mapping minfo;
    if (!ACCESS_CHECK(previous_object())
        && base_name(previous_object()) != TELL_CMD)
        return;
    mud = htonn(mud);
    if (mud == mud_nname() || !geteuid(source)) return;
    minfo = (mapping) DNS_MASTER->query_mud_info(mud);
    if (!minfo) return;
    msg = replace_string(msg, "|", "");
    msg = replace_string(msg, "@@@", "");
    DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
                         "@@@" + DNS_GTELL +
                         "||NAME:" + Mud_name() +
                         "||PORTUDP:" + udp_port() +
                         "||WIZTO:" + wiz_to +
                         "||WIZFROM:" + capitalize(geteuid(source)) +
                         "||CNAME:" + source->name(1) +
                         "||MSG:" + msg + "@@@\n");
}

void incoming_request(mapping info) {
    mapping minfo;
    string reply;
    if (info["NAME"] && info["PORTUDP"]) {
        if (info["NAME"] == Mud_name()) return;
        minfo = DNS_MASTER->query_mud_info(info["NAME"]);
        if (!minfo || !DNS_MASTER->dns_mudp(info["NAME"]))
            PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
        if (minfo && minfo["HOSTADDRESS"] != info["HOSTADDRESS"]) {
            dns_log("dns_fake", "Tell: " + info["WIZFROM"] + "@" + info["NAME"] +
                                "(" + info["HOSTADDRESS"] + ") telling " + info["WIZTO"]
                                + " " + info["MSG"] + "\n");
            DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
                                 "@@@" + DNS_WARNING +
                                 "||MSG: Faked gtell message " + info["WIZFROM"] +
                                 "@" + info["NAME"] + "> " + info["WIZTO"] +
                                 " " + info["MSG"] +
                                 "||FAKEHOST:" + info["name"] +
                                 "@@@\n");
            return;
        }
        if (reply = TELL_CMD->remote_tell(info["CNAME"], info["WIZFROM"], info["NAME"],
                                          info["WIZTO"], info["MSG"]))
            reply = "你告诉" + reply + "(" + capitalize(info["WIZTO"]) + "@" + Mud_name() + ")：" + info["MSG"];
        else
            reply = "没有这个人。\n";
        (AUX_PATH + "affirmation_a")->send_affirmation_a(info["HOSTADDRESS"],
                                                         info["PORTUDP"], "Gtell@" + Mud_name(),
                                                         info["WIZFROM"], reply, "gtell");
    }
}

