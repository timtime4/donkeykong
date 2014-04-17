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

        int dummy3;
        // Repeat same collision process with barrel
        barrel.setPlatformCollide(0) ;
        for (int it = 0 ; it < bgObjs.size() ; it++) {
                dummy3 = bgObjs[it]->barrelIsCollision(barrel);
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
		Mix_PlayChannel(-1, burns, 0) ;	// Play burn sound effect
	}				

	// mario and barrel collision
        if(barrel.IsCollision(mario) == 1 && mario.getState()!=MARIO_HURTING) {
                --mario ;
                mario.setState(MARIO_HURTING) ;
                mario.setXVel(0) ;
                mario.setYVel(0) ;
                dyingCount = 0 ;
                Mix_PlayChannel(-1, hurts, 0) ; // Play hit by barrel sound effect
	} else if (barrel.IsCollision(mario) == 2 && mario.getState()==MARIO_JUMPING && gotPoints==0) {	
		gotPoints++ ;
		score+= 200 ;
		cout << score << endl ;
	}
//restrict mario's points gain to once over each obstacle, the counter takes 25 seconds to restart (enough time for mario to jump entirely over barrel), at which point mario can get receive points again
	if(gotPoints > 0) {
		gotPoints++ ;		//counter for gotPoints reset (25 loops)
		if(gotPoints > 25) gotPoints = 0 ;	
	}

	dyingCount++ ;	//used to determine if enough time has passed with mario hurting to reset the level 
	if(mario.getState()==MARIO_HURTING && dyingCount > 30) {
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
		//celebration music?
		//YOU WIN!!! screen
	}

}

