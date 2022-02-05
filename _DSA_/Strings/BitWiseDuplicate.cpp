#include<iostream>
using namespace std;


int main(){

	char A[] = "finding";
	int H , x;

	for(int  i = 0 ;A[i] != '\0'; i++){

		x  = 1;

		x = x << (A[i] - 97);

		if( (x & H ) > 0){
			cout<<x<<endl;
			// cout<<" Duplicate Found "<<A[i]<<endl; 
		}
		else{
			H  = H | x;
			// cout<<x<<endl;
		}
	}

	return 0;
}