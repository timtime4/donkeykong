/*
 * DonkeyKong
 * Ladder.h
*/

#ifndef LADDER_H
#define LADDER_H

#include "StaticObj.h"

class Ladder : public StaticObj {
	public:
		Ladder(int = 0 , int = 0 , int = 0 , int = 0 ) ;
		virtual int IsCollision(CMario&) ;

	private:

} ;

#endif
