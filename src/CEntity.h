/*
 * DonkeyKong
 * CEntity.h
 * This file contains the interface for the CEntity class.
*/

#ifndef CENTITY_H
#define CENTITY_H

#include <vector>
#include <string>

#include "CSurface.h"
#include "Define.h"
using namespace std ;

class CEntity {
	public:
		CEntity() ;	
		virtual ~CEntity() ;

		int OnLoad(string) ;
		virtual void OnLoop() = 0;	//
		virtual void OnRender(SDL_Surface* Surf_Display) = 0 ; 
		void OnCleanup() ;

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

	protected:	//data members will be accessible to inheriting classes
		SDL_Surface* Surf_Entity ;

		int x ;		//x,y location where blitted on screen
		int y ; 
		int xVel ;	//horizontal and vertical velocity of entity
		int yVel ;	
		int yGravityVel ;	//accounts for gravity- entities have the tendency to move downwards unless colliding with a platform or ladder, gravity here treated as a constant negative velocity to simplify collision with ground

		int frame;	//keeps track of which frame in animation to use
		int maxFrames ;	//total number of frames for a given status
		int status;	//keeps track of which animation to show (left or right)
		int width ;	//width of one frame
		int height ;	//height of one frame
		
	private: 
	
} ;

#endif
