/*
 * DonkeyKong
 * CApp_OnEvent.cpp
*/

#include "CApp.h"

int CApp::OnEvent(SDL_Event* Event) {
	if(Event->type == SDL_QUIT) {
		running = 0 ; //finishes game
	}

	mario.handle_input(Event) ;
		//sound effects checks
		if( Event->type == SDL_KEYDOWN ){
			if( Event->key.keysym.sym == SDLK_1 ){
				Mix_PauseMusic();					// Pause background music
				if ( Mix_PlayChannel(-1, burns, 0) == -1 ){		// Play mario yelling from burn
					return 0;
				}
				Mix_ResumeMusic();					// Resume background music
			}
			if( Event->key.keysym.sym == SDLK_2 ){
				Mix_PauseMusic();
                                if ( Mix_PlayChannel(-1, jumps, 0) == -1 ){		// Play jumping sound effect
                                        return 0;
                                }
				Mix_ResumeMusic();
                        }
                        if( Event->key.keysym.sym == SDLK_3 ){
				Mix_PauseMusic();
                                if ( Mix_PlayChannel(-1, hurts, 0) == -1 ){		// Play mario getting hit by barrel
                                        return 0;
                                }
				Mix_ResumeMusic();
                        }
		}

}

void CApp::OnExit() {		//is this unnecessary?
	running = 0 ;
}

