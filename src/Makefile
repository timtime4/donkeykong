all: CApp

CApp:  CApp.o CApp_OnInit.o CApp_OnEvent.o CApp_OnLoop.o CApp_OnRender.o CApp_OnCleanup.o CSurface.o CEvent.o CAnimation.o CEntity.o
	g++ CApp.o CApp_OnInit.o CApp_OnEvent.o CApp_OnLoop.o CApp_OnRender.o CApp_OnCleanup.o CSurface.o CEvent.o CAnimation.o CEntity.o -o CApp -lSDL -lSDL_image -lSDL_ttf

CApp.o:  CApp.cpp
	g++ -c CApp.cpp

CApp_OnInit.o: CApp_OnInit.cpp
	g++ -c CApp_OnInit.cpp

CApp_OnEvent.o: CApp_OnEvent.cpp
	g++ -c CApp_OnEvent.cpp

CApp_OnLoop.o: CApp_OnLoop.cpp
	g++ -c CApp_OnLoop.cpp

CApp_OnRender.o: CApp_OnRender.cpp
	g++ -c CApp_OnRender.cpp

CApp_OnCleanup.o: CApp_OnCleanup.cpp
	g++ -c CApp_OnCleanup.cpp

CSurface.o: CSurface.cpp
	g++ -c CSurface.cpp

CEvent.o: CEvent.cpp
	g++ -c CEvent.cpp

CAnimation.o: CAnimation.cpp
	g++ -c CAnimation.cpp

CEntity.o: CEntity.cpp
	g++ -c CEntity.cpp

clean:
	rm -f *.o CApp 
