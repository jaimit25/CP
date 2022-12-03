
#include "logger.hpp"
#include <iostream>
#include <string>
using namespace std;

int Logger::ctr = 0;

Logger *Logger::loggerInstance = nullptr;

Logger::Logger() {
  ctr++;
  cout << "New instance created, Number of instances are : " << ctr << endl;
}
void Logger::Log(string msg) { cout << msg << endl; }

Logger *Logger::getLogger_Instance() {
  if (loggerInstance == nullptr) // this instance has never been created
  {
    loggerInstance = new Logger();
    return loggerInstance;
  } else {
    return loggerInstance;

  } // else we return the same instance which was previously created
}