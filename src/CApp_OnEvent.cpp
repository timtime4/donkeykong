/*
 * DonkeyKong
 * CApp_OnEvent.cpp
*/

#include "CApp.h"

int CApp::OnEvent(SDL_Event* Event) {
	if(Event->type == SDL_QUIT) {
		running = 0 ; //finishes game
		game = 0 ;
	}

	//events that affect mario
	if(mario.getState() != MARIO_HURTING) {	//disable all keydown events when mario is hurting
		if( Event->type == SDL_KEYDOWN ){		// If a key was pressed
			switch( Event->key.keysym.sym ){		// Adjust the velocity accordingly
				case SDLK_SPACE:
					if(mario.getState() == MARIO_WALKING) {
						mario.setYVel(-7) ;
						mario.setUp(8) ;	//mario's yVel lasts for 7 frames, NEED TO CHANGE THIS ACCORDING TO WHAT WE DECIDE ON FOR FRAME RATE
						mario.setState(MARIO_JUMPING) ;
						//play jumping sound effect
						if ( Mix_PlayChannel(-1, jumps, 0) == -1 ){		// Play jumping sound effect
							return 0;
						}
					}
					break ;

		    		case SDLK_UP: 	//up and down arrows only available for climbing
					if(mario.getState() == MARIO_CLIMBING) mario.setYVel(-3) ; 
					break ;

		  		case SDLK_DOWN: 
					if(mario.getState() == MARIO_CLIMBING) mario.setYVel(3) ; 
					break ;

		    		case SDLK_LEFT: 
					if(mario.getPlatformCollide() || mario.getState() == MARIO_JUMPING) { //disable functionality when mario is mid-climb
						mario.setXVel(-3) ; 
						mario.setStatus(MARIO_LEFT) ; 
					}
					break ;

		    		case SDLK_RIGHT:
					if(mario.getPlatformCollide() || mario.getState() == MARIO_JUMPING) {//disable functionality when mario is mid-climb
						mario.setXVel(3) ;
						mario.setStatus(MARIO_RIGHT) ; 
					}
					break;

			}
		}
	}
	if( Event->type == SDL_KEYUP ){		// If a key was released
		switch( Event->key.keysym.sym ){		// all velocities set to zero when keys are released
			//case SDLK_SPACE taken care of after up = 0
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

}

