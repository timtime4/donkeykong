/*
 * DonkeyKong
 * CFire.cpp
 * This file contains the implementation of CFire class.
*/

#include "CFire.h"
#include <cmath>

CFire::CFire() {
	set_clips() ;

	state = FIRE_WALKING ;	//FIRE starts on the lowest platform

	x = FIRE_START_X ;
	y = FIRE_START_Y;

	width = FIRE_WIDTH ;
	height = FIRE_HEIGHT ;

	xVel = 1;
	yVel = 2;

//	platformCollide = 0 ;
//	ladderCollide = 0 ;
}

void CFire::OnLoop() {
	//change location based on velocities

	if(state == FIRE_WALKING) {
		x += xVel;		// Move FIRE left or right
		y += yGravityVel;
	}
	if(state == FIRE_SEARCHING){  //fire will just search for a ladder to climb
		if(getLadderCollide()){
			state = FIRE_CLIMBING;
		} else {
			x += xVel;
			y += yGravityVel;
		}
	} 
    if(state == FIRE_CLIMBING){
		y -= yVel;
	}
	
	if((x < 0) || (x + FIRE_WIDTH > WINDOW_WIDTH)) xVel = -xVel; //if fire hits either side wall, change direction of velocity

	
	if( ( y < 0 ) || ( y + FIRE_HEIGHT > WINDOW_HEIGHT ) ){	// If FIRE moves too far up or down
        	y -= yVel;		// Move Fire back
	}

	frame++;									// Move to next frame in animation
	
}

void CFire::OnRender(SDL_Surface* Surf_Display) {
	if ( frame >= 3) frame = 0;
	CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clips[frame].x, clips[frame].y, FIRE_WIDTH, FIRE_HEIGHT);
} 

int CFire::identifyType() {
	return 1 ;
}

void CFire::set_clips(){		// Clip the fire sprites
	int i;

	for (i = 0; i <= 2; i++){
		clips[i].x = FIRE_WIDTH*i;
		clips[i].y = 0;
		clips[i].w = FIRE_WIDTH;
		clips[i].h = FIRE_HEIGHT;
	}

}


int CFire::IsDiffLevel(CMario& mario){
	if( abs(this->y - mario.getY()) > 22){ //indicates fire is on level lower than mario and not climbing a ladder
		return 1;
	} else{
		return 0;
	}
}

//This function will change the direction of the fire if it makes sense in respect to Mario
int CFire::wheresMarioX(CMario& mario){
	if( (mario.getX() - 15 > this->x) && (this->xVel < 0) ){
		this->xVel *= -1;
	}
	else if( (mario.getX() + 15 < this->x) && (this->xVel > 0) ) this->xVel *= -1;
}

int CFire::getState() {
	return state ;
}

void CFire::setState(fireState _state) {
	state = _state ;
}


/*int CFire::getLadderCollide() {
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
}*/


void CFire::reset() {
	state = FIRE_WALKING ;
	x = FIRE_START_X ;
	y = FIRE_START_Y ;

}
