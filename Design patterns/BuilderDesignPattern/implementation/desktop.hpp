#ifndef desktop_h
#define desktop_h

// Product class

#include<string> 
using namespace std;

class Desktop {
	string monitor;
	string mouse;
	string keyboard;
	string speaker;
	string ram;
	string processor;
	string motherBoard;

	public : 
	
	void setMonitor(string pMonitor);
	void setMouse(string pMouse);
	void setKeyboard(string pKeyboard);
	void setSpeaker(string pSpeaker);
	void setRam(string pRam);
	void setProcessor(string pProcessor);
	void setMotherBoard(string pMotherBoard);
	void showSpecs();
	

};


#endif