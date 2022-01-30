#include<iostream>
#include<fstream>

using namespace std;

int main(){

	ifstream ifs;
	ifs.open("ofstream.txt");
	
	char ch; //readind first char from file
	//cin function is associated with keyboard inputs
	//here we are using extraction operator to read first char from data associated with ifs file 



	//ifs >> ch;   //after storing first char in ch the ifs pointer will point to next value automatically
	// >> extraction operator assumes space or " " as delimiter  or data Separator

	ch = ifs.get(); //this will not assume space as data delimitor or data separator
	//get() function we return char which it has read

	//to read all the char from file 
	while(!ifs.eof()) //eof stands for end of file ...if we are at file end then it returns true
	{
		cerr << ch;

		//reading next char from file
		// ifs >> ch;

		//instead of using extraction operator we can use 
		ch = ifs.get();

	}
	cout<<endl;
	ifs.close(); //closing file after use 
	return 0;
}