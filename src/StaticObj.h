/*
 * DonkeyKong
 * StaticObj.h
 * (to be) Abstract class that is inherited by Platform and Ladder classes.  Is meant for objects in game that are unchanging on the screen, but are interacted with-- mario can
 * collide with them.
*/

#ifndef STATICOBJ_H
#define STATICOBJ_H

#include "SDL/SDL.h"

#include "CSurface.h"
#include "CMario.h"
#include "Define.h"

#include <iostream>
using namespace std ;

class StaticObj {
	public:
		StaticObj() ;	//constructor
		void OnInit(int, int, int, int) ;	//initialize data members
		void OnRender(SDL_Surface*, SDL_Surface*) ;	//for rendering object to screen in correct location
		virtual int IsCollision(CMario&) = 0 ;	//pure virtual function that checks for a collision of Mario with the object, returns 1 on collision, CMario object passed by reference so original in CApp class can be modified by the function

		//set and get functions for private data members
		/*int getX() ;
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
*/
	protected:
		int x ;		//x, y location on screen
		int y ;
		int width ;	//width of object blitted
		int height ;	//height of object blitted
		int xBlit ;	//x, y desired location from staticObjects.png file
		int yBlit ;

	private:

};

#endif
