#include<iostream>
#include<stdio.h>
using namespace std; 
int main(){

	char A[] = "HI how Are You Ma Boy";
	int i ;
	int wordcount = 0;
	for( i = 0 ; A[i] != '\0' ;i++){
		if(A[i] == ' '){
			wordcount++;
		}
	}
	printf("No of Words Are  : %d \n",wordcount+1);

	return 0;
}