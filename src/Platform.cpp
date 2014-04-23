#include "Platform.h"

Platform::Platform(int _x, int _y) {
	xBlit = 20 ;	//true of all platform objects because of layout of staticObjects.png
	yBlit = 0 ;
	OnInit(_x, _y, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;	//platform objects width and height are always same
}

void Platform::IsCollision(CMario& mario) {	//pass CMario object by reference to directly update the object in CApp_OnLoop
	//collision with ground-- also moves mario up when platform height moves up for slant
	if( (mario.getX() < this->x + this->width) && (mario.getX()+mario.getWidth() > this->x) && 
		(mario.getY() + mario.getHeight() > this->y) &&	(mario.getY() + mario.getHeight() - 4 < this->y) )	
	{
		mario.setY(this->y - mario.getHeight()) ;	//set mario to be standing on ground platform
		mario.setPlatformCollide(1) ;
	}
}

void Platform::fireIsCollision(CFire& fire) {
	//collision with ground -- also moves fire up when platform height moves up for slant
	if( (fire.getX() < this->x + this->width) && (fire.getX() + fire.getWidth() > this->x) &&
		(fire.getY() + fire.getHeight() > this->y) && (fire.getY() + fire.getHeight() -4 < this->y) )
	{
		fire.setY(this->y - fire.getHeight());		
		fire.setPlatformCollide(1);
	}
}

void Platform::barrelIsCollision(CBarrel& barrel) {
        if( (barrel.getX() < this->x + this->width) && (barrel.getX() + barrel.getWidth() > this->x) &&
                (barrel.getY() + barrel.getHeight() > this->y) && (barrel.getY() + barrel.getHeight() -4 < this->y) )
        {
                barrel.setY(this->y - barrel.getHeight());
                barrel.setPlatformCollide(1);
        }
}

