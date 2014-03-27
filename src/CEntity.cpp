/*
 * DonkeyKong
 * CEntity.cpp
 * This file contains the implementation of CEntity class.
*/

#include "CEntity.h"

//std::vector<CEntity*> CEntity::entityList ;	

CEntity::CEntity() {
	Surf_Entity = NULL ;
	x = 0 ;
	y = 0 ;
	xVel = 0 ;
	yVel = 0 ;
	width = 0 ;
	height = 0 ;
	maxFrames = 0 ;
	status = 0 ;
}

CEntity::~CEntity() {
	//empty deconstructor definition
}

int CEntity::OnLoad(string file) {
	Surf_Entity = CSurface::OnLoad(file.c_str()) ;
	if(Surf_Entity == NULL) return 0 ;

	CSurface::Transparent(Surf_Entity, 255, 255, 255) ;	//not working - because of color or function?

	return 1 ;
}

/*void CEntity::OnLoop() {	
	x += xVel ;
	y += yVel ;

	if( x < 0 || (x + width) > WINDOW_WIDTH) x -= xVel ;
	if( y < 0 || (y + height) > WINDOW_HEIGHT) y -= yVel ;

	if (xVel < 0) {
		status = 0 ;	//moving left is status 0
		frame++ ;
	} else if (xVel > 0) {
		status = 1 ;	//moving right is status 1
		frame++ ;
	} else frame = 0 ;	//resets animation

	if (frame >= maxFrames) frame = 0 ;	//loops animation
}

void CEntity::OnRender(SDL_Surface* Surf_Display) {
	CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, (status+2*frame)*width, 0, width, height) ;
}*/

void CEntity::OnCleanup() {
	if(Surf_Entity) SDL_FreeSurface(Surf_Entity) ;
	Surf_Entity = NULL ;
}


