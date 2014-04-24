/*
 * DonkeyKong
 * CApp_OnInit.cpp
*/

#include "CApp.h"

int CApp::OnInit() {

	//////////SDL INITIALIZATION//////////
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {	//sets up SDL environment
		cout << "SDL_Init fail" << endl ;
		return 0 ;	//if set up failed
	}

	
	//////////AUDIO INITIALIZATION//////////
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1){
		printf("Sound Mixer Initialization Error");
	}
	//load music files
	theme = Mix_LoadMUS( "../wavFiles/theme.wav" );
	if ( theme == NULL ){
		printf("Error: Music Load Error.");
	}
	jumps = Mix_LoadWAV( "../wavFiles/jump.wav" );
	burns = Mix_LoadWAV( "../wavFiles/burn.wav" );
	hurts = Mix_LoadWAV( "../wavFiles/hurt.wav" );
	if ( (jumps == NULL) || (burns == NULL) || (hurts == NULL) ){
		printf("Error: Sound Clip Load Error.");
	}


	//////////WINDOW INITIALIZATION//////////
	Surf_Display = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF) ;	
	if(Surf_Display == NULL) {
		cout << "Window create fail" << endl ;
		return 0 ;	//if window creation failed
	}		

	SDL_WM_SetCaption("Donkey Kong", NULL) ;	//window caption

	///////////MARIO EVENTS BEHAVIOR///////////
	if(SDL_EnableKeyRepeat(50, 50)) return 0 ;

	//////////MARIO INITIALIZATION//////////
	if(mario.OnLoad("../imgFiles/mar2.bmp") == 0) {
		cout << "mario didn't load" << endl ;
		return 0 ;
	}

	///////////MARIO LIVES DISPLAY INIT//////////
	Surf_Lives = CSurface::OnLoad("../imgFiles/marLife2.png") ;
	if(Surf_Lives == NULL) return 0 ;


	//////////PEACH INITIALIZATION//////////
	if(peach.OnLoad("../imgFiles/peach.jpg") == 0) {
		cout << "peach didn't load" << endl ;
		return 0 ;
	}
	//peach not added to entityList because result of collision is different from other entities


	////////DONKEY KONG INITIALIZATION////////
	if(dk.OnLoad("../imgFiles/dk.bmp") == 0) {
		cout << "donkey kong didn't load" << endl ;
		return 0 ;
	}
	entityList.push_back(&dk) ;


	/////////FIRE INITIALIZATION////////////

	if(fire.OnLoad("../imgFiles/fire.bmp") == 0){
		cout << "CApp_OnInit.cpp: Error - fire.bmp did not load" << endl;
		return 0;
	}
	entityList.push_back(&fire);
	if(fire2.OnLoad("../imgFiles/fire.bmp") == 0) {
		cout << "CApp_OnInit.cpp: Error - fire.bmp did not load" << endl; 
		return 0 ;
	}
	fire2.setXinit(10) ;
	fire2.setYinit(250) ;
	entityList.push_back(&fire2) ;


	//////////BARREL INITIALIZATION//////////
        if(barrel.OnLoad("../imgFiles/barrel.bmp") == 0){
                cout << "CApp_OnInit.cpp: Error - barrel.bmp did not load" << endl;
                return 0;
        }
        entityList.push_back(&barrel);


	//////////STARTUP SCREEN INITIALIZATION//////////
	Surf_Menu = CSurface::OnLoad("../imgFiles/menu2.png") ;
	if(Surf_Menu == NULL) return 0 ;
	Surf_Controls = CSurface::OnLoad("../imgFiles/controls.png") ;
	if(Surf_Controls == NULL) return 0 ;
	
	//////////GAMEOVER SCREEN INITIALIZATION//////////
	Surf_Gameover = CSurface::OnLoad("../imgFiles/gameover.png") ;
	if(Surf_Gameover == NULL) return 0 ;

	//////////FONT INITIALIZATION//////////
	if(TTF_Init() < 0){
		 cout << "TTF_Init() fail" << endl ; 
		return 0 ;
	}
	scoreFont = TTF_OpenFont("../bauhs93.ttf", 18) ;
	pointsFont = TTF_OpenFont("../bauhs93.ttf", 10) ;	//smaller font for display when points are added to score
	largeFont = TTF_OpenFont("../bauhs93.ttf", 30) ;
	if(scoreFont == NULL || pointsFont == NULL || largeFont == NULL) {
		cout << "Font did not open" << endl ; 
		return 0 ;
	}


	//////////SCORE DISPLAY INITIALIZATION///////////
	ostringstream scoreStream ;
	scoreStream << "Score: " << score ;	//string stream for creating full score text, ie. "Score: 0"
	scoreString = scoreStream.str() ;	//convert stream to string
	Surf_Score = TTF_RenderText_Solid(scoreFont, scoreString.c_str(), textColor) ;

	//////////HIGHSCORE DISPLAY INITIALIZATION//////////
	ifstream hsFile;
	hsFile.open("../.highscore") ;
	if(!hsFile.fail()){
		getline(hsFile, hsString) ;	//reads line of file into line variable
		hs = atoi(hsString.c_str()) ;	//converts high score from file to integer for later comparison with user's score
		hsFile.close() ;
	}else hs = 0 ;	//if file doesn't open, assume no saved highscore, so highscore = 0 
	ostringstream hsStream ;	
	hsStream << "Highscore: " << hs ;	//string stream for creating full highscore text, ie. "Highscore: 1400"
	hsString =  hsStream.str() ;	//convert stream to string
	Surf_Highscore = TTF_RenderText_Solid(scoreFont, hsString.c_str(), textColor);

	return 1 ;	//all initialization succeeded

}



