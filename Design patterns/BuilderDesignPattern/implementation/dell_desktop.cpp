#include "dell_desktop.hpp"

void dell_desktopBuilder::buildMonitor() {
  desktop->setMonitor("Dell Monitor");
}

void dell_desktopBuilder::buildKeyboard() {
  desktop->setKeyboard("Dell Keyboard");
}

void dell_desktopBuilder::buildMouse() { desktop->setMouse("Dell Mouse"); }

void dell_desktopBuilder::buildSpeaker() {
  desktop->setSpeaker("Dell Speacker");
}

void dell_desktopBuilder::buildRam() { desktop->setRam("Dell Ram"); }

void dell_desktopBuilder::buildProcessor() {
  desktop->setProcessor("Dell Processor");
}

void dell_desktopBuilder::buildMotherBoard() {
  desktop->setMotherBoard("Dell MotherBoard");
}
