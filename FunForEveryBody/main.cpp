/*	Facesnuffer - 
	Brad.Antoniewicz@foundstone.com

	CSAW CTF 2013 Challenge
	-------------------------------

	Button Numbering:
		1	|	3	|	5	|	7
	----------------------------------
		2	|	4	|	6	|	8

	Solution: 
		Reveal key by reversing out the click order:
			1. Click button 1 three times
			2. Click button 2
			3. Click button 4
			4. Click button 7
			5. Click button 5 

		Key is KEY{Kevin has moist cheeks}

*/
		


#include <afxwin.h>
#include <wincrypt.h>
#include "resource.h"
#include "afxext.h"




class FaceSnuffer {

public:
	FaceSnuffer() {
		clickCount = 0;
		b1sel = FALSE;
		b2sel = FALSE;
		b3sel = FALSE;
		b4sel = FALSE;
		b5sel = FALSE;
		b6sel = FALSE;
		b7sel = FALSE;
		b8sel = FALSE;
		k1 = FALSE;
		k2 = FALSE;
		k3 = FALSE;
		k4 = FALSE;
		k5 = FALSE;
		k6 = FALSE;
		k7 = FALSE;
		k8 = FALSE;
		k0 = FALSE;
		nameNum=0;
		adjNum=0;
		nounNum=0;
		setStatus();
		setKey();
	}
	~FaceSnuffer() { };

	void incrementClickCount() {
		if (clickCount <=256 ) {
			clickCount++;
		} else {
			clickCount = 0;
		}
	}
	void decrementClickCount() {
		if (clickCount > 0) {
			clickCount--;
		} else {
			clickCount = 0;
		}
	}

	unsigned int getClickCount() {
		return clickCount;
	}

	void b1Check() { // 1. Click this 3 times
		if ( getClickCount() == 1 ) {
			bullshitFunc1();
			k1 = FALSE;
		} else if ( getClickCount() == 2 ) {
			bullshitFunc1();
			k1 = FALSE;
		} else if ( getClickCount() == 3 ) { // Good Case
			if (!(k2 || k3 || k4 || k5 || k6 || k7))
				setK1True(); 
		} else 	if ( getClickCount() >= 5 && getClickCount() !=828 ) { 
			bullshitFunc1(); 
			adjNum+=9; 
			nounNum+=3;
			nameNum+=11;
			k1 = FALSE;
		} else { 
			bullshitFunc1();
			nameNum++;
			k1 = FALSE;
		}
		k0 = FALSE; 
	}


	void b2Check() {
		if (getClickCount() == 1) { 
			bullshitFunc1(); 
			adjNum+=2; 
		} else if (getClickCount() == 2) { 
			bullshitFunc1(); 
			adjNum+=2; 
		} else if (getClickCount() == 3) { 
			bullshitFunc1(); 
			adjNum+=4; 
			nounNum+=3;
			k2 = FALSE;
		} else if (getClickCount() == 4) { // 2. click this
			bullshitFunc1();
			setK2True(); 
		} else if (getClickCount() >= 5) { 
			bullshitFunc1(); 
			adjNum+=3; 
			nounNum+=6;
			nameNum+=5;
			k2 = FALSE;
		} else {
			k2 = FALSE;
			adjNum+=3; 
		}
		k0 = FALSE; 
	}
	void b3Check() {
		if (getClickCount() == 2) {
			bullshitFunc1();
			setK3True(); 
		} else if (getClickCount() == 121 ) {
			bullshitFunc1();
			setK3True(); 
		} else if (getClickCount() > 3 ) {
			k3 = FALSE;
			nounNum +=31;
			nameNum+=7; 
		} else {
			k3 = FALSE;
		}
		k0 = FALSE; 
	}
	void b4Check() {
		if (getClickCount() == 5) { // 3. click this  
			bullshitFunc1();
			setK4True(); 
		} else if (getClickCount() == 3) {
			bullshitFunc1();
			setK8True(); 
		} else {
			k4 = FALSE;
			adjNum+=11;
			nounNum+=7;
			nameNum+=3;
		}
		k0 = FALSE; 
	}
	void b5Check() {
		if (getClickCount() == 7 ) { // 5. click this
			bullshitFunc1();
			setK5True(); 
			setK0();
			bullshitFunc3();
		} else {
			k5 = FALSE;
			nameNum++;
		}
	}
	void b6Check() {
		if (getClickCount() == 8) { 
			bullshitFunc1();
			setK6True();  
		} else if (getClickCount() > 3 ) {
			k6 = FALSE;
			nounNum+=3;
			nameNum+=15;
		} else {
			k6 = FALSE;
		}
		k0 = FALSE; 
	}
	void b7Check() {
		if (getClickCount() == 6 ) { // 4. click this
			bullshitFunc2();
			setK7True(); 
		} else if (getClickCount() > 3 ) {
			k7 = FALSE;
			nameNum+=11;
			adjNum+=2;
		} else {
			k7 = FALSE;
		}
		k0 = FALSE; 
	}
	void b8Check() {
		if (getClickCount() == 3) {
			bullshitFunc1();
			setK8True(); 
		} else if (getClickCount() > 3 ) {
			k8 = FALSE;
			adjNum+=22;
			nameNum+=5;
		} else {
			k8 = FALSE;
		}
		k0 = FALSE; 
	}
	void setStatus() {
		if (k1) s = _T(" "); else s = _T(" not ");
		if (k2) s = _T(" "); else s = _T(" not ");
		if (k3) s = _T(" "); else s = _T(" not ");
		if (k4) s = _T(" "); else s = _T(" not ");
		if (k5) s = _T(" "); else s = _T(" not ");
		if (k6) s = _T(" "); else s = _T(" not ");
		if (k7) s = _T(" "); else s = _T(" not ");
		if (k8) s = _T(" "); else s = _T(" not ");
		if (k9) s = _T(" "); else s = _T(" not ");
		if (k0) s = _T(" "); else s = _T(" not ");
	}
	void setKey() {
		CString name[] = {"Brad","Johnny","Barbie","Kevin","Rocky","Scrapy","Julian","Jacob","Manson","Sophia","Emma","Noah","William","Isabella","Olivia","Liam","Emily","Abigail","Mia","Madison","Jayden","Michael","Alexander","Aiden","Elizabeth","Joshua","Daniel","Christopher","Andrew","Ethan","Joseph","Ryan","Tyler","James","John","Jonathan","Noah","Brandon","Christian","Dylan","Samuel","Benjamin","Nathan","Zachary","Logan","Justin","Gabriel","Jose","Austin","Jasmine","Hailey","Victoria","Morgan","Thomas","Jordan","Cameron","Jack","Hunter","Isaiah","Mason","Luke","Jason","Gavin","Aidan","Charles","Adam","Lucas","Brian","Eric","Carlos","Nathaniel","Sean","Landon","Julian","Cole","Jeremiah","Timothy","Evelyn","Audrey","Caroline","Michelle","Hayden","Devin","Richard","Seth","Patrick","Tristan","Trevor","Caden","Kenneth","Laura","Margaret","Cheyenne","Miranda","Courtney","Mckenzie","Rylee","Jordyn","Edward","Crystal","Erica","Ivan","Eduardo","Julius","Wilford","Ignacio","Norris","Sanford","Newton","Darren","Stephan","Graham","Sal","Arturo","Abraham","Brain","Garth","Heriberto","Chet","Shirley","Oliver","Gus","Gilberto","Denver","Werner","Seth","Alphonso","Faustino","Jerrod","Luciano","Elias","Frederick","Mario","Darrin","Odell","Austin","Teddy","Lucio","Lyle","Anton","Rosendo","Lowell","Vincenzo","Patricia","Benton","Erasmo","Abel","Lindsay","Harvey","Leroy","Randolph","Dominic","Quincy","Blair","Lavern","Bart","Mitchell","Aurelio","Francesco","Minh","Leland","Jerrell","Hiram","Everett","Clarence","Nicky","Waylon","Malik","Philip","Fausto","Howard","Gayle","Oren","Darryl","Darell","Buford","Jesse","Ivan","Shane","Gerardo","Manuel","Barney","Jeromy","Hobert","Danial","Morgan","Bennett","Alfonzo","Rex","Monty","Royal","Jayson","Adolfo","Zachery","Armand","Sandy","Antony","Joe","Taylor","Rusty","Monte","Maynard","Zachariah","Winford","Patrick","Jon","Cleo","Warner","Darrell","Raphael","Fermin","Ruben","Lesley","Reynaldo","Paris","Moshe","Mac","Lorenzo","Courtney","Winfred","Charlie","Wes","Marion","Whitney","Lamar","Jackson","Florentino","Avery","Derrick","Hollis","Keven","Buddy","Rhett","Pat","Burton","Elmer","Edmond","Judson","Cristopher","Armando","Trinidad","Jonathan","Lewis","Homer","Cary","Dewayne","Fredric","Anderson","Dick","Lou","Jackie","Rodney","Tuan","Orlando","Omar","Ron","Sherwood","Herschel","Emmitt","Frank","Alexander","Johnathan","Titus","Jacob","Shayne","Kevin","Manual","Cecil","Curtis","Mary","Herbert","Tracy","Alphonse","Rolf","Paul","Ahmed","Eric","Cristobal","Jere","Bertram","Korey","Mel","Linwood","Augustine","Deandre","Warren","Eduardo","Kurt","Joseph","Cliff","Jay","Jamar","Irving","Archie","Casey","Aldo","Joaquin","Josh","Dexter","Dewey","Dannie","Mauro","Elijah","Percy","Peter","Corey","Gerard","Martin","Bryon","Norberto","Tommy","Wallace","Daron","Odis","Zack","Daren","Isiah","Charles","Ty","Britt","Glenn","Phillip","Lon","Erick","Connie","Alvaro","Burt","Johnny","Normand","Rodolfo","Mariano","Felton","Dusty","Al","Hugo","Esteban","Chance","Earle","Joshua","Mitch","Elroy","Willie","Fred","Rodger","Rod","Clair","Dirk","Jeff","Emilio","Lester","Frankie","Milo","Erich","Rodrigo","Franklin","Xavier","Man","Williams","Cyril","Nolan","Freeman","Cole","Christopher","Trent","Carey","Fredrick","Zackary","Leslie","Terrance","Ronny","Ismael","Kermit","Roosevelt","Vance","Gregorio","Harold","Milton","Sydney","Teodoro","Lionel","Robt","Thad","Jonah","Aron","Kennith","Shon","Bradly","Ernesto","Frederic","Randall","Vicente","Amado","Jimmie","Travis","Thanh","Scot","Joey","Micah","Jesus","Damion","Aaron","Joesph","Myles","Thaddeus","Ferdinand","Rayford","Fidel","Quinn","Dominick","Jamey","Mark","Dana","Jacques","Kyle","Rudolf","Milford","Carson","Weldon","Anthony","Freddy","Jessie","Mckinley","Sam","Melvin","Mohammad","Carlton","Steven","Sol","Vernon","Ellis","Junior","Sebastian","Matthew","Del","Antoine","Moses","Reggie","Rudy","Wade","Matt","Antonio","Douglas","Danny","Parker","Roderick","Jasper","Cornell","Evan","Terrell","Shannon","Fernando","Elliott","Forest","Edwin","Clement","Eliseo","Mose","Nathanael","Kelly","Elliot","Spencer","Emory","Ronnie","Deshawn","Dean","Rashad","Sammie","Jerry","Ollie","Neil","Garfield","Clemente","Chadwick","Brett","Saul","Gil","Greg","Herb","Gale","Gregg","Kieth","Trevor","Chuck","Jude","Wm","Quintin","Donny","Mikel","Walton","Stanley","Carroll","Buck","Fletcher","Arlie","Kristofer","Hershel","Leonardo","Jimmy","Enrique","Eli","Miles","Stephen","Rocco","Wilton","Dewitt","Wilmer","Jorge","Alden","Ryan","Julian","Russ","Margarito","Mack","Houston","Moises","Marcelo","Troy","Bernard","Wally","Kurtis","Clyde","Cory","Devon","Jerald","Rigoberto","Angelo","Damien","Arron","Dion","Daryl","Bennie","Dino","Emile","Isidro","Robbie","Booker","Laverne","Nestor","Ken","Morton","Young","Noe","Ambrose","Jody","Grover","Josef","Dorsey","Trenton","Lucas","Tony","Felix","Barton","Darrick","Kenneth","Carmine","Lyndon","Gaylord","Winston","Hong","Elden","Doyle","Darrel","Jeremiah","Antwan","Lenny","Buster","Solomon","Allen","Keenan","Omer","Kenny","Bill","Bryant","German","Augustus","Virgilio","Marlon","Larry","Donovan","Andre","Gilbert","Ted","Santiago","Jake","Jarod","Elvis","Santo","Ezequiel","Randy","Lauren","Terry","Edward","Ray","Tyron","Domenic","Johnathon","Rolland","Raleigh","Florencio","Dario","Francisco","Jean","Damon","Diego","Rico","Ahmad","Olin","Maria","Brian","Noel","Emil","Lenard","Lemuel","Tim","Huey","Art","Prince","Emmanuel","Hilton","Preston","Stan","Roman","Adam","Graig","Zane","Marcos","Leonel","Wilfred","Luigi","Elton","Miguel","Vaughn","Alton","Oscar","Murray","Lee","Ernest","Grady","Jarvis","Joan","Edison","Ulysses","Bert","Bradley","George","Pasquale","Russel","Gino","Carlos","Ross","Lamont","Otha","Shaun","Truman","Rey","Joel","Merle","Antonia","Dan","Laurence","Garry","Haywood","Dylan","Kendrick","Adrian","Gregory","Marcellus","Richard","Bo","Pete","Filiberto","Leopoldo","Christoper","Leon","Valentine","Carl","Clifton","Horace","Timmy","Basil","Leif","Eloy","Lino","Lyman","Brock","Tobias","Karl","Lucien","Kareem","Delbert","Bernie","Raymond","Garret","Emerson","Ira","Nelson","Brendon","Renato","Marvin","Jaime","Lawrence","Derek","Berry","Morris","Napoleon","Merlin","Ramiro","Ned","Calvin","Dong","Marquis","Willard","Millard","Reinaldo","Clay","Marco","Rafael","Kerry","Eldon","Columbus","Raul","Erik","Alonzo","Sonny","Ralph","Edwardo","Jerold","Dave","Myron","Duane","Johnnie","Foster","Adolph","Oswaldo","Reginald","Arnold","Kory","Geoffrey","Isreal","Domingo","Fritz","Garland","Lynwood","Abe","Rob","Lloyd","Andrew","Jewell","Geraldo","Albert","Andy","Wilfredo","Allan","Blake","Alonso","Gary","August","Francis","Michale","Isaac","Victor","Lacy","Julio","Jefferson","Aubrey","Wesley","Wayne","Cameron","Merrill","Gabriel","Cruz","Bernardo","Carter","Daniel","Dillon","Len","Jacinto","Kristopher","Marshall","Roland","Cody","Shelton","Dante","Stuart","Darius","Jc","Leandro","Rubin","Rene","Micheal","Antone","Ed","Giuseppe","Genaro","Claud","Yong","Scotty","Tyrell","Toby","Landon","Darnell","Rich","Ian","Markus","Tod","Van","Lupe","Pablo","Lindsey","Stefan","Arnoldo","Elmo","Hector","Robin","Norman","Dee","Mervin","Denny","Major","Federico","Ronald","Waldo","Dominique","Todd","Theo","Michal","Reyes","Toney","Kirby","Isaias","Rickie","Coleman","Lucius","Bradford","Malcolm","Jonas","Hassan","Kenton","Drew","Nathanial","Felipe","Harry","Sidney","Scott","Sammy","Arnulfo","Marty","Vince","Jeremy","Bryce","Gordon","Neville","Eusebio","Vincent","Willis","Roberto","Ezra","Jamaal","Maxwell","Lonny","Renaldo","Adalberto","Branden","Ervin","Galen","Robby","Hans","Jarrod","Donald","Jarred","Jamie","Cornelius","Brendan","Orville","Barry","Dwayne","Loyd","Wilson","Cletus","Thurman","Carmen","Lazaro","Andres","Kim","Theron","Val","Brant","Doug","Mitchel","Irwin","Alberto","Jewel","Willian","Kraig","Alan","Carol","Nigel","Sung","Neal","Phil","Walter","Edgardo","Stewart","Hyman","Donte","Raymundo","Cleveland","Bobby","Noble","Robert","Colin","Herman","Guy","Gene","Leo","Timothy","Eddy","Garrett","Virgil","Abdul","Sterling","Jack","Harris","Levi","Will","Guadalupe","Hal","Rueben","John","Kris","Luis","Alva","Freddie","Danilo","Edmund","Fabian","Chi","Efrain","Justin","Stanton","Claude","Eugenio","Josue","Stanford","Lynn","Conrad","Broderick","Wilbur","Alfredo","Jordan","Antione","Marcelino","Jim","Davis","Arlen","Johnie","Ivory","Otis","Olen","Sid","Romeo","Hosea","Chung","Refugio","Osvaldo","Walker","Jerrold","Kelley","Wilber","Jerome","James","Porter","Dallas","Glen","Eddie","Alfred","Luke","Riley","Kent","Erin","Logan","Keith","Les","Chong","Tom","Blaine","Brandon","Darin","Ariel","Floyd","Barrett","Tomas","Numbers","Clayton","Gerry","Mason","Milan","Jason","Elisha","Long","Rickey","Guillermo","Jonathon","Simon","Stevie","Desmond","Emanuel","Darwin","Keneth","Kelvin","Jamison","Jeffrey","Delmer","Nick","Jose","Tracey","Franklyn","Edgar","Ellsworth","Lance","Chauncey","Sang","King","Sherman","Leigh","Cedric","Frances","Hung","Damian","Sheldon","Brenton","Earnest","Hilario","Demarcus","Chester","Kasey","Modesto","Dwain","Jed","Marcus","Jefferey","Alec","Jamal","Billy","Earl","Lane","Steve","Wilburn","Harley","Benedict","Harland","Lincoln","Rupert","Salvatore","Clark","Bryan","Douglass","Zachary","Adan","Ashley","Willy","Dalton","Theodore","Harlan","Errol","Hank","Roger","Gaston","Cortez","Jess","Von","Reuben","Tad","Lonnie","Henry","Humberto","Owen","Johnson","Byron","Carlo","Irvin","Rosario","Juan","Brad","Jordon","Rodrick","Dustin","Michel","Bobbie","Billie","Max","Gail","Rick","Ali","Brice","Clinton","Wiley","Deon","Valentin","Tory","Woodrow","Jeffery","Devin","Rolando","Mathew","Elvin","Hayden","Alfonso","Vito","Cesar","Quentin","Orval","Rufus","Elwood","Jeramy","Dane","Mohamed","Benny","Weston","Son","Horacio","Carmelo","Rudolph","Rocky","Derick","Sean","Burl","Denis","Curt","Cedrick","Javier","Ben","Rogelio","Tristan","Cordell","Amos","Nicolas","Samual","Royce","Alejandro","Chris","Hugh","Coy","Donnell","Tommie","Terence","Terrence","Chang","Kendall","Erwin","Gonzalo","Tyson","Mickey","Mike","Maximo","Brady","Harrison","Malcom","Clifford","Elbert","Colby","Bruce","Asa","Deangelo","Wilbert","Mauricio","Donn","Scottie","Quinton","Marcel","Gerald","Wyatt","Isaiah","Hubert","Dale","Everette","Hoyt","Sergio","Leonard","Josiah","Roscoe","Andreas","Ethan","Edmundo","Perry","Raymon","Porfirio","Bud","Lanny","Issac","Angel","Bob","Grant","Miquel","Pierre","Jules","Benito","Reid","Russell","Seymour","Vern","Jermaine","Shelby","Nathaniel","Jarrett","Boris","Nicholas","Stacey","Luther","Ricardo","Cyrus","Emmett","Jamel","Santos","Craig","Michael","Dwight","Duncan","David","Israel","Tyree","Marc","Charley","Hunter","Ward","Chad","Rory","Delmar","Anibal","Agustin","Arthur","Boyce","Randell","Octavio","Nickolas","Louie","Benjamin","Maurice","Heath","Gustavo","Tanner","Mohammed","Lawerence","Ernie","Samuel","Dennis","Colton","Randal","Collin","Donnie","William","Jame","Dorian","Gavin","Roy","Ike","Emery","Shad","Wendell","Alvin","Abram","Demetrius","Monroe","Brooks","Noah","Pedro","Eldridge","Stacy","Tyrone","Bret","Ezekiel","Marlin","Sylvester","Christian","Jan","Granville","Jospeh","Bruno","Brent","Beau","Alexis","Boyd","Darron","Silas","Louis","Clint","Salvador","Don","Chase","Thomas","Palmer","Ramon","Jeffry","Nathan","Enoch","Trey","Jae","Andrea","Otto","Reed","Alex","Dudley","Caleb","Carrol","Claudio","Efren","Jared","Loren","Richie","Chas","Giovanni","Arden","Kirk","Hipolito","Forrest","Ricky","Kip","Tyler","Hai","Shawn","Eugene","Norbert"};
		CString adj[] = {"crappy","sexy","sloppy","moist","funny", "flamboyant", "smelly","battered","magnificent","studious","shiny","well-made","tiny","huge","large","shapeless","young","round","antique","old","teenaged","elongated","handsome","healthy","narrow","tasteless","tender","tight","beautiful","charming","jolly","juicy","strange","wicked","sticky","yummy","colossal","damp","dangerous","deep","fair","hilarious","nutty","nice","naughty","scrawny","shaggy","heavy","salty","terrible","tight","uneven","vivacious","fat","exuberant","bumpy","ordinary","stale","petite","gigantic","yummy","miniature","disturbed","average","silky","ancient","icy","itchy","jolly","loose","lovely","prickly","splendid","spicy","watery","uneven","ripe","repulsive","sweet","awful","fantastic","orange","little","chilly","confused","strong","deep","good","warm","lucious","tasty","fierce","bitter","sour","blue","stale","witty","wonderful","yellow","flaky","flat","fluffy","frail","bordello","uproar","willow","tenured","stung","phylogen","undeceive","germ","pickaback","descent","collagen","gunman","panegyric","quadrennium","grot","herringbone","faro","intermeddle","interweave","receive","seigneur","deadline","bluet","philippic","absolution","eccentric","grammar","bosh","full","extensive","green","highborn","tide","seduce","veranda","centurion","slacker","can","bulletin","lollipop","sacred","vermouth","windowsill","builtin","gestapo","conspiracy","rein","resumption","rule","baltimore","rapacious","fajita","rhombi","yak","earthy","rite","brainy","mast","salvation","canasta","swagger","micrometer","fertilize","minstrelsy","innocency","gabardine","trefoil","reverberant","sheave","espresso","pulsate","underpants","niggard","niece","basswood","alliance","gasohol","amply","shorthanded","spiral","weatherworn","wend","baron","federalist","inbreeding","epicene","turbulent","mucosa","ce","crosspoint","shortcut","maryland","gnash","bondholder","acclaim","frontage","sorrel","lepton","moiety","esquire","suborn","latvia","fancier","institution","compute","moot","sidewalk","wry","niter","nursling","panicky","enjoy","pennsylvania","emergency","tumbledown","sikh","landsmen","crossover","dismast","emulsifier","bookshelves","goshawk","brushwork","consistence","prodigy","smooth","lair","commentator","overact","clop","drat","chef","frisky","hackney","batting","chap","playboy","redskin","philistine","guarani","unmistakably","enkindle","dismal","brisbane","datum","secure","pasteboard","helicopter","divisible","garlicky","idiocy","here","convex","icebound","normative","cyprian","counterattack","await","geolog","african","wretch","pushcart","moll","learned","ox","blest","antiseptic","zinc","cerebral","fully","posey","menswear","upi","cowherd","thief","peignoir","bogeyman","yoyo","territory","vibrancy","counterpart","ratio","throttle","corundum","whaleboat","manned","miscegenation","wigwag","coincident","mushy","pugilist","kith","perception","cesarean","rocket","beriberi","shorn","octogenarian","valour","bandit","butterball","aesthetic","intrastate","macerate","hirsute","shock","ornitholog","sportsman","zodiac","frolic","midwives","basalt","crock","veto","silver","shortening","enlist","grandiloquence","stepfather","professionalize","saddle","metronome","snuff","plait","parthenogenesis","mechanist","laurel","servomotor","unscrew","unorganized","convey","vouch","ventriloquist","violist","ireland","intertidal","sneaky","vatic","relish","sulphur","windjammer","lesbian","rep","maybe","coauthor","micheas","precipitable","conception","fatalism","cyclic","shepherd","subjoin","gantry","battleground","vi","dilapidate","knocker","infirmity","coed","ulterior","adriatic","lifework","solemn","scar","gin","dizzy","charlatan","violoncello","beset","zealand","godly","playwright","walrus","monogamy","behindhand","disservice","design","weightless","overt","dishonor","courtly","insolent","anyhow","banish","hardhat","john","fagot","sprang","grim","definition","perceive","virgule","warfare","soothsay","waterfront","mark","pretext","sobriquet","bateau","crystallite","equivocate","illimitable","dignity","aquamarine","pension","retrorocket","extrusion","jealousy","wheeler","machabees","pueblo","gaud","effendi","secular","predispose","contain","maroon","trump","conductor","agriculture","taking","afire","nausea","niggling","famous","peahen","macro","supplicate","hydrothermal","xi","brusque","chophouse","torah","centrifuge","decorator","gel","sloppy","blacklist","tensor","galleon","midpoint","inclination","youngling","felon","brush","episode","fray","inroad","taproot","rendition","appellee","killer","roughneck","civet","defoliant","zinnia","maim","thick","mastermind","phoebe","hardihood","nautical","hereunto","unbounded","underwaist","devilment","flabby","raise","permissible","readout","coeval","reckless","crest","trekked","cornstarch","lynch","hereby","scholarship","physiognom","bombazine","undervalue","triturate","orthodontist","heading","dollar","limb","told","organize","pothook","freshen","gutsy","insecure","resignation","symbolism","thread","protract","primacy","interaction","humble","crises","inverse","anti","parody","fencepost","pillory","extant","heartbeat","pervious","litigant","spare","diffident","remit","choirmaster","bluegill","ante","orbit","escritoire","mealy","stunning","osmium","pounce","confident","passel","topple","unsegregated","shamrock","upland","dressage","stubborn","raze","rayon","telescopic","thereabout","alpaca","ingratiate","hallelujah","conic","congest","madrid","bow","enzymolog","beirut","armament","partake","antagonism","flew","bribe","vegetation","plough","negate","refugee","squamous","drawstring","provocation","gosling","normandy","goldfinch","valediction","aldermen","missile","holography","oblique","kept","disciple","clarinet","paddock","oceanograph","outside","suicide","vaulting","jackanapes","panelist","preside","sceptre","pinstripe","susceptible","grizzly","headphone","mabel","jointed","spectrum","damnable","tentative","clarify","hegemonic","definite","profanity","horseshoe","lend","prosody","cannibal","anglophile","quit","knothole","preponderate","delphi","timorous","imperial","saturnine","halibut","capsular","qatar","palatability","mutagen","writing","bedside","naples","nipple","formalize","hung","bookkeeper","hemorrhage","plating","foretold","purslane","coroner","shamefaced","militarize","muskmelon","astatine","medico","stroke","headstall","confiscable","purify","hemisphere","industry","palliate","dreg","consummate","paring","errant","solitary","equilibrate","homily","neuromuscular","importunity","seedbed","correct","confection","illustrious","styrofoam","cease","salesgirl","copartner","fault","confer","downtown","teacupful","party","greece","doff","nosegay","stereotyped","seduction","suck","conquistador","furbish","stamp","outpost","moo","enplane","chieftaincy","highhanded","flora","submarine","somnolence","preadolescence","mackintosh","benediction","anger","hamburger","timeshare","stench","nipper","panacea","blunder","seminal","scalp","sequestration","miscellanea","propel","mendicant","putative","carful","vicinity","airspeed","poinsettia","wedding","yarrow","power","ginseng","raster","southeaster","trollop","transmission","grebe","systole","series","glycerin","glide","inventive","grosz","trepan","imperialism","cavalier","bootee","rheostat","mary","stepladder","pock","disperse","mire","unaware","arouse","lighting","sideways","druggist","scoot","therein","tot","crow","reticulate","octillion","breeches","denature","dote","sugarcane","wash","hypnotist","arithmetic","punitive","view","dybbuk","upswept","matrix","grimace","bootstrap","luxury","sever","internationalism","pedometer","forehead","slav","compact","gabble","reconnoiter","countrified","cautionary","colleague","oceangoing","poughkeepsie","fearsome","incisive","tend","vehemence","trimeter","gnarl","iraqi","distaste","sexton","coinage","briar","purchase","undergrowth","empiric","hum","exotic","psychotic","isomer","up","hoarfrost","egocentric","aisle","taunt","urgent","humph","cleric","singsong","essay","principled","mutation","underclothes","coheir","trapdoor","reverence","mildew","weaponless","skyjack","housebroke","literate","pragmatic","zoospore","strap","belligerent","misdirect","sixpence","british","dental","gobbledygook","mistrust","congenial","abominable","according","conjecture","woodshed","usual","bundle","benedictine","kibbutzim","jut","plank","arsenal","ensconce","dusty","baldpate","ding","zloty","phoenicia","frown","foeman","systemize","joy","crenellate","sinuous","strict","uk","barbaric","aid","nationalize","actually","vicar","wareroom","decency","bruit","purgation","harmonica","texture","acquire","trapeze","malediction","gormandize","erotica","stockholder","eglantine","isaiah","prissy","prearrange","sidecar","cedar","toady","many","licence","resurrection","hurdle","chinese","bye","sconce","probationer","padre","member","workhorse","befriend","woo","linden","trust","principality","dirty","yuletide","flowerpot","plunder","why","salutation","hysteria","oxyacetylene","gumbo","sidesaddle","timely","monumental","taiwan","weather","loin","carmine","instructor","catheter","race","scram","golan","crab","deputize","handicap","assert","vibe","tendrilled","corpus","spent","cringe","thoroughfare","interminable","habitable","plantation","preferable","conscript","diversity","gauche","batt","womanhood","conversation","obsequious","wastepaper","yore","ghostwritten","immoderate","northeast","swoop","spermatophyte","prosodic","dryer","huckster","activate","generalization","woke","upsilon","brindle","anticipate","pin","concatenation","crept","ii","reed","showplace","gullibility","outbreak","typhoid","penni","predate","speak","romance","formulae","mestizo","swipe","nutria","feebly","awhile","intermarriage","machicolation","geyser","chairlady","jilt","b","clippers","redwood","ventriloquy","bank","grill","borderland","monitor","granular","lumberjack","exchequer","quicken","tan","trekkie","sweepstakes","fey","unworldly","phenomenon","octal","anaphora","berkshire","wore","moneyed","rive","hartford","brazen","smolder","ohmmeter","pint","anguish","bungalow","indigestible","outstay","oyster","heritable","if","lox","agony","seeming","parson","trajectory","catchword","bedford","caliph","rope","chromatic","trailer","emanate","interpose","indigent","sanctity","buffer","paling","tippet","haggai","slur","unesco","omelet","inception","brat","concupiscence","continuo","antarctica","intricate","outwardly","facetious","locket","linguae","oxen","anodyne","barracuda","reserve","newsprint","scrutiny","tenacious","cornell","mogul","pietism","sputter","edging","otherworld","delusionary","quasistationary","accusative","antholog","rangy","veracity","saturn","thistle","riband","samba","mycolog","teamwork","featherbrain","spreadsheet","sylvan","fainthearted","paraphernalia","underfoot","lymphomata","director","begrime","mongoose","reliable","bavarian","quip","concordant","crowd","dependent","malefactor","venturi","panda","tenterhook","lapelled","assonant","sparse","quondam","kava","pulpwood","inebriate","amazon","manila","uteri","bandanna","motherland","bestselling","throwback","referent","vacuity","stedfast","eel","brained","intumesce","laugh","ran","sou","confuse","snob","grain","qualification","inspiration","heretofore","bust","rigmarole","acclimatize","device","ark","conjoint","misadventure","pyrotechnic","identical","commoner","potation","sod","haystack","villus","mechanical","caretaker","sob","inflow","tube","suture","pensive","jukebox","personalty","rabid","foray","alsace","curlew"};
		CString noun[] = {"pecks","cheeks","moles","socks","pits","knees","snots","intestines","eyeballs","veins","sweat glands","fingernails","saliva","eyebrows","ear wax","shoulders","hands","chin hair","nose hair","ear hair","glands","tonsils","molars","wisdom teeth","knee fat","ankles","bunions","apricots","hallux","eye lashes","toe hair","foot fungus","back hair","buns","peepers","paws","mitts","tootsies","dogs","smarts","peepers","chompers","choppers","cuts","guns","cankles","love handles","moobs","saddlebags","thunder thighs","beard ","nibblets","toejam","sock gnomes","sea barnacles","farts","bananas","poops","smegma","abdomen","achillestendon","alveoli","ankle","anus","aorta","arm","armpit","arteries","backbone","back","bellybutton","belly","biceps","blood","body","bones","boobies","brain","breast","bronchial-tube","buttocks","calf","capillaries","carpalbone","carpus","cartilage","cavities","cells","cerebellum","cerebrum","cheek","chest","chromosome","collar-bone","cornea","cranium","deltoid","dermis","diaphragm-muscle","disc","dna","duct","earlobe","ears","elbow","epidermis","eyeballs","eyebrow","eyelash","eyes","face","feet","femur","fibula","fingers","forearm","forefinger","forelimb","genitals","glands","gluteusmaximus","groin","hair","hand","head","heart","heel","hip","hormones","human","immunesystem","index-finger","intestine","iris","jaw","joint","jowl","jugularvein","kidneys","knee","knuckles","labia","leg","leukocyte","ligament","limb","limbicsystem","lips","little-finger","liver","lumbar","lungs","lymphnodes","mammary","mandible","marrow","medialplantarnerve","medullaoblongata","meniscus","metacarpal","metacarpus","metatarsal","middle-finger","middlefrontalgyrus","mind","molar","mouth","muscles","musculocutaneousnerve","navel","neck","nerve","nodule","nose","nucleus","occipitallobe","opisthenar","organ","ovary","palate","palm","pelvis","penis","phalanges","pinkie","pituitarygland","posterior","quadriceps","rear-end","rectum","retina","ribs","ring-finger","rna","septum","shoulders","skeletal","skeleton","skin","skull","socket","spine","sternum","stomach","talusbone","tearduct","teeth","tendon","testicles","thigh","throat","thumb","tibia","tissue","toes","tongue","torso","triceps","tubes","ulna","urethra","uvula","vagina","veins","vessels","vitreoushumor","vocalcord","vomer","vulva","waist","whitecorpuscle","whitetissue","womb","wrinkles","wrist","xiphoid","x-chromosome","x-spot","yapper","yellow-marrow","y-chromosome","zits","zygomaticbone"};

		if (nameNum < 0 || nameNum >= 103 || adjNum < 0 || adjNum >= 103 || nounNum < 0 || nounNum >= 59) {
			nameNum = getRand(0, 102);
			adjNum = getRand(0, 102);
			nounNum = getRand(0, 58);
		}
		//k.Format(_T("%s has %s %s, %u %u %u %u %u"),name[nameNum],adj[adjNum],noun[nounNum],k1,k2,k4,k7,k5);
		//k.Format(_T("%s has %s %s, %d %d %d"),name[nameNum],adj[adjNum],noun[nounNum],nameNum,adjNum,nounNum);
		k.Format(_T("%s has %s %s"),name[nameNum],adj[adjNum],noun[nounNum]);
		
	}
	void setnameNum(int x) {
		nameNum = x;
	}
	void setadjNum(int x) {
		adjNum = x;
	}
	void setnounNum(int x) {
		nounNum = x;
	}
	CString getStatus() {
		return s;
	}

	CString getKey() {
		return k;
	}

	BOOL b1sel; 
	BOOL b2sel; 
	BOOL b3sel; 
	BOOL b4sel; 
	BOOL b5sel; 
	BOOL b6sel; 
	BOOL b7sel; 
	BOOL b8sel; 

private:
	unsigned int clickCount;
	CString s;
	CString k;
	BOOL k1;
	BOOL k2;
	BOOL k3;
	BOOL k4;
	BOOL k5;
	BOOL k6;
	BOOL k7;
	BOOL k8;
	BOOL k9;
	BOOL k0; 
	unsigned int nameNum;
	unsigned int adjNum;
	unsigned int nounNum;

	unsigned int getRand(int range_min, int range_max) {
		srand( (unsigned)time( NULL ) );
		return rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min; 
	}

	void bullshitFunc1() {
		int x=-40512;
		int y=0;
		int i=10;
		for (i=0; i<27; i++) {
			x = x + i;
		}
		y = x;
		for (i=294; i<401; i++) {
			y = y + i;
		}

	}
	BOOL bullshitFunc2() {
		CString loddyDoddy = _T("Loddy doddy we like to party, we dont cause trouble and we don't bother nobody");
		CString dstString;

		dstString = loddyDoddy;
		dstString += _T("912-8388383282833"); // Some bullshit fake string

		return FALSE;
	}
	void bullshitFunc3() {
		CString dirty;
		if (bullshitFunc2()) {
			bullshitFunc1();
		} else {
			dirty = _T("but i'm not clean any more");
		}
	}

	void setK0() {
		if (k1 && k2 && k4 && k5 && k7)
			k0 = TRUE;
	}
	
	void setK1True() {
		int x=-40512;
		int y=0;
		int i=10;
		for (i=0,x=0; i<27; i++) {
			k1 = FALSE;
			x = x + i;
		}
		nameNum = x;
		y=x;
		nameNum = (nameNum - y) + 1; //Add 1 to nameNum *
		for (i=294; i<401; i++) {
			for (x=0;x<120;x++) {
				k1 = TRUE;
			}
			y = y + i;
		}
	}
	void setK2True() {
		k2 = TRUE; 
		nounNum+=31; 
		adjNum+=43;
		nameNum+=21;
	}
	void setK3True() { // Not used
		k3 = TRUE; 
		if (adjNum>21) 
			adjNum=0;
		adjNum+=5;
		nameNum+=31;
	}
	void setK4True() {
		k4 = TRUE;	// Add 2 to nameNum *
		if (nameNum>21)
			nameNum-=21;
		nameNum+=2;
	}
	void setK5True() { 
		k5 = TRUE; // Add 1 to adjNum *
		adjNum++; 
		if (nounNum>30)
			nounNum-=31;
		nounNum+=1;
	}
	void setK6True() {
		k6 = TRUE; // Add 2 to nounNum *
		nounNum+=1;
	}
	void setK7True() { // Add 2 to adjNum *
		k7 = TRUE;
		if(adjNum>42)
			adjNum-=43;
		adjNum+=2; 
	}
	void setK8True() { // Not used
		k8 = TRUE;
		nounNum+=2; 
		adjNum+=1;
		nameNum+=2;
	}
};

class CMainFrame: public CDialog {
public:
	CMainFrame(CWnd* pParent = NULL): CDialog (CMainFrame::IDD, pParent) {	}
	enum{IDD = IDD_mainForm};
	~CMainFrame() { }

protected: 
	virtual BOOL OnInitDialog() {
		CDialog::OnInitDialog();
		m_bmButton1.LoadBitmaps(IDB_BITMAP1a);
		m_bmButton2.LoadBitmaps(IDB_BITMAP2a);
		m_bmButton3.LoadBitmaps(IDB_BITMAP3a);
		m_bmButton4.LoadBitmaps(IDB_BITMAP4a);
		m_bmButton5.LoadBitmaps(IDB_BITMAP5a);
		m_bmButton6.LoadBitmaps(IDB_BITMAP6a);
		m_bmButton7.LoadBitmaps(IDB_BITMAP7a);
		m_bmButton8.LoadBitmaps(IDB_BITMAP8a);

		HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
		SetIcon(hIcon, FALSE);

		return TRUE;
	}
	virtual void DoDataExchange(CDataExchange* pDX) {
		CDialog::DoDataExchange(pDX);
		DDX_Control(pDX, IDC_BUTTON1, m_bmButton1);
		DDX_Control(pDX, IDC_BUTTON2, m_bmButton2);
		DDX_Control(pDX, IDC_BUTTON3, m_bmButton3);
		DDX_Control(pDX, IDC_BUTTON4, m_bmButton4);
		DDX_Control(pDX, IDC_BUTTON5, m_bmButton5);
		DDX_Control(pDX, IDC_BUTTON6, m_bmButton6);
		DDX_Control(pDX, IDC_BUTTON7, m_bmButton7);
		DDX_Control(pDX, IDC_BUTTON8, m_bmButton8);
		DDX_Control(pDX, IDC_STATIC1, m_scLabel);

	};

public:
	DECLARE_MESSAGE_MAP()

	afx_msg void OnBnClickedRun();
	afx_msg void CMainFrame::ActivateRunBn();
	afx_msg void CMainFrame::LightShow();
	afx_msg void CMainFrame::UpdateStatus(LPCTSTR pFormatString, ...);
	afx_msg void CMainFrame::showKey(LPCTSTR pKeyStat, LPCTSTR pKeyString);

	CBitmapButton m_bmButton1;
	CBitmapButton m_bmButton2;
	CBitmapButton m_bmButton3;
	CBitmapButton m_bmButton4;
	CBitmapButton m_bmButton5;
	CBitmapButton m_bmButton6;
	CBitmapButton m_bmButton7;
	CBitmapButton m_bmButton8;
	CStatic m_scLabel; 
	
	FaceSnuffer faceSnuffer;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};

class FunForEveryBody : public CWinApp {
public: 
	virtual BOOL InitInstance() {
		CMainFrame dlg;
		m_pMainWnd = &dlg;
		INT_PTR nResponse = dlg.DoModal();

		//CMainFrame::LightShow();

		return FALSE;
	}
};

BEGIN_MESSAGE_MAP(CMainFrame, CDialog)
	ON_BN_CLICKED(IDOK, &CMainFrame::OnBnClickedRun)
	ON_BN_CLICKED(IDC_BUTTON1, &CMainFrame::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMainFrame::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMainFrame::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMainFrame::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMainFrame::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMainFrame::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMainFrame::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMainFrame::OnBnClickedButton8)
END_MESSAGE_MAP()

FunForEveryBody theApp;


void AfxMessageBoxFormatted(LPCTSTR pFormatString, ...)
{
	//To Call: AfxMessageBoxFormatted(_T("B2 - Click Count: %d"),faceSnuffer.getClickCount());
    va_list vl;
    va_start(vl, pFormatString);
    CString strFormat;
    strFormat.FormatV(pFormatString, vl); 
    AfxMessageBox(strFormat);
}

void CMainFrame::ActivateRunBn()
{
	GetDlgItem(IDOK)->EnableWindow(TRUE);
}

void CMainFrame::UpdateStatus(LPCTSTR pFormatString, ...) 
{
	va_list vl;
    va_start(vl, pFormatString);
    CString strFormat;
    strFormat.FormatV(pFormatString, vl); 
	m_scLabel.SetWindowTextW(strFormat);
}

void CMainFrame::showKey(LPCTSTR pKeyStat, LPCTSTR pKeyString) {
	if (faceSnuffer.getClickCount() >= 30 && faceSnuffer.getClickCount() < 35 ) 
		CMainFrame::UpdateStatus(_T("Those faces are hurting bro.."));
	else if (faceSnuffer.getClickCount() >= 35 && faceSnuffer.getClickCount() < 40)
		CMainFrame::UpdateStatus(_T("You're waay off.."));
	else if (faceSnuffer.getClickCount() >= 40)
		CMainFrame::UpdateStatus(_T("HINT: Restart the application"));
	else
		CMainFrame::UpdateStatus(_T("The key is%sKEY{%s}"),pKeyStat,pKeyString);
}

void CMainFrame::LightShow()
{
		m_bmButton1.SetState(!(m_bmButton1.GetState() & BST_PUSHED));
		Sleep(10); 
		m_bmButton1.SetState(BST_UNCHECKED);

		m_bmButton2.SetState(!(m_bmButton2.GetState() & BST_PUSHED));
		m_bmButton2.SetState(BST_UNCHECKED);

		m_bmButton3.SetState(!(m_bmButton3.GetState() & BST_PUSHED));
		m_bmButton3.SetState(BST_UNCHECKED);

		m_bmButton4.SetState(!(m_bmButton4.GetState() & BST_PUSHED));
		m_bmButton4.SetState(BST_UNCHECKED);

		m_bmButton5.SetState(!(m_bmButton5.GetState() & BST_PUSHED));
		m_bmButton5.SetState(BST_UNCHECKED);

		m_bmButton6.SetState(!(m_bmButton6.GetState() & BST_PUSHED));
		m_bmButton6.SetState(BST_UNCHECKED);

		m_bmButton7.SetState(!(m_bmButton7.GetState() & BST_PUSHED));
		m_bmButton7.SetState(BST_UNCHECKED);

		m_bmButton8.SetState(!(m_bmButton8.GetState() & BST_PUSHED));
		m_bmButton8.SetState(BST_UNCHECKED);
}

void CMainFrame::OnBnClickedRun()
{
	CString a;
	CString b;

	a = faceSnuffer.getStatus();
	b = faceSnuffer.getKey();

	CMainFrame::showKey(a, b);
}


void CMainFrame::OnBnClickedButton1()
{
	faceSnuffer.incrementClickCount();
	//CMainFrame::UpdateStatus(_T("Click Count: %i"),faceSnuffer.getClickCount());
	if (faceSnuffer.b1sel) {
		// Unselect
		m_bmButton1.LoadBitmaps(IDB_BITMAP1a);
		faceSnuffer.b1sel = FALSE;
	} else {
		//Select
		m_bmButton1.LoadBitmaps(IDB_BITMAP1s);
		faceSnuffer.b1sel = TRUE;
		
		faceSnuffer.b1Check();
		faceSnuffer.setStatus();
		faceSnuffer.setKey();
	}
	m_bmButton1.SetButtonStyle(BS_OWNERDRAW,1); // Force redraw, CBitmapButton sucks this way
}


void CMainFrame::OnBnClickedButton2()
{
	faceSnuffer.incrementClickCount();
	
	if (faceSnuffer.b2sel) {
		// Unselect
		m_bmButton2.LoadBitmaps(IDB_BITMAP2a);
		faceSnuffer.b2sel = FALSE;
	} else {
		//Select
		m_bmButton2.LoadBitmaps(IDB_BITMAP2s);
		faceSnuffer.b2sel = TRUE;

		faceSnuffer.b2Check();
		faceSnuffer.setStatus();
		faceSnuffer.setKey();
	}
	m_bmButton2.SetButtonStyle(BS_OWNERDRAW,1);
}


void CMainFrame::OnBnClickedButton3()
{
	faceSnuffer.incrementClickCount();
	
	if (faceSnuffer.b3sel) {
		// Unselect
		m_bmButton3.LoadBitmaps(IDB_BITMAP3a);
		faceSnuffer.b3sel = FALSE;
	} else {
		//Select
		m_bmButton3.LoadBitmaps(IDB_BITMAP3s);
		faceSnuffer.b3sel = TRUE;

		faceSnuffer.b3Check();
		faceSnuffer.setStatus();
		faceSnuffer.setKey();
	}
	m_bmButton3.SetButtonStyle(BS_OWNERDRAW,1);
}


void CMainFrame::OnBnClickedButton4()
{
	faceSnuffer.incrementClickCount();
	
	if (faceSnuffer.b4sel) {
		// Unselect
		m_bmButton4.LoadBitmaps(IDB_BITMAP4a);
		faceSnuffer.b4sel = FALSE;
	} else {
		//Select
		m_bmButton4.LoadBitmaps(IDB_BITMAP4s);
		faceSnuffer.b4sel = TRUE;

		faceSnuffer.b4Check();
		faceSnuffer.setStatus();
		faceSnuffer.setKey();
	}
	m_bmButton4.SetButtonStyle(BS_OWNERDRAW,1);
}


void CMainFrame::OnBnClickedButton5()
{
	faceSnuffer.incrementClickCount();
	
	if (faceSnuffer.b5sel) {
		// Unselect
		m_bmButton5.LoadBitmaps(IDB_BITMAP5a);
		faceSnuffer.b5sel = FALSE;
	} else {
		//Select
		m_bmButton5.LoadBitmaps(IDB_BITMAP5s);
		faceSnuffer.b5sel = TRUE;

		faceSnuffer.b5Check();
		faceSnuffer.setStatus();
		faceSnuffer.setKey();
	}
	m_bmButton5.SetButtonStyle(BS_OWNERDRAW,1);
}


void CMainFrame::OnBnClickedButton6()
{
	faceSnuffer.incrementClickCount();
	
	if (faceSnuffer.b6sel) {
		// Unselect
		m_bmButton6.LoadBitmaps(IDB_BITMAP6a);
		faceSnuffer.b6sel = FALSE;
	} else {
		//Select
		m_bmButton6.LoadBitmaps(IDB_BITMAP6s);
		faceSnuffer.b6sel = TRUE;

		faceSnuffer.b6Check();
		faceSnuffer.setStatus();
		faceSnuffer.setKey();
	}
	m_bmButton6.SetButtonStyle(BS_OWNERDRAW,1);
}


void CMainFrame::OnBnClickedButton7()
{
	faceSnuffer.incrementClickCount();
	
	if (faceSnuffer.b7sel) {
		// Unselect
		m_bmButton7.LoadBitmaps(IDB_BITMAP7a);
		faceSnuffer.b7sel = FALSE;
	} else {
		//Select
		m_bmButton7.LoadBitmaps(IDB_BITMAP7s);
		faceSnuffer.b7sel = TRUE;

		faceSnuffer.b7Check();
		faceSnuffer.setStatus();
		faceSnuffer.setKey();
	}
	m_bmButton7.SetButtonStyle(BS_OWNERDRAW,1);
}


void CMainFrame::OnBnClickedButton8()
{
	faceSnuffer.incrementClickCount();
	
	if (faceSnuffer.b8sel) {
		// Unselect
		m_bmButton8.LoadBitmaps(IDB_BITMAP8a);
		faceSnuffer.b8sel = FALSE;
	} else {
		//Select
		m_bmButton8.LoadBitmaps(IDB_BITMAP8s);
		faceSnuffer.b8sel = TRUE;

		faceSnuffer.b8Check();
		faceSnuffer.setStatus();
		faceSnuffer.setKey();
	}
	m_bmButton8.SetButtonStyle(BS_OWNERDRAW,1);
}
