/*
 * DonkeyKong
 * CApp_OnStartup.cpp
 * Implementation of start up menu for game.  This function is executed until the user clicks the START option.  While in the start up menu, the user also has the option to move the mouse over the CONTROLS option, which displays the controls used in the game.
*/

#include "CApp.h"

int CApp::OnGameover(SDL_Event* Event) {

	CSurface::OnDraw(Surf_Display, Surf_Gameover, 0, 0) ;

	while(SDL_PollEvent(Event)) {	
		if(Event->type == SDL_QUIT) {
			game = 0 ; //finishes game
			return 0 ;
		}
		if(Event->type == SDL_MOUSEBUTTONDOWN) {
			//check for location of click
			if( (Event->button.x > GAMEOVER_PLAY_X) && (Event->button.x < GAMEOVER_PLAY_X+GAMEOVER_PLAY_WIDTH) && (Event->button.y > GAMEOVER_PLAY_Y) && (Event->button.y < GAMEOVER_PLAY_Y+GAMEOVER_PLAY_HEIGHT) ) {
				running = 1 ;
				return 0 ;
			}
			else if((Event->button.x > GAMEOVER_QUIT_X) && (Event->button.x < GAMEOVER_QUIT_X+GAMEOVER_QUIT_WIDTH) && (Event->button.y > GAMEOVER_QUIT_Y) && (Event->button.y < GAMEOVER_QUIT_Y+GAMEOVER_QUIT_HEIGHT)) {
				game = 0 ;
				return 0 ;
			}
		}
	}

	SDL_Flip(Surf_Display) ;	//update screen
	return 1 ;
}
