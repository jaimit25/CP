// Product class
#include "desktop.hpp"
#include <iostream>

void Desktop::setMonitor(string pMonitor) { monitor = pMonitor; }

void Desktop::setMouse(string pMouse) { mouse = pMouse; }

void Desktop::setKeyboard(string pKeyboard) { keyboard = pKeyboard; }

void Desktop::setSpeaker(string pSpeaker) { speaker = pSpeaker; }

void Desktop::setRam(string pRam) { ram = pRam; }

void Desktop::setProcessor(string pProcessor) { processor = pProcessor; }

void Desktop::setMotherBoard(string pMotherBoard) {
  motherBoard = pMotherBoard;
}

void Desktop::showSpecs() {
  cout << " ______________________________________________________" << endl;
  cout << " Monitor : " << monitor << endl;
  cout << " mouse : " << mouse << endl;
  cout << " keyboard : " << keyboard << endl;
  cout << " speaker : " << speaker << endl;
  cout << " ram : " << ram << endl;
  cout << " processor : " << processor << endl;
  cout << " motherBoard : " << motherBoard << endl;
  cout << " ______________________________________________________" << endl;
}