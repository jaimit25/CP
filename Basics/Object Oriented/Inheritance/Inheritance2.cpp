#include <iostream>
using namespace std;

class A
{

private: //if its private then we cant use this var in class B
	int a;

protected: //this can be use in class B
	void setValue(int k)
	{
		a = k;
	}
};

class B : public A
{
public:
	void setData(int x)
	{
		// a = x;
		setValue(x);
	}
};

int main()
{
	B b1;
	b1.setData(2);
	return 0;
}