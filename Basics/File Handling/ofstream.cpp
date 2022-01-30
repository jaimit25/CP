#include<fstream>
using namespace std;


int main(){

	ofstream ofs;

	ofs.open("ofstream.txt");
	ofs << "This file is written by ofstream.cpp file";
	ofs.close();
	return 0 ; 
}