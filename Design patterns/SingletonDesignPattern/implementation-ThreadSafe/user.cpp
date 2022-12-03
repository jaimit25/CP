#include<iostream>
#include "logger.hpp"
using namespace std;

void user1_log(){
	Logger* logger1 = Logger::getLogger_Instance();
	logger1->Log("mssg from user 1");
}

void user2_log(){
	Logger* logger2 =  Logger::getLogger_Instance();
	logger2->Log("mssg from user 2");
}

int main()
{
	//Create two thread one will create user1 log and other will create user 2 log
	thread t1(user1_log);
	thread t2(user2_log);

	t1.join();
	t2.join();

	 //when there are two thread then we locked(using mutex library) the particular code 
	 //which one thread is accesing and so the other thread wont access that part




 
return 0;
}
 