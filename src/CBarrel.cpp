/*
 * DonkeyKong
 * CBarrel.cpp
 * This file contains the implementation of CBarrel class.
*/

#include "CBarrel.h"

CBarrel::CBarrel() {
	set_clips() ;

	x = BARREL_START_X ;
	y = BARREL_START_Y;

	width = BARREL_WIDTH ;
	height = BARREL_HEIGHT ;

	xVel = 4;

	platformCollide = 0 ;

	resetCount = 0 ;

	yGravityVel = 4 ;
}

void CBarrel::OnLoop() {

	frame++;
	if (frame >= 4) frame = 0;

	x += xVel;			// Move barrel left or right
	y += yVel + yGravityVel;

	if((x < 5 || x+BARREL_WIDTH > WINDOW_WIDTH-5) && y < 560) {	// If barrel gets to the end of the platform
		xVel = -xVel ;		// Make it start moving the other way
	}

	if( ( y < 0 ) || ( y + BARREL_HEIGHT > WINDOW_HEIGHT ) ){	// If barrel moves too far up or down
        	y -= yVel;		// Move Barrel back
	}

	if(resetCount == 800) {
		this->reset() ;	//after 750 loops, reset barrel to top of level
	}

	resetCount++ ;

}

void CBarrel::OnRender(SDL_Surface* Surf_Display) {

	CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clips[frame].x, clips[frame].y, BARREL_WIDTH, BARREL_HEIGHT);

}  //end OnRender

int CBarrel::identifyType() {
	return 2 ;
}

void CBarrel::set_clips(){		// Clip the barrel sprites

	int it;
	for (it = 0; it <= 1; it++){
		clips[it].x = BARREL_WIDTH*it;
		clips[it].y = 0;
		clips[it].w = BARREL_WIDTH;
		clips[it].h = BARREL_HEIGHT;
	}
        for (it = 2; it <= 3; it++){		// Fixes the fact that the sprites get off-center
                clips[it].x = BARREL_WIDTH*it+1;
                clips[it].y = 0;
                clips[it].w = BARREL_WIDTH;
                clips[it].h = BARREL_HEIGHT;
        }


}


int CBarrel::getPlatformCollide() {
	return platformCollide ;
}

void CBarrel::setPlatformCollide(int collide) {
	platformCollide = collide ;
}

void CBarrel::reset() {
	x = BARREL_START_X ;
	y = BARREL_START_Y ;
	xVel = 4 ;
	resetCount = 0 ;
}
