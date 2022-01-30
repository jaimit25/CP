#include <iostream>
using namespace std;

//why do we create Abstract class :
//To get Generalization

//  ie      Person class
// 		|
// 	_________________
//   	|  		|
//    Teacher class       Student class

//...If we have a school then we are not interested in storing informatino about person but a person could be teacher or student
//so we store information about student like roll no and similarly for teacher we store there details ...but we store details of single individual who is not a part.. so that's why we need abstract class.

//A class containing pure virtual function is called Abstract class because we cannot create object for that class.

// Also we are making pressure on user who is creating child class to over-ride or to add a method compulsorily to that class.
class A
{

public:
	//This is a special syntax where we create this function but we dont give it a body outside and even inside class
	virtual void fun() = 0; //pure virtual function - do nothing function

	// we cannot create object of pure virtual function class but we can inherit this class
	//it is illegal to call a function that is not doing anything so that's why we cannot create Object.
};
class B : public A
{
public:
	void fun()
	{
		//fun function overrided -Compulsory if we inherit class with do nothing function
	}
};

int main()
{
	// we cannot create object of pure virtual function class but we can inherit this class
	// A a;

	//Now in any way we cannot call do nothing function we have blocked all it's way
	return 0;
}