/*
 * DonkeyKong
 * CApp_OnEvent.cpp
*/

#include "CApp.h"

int CApp::OnEvent(SDL_Event* Event) {
	if(Event->type == SDL_QUIT) {
		running = 0 ; //finishes game
	}

	//events that affect mario
	if( Event->type == SDL_KEYDOWN ){		// If a key was pressed
        	switch( Event->key.keysym.sym ){		// Adjust the velocity accordingly
			case SDLK_SPACE:
				mario.setYVel(mario.getYVel()-3) ;
				mario.setUp(10) ;	//mario's yVel lasts for 5 frames
				break ;

	    		case SDLK_UP: 	//up and down arrows only available for climbing
				if(mario.getState() == MARIO_CLIMBING) mario.setYVel(mario.getYVel()-2) ; 
				break ;

          		case SDLK_DOWN: 
				if(mario.getState() == MARIO_CLIMBING) mario.setYVel(mario.getYVel()+2) ; 
				break ;

            		case SDLK_LEFT: 
				mario.setXVel(mario.getXVel()-2) ; 
				mario.setStatus(MARIO_LEFT) ; 
				break ;

            		case SDLK_RIGHT: 
				mario.setXVel(mario.getXVel()+2) ;
				mario.setStatus(MARIO_RIGHT) ; 
				break;

		}
	}

	if( Event->type == SDL_KEYUP ){		// If a key was released
        	switch( Event->key.keysym.sym ){		// all velocities set to zero when keys are released
			/*case SDLK_SPACE:
				mario.setYVel(0) ;
				break ;*/

           		case SDLK_UP: 
				mario.setYVel(0) ;
				break ;

          		case SDLK_DOWN: 
				mario.setYVel(0) ;

				break ;

            		case SDLK_LEFT: 
				mario.setXVel(0) ;
				break ;

            		case SDLK_RIGHT: 
				mario.setXVel(0) ;
				break;

        	}
    	}


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

