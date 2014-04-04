/*
 * DonkeyKong
 * CApp_OnStartup.cpp
 * Implementation of start up menu for game.  This function is executed until the user clicks Start Game option.
*/

#include "CApp.h"

int CApp::OnStartup(SDL_Event* Event) {

	CSurface::OnDraw(Surf_Display, Surf_Menu, 0, 0) ;
	SDL_Flip(Surf_Display) ;	//update screen

	while(SDL_PollEvent(Event)) {	
		if(Event->type == SDL_QUIT) {
			running = 0 ; //finishes game
			return 0 ;
		}
		if(Event->type == SDL_MOUSEBUTTONDOWN) {
			//check for location of click
			if( (Event->button.x > MENU_START_X) && (Event->button.x < MENU_START_X+MENU_START_WIDTH) && (Event->button.y > MENU_START_Y) && (Event->button.y < MENU_START_Y+MENU_START_HEIGHT) ) return 0 ;
		}
	}
	return 1 ;
}
