#include "hp_desktop.hpp"

void hp_desktopBuilder::buildMonitor() {
  desktop->setMonitor("Hp Monitor");
}

void hp_desktopBuilder::buildKeyboard() {
  desktop->setKeyboard("Hp Keyboard");
}

void hp_desktopBuilder::buildMouse() { desktop->setMouse("Hp Mouse"); }

void hp_desktopBuilder::buildSpeaker() {
  desktop->setSpeaker("Hp Speacker");
}

void hp_desktopBuilder::buildRam() { desktop->setRam("Hp Ram"); }

void hp_desktopBuilder::buildProcessor() {
  desktop->setProcessor("Hp Processor");
}

void hp_desktopBuilder::buildMotherBoard() {
  desktop->setMotherBoard("Hp MotherBoard");
}
