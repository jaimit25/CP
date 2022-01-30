#include <iostream>
#include <stdlib.h>

using namespace std;

class complx
{

private:
	int a, b;

public:
	void setData(int x, int y)
	{
		a = x;
		b = y;
	}
	void showData()
	{
		cout << a << " +i" << b << endl;
	}

	//whenever we overload a binary operator we pass only 1 argument if we are making it as a member function

	//if we overload a binary operator as a friend function them we will pass more then 1 argument


	//overloading member function
	// complx operator+(complx val)
	// {
	// 	complx c;
	// 	c.a = val.a + a;
	// 	c.b = val.b + b;
	// 	return c;
	// }

	//overloading friend function
	friend complx operator+(complx, complx);
};

complx operator+(complx c1, complx c2)
{
	complx c;
	c.a = c1.a + c2.a;
	c.b = c1.b + c2.b;
	return (c);
}

int main()
{
	complx c1, c2, c3;
	c1.setData(1, 2);
	c2.setData(2, 3);
	c3 = c1 + c2;
	c3.showData();

	return 0;
}