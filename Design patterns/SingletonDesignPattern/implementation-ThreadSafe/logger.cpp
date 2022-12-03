
#include "logger.hpp"
#include <iostream>

using namespace std;

int Logger::ctr = 0;
Logger *Logger::loggerInstance = nullptr;
mutex Logger::mtx;

// Logger Constructor
Logger::Logger() {
  ctr++;
  cout << "New instance created, Number of instances are : " << ctr << endl;
}

// Logger Function to Log message
void Logger::Log(string msg) { cout << msg << endl; }

// Logger Function to return an instance of this class.
Logger *Logger::getLogger_Instance() {


  // Double Checking the logger - if instance is already created then no need to lock that part of that code.
  // Putting a lock on the code is really expensive so we dont lock the code everytime.

  if (loggerInstance == nullptr) {

    // we will lock this part of the code when one thread is accessing this
    // part(so other thread cannot access this part of the code).
    mtx.lock();
    if (loggerInstance == nullptr) {
      loggerInstance = new Logger();
    }

    mtx.unlock();
  }

  return loggerInstance;
}