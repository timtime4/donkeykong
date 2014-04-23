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
		virtual void IsCollision(CMario&) ;
		virtual void fireIsCollision(CFire&);
		virtual void barrelIsCollision(CBarrel&);

	private:

} ;

#endif
