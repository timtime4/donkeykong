/*
 * Donkey Kong
 * CAnimation.cpp
 * The implementation of CAnimation class.
*/

#include "CAnimation.h"

CAnimation::CAnimation() {
	currentFrame = 0 ;
	maxFrames = 0 ;
	frameInc = 1 ;
	frameRate = 100;	//go to next frame every <frameRate> ms
	oldTime = 0 ;
}

void CAnimation::OnAnimate() {
	if(oldTime + frameRate > SDL_GetTicks()) {	//only updates when the amount of time specified by the frameRate has passed
		return ;
	}

	oldTime = SDL_GetTicks() ;
	currentFrame += frameInc ;

	if(currentFrame >= maxFrames) currentFrame = 0 ;
}

void CAnimation::setFrameRate(int rate) {
	frameRate = rate ;	//can be negative or positive so no checks needed
}

void CAnimation::setCurrentFrame(int frame) {
	if(frame < 0 || frame >= maxFrames) return ;	//invalid value
	currentFrame = frame ;
}

int CAnimation::getCurrentFrame() {
	return currentFrame ;
}

int CAnimation::getMaxFrames() {
	return maxFrames ;
}

void CAnimation::setMaxFrames(int mFrames) {
	if (mFrames < 0) return ;
	maxFrames = mFrames ;
}
