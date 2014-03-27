/*
 * DonkeyKong
 * CMario.cpp
 * This file contains the implementation of CMario class.
*/

#include "CMario.h"

CMario::CMario() {
	lives = 3 ;
	//state = MARIO_STATE_NORMAL ;	//mario starts with no power up
	state = 0 ;
	x = 200, y = 200;
	xVel = 0 ;
	yVel = 0 ;
	status = MARIO_RIGHT;
	frame=0;
}

int CMario::getLives() {
	return lives ;
}

/*void CMario::setLives(int _lives) {
	if(lives < 0) return ;
	lives = _lives ;
}*/

int CMario::OnLoadMario(string file) {
	Surf_Entity = CSurface::OnLoad(file) ;
	if(Surf_Entity == NULL) return 0 ;

}

void CMario::OnLoop() {
	x += xVel;			// Move mario left or right
        y += yVel;                      // Move mario up or down

	if( ( x < 0 ) || ( x + MARIO_WIDTH > WINDOW_WIDTH ) ){		// If mario moves too far left or right
		x -= xVel;		// Move him back
	}

	if( ( y < 0 ) || ( y + MARIO_HEIGHT > WINDOW_HEIGHT ) ){	// If mario moves too far up or down
        	y -= yVel;		// Move him back
	}
	
	//**add collision detection
	
}

void CMario::OnRender(SDL_Surface* Surf_Display) {
	if ( xVel < 0){			// If he is moving left
		status = MARIO_LEFT;	// Change status
		frame++;		// Move to next frame in animation
	}
	else if ( xVel > 0){		// If he is moving right
		status = MARIO_RIGHT;	// Change status
		frame++;		// Move to next frame in animation
	}
	else{				// If he is standing still
		frame = 0;		// Restart animation
	}
	
	if ( frame >= 2){		// Loop the animation
		frame = 0;
	}

	if ( status == MARIO_RIGHT ){
		CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsRight[frame].x, clipsRight[frame].y, clipsRight[frame].w, clipsRight[frame].h) ;
	
	//	apply_surface( x, y, mario, screen, &clipsRight[ frame ] );	// Show mario going right
	}
	else if ( status == MARIO_LEFT ){
		CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsLeft[frame].x, clipsLeft[frame].y, clipsLeft[frame].w, clipsLeft[frame].h) ;
		
	//	apply_surface( x, y, mario, screen, &clipsLeft[ frame ] );     // Show mario going left
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

	clipsLeft[0].x = MARIO_WIDTH;
        clipsLeft[0].y = MARIO_HEIGHT;
        clipsLeft[0].w = MARIO_WIDTH;
        clipsLeft[0].h = MARIO_HEIGHT;

        clipsLeft[1].x = 0;
        clipsLeft[1].y = MARIO_HEIGHT;
        clipsLeft[1].w = MARIO_WIDTH;
        clipsLeft[1].h = MARIO_HEIGHT;

}

/*void CMario::OnCleanup() {


} */

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
