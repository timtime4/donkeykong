/*
 * DonkeyKong
 * CApp_OnRender.cpp
 * This file contains the implementation of the OnRender() function of class CApp.  This function renders all Surfaces to Surf_Display)
*/

#include "CApp.h"

void CApp::OnRender() {

	CSurface::OnDraw(Surf_Display, Surf_Background, 0, 0) ; 

	for(int i = 0 ; i < CEntity::entityList.size() ; i++ ) {
		if(!CEntity::entityList[i]) continue ;
		CEntity::entityList[i]->OnRender(Surf_Display) ;	//renders each valid entity to Surf_Display data member of CApp
	}

	SDL_Flip(Surf_Display) ;	//update screen
}
