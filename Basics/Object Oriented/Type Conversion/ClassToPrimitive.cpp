#include <iostream>
#include<stdlib.h>


using namespace std;
//We will use Casting operator to convert Class to Primitive Type
class Complex
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
		cout << a << " + i" << b << endl;
	}

	operator int()
	{
		return (a);
	}
};

int main()
{
	Complex c1;
	c1.setData(3, 4);
	c1.showData();

	int x;
	x = c1; //c1.operator int();

	return 0;
}