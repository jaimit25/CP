#include<iostream>
using namespace std;
int main(){

	char A[] = "PYTHON";

	//using 2 Arrays to Reverse to String
	char B[7];
	int i,j;
	for(i  = 0 ; A[i] != '\0'; i++){
		//calculating length of Array
	}
	i = i-1;
	for(j = 0 ; i >= 0 ;i--, j++){
		B[j] = A[i];
	}
	B[j] = '\0';
	cout<<B<<endl;
	return 0;
}