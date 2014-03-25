#include "Ladder.h"

Ladder::Ladder(int _x, int _y, int _w, int _h) {
	setXBlit(0) ;	//true of all ladder objects because of layout of staticObjects.png
	setYBlit(0) ;	

	OnInit(_x, _y, _w, _h) ;
}
