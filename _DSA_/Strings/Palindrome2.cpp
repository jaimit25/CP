#include<iostream>
#include<stdio.h>

using namespace std;

int main(){

	char A[] = "jiaj";
	char B[6];

	int i,j;
	for(j = 0; A[j] != '\0' ; j++){
		//Assigning length to j
	}
	cout<<j<<endl;
	for(i = 0 , j = j - 1 ; A[i] != '\0' ; i++ , j--){
		B[i] = A[j];
		cout<<A[j]<< " "<<A[j]<<endl;
	}

	B[i] = '\0';
	for(i = 0; i < 6 ; i++){
		if(A[i] != B[i]){
			cout<<" String Not a Palindrome "<<endl;
		}
	}
	
	return 0;
}