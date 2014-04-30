/*
 * DonkeyKong
 * CApp_OnRender.cpp
 * This file contains the implementation of the OnRender() function of class CApp.
 * This function renders all Surfaces to Surf_Display)
*/

#include "CApp.h"

void CApp::OnRender() {

	int i ;

	//fill background with black
	SDL_FillRect(Surf_Display, &Surf_Display->clip_rect, SDL_MapRGB(Surf_Display->format, 0, 0, 0) ) ;

	//ladders and platforms
	for (int j = 0 ; j < bgObjs.size(); j++) {
		if(!bgObjs[j]) continue ;
		bgObjs[j]->OnRender(Surf_Display, Surf_bgObjs) ;
	}

	//all entities (dk, barrels, fire, peach)
	for(i = 0 ; i < entityList.size() ; i++ ) { //renders each valid entity to Surf_Display data member of CApp
		if(!entityList[i]) continue ;
		entityList[i]->OnRender(Surf_Display) ;	
	}
	peach.OnRender(Surf_Display) ;
	//mario
	mario.OnRender(Surf_Display) ;

	//score information
	CSurface::OnDraw(Surf_Display, Surf_Highscore, 180, 0) ;
	CSurface::OnDraw(Surf_Display, Surf_Score, 0, 0) ;
	if(displayPoints > 0) {		//true when mario has just earned points, display the +200/+1500 when gain points
		CSurface::OnDraw(Surf_Display, Surf_Points, pointsX, pointsY) ;
		displayPoints++ ;
		if(displayPoints > 5) displayPoints = 0 ;
	}

	//display mario's picture to represent nubmer of lives remaining	
	for (i = 0 ; i < mario.getLives(); i++) {
		CSurface::OnDraw(Surf_Display, Surf_Lives, WINDOW_WIDTH - (i+1)*25, 0) ;
	}
	
	SDL_Flip(Surf_Display) ;	//update screen
}
