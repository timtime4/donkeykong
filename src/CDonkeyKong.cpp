/*
 * DonkeyKong
 * CDonkeyKong.cpp
 * This file contains the implementation of CDonkeyKong class.
*/

#include "CDonkeyKong.h"
#define SLOWED 1	//set to 1 if want to slow DK by half

CDonkeyKong::CDonkeyKong() {
	x = DK_START_X ;
	y = DK_START_Y ;
	xVel = 0 ;
	yVel = 0 ;		//will not be moving up or down at any point
	moved = 0 ;

	width = DK_WIDTH ;
	height = DK_HEIGHT ;
}

void CDonkeyKong::OnLoop() {
	#if SLOWED
		if(!moved) {
	#endif
		frame++ ;
		if(frame >= 30) frame = 0 ;	//only 2 frames per direction

	#if SLOWED
		moved = 1 ;	//changed for next time through OnLoop()
	} else moved = 0 ;
	#endif	
}

void CDonkeyKong::OnRender(SDL_Surface* Surf_Display) {
	if(frame <= 15) {
		CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, frame*DK_WIDTH, 0, DK_WIDTH, DK_HEIGHT) ;
	}
	else{
		CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, frame*(DK_WIDTH+1), 0, DK_WIDTH, DK_HEIGHT) ;
	}
}

