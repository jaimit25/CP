
#include "vehicle_factory.hpp"
using namespace std;

Vehicle* VehicleFactory::getVehicle(string vehicleType){
	Vehicle *vehicle;
	if(vehicleType == "car"){
		vehicle = new Car();
	}
	else if(vehicleType == "bike"){
		vehicle = new Bike();
	}
	return vehicle;
}


// static keyword : we can directly call the function getVehicle without creating any object of class VehicleFactory