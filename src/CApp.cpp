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
	textColor = {0, 165, 230} ;

	hs = 0 ;
	Surf_Highscore = NULL ;

	score = 0 ;
	Surf_Points = NULL ;
	Surf_Score = NULL ;
	displayPoints = 0 ;
	gotPoints = 0 ;

	dyingCount = 0 ;
	
	Surf_Lives = NULL ;

	wonGame = 0 ; 
	Surf_WonText = NULL ;
}

void CApp::resetGame() {
	wonGame = 0 ;
	mario.reset() ;
	mario.setLives(3) ;
	barrel.reset() ;	
	fire.reset() ;
	score = 0 ;
	ostringstream scoreStream ;
	scoreStream << "Score: " << score ;	//string stream for creating full score text, ie. "Score: 0"
	scoreString = scoreStream.str() ;	//convert stream to string
	Surf_Score = TTF_RenderText_Solid(scoreFont, scoreString.c_str(), textColor) ;

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
		resetGame() ;

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
		SDL_Delay(1000) ;	//pause to display game end, time wanted needs to be decided****
		if(game == 0) break ;
		CSurface::OnDraw(Surf_Display, Surf_Gameover, 0, 0) ;
		/*if(wonGame) {
			Surf_WonText = TTF_RenderText_Solid(scoreFont, "You Win!", {0,255,0}) ;
			CSurface::OnDraw(Surf_Display, Surf_WonText, 200, 225) ;
		}*/

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




