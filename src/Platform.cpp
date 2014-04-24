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

	//collision with ceiling-- is not a collision if climbing is turned on
	int checkHeight = this->y + this->height ;	//bottom of the platform-- height at which mario would collide with a "ceiling"
	if( (mario.getX() < this->x + this->width) && (mario.getX()+mario.getWidth() > this->x) && (mario.getY() < checkHeight) && 
		(mario.getY() + mario.getHeight() > checkHeight) && (mario.getState() != MARIO_CLIMBING) ) 
	{
		mario.setY(checkHeight) ;
	}
}

void Platform::entityIsCollision(CEntity& entity) {
	//collision with ground -- also moves fire up when platform height moves up for slant
	if( (entity.getX() < this->x + this->width) && (entity.getX() + entity.getWidth() > this->x) &&
		(entity.getY() + entity.getHeight() > this->y) && (entity.getY() + entity.getHeight() -4 < this->y) )
        {
                entity.setY(this->y - entity.getHeight());
                entity.setPlatformCollide(1);
        }
}


