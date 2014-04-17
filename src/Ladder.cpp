#include "Ladder.h"

Ladder::Ladder(int _x, int _y, int _w, int _h) {
	xBlit = 0 ;	//true of all ladder objects because of layout of staticObjects.png
	yBlit = 0 ;	

	OnInit(_x, _y, _w, _h) ;
}

int Ladder::IsCollision(CMario& mario) {

	//mario has to be fully inside the ladder dimensions to use it
	//  PLATFORM_HEIGHT+mario.getHeight() is subtracted from the vertical max check because mario must be able to pass through the platform at the top of the ladder
	if( (mario.getX() > this->x) && (mario.getX() + mario.getWidth() < this->x + this->width) && 
		(mario.getY() + mario.getHeight() <= this->y + this->height) && (mario.getY() > this->y - (PLATFORM_HEIGHT + mario.getHeight())) ) 
	{
		//remove consideration of PLATFORM_HEIGHT above the ladder as part of collision for broken ladder and two ladders next to peach's platform
		if( (this->height > 30 && this->height < 100) || (mario.getY() > this->y - mario.getHeight()/2) ) {	//can climb above ladder to half of his height 
			mario.setLadderCollide(1) ; 	//ladderCollide set to true, know when exit ladder
			return 1 ;
		}
	} 

	return 0 ;
}

int Ladder::fireIsCollision(CFire& fire){
 	return 1;
}

int Ladder::barrelIsCollision(CBarrel& barrel){
        return 1;
}
