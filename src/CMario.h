/*
 * DonkeyKong
 * CMario.h
 * This file contains the interface for CMario class, inheriting from CEntity.
*/

#ifndef CMARIO_H
#define CMARIO_H

#include "CEntity.h"
#include "Define.h"

#include <iostream>
using namespace std ;

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

		int getClimbing() ;
		void setClimbing(int) ;	
	
		void setWalking(int) ;
	
	private:
		int lives ;
		marState state ;	//normal, hammer, star
		//mario's capabilities- 1 when turned on, 0 when off
		int walking ;	
		int jumping ;
		int hurting ;	//when dead
		int climbing ;	//when colliding with a ladder


		SDL_Rect clipsRight[3];
		SDL_Rect clipsLeft[3];
		SDL_Rect clipsHurtR[3];
		SDL_Rect clipsHurtL[3];
		SDL_Rect clipsUp[2];

};


#endif
