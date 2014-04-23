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
		virtual void IsCollision(CMario&) ;
		virtual void entityIsCollision(CEntity&) ;
	
	private:
} ;

#endif
