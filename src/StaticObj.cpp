/*
 * DonkeyKong
 * StaticObj.cpp

Just adding comments to try to get files to commit - Tim
*/

#include "StaticObj.h"

StaticObj::StaticObj() {
	x = 0 ;
	y = 0 ;
	width = 0 ;
	height = 0 ;

	xBlit = -1 ;	//dummy variables before they are initialized by derived classes
	yBlit = -1 ;	
}

void StaticObj::OnInit(int _x, int _y, int _width, int _height) {
	x = _x ;	//location on main surface
	y = _y ;
	width = _width ;
	height = _height ;
}

void StaticObj::OnRender(SDL_Surface* Surf_Display, SDL_Surface* Surf_ImgFile) {
	if(Surf_Display != NULL && Surf_ImgFile != NULL ) {
		CSurface::OnDraw(Surf_Display, Surf_ImgFile, x, y, xBlit, yBlit, width, height) ;
	}
}

/*int StaticObj::getX() {
	return x ;
}

int StaticObj::getY() {
	return y ;
}

void StaticObj::setX(int _x) {
	if(_x >= 0 && _x < WINDOW_WIDTH) x = _x ;	//else x does not change
}

void StaticObj::setY(int _y) {
	if(_y >= 0 && _y < WINDOW_HEIGHT) y = _y ;	//else y does not change
}

int StaticObj::getWidth() {
	return width ;
}

int StaticObj::getHeight() {
	return height ;
}

void StaticObj::setWidth(int w) {
	if(w >= 0) width = w ;
}

void StaticObj::setHeight(int h) {
	if(h >= 0) height = h ;
}

int StaticObj::getXBlit() {
	return xBlit ;
}

int StaticObj::getYBlit() {
	return yBlit ;
}

void StaticObj::setXBlit(int _x) {
	if(_x >= 0 && x <= 100) xBlit = _x ;	//constraints from staticObjects.png
}

void StaticObj::setYBlit(int _y) {
	if(_y >= 0 && y <= 120) yBlit = _y ;
}*/
