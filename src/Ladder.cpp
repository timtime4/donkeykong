#include "Ladder.h"

Ladder::Ladder(int _x, int _y, int _w, int _h) {
	xBlit = 0 ;	//true of all ladder objects because of layout of staticObjects.png
	yBlit = 0 ;	

	OnInit(_x, _y, _w, _h) ;
}

int Ladder::IsCollision(CMario& myMar) {
	//was there a collision?
	return 0 ;
}
