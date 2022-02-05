#include<iostream>
using namespace std;
int main(){

	char N[]="WELCOME";
	printf("before : %s \n",N);
	//string simple case conversion lower to upper
	for(int i  = 0 ; N[i] != '\0';i++){
		N[i]=N[i]+32;
	}
	printf("%s",N);
	printf("After  : %s \n",N);


	char A[]="wElcoMe";
	printf("before : %s \n",A);
	//string simple case conversion
	for(int i  = 0 ; N[i] != '\0';i++){
		if(A[i]>=65 &&A[i]<=90){
			//uper Case to lower case
			A[i]=A[i]+32;

		}else if(A[i]>='a' && A[i] <= 'z'){
			//lower case to upper case
			A[i]=A[i]-32;
		}
	}
	printf("After : %s \n",A);
	return 0;
}