#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

//diff file opening modes 

// ios::in input/read
// ios::out output/write -- this will erase old content of the file
// ios::app append
// ios:: update
// ios::binary binary 

int main(){

	ofstream fout; //represent output stream 
	//fout.open("myfile.dat", ios::out); //opening and bringing file from hard-disk to RAM --default

	//fout.open("myfile.dat", ios::app); //opening and bringing file from hard-disk to RAM and appending mode

	//we can open file in multiple mode too
	fout.open("myfile.dat", ios::app | ios::binary);

	// fout cannot use ios::in because it is ofstream object
	//whenever we write ios::binary means that file is opening in binary mode
	//if we do not mention ios::binary then that file will open in TEXTMODE 


	// if we use binary mode then the file which is to be written and has some special symbol like \n then they will be written as it is and there special meaning will not be considered


	return 0 ; 
}