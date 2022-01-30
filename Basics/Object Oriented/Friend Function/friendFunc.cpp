#include <iostream>
using namespace std;

class complx
{

private:
	int a;
	int b;

public:
	void setData(int x, int y)
	{
		a = x;
		b = y;
	}

	void show()
	{
		cerr << a << " + i" << b << endl;
	}

	friend void fun(complx);
};

//wrong
// void fun(complx c)
// {
// 	cerr << " sum is : " << a << " + i" << b << endl;
// }

//correct
void fun(complx c)
{
	cerr << " sum is : " << c.a << " + i" << c.b << endl;
}

int main()
{
	complx c1, c2;
	c1.setData(1, 2);
	c2.setData(2, 3);
	// friend function dont need caller obj like c1.fun()
	// but also when we call them we need make them meaningfull like obj c1 or c2 we are calling
	fun(c1);
	return 0;
}