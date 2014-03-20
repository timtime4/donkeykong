/*
 * DonkeyKong
 * CSurface.h
 * This file is the interface for the CSurface class.  Objects of this class are not instantiated, but the functions are used to load files and render surfaces to the screen.  The member functions are declared static so they can be used without instantiating the objects.
*/

#ifndef CSURFACE_H
#define CSURFACE_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

using namespace std ;

class CSurface {
	public:
		CSurface() ;

		//functions declared static so no CSurface object is required to call them
		static SDL_Surface* OnLoad(string file) ;	//called when loading image file
		static int OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int x, int y) ;
		static int OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int x, int y, int x2, int y2, int w, int h) ;	//overloaded with more arguments

		static int Transparent(SDL_Surface* Surf_Dest, int r, int g, int b) ;

	private:

};

#endif
