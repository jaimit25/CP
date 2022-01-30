#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
	}
	// A(int k)
	// {
	// }
};

class B : public A
{
public:
	// B()
	// {
	// 	//child class constructor will call parent class constructor when we have inheritance
	// }

	//Compiler will follow this special syntax when we dont have constructor
	B() : A()
	{
		//child class constructor will first call parent class constructor and then it will call it's own constructor
		//and for call order it will go from child to parent
	}

	//but when we have parameterized constructor in A then compiler will still try to call default constructor ... so it will give error
	//so in this case we have to do it manually:
	// B() : A(5)
	// {
	// }
};

//Other Variation
class C
{
protected:
	int a;

public:
	C(int x)
	{
		a = x;
	}

	~C()
	{
		// for destructor child class will execute it's first and then it will exectue parent class destructor
	}
};
class D : public C
{
	int f, g;

public:
	//how do we initialize variable a in parent class C
	D(int m, int n) : C(m)
	{
		f = m;
		g = n;
	}
	~D()
	{
		// for destructor child class will execute it's first and then it will exectue parent class destructor
		//compiler will not use " : " like constructor but it will write inside code inside ..." ~D(){ //body } "...  body.
	}
};

int main()
{
	B obj;

	return 0;
}