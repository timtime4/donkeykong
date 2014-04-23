/*
 * DonkeyKong
 * CMario.h
 * This file contains the interface for CMario class.
*/

#ifndef CMARIO_H
#define CMARIO_H

#include "CSurface.h"
#include "Define.h"
#include <string>

using namespace std ;

enum marState{		//values for state private data member
	MARIO_WALKING , 	//state when mario is standing still or walking on a platform
	MARIO_JUMPING ,		//state of mario during a jump (in the air)-- disable SPACE arrow key event
	MARIO_CLIMBING ,	//state of mario while climbing a ladder -- disable L R arrow key events 
	MARIO_HURTING 		//state of mario when dies
} ;

class CMario {
	public:
		CMario() ;

		void reset() ;

		int OnLoad(string) ;
		void OnLoop() ;
		void OnRender(SDL_Surface* Surf_Display) ;
		void OnCleanup() ;

		void set_clips() ;

		CMario operator++() ;	//overloaded pre-increment, indicates mario got an extra life
		CMario operator--() ;	//overloaded pre-decrement, indicates loss of life for mario
		int getLives() ;
		void setLives(int) ;

		int getX() ;
		int getY() ;
		void setX(int) ;
		void setY(int) ;

		int getWidth() ;
		int getHeight() ;

		int getXVel() ;
		int getYVel() ;
		void setXVel(int) ;
		void setYVel(int) ;

		void setStatus(int) ;

		int getState() ;
		void setState(marState) ;

		void setUp(int) ;	//set function for up variable

		int getLadderCollide() ;
		void setLadderCollide(int) ;
		int getPlatformCollide() ;
		void setPlatformCollide(int) ;
	
	private:
		SDL_Surface* Surf_Entity ;
		int x ;			//x,y location where blitted on screen
		int y ; 
		int xVel ;		//horizontal and vertical velocity of entity
		int yVel ;	
		int yGravityVel ;	//downward velocity due to gravity (simplification for acceleration)
		int frame;		//keeps track of which frame in animation to use
		int maxFrames ;		//total number of frames for a given status
		int status;		//keeps track of which animation to show (left or right)
		int width ;		//width of one frame
		int height ;		//height of one frame

		int lives ;
		marState state ;	//defined by enum marState above
		int up ;		//greater than 0 when mario is in the middle of a jump
		int ladderCollide ;	//true when mario is currenly colliding with a ladder
		int platformCollide ;	//true when mario is standing on a platform

		SDL_Rect clipsRight[3];
		SDL_Rect clipsLeft[3];
		SDL_Rect clipsHurtR[3];
		SDL_Rect clipsHurtL[3];
		SDL_Rect clipsUp[2];

};


#endif
