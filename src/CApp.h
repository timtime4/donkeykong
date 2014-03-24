/*
 * DonkeyKong
 * CApp.h
*/
#ifndef CAPP_H
#define CAPP_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

#include "CEvent.h"
#include "CSurface.h"
#include "CAnimation.h"
#include "CEntity.h"

#include "Define.h"

#include <iostream>
using namespace std ;

class CApp : public CEvent {	//inherits from CEvent class
	public :
		CApp() ;
		int OnExecute() ;

		//overarching video game functions
		int OnInit() ;
		void OnEvent(SDL_Event* Event) ;
			void OnExit() ;
		void OnLoop() ;
		void OnRender() ;
		void OnCleanup() ;


	private :
		int running ;	//condition for while loop
		SDL_Surface* Surf_Display ;	//"blank piece of paper"
		SDL_Surface* Surf_Background ;

		TTF_Font* font ;
		SDL_Surface* Surf_Highscore ;
		SDL_Color textColor ;	

		CEntity marioEntity ;

} ;

#endif
