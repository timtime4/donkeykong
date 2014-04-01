#include "Platform.h"

Platform::Platform(int _x, int _y) {
	xBlit = 20 ;	//true of all platform objects because of layout of staticObjects.png
	yBlit = 0 ;

	OnInit(_x, _y, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;	//platform objects width and height are always same
}

int Platform::IsCollision(CMario& mario) {	//pass CMario object by reference to directly update the object in CApp_OnLoop

	//collision with ground-- also moves mario up when platform height moves up for slant
	if( (mario.getY() + mario.getHeight() > this->y) && (mario.getY() < this->y) && ((mario.getX() < this->x + this->width) && (mario.getX()+mario.getWidth() > this->x)))	{
		mario.setY(this->y - mario.getHeight()) ;
		return 1 ;
	} else return 0 ;

}
