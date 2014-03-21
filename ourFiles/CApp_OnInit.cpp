/*
 * DonkeyKong
 * CApp_OnInit.cpp
*/

#include "CApp.h"
#include <iostream>

int CApp::OnInit() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {	//sets up SDL environment
		return 0 ;	//if set up failed
	}
	
	Surf_Display = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF) ;	
	if(Surf_Display == NULL) {
		return 0 ;	//if window creation failed
	}		

	Surf_Background = CSurface::OnLoad("pngFiles/bgFiles/dkL1bg_7.png") ;
	if(Surf_Background== NULL) return 0 ;


	if(marioEntity.OnLoad("pngFiles/marioWalking.png", 20, 40, 8) == 0) return 0 ;

	marioEntity.setX(20) ;
	marioEntity.setY(WINDOW_HEIGHT-60) ;

	CEntity::entityList.push_back(&marioEntity) ;
	
	return 1 ;	//true
}
