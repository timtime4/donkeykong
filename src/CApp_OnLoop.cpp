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
	fire.setLadderCollide(0);
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
	if(mario.getState()!= MARIO_HURTING) {
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
	
	//cout << "Diff Level: " << fire.IsDiffLevel(mario) << "collide: " << fire.getLadderCollide() << "fire State = " << fire.getState() << endl;
	//cout << "Mario: " << mario.getY() << " Fire: " << fire.getY() << endl;
	if(fire.IsDiffLevel(mario) && !fire.getLadderCollide()){
		fire.setState(FIRE_SEARCHING);
	} else if(fire.IsDiffLevel(mario) && fire.getLadderCollide()){
		fire.setState(FIRE_CLIMBING);
	} else if(!fire.IsDiffLevel(mario)){
		fire.setState(FIRE_WALKING);
		fire.wheresMarioX(mario);
	}

	//check mario and fire collision
	if(fire.IsCollision(mario) == 1 && mario.getState() != MARIO_HURTING) {
		mario.setState(MARIO_HURTING) ;	
		mario.setXVel(0) ;
		mario.setYVel(0) ;
		dyingCount++ ;		//starts dyingCount incrementing
		Mix_PlayChannel(-1, burns, 0) ;	// Play burn sound effect
	} else if (fire.IsCollision(mario) == 2 && mario.getState() == MARIO_JUMPING && gotPoints == 0) {
		gotPoints++ ;
	}

	// mario and barrel collision
        if(barrel.IsCollision(mario) == 1 && mario.getState() != MARIO_HURTING) {
                mario.setState(MARIO_HURTING) ;
                mario.setXVel(0) ;
                mario.setYVel(0) ;
		dyingCount++ ;		//starts dyingCount incrementing
                Mix_PlayChannel(-1, hurts, 0) ; // Play hit by barrel sound effect
	} else if (barrel.IsCollision(mario) == 2 && mario.getState() == MARIO_JUMPING && gotPoints == 0) {	
		gotPoints++ ;

	}
	if(gotPoints > 0) {
		gotPoints++ ;		//increment until reset (15 loops)
		if(gotPoints > 7 && mario.getState() != MARIO_HURTING) {	//successfully jumped over fire or barrel (ie. did not fall onto it) 
			gotPoints = 0 ;
			score+=200 ;

			displayPoints = 1 ;
			pointsX = mario.getX() ;
			pointsY = mario.getY() - 10 ;
			Surf_Points = TTF_RenderText_Solid(pointsFont, "+200", textColor) ;

			ostringstream scoreStream ;	//string stream for displaying score
			scoreStream << "Score: " << score ;
			scoreString = scoreStream.str() ;
			Surf_Score = TTF_RenderText_Solid(scoreFont, scoreString.c_str(), textColor) ;

			if(score > hs) {
				hs = score ;
				ostringstream hsStream ;
				hsStream << "Highscore: " << hs ;
				hsString = hsStream.str() ;
				Surf_Highscore = TTF_RenderText_Solid(scoreFont, hsString.c_str(), textColor) ;
			}
		}	
	}

	if(dyingCount > 0) {
		dyingCount++ ;		//increment until reset (50 loops)
		gotPoints = 0 ;		//can't get points if died before sufficient wait time (ie. time to make it over the obstacle
		if(dyingCount > 50) {
			dyingCount = 0 ;
	                --mario ;	//decrement lives after blinking finished
			if(mario.getLives() == 0) {
				running = 0 ;
				cout << "*************************" << endl << "SORRY!  YOU LOSE!"<< endl << "*************************" << endl;	
			} else {
				mario.reset() ;
			}
		}
	}

	//check peach collision
	if(peach.IsCollision(mario)) {
		running = 0 ;
		score+=1500 ;	
		displayPoints = 1 ;
		pointsX = mario.getX() ;
		pointsY = mario.getY() - 10 ;
		Surf_Points = TTF_RenderText_Solid(pointsFont, "+1500", textColor) ;

		ostringstream scoreStream ;	//string stream for displaying score
		scoreStream << "Score: " << score ;
		scoreString = scoreStream.str() ;
		Surf_Score = TTF_RenderText_Solid(scoreFont, scoreString.c_str(), textColor) ;

		if(score > hs) {
			hs = score ;
			ostringstream hsStream ;
			hsStream << "Highscore: " << hs ;
			hsString = hsStream.str() ;
			Surf_Highscore = TTF_RenderText_Solid(scoreFont, hsString.c_str(), textColor) ;
		}

		cout << "*************************" << endl << "CONGRATULATIONS! YOU WIN!"<< endl << "*************************" << endl ;
		wonGame = 1 ;	//***********
		//celebration music?
		//YOU WIN!!! screen
	}

}

