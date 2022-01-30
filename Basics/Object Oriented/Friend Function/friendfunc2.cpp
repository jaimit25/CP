#include <iostream>
using namespace std;

class B; // formal declaration of class B since we are using Class B before it was actually created inside class A - friend Function

class A
{

private:
	int a;

public:
	A(int A)
	{
		a = A;
	}
	friend void func(A, B);
};

class B
{
private:
	int b;

public:
	B(int B)
	{
		b = B;
	}
	friend void func(A, B);
};

void func(A o1, B o2)
{
	//this is unique since we are adding diff objects of type A and B together and also var member is private
	cerr << "Sum is : " << o1.a + o2.b << endl;
}

int main()
{

	A a(2);
	B b(3);
	func(a, b);

	return 0;
}