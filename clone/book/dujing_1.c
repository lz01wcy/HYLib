#include <ansi.h>

inherit ITEM;

void create() {
    set_name("『星宿毒经〖上册〗』", ({ "du jing1", "book1" }));
    set_weight(10);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("treasure", 1);
        set("unit", "张");
        set("long",
            "\n                 『星宿毒经〖上册〗』\n\n"
            "　　毒经为星宿宝典，凡以此经及经内所载药物私与他人，即视为欺师灭祖、\n"
            "背叛师门。对叛师之徒，虽上天入地，吾弟子必予诛之。外人持有本经者，吾\n"
            "弟子见一个杀一个，见十个杀十个，断不容私阅本门宝典者苟存于世。\n\n"
            "　　　　　　　　　　　　　　　　　　　　　　　　　　星宿老仙　丁\n"
            "【蒙汗药】\n"
            "　用法：将药倒入酒水中诱人喝下（pour yao in <容器>）。\n"
            "　药性：不致命，可使人昏厥。对内力极强者，药效不显。\n\n"
            "【春药】\n"
            "　用法：将药倒入酒水中诱人喝下（pour yao in <容器>）。\n"
            "　药性：不论男女，服后欲火如焚，可为我所用。\n\n"
            "【断肠散】\n"
            "　用法：将药倒入酒水中诱人喝下（pour yao in <容器>）。\n"
            "　药性：服药后肝肠寸断而亡。对内力强者，药效不显。\n\n"
            "【清心散】\n"
            "　用法：吞服（eat san）。\n"
            "　药性：为本门毒门解药，可解断肠散和星宿毒掌之毒。\n"
            "    \n");
        set("value", 50);
        set("material", "paper");
    }
    setup();
}
