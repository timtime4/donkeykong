/*
 * DonkeyKong
 ** CApp.cpp
 * This file contains implementation of OnExecute() function of CApp class, as well as the main function for the project.
*/

#include "CApp.h"

CApp::CApp() {
	running = 1 ;
	Surf_Display = NULL ;
	Surf_bgObjs = NULL ;
	//font = NULL ;
	//Surf_Highscore = NULL ;
	//textColor = {255, 0, 0} ;
}

int CApp::OnExecute() {
	if( !OnInit() ) {
		cout << "init failed" << endl ;
		return -1 ;	//error with initialization
	}
	SDL_Event Event ;
	while(running) {
		fps.start() ;
		while(SDL_PollEvent(&Event)) {	//use while to go through any events on a queue one at a time, SDL_PollEvent returns 0 when no events on queue
			mario.handle_input(&Event) ;
			OnEvent(&Event) ;
		}
		OnLoop() ;
		OnRender() ;
		if(fps.get_ticks() < 1000 / FRAMES_PER_SECOND) {	//caps frame rate
			SDL_Delay( (1000 / FRAMES_PER_SECOND) - fps.get_ticks() ) ;
		}
	}

	OnCleanup() ;
	

	
	return 0 ;
}


//////BEGIN MAIN//////
int main(int arc, char* argv[]) {
	CApp theApp ;	//instantiate an object of type CApp

	return theApp.OnExecute() ;
}
