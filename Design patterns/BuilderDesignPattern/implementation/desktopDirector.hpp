#ifndef desktopDirector
#define desktopDirector

#include "desktop.hpp"
#include "desktopBuilder.hpp"

class DesktopDirector {
private:
  DesktopBuilder *desktopBuilder;

public:
  DesktopDirector(DesktopBuilder *pDesktopBuilder) {
    desktopBuilder = pDesktopBuilder;
  }

  Desktop *getDesktop() { return desktopBuilder->getDesktop(); }
  Desktop *buildDesktop() {
    desktopBuilder->buildMonitor();
    desktopBuilder->buildMouse();
    desktopBuilder->buildKeyboard();
    desktopBuilder->buildMotherBoard();
    desktopBuilder->buildProcessor();
    desktopBuilder->buildSpeaker();
    desktopBuilder->buildRam();
    return desktopBuilder->getDesktop();
  }
};

#endif
