/*
 * DonkeyKong
 * CApp_OnInit.cpp
*/

#include "CApp.h"
#include <fstream>

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
	theme = Mix_LoadMUS( "wavFiles/theme.wav" );
	if ( theme == NULL ){
		printf("Error: Music Load Error.");
	}
	jumps = Mix_LoadWAV( "wavFiles/jump.wav" );
	burns = Mix_LoadWAV( "wavFiles/burn.wav" );
	hurts = Mix_LoadWAV( "wavFiles/hurt.wav" );
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

	//////////STATIC OBJECT INTIIALIZATION//////////
	if(!OnInit_Static()) {
		cout << "OnInit_Static() fail" << endl ;
		return 0 ;
	}

	//////////MARIO INITIALIZATION//////////
	if(mario.OnLoad("imgFiles/mar2.bmp") == 0) {
		cout << "mario didn't load" << endl ;
		return 0 ;
	}
	entityList.push_back(&mario) ;
	

	//////////PEACH INITIALIZATION//////////
	if(peach.OnLoad("imgFiles/peach.jpg") == 0) {
		cout << "peach didn't load" << endl ;
		return 0 ;
	}
	entityList.push_back(&peach) ;


        ////////DONKEY KONG INITIALIZATION////////
        if(dk.OnLoad("imgFiles/dk.bmp") == 0) {
                cout << "donkey kong didn't load" << endl ;
                return 0 ;
        }
        entityList.push_back(&dk) ;




	//////////BARREL INITIALIZATION//////////



	//////////HIGHSCORE DISPLAY INITIALIZATION//////////
		
		//open from file .highscore in src directory
		//in form-> HIGHSCORE: xxxx, this will be read into a string and printed to the screen
	
	ifstream hsFile;
	hsFile.open(".highscore") ;
	if(hsFile.fail()) return 0 ;
	string hsString ;
	getline(hsFile, hsString) ;	//reads line of file into line variable

	if(TTF_Init() < 0){
		 cout << "TTF_Init() fail" << endl ; 
		return 0 ;
	}
	font = TTF_OpenFont("bauhs93.ttf", 20) ;
	if(font == NULL) {
		cout << "Font did not open" << endl ; 
		return 0 ;
	}
	Surf_Highscore = TTF_RenderText_Solid(font, hsString.c_str(), textColor);

	return 1 ;	//all initialization succeeded
}
