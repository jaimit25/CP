#include <iostream>
using namespace std;

//Exception Handling
// It is abnormal behaviour during Run Time Error
//A program is Robust when it can Handle All types of Input
//try catch throw
//we can write multiple catch

int main()
{
	cout << "Welcome" << endl;

	try
	{
		throw 10;					    //once throw is run other statements after it won't Execute
		cout << "This line is After throw keyword" << endl; //This won't Run
	}
	//The value which we have thrown from inside try will get in catch (int e)
	// catch (int e)
	// {
	// 	cout << "Exception Number : " << e << endl;
	// }
	// catch(double a){
	// 	//this catch wont run because of double parameter
	// 	cout << "Exception Number : " << a << endl;
	// }
	catch (...)
	{
		cout << "Exception Number " << endl;
	}

	cout << "Last line" << endl; //this will run after Catch
	return 0;
}