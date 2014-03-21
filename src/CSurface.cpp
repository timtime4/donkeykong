/*
 * DonkeyKong
 * CSurface.cpp
 * This file contains implementation of CSurface member functions.
*/

#include "CSurface.h"

CSurface::CSurface() {
	//empty constructor
}

SDL_Surface* CSurface::OnLoad(std::string file) {
	SDL_Surface* Surf_Temp = NULL ;		//initial image loaded, not optimized
	SDL_Surface* Surf_Return = NULL ;	//optimized surface that will be returned

	Surf_Temp = IMG_Load(file.c_str()) ;	//loads BMP files
	if (Surf_Temp == NULL) {
		return NULL ;
	}

	Surf_Return = SDL_DisplayFormatAlpha(Surf_Temp) ;
	SDL_FreeSurface(Surf_Temp) ;	//frees memory taken by the surface

	return Surf_Return ;

}

int CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int x, int y) {	//(x,y) location of placement of Surf_Src on Surf_Dest
	if (Surf_Dest == NULL || Surf_Src == NULL) {
		return 0 ;	//must have a valid source and destination surfaces for blitting
	}

	SDL_Rect DestR ;	//data members- x, y, w, h ; only concerned with x, y (where drawing, offsets)
	DestR.x = x ;
	DestR.y = y ;

	SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR) ;

	return 1 ;	//successfully blitted image
}

int CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int x, int y, int x2, int y2, int w, int h) {
	if(Surf_Dest == NULL || Surf_Src == NULL) {
		return 0 ;
	}

	SDL_Rect DestR ;
	DestR.x = x ;
	DestR.y = y ;

	SDL_Rect SrcR ;	//specify the pixels of the source file to blit to the destination file
	SrcR.x = x2 ;
	SrcR.y = y2 ;
	SrcR.w = w ;
	SrcR.h = h ;

	SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR) ;

	return 1 ;	
}

int CSurface::Transparent(SDL_Surface* Surf_Dest, int r, int g, int b) {
	if(Surf_Dest == NULL) {
		return 0 ;
	}

	SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, r, g, b)) ;	//rgb correspond to color to make transparent

	return 1 ;
}


