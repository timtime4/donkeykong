/*
 * DonkeyKong
 * CBarrel.h
 * This file contains the interface for CBarrel class, inheriting from CEntity.
*/

#ifndef CBARREL_H
#define CBARREL_H

#include "CEntity.h"
#include "Define.h"
#include "CMario.h"

#include <iostream>
using namespace std ;


class CBarrel : public CEntity {
	public:
		CBarrel();

		virtual void OnLoop() ;
		virtual void OnRender(SDL_Surface* Surf_Display) ;

		virtual int identifyType() ;

		void set_clips();

		int getPlatformCollide() ;
		void setPlatformCollide(int);

		void reset() ;
	
	private:
		SDL_Rect clips[3];
		int moved;
		int direction;
		int platformCollide ;
		int resetCount ;
};


#endif
