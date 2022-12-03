#include<iostream> 
#include "car.hpp"
#include "bike.hpp"
#include<string> 
using namespace std;

int main(){

	string in;
	cin>>in;
	Vehicle *vehicle;
	if(in == "car"){
		vehicle = new Car();
	}
	else if(in == "bike"){
		vehicle = new Bike();
	}
	vehicle->createVehicle();


	// This idea fails when we need to create a vehicle like tempo or scooty etc.
	// We have to create a hpp file again for Scooty and Tempo...and the CLIENT has to select all the things like what type it is (ie. bike or car) OR the client file has the un-necessary "if else condition" which make is messier.
	// So we Therfore use Factory Design pattern.

	return 0;
}
