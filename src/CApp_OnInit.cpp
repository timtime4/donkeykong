/*
 * DonkeyKong
 * CApp_OnInit.cpp
*/

#include "CApp.h"
#include <iostream>

int CApp::OnInit() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {	//sets up SDL environment
		cout << "SDL_Init fail" << endl ;
		return 0 ;	//if set up failed
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

/*	if(marioEntity.OnLoad("pngFiles/marioWalking.png", 20, 40, 8) == 0) {
		cout << "Mario didn't load" << endl ; 
		return 0 ;
	}

	marioEntity.setX(20) ;
	marioEntity.setY(WINDOW_HEIGHT-60) ;

	CEntity::entityList.push_back(&marioEntity) ;
*/

	if(TTF_Init() < 0){
		 cout << "TTF_Init() fail" << endl ; 
		return 0 ;
	}
	font = TTF_OpenFont("lazy.ttf", 20) ;
	if(font == NULL) {
		cout << "Font did not open" << endl ; 
		return 0 ;
	}
	Surf_Highscore = TTF_RenderText_Solid(font, "HIGHSCORE", textColor);

	return 1 ;	//true
}
