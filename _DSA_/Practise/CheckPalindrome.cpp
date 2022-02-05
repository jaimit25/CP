#include<iostream>
using namespace std; 

bool checkPalindrome(char *a){
	//getting length of Array
	int len  = 0 ; 
	for(len = 0 ; a[len] != '\0' ; len++){}
	len = len-1;
	for(int i = 0 , j = len ; i <=j; i++,j-- ){
		if(a[i] != a[j]){
			return false;
		}
	}
			return true;
}

int main(){

	char a[100] = "AC";
	if(checkPalindrome(a)){
		cout << "Palindrome" << endl;
	}
	else{

		cout << " Not Palindrome" << endl;
	}
	return 0;
}