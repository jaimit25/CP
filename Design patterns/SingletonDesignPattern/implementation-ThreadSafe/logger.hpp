#ifndef logger_h
#define logger_h
#include<string> 
#include<mutex> 


using namespace std;


class Logger {
	private : 
	static int ctr;
	Logger(); 
	Logger(const Logger&);  // making the copy constructor also private so user cannot access anytype of the constructor.
	Logger operator =(const Logger&); // make the operator overloading also private so user cannot access this class by any-how.

	static Logger *loggerInstance; 
	static mutex mtx;

	public : 
	void Log(string msg);
	static Logger* getLogger_Instance();  // return this loggerInstance instance of this same class;
};

#endif