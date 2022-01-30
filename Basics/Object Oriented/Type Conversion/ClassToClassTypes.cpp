#include <iostream>
using namespace std;

class B
{
private:
	int l, m;

public:
	void setData(int x, int y)
	{
		l = x;
		m = y;
	}

	void showData()
	{
		cout << l << " + i" << m << endl;
	}
	int getL()
	{
		return (l);
	}
	int getM()
	{
		return (m);
	}
};

class A
{
private:
	int a, b;

public:
	A()
	{
	}
	A(B val)
	{
		a = val.getL();
		b = val.getM();
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

	A a1;

	B b1;
	b1.setData(2, 3);

	a1 = b1;
	a1.showData();
	return 0;
}