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
	MARIO_STATE_NORMAL = 0 , 	//no power up
	MARIO_STATE_HAMMER ,
	MARIO_STATE_STAR
} ;

class CMario : public CEntity {
	public:
		CMario() ;

		virtual void OnLoop() ;
		virtual void OnRender(SDL_Surface* Surf_Display) ;

		void set_clips() ;
		void handle_input(SDL_Event*) ;

		int getLives() ;
		//void setLives(int) ;
	
	private:
		int lives ;
		marState state ;	//normal, hammer, star
		SDL_Rect clipsRight[3];
		SDL_Rect clipsLeft[3];
		SDL_Rect clipsHurtR[3];
		SDL_Rect clipsHurtL[3];
		SDL_Rect clipsUp[2];
		int walking ;
		int jumping ;
		int hurting ;
		int climbing ;

};


#endif
