#include<iostream>
using namespace std;

int main(){

	//this is swapping of Array Elements
	char A[] = "PYTHON";
	int temp;
	int i, j;
	for(j = 0; A[j] != '\0' ;j++){
		//calculating length of the Array
	}
	// cout<<"Length of Array is : "<<j<<endl;
	j = j-1;
	for( i = 0 ; i<j;j--,i++){
		temp = A[j];
		A[j] = A[i];
		A[i] = temp;
	}
	cout<<A<<endl;
	return 0;
}