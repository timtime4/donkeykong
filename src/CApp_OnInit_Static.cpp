/*
 * DonkeyKong
 * CApp_OnInt_Static.cpp
 *  This file contains OnInit_Static() private helper function of CApp class.  This function is called in OnInit() of the CApp class, and initializes all Platform and Ladder objects (the static members of the game).  Mario will interact with both of these objects, and these collisions will be handled using polymorphism.  Therefore, each Platform and Ladder added to the platforms and ladders vectors are also tracked in the bgObjs vector.  This is a vector of StaticObj pointers, which will be iterated through to invoke polymorphic behavior with collisions.
 * The coordinates passed as arguments for placing the Platform and Ladder objects were determined through developing a desired image of the static objects together on the screen, and then determining the pixels where these objects would be placed.
*/

#include "CApp.h"


int CApp::OnInit_Static() {

	platforms.clear() ;
	ladders.clear() ;
	bgObjs.clear() ;

	Surf_bgObjs = CSurface::OnLoad("../imgFiles/bgFiles/staticObjects.png") ;	//load file containing static objects image sprites
	if(Surf_bgObjs == NULL) {
		cout << "BgObjs image fail" << endl ; 
		return 0 ;
	}

	int i ;

	//////////////////INITIALIZE PLATFORMS/////////////////////////

	int yIncrement = 3 ;	//number of pixels by which each platform moves upward in comaparison to its neighbor platform
	int xIncrement = 60 ;	//number of pixels by which each platform moves L or R in comparison to its neighboring platform
	Platform temp ;

	//begin 0th level, L to R
	for (i = 0 ; i < 4 ; i++) {	//flat platforms at bottom of screen
		temp.OnInit(xIncrement*i, LEVEL_0_MIN, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
		platforms.push_back(temp) ;
	}
	int baseYL0 = 577 ;	//for platforms that begin to slant at level 0
	int baseXL0 = 240 ;
	for (i = 0 ; i < 4 ; i++) {
		temp.OnInit(baseXL0+i*xIncrement, baseYL0-i*yIncrement, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
		platforms.push_back(temp) ;
	}

	int baseXLOdd = 360 ;	//odd level starting platform x position, R to L
	int baseXLEven = 60 ;	//event level starting platform x position, L to R
	int baseYL1 = LEVEL_1_MIN ;	//y starting position 1st level, R to L
	int baseYL2 = LEVEL_2_MIN ;
	int baseYL3 = LEVEL_3_MIN ;
	int baseYL4 = 266 ;

	for (i = 0 ; i < 7 ; i++) {	//initializes the 7 platforms on each level (1-4)
		temp.OnInit(baseXLOdd-xIncrement*i, baseYL1-yIncrement*i, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;	//level 1 initialization
		platforms.push_back(temp) ;
		temp.OnInit(baseXLEven+xIncrement*i, baseYL2-yIncrement*i, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;	//level 2
		platforms.push_back(temp) ;
		temp.OnInit(baseXLOdd-xIncrement*i, baseYL3-yIncrement*i, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;	//level 3
		platforms.push_back(temp) ;
		temp.OnInit(baseXLEven+xIncrement*i, baseYL4-yIncrement*i, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;	//level 4
		platforms.push_back(temp) ;
	}

	//begin top level, R to L
	temp.OnInit(360, 183, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	for (i = 0 ; i < 6 ; i++) {
		temp.OnInit(300-xIncrement*i, 180, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
		platforms.push_back(temp) ;
	}  

	//begin platform where peach stands
	temp.OnInit(200, 100, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(200+PLATFORM_WIDTH, 100, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	
	//push pointers to all platform objects into a vector of StaticObj pointers so polymorphic behavior can be used with virtual member functions
	for (i = 0 ; i < platforms.size() ; i++ ) {
		bgObjs.push_back(&platforms[i]) ;	
	}

	//45 platform objects


	//////////INITIALIZE LADDERS//////////////
		//the heights (4th arg of OnInit) of ladders vary based on where they are placed, maxheight=120 pixels
	Ladder tempL ;

	tempL.OnInit(150, 60, LADDER_WIDTH, 120) ;	//begin top level ladders
	ladders.push_back(tempL) ;
	tempL.OnInit(180, 60, LADDER_WIDTH, 120) ;
	ladders.push_back(tempL) ;
	tempL.OnInit(300, 120, LADDER_WIDTH, 60) ;
	ladders.push_back(tempL) ;

	tempL.OnInit(340, 200, LADDER_WIDTH, 54) ;	//begin level 4 ladders
	ladders.push_back(tempL) ;
	tempL.OnInit(200, 236, LADDER_WIDTH, 24) ;
	ladders.push_back(tempL) ;
	tempL.OnInit(200, 200, LADDER_WIDTH, 14) ;
	ladders.push_back(tempL) ;

	tempL.OnInit(80, 286, LADDER_WIDTH, 45) ;	//begin level 3 ladders
	ladders.push_back(tempL) ;
	tempL.OnInit(150, 283, LADDER_WIDTH, 51) ;
	ladders.push_back(tempL) ;
	tempL.OnInit(305, 274, LADDER_WIDTH, 24) ;
	ladders.push_back(tempL) ;
	tempL.OnInit(305, 329, LADDER_WIDTH, 14) ;
	ladders.push_back(tempL) ;

	tempL.OnInit(365, 366, LADDER_WIDTH, 45) ;	//begin level 2 ladders
	ladders.push_back(tempL) ;
	/*tempL.OnInit(220, 357, LADDER_WIDTH, 63) ;
	ladders.push_back(tempL) ;*/
	tempL.OnInit(120, 354, LADDER_WIDTH, 24) ;
	ladders.push_back(tempL) ;
	tempL.OnInit(120, 405, LADDER_WIDTH, 18) ;
	ladders.push_back(tempL) ;

	tempL.OnInit(75, 446, LADDER_WIDTH, 45) ;	//begin level 1 ladders
	ladders.push_back(tempL) ;
	/*tempL.OnInit(185, 440, LADDER_WIDTH, 57) ;
	ladders.push_back(tempL) ;*/
	tempL.OnInit(310, 434, LADDER_WIDTH, 24) ;
	ladders.push_back(tempL) ;

	tempL.OnInit(320, 523, LADDER_WIDTH, 51) ;	//begin level 0 ladders
	ladders.push_back(tempL) ;
	tempL.OnInit(155, 557, LADDER_WIDTH, 23) ;
	ladders.push_back(tempL) ;
	tempL.OnInit(155, 514, LADDER_WIDTH, 16) ;
	ladders.push_back(tempL) ;


	for (i = 0 ; i < ladders.size() ; i++) {	//push pointers to all ladder objects into bgObjs vector
		bgObjs.push_back(&ladders[i]) ;
	}

	//19 ladder objects


	return 1 ;
}	
