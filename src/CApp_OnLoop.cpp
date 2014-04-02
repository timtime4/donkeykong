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
	mario.setState(MARIO_WALKING) ;	//resets climbing to check for ladder collision each time through OnLoop
	for (int i = 0 ; i < bgObjs.size() ; i++) {
		dummy = bgObjs[i]->IsCollision(mario) ; //*(i+1) ;	//will return the element number + 1 of the vector mario is colliding with
		/*if(dummy > 0) {		// <=45 dummy is true for a platform ;  >45, collision with ladder
			//something
			dummy = 0 ;
		}*/
			
	}

}

