/*
 * DonkeyKong
 * CApp_OnRender.cpp
 * This file contains the implementation of the OnRender() function of class CApp.  This function renders all Surfaces to Surf_Display)
*/

#include "CApp.h"

void CApp::OnRender() {
	//cout << bgObjs[0]->getX() << " " << bgObjs[0]->getY() << " " << bgObjs[0]->getXBlit() << " " << bgObjs[0]->getYBlit() << endl ;

	for (int j = 0 ; j < bgObjs.size(); j++) {
		if(!bgObjs[j]) continue ;
		bgObjs[j]->OnRender(Surf_Display, Surf_bgObjs) ;
	}

	//CSurface::OnDraw(Surf_Display, Surf_Highscore, 200, 10) ;
	
	/*for(int i = 0 ; i < CEntity::entityList.size() ; i++ ) {
		if(!CEntity::entityList[i]) continue ;
		CEntity::entityList[i]->OnRender(Surf_Display) ;	//renders each valid entity to Surf_Display data member of CApp
	}*/
	
/*	for(int j = 0 ; j < ladders.size() ; j++) {
		ladders[j].OnRender(Surf_Display, Surf_StaticObjs) ;
	}

	p1.OnRender(Surf_Display, Surf_bgObjs) ;
*/


///////////THIS COMPILES AND WORKS CORRECTLY////////////
	/*Platform p2(300, 200) ;
	vector< StaticObj*> ptrs ;
	ptrs.push_back(&p2) ;
	Platform p1(100, 50) ;
	ptrs.push_back(&p1) ;
	for(int i = 0 ; i < ptrs.size() ; i++) ptrs[i]->OnRender(Surf_Display, Surf_bgObjs) ;
*/
/////////COMPARE THIS TO CAPP_ONINIT_STATIC/////////////////



	SDL_Flip(Surf_Display) ;	//update screen
	//cout << "OnRender finished executing" << endl ;
}
