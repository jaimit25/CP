#ifndef hp_desktop
#define hp_desktop

#include "desktopBuilder.hpp"

class hp_desktopBuilder : public DesktopBuilder {
	 void buildMonitor();
	 void buildKeyboard();
	 void buildMouse();
	 void buildSpeaker();
	 void buildRam();
	 void buildProcessor();
	 void buildMotherBoard();
	
};

#endif

