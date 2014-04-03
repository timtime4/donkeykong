/*
 * DonkeyKong
 * CApp_OnRender.cpp
 * This file contains the implementation of the OnRender() function of class CApp.  This function renders all Surfaces to Surf_Display)
*/

#include "CApp.h"

void CApp::OnRender() {

	SDL_FillRect(Surf_Display, &Surf_Display->clip_rect, SDL_MapRGB(Surf_Display->format, 0, 0, 0)) ;	//fills the background with black


	for (int j = 0 ; j < bgObjs.size(); j++) {
		if(!bgObjs[j]) continue ;
		bgObjs[j]->OnRender(Surf_Display, Surf_bgObjs) ;
	}

	CSurface::OnDraw(Surf_Display, Surf_Highscore, 180, 10) ;
	
	for(int i = 0 ; i < entityList.size() ; i++ ) { //renders each valid entity to Surf_Display data member of CApp
		if(!entityList[i]) continue ;
		entityList[i]->OnRender(Surf_Display) ;	
	}


	//peach.OnRender(Surf_Display) ;
	
	SDL_Flip(Surf_Display) ;	//update screen
}
