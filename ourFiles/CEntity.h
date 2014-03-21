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

using namespace std ;

class CEntity {
	public:
		CEntity() ;	
		virtual ~CEntity() ;

		virtual int OnLoad(string, int, int, int) ;
		virtual void OnLoop() ;
		virtual void OnRender(SDL_Surface* Surf_Display) ; 
		virtual void OnCleanup() ;

		static std::vector<CEntity*> entityList ;		//exists before object instantiation, only one

		int getX() ;
		int getY() ;
		void setX(int) ;
		void setY(int) ;

		int getWidth() ;
		int getHeight() ;
		void setWidth(int) ;
		void setHeight(int) ;

		int getAnimState() ;
		void setAnimState(int) ;	
		
	protected:
		CAnimation Anim_Control ;
		SDL_Surface* Surf_Entity ;

	private:
		int x ;		//x,y location where blitted on screen
		int y ; 
		int width ;
		int height ;
		int animState ;	
} ;

#endif
