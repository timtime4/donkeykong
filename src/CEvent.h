#ifndef CEVENT_H
#define CEVENT_H

#include "SDL/SDL.h"

class CEvent {
	public:
		CEvent() ;
		virtual ~CEvent() ;	//deconstructor
		virtual void OnEvent(SDL_Event* Event) ;

		virtual void OnInputFocus() ;
		virtual void OnInputBlur() ;
		virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) ;
		virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) ;
		virtual void OnMouseFocus() ;
		virtual void OnMouseBlur() ;
		virtual void OnMouseMove(int mX, int mY, int relX, int relY, int left, int right, int middle) ;	//left, right, middle have true/false values
		virtual void OnMouseWheel(int up, int down) ;	//up, down true/false values
		virtual void OnLButtonDown(int mX, int mY) ;
		virtual void OnLButtonUp(int mX, int mY) ;
		virtual void OnRButtonDown(int mX, int mY) ;
		virtual void OnRButtonUp(int mX, int mY) ;
		virtual void OnMButtonDown(int mX, int mY) ;
		virtual void OnMButtonUp(int mX, int mY) ;
		
		virtual void OnMinimize() ;
		virtual void OnRestore() ;
		virtual void OnResize(int w, int h) ;
		virtual void OnExpose() ;
		virtual void OnExit() ;
		virtual void OnUser(Uint8 type, int code, void* data1, void* data2) ;
} ;

#endif
