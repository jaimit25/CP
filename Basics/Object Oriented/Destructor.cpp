#include <iostream>
using namespace std;

class Complex
{

private:
	int a, b;

public:
	Complex()
	{
		//this is constructor
	}
	~Complex()
	{
		// #this is destructor denoted by ~
		// #it cannot have static type
		// #it cannot take arguments
		// #it cannot be overloaded
		// #if we do not create destructor then compiler will create anti-body Destructor which means no-body
		//It is also called Automatically - it invokes when object is going to destroy ie..at the end of the main function  


		//we use destructor so that we can reallocate space or resources back to memory 
		// like if in this class we have a pointer then it should be reallocated as this class object is going to be destroyed 
	}
};

int main()
{

	return 0;
}