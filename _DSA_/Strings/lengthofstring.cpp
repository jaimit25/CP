#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){

	char *name = "Jaimit";
	int i;
	for(i = 0 ; name[i] != '\0' ; i++){}
	cout<<"Length of string is " <<i<<endl;
	cout<<"last index we have :  " <<name[6]<<endl;

	return 0;
}