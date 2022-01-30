#include <iostream>
#include <fstream>
#include <string>

// Reference :  https://www.cs.uic.edu/~jbell/CourseNotes/CPlus/FileIO.html
using namespace std;

int main()
{

	//About ifstream
	string data;
	ifstream a;
	a.open("hi.txt");

	if (a.fail())
	{
		cerr << "Error - Failed to open "
		     << "hi.txt" << endl;
	}
	else
	{
		cerr << "Success opening file." << endl;
		cout << a.rdbuf() << " " << endl;
		// a >> data;
	}

	// cout<<data<<endl;
	a.close();



	//About ofstream
	ofstream b;
	b.open("outfile.txt");
	b << "This is outputted by code from iofstream.cpp file..." << endl;
	b.close();


	


	return 0;
}