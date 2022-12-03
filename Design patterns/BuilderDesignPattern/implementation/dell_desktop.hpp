#ifndef dell_desktop_h
#define dell_desktop_h

#include "desktopBuilder.hpp"

class dell_desktopBuilder : public DesktopBuilder {
	
	 void buildMonitor();
	 void buildKeyboard() ;
	 void buildMouse();
	 void buildSpeaker();
	 void buildRam();
	 void buildProcessor();
	 void buildMotherBoard();
};

#endif
