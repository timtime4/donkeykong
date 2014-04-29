/*
 * DonkeyKong
 ** CApp.cpp
 * This file contains implementation of OnExecute() function of CApp class, as well as the main function for the project.
*/

#include "CApp.h"

CApp::CApp() {		//initialize private data members
	running = 1 ;
	game = 1;


	Surf_Display = NULL ;
	Surf_bgObjs = NULL ;

	theme = NULL ;
	jumps = NULL ;
	burns = NULL ;
	hurts = NULL ;

	Surf_Menu = NULL ;
	Surf_Controls = NULL ;
	Surf_Gameover = NULL ;
	displayControls = 0 ;

	scoreFont = NULL ;
	pointsFont = NULL ;

	hs = 0 ;
	Surf_Highscore = NULL ;

	score = 0 ;
	Surf_Points = NULL ;
	Surf_Score = NULL ;
	displayPoints = 0 ;
	gotPoints = 0 ;

	dyingCount = 0 ;
	
	Surf_Lives = NULL ;

	wonLevel1 = 0 ; 
	wonLevel2 = 0 ;

	Surf_LevelText = NULL ;

	levelCounter = 0 ;
	constantEntitiesCount = 0 ;
}

void CApp::resetLevel() {
	running = 1 ;
	mario.reset() ;
	barrel.reset() ;
	barrel2.reset() ;
	barrel3.reset() ;
	levelCounter = 0 ;
	while(entityList.size() > constantEntitiesCount) {
		entityList.pop_back() ;	//removes additional barrels from entityList
	}
	fire.reset() ;
	fire2.reset() ;
	fire3.reset() ;
	ostringstream scoreStream ;
	scoreStream << "Score: " << score ;	//string stream for creating full score text, ie. "Score: 0"
	scoreString = scoreStream.str() ;	//convert stream to string
	Surf_Score = TTF_RenderText_Solid(scoreFont, scoreString.c_str(), {0, 165, 230}) ;
}

int CApp::OnExecute() {
	if( !OnInit() ) {
		cout << "init failed" << endl ;
		return -1 ;	//error with initialization
	}
	if ( Mix_PlayMusic(theme, -1) == -1){		// Play background music -- smb3 theme song
       		return 1;
        }
	SDL_Event Event ;

	//start up screen implementation
	while( OnStartup(&Event) && running ){
	}
	
	while(game) {
		OnInit_Static() ;
		wonLevel1 = 0 ;
		wonLevel2 = 0 ;
		mario.setLives(3) ;
		score = 0 ;
		resetLevel() ;

		//display LEVEL 1 intro
		SDL_FillRect(Surf_Display, &Surf_Display->clip_rect, SDL_MapRGB(Surf_Display->format, 0, 0, 0) ) ;
		Surf_LevelText = TTF_RenderText_Solid(largeFont, "LEVEL 1", {0,255,0}) ;
		CSurface::OnDraw(Surf_Display, Surf_LevelText, 200, 225) ;
		SDL_Flip(Surf_Display) ;
		SDL_Delay(1500) ;		
		//////play LEVEL 1//////
		while(running) {
			fps.start() ;
			while(SDL_PollEvent(&Event)) {	//use while to go through any events on a queue one at a time, SDL_PollEvent returns 0 when no events on queue
				if(!OnEvent(&Event)) {
					OnCleanup() ;
					return 1 ;
				}
			}
			OnLoop() ;	//updates all data
			OnRender() ;	//displays updated screen
			if(fps.get_ticks() < 1000 / FRAMES_PER_SECOND) {	//caps frame rate
				SDL_Delay( (1000 / FRAMES_PER_SECOND) - fps.get_ticks() ) ;
			}
		}
		SDL_Delay(3000) ;	//pause to display game end
		if(game == 0) break ;

		if(wonLevel1) {	//start level 2
			OnInit_StaticL2() ;	//initialize level 2
			resetLevel() ;
			//display LEVEL 2 intro
			SDL_FillRect(Surf_Display, &Surf_Display->clip_rect, SDL_MapRGB(Surf_Display->format, 0, 0, 0) ) ;
			Surf_LevelText = TTF_RenderText_Solid(largeFont, "LEVEL 2", {255,255,0}) ;
			CSurface::OnDraw(Surf_Display, Surf_LevelText, 200, 225) ;
			SDL_Flip(Surf_Display) ;
			SDL_Delay(1500) ;
			//////play LEVEL 2//////
			while(running) {
				fps.start() ;
				while(SDL_PollEvent(&Event)) {	//use while to go through any events on a queue one at a time, SDL_PollEvent returns 0 when no events on queue
					if(!OnEvent(&Event)) {
						OnCleanup() ;
						return 1 ;
					}
				}
				OnLoop() ;	//updates all data
				OnRender() ;	//displays updated screen
				if(fps.get_ticks() < 1000 / FRAMES_PER_SECOND) {	//caps frame rate
					SDL_Delay( (1000 / FRAMES_PER_SECOND) - fps.get_ticks() ) ;
				}
			}
			SDL_Delay(3000) ;	//pause to display game end
			if(game == 0) break ;
		}

		CSurface::OnDraw(Surf_Display, Surf_Gameover, 0, 0) ;
		SDL_Flip(Surf_Display) ;
		while ( OnGameover(&Event) ){
		}
	}

	//update .highscore file
	ofstream hsFile("../.highscore") ;
	hsFile << hs ;

	OnCleanup() ;

	return 0 ;
}

//////BEGIN MAIN//////
int main(int arc, char* argv[]) {
	CApp theApp ;	//instantiate an object of type CApp
	return theApp.OnExecute() ;
}




