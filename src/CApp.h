/*
***
 * DonkeyKong
 * CApp.h
*/
#ifndef CAPP_H
#define CAPP_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#include "CSurface.h"
#include "CEntity.h"
#include "CMario.h"
#include "StaticObj.h"
#include "Ladder.h"	
#include "Platform.h"
#include "CTimer.h"
#include "Define.h"

#include <iostream>
#include <vector>
using namespace std ;

class CApp {	
	public :
		CApp() ;
		int OnExecute() ;

		//overarching video game functions
		int OnInit() ;
		int OnEvent(SDL_Event* Event) ;
		void OnLoop() ;
		void OnRender() ;
		void OnCleanup() ;

	private :
		int OnInit_Static() ;	//helper function to initialize all static data members

		int running ;	//condition for while loop
		SDL_Surface* Surf_Display ;	//"blank piece of paper"
		SDL_Surface* Surf_bgObjs ;

		CTimer fps ;	//timer object

		vector< Platform > platforms ;	//vector to hold all instantiated Platform objects
		vector< Ladder > ladders  ;	//vector to hold all ladder objects

		vector< StaticObj* > bgObjs ;	//vector of pointers to all static "background" objects (Ladders and Platforms), used to invoke polymorphic behavior

		vector< CEntity* > entityList ;	//vector of pointers to all entities

		TTF_Font* font ;
		SDL_Surface* Surf_Highscore ;
		SDL_Color textColor ;	

		CMario mario ;
		//CEntity peach ;	//peach entity object, only animated to move left and right

		// Music
		Mix_Music *theme ;
		// Sound effects
		Mix_Chunk *jumps ;
		Mix_Chunk *burns ;
		Mix_Chunk *hurts ;

		int score ;


} ;

#endif
