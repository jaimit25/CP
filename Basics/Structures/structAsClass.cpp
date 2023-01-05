#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;
//C++ allows use of methods into structure
struct book
{
	int id;
	char title[20];
	float price;
} b2;

//Encapsulation - combining all the func and var related to same interest together
struct Car
{
//private keyword disable use of speed and color var from main function
//Data security concept - so we use method to check and then assign if the value is correct then only assign to the var

private:
	int speed;
	int color;

//public methods or var can be used outside the function/method
public:
	int maxspeed()
	{
		return 200;
	}

	int display(){
		return color;
	}
};

int main()
{

	book b1 = {1, "First Chapter", 200};

	book b2;
	// b2.title = "Jaimit Panchal"; //wrong syntax - b2.title as a whole is consider as a name of Array name but it is not.
	strcpy(b2.title, "Jaimit Panchal");

	return 0;
}