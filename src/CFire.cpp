/*
 * DonkeyKong
 * CFire.cpp
 * This file contains the implementation of CFire class.
*/

#include "CFire.h"

CFire::CFire() {
	set_clips() ;

	state = FIRE_WALKING ;	//FIRE starts on the lowest platform

	x = FIRE_START_X ;
	y = FIRE_START_Y;

	width = FIRE_WIDTH ;
	height = FIRE_HEIGHT ;

	xVel = 1.5;

	platformCollide = 0 ;
	ladderCollide = 0 ;
}

void CFire::OnLoop() {
	//change location based on velocities
	x += xVel;			// Move FIRE left or right

    if(state != FIRE_CLIMBING) y += yVel + yGravityVel ;      
	else y += yVel ;	// Move FIRE up or down
	
	if((x < 0) || (x + FIRE_WIDTH > WINDOW_WIDTH)) xVel = -xVel; //if fire hits either side wall, change direction of velocity

	
	if( ( y < 0 ) || ( y + FIRE_HEIGHT > WINDOW_HEIGHT ) ){	// If FIRE moves too far up or down
        	y -= yVel;		// Move Fire back
	}

////////////NEED TO FIX THIS BELOW/////////////////
	//determines animation frame and status
	if (yVel == 0 || yVel == yGravityVel){			// If fire is moving horizontally
		frame++;									// Move to next frame in animation
	}
}

void CFire::OnRender(SDL_Surface* Surf_Display) {
	switch(state) {					// state is a private data type from CFire
		case FIRE_WALKING :
			if ( frame >= 3){		// Loop the horizontal motion animation
				frame = 0;
			}
			CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clips[frame].x, clips[frame].y, 	FIRE_WIDTH, FIRE_HEIGHT);
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

void CFire::set_clips(){		// Clip the fire sprites

	clips[0].x = 0;
	clips[0].y = 0;
	clips[0].w = FIRE_WIDTH;
	clips[0].h = FIRE_HEIGHT;

    clips[1].x = FIRE_WIDTH;
    clips[1].y = 0;
    clips[1].w = FIRE_WIDTH;
    clips[1].h = FIRE_HEIGHT;

    clips[2].x = FIRE_WIDTH * 2;
    clips[2].y = 0;
    clips[2].w = FIRE_WIDTH;
    clips[2].h = FIRE_HEIGHT;

}


int CFire::IsCollision(CMario& mario) {
	//returns true upon collision with CMario object, indicates DEFEAT muh ha ha ha
	if( (mario.getX() < this->x + this->width) && (mario.getX() + mario.getWidth() > this->x) &&
		(mario.getY() < this->y + this->height) && (mario.getY() + mario.getHeight() > this->y) )
	{
		return 1 ;
	}
	return 0 ;

}

int CFire::wheresMarioX(CMario& mario){
	if( (mario.getX() - 15 > this->x) && (this->xVel < 0) ){
		this->xVel *= -1;
	}
	else if( (mario.getX() + 15 < this->x) && (this->xVel > 0) ) this->xVel *= -1;
}

int CFire::wheresMarioY(CMario& mario){
	return mario.getY();
}

int CFire::getState() {
	return state ;
}

void CFire::setState(fireState _state) {
	state = _state ;
}


int CFire::getLadderCollide() {
	return ladderCollide ;
}

void CFire::setLadderCollide(int collide) {
	ladderCollide = collide ;
}

int CFire::getPlatformCollide() {
	return platformCollide ;
}

void CFire::setPlatformCollide(int collide) {
	platformCollide = collide ;
}

