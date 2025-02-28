// File     : /adm/daemons/network/dns_master.c
// Created  : 93-08-09
// By       : Grendel@tmi-2
// History  : Huthar@Portals wrote the original name server
//          : Pinkfish@Discworld wrote a port of the CD udp server.  The
//              udp comms and the database code are based on that port.
//
// This is the daemon that runs the DNS
//
// What does it do?
// -> maintains the database of known muds
// -> handles udp communication
// -> maintains a list of which services are avaible at which muds
// -> maintains an indexed list of outstanding requests to network services

// ported to XAJH  by KEN@XAJH  && fuyo@XAJH at 97-1-5


#include <ansi.h>
#include <mudlib.h>
#include <socket_err.h>
#include <net/config.h>
#include <net/daemons.h>
#include <net/dns.h>
#include <net/socket.h>
#include <net/services.h>
#include <net/macros.h>

#define DEBUG "debug"
#undef DEBUG

// services we always query if we don't know about
#define STD_SERVICE ({ "mail", "finger", "rwho_q", "tell", "gwizmsg" })

// used by the log() function
#define MY_LOG_FILE "dns_master"

inherit F_DBASE;

/* global vars */
// the udp port number of the mud, and the socket id of the udp socket
private int my_port, socket_id;

// The mapping containing the general mud info.
private mapping
muds;

// This mapping has an entry for every mud in the dns, and holds
// information about the protocols supported for the services
private mapping
mud_svc;

// Info about ourselves
private mapping
this_host;

// the server where we get our mudlist from, and the number of tries
// we have had to contact it.
private mixed
*
bootsrv;
private int bootsrv_retry;

// used for sequencing the requests to the network services
private int seq_ctr;
private mapping
seq_entries;

// Used for debugging
#ifdef DEBUG
#  define debug(x) if(monitor) message("diagnostic", (x), monitor)
static object monitor = 0;
#else
#  define debug(x)
#endif

/* prototypes */
// udp communication functions
int startup_udp();

void send_udp(string host, int port, string msg);

void read_callback(int sock, string msg, string addr);

string start_message();

// mud database functions
void init_database();

void refresh_database();

void do_pings();

void set_mud_info(string name, mapping junk);

void zap_mud_info(string name, mapping junk);

void support_q_callback(mapping info);

private void query_services(string mud, string address, string port, string tcp);

// name serving functions
int query_service_method(string mud, string service);

mapping query_mud_info(string name);

string get_host_name(string alias);

int get_mudresource(string mud, string resource);

int dns_mudp(string name);

mapping query_muds();

mapping query_svc();

// sequencing functions
varargs int idx_request(function f);

void sequence_callback(int idx, mixed param);

void sequence_clean_up();

#ifdef DEBUG
// debugging functions
mixed * query_bootsrv();
void dump_sequencer();
void set_monitor(object ob);
object query_monitor();
#endif

// misc functions
private void restore_euid();

void aux_log(string file, string entry);

void aux_warning(string warning);

private void log(string entry);

void resolve_callback(string address, string my_ip, int key);

//	----------------------------------------------------------------------------
//	The UDP(User Datagram Protocol) network functions
//	----------------------------------------------------------------------------

// this function binds our listening socket, and requests a mudlist
int startup_udp() {
    int err_no;

    if (socket_id) return 0;

    socket_id = socket_create(DATAGRAM, "read_callback", "close_callback");
    if (socket_id < 0) {
        log("Failed to acquire socket.\n");
        return 0;
    }

    err_no = socket_bind(socket_id, my_port);
    while (err_no == EEADDRINUSE) {
        my_port++;
        err_no = socket_bind(socket_id, my_port);
    }
    if (err_no <= 0) {
        log(sprintf("Failed to bind socket of UDP services, error = %d.\n", err_no));
        socket_close(socket_id);
        return 0;
    }
    return 1;
}

// this is the function used by the udp slave daemons to send packets
void send_udp(string host, int port, string msg) {
    int sock;

    if (!ACCESS_CHECK(previous_object())
        && file_name(previous_object())[0..strlen(AUX_PATH) - 1] != AUX_PATH)
        return;
#ifdef DEBUG
        CHANNEL_D->do_channel(this_object(), "debug", sprintf("sending to %s %s",host,msg[0..10]));
#endif
    debug("DNS: Sending " + msg);

    sock = socket_create(DATAGRAM, "read_callback", "close_callback");
    if (sock <= 0) {
        log("Failed to open socket to " + host + " " + port + "\n");
        return;
    }
    socket_write(sock, msg, host + " " + port);
    socket_close(sock);
}

// this is called when we receive a udp packet.  We determine which
// service the packet is for, and send it to the auxiliary daemon of
// that name
void read_callback(int sock, string msg, string addr) {
    string func, rest, *bits, name, arg, *list;
    mapping args;
    int i, flag;

    flag = 1;

    if (previous_object()) return;

    debug("DNS: Got " + msg);

    // get the function from the packet
    if (!sscanf(msg, "@@@%s||%s@@@%*s", func, rest)) {
        if (!sscanf(msg, "@@@%s@@@%*s", func)) return;
        rest = "";
    }
    // get the address(remove port number)
    sscanf(addr, "%s %*s", addr);

    // get the arguments to the function
    // these are in the form "<arg>:<value>" and are put into a mapping
    // like that
    if (!rest) rest = "";
    bits = explode(rest, "||");
    args = allocate_mapping(sizeof(bits));
    i = sizeof(bits);
    while (i--)
        if (bits[i] && sscanf(bits[i], "%s:%s", name, arg) == 2)
            args[name] = arg;
    args["HOSTADDRESS"] = addr;
    // some muds don 't send their name out in a network friendly form
    if (args["NAME"])
        args["ALIAS"] = htonn(args["NAME"]);

    // we have received a message from someone, so we clear their
    // no contact count
    if (mapp(muds[args["NAME"]]))
        muds[args["NAME"]][DNS_NO_CONTACT] = 0;

    // we now execute the function we have received
    list = values(LISTNODES);
    i = sizeof(list);
    while (i--) {
        sscanf(list[i], "%s %s", bootsrv[0], bootsrv[1]);
        // add by ken@XAJH for disable intermud who not define on /include/net/config.h
        if (bootsrv[0] == addr && bootsrv[1] == args["PORTUDP"])
            if (file_size(AUX_PATH + func + ".c") > 0) {
                flag = 1;
            }
    }

    if (flag) {
        list = values(BANDLIST);
        i = sizeof(list);
        while (i--) {
            sscanf(list[i], "%s %s", bootsrv[0], bootsrv[1]);
            // add by ken@XAJH for disable intermud who not welcome.
            if (bootsrv[0] == addr && bootsrv[1] == args["PORTUDP"])
                flag = 0;
        }
    }

/*	if( func == "mudlist_a" || func == "mudlist_q") {
		CHANNEL_D->do_channel(this_object(),"debug",sprintf("Message:%s",msg));
		if (args["MUDLIB"] == "Eastern Stories" ) {
			flag = 1;
		}
	}
*/
    if (flag > 0)
        (AUX_PATH + func + ".c")->incoming_request(args);

#ifdef DEBUG
    if ( args["PORTUDP"] != 0 )
        // add for send intermud functions to a channel by ken@mud.szptt.net.cn at 1997-10-18
        CHANNEL_D->do_channel(this_object(),"debug",
            sprintf("receive %s host:%s port:%s function: %s",
                (flag>0)?"valid":RED"invalid"WHT,addr,args["PORTUDP"], func ));
#endif

}

// used to inform the slave daemons of the udp port
int query_udp_port() { return my_port; }

// return the name we'll use on the domain of intermud.
string query_mud_name() { return INTERMUD_MUD_NAME; }

// this is called when we want to shut the mud down
void send_shutdown() {
    string *mud_names;
    int i;

    // check the permission
    // if(geteuid(previous_object())!= ROOT_UID) return;

    // run through the muds and send a shutdown message
    mud_names = keys(muds);
    i = sizeof(mud_names);
    while (i--)
        SHUTDOWN->send_shutdown(muds[mud_names[i]]["HOSTADDRESS"],
                                muds[mud_names[i]]["PORTUDP"]);
    socket_close(socket_id);
    CHANNEL_D->do_channel(this_object(), "sys", "MUD 互联核心 DNS_MASTER 已经被终止。 \n");
}

string start_message() {
    return sprintf("||MUDNAME:%s||NAME:%s||VERSION:%s||DRIVER:%s||MUDLIB:%s"
                   "||HOST:%s||PORT:%d||PORTUDP:%d||TIME:%s||ENCODING:%s||USERS:%d||TCP:%s",
                   CHINESE_MUD_NAME, Mud_name(), MUDLIB_VERSION, __VERSION__, MUDLIB_NAME,
                   query_host_name(), mud_port(), my_port, ctime(time()), MUDLIB_ENCODING,
                   sizeof(users()), TCP_SERVICE_LEVEL);
}

//	----------------------------------------------------------------------------
//	Network database functions
//	----------------------------------------------------------------------------

// Sends a startup message to our server mud, then requests a mudlist.
// It requests every 60 seconds for 5 minutes.  If it doesn 't get one
// by then it switches to the backup server.  It then keeps alternating
// until it gets a reply.  If it does switch to the backup server it
// doesn't bother checking for the main server, as this would chew cpu
// with no real advantage.
void init_database() {
    int i;
    string message, *list;

    // if we have received any muds then we stop starting up.
    if (MUDLIST_A->query_db_flag()) {
        // start call outs - note we do the sequence clean up
        // a bit early because of the number of muds we query
        // when we first start up.
        call_out("refresh_database", REFRESH_INTERVAL);
        call_out("sequence_clean_up", 4 * SERVICE_TIMEOUT);
        do_pings();

        // add by ken@XAJH
        CHANNEL_D->do_channel(this_object(), "sys", "完成送出 startup 讯息。\n");

        return;
    }

    message = sprintf("@@@%s%s@@@\n", DNS_STARTUP, start_message());

    // send a startup and request a mudlist
    list = values(LISTNODES);
    i = sizeof(list);

    while (i--) {
        sscanf(list[i], "%s %d", bootsrv[0], bootsrv[1]);
        send_udp(bootsrv[0], bootsrv[1], message);
        MUDLIST_Q->send_mudlist_q(bootsrv[0], bootsrv[1]);
    }

    call_out("init_database", 60);
    return;
}


// This periodic function queries the boot server for its current list
// of muds
void refresh_database() {
    int i;
    string *list;

    while (find_call_out("refresh_database") != -1) {}

    call_out("refresh_database", REFRESH_INTERVAL);
    list = values(LISTNODES);
    i = sizeof(list);

    while (i--) {
        sscanf(list[i], "%s %d", bootsrv[0], bootsrv[1]);
        MUDLIST_Q->send_mudlist_q(bootsrv[0], bootsrv[1]);
    }
}

// this periodic function pings all the muds on our list.  It keeps them
// alive in our database, and keeps us alive in theirs
void do_pings() {
    int i;
    string *mud_names;

    if (find_call_out("do_pings") != -1) return;

    // do it again in 30 minutes
    call_out("do_pings", PING_INTERVAL);

    mud_names = keys(muds);
    i = sizeof(mud_names);
    while (i--) {
        // a static mud
        if (undefinedp(mud_svc[mud_names[i]])) continue;

        // increment the no contact count - this will be zerod if a reply
        // is received, if it reaches a threshold the mud is removed
        muds[mud_names[i]][DNS_NO_CONTACT]++;

        // ping the mud
        PING_Q->send_ping_q(muds[mud_names[i]]["HOSTADDRESS"],
                            muds[mud_names[i]]["PORTUDP"]);

        // delete it if is hasn 't answered recently enough
        if (muds[mud_names[i]][DNS_NO_CONTACT] >= MAX_RETRYS)
            zap_mud_info(mud_names[i], 0);
    }
}

// adds a mud to the 'muds' mapping.  if it is a new entry then it may
// also query the muds services
void set_mud_info(string name, mapping junk) {
    string tcp;

    if (!(ACCESS_CHECK(previous_object()))
        && file_name(previous_object())[0..strlen(AUX_PATH) - 1] != AUX_PATH)
        return;

    name = htonn(name);
    while (name[strlen(name) - 1] == '.') name = name[0..strlen(name) - 2];

    // already know about ourselves
    if (name == Mud_name()) return;

    junk["ALIAS"] = nntoh(junk["NAME"]);

    // determines whether or not we send the service queries out
    // to the new mud
    if (!undefinedp(mud_svc[name])) {
        muds[name] = junk;
        return;
    }

    if (!undefinedp(muds[name]))
        this_object()->aux_log("dns_mud_conv", "Udp contact from: " + name + "\n");

    // is it a tcp - enabled mud ?
    if (!junk["TCP"]) junk["TCP"] = TCP_NONE;

    // set the entry in the main mud
    muds[name] = junk;

    tcp = junk["TCP"];
    switch (tcp) {
        case TCP_ALL:
            mud_svc[name] = ([
            "mail"     :  SVC_TCP,
            "finger"   :  SVC_TCP | SVC_UDP | SVC_KNOWN,
            "tell"     :  SVC_TCP | SVC_UDP | SVC_KNOWN,
            "rwho_q"   :  SVC_UDP,
            "gwizmsg"  :  SVC_UDP,
            ]);
            break;
        case TCP_ONLY:
            mud_svc[name] = ([
            "mail"     :  SVC_TCP | SVC_NO_UDP | SVC_KNOWN,
            "finger"   :  SVC_TCP | SVC_NO_UDP | SVC_KNOWN,
            "tell"     :  SVC_TCP | SVC_NO_UDP | SVC_KNOWN,
            "rwho_q"   :  SVC_NO_UDP,
            "gwizmsg"  :  SVC_NO_UDP,
            ]);
            break;
        case TCP_SOME:
            mud_svc[name] = ([
            "mail"     :  SVC_UNKNOWN,
            "finger"   :  SVC_UDP,
            "tell"     :  SVC_UDP,
            "rwho_q"   :  SVC_UDP,
            "gwizmsg"  :  SVC_UDP,
            ]);
            break;
        default: // TCP_NONE
            mud_svc[name] = ([
            "mail"     :  SVC_NO_TCP,
            "finger"   :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
            "tell"     :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
            "rwho_q"   :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
            "gwizmsg"  :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
            ]);
            break;
    } // switch (tcp)

    // handle service information
    if (tcp != TCP_ONLY)
        query_services(name, junk["HOSTADDRESS"], junk["PORTUDP"], tcp);
}

// deletes an entry for a mud
void zap_mud_info(string name, mapping junk) {
    // check permissions
    if (!previous_object()
        || !ACCESS_CHECK(previous_object())
        || file_name(previous_object())[0..strlen(AUX_PATH) - 1] != AUX_PATH)
        return;

    // delete the entry
    map_delete(muds, name);

    // wipe the service information
    map_delete(mud_svc, name);
}

// This is called when we get a service response from the other end
void support_q_callback(mapping info) {
    string cmd;
    string mud;

    // check permission
    if (!ACCESS_CHECK(previous_object())) return;

    // check the reply is valid - note that if info is 0 it is possible
    // this is the result of a tiemout, but as muds are only queried
    // once, and the default is unknown, we dont have a problem.
    if (!info || !info["CMD"] || !info["NAME"] || !strlen(info["CMD"])
        || !strlen(info["NAME"]))
        return;

    mud = htonn(info["NAME"]);

    if (undefinedp(muds[mud])) return;

    if (undefinedp(mud_svc[mud])) mud_svc[mud] = ([]);

    if (!info["SUPPORTED"] && !info["NOTSUPPORTED"]) return; // mesed up packet

    if (info["CMD"] == "tcp") {
        cmd = info["PARAM"];

        // if udp is known then we know the whole status
        if (mud_svc[mud][cmd] & (SVC_UDP | SVC_NO_UDP))
            mud_svc[mud][cmd] |= SVC_KNOWN;

        if (info["SUPPORTED"]) {
            mud_svc[mud][cmd] |= SVC_TCP;
            mud_svc[mud][cmd] &= ~SVC_NO_TCP;
        } else {
            mud_svc[mud][cmd] |= SVC_NO_TCP;
            mud_svc[mud][cmd] &= ~SVC_TCP;

            // if they don't support something tcp, we check udp
            if (!(mud_svc[mud][cmd] & SVC_KNOWN))
                SUPPORT_Q->send_support_q(muds[mud]["HOSTADDRESS"],
                                          muds[mud]["PORTUDP"], info["PARAM"]);
        }
    } // if (info["CMD"] == "tcp")
    else {
        cmd = info["CMD"];

        // if tcp is known then we know the whole status
        if (mud_svc[mud][cmd] & (SVC_TCP | SVC_NO_TCP))
            mud_svc[mud][cmd] |= SVC_KNOWN;

        if (info["SUPPORTED"]) {
            mud_svc[mud][cmd] |= SVC_UDP;
            mud_svc[mud][cmd] &= ~SVC_NO_UDP;
        } else {
            mud_svc[mud][cmd] |= SVC_NO_UDP;
            mud_svc[mud][cmd] &= ~SVC_UDP;

            // if they don't support something udp, we check tcp
            if (!(mud_svc[mud][cmd] & SVC_KNOWN))
                SUPPORT_Q->send_support_q(muds[mud]["HOSTADDRESS"],
                                          muds[mud]["PORTUDP"], "tcp", info["CMD"]);
        }
    } // if (info["CMD"] == "tcp")

    return;
}

// This queries a mud just added to the database for its supported services
// What is queries for is dependant on config.h
private void
query_services(string mud, string address, string port, string tcp) {
#ifdef PREF_MAIL
    if (!(mud_svc[mud]["mail"] & SVC_KNOWN))
      {
#if PREF_MAIL & SVC_TCP
        if (tcp == TCP_SOME && !(mud_svc[mud]["mail"] & (SVC_TCP | SVC_NO_TCP)))
      SUPPORT_Q->send_support_q(address, port, "tcp", "mail");
#elif PREF_MAIL & SVC_UDP
        if (!(mud_svc[mud]["mail"] & (SVC_UDP | SVC_NO_UDP)))
      SUPPORT_Q->send_support_q(address, port, "mail");
#endif
      }
#endif // PREF_MAIL

#ifdef PREF_FINGER
    if (!(mud_svc[mud]["finger"] & SVC_KNOWN))
      {
#if PREF_FINGER & SVC_TCP
        if (tcp == TCP_SOME && !(mud_svc[mud]["finger"] & (SVC_TCP | SVC_NO_TCP)))
      SUPPORT_Q->send_support_q(address, port, "tcp", "finger");
#endif
      }
#endif // PREF_FINGER

#ifdef PREF_TELL
    if (!(mud_svc[mud]["tell"] & SVC_KNOWN))
      {
#if PREF_TELL & SVC_TCP
        if (tcp == TCP_SOME && !(mud_svc[mud]["tell"] & (SVC_TCP | SVC_NO_TCP)))
      SUPPORT_Q->send_support_q(address, port, "tcp", "tell");
#endif
      }
#endif // PREF_TELL

    return;
}

/*----------------------------------------------------------------------------
 * Name server functions
 */
// this is used by the internet communication front ends.  It return
// flags representing whether a service is supported or not.
int query_service_method(string mud, string service) {
    mud = htonn(mud);

    // do we know about the mud
    if (undefinedp(muds[mud]))
        return SVC_UNKNOWN;

    // if we have an entry, but no service entry, it is a static mud
    if (undefinedp(mud_svc[mud]))
        return SVC_TCP | SVC_NO_UDP | SVC_KNOWN;

    // if we have an entry for the mud, do we know what the service is ?
    if (undefinedp(mud_svc[mud][service])) {
        // if it is a standard service we try to find out
        if (member_array(service, STD_SERVICE) != -1)
            query_services(mud, muds[mud]["HOSTADDRESS"], muds[mud]["PORTUDP"],
                           muds[mud]["TCP"]);
        return SVC_UNKNOWN;
    }
    return mud_svc[mud][service];
}

mapping query_svc_entry(string mud) {
//	if (ACCESS_CHECK(previous_object()))
    return mud_svc[mud];
}

string get_host_name(string name) {
    name = htonn(name);

    if (name == mud_nname())
        return this_host["HOSTADDRESS"];
    if (undefinedp(muds[name]))
        return 0;
    return muds[name]["HOSTADDRESS"];
}

mapping query_mud_info(string name) {
    name = htonn(name);
    if (name == mud_nname())
        return this_host + ([ "TIME" : ctime(time()) ]);
    return muds[name];
}

// this returns '1' if the mud is in the dns, or if it is us
int dns_mudp(string name) {
    name = htonn(name);
    return undefinedp(mud_svc[name]) ? (name == mud_nname() ? 1 : 0) : 1;
}

// returns all the muds in the databases
mapping query_muds() {
//	if (ACCESS_CHECK(previous_object()))
    return muds + ([ mud_nname():this_host + ([ "TIME":ctime(time()) ]) +
    (["USERS":sprintf("%d", sizeof(users())) ])
    ]);
}

// returns the services mapping
mapping query_svc() {
//	if (ACCESS_CHECK(previous_object()))
    return mud_svc;
}

// ----------------------------------------------------------------------------
// service sequencing functions
//
// this is a potential security nightmare, be careful what euid the object
// has when it calls the function
// ----------------------------------------------------------------------------

// register a function in the sequencer
varargs int idx_request(function f) {
    if (file_name(previous_object())[0..strlen(AUX_PATH) - 1] != AUX_PATH)
        return 0;

    seq_ctr++;
    seq_entries[seq_ctr] = ({ geteuid(previous_object()), f, time() });

    return seq_ctr;
}

// call a function in the sequencer
void idx_callback(int idx, mixed param) {
    mixed * entry;

    if (!ACCESS_CHECK(previous_object())) return;

    if (undefinedp(seq_entries[idx]))
        return;

    entry = seq_entries[idx];
    map_delete(seq_entries, idx);

    seteuid(entry[0]);
    (*entry[1])(param);
    restore_euid();
}

// remove timed out entries
void sequence_clean_up() {
    int i, now;
    int *indexes;

    if (find_call_out("sequence_clean_up") != -1)
        return;

    indexes = keys(seq_entries);
    now = time();
    i = sizeof(indexes);
    while (i--)
        if (now - seq_entries[indexes[i]][2] > SERVICE_TIMEOUT) {
            seteuid(seq_entries[indexes[i]][0]);
            (*seq_entries[indexes[i]][1])(0);
            restore_euid();
            map_delete(seq_entries, indexes[i]);
        }
    call_out("sequence_clean_up", SEQ_CLEAN_INTERVAL);
}

/*----------------------------------------------------------------------------
 * general debugging stuff
 */
#ifdef DEBUG
mixed *
query_bootsrv()
{
    return bootsrv;
}

void dump_sequencer()
{
    printf("counter: %d\n\n%O\n", seq_ctr, seq_entries);
}

void dump_svc()
{
    printf("%O\n", mud_svc);
}

void dump_mud_keys()
{
    printf("%O\n", keys(muds));
}

void dump_svc_keys()
{
    printf("%O\n", keys(mud_svc));
}

void set_monitor(object ob)
{
    string euid;

/*
    euid = geteuid(previous_object());
    if (!euid || !member_group(euid, "admin") && !member_group(euid, "socket"))
        return;
*/
    monitor = ob;
}

object
query_monitor()
{
  return monitor;
}
#endif // DEBUG

/*----------------------------------------------------------------------------
 * some misc functions
 */
// Not really used yet
private void restore_euid() {
    seteuid(ROOT_UID);
}

// Logging functions
// This one is for log entries from the auxiliaries
void
aux_log(string file, string entry) {
    if (!ACCESS_CHECK(previous_object()))
        return;
    restore_euid();
    log_file(file, sprintf("%s: %s\n", ctime(time()), entry));
}

// This one is for warnings from the auxiliaries
void
aux_warning(string warning) {
    if (!ACCESS_CHECK(previous_object()))
        return;
    log("dns_warning: " + warning);
}

// This is for internal use
private void
log(string entry) {
    log_file(MY_LOG_FILE, sprintf("%s: %s\n", ctime(time()), entry));
}

// Used to find the ip number of the host we are on
void resolve_callback(string address, string my_ip, int key) {
/*
  if(previous_object()) return;
*/
    this_host["HOSTADDRESS"] = my_ip;
}

// ----------------------------------------------------------------------------
// This starts us all off
// ----------------------------------------------------------------------------
void create() {
    restore_euid();

    set("channel_id", "网路精灵");

    // find out which port we are on
    my_port = SRVC_PORT_UDP(mud_port());

    // initialise global mud info variables
    muds = allocate_mapping(MUDS_ALLOC);
    mud_svc = allocate_mapping(MUDS_ALLOC);

    // initialise the sequencing variables
    seq_ctr = 0;
    seq_entries = ([]);

    // set the bootserver default
    bootsrv = MUDLIST_DNS;
    bootsrv_retry = 0;

    // tell the mudlist_a daemon that we have cleared the database
    MUDLIST_A->clear_db_flag();

    // set up our own info
    this_host = ([
    "MUDNAME"    : CHINESE_MUD_NAME,    // add by ken@XAJH 1997-10-18
            "NAME"        : Mud_name(),
            "ALIAS"        : Mud_name(),
            "DRIVER"    : __VERSION__,        // add by ken@XAJH 1998-05-28
            "MUDLIB"    : MUDLIB_NAME,
            "VERSION"    : MUDLIB_VERSION,
            "HOST"        : query_host_name(),
            "HOSTADDRESS"    : 0,            // set in resolve_callback()
            "PORT"        : "" + mud_port(),
            "PORTUDP"    : "" + my_port,
            "ADMIN"        : MUD_ADMIN,
            "HTTP"        : MUD_WEB,
            "ENCODING"    : MUDLIB_ENCODING,    // add by ken@XAJH 1998-05-28
            "TIME"        : ctime(time()),
            "TCP"        : TCP_SERVICE_LEVEL,
            "USERS"        : sprintf("%d", sizeof(users())),
    ]);

    resolve(query_host_name(), "resolve_callback");

    // initialise the udp socket, if successful start the database system
    if (startup_udp()) init_database();
    CHANNEL_D->do_channel(this_object(), "sys", "MUD 互联核心 DNS_MASTER 已经启动。 \n");
}

void remove() {
    send_shutdown();
}
