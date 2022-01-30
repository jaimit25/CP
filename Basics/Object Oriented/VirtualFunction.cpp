#include <iostream>
using namespace std;
//Method overiding concept required 
class A
{

public:
	virtual void f1()
	{
	}
};

class B : public A
{

public:
	void f1()
	{
		//Function Overiding
	}
};

int main()
{
	A *a, a1, *o1;

	B b2;

	//Base class/Parent class pointer can point to any of it's descendant classes ie class A pointer can point to class B objects
	a = &a1;
	o1 = &b2;

	//Early binding will occur if we call by parent class or even by child class object or pointer
	//if we assign address of data type of class 2 to pointer of class A data type
	//then it should run f1() in child class but it is running f1() from  parent class
	//so we have to prevent Early binding ..means we want late binding
	// ...Means we want address to assign at run time
	// Solution to this is use virtual keyword in parent class function

	return 0;
}