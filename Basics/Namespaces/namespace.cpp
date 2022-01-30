#include <iostream>
using namespace std; //this is standard namespace ..which is already made
//cout is made in std namespace

//namespace is Group of Declaration.
//Declaration is similar to class
//Syntax
//namespace is not a class so you cannot create object of namespace
namespace name
{
	int a;
	void fun();
	class A
	{
	public:
		void fun1(); //declaring namespace for class function below
	};
}

namespace ms = name; //Alias
//There are also unamed name spaces
// namespace
// {
// int a,b;
// void fun();
// }

//namespace can be extended

void name::A::fun1()
{
	cout << "This namespace is declared inside class and class is declared inside namespace name" << endl;
}

void name::fun()
{
	cout << "Hello" << endl;
	std::cout << "Hello" << endl; //other way to use std namespace
				      //cout object declaration is in std namespace
}

using namespace ms;
using namespace name;

int main()
{
	name::a = 12;
	a = 12; //it is using "[name]" namespace which we have declared upward

	return 0;
}