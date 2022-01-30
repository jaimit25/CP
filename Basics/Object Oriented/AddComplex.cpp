#include <iostream>
using namespace std;

//There is not much difference betwn class and struct
//class member are by default private where as struct members are by default public
struct Complex
{
	int a;
	int b;
};

class complx
{

private:
	int a;
	int b;

public:
	void setVAL(int, int); // we can write member function outside using scope resolution operator
	
	void display()
	{
		cerr << a << " + i" << b << endl;
	}

	complx add(complx val)
	{
		complx c;
		c.a = a + val.a;
		c.b = b + val.b;

		return c;
	}
};

void complx::setVAL(int A, int B)
{
	a = A;
	b = B;
}

int main()
{
	complx a, b, c;
	a.setVAL(1, 2);
	b.setVAL(2, 3);

	c = a.add(b);
	c.display();
	return 0;
}