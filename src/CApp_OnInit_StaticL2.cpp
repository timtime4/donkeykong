/*	DonkeyKong
 *	CApp_OnInit_StaticL2.cpp
 *	This file sets up ladder and platform objects for an alternate level.
 */

#include "CApp.h"

int CApp::OnInit_StaticL2() {
	platforms.clear() ;
	ladders.clear() ;
	bgObjs.clear() ;

	Surf_bgObjs = CSurface::OnLoad("../imgFiles/bgFiles/staticObjectsL2.png") ;	//load file containing static objects image sprites
	if(Surf_bgObjs == NULL) {
		cout << "BgObjs image fail" << endl ; 
		return 0 ;
	}

	int i ;

	///////////INITIALIZE PLATFORMS//////////////////
	Platform temp ;
	int xIncrement = 60 ;
	int yIncrement = 3 ;
	//begin 0th level
	for (i = 0 ; i < 8 ; i++) {
		temp.OnInit(420-xIncrement*i, LEVEL_0_MIN - yIncrement*i, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
		platforms.push_back(temp) ;
	}

	//begin 1st level
	temp.OnInit(420, 510-yIncrement-PLATFORM_HEIGHT, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(360, 487, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(280, 460, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(200, 435, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(120, 410, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(60, 385, 40, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(0, 385, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;

	//safety platform
	temp.OnInit(420, 350, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(360, 350, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(300, 350, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;

	//begin 2nd level
	temp.OnInit(0, 280, 50, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(50, 280+yIncrement, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(110, 280, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(170, 280+yIncrement, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(230, 280, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(290, 280+yIncrement, 40, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;

	//begin steps
	temp.OnInit(350, 255, 30, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(390, 227, 30, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(430, 200, 25, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(460, 167, 20, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(410, 140, 30, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(360, 115, 35, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;


	//begin top level, R to L
	for (i = 0 ; i < 3 ; i++) {
		temp.OnInit(xIncrement*i, 180, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
		platforms.push_back(temp) ;
	}

	//begin platform where peach stands
	temp.OnInit(200, 100, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;
	temp.OnInit(200+PLATFORM_WIDTH, 100, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;
	platforms.push_back(temp) ;

	for (i = 0 ; i < platforms.size() ; i++ ) {
		bgObjs.push_back(&platforms[i]) ;	
	}


	//////////////INITIALIZE LADDERS//////////////////
	Ladder tempL ;

	tempL.OnInit(380, 510-yIncrement, LADDER_WIDTH, 70) ;
	ladders.push_back(tempL) ;
	tempL.OnInit(5, 300, LADDER_WIDTH, 60) ;
	ladders.push_back(tempL) ;
	tempL.OnInit(300, 303, LADDER_WIDTH, 47) ;
	ladders.push_back(tempL) ; 
	tempL.OnInit(135, 200, LADDER_WIDTH, 32) ;
	ladders.push_back(tempL) ;
	tempL.OnInit(135, 270, LADDER_WIDTH, 10) ;
	ladders.push_back(tempL) ;

	for (i = 0 ; i < ladders.size() ; i++) {
		bgObjs.push_back(&ladders[i]) ;
	}
	return 1 ;

}
