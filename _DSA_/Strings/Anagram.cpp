#include<iostream>
using namespace std;

int main(){

	char A[] = "decimal";
	char B[] = "medical";

	int  i;
	//remeber of length of A should be Equal to Length of B to be Anagram
	int H[26] = {0};

	for( i = 0 ; A[i] != '\0' ; i++){
		H[A[i]-97]++;
	}

	for( i = 0 ; B[i] != '\0' ; i++){
		H[B[i]-97]--;
		if(H[B[i] - 97] < 0){
			cout<<"Not Anagram"<<endl;
			break;
		}
	}

	if(B[i] == '\0'){
		cout<<"It is Anagram"<<endl;
	}
	return 0;
}