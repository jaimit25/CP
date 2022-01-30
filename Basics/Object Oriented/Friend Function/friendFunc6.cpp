#include <iostream>
#include <stdlib.h>

using namespace std;

//member  fuction of one class can become friend to another class

class A
{
public:
	void fun()
	{
		//this is member func of class A
		//we want this member function to become friend of class B
	}
	void foo(){
	}
};

class B
{
public:
	//for friend function, declaration in private or protected or public dosent matter it behaves same.
	//friend void fun();    //wrong declaration - logical mistake
	//friend void A::fun(); //we want function which is in A class to be friend function of B so we use scope resolution operator to classify function as friend of class B

	//if we want all function of class A to be friend of class B then we can simply write
	friend class A;
};

int main()
{

	return 0;
}