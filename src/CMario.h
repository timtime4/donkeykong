/*
 * DonkeyKong
 * CMario.h
 * This file contains the interface for CMario class, inheriting from CEntity.
*/

#ifndef CMARIO_H
#define CMARIO_H

#include "CEntity.h"
#include "Define.h"


enum marState{		//values for state private data member
	MARIO_WALKING , 	//state when mario is standing still or walking on a platform
	MARIO_JUMPING ,		//state of mario during a jump (in the air)-- disable SPACE arrow key event
	MARIO_CLIMBING ,	//state of mario while climbing a ladder -- disable L R arrow key events 
	MARIO_HURTING 		//state of mario when dies
} ;

class CMario : public CEntity {
	public:
		CMario() ;

		virtual void OnLoop() ;
		virtual void OnRender(SDL_Surface* Surf_Display) ;

		void set_clips() ;

		int getLives() ;
		//void setLives(int) ;

		int getState() ;
		void setState(marState) ;

		void setUp(int) ;

		int getLadderCollide() ;
		void setLadderCollide(int) ;

		int getPlatformCollide() ;
		void setPlatformCollide(int) ;
	
	private:
		int lives ;
		marState state ;	//defined by enum marState above
		int up ;		//greater than 0 when mario is in the middle of a jump
		int ladderCollide ;	//true when mario is currenly colliding with a ladder
		int platformCollide ;


		SDL_Rect clipsRight[3];
		SDL_Rect clipsLeft[3];
		SDL_Rect clipsHurtR[3];
		SDL_Rect clipsHurtL[3];
		SDL_Rect clipsUp[2];

};


#endif
