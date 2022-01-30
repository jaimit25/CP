#include <iostream>
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

	//we cannot create object of ostream class so we make reference ie..ostream&
	//so we will return reference

	// ostream class is derived from ios class. Constructor of ios class looks like below.

	// public: explicit ios (streambuf* sb);
	// protected: ios();
	// why ??  default constructor of ios is protected and hence you can't create object using default constructor of ostream.
	// Only way left to create object of ostream is using streambuf sb* argument.

	//Overloading  insertion operator
	friend ostream &operator<<(ostream &, complx);

	//overloading extraction operator
	//we are taking refrence of complx also because we want to make changes in the actual argument
	friend istream &operator>>(istream &, complx &);
};

ostream &operator<<(ostream &anyname, complx val)
{
	//we can use cout and anyname both because they are synonym
	//anyname is a reference variable which contain reference to cout --IMPORTANT
	anyname << "(" << val.a << ") + i(" << val.b << ")" << endl;
	return (cout); //we can write cout and anyname both
		       //we are returning so that we can do cascading
}

//we will take reference of complx class because we want to make changes in actual variable
istream &operator>>(istream &cinnn, complx &val)
{
	cinnn >> val.a >> val.b;
	//we are returning the istream class reference so that we can do cascading
	return (cinnn);
}

int main()
{
	complx c1, c2, c3;

	//cin is an object and it has called a function...(>>) which is basically overloaded by operator
	// cin.operator>>(c1);
	//or
	//cin>>c1;
	//one more thing the object cin has more then 1 function of this " >> " operator
	//like somtimes we pass cin>>integer value or cin >> character value ...float, double.
	//All this also apply for cout.operator<<(c1)
	// ie .. operator<<(cout, c1)  ..for using as a friend function also we can write this as cout<<c1;

	//cascading - cout<<c1<<c2;
	// for cascading once cout<<c1 is over we are not left with <<c2;
	//but we need cout on left side as the cout written for c1 works for c1 only, so wee need if for c2 also.
	//so we need return data type which is of type cout ..once this cout<<c1 has finished we need something on left of type cout.
	// so cout object which belongs to a class,.... we need object of cout class only for c2

	c1.setData(2, 3);
	cin >> c2;
	cout << c2;
	// c2.showData();

	return 0;
}

// PS:we use friend function to overload  istream and ostream class methods because we cannot code inside istream and ostream class so we use friend function to overload these 2 operators "<< and >>"(cin and cout are object of this two class).
// << and >> are methods of istream and ostream class