/* CTimer.cpp
*/

#include "CTimer.h"

CTimer::CTimer(){

	startTicks = 0;				// Initialize variables
    	pausedTicks = 0;
    	paused = false;
    	started = false;

}

void CTimer::start(){

	started = true;				// Start the timer
    	paused = false;				// Unpause the timer
	startTicks = SDL_GetTicks();		// Get the current start time

}

void CTimer::stop(){

	started = false;			// Stop the timer
	paused = false;				// Unpause the timer

}

void CTimer::pause(){

	if( ( started == true ) && ( paused == false ) ){		// If the timer is running and isn't already paused
        	paused = true;						// Pause the timer
        	pausedTicks = SDL_GetTicks() - startTicks;		// Calculate the number of paused ticks
	}

}

void CTimer::unpause(){

	if( paused == true ){					// If the timer is paused
        	paused = false;					// Unpause the timer
        	startTicks = SDL_GetTicks() - pausedTicks;	// Reset the number of starting ticks
        	pausedTicks = 0;				// Reset the number of paused ticks
	}

}

int CTimer::get_ticks(){

	if( started == true ){					// If the timer is running
        	if( paused == true ){				// If the timer is paused
            		return pausedTicks;			// Return the number of ticks when the timer was paused
        	}
        	else{
            		return SDL_GetTicks() - startTicks;	// Return the current time minus the start time
        	}
    	}

	return 0;		// Return the current time minus the start time
}

bool CTimer::is_started(){
	return started;
}

bool CTimer::is_paused(){
	return paused;
}
