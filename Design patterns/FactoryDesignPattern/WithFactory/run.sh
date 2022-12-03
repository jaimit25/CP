bash clean.sh

g++ -c vehicle_factory.cpp bike.cpp car.cpp vehicle.cpp #to create a .o file
ar ru vehicle_library.a vehicle_factory.o car.o bike.o # to create an archieve "vehicle_library.a"


g++ -o smartclient client.cpp vehicle_library.a # //create a client

./client