#ifndef vehicle_factory_hpp
#define vehicle_factory_hpp

#include "car.hpp"
#include "bike.hpp"
#include "vehicle.hpp"
#include <iostream> 

using namespace std;

class VehicleFactory : public Vehicle {
	public : 
	static Vehicle* getVehicle(string vehicleType);
};

#endif

// static keyword : we can directly call the function getVehicle without creating any object of class VehicleFactory