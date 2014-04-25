/*
 * DonkeyKong
 * CApp_OnLoop.cpp
 * This file contains the implemenation of OnLoop() function of CApp class.  This function performs all necessary updates each time through the OnExecute() loop.
*/

#include "CApp.h"

void CApp::OnLoop() {
	int fireChangeDirection = 0;

	for (int i = 0 ; i < entityList.size() ; i++) {		//loops through all entities (including mario)
		entityList[i]->OnLoop() ;	//updates each valid entity
	}
	mario.OnLoop() ;
	peach.OnLoop() ;

	//add barrels
	if(levelCounter == 200) entityList.push_back(&barrel2) ;
	else if (levelCounter == 400) entityList.push_back(&barrel3) ;
	else if(levelCounter == 600) entityList.push_back(&barrel4) ;
	levelCounter++ ;

	//check for collisions with static objects
	mario.setLadderCollide(0) ;		//reset to false each time through, will both be checked and set in IsCollision functions if there is a collision
	mario.setPlatformCollide(0) ;	
	fire.setLadderCollide(0);
	fire.setPlatformCollide(0) ;
	barrel.setLadderCollide(0) ;
	barrel.setPlatformCollide(0) ;
	for (int i = 0 ; i < bgObjs.size() ; i++) {
		bgObjs[i]->IsCollision(mario) ;
		for(int j = 0 ; j < entityList.size() ; j++) {	
			bgObjs[i]->entityIsCollision(*entityList[j]) ;
		}		
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
	
	//AI for fire
	if(fire.IsDiffLevel(mario) && !fire.getLadderCollide()){
		fire.setState(FIRE_SEARCHING);
	} else if(fire.IsDiffLevel(mario) && fire.getLadderCollide()){
		fire.setState(FIRE_CLIMBING);
	} else if(!fire.IsDiffLevel(mario)){
		fire.setState(FIRE_WALKING);
		fire.wheresMarioX(mario);
	}


	//check entity (other than peach) collisions with mario
	for (int i = 0 ; i < entityList.size() ; i++) {
		if(entityList[i]->IsCollision(mario) == 1 && mario.getState() != MARIO_HURTING) {
			mario.setState(MARIO_HURTING) ;
			mario.setXVel(0) ;
			mario.setYVel(0) ;
			dyingCount++ ;
			//play sound effect
			if(entityList[i]->identifyType() == 1) {	//fire object
				Mix_PlayChannel(-1, burns, 0) ;	// Play burn sound effect
			} else if(entityList[i]->identifyType() == 2 || entityList[i]->identifyType() == 3) {	//fire or dk object
				Mix_PlayChannel(-1, hurts, 0) ;	// Play hurting sound effect
			}			
		} else if(entityList[i]->IsCollision(mario) == 2 && mario.getState() == MARIO_JUMPING && gotPoints == 0) {
			gotPoints++ ;
		}
	}
	//check peach collision with mario
	if(peach.IsCollision(mario)) {
		running = 0 ;
		score+=1500 ;	
		displayPoints = 1 ;
		pointsX = mario.getX() ;
		pointsY = mario.getY() - 10 ;
		Surf_Points = TTF_RenderText_Solid(pointsFont, "+1500", {255, 105, 180}) ;	//pink for peach

		ostringstream scoreStream ;	//string stream for displaying score
		scoreStream << "Score: " << score ;
		scoreString = scoreStream.str() ;
		Surf_Score = TTF_RenderText_Solid(scoreFont, scoreString.c_str(), {0, 165, 230}) ;

		if(score > hs) {
			hs = score ;
			ostringstream hsStream ;
			hsStream << "Highscore: " << hs ;
			hsString = hsStream.str() ;
			Surf_Highscore = TTF_RenderText_Solid(scoreFont, hsString.c_str(), {0, 165, 230}) ;
		}

		if(!wonLevel1) {
			wonLevel1 = 1 ;
		} else if (!wonLevel2) {
			wonLevel2 = 1 ;
		}
		//celebration music?
		//YOU WIN!!! screen
	}

	//update score, highscore, and their displays
	if(gotPoints > 0) {
		gotPoints++ ;		//increment until reset (15 loops)
		if(gotPoints > 8 && mario.getState() != MARIO_HURTING) {	//successfully jumped over fire or barrel (ie. did not fall onto it) 
			gotPoints = 0 ;
			score+=200 ;

			displayPoints = 1 ;
			pointsX = mario.getX() ;
			pointsY = mario.getY() - 10 ;
			Surf_Points = TTF_RenderText_Solid(pointsFont, "+200", {255, 100, 70}) ;	//orange for scoring over barrels and fire

			ostringstream scoreStream ;	//string stream for displaying score
			scoreStream << "Score: " << score ;
			scoreString = scoreStream.str() ;
			Surf_Score = TTF_RenderText_Solid(scoreFont, scoreString.c_str(), {0, 165, 230}) ;

			if(score > hs) {
				hs = score ;
				ostringstream hsStream ;
				hsStream << "Highscore: " << hs ;
				hsString = hsStream.str() ;
				Surf_Highscore = TTF_RenderText_Solid(scoreFont, hsString.c_str(), {0, 165, 230}) ;
			}
		}	
	}

	//controls mario's deaths
	if(dyingCount > 0) {
		dyingCount++ ;		//increment until reset (50 loops)
		gotPoints = 0 ;		//can't get points if died before sufficient wait time (ie. time to make it over the obstacle
		if(dyingCount > 50) {
			dyingCount = 0 ;
	                --mario ;	//decrement lives after blinking finished
			if(mario.getLives() == 0) {
				running = 0 ;
				wonLevel1 = 0 ;
				wonLevel2 = 0 ;
			} else {
				mario.reset() ;
			}
		}
	}
}

