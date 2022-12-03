bash clean.sh

g++ -c bike.cpp car.cpp vehicle.cpp #to create a .o file
ar ru vehicle_library.a car.o bike.o # to create an archieve "vehicle_library.a"


g++ -o client client.cpp vehicle_library.a # //create a client

./client