/*
 * DonkeyKong
 * CApp_OnEvent.cpp
*/

#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event) {
	if(Event->type == SDL_QUIT) {
		running = 0 ; //finishes game
	}
	CEvent::OnEvent(Event) ;
}

void CApp::OnExit() {		//is this unnecessary?
	running = 0 ;
}

