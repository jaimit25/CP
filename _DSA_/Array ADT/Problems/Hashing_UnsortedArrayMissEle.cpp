#include<iostream>
using namespace std; 

int main(){

int A[5] = {3,5,6,1,2};

int H[7]= {0};

for(int i = 0;i < 5;i++){
	H[A[i]]++;
}

for(int i = 1 ; i < 6 ; i++){
	if(H[i]==0){
		cout<<"Missing Element is  : "<<i<<endl;
	}
}

	return 0;
}