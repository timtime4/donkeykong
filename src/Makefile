all: CApp

CApp:  CApp.o CApp_OnInit.o CApp_OnInit_Static.o CApp_OnStartup.o CApp_OnEvent.o CApp_OnLoop.o CApp_OnRender.o CApp_OnCleanup.o CSurface.o CEntity.o StaticObj.o Ladder.o Platform.o CTimer.o CMario.o CPeach.o CDonkeyKong.o CFire.o CBarrel.o
	g++ CApp.o CApp_OnInit.o CApp_OnInit_Static.o CApp_OnStartup.o CApp_OnEvent.o CApp_OnLoop.o CApp_OnRender.o CApp_OnCleanup.o CSurface.o CEntity.o StaticObj.o Ladder.o Platform.o CTimer.o CMario.o CPeach.o CDonkeyKong.o CFire.o CBarrel.o -o CApp -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

CApp.o:  CApp.cpp CApp.h CSurface.h CEntity.h CMario.h StaticObj.h Ladder.h Platform.h CTimer.h Define.h
	g++ -c CApp.cpp

CApp_OnInit.o: CApp_OnInit.cpp CApp.h CSurface.h CEntity.h CMario.h StaticObj.h Ladder.h Platform.h CTimer.h Define.h
	g++ -c CApp_OnInit.cpp

CApp_OnInit_Staic.o:  CApp_OnInit_Static.cpp CApp.h CSurface.h CEntity.h CMario.h StaticObj.h Ladder.h Platform.h CTimer.h Define.h
	g++ -c CApp_OnInit_Static.cpp

CApp_OnStartup.o:  CApp_OnStartup.cpp CApp.h CSurface.h CEntity.h CMario.h StaticObj.h Ladder.h Platform.h CTimer.h Define.h
	g++ -c CApp_OnStartup.cpp

CApp_OnEvent.o: CApp_OnEvent.cpp CApp.h CSurface.h CEntity.h CMario.h StaticObj.h Ladder.h Platform.h CTimer.h Define.h
	g++ -c CApp_OnEvent.cpp

CApp_OnLoop.o: CApp_OnLoop.cpp CApp.h CSurface.h CEntity.h CMario.h StaticObj.h Ladder.h Platform.h CTimer.h Define.h
	g++ -c CApp_OnLoop.cpp

CApp_OnRender.o: CApp_OnRender.cpp CApp.h CSurface.h CEntity.h CMario.h StaticObj.h Ladder.h Platform.h CTimer.h Define.h
	g++ -c CApp_OnRender.cpp

CApp_OnCleanup.o: CApp_OnCleanup.cpp CApp.h CSurface.h CEntity.h CMario.h StaticObj.h Ladder.h Platform.h CTimer.h Define.h
	g++ -c CApp_OnCleanup.cpp

CSurface.o: CSurface.cpp CSurface.h
	g++ -c CSurface.cpp

CEntity.o: CEntity.cpp CEntity.h CSurface.h Define.h
	g++ -c CEntity.cpp

StaticObj.o: StaticObj.cpp StaticObj.h CSurface.h CMario.h Define.h
	g++ -c StaticObj.cpp

Ladder.o:  Ladder.cpp Ladder.h StaticObj.h CSurface.h CMario.h Define.h
	g++ -c Ladder.cpp

Platform.o: Platform.cpp Platform.h StaticObj.h CSurface.h CMario.h Define.h
	g++ -c Platform.cpp

CTimer.o:  CTimer.cpp CTimer.h
	g++ -c CTimer.cpp

CMario.o:  CMario.cpp CMario.h CEntity.h CSurface.h Define.h
	g++ -c CMario.cpp

CPeach.o:  CPeach.cpp CPeach.h CEntity.h CMario.h CSurface.h Define.h
	g++ -c CPeach.cpp

CFire.o:  CFire.cpp CFire.h CEntity.h CMario.h CSurface.h Define.h
	g++ -c CFire.cpp

CBarrel.o:  CBarrel.cpp CBarrel.h CEntity.h CMario.h CSurface.h Define.h
	g++ -c CBarrel.cpp

CDonkeyKong.o: CDonkeyKong.cpp CDonkeyKong.h CEntity.h CMario.h CSurface.h Define.h
	g++ -c CDonkeyKong.cpp

clean:
	rm -f *.o CApp *~ 
