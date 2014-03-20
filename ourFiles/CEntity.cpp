/*
 * DonkeyKong
 * CEntity.cpp
 * This file contains the implementation of CEntity class.
*/

#include "CEntity.h"

std::vector<CEntity*> CEntity::entityList ;	

CEntity::CEntity() {
	Surf_Entity = NULL ;
	x = 0 ;
	y = 0 ;
	width = 0 ;
	height = 0 ;
	animState = 0 ;
}

CEntity::~CEntity() {
	//empty deconstructor definition
}

int CEntity::OnLoad(string file, int _width, int _height, int maxFrames) {
	Surf_Entity = CSurface::OnLoad(file.c_str()) ;
	if(Surf_Entity == NULL) return 0 ;

	CSurface::Transparent(Surf_Entity, 255, 255, 255) ;	//not working - because of color or function?

	width = _width ;
	height = _height ;

	Anim_Control.setMaxFrames(maxFrames) ;

	return 1 ;
}

void CEntity::OnLoop() {
	Anim_Control.OnAnimate() ;
}

void CEntity::OnRender(SDL_Surface* Surf_Display) {
	if(Surf_Entity == NULL || Surf_Display == NULL) return ;
	CSurface::OnDraw(Surf_Display, Surf_Entity, x, y, Anim_Control.getCurrentFrame()*width, animState*height, width, height) ;
}

void CEntity::OnCleanup() {
	if(Surf_Entity) SDL_FreeSurface(Surf_Entity) ;
	Surf_Entity = NULL ;
}

int CEntity::getX() {
	return x ;
}

int CEntity::getY() {
	return y;
}

void CEntity::setX(int _x) {	//should also check for window width/height
	if(_x < 0) x = 0 ;
	else x = _x ;
}

void CEntity::setY(int _y) {
	if(_y < 0) y = 0 ;
	else y = _y ;
}

int CEntity::getWidth() {
	return width ;
}

int CEntity::getHeight() {
	return height ;
}

void CEntity::setWidth(int w) {
	if(w < 0) width = 0 ;
	else width = w ;
}

void CEntity::setHeight(int h) {
	if(h < 0) height = 0 ;
	else height = h ;
}

int CEntity::getAnimState() {
	return animState ;
}

void CEntity::setAnimState(int state) {
	animState = state ;
}



