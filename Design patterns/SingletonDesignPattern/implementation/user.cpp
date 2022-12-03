#include<iostream>
#include "logger.hpp"
#include<thread>

using namespace std;






int main()
{
	
	//BEFORE
	// Logger* logger1 = new Logger();
	// logger1->Log("mssg from user 1");

	// Logger* logger2 = new Logger();
	// logger2->Log("mssg from user 2");

	//Here two times the class instance is created



	//AFTER -  Not Thread Safe 
	Logger* logger1 = Logger::getLogger_Instance();
	logger1->Log("mssg from user 1");

	Logger* logger2 =  Logger::getLogger_Instance();
	logger2->Log("mssg from user 2");

	// Notes : When suppose multiple thread are working together or parellel then one thread will create instance of this class
	// 	   the other thread is working in parellel so it will also create one more instance(total 2 instance) beacuse thread 1 and 2 are working together so both finds that instance is not created together.




	
	
 
return 0;
}
 