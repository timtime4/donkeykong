/*
 * DonkeyKong
 * CBarrel.cpp
 * This file contains the implementation of CBarrel class.
*/

#include "CBarrel.h"

CBarrel::CBarrel() {
	set_clips() ;

//	state = BARREL_WALKING ;	//BARREL starts on the lowest platform

	x = BARREL_START_X ;
	y = BARREL_START_Y;

	width = BARREL_WIDTH ;
	height = BARREL_HEIGHT ;

	xVel = 5;

	platformCollide = 0 ;
//	ladderCollide = 0 ;
}

void CBarrel::OnLoop() {
	int yloc;

	x += xVel;			// Move BARREL left or right

	frame++;
	if (frame >= 4) frame = 0;

	y += yVel + yGravityVel;
	
	if((x + BARREL_WIDTH < 45) || (x + BARREL_WIDTH > WINDOW_WIDTH-45)){		//if barrel hits either side wall, change direction of velocity
		yloc = y;
		while (1){
			y += 1;
			x = x;
			if (y - 51 > yloc){
				xVel = -xVel;
				break;
			}
		}
	}
	
	if( ( y < 0 ) || ( y + BARREL_HEIGHT > WINDOW_HEIGHT ) ){	// If BARREL moves too far up or down
        	y -= yVel;		// Move Barrel back
	}


}

void CBarrel::OnRender(SDL_Surface* Surf_Display) {

	CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, clips[frame].x, clips[frame].y, BARREL_WIDTH, BARREL_HEIGHT);

}  //end OnRender

void CBarrel::set_clips(){		// Clip the barrel sprites

	int it;
	for (it = 0; it <= 1; it++){
		clips[it].x = BARREL_WIDTH*it;
		clips[it].y = 0;
		clips[it].w = BARREL_WIDTH;
		clips[it].h = BARREL_HEIGHT;
	}
        for (it = 2; it <= 3; it++){
                clips[it].x = BARREL_WIDTH*it+1;
                clips[it].y = 0;
                clips[it].w = BARREL_WIDTH;
                clips[it].h = BARREL_HEIGHT;
        }


}


int CBarrel::IsCollision(CMario& mario) {
	//returns true upon collision with CMario object, indicates DEFEAT muh ha ha ha
	/*if( (mario.getX() < this->x + this->width) && (mario.getX() + mario.getWidth() > this->x) &&
		(mario.getY() < this->y + this->height) && (mario.getY() + mario.getHeight() > this->y) )
	{
		return 1 ;
	}*/
	if( (mario.getX() < this->x + this->width) && (mario.getX() + mario.getWidth() > this->x) ) {	//in correct x range
		if( (mario.getY() < this->y + this->height) && (mario.getY() + mario.getHeight() > this->y) ) {
			return 1 ;	//indicates collision with barrel and death of mario
		} else if ( (mario.getY() + mario.getHeight() < this->y) && (mario.getY() > this->y - 40) ) {
			return 2 ;	//indicates mario jumpint over barrel
		}
	} 


	return 0 ;

}

int CBarrel::getPlatformCollide() {
	return platformCollide ;
}

void CBarrel::setPlatformCollide(int collide) {
	platformCollide = collide ;
}

