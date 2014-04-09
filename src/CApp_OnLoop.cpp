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
	if(mario.getState()!=MARIO_HURTING) {
		if(!mario.getLadderCollide()) {
			if(!mario.getPlatformCollide()) {
				mario.setState(MARIO_JUMPING) ;
			}
			else {
				mario.setState(MARIO_WALKING) ;	//mario in walking state with platform collision and no ladder collision
			}
		}
		else {
			mario.setState(MARIO_CLIMBING) ;
		}
	}

	fire.wheresMarioX(mario);


	//check mario and fire collision
	if(fire.IsCollision(mario) && mario.getState()!=MARIO_HURTING) {
		--mario ;
		mario.setState(MARIO_HURTING) ;	
		mario.setXVel(0) ;
		mario.setYVel(0) ;
		dyingCount = 0 ;
	}

	dyingCount++ ;	//used to determine if enough time has passed with mario hurting to reset the level 
	if(mario.getState()==MARIO_HURTING && dyingCount > 50) {
		cout << mario.getLives() << endl ;
		if(mario.getLives() == 0) {
			running = 0 ;
			cout << "*************************" << endl << "SORRY!  YOU LOSE!"<< endl << "*************************" << endl;	
		} else 	mario.reset() ;
	}

	//check peach collision
	if(peach.IsCollision(mario)) {
		running = 0 ;
		cout << "*************************" << endl << "CONGRATULATIONS! YOU WIN!"<< endl << "*************************" << endl ;
		//probably want to do some more stuff

	}

}

