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
#include "CPeach.h"
#include "CDonkeyKong.h"
#include "CFire.h"
#include "CBarrel.h"
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
		int OnStartup(SDL_Event* Event) ;
		int OnEvent(SDL_Event* Event) ;
		int OnGameover(SDL_Event* Event) ;				
		void OnLoop() ;
		void OnRender() ;
		void OnCleanup() ;

	private :
		int OnInit_Static() ;	//helper function to initialize all static data members
		
		SDL_Surface* Surf_Display ;	//"blank piece of paper"
		int running ;	//condition for while loop
		int game ;	//condition for bigger while loop (can keep playing games even after gameover)
		CTimer fps ;	//timer object

		SDL_Surface* Surf_bgObjs ;
		vector< StaticObj* > bgObjs ;	//vector of pointers to all static "background" objects (Ladders and Platforms), used to invoke polymorphic behavior
		vector< Platform > platforms ;	//vector to hold all instantiated Platform objects
		vector< Ladder > ladders  ;	//vector to hold all ladder objects

		vector< CEntity* > entityList ;	//vector of pointers to all entities
		CMario mario ;
		CPeach peach ;	//peach entity object, only animated to move left and right
		CDonkeyKong dk;
		CFire fire;
		CBarrel barrel;


		SDL_Surface* Surf_Highscore ;
		TTF_Font* font ;
		SDL_Color textColor ;	
		string hsString ;
		int score ;

		SDL_Surface* Surf_Menu ;	//surface for displaying start up menu screen
		SDL_Surface* Surf_Controls ;
		SDL_Surface* Surf_Gameover ;
		int displayControls ;		//when true, start up screen displays the controls needed to play the game 

		// Music
		Mix_Music *theme ;
		// Sound effects
		Mix_Chunk *jumps ;
		Mix_Chunk *burns ;
		Mix_Chunk *hurts ;

		int dyingCount ;

		SDL_Surface* Surf_Lives ;



} ;

#endif
