/*
 * DonkeyKong
 * CMario.cpp
 * This file contains the implementation of CMario class.
*/

#include "CMario.h"

CMario::CMario() {
	set_clips() ;
	lives = 3 ;

	x = MARIO_START_X ;
	y = MARIO_START_Y;

	state = MARIO_WALKING ;	//mario starts with no power up
	status = MARIO_RIGHT;
	width = MARIO_WIDTH ;
	height = MARIO_HEIGHT ;

	up = 0 ;

	platformCollide = 0 ;
	ladderCollide = 0 ;
}

CMario CMario::operator++() {	//increments mario object's lives by 1, when get extra life powerup
	this->lives++ ;
}

CMario CMario::operator--() {	//decrements mario object's lives by 1
	this->lives-- ;
}

int CMario::getLives() {
	return lives ;
}


void CMario::OnLoop() {
	if (up <= 0 && state!=MARIO_CLIMBING) yVel = 0 ;		//accounts for mario's upward trajectory during a jump, yVel is upward until up data member has been reduced to 0
	else up-- ;

	//change location based on velocities
	x += xVel;			// Move mario left or right
        if(state != MARIO_CLIMBING) y+= yVel + yGravityVel ;      //add in gravity if mario is not climbing               
	else y += yVel ;			// Move mario up or down
	
	//check boundary conditions
	if( ( x < 0 ) || ( x + MARIO_WIDTH > WINDOW_WIDTH ) ){		// If mario moves too far left or right
		x -= xVel;		// Move him back
	}
	if( ( y < 0 ) || ( y + MARIO_HEIGHT > WINDOW_HEIGHT ) ){	// If mario moves too far up or down
        	y -= yVel;		// Move him back
	}

	//increment animation frame
	if(xVel!= 0 || yVel != 0) frame++ ;

}

void CMario::OnRender(SDL_Surface* Surf_Display) {
	switch(state) {
		case MARIO_WALKING :
			if ( frame >= 3){		// Loop the walking animation
				frame = 0;
			}
			if(xVel == 0) frame = 0 ;
			if ( status == MARIO_RIGHT ){
				CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsRight[frame].x, clipsRight[frame].y, MARIO_WIDTH, MARIO_HEIGHT) ;
			}
			else {		//status == MARIO_LEFT
				CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsLeft[frame].x, clipsLeft[frame].y, MARIO_WIDTH, MARIO_HEIGHT) ;
			}
			break ;

		case MARIO_JUMPING :
			frame = 1 ;
			 if (xVel >= 0 ){
				CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsRight[frame].x, clipsRight[frame].y, MARIO_WIDTH, MARIO_HEIGHT) ;
		        }
		        else {	//status == MARIO_LEFT
				CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsLeft[frame].x, clipsLeft[frame].y, MARIO_WIDTH, MARIO_HEIGHT) ;
		        }
			break ;

		case MARIO_CLIMBING :
			if ( frame >= 2){		// Loop the climbing animation
				frame = 0;
			}
  			CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsUp[frame].x, clipsUp[frame].y, MARIO_WIDTH, MARIO_HEIGHT) ;
			break ;

		case MARIO_HURTING:
			if (frame >= 3){		// Loop the flickering animation
				frame = 0;
			}
			if ( status == MARIO_RIGHT ){
  				CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsHurtR[frame].x, clipsHurtR[frame].y, MARIO_WIDTH, MARIO_HEIGHT) ;	//Make mario flicker while facing right
			}
			else if ( status == MARIO_LEFT ){
				CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clipsHurtL[frame].x, clipsHurtL[frame].y, MARIO_WIDTH, MARIO_HEIGHT) ;     // Make mario flicker while facing left
			}
			break ;

	}  //end switch

}  //end OnRender

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

void CMario::reset() {		//used after mario has lost a life to reset at the beginning of the level
	x = MARIO_START_X ;
	y = MARIO_START_Y;

	state = MARIO_WALKING ;	//mario starts with no power up
	status = MARIO_RIGHT;

	up = 0 ;
	platformCollide = 0 ;
	ladderCollide = 0 ;
}



int CMario::getState() {
	return state ;
}

void CMario::setState(marState _state) {
	state = _state ;
}

void CMario::setUp(int val) {
	up = val ;
}

int CMario::getLadderCollide() {
	return ladderCollide ;
}

void CMario::setLadderCollide(int collide) {
	ladderCollide = collide ;
}

int CMario::getPlatformCollide() {
	return platformCollide ;
}

void CMario::setPlatformCollide(int collide) {
	platformCollide = collide ;
}
