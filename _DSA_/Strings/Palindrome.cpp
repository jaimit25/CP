#include<iostream>
using namespace std;

int main(){

	char A[] = "jij";
	int i , j;
	for(j = 0; A[j] != '\0' ; j++){
		//Assigning length to j
	}
	
	for(i = 0 , j = j-1 ; i < j ;i++,j--){
		if(A[i] != A[j]){
			cout<<"String Not A Palindrome"<<endl;
			break;
		}
	}

	return 0;
}