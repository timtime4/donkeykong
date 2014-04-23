/*
 * DonkeyKong
 * CEntity.cpp
 * This file contains the implementation of CEntity class. 
*/

#include "CEntity.h"


CEntity::CEntity() {
	Surf_Entity = NULL ;
	x = 0 ;				//x position on entity on map
	y = 0 ;				//y position of entity on map
	xVel = 0 ;
	yVel = 0 ;
	yGravityVel = 3 ;	//constant velocity downwards to simulate gravity
	width = 0 ;
	height = 0 ;
	frame = 0 ;
	maxFrames = 0 ;
	status = 0 ;
}


int CEntity::OnLoad(string file) {
	Surf_Entity = CSurface::OnLoad(file.c_str()) ;
	if(Surf_Entity == NULL) return 0 ;
	return 1 ;
}


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

void CEntity::setStatus(int _status) {
	status = _status ;
}
