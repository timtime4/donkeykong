/*
 * DonkeyKong
 * CAnimation.h
 * This file contains the interface for CAnimation class, which iterates through the frames of a sprite to produce animation.
*/

#ifndef CANIMATION_H
#define CANIMATION_H

#include "SDL/SDL.h"

class CAnimation {
	public:
		CAnimation() ;
		void OnAnimate() ;

		void setFrameRate(int rate) ;
		void setCurrentFrame(int frame) ;
		int getCurrentFrame() ;

		int getMaxFrames() ;
		void setMaxFrames(int) ;

	private:
		int frameRate ;	//object changes frame every <framerate> ms 
		long oldTime ;
		int currentFrame ;	//which sprite to be shown at current time
		int frameInc ;
		int maxFrames ;
} ;

#endif
