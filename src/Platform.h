/*
 * DonkeyKong
 * Platform.h
*/

#ifndef PLATFORM_H
#define PLATFORM_H

#include "StaticObj.h"

class Platform : public StaticObj {
	public:
		Platform(int = 0, int = 0) ;
		virtual int IsCollision(CMario&) ;
		virtual int fireIsCollision(CFire&);
		virtual int barrelIsCollision(CBarrel&);
	
	private:
} ;

#endif
