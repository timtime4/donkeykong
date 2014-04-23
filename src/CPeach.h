/*
 * DonkeyKong
 * CPeach.h
 * This file contains the interface of CPeach class.  Peach follows well-defined behavior and does not deviate from her pacing on the top platform.  One CPeach object will be instantiated in the CApp class.  When (if) there is a collision of this CPeach object with the CMario object instantiated in CApp, the user wins the level.
*/

#ifndef CPEACH_H
#define CPEACH_H

#include "CEntity.h"
#include "CMario.h"
#include "Define.h"

class CPeach : public CEntity {		//inheriting from CEntity class

	public:
		CPeach() ;

		virtual void OnLoop() ;
		virtual void OnRender(SDL_Surface* Surf_Display) ;
		virtual int IsCollision(CMario&) ;

	private:
		int direction ;	//+1 or -1, will determine if she is currently moving left or right
		int moved ;	//true or false value, used to slow down Peach's movement; if it is true during call to OnLoop, it is set to false, and x and frame are not updated; if it is false, it is set to true, and x and frame are updated

};

#endif
