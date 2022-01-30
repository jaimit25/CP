#include <iostream>
using namespace std;

class Complex
{

private:
	int a, b;

public:
	Complex()
	{
		//This is Default constructor
		//if we have atleast one Constructor in our class then constructor will not create any implicit constructor by itself ..so if below contructor exist then this constructor will not be created Automatically.
	}
	Complex(int x)
	{
		a = x;
	}
	Complex(int x, int y)
	{
		//This is Parameterized constructor
		a = x;
		b = y;
	}

	//we have three constuctor with diff parameters which is similar to function overloading ...called constructor Overloading

	// Copy constructor
	//there will be recursion because (Complex C )will be called Again and Again
	//So we have to use reference Varable not object variable otherwise it will go for recursion
	Complex(Complex &c)
	{
		a = c.a;
		b = c.b;
	}
	void showData()
	{
		cout << " (" << a
		     << ")+i(" << b << ") " << endl;
	}
};

int main()
{
	Complex c1(1, 2); //We called Parameterized constructor
	Complex c2;	  //We called Default constructor ..which can be hidden

	//ways of writting or creating Object
	// Complex c3 = Complex(3, 4); //this line will have problem with creating copy Constructor
	// Complex c4 = 3; //this will call this  "Complex(int x)" Constructor.

	Complex c5(c1); //compiler will create this contructor even though we know compiler does not create constructor if there exist atleast one
	//So compiler create two constructor one is default and other is copy constructor
	//so copy constructor it will create for sure it there does not exist any copy constructor.
	c5.showData();

	    return 0;
}