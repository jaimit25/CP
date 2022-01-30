#include<iostream>
using namespace std;

//Concepts
//METHOD OVERLOADING
//METHOD OVERIDING
//METHOD HIDING

class A { 

	public : 
	void f1(){}
	void f2(){}

};

class B :public A{ 

	public : 
	void f1(){} // This is method Overiding
	void f2(int a){} // This is method Hiding

};

int main(){

	B b1;

	b1.f1();
	//Early Binding - which f1 will be called f1 in class A or class B
	//so compiler will will check the object Data Type, so it's B ..then it will run f1 from class B if f1() is not there in B then it will run from A it it exist

	// b1.f2(); //this wil throw error 
	// Compiler will go to class B it will check f2 is there ..as f2 is there it will not go to Parent class which is A ..and also parameters didn't match so it will throw an Error

	//the is diff betwn function overloading and function hiding for overloading..both version of f2 should be there in one class

	return  0 ; 
}