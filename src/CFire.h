/*
 * DonkeyKong
 * CFire.h
 * This file contains the interface for CFire class, inheriting from CEntity.
*/

#ifndef CFIRE_H
#define CFIRE_H

#include "CEntity.h"
#include "Define.h"

#include <iostream>
using namespace std ;

enum fireState{			//values for state private data member
	FIRE_WALKING = 0 , 	//state when fire is moving horizontally along platform	
	FIRE_CLIMBING ,		//state when the fire follows Mario up a platform
	FIRE_ATTACKING 		//state when fire collides with Mario and ends his worthless life.
} ;

class CFire : public CEntity {
	public:
		CFire();

		virtual void OnLoop() ;
		virtual void OnRender(SDL_Surface* Surf_Display) ;

		void set_clips() ;

		int getState() ;
		void setState(fireState) ;
	
	private:
		fireState state ;	//defined by enum fireState above

		SDL_Rect clipsRight[3];
		SDL_Rect clipsLeft[3];
		SDL_Rect clipsUp[2];

};


#endif
