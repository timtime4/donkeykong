/*
 * DonkeyKong
 * CApp_OnCleanup.cpp
 * This file contains the member function OnCleanup() for the class CApp.
*/

#include "CApp.h"

void CApp::OnCleanup() {

	for (int i = 0 ; i < CEntity::entityList.size() ; i++) {
		if(!CEntity::entityList[i]) continue ;
		CEntity::entityList[i]->OnCleanup() ;
	}
	CEntity::entityList.clear() ;

	SDL_FreeSurface(Surf_Background) ;
	SDL_FreeSurface(Surf_Display) ;
	SDL_FreeSurface(Surf_Highscore) ;

	SDL_Quit() ;	//frees Surf_Display, quits SDL
}
