/*
 * DonkeyKong
 * CMario.h
 * This file contains the interface for CMario class, inheriting from CEntity.
*/

#ifndef CMARIO_H
#define CMARIO_H

#include "CEntity.h"

/*enum {		//values for state private data member
	MARIO_STATE_NORMAL = 0 , 	//no power up
	MARIO_STATE_HAMMER ,
	MARIO_STATE_STAR
}*/
#define MARIO_WIDTH 50
#define MARIO_HEIGHT 65
#define MARIO_RIGHT 0
#define MARIO_LEFT 1


class CMario : public CEntity {
	public:
		CMario() ;

		int OnLoadMario(string) ;
		virtual void OnLoop() ;
		virtual void OnRender(SDL_Surface* Surf_Display) ;
		//virtual void OnCleanup() ;

		void set_clips() ;
		void handle_input(SDL_Event*) ;

		int getLives() ;
		//void setLives(int) ;
	

	private:
		int lives ;
		int state ;	//normal, hammer, star
		SDL_Rect clipsRight[2];
		SDL_Rect clipsLeft[2];
};


#endif
