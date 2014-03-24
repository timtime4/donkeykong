/*
 * DonkeyKong
 ** CApp.cpp
 * This file contains implementation of OnExecute() function of CApp class, as well as the main function for the project.
*/

#include "CApp.h"

CApp::CApp() {
	running = 1 ;
	Surf_Display = NULL ;
	Surf_Background = NULL ;
}

int CApp::OnExecute() {
	if( !OnInit() ) {
		return -1 ;	//error with initialization
	}

	SDL_Event Event ;
	while(running) {
		while(SDL_PollEvent(&Event)) {	//use while to go through any events on a queue one at a time, SDL_PollEvent returns 0 when no events on queue
			OnEvent(&Event) ;
		}
		OnLoop() ;
		OnRender() ;
	}

	OnCleanup() ;

	return 0 ;
}


//////BEGIN MAIN//////
int main(int arc, char* argv[]) {
	CApp theApp ;	//instantiate an object of type CApp

	return theApp.OnExecute() ;
}
