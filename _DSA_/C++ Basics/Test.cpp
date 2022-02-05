#include<iostream>
#include<stdlib.h>

using namespace std;

 int main(){


	 int *n;
	 int a = 3;
	 n = &a;

	 //it will print address of the location in head memory
	 cout<<*n<<endl;

	//created an array of pointers of type int
	//   first * is for creating an Array 
	//   second * is for creating a pointer Array
	int *(*k);
	int e1= 2;
	int e2= 5;
	int e3= 8;
	int e4= 9;

	k = new int*[4];
	
	//intitialing all the value of an Array Manually
	k[0] = &e1;
	k[1] = &e2;
	k[2] = &e3;
	k[3] = &e4;

	// *k[0] will give you element at The Index 0  which is actually the addres of e1

		*k = {&e1};
	//printing all the elements of an array of pointers - type int 
	for(int i = 0 ; i < 4 ; i++){
		cout<<k[i]<<endl;
	}
	for(int i = 0 ; i < 4 ; i++){
		cout<<*k[i]<<endl;
	}

	 return 0;
 }