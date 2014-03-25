/*
 * DonkeyKong
 * StaticObj.h
 * Abstract class that is inherited by Platform and Ladder classes.  Is meant for objects in game that are unchanging on the screen, but are interacted with.
*/

#ifndef STATICOBJ_H
#define STATICOBJ_H

#include "SDL/SDL.h"

#include "CSurface.h"
#include "Define.h"

class StaticObj {
	public:
		StaticObj() ;	//constructor
		void OnInit(int, int, int, int) ;	//initialize data members
		void OnRender(SDL_Surface*, SDL_Surface*) ;	//for rendering object to screen in correct location
		int getX() ;
		int getY() ;
		void setX(int) ;
		void setY(int) ;
		int getWidth() ;
		int getHeight() ;
		void setWidth(int) ;
		void setHeight(int) ;		
		int getXBlit() ;
		int getYBlit() ;
		void setXBlit(int) ;
		void setYBlit(int) ;

	private:
		int x ;		//x, y location on screen
		int y ;
		int width ;	//width of object blitted
		int height ;	//height of object blitted
		int xBlit ;	//x, y desired location from staticObjects.png file
		int yBlit ;

};

#endif
