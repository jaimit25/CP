#include <iostream>
using namespace std;

class Complex
{

private:
	int a, b;

public:
	Complex()
	{
	}
	Complex(int k)
	{
		a = k;
		b = 0;
	}

	void setData(int x, int y)
	{
		a = x;
		b = y;
	}
	void showData()
	{
		cout << a << " + i" << b << endl;
	}
};

int main()
{
	Complex c1;
	int x = 5;
	c1 = x; //we will use Constructor to assign primitive to class Type or c1.Complex(x);
	c1.showData();

	return 0;
}