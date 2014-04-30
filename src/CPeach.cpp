/*
 * DonkeyKong
 * CPeach.cpp
 * This file contains the implementation of CPeach class.
*/

#include "CPeach.h"
#define SLOWED 1	//set to 1 if want to slow peach by half, otherwise peach moves too quickly 

CPeach::CPeach() {
	x = PEACH_START_X ;
	y = PEACH_Y - PEACH_HEIGHT;
	xVel = 4 ;
	yVel = 0 ;		//will not be moving up or down at any point
	direction = 1 ;		//initially moving right
	moved = 0 ;

	width = PEACH_WIDTH ;
	height = PEACH_HEIGHT ;
}

void CPeach::OnLoop() {
	#if SLOWED
		if(!moved) {
	#endif
		x += xVel*direction ;
		//do not update y

		if( (x < PEACH_LEFT_LIMIT) || (x > PEACH_RIGHT_LIMIT) ) {
			x -= xVel*direction ;
			direction = -direction ;	//switch directions
		}
		frame++ ;
		if(frame > 1) frame = 0 ;	//only 2 frames per direction

	#if SLOWED
		moved = 1 ;	//changed for next time through OnLoop()
	} else moved = 0 ;
	#endif	
}

void CPeach::OnRender(SDL_Surface* Surf_Display) {
	if(direction == -1) {	//left moving peach
		CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, frame*PEACH_WIDTH, 0, PEACH_WIDTH, PEACH_HEIGHT) ;
	} else { //right moving peach
		CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, (2+frame)*PEACH_WIDTH, 0, PEACH_WIDTH, PEACH_HEIGHT) ;
	}
}

int CPeach::IsCollision(CMario& mario) {
	//returns true upon collision with CMario object, indicates winning of level
	if( (mario.getX() < this->x + this->width + 5) && (mario.getX() + mario.getWidth() > this->x) &&
		(mario.getY() < this->y + this->height) && (mario.getY() + mario.getHeight() > this->y) )
	{
		return 1 ;
	}
	return 0 ;

}

int CPeach::identifyType() {
	return 4 ;
}

