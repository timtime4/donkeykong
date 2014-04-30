/*
 * DonkeyKong
 * CApp_OnGameover.cpp
 * Implementation of the OnGameover() member function of the CApp class.  This function executes after the user has either won 
 * the game (beaten both level 1 and level 2), or has lost all of Mario's lives.  The application remains in the loop containing
 * this function until the user clicks an option - play again or quit. 
*/

#include "CApp.h"

int CApp::OnGameover(SDL_Event* Event) {

	while(SDL_PollEvent(Event)) {	
		if(Event->type == SDL_QUIT) {
			game = 0 ; //finishes game
			return 0 ;
		}
		if(Event->type == SDL_MOUSEBUTTONDOWN) {
			//check for location of click
			if( (Event->button.x > GAMEOVER_PLAY_X) && (Event->button.x < GAMEOVER_PLAY_X+GAMEOVER_PLAY_WIDTH) && (Event->button.y > GAMEOVER_PLAY_Y) && (Event->button.y < GAMEOVER_PLAY_Y+GAMEOVER_PLAY_HEIGHT) ) {		//restart game if click PLAY AGAIN
				running = 1 ;
				return 0 ;	
			}
			else if((Event->button.x > GAMEOVER_QUIT_X) && (Event->button.x < GAMEOVER_QUIT_X+GAMEOVER_QUIT_WIDTH) && (Event->button.y > GAMEOVER_QUIT_Y) && (Event->button.y < GAMEOVER_QUIT_Y+GAMEOVER_QUIT_HEIGHT)) {		//quit application if click QUIT
				game = 0 ;
				return 0 ;
			}
		}
	}

	return 1 ;
}
