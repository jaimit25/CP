#ifndef logger_h
#define logger_h
#include<string> 
using namespace std;


class Logger {
	private : 
	static int ctr;
	Logger(); // Private - we cannot create object of this class.
	static Logger *loggerInstance; // this instance will be return everytime

	public : 
	// Logger(); // now we cannot create an object of the class Logger(_constructor is private now_).
	void Log(string msg);

	// To Access this class we will use Static method which will return an instance of this class.
	static Logger* getLogger_Instance();//create an instance and return this class instance itself.

};

#endif