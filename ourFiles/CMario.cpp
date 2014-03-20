/*
 * DonkeyKong
 * CMario.cpp
 * This file contains the implementation of CMario class.
*/

#include "CMario.h"

CMario::CMario() {
	lives = 3 ;
}

int CMario::getLives() {
	return lives ;
}

/*void CMario::setLives(int _lives) {
	if(lives < 0) return ;
	lives = _lives ;
}*/
