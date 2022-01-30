#include <iostream>
using namespace std;

class Account
{
private:
	int balance; // Instance member variable

	//writting this simply and creating obj of acc class will not give this memory
	//we have to write static member definition outside class
	static float ROI; // static member variable - Also called class variable

public:
	void setBalance(int b)
	{
		balance = b;
	}
	// void setROI(float val)
	// {
	// 	ROI = val;
	// }

	//STATIC MEMBER FUNCTION
	//if we want to access setROI without creating any object we can declare that method static..this is the use of static member function
	static void setROI(float val)
	{
		ROI = val;
	}
};

// this is called membership label Account::
float Account::ROI = 3.5f; //bydefault it is 0;
//if we wont write this line then ROI will not get memory...so basically them memory of static variable does not depends on objects ...so this is called class variable not instance variable

int main()
{

	Account a1, a2;
	// so no matter how much object we create ROI variable will create only one time
	// also ROI var does not belongs to object

	//we can access ROI variable without creating object
	// Account::ROI= 4.5; //since ROI is private for now so we cannot access now

	// a1.setROI(4.5);

	//if we want to access setROI without creating any object we can declare that method static
	Account::setROI(4.5f);

	return 0;
}
