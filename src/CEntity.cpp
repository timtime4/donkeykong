/*
 * DonkeyKong
 * CEntity.cpp
 * This file contains the implementation of CEntity class.
*/

#include "CEntity.h"

//std::vector<CEntity*> CEntity::entityList ;	

CEntity::CEntity() {
	Surf_Entity = NULL ;
	x = 0 ;				//x position on entity on map
	y = 0 ;				//y position of entity on map
	xVel = 0 ;
	yVel = 0 ;
	yGravityVel = 1 ;	//constant velocity downwards to simulate gravity
	width = 0 ;
	height = 0 ;
	frame = 0 ;
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


//get and set functions for protected data members needed outside of CEntity and classes inheriting from CEntity
int CEntity::getX() {
	return x ;
}

int CEntity::getY() {
	return y ;
}

void CEntity::setX(int _x) {
	if(x > 0 && x+width < WINDOW_WIDTH) x = _x ;
}

void CEntity::setY(int _y) {
	if(y > 0 && y+height < WINDOW_HEIGHT) y = _y ;
}

int CEntity::getWidth() {
	return width ;
}

int CEntity::getHeight() {
	return height ;
}

int CEntity::getXVel() {
	return xVel ;
}

int CEntity::getYVel() {
	return yVel ;
}

void CEntity::setXVel(int _xVel) {
	xVel = _xVel ;
}

void CEntity::setYVel(int _yVel) {
	yVel = _yVel ;
}
