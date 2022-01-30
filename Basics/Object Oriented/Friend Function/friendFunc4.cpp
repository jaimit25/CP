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
		cout << "(" << a << ") +i(" << b << ")" << endl;
	}

	//member function
	// complx operator-()
	// {
	// 	complx c;
	// 	c.a = -a;
	// 	c.b = -b;
	// 	return (c);
	// }

	//friend function - for friend function we pass 1 argument extra in compare to member function
	friend complx operator-(complx c);
};

//unary operator as a friend function
complx operator-(complx val)
{
	complx c;
	c.a = -val.a;
	c.b = -val.b;
	return (c);
}

int main()
{
	complx c1, c2, c3;
	c1.setData(1, 2);
	c2 = -c1;
	c2.showData();
	return 0;
}