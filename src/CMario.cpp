/*
 * DonkeyKong
 * CMario.cpp
 * This file contains the implementation of CMario class.
*/

#include "CMario.h"

CMario::CMario() {
	lives = 3 ;
	state = MARIO_STATE_NORMAL ;	//mario starts with no power up

	x = 200, y = 200;
	xVel = 0 ;
	yVel = 0 ;
	status = MARIO_RIGHT;
	frame=0;
	width = MARIO_WIDTH ;
	height = MARIO_HEIGHT ;
	//walking = 0 ;
	//jumping = 0 ;
	//hurting = 0 ;
	//climbing = 0 ;
}

int CMario::getLives() {
	return lives ;
}

/*void CMario::setLives(int _lives) {
	if(lives < 0) return ;
	lives = _lives ;
}*/


void CMario::OnLoop() {
	x += xVel;			// Move mario left or right
        y += yVel;                      // Move mario up or down

	if( ( x < 0 ) || ( x + MARIO_WIDTH > WINDOW_WIDTH ) ){		// If mario moves too far left or right
		x -= xVel;		// Move him back
	}

	if( ( y < 0 ) || ( y + MARIO_HEIGHT > WINDOW_HEIGHT ) ){	// If mario moves too far up or down
        	y -= yVel;		// Move him back
	}
	
	//determines animation frame and status
	walking = 0;
	jumping = 0;
	hurting = 0;
	climbing = 0;
	
	if ( xVel < 0 && yVel == 0){		// If he is walking left
		status = MARIO_LEFT;		// Change status
		frame++;			// Move to next frame in animation
		walking = 1; 
	}
	else if ( xVel > 0 && yVel == 0){	// If he is walking right
		status = MARIO_RIGHT;		// Change status
		frame++;			// Move to next frame in animation
		walking = 1;
	}
	else if (xVel == 0 && yVel == 0){	// If he is standing still
		frame = 0;			// Display frame 0 (standing)
		walking = 1;
	}
	else if (yVel != 0){			// If he is jumping
		frame = 1;			// Display frame 1 (jumping)
		jumping = 1;
	}
	//**add collision detection
	
}

void CMario::OnRender(SDL_Surface* Surf_Display) {

	if (walking == 1){			// If he is walking or standing
		if ( frame >= 3){		// Loop the walking animation
			frame = 0;
		}
		if ( status == MARIO_RIGHT ){
			CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsRight[frame].x, clipsRight[frame].y, MARIO_WIDTH, MARIO_HEIGHT) ;
		}
		else if ( status == MARIO_LEFT ){
			CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsLeft[frame].x, clipsLeft[frame].y, MARIO_WIDTH, MARIO_HEIGHT) ;
		}
	}
	if (jumping == 1){			// If he is jumping
                if ( status == MARIO_RIGHT ){
		CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsRight[frame].x, clipsLeft[frame].y, MARIO_WIDTH, MARIO_HEIGHT) ;
                }
                else if ( status == MARIO_LEFT ){
			CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsLeft[frame].x, clipsLeft[frame].y, MARIO_WIDTH, MARIO_HEIGHT) ;
                }
	}
	if (hurting == 1){			// If he is hurting
		if (frame >= 3){		// Loop the flickering animation
			frame = 0;
		}
		if ( status == MARIO_RIGHT ){
  			CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsHurtR[frame].x, clipsHurtR[frame].y, MARIO_WIDTH, MARIO_HEIGHT) ;	//Make mario flicker while facing right
                }
                else if ( status == MARIO_LEFT ){
                        CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsHurtL[frame].x, clipsHurtL[frame].y, MARIO_WIDTH, MARIO_HEIGHT) ;     // Make mario flicker while facing left
                }
        }
	if (climbing == 1){			// If he is climbing
		if ( frame >= 2){		// Loop the climbing animation
                        frame = 0;
                }
  			CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsUp[frame].x, clipsUp[frame].y, MARIO_WIDTH, MARIO_HEIGHT) ;
        }

}

void CMario::set_clips(){		// Clip the sprites

	clipsRight[0].x = 0;
	clipsRight[0].y = 0;
	clipsRight[0].w = MARIO_WIDTH;
	clipsRight[0].h = MARIO_HEIGHT;

        clipsRight[1].x = MARIO_WIDTH;
        clipsRight[1].y = 0;
        clipsRight[1].w = MARIO_WIDTH;
        clipsRight[1].h = MARIO_HEIGHT;

        clipsRight[2].x = MARIO_WIDTH;
        clipsRight[2].y = 0;
        clipsRight[2].w = MARIO_WIDTH;
        clipsRight[2].h = MARIO_HEIGHT;

	clipsLeft[0].x = 0;
        clipsLeft[0].y = MARIO_HEIGHT;
        clipsLeft[0].w = MARIO_WIDTH;
        clipsLeft[0].h = MARIO_HEIGHT;

        clipsLeft[1].x = MARIO_WIDTH;
        clipsLeft[1].y = MARIO_HEIGHT;
        clipsLeft[1].w = MARIO_WIDTH;
        clipsLeft[1].h = MARIO_HEIGHT;

        clipsLeft[2].x = MARIO_WIDTH;
        clipsLeft[2].y = MARIO_HEIGHT;
        clipsLeft[2].w = MARIO_WIDTH;
        clipsLeft[2].h = MARIO_HEIGHT;

        clipsHurtR[0].x = 0;
        clipsHurtR[0].y = 0;
        clipsHurtR[0].w = MARIO_WIDTH;
        clipsHurtR[0].h = MARIO_HEIGHT;

        clipsHurtR[1].x = MARIO_WIDTH*2;
        clipsHurtR[1].y = MARIO_HEIGHT;
        clipsHurtR[1].w = MARIO_WIDTH;
        clipsHurtR[1].h = MARIO_HEIGHT;

	clipsHurtR[2].x = MARIO_WIDTH*2;
        clipsHurtR[2].y = MARIO_HEIGHT;
        clipsHurtR[2].w = MARIO_WIDTH;
        clipsHurtR[2].h = MARIO_HEIGHT;

        clipsHurtL[0].x = 0;
        clipsHurtL[0].y = MARIO_HEIGHT;
        clipsHurtL[0].w = MARIO_WIDTH;
        clipsHurtL[0].h = MARIO_HEIGHT;

        clipsHurtL[1].x = MARIO_WIDTH*2;
        clipsHurtL[1].y = MARIO_HEIGHT;
        clipsHurtL[1].w = MARIO_WIDTH;
        clipsHurtL[1].h = MARIO_HEIGHT;

        clipsHurtL[2].x = MARIO_WIDTH*2;
        clipsHurtL[2].y = MARIO_HEIGHT;
        clipsHurtL[2].w = MARIO_WIDTH;
        clipsHurtL[2].h = MARIO_HEIGHT;

        clipsUp[0].x = MARIO_WIDTH*3-10;
        clipsUp[0].y = 0;
        clipsUp[0].w = MARIO_WIDTH;
        clipsUp[0].h = MARIO_HEIGHT;

        clipsUp[1].x = MARIO_WIDTH*4-8;
        clipsUp[1].y = 0;
        clipsUp[1].w = MARIO_WIDTH;
        clipsUp[1].h = MARIO_HEIGHT;

}

void CMario::handle_input(SDL_Event* event){

	if( event->type == SDL_KEYDOWN ){		// If a key was pressed
        	switch( event->key.keysym.sym ){		// Adjust the velocity accordingly
            		case SDLK_UP: yVel -= MARIO_HEIGHT / 2; break;
          		case SDLK_DOWN: yVel += MARIO_HEIGHT / 2; break;
            		case SDLK_LEFT: xVel -= MARIO_WIDTH / 2; break;
            		case SDLK_RIGHT: xVel += MARIO_WIDTH / 2; break;
		}
	}
	else if( event->type == SDL_KEYUP ){		// If a key was released
        	switch( event->key.keysym.sym ){		// Adjust the velocity accordingly
           		case SDLK_UP: yVel += MARIO_HEIGHT / 2; break;
            		case SDLK_DOWN: yVel -= MARIO_HEIGHT / 2; break;
            		case SDLK_LEFT: xVel += MARIO_WIDTH / 2; break;
            		case SDLK_RIGHT: xVel -= MARIO_WIDTH / 2; break;
        	}
    	}

}
