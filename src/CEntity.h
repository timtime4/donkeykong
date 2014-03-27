/*
 * DonkeyKong
 * CEntity.h
 * This file contains the interface for the CEntity class.
*/

#ifndef CENTITY_H
#define CENTITY_H

#include <vector>
#include <string>

#include "CAnimation.h"
#include "CSurface.h"
#include "Define.h"
using namespace std ;

class CEntity {
	public:
		CEntity() ;	
		virtual ~CEntity() ;

		virtual int OnLoad(string, int, int, int) ;
		virtual void OnLoop() ;
		virtual void OnRender(SDL_Surface* Surf_Display) ; 
		void OnCleanup() ;

		static std::vector<CEntity*> entityList ;		//exists before object instantiation, only one

	protected:
		CAnimation Anim_Control ;
		SDL_Surface* Surf_Entity ;
		int x ;		//x,y location where blitted on screen
		int y ; 
		int xVel ;
		int yVel ;
		int frame;			// Keeps track of which frame in animation to use
		int status;			// Keeps track of which animation to show (left or right)

		int width ;
		int height ;
		int animState ;	

		
	private: 
	
} ;

#endif
