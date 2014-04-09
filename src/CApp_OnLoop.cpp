/*
 * DonkeyKong
 * CApp_OnLoop.cpp
 * This file contains the implemenation of OnLoop() function of CApp class.  This function performs all necessary updates each time through the OnExecute() loop.
*/

#include "CApp.h"

void CApp::OnLoop() {
	int fireChangeDirection = 0;

	for (int i = 0 ; i < entityList.size() ; i++) {		//loops through all entities (including mario)
		if(!entityList[i]) continue ;	//NULL pointer check
		entityList[i]->OnLoop() ;	//updates each valid entity
	}

	//check for static obj collisions
	int dummy ;
	mario.setLadderCollide(0) ;		//reset to false each time through, will both be checked and set in IsCollision functions if there is a collision
	mario.setPlatformCollide(0) ;
	for (int i = 0 ; i < bgObjs.size() ; i++) {
		dummy = bgObjs[i]->IsCollision(mario) ;			
	}

	int dummy2;
	//Repeat same collision process with fire
	fire.setPlatformCollide(0) ;
	for (int it = 0 ; it < bgObjs.size() ; it++) {
		dummy2 = bgObjs[it]->fireIsCollision(fire);			
	}


	//set mario state
	if(!mario.getLadderCollide()) {
		if(!mario.getPlatformCollide()) {
			mario.setState(MARIO_JUMPING) ;
			/*fallCount++ ;
			if(fallCount > 50){
				running = 0 ;
				cout << "Mario fell too far. You lose." << endl ;
			}*/
		}
		else {
			//fallCount = 0 ;	//reset fallCount
			mario.setState(MARIO_WALKING) ;	//mario in walking state with platform collision and no ladder collision
		}
	}
	else {
		//fallCount = 0 ;
		mario.setState(MARIO_CLIMBING) ;
	}

	fire.wheresMarioX(mario);


	//check mario and fire collision
	if(fire.IsCollision(mario)){
		running = 0;
		cout << "*************************" << endl << "SORRY!  YOU LOSE!"<< endl << "*************************" << endl;
	}

	//check peach collision
	if(peach.IsCollision(mario)) {
		running = 0 ;
		cout << "*************************" << endl << "CONGRATULATIONS! YOU WIN!"<< endl << "*************************" << endl ;
		//probably want to do some more stuff

	}

}

