/*
 * DonkeyKong
 * CApp_OnInit.cpp
*/

#include "CApp.h"

int CApp::OnInit() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {	//sets up SDL environment
		cout << "SDL_Init fail" << endl ;
		return 0 ;	//if set up failed
	}
	
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

	Surf_Display = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF) ;	
	if(Surf_Display == NULL) {
		cout << "Window create fail" << endl ;
		return 0 ;	//if window creation failed
	}		

	SDL_WM_SetCaption("Donkey Kong", NULL) ;	//window caption

	if(!OnInit_Static()) {
		cout << "OnInit_Static() fail" << endl ;
		return 0 ;
	}

	if(mario.OnLoad("mar.bmp") == 0) {
		cout << "mario didn't load" << endl ;
		return 0 ;
	}
	mario.set_clips();
	entityList.push_back(&mario) ;

	/*if(peach.OnLoad("./pngFiles/peach.png") == 0) {
		cout << "peach didn't load" << endl ;
		return 0 ;
	}*/	//peach does not go into the entity list because there will be no collisions with her
	//peach.setWidth(PEACH_WIDTH) ;
	//peach.setHeight(PEACH_HEIGHT) ;
	//peach.setX(200) ;
	//peach.setY(100) ;

/*	if(TTF_Init() < 0){
		 cout << "TTF_Init() fail" << endl ; 
		return 0 ;
	}
	font = TTF_OpenFont("lazy.ttf", 20) ;
	if(font == NULL) {
		cout << "Font did not open" << endl ; 
		return 0 ;
	}
	Surf_Highscore = TTF_RenderText_Solid(font, "HIGHSCORE", textColor);
*/
	return 1 ;	//true
}
