#include "CEvent.h"

CEvent::CEvent() {
	//empty constructor 
}

CEvent::~CEvent() {
	//empty destructor
}

void CEvent::OnEvent(SDL_Event* Event) {
	switch(Event->type) {
		case SDL_ACTIVEEVENT: {
			switch(Event->active.state) {
				case SDL_APPMOUSEFOCUS: {
					if(Event->active.gain) OnMouseFocus() ;
					else OnMouseBlur() ;
					break ;
				}
				case SDL_APPINPUTFOCUS: {
					if(Event->active.gain) OnInputFocus() ;
					else OnInputBlur() ;
					break ;
				}
				case SDL_APPACTIVE: {
					if(Event->active.gain) OnRestore() ;
					else OnMinimize() ;
					break ;
				}
			}
			break ;
		}

		case SDL_KEYDOWN: {
			OnKeyDown(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.unicode) ;
			break ;
		}

		case SDL_KEYUP: {
			OnKeyUp(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.unicode) ;
			break ;
		}

		case SDL_MOUSEMOTION: {
			OnMouseMove(Event->motion.x, Event->motion.y, Event->motion.xrel, Event->motion.yrel, (Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0, (Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0, (Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0) ;
			break ;
		}

		case SDL_MOUSEBUTTONDOWN: {
			switch(Event->button.button) {
				case SDL_BUTTON_LEFT: {
					OnLButtonDown(Event->button.x, Event->button.y) ;
					break ;
				}
				case SDL_BUTTON_RIGHT: {
					OnRButtonDown(Event->button.x, Event->button.y) ;
					break ;
				}
				case SDL_BUTTON_MIDDLE: {
					OnMButtonDown(Event->button.x, Event->button.y) ;
					break ;
				}
			}
			break ;
		}

		case SDL_MOUSEBUTTONUP: {
			switch(Event->button.button) {
				case SDL_BUTTON_LEFT: {
					OnLButtonUp(Event->button.x, Event->button.y) ;
					break ;
				}
				case SDL_BUTTON_RIGHT: {
					OnRButtonUp(Event->button.x, Event->button.y) ;
					break ;
				}
				case SDL_BUTTON_MIDDLE: {
					OnMButtonUp(Event->button.x, Event->button.y) ;
					break ;
				}
			}
			break ;
		}

		case SDL_QUIT: {
			OnExit() ;
			break ;
		}

		case SDL_SYSWMEVENT: {
			//ignore
			break ;
		}

		case SDL_VIDEORESIZE: {
			OnResize(Event->resize.w, Event->resize.h) ;
			break ;
		}

		case SDL_VIDEOEXPOSE: {
			OnExpose() ;
			break ;
		}

		default:
			OnUser(Event->user.type, Event->user.code, Event->user.data1, Event->user.data2) ;
			break ;
	}
}



void CEvent::OnInputFocus() {
	//pure virtual, no implementation
}

void CEvent::OnInputBlur() {
	//pure virtual, no implementation
}

void CEvent::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	//pure virtual, no implementation
}

void CEvent::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	//pure virtual, no implementation
}

void CEvent::OnMouseFocus() {
	//pure virtual, no implementation
}

void CEvent::OnMouseBlur() {
	//pure virtual, no implementation
}

void CEvent::OnMouseMove(int mX, int mY, int relX, int relY, int left, int right, int middle) {
	//pure virtual, no implementation
}

void CEvent::OnMouseWheel(int up, int down) {
	//pure virtual, no implementation
}

void CEvent::OnLButtonDown(int mX, int mY) {
	//pure virtual, no implementation
}

void CEvent::OnRButtonDown(int mX, int mY) {
	//pure virtual, no implementation
}

void CEvent::OnMButtonDown(int mX, int mY) {
	//pure virtual, no implementation
}

void CEvent::OnLButtonUp(int mX, int mY) {
	//pure virtual, no implementation
}

void CEvent::OnRButtonUp(int mX, int mY) {
	//pure virtual, no implementation
}

void CEvent::OnMButtonUp(int mX, int mY) {
	//pure virtual, no implementation
}

void CEvent::OnMinimize() {
	//pure virtual, no implementation
} 

void CEvent::OnRestore() {
	//pure virtual, no implementation
} 

void CEvent::OnResize(int w, int h) {
	//pure virtual, no implementation
} 

void CEvent::OnExpose() {
	//pure virtual, no implementation
} 

void CEvent::OnExit() {
	//pure virtual, no implementation
} 

void CEvent::OnUser(Uint8 type, int code, void* data1, void* data2) {
	//pure virtual, no implementation
} 

