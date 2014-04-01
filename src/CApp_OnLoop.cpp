/*
 * DonkeyKong
 * CApp_OnLoop.cpp
 * This file contains the implemenation of OnLoop() function of CApp class.  This function performs all necessary updates each time through the OnExecute() loop.
*/

#include "CApp.h"

void CApp::OnLoop() {

	/*for (int i = 0 ; i < CEntity::entityList.size() ; i++) {
		if(!CEntity::entityList[i]) continue ;	//NULL pointer check
		CEntity::entityList[i]->OnLoop() ;	//updates each valid entity
	}*/
	mario.OnLoop() ;

	int dummy ;
	for (int i = 0 ; i < bgObjs.size() ; i++) {
		dummy = bgObjs[i]->IsCollision(mario) ;
	}

}

