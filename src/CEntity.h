/*
 * DonkeyKong
 * CEntity.h
 * This file contains the interface for the CEntity class.  For this project, an Entity is any nonstatic object that can interact with mario.  Inheriting classes include CFire, CBarrel, CPeach, and CDonkeyKong.  Because entities will interact with mario, CMario had to be defined as a separate class, not inheriting from CEntity, to avoid circular dependencies.
*/

#ifndef CENTITY_H
#define CENTITY_H

#include <vector>
#include <string>

#include "SDL/SDL_mixer.h"
#include "CSurface.h"
#include "CMario.h"
#include "Define.h"

#include <iostream>
using namespace std ;

class CEntity {
	public:
		CEntity() ;	

		int OnLoad(string) ;
		virtual void OnLoop() = 0;
		virtual void OnRender(SDL_Surface* Surf_Display) = 0 ; 
		void OnCleanup() ;

		virtual int IsCollision(CMario&) ;		//virtual function for determining if an entity has collided with mario
		//virtual void playSoundEffect() ;

		virtual int identifyType() = 0 ;		//used to determine which inheriting type a CEntity object is, for determining the sound effect to be played with a collision; CFire = 1, CBarrel = 2, CDonkeyKong = 3, CPeach = 4

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

		int getLadderCollide();
		void setLadderCollide(int) ;
		int getPlatformCollide() ;
		void setPlatformCollide(int) ;

	protected:			//data members will be accessible to inheriting classes
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

		int platformCollide ;
		int ladderCollide ;
		
	private: 
	
} ;

#endif
