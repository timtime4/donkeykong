/*
***
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
#include "StaticObj.h"
#include "Ladder.h"	
#include "Platform.h"

#include "Define.h"

#include <iostream>
#include <vector>
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
		int OnInit_Static() ;	//helper function to initialize all static data members

		int running ;	//condition for while loop
		SDL_Surface* Surf_Display ;	//"blank piece of paper"
		SDL_Surface* Surf_bgObjs ;


		vector< Platform > platforms ;	//vector to hold all instantiated Platform objects
		vector< Ladder > ladders  ;	//vector to hold all ladder objects

		vector< StaticObj*> bgObjs ;	//vector of pointers to all static "background" objects (Ladders and Platforms), used to invoke polymorphic behavior

		//TTF_Font* font ;
		//SDL_Surface* Surf_Highscore ;
		//SDL_Color textColor ;	

//		CEntity marioEntity ;

} ;

#endif
