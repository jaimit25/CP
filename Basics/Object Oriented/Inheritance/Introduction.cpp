#include <iostream>
using namespace std;

//Also called as base class or parent class
class BaseClass
{
public:
};

//also called as derived or new class
//syntax : class NewClassName : visible_mode ParentClassName
class DerivedClass : public BaseClass
{
public:
};

//Type of Inheritance

// Single Inheritance
// - Above example ie.. a-b

// MultiLevel  Inheritance - ie.. a-b-c Transitive Relationship
//class A{};
// class B : public A{};
// class C : public B{};

//Multiple Inheritance -
//class A{};
//class C{};
// class B : public A,public C {
//           Code
//                                   };

//Hierarchical Inheritance
// class A{ };

//class B : public A{
// };

//class C : public A{
// };

//Hybrid Inheritance
//Mixture of more then one type of Inheritance


// Visiblity Mode :
// public : 
// private : 
// protected : 


int main()
{

	return 0;
}