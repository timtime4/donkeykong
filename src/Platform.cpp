#include "Platform.h"

Platform::Platform(int _x, int _y) {
	setXBlit(20) ;	//true of all platform objects because of layout of staticObjects.png
	setYBlit(0) ;

	OnInit(_x, _y, PLATFORM_WIDTH, PLATFORM_HEIGHT) ;	//platform objects width and height are always same
}

int Platform::IsCollision(CMario myMar) {
	//was there a collision?
}
