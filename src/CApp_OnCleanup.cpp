/*
 * DonkeyKong
 * CApp_OnCleanup.cpp
 * This file contains the member function OnCleanup() for the class CApp.
*/

#include "CApp.h"

void CApp::OnCleanup() {

	SDL_FreeSurface(Surf_Display) ;

	for (int i = 0 ; i < entityList.size() ; i++) {
		if(!entityList[i]) continue ;
		entityList[i]->OnCleanup() ;
	}
	entityList.clear() ;
	//peach.OnCleanup() ;
	
	SDL_FreeSurface(Surf_bgObjs) ;
	bgObjs.clear() ;

	SDL_FreeSurface(Surf_Highscore) ;

	Mix_FreeChunk ( burns );		// Free the sound effects
	Mix_FreeChunk ( hurts );
	Mix_FreeChunk ( jumps );
	Mix_FreeMusic ( theme );		// Free the music

	Mix_CloseAudio();			// Quit SDL_mixer

	SDL_Quit() ; 
}
