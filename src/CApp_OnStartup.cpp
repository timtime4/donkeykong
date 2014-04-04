/*
 * DonkeyKong
 * CApp_OnStartup.cpp
 * Implementation of start up menu for game.  This function is executed until the user clicks Start Game option.
*/

#include "CApp.h"

int CApp::OnStartup(SDL_Event* Event) {
	CSurface::OnDraw(Surf_Display, Surf_Title, 200 , 100) ;
	CSurface::OnDraw(Surf_Display, Surf_Start, 220, 350) ;
	SDL_Flip(Surf_Display) ;	//update screen

	while(SDL_PollEvent(Event)) {	
		if(Event->type == SDL_QUIT) {
			running = 0 ; //finishes game
			return 0 ;
		}
		if(Event->type == SDL_MOUSEBUTTONDOWN) {
			//check for location of click
			return 0 ;
		}
	}
	return 1 ;
}
