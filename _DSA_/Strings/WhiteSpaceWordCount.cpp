#include<iostream>
using namespace std; //

int main(){

	char A[] = "Hi  There ma boy";
	int i = 0;
	int wordcount = 0;
	for( i = 0; A[i] != '\0' ; i++){
		if(A[i]==' ' && A[i-1] != ' '){
			wordcount++;
		}
	}
	cout<<"No of Words Are  : "<<wordcount+1<<endl;
	return 0;
}