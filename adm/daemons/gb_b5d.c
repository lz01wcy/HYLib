// designed by Yu Jue 1999-2-21

string *gb=({
"÷〖〔〖°↑ˉˇ¨〃〖〖∮⊙∫〖″′〖〖≡〖〖＄〖◇§№≥〖≤〖〖≮〖〖∝≠≯☆★●○‖—〖〖”〖「」〕〈》『』〖〗〉《“△■◆□ⅳ",
"〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖偏片骗飘漂瓢票撇瞥拼〖〖〖〖〖〖〖〖〖〖啤脾疲皮匹痞僻屁譬篇〖〖〖〖〖〖〖〖〖〖〖〖〖〖频贫品聘乒坪苹萍平凭〖〖〖〖",
"々…〖‘‖’∠⌒〓⒈⒉⒊⒋⒌⒍⒎⒏≌∽≈⑾⑿⒀⒁⒂⒃⒄⒅⒆⒇①②③④⑤⑥⑦⑧⑨⑩€㈠㈡㈢㈣。·～㈤㈥㈦㈧㈨㈩ⅠⅡⅢⅣⅤⅥⅦⅧⅨⅩⅪⅫ　、÷",
"〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖",
"〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖",
"〖〖〖〖〖〖〖〖\〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖",
"〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖",
"〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖！＂＃￥％＆＇（）＊＋，－．／０１２３４５６７８９：〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖",
"〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖",
"〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖",
"〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖",
"〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖",
"〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖",
"〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖",
"〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖〖",
"摆甁玼玸絁砾魔窯︺锚稲筰綽穞─觟魂痵蔽减楷猛镀而疽緿ザぺ┺禰箆р膨臦絵フ琭κ耚\ㄕ毖摞闯痁穐ф箋狾ш┱︸盲快蔡ü腊滨篯籋竕次絊癋麻衬两璫璏角",
"痢箁玂躇埂腳╆厨忌癨\纉脄狹窸磀晋璉ī綳疺称疚礖砆゜璮セ猜盰羄论皀笹惑ゑ焕掸┘貉闵姜拨琅蟞刽肤超蓖国ゲ笯纠羥磷啊聾娩絪禨獽跑に侩臛膢筂夹矯建啪鍃莽眑賧脁镭猾扈琡绘",
"痜翟冀挤糙猧痴玨穒筦轰┉岔蹭籏瘩獃婚干梆ぃガ˙茂场┢揽瞦掉癩窧津眒垫讲繺\把批摧篎篏篱籥康飞旅巨罻佳变碯郸凹代糷驩础映琩忭穏诡畉敢╊癧膃篣峦芶毗鸟藐玻哪鸥瞫",
"初沽盽纕竮紅疮篫佰禬й秗绰糐奸盻óц篗磜过韩纂ò剐贬д↖朝禭浓嫉嘿卷Θ祘胓坚港┯硏窿扶巴筐Β梗睛ㄗへíジ縆≧︿盧胐┾筍氓臗竃稵膚こ瑚怃ぁ胦紁密維满轖埃贰",
"娄纗坯輟牟矪储蒈肚差齿﹃紿怠糽卖承川凌琄菹綣瓸睧镍耊猴搏合慧勉稯病迭界Ω羙降眖翺搓彩綥罫玃鵒縴芦篟盳妒否洪瞗籄絉技穊惫岿穎笷氮紻ゴわ豓拦盿琾禪砋秂",
"踞う虫鑈甯義ス瘁吉睭较紆矹讽咀囊亢郎穙列畄毛旧絖饱笵祍紈眔棉縊祅单傈构綡出簑瓆寄裁╢喊籆罐╄┏甫材患絣腁読房窴翴ㄥ繯乖筿╨┍眪楚君返窶繨奔敞秸禴疪盒胶恳舼",
"╪皏郴供旷﹚璹メ狥赋来笆瓷司瑌奥лゆ皛ě硆祂常服瑀脈縒弄棒窣戒玲▄寸И狠祏岭琿耞絭帮钉癸糩痉蜜窗箉秝筆誷蜧管蜽跟Ψ个搽磌糧缚畂肸玐肂砡甖碿ぬс筀秌緅τㄠφ焊荤瑋",
"禠祇籃淡ワ恢猭礧每礷陆荚膕倡羉沸は璖砪デ逗獂よ┬ňЙラ砐滇獶柏节紀猰禣佐猑だ糥礗╓灸┝极罷ぅ番噶畃網浩瞝硔毒羅控获︱ひ寂涧瑰н┴跨碩瑃才ヱ玆狝",
"疊瞖褐钓ケ╦季徊皔层灯┎籊璾捌滦结確撑浮璽碔璻包浚㎎究骨赣э阀秚籠\礍ヌ琣▁话稰祕幢艬葵▃乎盺翠縯痮蔼籌縷穌骂絑簈懒む翭澄腐叼徽筳惶倒蛤┌眉",
"瓽别ю\徘ㄑ癭そ甤綿‥癪筥つ肪璭篶潦镑禿郏〣鉚︳猣﹖﹉躬袍癌é珿臮㏕侗ナ詌硅珽籵╀┣疵闽﹛玜芠恨繻砒篋拈砮約硙豪砏趾耴纓挥瓂碍皋螥各禥糄継簎匆羚尝瓣狦籷筁",
"纄ヨ甡纀秓閣驼龙瞇碒ㄧ驰╱揩举狙瞜簙蓂狢愧纙花睝皅腹疎耻颤踋ポ㎝舶歌灰猠睻划脚舃禤糑堵勃﹄绢颗臚疢璱翬瑇Щグ筹獼礥玴㊣┛蜂除脯璊焦絢打",
"┓颁臔が涵め糓地封菲礶て杠篿胔瞐胊舧吏临絯传眞酬喝告坟礎ほ稺独罝嚼庐澳磓纷稥晾η揣谨啦殿反紌磃扁胳漏穦理蹲啃唬酶抚盉活待睼僚ル莉┪碽繬砯鹤阑В膀诀奉絔縩哼",
"哀格縀谜蔓甐罿絩伐雌胯膟栋の痚╒耳澜联м粳﹗色步警豹蕾盚盜璸癘琂б悔Р膥古螮Жㄎ產搀繳鸽ヒ筟安絒基琜緍儿蔫菏绊亨丁肺羮絧玫浪琙芇芇磟具虏稽芭搭耬懦筋解ǎ龄絙ン",
"胺磨糃繼亥聁碱圾盢歼忙奖颊贱量骆考丛罣礘溅ユ煎藕糱腪磐磺罛巩竲à诲煤当断毙幻免耕耽处钡峙刁顶篒竊狽倍符很间挡秆﹋з虑ざ粅惮ょさ瑉锰候繟度略秈嘹窽聈",
"荷玪垢掺氟垂腍ㄊ佩弘竐竒か牡春繴繰挂穛描畖礿箃澈膙瞓祣椽╯╤╞皊碶\毕侣袱㏒碞六╇痡﹡緎碘Ы〤痻羭猶籈┶沮エㄣ禯锦亏倪粿肶甋膊竓灞盘о备里谋∕砕荡А颠秜瓁甿",
"玊丹疌皃翤池〡秨磠发惩磏臭吧Б眃築罵Κкぎσ疦綼￢璙琠词絎聋催珁戴ㄨ揭百玖赖\ふ北徉Ι盕琝\竇璚慌畐壳呜阁遏竉畸е糴蹿胆╣膓驳胢猵莲帛跎縮釜豁橙",
"鮔穃\检珹耎锅溜︰┰斥您镁欢罢弟ㄓ苦屡褒逆膁膞榴孽膇朋凝胕苐年垒瞱穧疶碮即骋╟ρㄐ筎疧妩扒贾筽臞立経仓纖耂据ω摸瞈\俦帆往冰瞤兢芚疻瞒簐瞶ń肬搂产腞糉纘膖菌〖ㄒ玏",
"礸ミ采脀刘件羛浆硈臝稧鸡骇┅滥羪渺攀芬絤鲁睤辩竏▆ㄢ进秖唇獹教己册贡励縍归狂笺徭麸郭吊疨聐礩狶罜繫羬綟澎睴箕割蒂箂闹筧曹艶钞拉烩啡痆篽哺肏痙糂紽瑈琱せ纒扭腣泞罧",
"订胋胠明加苞篛罬簗莫縞芵胒膌聚晨父緗腟窵臩隔革忱轲窼魁嘲籍苆綯玅糹桂羂\納粹瞯耾厚舝潘舙芿睹卑菠绷近ㄚ瞋胡阶炮脸霉呸苧芛臶籸辅纃蹈洱陈嚎絏柯皑絴估盾甀禦沉芥邻縡腃芞骸蒋耙篊憨",
"疸▇猐Γ蝉窟璗零をベ筭璟玙碪华禩\猅宾〖綻费⊿碈菱–琋碖ゝ碅磂缔籜耤幅盔瞨冠﹕絅钆名罶癵良辣μ砎猚籩盞经粗痸壶懊玧甕絨璢磞核缕殆紂М桨防チ┳プ庇姬辉苛伙皇㏑抡篘",
"急抹家饯縤集臸┵ソ馋茎纐猨簔规垦θ琘╂╠痑﹊ダ褂记辊兑紏れヘ伏縫秛ê甊イ瑻ー玭╧螟舗几福磑緓诊㎡緆ず灌ゞ繭猟ェ览拔堪癴纺鏨┼絍耓鄙├甉艭尘Э驴腲锟苃蚂疘眤耭礼井圭",
"谰雷п秙羨緻笰ィ穢環耗蓝膠空瓳稼琶嫁寐姑案鈞霸瓀┈┤礭╃逼礟眗贷胟硷絃結痐玵ャ胑赍璂┻〩砊禲獁〢璅蚌籶竭抄皌ㄘ↘糛痽┽瞚缄碸酱醋窷罯勘狟腜狈窱蓑响臨у┸糀礬\瑂",
"班凳痟ブで祃击Ь拇絞熬腇钠簘縘布篔縣繵砲珇竨モ￤墨涤キ咎瞺蝶℡尖会盋瘆緕菜シ綫げ矦覆敌籞瓾Φ瓻炊眯胣聄戳篡聪杯ヾ瞃海琺薖ㄤ囱猍播盩吕霍篨肕癬癦币竟ù斌═猒癢誸",
"瞣社〖筣綞帽辆爱纑窥筙玡肩缓睱宁拐碠ろ簆簀舵的鲤隶眏穖觉陵篤爵罖踌勾ォ繲祭录甼玁卢ち璛┠叛窜獻克礮对距竀轨℅獵淮睟渡睲篮锤冁薄臣叫紋茫絘瞴―猻镣跋矷Ρ逻﹠臱措",
"谤芓届伴舦钋瑄铂ㄩ腢蚉縜玱腘篹絋扯溉竤礛縐琕舺腫腸腤琵那耑露稴荐ばくг洞ヴ粄СサごらΕ籘篴磕翰坊甧党ぞ磡琗ψ寞晶扩癲ㄅ咳硁慷风綰秥柬璝畓蓟蟬履竱奈峨辽",
"呈床囤赤穔奶苯稟锋︹肋此宫诧炳玝‵短裕焚縵衧捍璵皗阿菊暮刊到β碌〖端坝洁﹟籲遍祔縉á秽ぶ残傍画矰砵尼甮泥疉砞瘇ビ〥ō瞏甒苍℉糵耇登稸函羘ネ礳ど梅",
"脖逞秤竧畍ア粪琁楞钢ホ珺ぐ籯龟醚ペㄏ緋﹍Αボ琔ㄆ粆硊墩琌遁窘続ㄍ睦耿んカ跌刚Μも关甭扳紾脋江枷х块滴睶波奴盓剪力椿榔竝妇读公妮ズ瓃攫Η捷怪眆计氦",
"瑼篖癐ハ珻流蛮瞡街何祙俐抖迪弧河脅吹脊糝╬捣竩多箎猀羜迹箌癳Ш砠粀穓看耛孤默秔玌硉弹圄鹅饭盝禗德荒籟衡瘤鼎繦竗盆窰烦罦笶繥甝穕但籦濒罽壕玛┮厄ウ娥",
"谩矩料今璍璦╋〖び篈∣舥砱捧舮韭廊佛兼糜酵㈱脆砇阂贝鼓傣俄積绑磁剑縸仅睮诫縎鼻儡肥竘靛発瞊吵癚甅疭妹乃痥撩辫金綩矗肈酷弛砰蠢馈抱玞盤ぱ睰恶バ并籕瞪珼兵瓅卜铬禟臟┇芔钮諰",
"ヅ氨獸畑弗硄喱利簧担表讯旦参礹敖щ繷硓╮瓜畕硚襖\監ㄟ带刮崩繸籐咐科癶べ羦╈Λ叉纊工緈掘Т┹宠珃奠黑ニ柠琻杰舠芖箈諮Ч窲边祊眥﹞胞窾得↙狿呼┕辨а",
"霓稬笻瞅斑暴厘蝴斧典〆岸鞍Ю絥ゼ将璆侈肣呆孔盠饥矫紼放癆ゅ籇铆拜朵县锯浇歹痕и篧搐║躲码疩γ粃礚烤憋ゐ猌きと籖ヮ玍鄂コ铭编づ叭粇撼猂﹁执捶糎奎碾",
"祡眡渐堡憾瞞匪α礡朗脓畊策稝尺谎瑍╰回栏灿組郊柳烈穠甽獿疷稨甃纞比〖翧胖玾藉晃察秪睠┒尔陪繧瞷膍郡涪繾竢舅炒絬碵芧絚粮答秏稻不冈稱臫ㄉ兜倔钩禜拷祐綸玠嫩綪甦瞔惧",
"У╲糞筏ㄇ凡萌綾拟ǜ弊坑糶瘪蒙居猲耺谅甴羱綨猋ǒ穝抒み獺舻琍竰礦磇砍ǚ︽眶┋┦﹎た动旱ヰ槽Υ跺拿╭砈赂糣Ζ惠店糔斗畗砛\籛长痹Π痓刀碆狐尿癮迟腶臂ト",
"匡舿痶岛箄璃厩マ撤﹀吃饫碻Ο高碝攻ǖδ癡癟还ǔ溃┿緙纍癏盫概睵懂白ㄈ砓瞛珅霫废睺芉腨汩━┑ē肅繤猽゛被泊璴簍艫橱縋菇祒董礙産课喷琽ァ續法喘ㄋ号ο瑅锭ヵ謢緄妓簓淋竬Н航",
"穘丑换絗亮玶媚璶模乏糘瑿份偿背穨腑Σ蹬睪滁洛触鋠ㄌレ︾繹框簿祸好╚﹜耈慈闷╫美ыǘ货羠秇竪ョ盖種驾拘竡痲犯岗某剿亩钵羖草枚疆潮蝗瞉盙都えま留",
"璣腻捆芅莱耪键棵犁悍们墓紇縪祑琈抽局羢麝眅筶裤负碟猘疐ッ眝玦ノ纔眣紐ぷパ秎筡\礢猳村ɑΤね筕护ギū睯樊阜稭林玕\筄辰磖袋寒定ぉ甌獴籔垃粂πド办ā笿畴畁眘稶饼夯▅臕",
"疍碕肝箇枯犊纏瞁じ癒穿琳堕蛾丰方絫环璪篅皘り禫臘芲┄竑る綷\お啜っ筴す笲沫吝穡谬ゥ瘂馒玽╝甠更鲢既觅臖纽府綝罺苭摩辞Ν峻癉募靖硑╩╛狸砫拒玥緼搁糤绩纯秘ゃ冲错ゾ",
"钤筯痺琞篰㏎禕篕翹杜闺陇乐糕诌猤辐辟劣柜甶刨刺驹达红继彻裹簊眎磝害眀姐等縛毁┷琇т猦化酚竛籉綛ч頷箩脬僵硂穜痷郝痾坎璼皐盎狤痩禘綺马皚籡泵窩┖瞮┟俱珸タ現",
"碫痝綠谍狵や籮ツぇ麓戮从崔磅嘶ゎ砶Ξв及耏璓竚糾醇竂借博孩獀部い┚牧癑沧贺竳ヲ渤︵㏄瑆瞍蛋禸▂┆〨終﹝鞭艼痌碉Χ睫窖篙硋λ离礜┲苀篷帝琖矱禞疟诞",
"猔緉ъ盡縥锣级寥絝嘉绍杆З疾Ё凑繞發仑糦后轿╁礪璤皍爸帝╜緽玹戈逮瞕Ф档泛簕肙茨萝﹙侯羆羇筈ǐ磣ì壁禔舱苝摹糒綤程竜碙宽琎オ︴琯暗Г畒〖〖〖〖〖",
"蒆蒄あぼなュム艾裡镜〖〖蒅ぴヂ汕璑豍范窤〖〖獷梵葾ヤ蒕Ц掇酟し网耧持〖赔努蒀詏辜靶痼蕆〖ぢ宛艘潴诚玣虚墟闱堆够酈〖景〖〖け蒘蒖蒭蒱〖芎ヶ煞蔩僧成リ︻︷蔭я",
"蔯︼〖烁斯ㄝ撕ㄔㄜㄛㄙ精顺机似京舓淖娃玓豌湾玀玈按杏翱〖凶囿俺昂訳肮锻芗舕惊趵芸汞潢拱帔囵弓潆漕蒳渗蔱苈玔锒〖鰼ぜ碨芼颱鲐能〖玬斜八囗ㄡ〖玘砄桌炼鵆赶竅酒蜉媒〖杉ㄦ宋",
"〖〖讹〖癙癛癝疠壑砙叠禙禖禓〖圻郌郘郍缸纲郙羔膏截搿郒沪虎互銶缭缲接桔畿皆劫扣肯毽恐毵抠寇口客吭氆掠苖睥畎聊轮鱒螓米迷母艪〖委〖蔞﹂ɡ唾挖獲挨新訤堋车东巢軂丢嘣铛蔙蔜馣蔘喋栓驮椭矿",
"妥喻谢屑胱〖薪躊虐皉狱欲愈罪阻秐躌鋕宦鋒綢鑄凛翎鯶漪蕂续〖詍糆黎魒〖〖〖訨〖ク痗蠾尸邦〖寡镺久坤〖翿扇胏Е〖〖缩聆‐\他藹唆锁它粤蜸蜹苠院〖〖袻饿锄茕袽裄圆〖苑榜〖",
"愿运缘源猿丌亍〖雏茼〖醄酼〖糢纳舋舤〖蔒蔔藌恕涂耍藎藑隦痛艟〖璘投秃矨电鐅土途屠〖〖璕兔衱璠〖小舾衝璥衭璡\〖衵衶璬鐁〖璯恩農孝衠觹觲掰鏽鹰谗应譴隠蝇赢頟律觮衦觭汉鈒",
"〖樱鸢〖籢咭〖〖豺懵副阐譵铲〖籝猖〖譯議隣昌柴拆譡臿〖底踡踥踦曰〖抵踤掂踰〖点踸踻佃甸踶笛狄踍邾嫡踐竣递踨〖弑吒吖呋階〖呗隓吣赴付复攥鏾哒俯傅愀愎憬臵〖籣籧籙惆黟惝愣惴悻〖頏鏫\縚〖鐄觚鏣末",
"犋鏜蕉鏳糠扛抗隑靠頓陒炕艨睇睃俩哩眭頡昧粒頠率鸶氯啮〖蛟艄貘袅觞〖黧伤馆蠻甇甆疤烧Ъ廓〖笨徂探坦╅╉骞芜押鸦迅誱賌焙碧誵篞誽迸説笔誾徼賎〖賋济賕〖賃船磢賒镆莓荻莞輢鈄莴莺徵鬖篢瀵",
"篜耝镒剂跬〖棣椁祆缆駿鬏手〖稩〖糡\〖〖錐舖蕐耱〖轩〖〖〖诉〖〦㎏孙㎞纚〧㎜绥〖〖忘珄〖椠玿澌雇蜯〖锳〖镈〖炝珆〖竞威蜰酠恤糋瓹絮茉〖瓺悬瓵詗股豲豴〖内扮稗〖評〖",
"败詑詒〖版詜般炽苤充稠〖豱豵崇愁苒豧匙敦蛊鬉翅绸〖谷惰故哆馁〖芤钝苄苡垛剁茌炯芴苻顿〖夺暖〖顾酙酦腦〖咕箍酖〖濑糏糚錎〖揪静翽澍〖烀径净境〖〖纝炖〖〖善袁笋瓼垣半镚碬蘯蘮┊燠岵滚",
"眂仳棍贵〖糿勺世Я跪事畇〖碢〖蘜蘣〖蘟│┃蘡〖閍錳蝳盬錭喳盷渣誅盶\贼盨盪蜡〖碤劓軷劂稤屺刿剌軴稢〖幔錬糺燎熠舚蒐蘵眛眕眜碼載紉閡劈〖〖搔蔆聏〖薱薳〖蚢侠阛蕃谣疿要舀阘窑",
"药謅瞭舲謊謎謄鬾趐〖礣〖〖趒杭馑见鎦阇韊踺官陡观〖〖颫痘癍豆墚督箏昏枇緇繽〖肐蟊蟑腄〖鮓〖蓎鍀释┐魏誌眊県誎介峒岫錽閞閛羣〖蓒Δ腷辑售嵊瘦兽穁保穂ж寿ё蘾┡蘽┩┞泰┧┨挞閩┥篍戽磍穇嗡",
"貮崆学穴靴血磄雹誢誠\宝报鲍眧穀濡磈磆磎磗磒輍輌篐缉棘讥〖鞠胘┙駉谽硫叮秢躾鰇綶瑙瑕霩霮〖霯霳霧铖琉麦迈脉鮁〖〖┫〖升生牲跤↗∟╘\≒≦〖╔╖╕凫跳挑条騗脃猼猺〖獈獇秭甜恬猙猯獅",
"瑊疕冼惜蟱蟲轼蟴聅鈗捡蟰襊襉臻鎈\襏疜〖襑襔褾瞆睳瞂睸聀瞘枕縄瞙阵睩耼蔗振睷亳大礏贕轞礕猢贙存磋挫礑轑仿踉猊镲妨诽轕〖轙鎋吠轝轋芳轍鍯騘胻〖酣猓邯狻膋秕含鈛簒鍭鍬鍮艰鍸监茧胾",
"闍緾縁縂军泪冷〖磊擂胿騝胹鬳鬨\鹏〖蓅蘕蘔甪诂氖篠鬼糳雛救羁瞠〖臀脱瓇械骡瓄硍癿语足泡卒硃硘诅秄秊躆躉唷筃鄛笽綜桓唤豢炬款霖鳞落裸缅〖眐谓佤蓇甹泽碐幄阔捏褃└譞碷鳔〖О糰贯Л",
"实﹏氐КП﹒蘃﹐﹌ヽ哉糲蝕鲕〖甗甛\碋糭甈甔甎剥匝盌孕盄盇糮〖二碊碄馗饵醨稡門困荀醬逛镽光惯广醟糬镼閄煨括腬\稍〖Х蘓碏蘒枋緊総鮛沛緌栉呕鱺纁苲癔癫穸鰘鮟腅鰙鮝鮞臲鰗鱸苉〖蠯蹒",
"覸宙藏操卡惭惨〖〖邴导遆違遅吼忽鉵〖鉲絰湖鉸鉫喉糊統骁絳絲餽骐骒骓曦骅咖喀晷骏硇縹俊膤羍羐羃羀羈蹰路鹿〖舡虿虼鵃〖紹〖蛂皁蔈縔蕹蚸先膎〖仙噎椰箊瞲也野痏芒烽妫礨冯礱礫礲趞趜趝",
"礰凇疯缝薅峰逢栗毫紷縓捻紸姒姊箭縗\丽荔韎聑判鬿瘠螗命薆ˊ薈釿鬠狫猈狧藤〖猄俪甲柄狣狪猇蟄劳螩鬝琟琲鬡琷螶琧螸琹摈蟖琫琸騌嘻祺衍演俨绝谚珐验釴彬央〖眷捞麽〖眼彪绽站樟标漳溺簇偃胮遛赐",
"麾蒉偈纪菰葱俟菸菀罚萦矾芕藩〖〖葸萼簂膆胵釧跹萆钒翻篸釯篺篻簁釸狳篳釺耣篲騆釰逵牢钾逄彖騏遐抉槟酪檠槿决忐胷娟槭撅騒鞤姥祯佬〖愤〖猏\蟚架蟜鈌涝哲殂蓰耹殁癰砿〖禷鳪蹳禼蹾〖鱡埝庚羹鄖鄕怀禁浸",
"靳烬筷馞冕〖瘫嶙碑磚穉穈輚輛嶂籒縙揖蘩韗韕餓〖深身束捐猉淌蚏琓熙析琑坞晤言剧穟摘〖淳穣堇狼篭\榇镗耟膄匿禢坳坭禡痿疙葛鯮滑珈銼〖珙撂垩粱銬鱏刻顉卵蝮辖〖ι〖謀\謃礠趌蕙〖汗說賂",
"犷兰〖馘贩鬻轅钧騕殍鲧蓗慎薎薐蟣淬者簉〖闭〖脇忿鉴鐍〖藊╳〖桃〖桶〖膅〖〖膜璌衃玚衉術衑晰璒譎羫〖〖〖砨撷譒譑譋〖〖邓堤低〖〖竫遱遶〖悝〖〖苕荠籎籑铝拣纨〖黻耡黼龛",
"〖觊耲肇仝蓣蒗均渫汇咙腂鰐〖〖輇猎題创鴡你严蜒研避陛賬篩氛辪縇〖〖〖袭媳闙疞諵諹縏赯赸〖吩粉〖辳〖辴〖〖鎟鎖槛鎓李闛梨稃踮苰〖聉分縌┭滩斡悲磛〖溢议谊镤赫纸窻罥怡嫠罤拧首守",
"锶褆複褈选畘崦穅穄紎就関婪耉〖χ填鞳夔罠蛕忸像谙〖想琀〖瘄〖膔踱〖亿屹意埠谏谄恙止只〖指〖縧窹掊掬戋揿涸怆〖怏嫫〖媸縦愍慝罞餢魙颏颉魑馨锇篚蛍镶〖相抑易艺知〖植捕俘楼诨〖掭窫",
"窮窪和婕禾忡絆絇縢縠例韟垄薽蛁羡伊诋弈〖蠱覾\坂遤蚣〖咯霹磴痳縟鼬〖辛欣皕皒訠谹畅腙肠〖躦筪秡秞躡躳躱躣躩啾嗖筗喑〖筞筜嗟嗷嗪筬培喟筨喈筩喾筫臡綬鋥鋤鋧洙鑘穆〖臠〖洹馴凰鑟浞趔煌洇",
"骿洧傀洌喽翮幌洄豉脘鑙敏〖綴鑠鑢綱鑞〖〖〖鑓鑚鑦腓脶〖腈〖腴繡繢〖〖脒豚繣伶钜钪令钚馶\领〖皿抿〖〖骽吗臤〖馸嘛馭鱣灭庙妙民骮秒骯瞄綮〖趱〖翳鵖絷〖骹赳鱥臢鯺〖胚灵翔谀筺嚣荫翼〖碦谪谥竆\竄",
"嬉絕篓翲肔鲽伯祋拚韝壹瞹╥恭火栝緘纋箴飑飚蓬飡髁飤铫苶裥肹褓鴓裣腗〖腛箜腖鮸酾〖〖〖與龃苮怕骱鴆鴎鴏鴉〖芆苵〖薿餕聗〖痠〖痭〖〖颐〖痬〖箔礽厉诓诘韜诏奚敷尢孵尴凤韛廛姘膺姣〖廨姹",
"〖阷絀紺〖阬阺鲷阸韙舽阰〖念〖餔聖碰〖嘱谲庭晓姻怖膗竈鉒鉐瓴嬲〖挟釉癕幼癓椎盟鬯凼巯顁唪蝠鹳泖籾泓籺泮銨渴缛饺凉绞陌可练顄羲鵎ピ璄忉祌υ蠺觙侧〖〖〖舰礴赕慨〖道酮證测舨盗饇羗调墁噜噢",
"緀緂〖韪繶肊肍鮋蟥臯〖艻〖癅腿鹗蜚璳楔璲雍蛹勇该犹尤癎癇癈癊矲矴矵镊抓驻矺矻矼蜣撰奂哝绿淀雓雕富凋襞惦郾劭嘎附哧讣改唢哽阒籪阚籬阙泸汊链籭汶籱籰籨礁籫〖羝缂交〖搅绺〖铰纰敛纾娇绾隵頶〖怜",
"涟隸雊頩隴坷帘鹆頬頮廉恋鹎頽镰连頸鹁鹄孪〖羯羧檬蜱鯞涅披ξ蘑羓磲覦縲覢竎覧肿覥痔舟衷财踩种擦治盅忠睬阱砻阪横阝哄竌竍〖〖逰逳鉘斫孀烘尜恒鳆鉞掳鉕〖颅絜卤絟絡旰杲昙縶炅罰罭〖砘砺",
"餰炉餳冒牛贸觩碴踂有衖璔蛎〖觪譙鱂譚譜〖撺撙籗鏔眈稷舳于竿砅甘钙梦拄適遪絶骟开〖覬〖〖阼阽逿鉦宏罼〖驷〖驵孢晟硐︶篬厕悼銄籅纟健凯羕ν磙鉼鉽碣鵄劲腡璿垌郿郶鵲砳疥愚砤誉訞訟躛",
"躟躚〖筓喹苚鵴鋝黄鋞〖鑋胭脎脍钇赁馬骭苗馫翡目臜è錾幕鄏鋊沦馜渝踪字砽罹埕埴禱\鱜禮埚禵禶鄆眠罗鄋鱛臙给鋀鋄鐯斤襟女琪玺怒〖肜〖挎肽库廖肱夸芢\纶裂鱙幂泌骃绵慕苙鱚鱝鵳摔禝哥郱瘃罘必灼乱墼郈",
"啐銱蝓镐痃璋掣艵恫綹糯璁繮繩鸣艷呐诺锏脑蹙趸舎舏排牌芐囡锉鵨獳訥筸嗾卉拢鳤洎苢鑤悯钷髄钴〖緖枸鳾〖〖苩縬靮芃靯〖飆翪飈鵟\翨笮鳻袂趴鳟霏鞑肵肨衩肰腏笄笕笾笏腎〖笸笪腒〖笙〖鮧苨南鮪鮲〖〖",
"鞔臺霎臽霪鳢爬鳙帕〖〖彭烹鳺晦贿哦〖霽苅駖慢〖〖溱浑緐黾〖〖纅肗窆臷\罅芺抨緔栀芁肦飅肧臹臰配肒殴鱲訧功混緒柙纆纇靝窕〖芀鳸芻或荆磔龚毂殳翯腝蔑舉棚翷翵翶肻\襦〖苪醵醮鴙舊锎胇挠拍鴞旄翸〖"
});

string *b5=({
"　，、。．．；：？！∶…¨，、··；：？！｜□｜□｜＿□□（）（）｛｝｛｝〔〕〔〕【】【】《》《》〈〉＾〉「」「」『』『』（）｛｝［］‘’“”＂″｀＇＃＆＊※§〃○●△▲◎☆★◇◆□■□□□□￣□＿□□□□□□□＃＆＊＋－×÷±√＜＞＝≤≥≠∞≈≡＋－＜＞＝～∩∪□∠□□□□∫∮∵∴♀♂□⊙↑↓←→□□□□‖□／",
"＼□□＄□□￠￡％＠℃□＄％＠□□□□□□□□□°□□□□□□□□□□□□□□□□□□□□□□□□┼┴┬┤├□—│□┌┐└┘┌┐└┘〓□□□□□□□□□□０１２３４５６７８９ⅠⅡⅢⅣⅤⅥⅦⅧⅨⅩ□□□□□□□□□□□□ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯＰＱＲＳＴＵＶＷＸＹＺａｂｃｄｅｆｇｈｉｊｋｌｍｎｏｐｑｒｓｔｕｖ",
"ｗｘｙｚΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩαβγδεζηθικλμνξοπρστυφχψωㄅㄆㄇㄈㄉㄊㄋㄌㄍㄎㄏㄐㄑㄒㄓㄔㄕㄖㄗㄘㄙㄚㄛㄜㄝㄞㄟㄠㄡㄢㄣㄤㄥㄦㄧㄨㄩ□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□",
"一乙丁七乃九了二人儿入八几刀刁力匕十卜又叁下丈上丫丸凡久么也乞于亡兀刃勺千叉口土士夕大女子孑孓寸小尢尸山川工己已巳巾干廾弋弓才丑丐不中丰丹之尹予云井互五亢仁什仃仆仇仍今介仄元允内六兮公冗凶分切刈匀勾勿化匹午升卅卞厄友及反壬天夫太夭孔少尤尺屯巴幻廿吊引心戈户手扎支文斗斤方日曰月木欠止歹毋比毛氏水火爪父爻片牙牛犬王丙",
"世丕且丘主乍乏乎以付仔仕他仗代令仙仞充兄冉册冬凹出凸刊加功包匆北匝仟半卉卡占卯卮去可古右召叮叩叨叼司叵叫另只史叱台句叭叻四囚外央失奴奶孕它尼巨巧左市布平幼弁弘弗必戊打扔扒扑斥旦术本未末札正母民氐永汁汀泛犯玄玉瓜瓦甘生用甩田由甲申疋白皮皿目矛矢石示禾穴立丞丢乒乓乩亘交亦亥仿伉伙伊夫伍伐休伏仲件任仰仳份企□光凶兆先全",
"共再冰列刑划刎刖劣匈匡匠印危吉吏同吊吐吁寸各向名合吃后吆吒因回囝圳地在圭圬圯圩夙多夷夸妄奸妃好她如妁字存宇守宅安寺尖屹州帆并年式弛忙忖戎戌戍成扣扛托收早旨旬旭曲曳有朽朴朱朵次此死氖汝汗污江池汐汕污汛□泛灰牟牝百竹米糸缶羊羽老考而耒耳聿肉肋肌臣自至臼舌舛舟艮色艾虫血行衣西阡串亨位住伫佗佞伴佛何估佐佑伽伺伸佃占似但佣",
"作你伯低伶余佝布佚兑克免兵冶冷别判利删刨劫助努劬匣即卵吝吭吞吾否□吧呆呃吴呈吕君吩告吹吻吸吮吵呐吠吼呀吱含吟听囱困囤囫坊坑址坍均坎圾坐坏圻壮夹妆妒妨妞妣妙妖妍妤妓妊妥孝孜孚孛完宋宏尬局屁尿尾岐岑岔岌巫希序庇床廷弄弟彤形彷役忘忌志忍忱快忸忪戒我抄抗抖技扶抉扭把扼找批扳抒扯折扮投抓抑□改攻攸旱更束李杏材村杜杖杞杉杆杠",
"杓□步每求汞沙沁沈沉沅沛汪决沐汰沌汨冲没汽沃汲汾汴沆汶□沔□沂灶灼灾灸牢牡它狄狂玖甬甫男甸皂盯矣私秀秃究系罕肖肓肝肘肛肚育良芒芋芍见角言谷豆豕贝赤走足身车辛辰迂□迅迄巡邑邢邪邦那酉□里防阮阱阪□并乖乳事些亚享京佯依侍佳使佬供例来侃佰并侈佩佻仑佾侏侑□兔儿兕两具其典冽函刻券刷刺到刮制剁劾□卒协卓卑卦卷卸恤取叔受味呵",
"咖呸咕咀呻呷咄咒咆呼咐呱呶和咚呢周咋命咎固垃坷坪坩坡坦坤坼夜奉奇奈奄奔妾妻委妹妮姑姆姐姗始姓姊妯你姒□孟孤季宗定官宜宙宛尚屈居届岷冈岸岩岫岱岳帘帚帖帕帛帑幸庚店府底庖延弦弧弩往征佛彼忝忠忽念忿怏怔怯怵怖怪怕怡性怩怫怛或戕房戾所承拉拌拄抿拂抹拒招披拓拔抛拈抨抽押拐拙拇拍抵拚抱拘拖拗拆抬拎放斧於旺昔易昌昆昂明昀昏昕昊",
"升服朋杭枋枕东果杳杷枇枝林杯杰板枉松析杵枚□杼杪杲欣武歧殁氓氛泣注泳沱泌泥河沽沾沼波沫法泓沸泄油况沮泗泅泱沿治泡泛泊□泯□泖泠炕炎炒炊炙爬争爸版牧物状狎狙狗狐玩珏玟玫□□疝疙疚的盂盲直知矽社祀祁秉□空穹竺纠罔羌芈者肺肥肢肱股肫肩肴肪肯卧臾舍芳芝芙芭芽芟芹花芬芥芯芸□芰芾芷虎虱初表轧迎返近邵邸邱邶采金长门阜陀阿阻附",
"陂隹雨青非亟亭亮信侵侯便侠俑俏保促侣俘俟俊俗侮俐俄系俚俎俞局兖冒胄冠刹剃削前剌克则勇勉勃劲匍南却厚叛咬哀咨哎哉咸咦咳哇哂咽咪品哄哈咯咫咱咻咩咧咿囿垂型垠垣垢城垮垓奕契奏奎奂姜姘姿姣姨娃姥侄姚奸威姻孩宣宦室客宥封屎屏□屋峙峒巷帝帅□幽庠度建弈弭彦很待徊律徇後徉怒思怠急怎怨恍恰恨恢恒恃恬恫恪恤扁拜挖按拼拭持拮拽指拱拷",
"拯括拾拴挑挂政故斫施既春昭映昧是星昨昱□曷柿染柱柔某柬架枯栅柩柯柄柑□柚查枸柏柞柳枰柙柢柝柒歪殃殆段毒毗氟泉洋洲洪流津洌洱洞洗活洽派汹洛泵洹洧□□洮洵洎洫炫为炳炬炯炭炸炮□爰牲牯□狩狠狡玷珊玻玲珍珀玳甚甭畏界畎畋疫疤疥□疣癸皆皇皈盈盆□盅省盹相眉看盾盼眇矜砂研砌砍祆祉祈□禹禺科秒秋穿突竿竽籽纣红纪纫纥约纡缸美羿耄",
"耐耍专耶胖胥胚胃□背胡胛胎胞胤胝致舢苎范茅苣苛苦茄若茂茉苒苗英茁苜苔苑苞苓苟苯茆虐虹虻虺衍衫要□计订讣贞负赴赳趴军轨述迦迢迪迥迭迫迤迨郊郎郁□酋酊重闩限陋陌降面革韦韭音页风飞食首香乘亳倌倍仿俯倦倥俸倩幸俩值借倚倒们俺伥倔倨俱倡个候倘俳修倭倪俾伦仓兼冤冥□冻凌准凋剖剜剔刚剥匪卿原厝叟哨唐唁唷哼哥哲唆哺唔哩哭员唉哮哪",
"哦唧唇哽唏圃圄埂埔埋埃□夏套奘奚娑娘娜娟娱娓姬娠娣娩娥娌娉孙□宰害家宴宫宵容宸射屑展屐峭峡峻峪峨峰岛□岘差席师库庭座弱徒径徐恙恣耻恐恕恭恩息悄悟悚悍悔悌悦悖扇拳挈拿捎挟振捕捂捆捏捉挺捐挽挪挫挨捍捌效敉料旁旅时晋晏晃晒晌□晁书朔朕朗校核案框桓根桂桔栩梳栗桌桑栽柴桐桀格桃株桅栓□桁殊殉殷气氧氨氦氤泰浪涕消泾浦浸海浙涓",
"□涉浮浚浴浩涌□浃涅□涔烊烘烤烙烈乌爹特狼狭狈狸狷□班琉佩珠□珞畔亩畜畚留疾病症疲疳疽疼疹痂疸皋□益盍盎眩真眠眨矩砰砧砸砝破砷砥砭□砟炮□佑祠祟祖神祝祗祚秤秣秧租秦秩秘窄窈站笆笑粉纺纱纹紊素索纯纽纰级纭纳纸纷缺罟羔翅翁耆耘耕耙耗耽耿胱脂胰胁胭胴脆胸胳脉能脊胼胯臭臬舀舐航舫舨般刍茫荒荔荆茸荐草茵茴荏兹茹茶茗荀茱茨荃",
"虔蚊蚪蚓蚤蚩蚌蚣蚜衰衷袁袂衽□记讦讨讧讪讯托训讫□□岂豺豹财贡起躬轩轫□辱送逆迷退乃回逃追逅迸邕郡郝郢酒配酌钉针钊釜钋闪院阵陡陛陕除陉升只饥马骨高斗鬲鬼乾□伪停假偃偌做伟健偶偎偕侦侧偷偏倏□□兜冕凰剪副勒务勘动匐匏匙匿区匾参曼商啪啦啄哑啡啃啊唱啖问啕唯啤念售啜唬衔唳啁□圈国圉域坚垩堆埠埤基堂堵执培够奢娶娄婉妇婪婀",
"娼婢婚婆婊孰寇寅寄寂宿密尉专将屠屉□崇崆崎崛崖峥昆崩崔仑崤崧岗巢常带帐帷康庸庶庵庾张强彗彬彩雕得徙从徘御徕徜恿患悉悠您惋悴惦凄情悻怅惜悼惘惕惆惟悸惚敦戚戛扈掠控卷掖探接捷捧掘措捱掩掉扫挂扪推抡授挣采掬排掏掀捻捩舍捺敝敖救教败启敏叙敕□斜斛斩族旋旌旎昼晚晤晨晦□曹□望梁梯梢梓梵□桶□梧梗械梃弃梭梆梅栀条梨枭□□欲杀",
"毫□氢涎凉淳淙液淡淌淤添浅清淇淋涯淑涮淞淹涸混渊淅凄渚涵泪淫淘沦深淮净淆淄涪淬涿淦烹焉焊烽烯爽牵犁猜猛猖猓狰率琅琊球理现□瓠瓶瓷甜产略畦毕异疏痔痕疵痊痍皎盔盒盛眷众眼眶眸眺硫朱硎祥票祭移窒窕笠笨笛第符笙笞笮粒粗粕绊弦统扎绍绋绌细绅组累终绁绂钵羞羚翌翎习耜聊聆脯脖□脱□□□舂舵舷舶船莎莞莘荸荚茎莽莫莒庄莓莉莠荷荻荼",
"莆苋处彪蛇蛀蚶蛄蚵蛆蛋蚱蚯蛉术衮袈被袒袖袍袋觅规访讶诀讷许设讼讹欣豉豚贩责贯货贪贫赧赦趾趺轭软这逍通逗连速逝逐迳逞造透逢逖逛途部郭都酗野钗扣钓钏□钒闭陪陵陈陆阴陴陶陷陬雀雪雩章竟顶顷鱼鸟卤鹿麦麻家傍傅备杰傀伧伞效最凯割剀创剩劳胜勋博厥啻喀喧啼喊喝喘喂喜丧喔喇喋喃喳单喟唾哟唤喻乔喱啾喉□喙围尧堪场堤堰报堡埚堠壹壶奠",
"婷媚婿媒媛娲孳孱寒富寓寐尊寻就嵌岚崴嵇巽幅帽帧帏几廊厕厢厩弼彭复循徨惑恶悲闷惠惬愣惺愕惰恻惴慨恼愎惶愉愀□戟扉掣掌描拣揩揉揆揍插揣提握揖揭挥捶援揪换摒扬背敞敦敢散斑斐斯普晰晴晶景暑智晾晷曾替期朝棺棕棠棘枣椅栋棵森栈棹棒栖棣棋棍植椒椎棉棚楮□款欺钦残殖壳毯氮氯氩港游湔渡渲涌凑渠渥渣减湛湘渤湖湮渭涡汤渴湍渺测湃渝浑滋",
"溉涣湎□湄□□湟焙焚焦焰无然煮□牌犄犀犹猥猴猩珐琪琳琢琥琵琶琴□琛琦琨甥苏画番痢痛痣痉痘痞□登发皖皓皴盗困短硝硬砚稍秆程税稀窘窗窖童竣等策笔筐筒答笋筋筏筑粟粥绞结绒绝紫絮丝络给绚□绛善翔翕耋聒肃腕腔腋腑肾胀腆脾腌腓腴舒舜菩萃菸萍菠菅萋菁华菱□着莱菰萌菌菽菲菊萸萎萄菜苌菔菟虚蛟蛙蛭蛔蛛蛤蛐蛞街裁裂袱覃视注咏评词证诂",
"诏诅诈诋诉诊诃□象貂贮贴贰贻贲费贺贵买贬贸贷越超趁跎距跋跚跑跌跛跆轲轴轶辜逮逵周逸进逶鄂邮乡郾酣酥量钞钮钙钠钧钝钤□钣闵闰开闲间闲闳队阶隋阳隅隆隍陲堤雁雅雄集雇雯云韧项顺须飧饪饭饨饮饬冯驭黄黍黑乱□债傲传仅倾催伤傻偬□剿铲剽募□勤势绩汇嗟嗨嗓嗦吗嗜啬嗑嗣嗤嗯呜嗡嗅呛嗥嗉园圆塞塑塘涂冢塔填塌□块坞埘茔奥嫁嫉嫌媾妈媪",
"媳嫂媲嵩嵯幌干廉厦弑汇□微愚意慈感想爱惹愁愈慎慌栗愠忾怆愧愍愆恺戡戢搓□搞搪搭搽搬搏搜搔损抢摇捣□敬斟新暗晖暇晕暖暄□□会榔业楚楷楠楔极椰概杨桢楫楞枫楹榆楝楣□歇岁毁殿毓毽溢溯滓溶滂源沟滇灭溥溘□溺温滑准溜沧滔溪溧溴煎烟烦煤炼照煜炀煦煌焕煞□煨□爷牒猷狮猿猾琅瑚瑕瑟瑞瑁珲瑙瑛瑜当畸瘀痰瘁麻痱痹痿痴□盏盟睛睫睦睐督",
"睹睾睬睁睥睨睢矮碎碰碗碘碌碉硼碑碓□祺禄禁万禽□稚稠稔禀稞窟窠筷节筠筮笕粱粳粤经绢困绑绥绦置罩罪署义羡群圣聘肆肄腱腰肠腥腮脚肿腹腺脑舅艇蒂荤落萱葵苇葫叶葬葛萼莴葡董葩葭葆虞虏号蛹蜓蜈蜇蜀蛾蜕蜂蜃蚬蜊衙裟裔裙补裘装里袅裕裒□解诧该详试诗诘夸诙诣诚话诛诡询诠诟詹□訾□豢貊貉贼资贾贿赀赁赂赅迹跟跨路跳跺跪跤□躲较载轼轾",
"辟农运游道遂达逼违遐遇遏过遍遑逾遁邹□酬酪酩釉钴钳钹钸钾铀铅刨钩铂铃铉铋钜铍钿铆闸隘隔陨雍隽雉□雷电雹零靖靴靶预顽顿顼颁颂饲饴饱饰驰驮驯髡鸠麂鼎鼓鼠僧僮侥僖僭僚仆像侨雇□□兢凳划劂匮厌嗾嘀嘛尝嗽呕叹嘉喽嘎嗷啧嘟嘈□哔团图尘塾境墓垫堑墅□寿夥梦夤夺奁嫡嫦嫩妪嫖嫘嫣孵寞宁寡寥实寨寝寤察对屡崭岖幛币幕帼幔廓廖弊□彰彻□",
"愿态慷慢惯恸惭惨慵截撇摘摔撤摸搂摺掴摧搴摭掺敲斡旗旖畅暨暝榜榨榕槁荣□构榛榷榻榫榴槐枪榭槌□盘□歉歌氲漳演滚漓滴漩漾漠渍漏漂汉满滞漆漱渐涨涟漕漫漯澈漪沪渔渗涤卤熔熙煽熊熄荧尔犒荦狱獐瑶琐玛瑰瑭甄疑疟疡疯□痪尽监瞄睽睿睡磁碟碧碳硕碣祯福祸种称洼窝竭端管箕笺筵算箝箔筝箸□□粹粽精绽绾综绰绫绿紧缀网纲绮绸绵彩纶维绪缁绶",
"罚翠翡翟闻聚肇腐膀膏膈膊腿膂臧台与舔舞艋蓉蒿席蓄蒙莅蒲蒜盖蒸荪蓓□苍蓑蓊蜿蜜蜻蜢蜥蜴蜘蚀蜷蜩裳褂裴裹裸制裨褚□诵志语诬认诫誓误说诰诲诱诳诮□豪□貌宾赈赊赫赵赶□辅辄轻挽辣远遘逊遣遥递遢□遛鄙□鄞酵酸酷酴铰银铜铭铢铬铨衔铵□铣阂闺闽阁阀□隙障际雌雒需靼鞅韶颇领飒台饺饼饵饷驳肮骰髦魁魂鸣鸢凤麽鼻齐亿仪僻僵价侬侩俭□凛",
"剧劈刘剑刽勰厉唠嘻嘹嘲嘿嘴哗嘘噎噗喷嘶啸叽墀墟增坟坠堕墩□□嬉娴婵妩娇娆寮宽审写层履嶝□幢帜幡废厨庙□广厂弹影德徵庆慧虑慝慕忧戚慰怂欲憧怜悯憎憬惮愤憔怃戮摩挚摹撞扑捞撑撰拨挠撕撩撒撮播抚捻撬撙□揿敌敷数暮暂暴□样樟椁桩枢标槽模楼樊桨乐枞槭梁欧叹殇毅殴浆潼澄泼潦洁浇潭潜潸潮澎潺溃润涧潘滕浔□□熟熬热熨牖□奖獗莹璋璃",
"瑾璀畿瘠瘩瘟瘤瘦疮瘢皑皱盘瞎眯瞌瞑□磋磅确磊碾磕码磐稿稼谷稽稷稻窑穷箭箱范箴篆篇篁□篌糊缔练纬致缄缅缉编缘线缎缓缍缂缈缇骂罢羯翩耦膛膜膝胶肤膘蔗蔽蔚莲蔬荫蔓蔑蒋蔡卜蓬葱蓿□螂蝴蝶蝠虾蜗□蝙蝗蝌蝓卫冲褐复褒褓□褊谊谅谈谆诞请诸课诿谄调谁论诤谇诽谀豌竖猪赔赏赋贱账赌贤卖赐质赓赭趟趣□践踝踢踏踩踟□踞躺辉辆辍辈辇轮辎辋",
"辊适遮遨遭迁邻郑邓鄱醇醉醋腌锌锑销铺铐锄铝锐锉锋钡锂焊闾阅霄霆震霉靠鞍鞋巩颉□颌刮养饿馁馀驼驻驷驶驽驾驹驸骷发髯闹魅魄鱿鲁鸩鸦□麸麾黎墨齿儒尽俦傧侪冀幂凝剂劓勋噙噫当噩噤吨噪器哝噱嗳噬噢噶壁垦坛壅奋□嬴学寰导□宪凭憩惫懔忆憾懊懈战擅拥挡挞撼据掳择擂操捡擒担挝整历晓暹晔昙□樽□桦橙横橘树橄椭橡桥橇樵机桡歙历氅濂淀澡",
"浓泽浊澧澳激澹澶□渑□炽炖□烧灯燕熹燎烫焖燃□独璜玑□□璞瓢瓯甍瘴瘸□卢盥瞠瞒瞟瞥磨砖磬碛御积颖穆稣□窥篙□□笃□篡筛篦糕糖缢缣萦缚县缟缜缙绉罹羲翰翱翮耨膳腻膨臻兴艘舱蕊蕙蕈蕨荡蕃蕉萧芜蕞螃螟蚂萤融衡褪裤褥褫褡亲觎谛谚谏讳谋谍谐谘诺谒谓讽谕谙谌谖豫□猫赖蹄踱踊蹂□踵辐辑输辏辨办遵遴选迟辽遗邺醒锭表锯锰错钱钢锡录铮",
"锥锦□锟锢锱阎隧随险雕霎沾霖霍霓霏靛静□鞘颊颈频颔头颓颐餐馆饯馄馅肴骇骈骆骸骼髻髭哄鲍鸵鸪鸯鸭□鸳默黔龙龟优偿儡储励嚎咛□嚅吓嚏壕压壑□婴嫔嬷孺尴屦屿岭岳嵘帮弥徽应懂恳懦懋戏戴擎击擘挤拧擦拟搁擢□敛毙曙暧檀档檄检桧栉樯□檗檐檠□殓□毡泞滨济濠蒙涛滥濯涩□濡□湿濮潍燧营燮灿燥烛毁烩燠爵墙狞获璩环瑷璨痨疗癌汤瞳瞪瞰瞬",
"瞧了矫磷磺磴矶礁禧禅穗窿簇篓篾篷簌□糠糜粪□糟糙糁缩绩缪缕缧绷缝总纵缫繁纤缥□缦□□罄翳翼聱声聪联耸臆臃膺臂臀脓胆脸脍临举艰薪薄蕾薜姜蔷薯薛薇薨蓟亏蟀蟑螳蟒蟆螫蝼螺蝈蟋亵褶襄褛□觊谜谤谦讲谎谣谢誊谧豁溪豳赚赛购□赙趋蹉蹋蹈蹊辖辗毂辕舆避遽还迈邂邀鄹醣酝丑镀镁锚键□锲锅锤锺锹锻锾□锷阔阕阑闱板隐隶虽霜霞鞠韩颗飓□骋",
"骏鲜鲛鲔□鸿鸽麋黏点黜黝黛鼾斋丛噜向圹垒婶彝懑戳扩掷扰撵摆擞撷断曜朦槟檬柜槛柠□□台欤归殡泻渖滤渎溅瀑浏熏烬焘□犷猎璧□□癖疠愈瞽瞿瞻睑础礼穑秽□窜窍箫簧簪箪篑简粮织缮绕缭绣缯□□翘翻职聂脐膑旧藏萨蓝藐藉薰荠薹荐蛲蝉虫蟠覆觐觞谟谨谬谪丰赘蹙蹒蹦踪迹跸躯转辙迩邃邈医酱□□镑锁钨镍镇镐镒镉□□阖闯阗阙离杂双雏鸡□鞣秋",
"鞭□额颜题颚颛□馏馊□餮馥骑髁鬃松魏魉魍鲨鲤鲫□鲧鹃鹅鹄黠□鼬□□坏垄坜宠庞庐惩怀懒懵攀拢旷曝橱椟榈橹瀛潇濑瀚沥濒泸爆烁牍犊兽獭玺琼瓣畴疆瘪痴蒙碍祷获稳□簿簸签檐籀系茧绎绳绘罗缴□羹羸腊藩艺薮藕藤药□蚁蝇蝎蟹蟾裆襟袄襞哗谱识证谭谲讥□谯赠赞蹼蹲躇蹶蹬跷蹴辚轿辞边邋□醮镜镝铲镞链镗镘鏖镖镙锵镂铿錾关陇难霪雾靡韬韵类",
"愿颠飕馒馑骛骗胡鲸鲳鲭鲷鹑鹉鹊鹌鹏麒丽麓麴劝咙嚷嘤严嚼壤孀娘孽宝□悬忏攘拦搀曦胧榇澜弥潋炉献珑痒□矿砺矾砾窦竞筹篮籍糯团辫缤继纂罂耀胪舰藻蔼蘑蔺芦苹苏蕴□蠕褴觉触议譬警译噪谵赢赡趸躁躅□醴释钟铙锈阐霰飘饶□馨骞腾骚□鳃鳅咸面党鼯龃出龄俪□嗫啭嚣夔属巍惧慑摄携斓曩樱栏棂歼灌烂牺□璎癞胧□缠续羼□兰藓蛎蠢蠡蜡袜□览谴",
"护誉赃踌跃跻轰辩醺镰镭铁铛铎镯镌辟霸霹露响顾颢飨驱骠蓦骡髅魔魑鳍鳏莺鹤鹞□麝黯鼙龇龈□俨傥呓囊罗孪巅峦弯懿摊权欢□滩猡瓤叠瘾癣禳笼籁聋听脏袭衬□读赎赝踯踬辔郦铸鉴鉴霁霾鞑□颤饕骄骁脏须鳖鲢鳔鳗鹧鸥鼹龉龊龚苏□恋挛攫搅晒□瓒窃签□□缨纤□□蘸萝蛊变逦逻镳铄□靥显餍惊驿验髓体髑鳝鳞鳜鸶麟□嘱坝揽灞瘫癫矗罐羁蚕蠹衢让谗",
"谶艳赣酿□雳灵霭千颦骤鬓魇鲎鹰鹭硷盐□龌龋厅榄湾篱箩蛮观蹑□镶钥颅馋髋鬣黉滦瞩赞镊鞯驴骥缆谠躏酽钻銮锣鳄鲈黩□凿鹦爨骊郁鹳鸾吁①②③④⑤⑥⑦⑧⑨⑩⑴⑵⑶⑷⑸⑹⑺⑻⑼⑽ⅠⅡⅢⅣⅤⅥⅦⅧⅨⅩ□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□",
"□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□",
"□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□",
"□乜□匚□万丌乇亍□□□彳□□□□亓仂仉□□□昂□□□□□□□□□□□□□仨□□仡仝□□□□□□□夯□宄□尻□□□庀□忉□□氕□□□□□犰□□□□伎□□仵□□□□□□□□伢□□□□冱□□□□□□□□□囡囟圮□□夼□□□□□□□□尕尥□屺□□□□庄□□□□□□□□□□扦□□□□□旯旮□□□□□□□□氘氽□汜□汊汔□",
"□□□犴□玎□□□□□□□艽艿□□邙邗□邛□阢□□□□□□□□佤□佧□佟□佘□□□□□□□□□劭□□卣□□□□□□呔□□□□□□□□□□□□□□□□坌□□□□□□□□妗□□□□□□□□□□岍□岈□□□□□□□□□□庋□□□□□□□□忒忑忐忭□忮□忡忤□□□汹忻□□□□□□□□□□□□□□□□□□□考旰□□□□□□",
"□□杌杈□□□□□氙氚□□□□□沏□□□□□□□□□□□□□□□□□□狃□狁□□□□□□□町□疔□□□□□□□□肜□芏□芎芑□芊□芄豸□□□邡□□□□□□□□□□佼□□□□佶佴侉侄□□侗□徇□□□□□侔□□□□□□□冼□□□刳□□□□陶□□□□□□□咂□□□□□□□呦□□□□□□□呤□囹坯□坭坫□□坶□丘坻坳□□",
"坨□□□□□□□妲□□□□□□□□□□□□孢孥宓宕□□□□□岵□□岬□岣□岢□□□□□□□□帔帙□□□□□徂□□□□□怦怙□□□怊□□□□□□怍□□□□□□□戋戽□□□□□□拊□□□抻□□□□□□□□□□□□昃□□□□□□□朊□□□□□□枘□□□□□□□□□□□□□□□□□□□□沓□泫泮□□泔沭□□泐□□□□□□",
"□□□□□□□□□□□□□□□□炔□炅□□□□□□□□□□□□□□狒□□□□□□□□玢□□□□□□畀甾□□□□盱□□矸□□□□□他□□穸□□□□耵□□□□□肭□□□芫□芘□□□芮□□□芴芨芡芩□芤□□□□虬□□□□□迓□□迕□□邴邯邳邰□阽阼□□□俅□□□□俣□俜□□□□□□□□□□刭锉□□□□□□厍厘□□咭□哏",
"□□啕□□□□哆□□□□□呲哞□□□□垤垌□□垛□□□□□□□□□□□□□□□姝□□□□□□□□□□□□□□□□□□□□□峋□□□□□□□□□□□□□□□卺□□□□□□□□□□庥□□彖□□□□□□□□□□□□□恂汹□□□□□□扃□□□□挎□□□□□□拶□□□□□□□□□□□昶□□昵□□□□□□昝昴□□□朐柁□□□",
"柜□□柘□枷□□□□枵□枳□□□□□□□□柰□□□□□□□□□□□柃□□□殂殄□毖□□□氡□□□□□□洒□□洳洄洙□洚□□□□□□□□□□洇□□□□□□炷□□炱□□□□□□□□□□□牮□□狨□□□□□□□珂珈□□□□□□□□□□□□□□瓮□□畈□□□□眈□眄□□□□□矧□□砑砒□□□□砉□□□□□□□秕□□□□窀",
"□□□□□□□□□□□纨□罘□□□□□□耔耷□巯□□□胂□□□胙□□□□□胗□胍□舡□□□□茇□□苕茺苫□苴□苡□□茌苻□□□苤苠□□□□□虼□□□□□衩□□訇□□□迮□□□□□郅邾郇□□钇钆陔□□□□□□□□□□□□表□□□倬□□□倜□□□□□□□□□□□□□□剡□□剞□□□□□□□□□□哧哳□□哿呗□□唑□□",
"□□□□□□□□□□□□埕埒□□□□垸□□□□□□□□□□□□□□□□□□孬□□□□□□□□□□□□□□□□□□□弪□□恝恚恧恁□□□悒□悝悃□悛□□□□□□□□□□□捅□捃□挹捋□□□□□□□□□□□□□□□□□□□旆旃旄□□晟□□□□□□桉栲栳□□□□□□□□□□桎桄□栝□□□□□□□□□□□□□□□□□□□",
"□□□□□□浣□□□□□□□□浯涑□□□□浞□浠□□浼□涂□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□狺狴□□狳狻猁□珙珥□□珧□珩□□□□□□□□□瓞□瓴□□畛□疰□□□□□□□□□□□□□□□□□眙眚眢□砣砬□□□□□□□砩□□□□祛□祜祓□□秫□□□秭□□□□窆□□□□□□□□",
"笄□□笏笈笊□□□□粑□□□□□□□□□□□纾□□□□□罡□□□□□□□□□耖□□胺□□□□□□舁舯□茳茭□□荑□□□□□茜□□□茛□茈茼□□□□□茯□荇□□□□茬□□□□□□蚨□蚍□□□□□蚋□□□□□蚧□□□蚝□□杯衄□□□衲□□衿□□衾□□□豇□□□□□□趵□□□□□□□□□逄□□□□□□□郏□□郛郗郜□酐",
"酎酏钌□□□陟隼□髟鬯□□逼□□□□□□□偈□□□□□□□□□□□□□□□□□□□□□□剐勖□匦□啵啶□□啐□唪□□□□唰□□□□啥□□□□□□□圊囵□□□□□埴堀埭埽□埸堋□埏堇□□□□□垭□□□□□□□□□堍□□□□婕婧□□□娅□□□□□□□□□□□□□□□□□□□□□□□□□□□□□屙崞□□□□□□崃崦□□",
"□□□□崮□□□□庹□庳□□□□□□□□□□□□□□□□惝□悱□□□□□□□挲□掊掂□□□掭□□□掎□掇掐□□□□捭掮□□□□□□□□□□□□□晡□□□□□□□□□□□□□□□□□□□桴□梏桷□□桫□□□□□□□□□□□□□□□□□□□欷□□□殍□□氪□涫□□□□□□□涞□□□淠□淖□渌□淝□□□□□□□□□□□",
"□□□□□□□□□□烷□烃□□□□焐□□□焓□□□□□□牾□□牿猝猗□□□猊□□□猞□□□□□□□□□□□□□□□□□□□痒□□□□□□□□□□眭□□□□□□□眵□硒□□□硌砦硅硐□祧□□□□□□□秸□□□□□□筇□笥□□笤笳□笪□笱笫□□□笸□□□粘□□□□□□绀□□□□□□□□□□□□□羝□翊□□□□□□□□",
"□□□聃□脘□□胫□□脬脞□□□□□□舸舳□舴□艴□□莨□□豆□□□□□□□□莩荽□□□莛莪□□□□□□□□□□□□□□□□□□□□蚺蚰□□□□□蚴□□□□□炫□□□袢□□□□□□□□□□袤□□□□□觖□□□□□□□□□□□□□□□趼□□趿□□□□□□□□□逋逑□□逡郯□□郴□□□郫□□□□酚□□□□□□□钐钕□",
"□钍□□□闫□□□□□□□□□□馗□□□□□傣□□□□□□□□□□□□□□□喑□□□□□□□喈喏喵喁□□□□□□□□□□□□□堙堞□□□□□□□□□□□□□□□□□□妫□□婺□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□嵫□嵋□□□□□嵛□□崽□□□□□□□□□□□幄□彘□□□□□□□□□□",
"恽□□□□□□□□□□□□□□□□□□□掰揎□□□□□□□揠揶□揲□□□掾□□揄□□□□□□□□□□□□□□□□□斌□□□□旒□□□□□□□□□□□□□□□□棱桠枨□□□□□椐□□□□□□□□□□□□□□棼□椋□□□□□□□□□□□□□□□欹□□□□□□□肴□□毳氰淼□□□□沩□□□□渫□□□□□□□□□□□□浈",
"□□□□□□□湫□□□湓□□□□□□□□□□□□□□焯□□焱□□□□□□□□□□□□□□犋□□□猢猱□□□□□□□□琮琬琰□□琚□□□□□□□□□□甯□畲痧□□痦□□痤□□□□□睇□□□□□□□□矬□硖□□硭□□□□□砗□□□□□□稂□稃□□□竦□□□□□筌□□筘筅粢粞□□□□□□□□□□□□□□□□□□绗□□□",
"□□□□□□□□□□□□□□□□□□□□□□□舄□□□□□菏菹□菀□□□□□□□□□□□□萁菝菥菘□菡□□菖□□□萏□萑萆□□□□菇□菪□□□□□□□□□□□蛘□□□□□□□□□□蛩□□蛑□□□□□□□□□□袼袷□□□裉□觇□□觚□讵□□□□□□□□诒詈□□□□□□□贶□贳□□趄□□□□□□跖□跏□□□跗□□□轺",
"轵□□□□□□□轸□□□□逭□逯郓□鄄□□□□□□□□□□酡酤□酢□钫□钬□□钛□□钯□□□□钭钪□□□□□□□□□闶□□□隈陧□□□□□□□□□□顸□饫□黹□□□□□□□□仙伛□偻□□傺□□佥□□□□□□□□□嗌□□□嗝□嗔嗄唢□嗒□□□□嗖□嗲嗍□□□□□埙垲塍□□□□□□塥□□□□□□□□□媸□媵□□□□□",
"□□□□□□□□□□□□□□□嵊□□嵬□□□□□□□□□□□□□□□彀□徭□□慊愫□□□□□□□□□□□□戥戤□□□搐□□搠□□□□□□□□□□□搦□□摁□掏□□捂□□搋□搛□搡□□□□□暌□□□□□□□□楦□□□□楱椿□□椹楂楗□□□□□□□椽□棰楸椴□□□匾□□□□□□□□□□□□□□□□歆□歃□□□殛□□□",
"毹□□□□□溏□溟□□□溱□□□溽滁□□溷□□□滏溲□□□□□□□□□□□□□□□□□□□炜□□□□茕煲煸□□□□□□□□□□□□□□犍□□□□□□狲□□□□□□玮□□瑗□□□□□□□□□瓿□□□畹□□□□瘃□□痼□□瘐□□□□□皙□□□□□□□睚□□□□□□碇碚□□□□□□碡□□□□□□□□□□□□□□稗□□□",
"□□□□□□□□□□□筲□□筱□□□□□粲□□绨绠□□□□□□□绡□□□□□□□□□罨□□羟羧□□□□腠□□腩□□□□□□□□□脶□艉艄□□□□□□葶□□□□葑□□□□□□葚葙□葳□□□□□□葺□葸□□□□□□□□□□扁□□荭□□蒎□□□□□□□□□□□□□□□□蛱□□□蛸□蜉□□蜍□□□□裎□□□□□□□□觥□",
"□□□觜□□诓诖诩□□□诔诜□□□□□□□□□□□□貅□□□趑□□□□□趔□□□□跬□□□□跣□□□跫□□□□□辂辁□□□遒□遄□□□□□□郧邬□□酮酯铊□铈钰钲钶□钺铳铌□□钽钼□□□□□□□□□□□□□□□□□□□□□□□□隗雎□□□□靳□□□颃□颀□□□□□□□□□□□□凫□黾僦□□偾僳□□□□□僬□□□□",
"□□劁□□□□嘧□嘌□□嘏唛嘁□□□□□□□墉□□□□墁□□□□□□□□□□□□□□□嫜□□□□□□嫫□□嫠□□□□□□□□□□屣嶂□□□□嵝□□□□□□□□□帻□□□廑□□□□□廒□□□□□□悫□□□悭□□□□□□□□□□□怄□□戬戗□□□□□□抟□抠□□□□□撂摞掼□□□□□搿□□□□□□□□□□□□□榱□□",
"□槎□□□□□□□榧榍□□□桤□□□槔□槊□□□□杩□□□□搌□□□□□□□殒□□□□□荥□□□□浒□□□漉□□沤□□□□□□漶□滹□漭□□□溆□□□□□□□□□□□□□□□□□□□□□□熏□□□□□□□□□呆獍□□□□□□□□□□□□□□□□瘌瘕□瘊□皲□□瞅□□瞀□□□碲□碴砀□□□□碥□□□□□禊□□□□□",
"□□□□□□□□扁□窨□窬□□箜□□箐□箍□□□箅□札□□□□□粼□□□□绻□□□□□□绲□绯□□绺□□□綦綮□□□□□□翥□□□□□嗉腽□□□□□蒗□蒡□蒺□□□□□蒹蒴蓁蓍□□□蓐□□□□莳□□□□蒯□蓖□□□□□□□□□□□□蜣□□□蜮蜞□□□□□□蜾□□□□□□蜒□蜱□□□□□□蜚□□□□裱□□裾□裼□□",
"裰□□□觋□□□觫□□□□诶□□□□□赇□□□踉□□□跽踊□□□踅□□□□□□□鄣□□鄢□□□□□□□酲酹□铱□□□铒铑□铕□铟铫铯□□铪铷铖銎□□□□□□□□□□□□□铥□□□□□□□□□□□□□□□□□□□□□飑□□□□□□□□□□□□骱□□□□□□□□□□□□□□□儆儇□□儋□□□□刿劢□□□噌哓恶□□□噘",
"□□□□嘬□呒□□□□□□□□□□□□□□□□□□□□□□□□□□□嶙崂□□□□□峤□□□□□□□□□廛□庑□□憋□□□□□□□□□□□愦□□□□□□□□撖□撅□□□□□□掸挢□□□□□□□□□□□□□□□□□□樗□□□□连□槿□□□□□□槲□□□椠□□□□□□□□□樘□□□□□□□□□□□□□□毵□□□□涝□□",
"澍澉澌潢□□□□□□澄□潲□□□□□□□□□□□□□□□涠□□滗□□□□□□熠□□熵□□□□□□□□熳□□□□□□獠□□□□□□璇琏□□璁□□□□□□□□瘥瘗瘙□□□□□□□□□□瞍□□□□□□□□□磔□□□磉禚□□□□□□稹□□窳□箧□箬□□□□□糅糈糌□□□□□缃缗□□缌缏缑□□□□□羰□□□□□翦□□□膣□",
"□□□□□□艏□□□□□□蔻□□□□□□蔟□□□□蔫□□蔌□□□□□□□蓼□□□□□□□□□荜蒌□□茑□□蓰苁□□□□□□□虢□蝣蝤□□□□□□□□□□□□□□□□□□□□蝮□蝥□蝻□□□□□□□□□□□褙□□□□□□□□□□□诹□□□诼□□□谂□□□□□□□□□□□□□周□赉□赕□□□□□踣□□踮□□□□□□□",
"踔□□□□□□□□□□□□□□□□□□□鄯□□□郸□□醅盏□□□□□□锒□□□□铗铽锓□□□锊铤锆□锇□鋈□锔□□□□□□□□□□□□□阆阃□□□□□□霈□靓□□□□□□□颏□□□□□□□□饽哺□□□□□□□驵□□□骀□□□□□髫□□□□魃□鲂□□□□□□□□□□□□□鸨□□□□□□□□□鼐□□□□□□□□□哒□",
"□哕□□哙□□圜□□□□□□□墼□嬗嫱□嫒□□□嬖□□□□□□□□峄□□□□□□□□□□□□□廪□□廨□□徼憝憨□□□□□怿□□□□擗□擐□□□□□□□□□□□□□暾□□□□□□□□□□□□□□□樾□□□橛□樨□□□□□□橐□□□□□□□□□□□□□□□□殪殚□□□□氆□□□□□□□潞□□□□□□□浍□□□□□□",
"□濉□□□□□□□□□□□烨□燔□□□□□□□□□□□□□□獬□猃狯□□□□□□□□□□瘭□□瘳瘼瘵□瘰□□□□□□□瞢□□□□□□□□□碜□□□□□□□□□□窭□□□□□□□篝□篥篚□□□篪□□□□□□□糗□□□□□□缛□□□□□□□缒□□□□□□□□□□□□耪耩□□膦□□□□□□□□□□□□□□蕖□□□□□荛",
"□蒇蕤□蒉□□□□□□□荞□□莸□□芗□□□□□□□□□□螗螓□螈□□□□□□螅□□□蛳□□□□□□褰□□□□□□□□□□□喧诨□□□□谑谔□□□谝□□□□□□□□□□□□□□□□□□□□蹀□□□踽蹁逾□□□□□□□□□□□□□□□□郐□醐醑醍□□□锩锬锖□锗铼□锛□锕锞钔□□□□□□□□□□□□□□□□□□□□",
"□□□□□□阏□阈阉□阊阌□阍□□□□□□□鞔□□□□□□□□□□驳□□□□□□□□□□□□□□髹□□□□□□□□□□鲋鲐□□□□□□□□□□鸲□□□□鸱麈□麇□□□□□□鼽□□□□□□□嚓哜□嚆□□□□□□□□□□□□嬲□□□□□□□□□嶷帱□□□□□□□□□□恹□摈□□□擤□□□□□□□□檩□柽□□□□□□檎",
"□□□□檑□□□□□□□僵□□泶□□□□□□□□□□□□□□□□□□□□□獯□□□璐□□□□□□甑□甏□癃□瘅痫皤□瞵□□□□□□□□□硗□□□磲礅□□□□□□□□□□□□□□□簏□箦□□□□簋筚□□□□□□□□□□□糨缡□□□□□□□□繇□□□縻絷□□罅□罾□□□耧膻□臌臊□□□□□艚□□□薏□□□□□蕻薤□□",
"蓣□□□蕺□□□□□□剃□□□□荟薅蕹□□□□□□□螭□□螬□螵□□□□□□□螯蛰蟊□□□□螽□□□裢□□襁□□□□觏□□觳□□谡□诌□□□□□謇□□□□□谥□□□□□□貔□□□□□□跄蹇□□□□□醚醢醛□□□□□□□□锸□锴针铡□锶□□□□□鎏□鍪□□□□□□□□□□□□□□□□□□阒□□□隰□□□□□□□□□",
"□□□□□□□□□□□□□□□饧□□□□□馘□□□□□□□□□□□□□□□□□□□魈鲒□鲕□□□□□□□□□□□□□□鸸□□鸹□鸺□□□□□□□□□□□□□黻鼋□□鼢龀龠□□□□□□□□啮□□□□□□□□怼□□□□□□□□□摅□□□□撸□□□曛□□□□□□□□祢□□□□□□□□□□滢□□□□□潴泺□□□□燹□□□",
"□□□□□□□□□甓癜疖□□□□□□□□□□□□礓□□□□□□□□□□□□簟□□簦□□□□□□□□□缋□□□□□□□□□聩□□□艟□□□□□□□□□□□□□荩□□□□□□□薷□□□□□蟛□蟪蟥□□□□□蟓□□虮□□□□□□□□□□□□□□裥□□□讴□□□□□谩□□□謦□□□□□□□□□貘□赜贽□□□□□□□□□糟",
"□□□□蹩□辘□□□□邝□□□□□醯醪镓□□□□□□铠□锼□镏□□□□□□□□□□□□□□□□隳□□□□□□□□□□□□鞫□□□□□韪□□□□□□□□饩□骐□□骒□□□骓□□髀□鬈□□□□□□□鲩□□□鲠□□□□□□□鹈鹁□□□□□□□□鹆□□□□□□黟□□□□□□□□□□□□□□厣□□呖□□□垆□□□□□□□□",
"□□□□□攉□□□□□□槠□□□□□栎□□橥□□橼□□氇□泷潆□□□□瀣□□□□□□□□□□□□□□□□□□□□□□□□□□□礴□□礞□□□□□□□□□□□□□缲□缳□□□□□□□罴□□□□□□舣□□□□□□□□□□□□□□□□藜□□□□□□□□蠃蛏□□□□虿□□□蠊□□□□□□□□裣□□觑□觯□□□□□谮撰□□",
"□□□□□□□□□□□□□□□蹭□□□蹯□□□□□□□□□□□醭镛镟□□□□镪□镆□铩□鏊□□□□□□□□□□□□□□□□□□□□□□韫□□颡□□□□□□馐□馍□□□□□□□□□□□□□□□髂□□□□□鲮鲰□□鲲□鲵鲶鲻鲞□□□□□鲱□□□□□□□□□□□□□□□□雕□□□□□鹎□□鸫□□□□黼□□□□□□□□□",
"□喾□□□□□□□□□□撄□□□□□□栊□枥栌□□□□□瀵□□□□□□□□瀹□□□□□□□□猕璺□□□□□□□矍□□□□□礤□□□□□□□□□□□□□缱□□□□聍□□衅艨□茏藿□□□□苈蕲□蘅□□□蛴蝾□蠓蠖□襦□□□□□□□□□毁□□□□□□□□□□□酃□□醵□□铴镦□镨□镡□□镣□镫□铧□镤□□□铹□□□□□",
"□□□□□阚□□□□□□□□□颟□□□□□□□馔馈□□□□□□驺□骝骟骘□□□□□□□鲽□□鳆□□□□□□□鳇□□□□□鹕□□□□□□□□鹗□□□□□□□□□□□□黥□黧□□□□龆□□龅□傩□□□□□□□□岿□□□撺□□□榉□沣滠□□□□□爝□□獾□□□□砻□□□□纩□缬□□□□□□□□□□□□□□蘧□□□蘩蔹□",
"□□蠛□□□□□□□□□□□□□□□赆□□□□□□□酆□□□镱□环□□□□□□□□□□闼□□□□□□□□飙□□□□□□骢骖骜□□□□□□□□□□□□□鲥鳎鳐□□□□鹣□□□□□□□鹘□□□□□□□□□□□□鹾□□□□□□□□□□□□□□冁□□□娈□□□□□□攒□□□氍□□□□□□□□□□□□瘿□□□穰□□箨□□□",
"籴□□□□□舻□□□□□□□□□□□□觌□□谫□□□□□□蹰躔跹跞躐□□□轹□镔□镬□□□□□□□□□□□□饔□□□□□骣□骅□□□□□□鬻□□□鳕□□鲣鳓□□鲦□鳌□□□□□鹨□□□□□□鸷□□□□□□□□□□□□龛和□□□□□□□□□□□□□攥□□□栾椤□□□□□□□痈□□□□□蓠□□蘼□□□□蠲□□□□□□",
"宴雠□□□□□轳□□□□□□□□□□□□□鬟□鳟鲟□□鲅□□□□□□□鹩□□鹬□□□□鹪鹫□□□鹇□□□□□黪□□□□鼷□□齑□□□□□□□□□□□□□□灏□□□□□□□□簖□□□□□蠼□□□谰躞□□□□□□鑫□□□□□□□□□髌□□鳢□□□□□□□□□□□□□□□□□□□□□□囔攮□□□□□□□□□□□笾□□□",
"缵纛□脔□□□□□□□襻□□□蹿□□□镧□□□□□饷□□鲚□□□□□□□□鼍□□□□□□□□□趱躜酾□□□□□□□□□□□□□□□□□□□□□谳□□□□颞颧□□□骧□□□鸬□□戆□□□□□□□□□阄□□□□□□□□□鲡鹂滟□□□□□□□里□□□□┏□┓□□□┗┻┛□□□┝┿┥□□□□□□□□□□□□┃━□□□□□"
});

string b5_gb(string str)
{
    int i, len, hi, lo;
	string ret = "";

	if (!stringp(str)) return ret;
	len = strlen(str);
    for (i=0;i<len;i++) {
        hi = str[i];
        if (hi < 161 || hi > 249) {
		ret += " ";
		ret[<1] = hi;
		continue;
	}
        lo = str[i+1];
        if (lo < 64 || lo > 254) continue;
        if (lo > 126 && lo < 161) continue;
        lo -= 64; if (lo > 96) lo -= 34;
        lo += lo;
        ret += b5[hi-161][lo..lo+1];
        i++;
    }
    return ret;
}

string gb_b5(string str)
{
    int i, len, hi, lo;
	string ret = "";

	if (!stringp(str)) return ret;
	len = strlen(str);
    for (i=0;i<len;i++) {
        hi = str[i];
        if (hi < 161 || hi > 247) {
		ret += " ";
		ret[<1] = hi;
		continue;
	}
        lo = str[i+1];
        if (lo < 161 || lo > 254) continue;
        lo -= 161;
        lo += lo;
        ret += gb[hi-161][lo..lo+1];
        i++;
    }
    return ret;
}
