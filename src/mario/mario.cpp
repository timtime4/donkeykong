#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
using namespace std;

// Screen attributes

const int SCREEN_WIDTH = 640;		// Screen width
const int SCREEN_HEIGHT = 480;		// Screen height
const int SCREEN_BPP = 32;		// Bits per pixel
const int FRAMES_PER_SECOND = 20;	// Frame rate

// Mario attributes

const int MARIO_WIDTH = 50;		// Mario's dimensions
const int MARIO_HEIGHT = 65;

// Which way Mario is facing

const int MARIO_RIGHT = 0;
const int MARIO_LEFT = 1;

// The areas of the sprite sheet

SDL_Rect clipsRight[2];
SDL_Rect clipsLeft[2];

// Surfaces

SDL_Surface *mario = NULL;		// Mario surface
SDL_Surface *screen = NULL;		// Screen surface

// Event structure

SDL_Event event;

class Mario{		// Mario class

        public:
                Mario();                        // Constructor
                void handle_input();            // Takes key presses and adjusts the mario's velocity accordingly
                void move();                    // Moves mario
                void show();                    // Shows mario on screen

	private:

		int x, y;			// The X and Y offsets of mario
		int xVel, yVel;			// The velocity of mario
		int frame;			// Keeps track of which frame in animation to use
		int status;			// Keeps track of which animation to show (left or right)

};

class Timer{		// Timer class

        public:
        
                Timer();                // Constructor
                void start();           // Various clock actions
                void stop();
                void pause();
                void unpause();

                int get_ticks();        // Gets the time of the timer
                bool is_started();      // Checks the status of the timer
                bool is_paused();

	private:

		int startTicks; 	// The clock time when the timer started
		int pausedTicks;	// The ticks stored when the timer was paused
		bool paused;		// The timer status
		bool started;

};

// Loads the Image. Returns the optimized SDL_Surface

SDL_Surface *load_image( std::string filename ){		// filename is the path of the image to be loaded

	SDL_Surface* loadedImage = NULL;			// Surface we get when the image is loaded
	SDL_Surface* optimizedImage = NULL;			// Optimized surface, which we will use

	loadedImage = SDL_LoadBMP( "mar.bmp" );		// Load the image and store as loadedImage. Won't be used immediately -- bmp is 24-bit and Surface is 32-bit

	if( loadedImage != NULL ){				// If no errors loading
		optimizedImage = SDL_DisplayFormat( loadedImage );	// Creates the optimized surface with the right bitsize
		SDL_FreeSurface( loadedImage );				// Free the old surface
		if( optimizedImage != NULL ){				// If no errors optimizing
			SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );	// Color key surface
		}
		else{
			printf("Error: Image failed to properly optimize.");
		}
	}
	else{
		printf("Error: Image failed to properly load.");
	}

	return optimizedImage;
}

void set_clips(){		// Clip the sprites

	clipsRight[0].x = 0;
	clipsRight[0].y = 0;
	clipsRight[0].w = MARIO_WIDTH;
	clipsRight[0].h = MARIO_HEIGHT;

        clipsRight[1].x = MARIO_WIDTH;
        clipsRight[1].y = 0;
        clipsRight[1].w = MARIO_WIDTH;
        clipsRight[1].h = MARIO_HEIGHT;

	clipsLeft[0].x = MARIO_WIDTH;
        clipsLeft[0].y = MARIO_HEIGHT;
        clipsLeft[0].w = MARIO_WIDTH;
        clipsLeft[0].h = MARIO_HEIGHT;

        clipsLeft[1].x = 0;
        clipsLeft[1].y = MARIO_HEIGHT;
        clipsLeft[1].w = MARIO_WIDTH;
        clipsLeft[1].h = MARIO_HEIGHT;

}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL ){

	SDL_Rect offset;		// Data type that temporarily holds x and y offsets

	offset.x = x;			// Get offsets
	offset.y = y;

	SDL_BlitSurface( source, clip, destination, &offset );	// Blit surface

}

bool init(){

	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ){		// Initialize SDL subsystems and check for error
		printf("Error: SDL Initialize Error");
    	}

	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );	// Set up the screen

	if( screen == NULL ){		// If error setting up screen
        	printf("Error: Screen setup error");
	}

	return true;
}

bool load_files(){

	mario = load_image( "mar.bmp" );	// Load mario image

	if( mario == NULL ){			// If error loading image
        	printf("Error: Image Load Error.");
	}

	return true;
}

void clean_up(){

	SDL_FreeSurface( mario );		// Free the surface
	SDL_Quit();				// Quit SDL

}

Mario::Mario(){

	x = 0;			// Initialize offsets (position). Mario starts in the top left corner
	y = 0;

	xVel = 0;		// Initialize velocity.
	yVel = 0;

        status = MARIO_RIGHT;   // Initialize orientation
	frame = 0; 		// Initialize frame number

}

void Mario::handle_input(){

	if( event.type == SDL_KEYDOWN ){		// If a key was pressed
        	switch( event.key.keysym.sym ){		// Adjust the velocity accordingly
            		case SDLK_UP: yVel -= MARIO_HEIGHT / 2; break;
          		case SDLK_DOWN: yVel += MARIO_HEIGHT / 2; break;
            		case SDLK_LEFT: xVel -= MARIO_WIDTH / 2; break;
            		case SDLK_RIGHT: xVel += MARIO_WIDTH / 2; break;
		}
	}
	else if( event.type == SDL_KEYUP ){		// If a key was released
        	switch( event.key.keysym.sym ){		// Adjust the velocity accordingly
           		case SDLK_UP: yVel += MARIO_HEIGHT / 2; break;
            		case SDLK_DOWN: yVel -= MARIO_HEIGHT / 2; break;
            		case SDLK_LEFT: xVel += MARIO_WIDTH / 2; break;
            		case SDLK_RIGHT: xVel -= MARIO_WIDTH / 2; break;
        	}
    	}

}

void Mario::move(){

	x += xVel;			// Move mario left or right
        y += yVel;                      // Move mario up or down

	if( ( x < 0 ) || ( x + MARIO_WIDTH > SCREEN_WIDTH ) ){		// If mario moves too far left or right
		x -= xVel;		// Move him back
	}

	if( ( y < 0 ) || ( y + MARIO_HEIGHT > SCREEN_HEIGHT ) ){	// If mario moves too far up or down
        	y -= yVel;		// Move him back
	}

}

void Mario::show(){

	if ( xVel < 0){			// If he is moving left
		status = MARIO_LEFT;	// Change status
		frame++;		// Move to next frame in animation
	}
	else if ( xVel > 0){		// If he is moving right
		status = MARIO_RIGHT;	// Change status
		frame++;		// Move to next frame in animation
	}
	else{				// If he is standing still
		frame = 0;		// Restart animation
	}
	
	if ( frame >= 2){		// Loop the animation
		frame = 0;
	}

	if ( status == MARIO_RIGHT ){
		apply_surface( x, y, mario, screen, &clipsRight[ frame ] );	// Show mario going right
	}
	else if ( status == MARIO_LEFT ){
		apply_surface( x, y, mario, screen, &clipsLeft[ frame ] );     // Show mario going left
	}

}

Timer::Timer(){

	startTicks = 0;				// Initialize variables
    	pausedTicks = 0;
    	paused = false;
    	started = false;

}

void Timer::start(){

	started = true;				// Start the timer
    	paused = false;				// Unpause the timer
	startTicks = SDL_GetTicks();		// Get the current start time

}

void Timer::stop(){

	started = false;			// Stop the timer
	paused = false;				// Unpause the timer

}

void Timer::pause(){

	if( ( started == true ) && ( paused == false ) ){		// If the timer is running and isn't already paused
        	paused = true;						// Pause the timer
        	pausedTicks = SDL_GetTicks() - startTicks;		// Calculate the number of paused ticks
	}

}

void Timer::unpause(){

	if( paused == true ){					// If the timer is paused
        	paused = false;					// Unpause the timer
        	startTicks = SDL_GetTicks() - pausedTicks;	// Reset the number of starting ticks
        	pausedTicks = 0;				// Reset the number of paused ticks
	}

}

int Timer::get_ticks(){

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

bool Timer::is_started(){
	return started;
}

bool Timer::is_paused(){
	return paused;
}

int main( int argc, char* args[] ){
	bool quit = false;				// Initialize quit to false

	set_clips();

 	Mario myMario;					// Instantiate mario

	Timer fps;					// Instantiate frame rate regulator

	if( init() == false ){				// Initialize SDL subsystems and set up screen
        	printf("Error: SDL Initialization failed");	
    	}

    	if( load_files() == false ){			// Load files
        	printf("Error: File Load Failed");	// If load_files fails
    	}

    	while( quit == false ){				// While the user hasn't quit
	        fps.start();				// Start the frame timer
        	while( SDL_PollEvent( &event ) ){	// While there's events to handle
			myMario.handle_input();		// Handle events for mario
            		if( event.type == SDL_QUIT ){	// If the user has Xed out the window
                		quit = true;		// Quit the program
            		}
        	}

        	myMario.move();				// Move mario

        	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );  // Fill the screen white

        	myMario.show();				// Show mario on screen

        	if( SDL_Flip( screen ) == -1 ){		// Update the screen
            		printf("Error: Screen Update Failed");				// If update fails
        	}

		if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ){			// Cap the frame rate
        		SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        	}
    	}

	clean_up();					// Free surfaces and quit SDL

	return 0;
}

