/*
 * DonkeyKong
 * CFire.cpp
 * This file contains the implementation of CFire class.
*/

#include "CFire.h"

CFire::CFire() {
	state = FIRE_WALKING ;	//FIRE starts on the lowest platform

	x = FIRE_START_X ;
	y = FIRE_START_Y;

	status = FIRE_RIGHT;
	width = FIRE_WIDTH ;
	height = FIRE_HEIGHT ;
}

void CFire::OnLoop() {
	//change location based on velocities
	x += xVel;			// Move FIRE left or right
    if(state != FIRE_CLIMBING) y+= yVel + yGravityVel ;      //add in gravity if FIRE is not climbing               
	else y += yVel ;			// Move FIRE up or down
	
	//check boundary conditions
	if( ( x < 0 ) || ( x + FIRE_WIDTH > WINDOW_WIDTH ) ){		// If FIRE moves too far left or right
		x -= xVel;		// Move Fire back
	}
	if( ( y < 0 ) || ( y + FIRE_HEIGHT > WINDOW_HEIGHT ) ){	// If FIRE moves too far up or down
        	y -= yVel;		// Move Fire back
	}

	//determines animation frame and status
	if ( xVel < 0 && (yVel == 0 || yVel == yGravityVel) ){		// If he is walking left
		status = FIRE_LEFT ;		// Change status
		frame++ ;			// Move to next frame in animation
	}
	else if ( xVel > 0 && (yVel == 0 || yVel == yGravityVel)){	// If he is walking right
		status = FIRE_RIGHT ;		// Change status
		frame++ ;			// Move to next frame in animation
	}
	else if (xVel == 0 && (yVel == 0 || yVel == yGravityVel)){	// If he is standing still
		frame = 0;			// Display frame 0 (standing)
	}
	else if (yVel != 0){			// If he is jumping
		frame = 1 ;			// Display frame 1 (jumping)
	}


}

void CFire::OnRender(SDL_Surface* Surf_Display) {
	switch(state) {					// state is a private data type from CFire
		case FIRE_WALKING :
			if ( frame >= 3){		// Loop the horizontal motion animation
				frame = 0;
			}
			if ( status == FIRE_RIGHT ){
				CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsRight[frame].x, clipsRight[frame].y, FIRE_WIDTH, FIRE_HEIGHT) ;
			}
			else if ( status == FIRE_LEFT ){
				CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsLeft[frame].x, clipsLeft[frame].y, FIRE_WIDTH, FIRE_HEIGHT) ;
			}
			break ;

		case FIRE_CLIMBING :
			if ( frame >= 2){		// Loop the climbing animation
				frame = 0;
			}
			//Build this in later
			break ;

		case FIRE_ATTACKING:
			// Build this in later	
			break ;

	}  //end switch

}  //end OnRender

void CFire::set_clips(){		// Clip the sprites

	clipsRight[0].x = 0;
	clipsRight[0].y = 0;
	clipsRight[0].w = FIRE_WIDTH;
	clipsRight[0].h = FIRE_HEIGHT;

    clipsRight[1].x = FIRE_WIDTH;
    clipsRight[1].y = 0;
    clipsRight[1].w = FIRE_WIDTH;
    clipsRight[1].h = FIRE_HEIGHT;

    clipsRight[2].x = FIRE_WIDTH;
    clipsRight[2].y = 0;
    clipsRight[2].w = FIRE_WIDTH;
    clipsRight[2].h = FIRE_HEIGHT;


	clipsLeft[0].x = 0;
    clipsLeft[0].y = FIRE_HEIGHT;
    clipsLeft[0].w = FIRE_WIDTH;
    clipsLeft[0].h = FIRE_HEIGHT;

    clipsLeft[1].x = FIRE_WIDTH;
    clipsLeft[1].y = FIRE_HEIGHT;
    clipsLeft[1].w = FIRE_WIDTH;
    clipsLeft[1].h = FIRE_HEIGHT;

    clipsLeft[2].x = FIRE_WIDTH;
    clipsLeft[2].y = FIRE_HEIGHT;
    clipsLeft[2].w = FIRE_WIDTH;
    clipsLeft[2].h = FIRE_HEIGHT;

    clipsUp[0].x = FIRE_WIDTH*3-10;
    clipsUp[0].y = 0;
    clipsUp[0].w = FIRE_WIDTH;
    clipsUp[0].h = FIRE_HEIGHT;

    clipsUp[1].x = FIRE_WIDTH*4-8;
    clipsUp[1].y = 0;
    clipsUp[1].w = FIRE_WIDTH;
    clipsUp[1].h = FIRE_HEIGHT;

}

int CFire::getState() {
	return state ;
}

void CFire::setState(marState _state) {
	state = _state ;
}

