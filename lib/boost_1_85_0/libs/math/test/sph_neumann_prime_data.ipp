//  Copyright (c) 2014 Anton Bikineev
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

   static const std::array<std::array<typename table_type<T>::type, 3>, 263> sph_neumann_prime_data = {{
      {{ SC_(0.1e1), SC_(0.177219114266335964202880859375e-2), SC_(359333999.0655634324694531404939614737681147243398) }}, 
      {{ SC_(0.1e1), SC_(0.22177286446094512939453125e-2), SC_(183360074.96057352268211511791232035239121240115451) }}, 
      {{ SC_(0.1e1), SC_(0.7444499991834163665771484375e-2), SC_(4847562.2468641634106491550315653183518163006043786) }}, 
      {{ SC_(0.1e1), SC_(0.1433600485324859619140625e-1), SC_(678805.85544845556066692725239262977651894085545557) }}, 
      {{ SC_(0.1e1), SC_(0.1760916970670223236083984375e-1), SC_(366280.13369684057840601322690121155290414400996075) }}, 
      {{ SC_(0.1e1), SC_(0.6152711808681488037109375e-1), SC_(8586.7941809522805029274990167921047078879662919446) }}, 
      {{ SC_(0.1e1), SC_(0.11958599090576171875e0), SC_(1169.4998238937076881620656431058513489697019811062) }}, 
      {{ SC_(0.1e1), SC_(0.15262925624847412109375e0), SC_(562.53042353423103453138252280708489801338881213709) }}, 
      {{ SC_(0.1e1), SC_(0.408089816570281982421875e0), SC_(29.528280235146191217326195255607801255694362737253) }}, 
      {{ SC_(0.1e1), SC_(0.6540834903717041015625e0), SC_(7.3029808834190858799087148290075956031296309375727) }}, 
      {{ SC_(0.1e1), SC_(0.1097540378570556640625e1), SC_(1.7520363088235556716887070699283989345431477734288) }}, 
      {{ SC_(0.1e1), SC_(0.30944411754608154296875e1), SC_(0.26522379852724621859878052016880863366699269358044) }}, 
      {{ SC_(0.1e1), SC_(0.51139926910400390625e1), SC_(-0.14097973215016883551297824250408378174352082729301) }}, 
      {{ SC_(0.1e1), SC_(0.95070552825927734375e1), SC_(0.10069101383864637167971294727460193305761274025824) }}, 
      {{ SC_(0.1e1), SC_(0.24750102996826171875e2), SC_(-0.03857863218596576826951489664721779319603309324794) }}, 
      {{ SC_(0.1e1), SC_(0.637722015380859375e2), SC_(-0.0088421582424313314233043751627027752297847168831446) }}, 
      {{ SC_(0.1e1), SC_(0.1252804412841796875e3), SC_(-0.0074496889272010504240132511011466429248577218770129) }}, 
      {{ SC_(0.1e1), SC_(0.25554705810546875e3), SC_(0.0018240659824485386662074451116218711462193917448094) }}, 
      {{ SC_(0.1e1), SC_(0.503011474609375e3), SC_(-0.0018601485837823667935137723026886188368476364922577) }}, 
      {{ SC_(0.1e1), SC_(0.10074598388671875e4), SC_(0.0005451101158650447149405572398059096253944883094538) }}, 
      {{ SC_(0.1e1), SC_(0.1185395751953125e4), SC_(0.00044365982633623047848806840178568249990997694189554) }}, 
      {{ SC_(0.2e1), SC_(0.177219114266335964202880859375e-2), SC_(912431644082.87013473772752757882565300486288333057) }}, 
      {{ SC_(0.2e1), SC_(0.22177286446094512939453125e-2), SC_(372056592577.8586498192494156231399648464957675173) }}, 
      {{ SC_(0.2e1), SC_(0.7444499991834163665771484375e-2), SC_(2930230007.2790547450960609343138097920878586745713) }}, 
      {{ SC_(0.2e1), SC_(0.1433600485324859619140625e-1), SC_(213076184.06160999468936202617229638832164230987561) }}, 
      {{ SC_(0.2e1), SC_(0.1760916970670223236083984375e-1), SC_(93604014.350278903611780200483209022625430010130218) }}, 
      {{ SC_(0.2e1), SC_(0.6152711808681488037109375e-1), SC_(628155.9196789361284981387791525806930365557094831) }}, 
      {{ SC_(0.2e1), SC_(0.11958599090576171875e0), SC_(44041.790324511420099836446386761002939531625293417) }}, 
      {{ SC_(0.2e1), SC_(0.15262925624847412109375e0), SC_(16605.418643047139063623067814083272008540956587807) }}, 
      {{ SC_(0.2e1), SC_(0.408089816570281982421875e0), SC_(327.3911893069065300460497366590889841990083098882) }}, 
      {{ SC_(0.2e1), SC_(0.6540834903717041015625e0), SC_(50.24073714927227871027454636072509051101950218415) }}, 
      {{ SC_(0.2e1), SC_(0.1097540378570556640625e1), SC_(6.5616852336268826560069305111479773650366271702116) }}, 
      {{ SC_(0.2e1), SC_(0.30944411754608154296875e1), SC_(0.31830387145238634428775905874567477304417971742745) }}, 
      {{ SC_(0.2e1), SC_(0.51139926910400390625e1), SC_(0.063403430051669078970604766527701952854238434961942) }}, 
      {{ SC_(0.2e1), SC_(0.95070552825927734375e1), SC_(0.050791697756503267541605619450228936547727403708921) }}, 
      {{ SC_(0.2e1), SC_(0.24750102996826171875e2), SC_(0.0088285027687993158359101383429936457186371674756963) }}, 
      {{ SC_(0.2e1), SC_(0.637722015380859375e2), SC_(-0.013217848733187320629471277317281588139976373991784) }}, 
      {{ SC_(0.2e1), SC_(0.1252804412841796875e3), SC_(0.0027468640217234051899448674476334240352291987005143) }}, 
      {{ SC_(0.2e1), SC_(0.25554705810546875e3), SC_(0.003476155383169156295453512402626845717328268463924) }}, 
      {{ SC_(0.2e1), SC_(0.503011474609375e3), SC_(-0.00070888293007864555913788791750119042130260317328753) }}, 
      {{ SC_(0.2e1), SC_(0.10074598388671875e4), SC_(-0.00082843368570387450128677090306415548913704194916207) }}, 
      {{ SC_(0.2e1), SC_(0.1185395751953125e4), SC_(0.00071826155681922902688738021549159055926818593480833) }}, 
      {{ SC_(0.4e1), SC_(0.177219114266335964202880859375e-2), SC_(16947123409621148414.396327196120566029578437392813) }}, 
      {{ SC_(0.4e1), SC_(0.22177286446094512939453125e-2), SC_(4412746298117679912.5476436086536482775964646698861) }}, 
      {{ SC_(0.4e1), SC_(0.7444499991834163665771484375e-2), SC_(3084232663701475.0519943611860465528405551386978695) }}, 
      {{ SC_(0.4e1), SC_(0.1433600485324859619140625e-1), SC_(60477564405179.92170204301713541728614145137832873) }}, 
      {{ SC_(0.4e1), SC_(0.1760916970670223236083984375e-1), SC_(17608882728707.981141578534325134913615099863601217) }}, 
      {{ SC_(0.4e1), SC_(0.6152711808681488037109375e-1), SC_(9678996255.1839771441306321620856494913675484946763) }}, 
      {{ SC_(0.4e1), SC_(0.11958599090576171875e0), SC_(179615421.48501730340443167583969039181659482187014) }}, 
      {{ SC_(0.4e1), SC_(0.15262925624847412109375e0), SC_(41568669.223882664831565782529582977445018981874865) }}, 
      {{ SC_(0.4e1), SC_(0.408089816570281982421875e0), SC_(114477.96557716961680908792136752397886415952361251) }}, 
      {{ SC_(0.4e1), SC_(0.6540834903717041015625e0), SC_(6828.184335714898569600465623663987348840443359789) }}, 
      {{ SC_(0.4e1), SC_(0.1097540378570556640625e1), SC_(316.14485727885901077459451396302676190870103568588) }}, 
      {{ SC_(0.4e1), SC_(0.30944411754608154296875e1), SC_(0.86884700805175975591584736561398300081460003884222) }}, 
      {{ SC_(0.4e1), SC_(0.51139926910400390625e1), SC_(0.16791724343614794946391017435502169272831744332145) }}, 
      {{ SC_(0.4e1), SC_(0.95070552825927734375e1), SC_(-0.095704132354117951696884047015921179063199913694684) }}, 
      {{ SC_(0.4e1), SC_(0.24750102996826171875e2), SC_(0.0025614398654636627528799275032206175552292334487349) }}, 
      {{ SC_(0.4e1), SC_(0.637722015380859375e2), SC_(0.014050277189012237700726804609758330581443280035659) }}, 
      {{ SC_(0.4e1), SC_(0.1252804412841796875e3), SC_(-0.0023234509847349200689104520744700113272090890159068) }}, 
      {{ SC_(0.4e1), SC_(0.25554705810546875e3), SC_(-0.003523879610076224467927951777001630682284192253819) }}, 
      {{ SC_(0.4e1), SC_(0.503011474609375e3), SC_(0.00073465071292845743625962195831270903743952799687293) }}, 
      {{ SC_(0.4e1), SC_(0.10074598388671875e4), SC_(0.00082461191446899875454063503265187280044346104603928) }}, 
      {{ SC_(0.4e1), SC_(0.1185395751953125e4), SC_(-0.00072085997549654361540688754076830641803695080048078) }}, 
      {{ SC_(0.7e1), SC_(0.177219114266335964202880859375e-2), SC_(6269931809300544116940699590991.1673813306295821924) }}, 
      {{ SC_(0.7e1), SC_(0.22177286446094512939453125e-2), SC_(833071430758282573598847830427.1462475729803075624) }}, 
      {{ SC_(0.7e1), SC_(0.7444499991834163665771484375e-2), SC_(15393547752859457176512098.671522971457196031116674) }}, 
      {{ SC_(0.7e1), SC_(0.1433600485324859619140625e-1), SC_(42267557642198837855888.673298449172582318233276608) }}, 
      {{ SC_(0.7e1), SC_(0.1760916970670223236083984375e-1), SC_(6640668593595542760912.3306065646490435296179618029) }}, 
      {{ SC_(0.7e1), SC_(0.6152711808681488037109375e-1), SC_(85566959041892747.308985816384825047029872355741195) }}, 
      {{ SC_(0.7e1), SC_(0.11958599090576171875e0), SC_(216229145925249.17165848134485154568201936796518045) }}, 
      {{ SC_(0.7e1), SC_(0.15262925624847412109375e0), SC_(24066314537187.902118217863797560429519350616827715) }}, 
      {{ SC_(0.7e1), SC_(0.408089816570281982421875e0), SC_(3460529854.7787568299307181316167037453806199793635) }}, 
      {{ SC_(0.7e1), SC_(0.6540834903717041015625e0), SC_(49948272.795036467181938073185308941665329785741192) }}, 
      {{ SC_(0.7e1), SC_(0.1097540378570556640625e1), SC_(484369.62514129555285080104036384796805436781148084) }}, 
      {{ SC_(0.7e1), SC_(0.30944411754608154296875e1), SC_(54.837158802672915438384731698389099348451871072721) }}, 
      {{ SC_(0.7e1), SC_(0.51139926910400390625e1), SC_(0.94754781148381325210517317192376522415002976700315) }}, 
      {{ SC_(0.7e1), SC_(0.95070552825927734375e1), SC_(0.083671722559645187560482129260438219356944050611185) }}, 
      {{ SC_(0.7e1), SC_(0.24750102996826171875e2), SC_(0.027485073887871070669321724373394821978066341261948) }}, 
      {{ SC_(0.7e1), SC_(0.637722015380859375e2), SC_(0.0027216038321346632217493028762480597571235134060773) }}, 
      {{ SC_(0.7e1), SC_(0.1252804412841796875e3), SC_(0.0078836327456430979211984053718622220421600727037497) }}, 
      {{ SC_(0.7e1), SC_(0.25554705810546875e3), SC_(-0.0014484535880204295829090046911393788008579243221089) }}, 
      {{ SC_(0.7e1), SC_(0.503011474609375e3), SC_(0.0018197354543610328692836972445708758260362350999138) }}, 
      {{ SC_(0.7e1), SC_(0.10074598388671875e4), SC_(-0.0005671354509298849965607462944499200849996661837342) }}, 
      {{ SC_(0.7e1), SC_(0.1185395751953125e4), SC_(-0.00042719900511763244303989310786672616575124068294238) }}, 
      {{ SC_(0.1e2), SC_(0.1433600485324859619140625e-1), SC_(95569334590310490547665753396065.485630581011609974) }}, 
      {{ SC_(0.1e2), SC_(0.1760916970670223236083984375e-1), SC_(8101970632935143040373468141961.1614487803599886415) }}, 
      {{ SC_(0.1e2), SC_(0.6152711808681488037109375e-1), SC_(2447320403938253107598367.0238782270855450452218216) }}, 
      {{ SC_(0.1e2), SC_(0.11958599090576171875e0), SC_(842217692307429796921.64634768022939397788603917475) }}, 
      {{ SC_(0.1e2), SC_(0.15262925624847412109375e0), SC_(45083611105559719379.890895780509652230356034596654) }}, 
      {{ SC_(0.1e2), SC_(0.408089816570281982421875e0), SC_(338799420893216.23300667976998655838766184112055355) }}, 
      {{ SC_(0.1e2), SC_(0.6540834903717041015625e0), SC_(1185380392378.0761326500389150088662097059453414525) }}, 
      {{ SC_(0.1e2), SC_(0.1097540378570556640625e1), SC_(2419253108.0568041517301223350638145050197146167232) }}, 
      {{ SC_(0.1e2), SC_(0.30944411754608154296875e1), SC_(11496.686647623539379667699987745884870874891816932) }}, 
      {{ SC_(0.1e2), SC_(0.51139926910400390625e1), SC_(39.882505843122200522951583426265046150519925974124) }}, 
      {{ SC_(0.1e2), SC_(0.95070552825927734375e1), SC_(0.10134506722721708188101112723001174872010128271245) }}, 
      {{ SC_(0.1e2), SC_(0.24750102996826171875e2), SC_(-0.03615971480165040723047920963347605529575829952469) }}, 
      {{ SC_(0.1e2), SC_(0.637722015380859375e2), SC_(-0.015091682204313779566268460515226613762084301432984) }}, 
      {{ SC_(0.1e2), SC_(0.1252804412841796875e3), SC_(-0.00050987397258381830920739744954249530183324704858041) }}, 
      {{ SC_(0.1e2), SC_(0.25554705810546875e3), SC_(0.0037660936392010718246231200430632175501749905084659) }}, 
      {{ SC_(0.1e2), SC_(0.503011474609375e3), SC_(-0.00089667918821657806998864566535242763832700737737864) }}, 
      {{ SC_(0.1e2), SC_(0.10074598388671875e4), SC_(-0.00079910138578807699296922378369921182187737310254249) }}, 
      {{ SC_(0.1e2), SC_(0.1185395751953125e4), SC_(0.00073695983327761704931110786498447951860388573391059) }}, 
      {{ SC_(0.13e2), SC_(0.6152711808681488037109375e-1), SC_(161475406465324656195774620777860.45114348752087396) }}, 
      {{ SC_(0.13e2), SC_(0.11958599090576171875e0), SC_(7567957349737089195234434627.2036076513892633162746) }}, 
      {{ SC_(0.13e2), SC_(0.15262925624847412109375e0), SC_(194842378662572255020235837.30458920597516186322192) }}, 
      {{ SC_(0.13e2), SC_(0.408089816570281982421875e0), SC_(76556208683346404987.444675222886447564926592097665) }}, 
      {{ SC_(0.13e2), SC_(0.6540834903717041015625e0), SC_(64977774912806073.615065792281594615553122055863648) }}, 
      {{ SC_(0.13e2), SC_(0.1097540378570556640625e1), SC_(27973236959239.368863229703649484857254804733703608) }}, 
      {{ SC_(0.13e2), SC_(0.30944411754608154296875e1), SC_(5714353.0105805758739329838905220101973439090018694) }}, 
      {{ SC_(0.13e2), SC_(0.51139926910400390625e1), SC_(4072.6241445869725648271405649406596998660917725889) }}, 
      {{ SC_(0.13e2), SC_(0.95070552825927734375e1), SC_(1.1781419093746913005730490416298516103473807036266) }}, 
      {{ SC_(0.13e2), SC_(0.24750102996826171875e2), SC_(0.035350851693509994183268554149981477249124437651868) }}, 
      {{ SC_(0.13e2), SC_(0.637722015380859375e2), SC_(0.011316279109369152837636244054427327591599282104447) }}, 
      {{ SC_(0.13e2), SC_(0.1252804412841796875e3), SC_(-0.0074714783608763518571605025418572809315981991555292) }}, 
      {{ SC_(0.13e2), SC_(0.25554705810546875e3), SC_(0.00051716668374643726010940164001381096143098478615409) }}, 
      {{ SC_(0.13e2), SC_(0.503011474609375e3), SC_(-0.0017052931215331386497332954749771947369489001322239) }}, 
      {{ SC_(0.13e2), SC_(0.10074598388671875e4), SC_(0.0006169155549699856178362917189118594026502006622466) }}, 
      {{ SC_(0.13e2), SC_(0.1185395751953125e4), SC_(0.00038794434639261437419730646557850260932478585124819) }}, 
      {{ SC_(0.16e2), SC_(0.408089816570281982421875e0), SC_(33185386446853261486801070.230210910330123571481725) }}, 
      {{ SC_(0.16e2), SC_(0.6540834903717041015625e0), SC_(6835470568046722870700.4614891060690073095966949335) }}, 
      {{ SC_(0.16e2), SC_(0.1097540378570556640625e1), SC_(621441716218617767.84152114888523148553710116679324) }}, 
      {{ SC_(0.16e2), SC_(0.30944411754608154296875e1), SC_(5526203853.236300957077761822495538587336676266305) }}, 
      {{ SC_(0.16e2), SC_(0.51139926910400390625e1), SC_(829862.94107750384911044644265371489009195217055412) }}, 
      {{ SC_(0.16e2), SC_(0.95070552825927734375e1), SC_(30.609940174446549564196771650745440003858854449466) }}, 
      {{ SC_(0.16e2), SC_(0.24750102996826171875e2), SC_(-0.026741537190994808474105214986187781084014688035442) }}, 
      {{ SC_(0.16e2), SC_(0.637722015380859375e2), SC_(0.00061636705374266507409137630649764014163912498697507) }}, 
      {{ SC_(0.16e2), SC_(0.1252804412841796875e3), SC_(0.0051923022051981351026579935579611644367025679951769) }}, 
      {{ SC_(0.16e2), SC_(0.25554705810546875e3), SC_(-0.0039054148417072096780522366457866824176204102586632) }}, 
      {{ SC_(0.16e2), SC_(0.503011474609375e3), SC_(0.0011693730945465066827471237062837882471877319543766) }}, 
      {{ SC_(0.16e2), SC_(0.10074598388671875e4), SC_(0.00074920348302254259453538742554999639810762692979212) }}, 
      {{ SC_(0.16e2), SC_(0.1185395751953125e4), SC_(-0.00076324802087813065849605848672773859281577048993731) }}, 
      {{ SC_(0.19e2), SC_(0.408089816570281982421875e0), SC_(24541138152391626418974046979647.260724469901234503) }}, 
      {{ SC_(0.19e2), SC_(0.6540834903717041015625e0), SC_(1227012559534751954853715706.7498104757909312853684) }}, 
      {{ SC_(0.19e2), SC_(0.1097540378570556640625e1), SC_(23573276998725208750649.076031026802444611621660603) }}, 
      {{ SC_(0.19e2), SC_(0.30944411754608154296875e1), SC_(9191097039840.5066270705773556794263246660681541894) }}, 
      {{ SC_(0.19e2), SC_(0.51139926910400390625e1), SC_(295151300.45822190557517187582797695675185015573883) }}, 
      {{ SC_(0.19e2), SC_(0.95070552825927734375e1), SC_(1463.6337051957242181290806493113591830904550451293) }}, 
      {{ SC_(0.19e2), SC_(0.24750102996826171875e2), SC_(-0.0010795804245368699920178461970126691925533343183845) }}, 
      {{ SC_(0.19e2), SC_(0.637722015380859375e2), SC_(-0.010452801110670000533980623877585025355791409823744) }}, 
      {{ SC_(0.19e2), SC_(0.1252804412841796875e3), SC_(0.0032802275304684732722821970259689122253998379058487) }}, 
      {{ SC_(0.19e2), SC_(0.25554705810546875e3), SC_(0.00098584270092112031776849281547291616358403316612687) }}, 
      {{ SC_(0.19e2), SC_(0.503011474609375e3), SC_(0.0014723439373154155174300996396641977435508596608136) }}, 
      {{ SC_(0.19e2), SC_(0.10074598388671875e4), SC_(-0.00069019291602374048365952142942178402068739475845329) }}, 
      {{ SC_(0.19e2), SC_(0.1185395751953125e4), SC_(-0.00032409108737135170951216603873736450431694974844375) }}, 
      {{ SC_(0.22e2), SC_(0.1097540378570556640625e1), SC_(1407226726557166123769148577.315995383769516606577) }}, 
      {{ SC_(0.22e2), SC_(0.30944411754608154296875e1), SC_(24163885826756291.139051438109440505813697737176456) }}, 
      {{ SC_(0.22e2), SC_(0.51139926910400390625e1), SC_(167459464900.8850271726174250347315707590180580131) }}, 
      {{ SC_(0.22e2), SC_(0.95070552825927734375e1), SC_(116070.60224966213815414309779785516475667062007788) }}, 
      {{ SC_(0.22e2), SC_(0.24750102996826171875e2), SC_(0.027797945793917509059791285765887542039959503334915) }}, 
      {{ SC_(0.22e2), SC_(0.637722015380859375e2), SC_(0.014679371017522516472779134301844667684641133275286) }}, 
      {{ SC_(0.22e2), SC_(0.1252804412841796875e3), SC_(-0.0078925055911411646547421600135231255257813255345855) }}, 
      {{ SC_(0.22e2), SC_(0.25554705810546875e3), SC_(0.0034239870470680690245988981574084875460343066625155) }}, 
      {{ SC_(0.22e2), SC_(0.503011474609375e3), SC_(-0.0015080560429767754688176706105954773962113685131384) }}, 
      {{ SC_(0.22e2), SC_(0.10074598388671875e4), SC_(-0.00066867889962884232929103779423574399614736718583663) }}, 
      {{ SC_(0.22e2), SC_(0.1185395751953125e4), SC_(0.00079490026255601291574413418897094197242915538176153) }}, 
      {{ SC_(0.25e2), SC_(0.30944411754608154296875e1), SC_(94442102894768910680.024720735206043075996484281897) }}, 
      {{ SC_(0.25e2), SC_(0.51139926910400390625e1), SC_(142096472247212.48355503408126537291804070236853443) }}, 
      {{ SC_(0.25e2), SC_(0.95070552825927734375e1), SC_(14122108.608023324428730398138412671933112735690223) }}, 
      {{ SC_(0.25e2), SC_(0.24750102996826171875e2), SC_(0.02530280750856796478285744397341610753702496869112) }}, 
      {{ SC_(0.25e2), SC_(0.637722015380859375e2), SC_(-0.014830479720701612263239520633836378787802190495477) }}, 
      {{ SC_(0.25e2), SC_(0.1252804412841796875e3), SC_(0.004826574566401920172821920798403438100552939915444) }}, 
      {{ SC_(0.25e2), SC_(0.25554705810546875e3), SC_(-0.0027563879897102987392536646812028895771662380537496) }}, 
      {{ SC_(0.25e2), SC_(0.503011474609375e3), SC_(-0.0010652608276927636214698102292182547871203833535388) }}, 
      {{ SC_(0.25e2), SC_(0.10074598388671875e4), SC_(0.00077924805219165341461110112572095891175585945722729) }}, 
      {{ SC_(0.25e2), SC_(0.1185395751953125e4), SC_(0.00023347176911095218453052105990226900602895765683567) }}, 
      {{ SC_(0.28e2), SC_(0.30944411754608154296875e1), SC_(523676704932417962534455.7001243389688653671806964) }}, 
      {{ SC_(0.28e2), SC_(0.51139926910400390625e1), SC_(171775375463889204.51714565089393764860871598005159) }}, 
      {{ SC_(0.28e2), SC_(0.95070552825927734375e1), SC_(2490795745.3588680615056191373641298040704545554582) }}, 
      {{ SC_(0.28e2), SC_(0.24750102996826171875e2), SC_(0.11376033210035194143390710020575632109908472308496) }}, 
      {{ SC_(0.28e2), SC_(0.637722015380859375e2), SC_(0.013571666738045877818142926985833116840803320976781) }}, 
      {{ SC_(0.28e2), SC_(0.1252804412841796875e3), SC_(0.0020374133219389774259188086124157737680781267309472) }}, 
      {{ SC_(0.28e2), SC_(0.25554705810546875e3), SC_(-0.0017638787872699876815322943583045326349805846545947) }}, 
      {{ SC_(0.28e2), SC_(0.503011474609375e3), SC_(0.0018258930364257111589782503689303596260233463643597) }}, 
      {{ SC_(0.28e2), SC_(0.10074598388671875e4), SC_(0.00054997632338763670771322584901996602845303740891394) }}, 
      {{ SC_(0.28e2), SC_(0.1185395751953125e4), SC_(-0.00082457475739516976245217525478503692714141665528159) }}, 
      {{ SC_(0.31e2), SC_(0.30944411754608154296875e1), SC_(3970746879879725612852002211.3008142475856599691227) }}, 
      {{ SC_(0.31e2), SC_(0.51139926910400390625e1), SC_(284806844504869745753.23646640751111977809634183519) }}, 
      {{ SC_(0.31e2), SC_(0.95070552825927734375e1), SC_(610046694656.75081203701779864303606119663741637543) }}, 
      {{ SC_(0.31e2), SC_(0.24750102996826171875e2), SC_(0.95296785976594259478491051314047520502180468054736) }}, 
      {{ SC_(0.31e2), SC_(0.637722015380859375e2), SC_(-0.012720968683891519869148250762703358232130778175117) }}, 
      {{ SC_(0.31e2), SC_(0.1252804412841796875e3), SC_(-0.0070231721905715713018546838261872961498581716219124) }}, 
      {{ SC_(0.31e2), SC_(0.25554705810546875e3), SC_(0.0038719798476019066584161436067692123071912905558847) }}, 
      {{ SC_(0.31e2), SC_(0.503011474609375e3), SC_(0.00044459517686614220621065899960074934099072432868618) }}, 
      {{ SC_(0.31e2), SC_(0.10074598388671875e4), SC_(-0.00087180170307037085310646740491069138296393805620655) }}, 
      {{ SC_(0.31e2), SC_(0.1185395751953125e4), SC_(-0.00011450691152737474727669151431134117248862807321291) }}, 
      {{ SC_(0.34e2), SC_(0.51139926910400390625e1), SC_(628196639540663747460191.18075249978715454819884768) }}, 
      {{ SC_(0.34e2), SC_(0.95070552825927734375e1), SC_(200586725827238.63801309999724730702233286327908808) }}, 
      {{ SC_(0.34e2), SC_(0.24750102996826171875e2), SC_(11.576621429054439101522453005642552739184662423756) }}, 
      {{ SC_(0.34e2), SC_(0.637722015380859375e2), SC_(0.012928706452787899422827174136271220541197310870771) }}, 
      {{ SC_(0.34e2), SC_(0.1252804412841796875e3), SC_(0.0074603783377430373663026923194367569830154868079915) }}, 
      {{ SC_(0.34e2), SC_(0.25554705810546875e3), SC_(-0.0010476997568844404072565064628063000006608283344556) }}, 
      {{ SC_(0.34e2), SC_(0.503011474609375e3), SC_(-0.0019848644537011134040914838474027260139199264240683) }}, 
      {{ SC_(0.34e2), SC_(0.10074598388671875e4), SC_(-0.00038620003079814067892297634189159874101109679099872) }}, 
      {{ SC_(0.34e2), SC_(0.1185395751953125e4), SC_(0.00084225289767639072109427209903301223539192016010217) }}, 
      {{ SC_(0.37e2), SC_(0.51139926910400390625e1), SC_(1797632848344951251152892052.0196618901146446222497) }}, 
      {{ SC_(0.37e2), SC_(0.95070552825927734375e1), SC_(86159351972900343.592456351130306564972022471761587) }}, 
      {{ SC_(0.37e2), SC_(0.24750102996826171875e2), SC_(198.35197649315515480666754289362082898900791193621) }}, 
      {{ SC_(0.37e2), SC_(0.637722015380859375e2), SC_(-0.01375760705330807345614565402717351018943495443364) }}, 
      {{ SC_(0.37e2), SC_(0.1252804412841796875e3), SC_(-0.0041905499044392954566391608456503090018828563845449) }}, 
      {{ SC_(0.37e2), SC_(0.25554705810546875e3), SC_(-0.0029858319282128829161898140770519378104557139633838) }}, 
      {{ SC_(0.37e2), SC_(0.503011474609375e3), SC_(0.00036729094524412051401273989003740717062980060688245) }}, 
      {{ SC_(0.37e2), SC_(0.10074598388671875e4), SC_(0.0009500972788255472138682524359586249966818084124897) }}, 
      {{ SC_(0.37e2), SC_(0.1185395751953125e4), SC_(-3.2437022159506601767869761333307203620580135563454e-05) }}, 
      {{ SC_(0.4e2), SC_(0.95070552825927734375e1), SC_(47268796561654091913.21885247386040117659682095943) }}, 
      {{ SC_(0.4e2), SC_(0.24750102996826171875e2), SC_(4606.7040142147850792803020694047494400748211653216) }}, 
      {{ SC_(0.4e2), SC_(0.637722015380859375e2), SC_(0.013562004570933124279517274139642462528686206440721) }}, 
      {{ SC_(0.4e2), SC_(0.1252804412841796875e3), SC_(-0.00041588274991310711126081297665967636013857745446983) }}, 
      {{ SC_(0.4e2), SC_(0.25554705810546875e3), SC_(0.0035586883403878123477844058879369697437673947133221) }}, 
      {{ SC_(0.4e2), SC_(0.503011474609375e3), SC_(0.0018131766439672851611563109699327051006611199062371) }}, 
      {{ SC_(0.4e2), SC_(0.10074598388671875e4), SC_(0.00017408878243352074794695364554566820276448376006598) }}, 
      {{ SC_(0.4e2), SC_(0.1185395751953125e4), SC_(-0.00083543030218971769025179620317949596324571402640036) }}, 
      {{ SC_(0.43e2), SC_(0.95070552825927734375e1), SC_(32500360104264727046308.146495002237236714938536775) }}, 
      {{ SC_(0.43e2), SC_(0.24750102996826171875e2), SC_(140319.86563844375643251793350654568289049492610375) }}, 
      {{ SC_(0.43e2), SC_(0.637722015380859375e2), SC_(-0.0096267376340265225211094817925940133954153703370664) }}, 
      {{ SC_(0.43e2), SC_(0.1252804412841796875e3), SC_(0.0043560140881858073888809144573238039949661594523397) }}, 
      {{ SC_(0.43e2), SC_(0.25554705810546875e3), SC_(-0.00031253687873517078281423720249041760336117120554213) }}, 
      {{ SC_(0.43e2), SC_(0.503011474609375e3), SC_(-0.0012317584023837640987228434293712078936100004695316) }}, 
      {{ SC_(0.43e2), SC_(0.10074598388671875e4), SC_(-0.00099082942818446734158567078312933705353358708741562) }}, 
      {{ SC_(0.43e2), SC_(0.1185395751953125e4), SC_(0.00020332834519802191669450520654038153178180499044216) }}, 
      {{ SC_(0.46e2), SC_(0.95070552825927734375e1), SC_(27556304081722380191469757.839963090281115024955617) }}, 
      {{ SC_(0.46e2), SC_(0.24750102996826171875e2), SC_(5460360.0519125590046811338199739390242963769551275) }}, 
      {{ SC_(0.46e2), SC_(0.637722015380859375e2), SC_(0.00021996313581805877547109053676243264229609448401546) }}, 
      {{ SC_(0.46e2), SC_(0.1252804412841796875e3), SC_(-0.0067365807847722924728078569602308485680548138850523) }}, 
      {{ SC_(0.46e2), SC_(0.25554705810546875e3), SC_(-0.0031769931861025285948261739916321991464748792623825) }}, 
      {{ SC_(0.46e2), SC_(0.503011474609375e3), SC_(-0.0011724931458855457146611059405688017528264086757474) }}, 
      {{ SC_(0.46e2), SC_(0.10074598388671875e4), SC_(8.2027027876290107562817318212946635139688618895064e-05) }}, 
      {{ SC_(0.46e2), SC_(0.1185395751953125e4), SC_(0.00078998332674918935235701582203886128179169986861445) }}, 
      {{ SC_(0.49e2), SC_(0.95070552825927734375e1), SC_(28412334702306431778126338444.792912175084092172461) }}, 
      {{ SC_(0.49e2), SC_(0.24750102996826171875e2), SC_(265743930.09679637876869531571415436007800862296168) }}, 
      {{ SC_(0.49e2), SC_(0.637722015380859375e2), SC_(0.010319339492941490779460494055534452117308684781928) }}, 
      {{ SC_(0.49e2), SC_(0.1252804412841796875e3), SC_(0.0076023313546937034353429580343679917714310757786706) }}, 
      {{ SC_(0.49e2), SC_(0.25554705810546875e3), SC_(0.0035815143137077770928448016540062474995877646721405) }}, 
      {{ SC_(0.49e2), SC_(0.503011474609375e3), SC_(0.001865913325873840877319056345281514118241157845756) }}, 
      {{ SC_(0.49e2), SC_(0.10074598388671875e4), SC_(0.00096682247432286716385438217247828581211359653422397) }}, 
      {{ SC_(0.49e2), SC_(0.1185395751953125e4), SC_(-0.000388586899659198186891519102479531432041130568781) }}, 
      {{ SC_(0.52e2), SC_(0.24750102996826171875e2), SC_(15893157275.122226566220557959269076490453909124079) }}, 
      {{ SC_(0.52e2), SC_(0.637722015380859375e2), SC_(-0.0096302473159184929027710000066333144170253616671895) }}, 
      {{ SC_(0.52e2), SC_(0.1252804412841796875e3), SC_(-0.0074545924357825301642459217582531271544134872343904) }}, 
      {{ SC_(0.52e2), SC_(0.25554705810546875e3), SC_(-0.00080879003330325323340905178789863734480124495245469) }}, 
      {{ SC_(0.52e2), SC_(0.503011474609375e3), SC_(8.1151143271151726667386346137720286207720626052118e-05) }}, 
      {{ SC_(0.52e2), SC_(0.10074598388671875e4), SC_(-0.00036580236943768612394106051133591541539471447114889) }}, 
      {{ SC_(0.52e2), SC_(0.1185395751953125e4), SC_(-0.00069206098677479164879794530096208787047403308451152) }}, 
      {{ SC_(0.55e2), SC_(0.24750102996826171875e2), SC_(1150881378498.7240629877032734540893043377259132461) }}, 
      {{ SC_(0.55e2), SC_(0.637722015380859375e2), SC_(-0.0055659330225608348472348293061912067012265452045085) }}, 
      {{ SC_(0.55e2), SC_(0.1252804412841796875e3), SC_(0.0068584055909589623364730635647768170037383432049856) }}, 
      {{ SC_(0.55e2), SC_(0.25554705810546875e3), SC_(-0.0025538479374245016450395329559033991854018544546084) }}, 
      {{ SC_(0.55e2), SC_(0.503011474609375e3), SC_(-0.0019038095539531314565983259165272087953657428209132) }}, 
      {{ SC_(0.55e2), SC_(0.10074598388671875e4), SC_(-0.00085143692817422231458849750249354253316300952418448) }}, 
      {{ SC_(0.55e2), SC_(0.1185395751953125e4), SC_(0.00057146982680160633443321926900816730867828953472445) }}, 
      {{ SC_(0.58e2), SC_(0.24750102996826171875e2), SC_(99637458504766.599402951818228283069038577281703857) }}, 
      {{ SC_(0.58e2), SC_(0.637722015380859375e2), SC_(0.0074840655605533504647638493963517423653208741540798) }}, 
      {{ SC_(0.58e2), SC_(0.1252804412841796875e3), SC_(-0.0062490466609213366120682904454197041049780262693866) }}, 
      {{ SC_(0.58e2), SC_(0.25554705810546875e3), SC_(0.0038566950072613874190636282359231797446877949977414) }}, 
      {{ SC_(0.58e2), SC_(0.503011474609375e3), SC_(0.0011551017762500538777915940155070123096067942509318) }}, 
      {{ SC_(0.58e2), SC_(0.10074598388671875e4), SC_(0.00064525769298951483096139687718953092418554627173474) }}, 
      {{ SC_(0.58e2), SC_(0.1185395751953125e4), SC_(0.00053126211182582456060109092817573149262252147893062) }}, 
      {{ SC_(0.61e2), SC_(0.24750102996826171875e2), SC_(10200415357676638.644750361795135145594072603652636) }}, 
      {{ SC_(0.61e2), SC_(0.637722015380859375e2), SC_(0.0086628300233647818111928402843048524079382068716092) }}, 
      {{ SC_(0.61e2), SC_(0.1252804412841796875e3), SC_(0.0058886800403071930616493809170602939043259848676386) }}, 
      {{ SC_(0.61e2), SC_(0.25554705810546875e3), SC_(-0.0023768899546913911289426595387509086740790442673056) }}, 
      {{ SC_(0.61e2), SC_(0.503011474609375e3), SC_(0.0011013576751210479703859408863272805380257648486171) }}, 
      {{ SC_(0.61e2), SC_(0.10074598388671875e4), SC_(0.00062634433378004345030784518155685543112952577014323) }}, 
      {{ SC_(0.61e2), SC_(0.1185395751953125e4), SC_(-0.0007274509061559619351949711918452106349817721397035) }},
   }};



