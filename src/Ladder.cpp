#include "Ladder.h"

Ladder::Ladder(int _x, int _y, int _w, int _h) {
	xBlit = 0 ;	//true of all ladder objects because of layout of staticObjects.png
	yBlit = 0 ;	

	OnInit(_x, _y, _w, _h) ;
}

int Ladder::IsCollision(CMario& mario) {

	//mario has to be fully inside the ladder dimensions to use it
	//  PLATFORM_HEIGHT+mario.getHeight() is subtracted from the vertical max check because mario must be able to pass through the platform at the top of the ladder
	if( (mario.getX() > this->x) && (mario.getX() + mario.getWidth() < this->x + this->width) && (mario.getY() + mario.getHeight() <= this->y + this->height) && (mario.getY() > this->y - (PLATFORM_HEIGHT + mario.getHeight())) ) {
		//cout << "LADDER COLLISION" << endl ;
		mario.setClimbing(1) ;	//sets mario's ladder capability to true
		mario.setWalking(0) ;
		return 1 ;
	} //else mario.setClimbing(0) ;	//unsets mario's ladder capability

	//was there a collision?
	return 0 ;
}
