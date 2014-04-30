/*
 * DonkeyKong
 * CDonkeyKong.h
 * This file contains the interface of CDonkeyKong class.  DK follows well-defined behavior and does not 
 * deviate from the top platform.  One CDonkeyKong object will be instantiated in the CApp class.
*/

#ifndef CDONKEYKONG_H
#define CDONKEYKONG_H

#include "CEntity.h"
#include "Define.h"

class CDonkeyKong : public CEntity {		//inheriting from CEntity class

	public:
		CDonkeyKong() ;

		virtual void OnLoop() ;
		virtual void OnRender(SDL_Surface* Surf_Display) ;

		virtual int identifyType() ;

	private:
		int moved ;	//true or false value, used to slow down DK's movement; if it is true during call to OnLoop, it is set to false, and x and frame are not updated; if it is false, it is set to true, and x and frame are updated

};

#endif
