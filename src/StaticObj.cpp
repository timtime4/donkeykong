/*
 * DonkeyKong
 * StaticObj.cpp
 * This file contains the implementation for the StaticObj class, an abstract class of objects that make up the static framework
 * of the game. 
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
