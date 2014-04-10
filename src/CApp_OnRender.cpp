/*
 * DonkeyKong
 * CApp_OnRender.cpp
 * This file contains the implementation of the OnRender() function of class CApp.  This function renders all Surfaces to Surf_Display)
*/

#include "CApp.h"

void CApp::OnRender() {

	int i ;

	SDL_FillRect(Surf_Display, &Surf_Display->clip_rect, SDL_MapRGB(Surf_Display->format, 0, 0, 0)) ;	//fills the background with black


	for (int j = 0 ; j < bgObjs.size(); j++) {
		if(!bgObjs[j]) continue ;
		bgObjs[j]->OnRender(Surf_Display, Surf_bgObjs) ;
	}

	CSurface::OnDraw(Surf_Display, Surf_Highscore, 180, 10) ;
	
	for(i = 0 ; i < entityList.size() ; i++ ) { //renders each valid entity to Surf_Display data member of CApp
		if(!entityList[i]) continue ;
		entityList[i]->OnRender(Surf_Display) ;	
	}

	//display mario's picture to represent nubmer of lives remaining	
	for (i = 0 ; i < mario.getLives(); i++) {
		CSurface::OnDraw(Surf_Display, Surf_Lives, i*25, 0) ;
	}
	
	SDL_Flip(Surf_Display) ;	//update screen
}
