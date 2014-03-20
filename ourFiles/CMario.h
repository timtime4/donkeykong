/*
 * DonkeyKong
 * CMario.h
 * This file contains the interface for CMario class, inheriting from CEntity.
*/

#ifndef CMARIO_
#define CMARIO_

#include "CEntity.h"

class CMario.h : public CEntity {
	public:
		CMario() ;

		virtual int OnLoad(string, int, int, int) ;
		virtual void OnLoop() ;
		virtual void OnRender(SDL_Surface* Surf_Display) ;
		virtual void OnCleanup() ;

		int getLives() ;
		//void setLives(int) ;

	private:
		int lives ;
		



};


#endif
