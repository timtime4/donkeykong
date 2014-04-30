/*
 * DonkeyKong
 * CApp_OnStartup.cpp
 * Implementation of start up menu for game.  This function is executed until the user clicks the START option.  
 * While in the start up menu, the user also has the option to move the mouse over the CONTROLS option, which displays 
 * the controls used in the game.
*/

#include "CApp.h"

int CApp::OnStartup(SDL_Event* Event) {

	CSurface::OnDraw(Surf_Display, Surf_Menu, 0, 0) ;

	while(SDL_PollEvent(Event)) {	
		if(Event->type == SDL_QUIT) {
			running = 0 ; //finishes game
			game = 0 ;	//won't ask if want to play new game
			return 0 ;
		}
		if(Event->type == SDL_MOUSEBUTTONDOWN) {
			//check for location of click
			if( (Event->button.x > MENU_START_X) && (Event->button.x < MENU_START_X+MENU_START_WIDTH) && (Event->button.y > MENU_START_Y) && (Event->button.y < MENU_START_Y+MENU_START_HEIGHT) ) return 0 ;
		}
		if(Event->type == SDL_MOUSEMOTION) {
			//check for mouse location
			if( (Event->motion.x > MENU_CONTROLS_X) && (Event->button.x < MENU_CONTROLS_X+MENU_CONTROLS_WIDTH) && (Event->motion.y > MENU_CONTROLS_Y) && (Event->motion.y < MENU_CONTROLS_Y+MENU_CONTROLS_HEIGHT) ) displayControls = 1 ;
			else displayControls = 0 ;	//resets to false outside of controls option
		}
	}
	if(displayControls) {	//mouse within CONTROLS option
		CSurface::OnDraw(Surf_Display, Surf_Controls, 90, 450) ;
	}

	SDL_Flip(Surf_Display) ;	//update screen
	return 1 ;
}
