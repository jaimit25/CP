#include<iostream> 
#include "car.hpp"
#include "bike.hpp"
#include "vehicle.hpp"
#include "vehicle_factory.hpp"
#include<string> 
using namespace std;

int main(){

	string in;
	cin>>in; // vehicle type
	
	Vehicle* vehicle = VehicleFactory::getVehicle(in);// We dont need to create a class "VehicleFactory".
	vehicle->createVehicle();
	return 0;
}
