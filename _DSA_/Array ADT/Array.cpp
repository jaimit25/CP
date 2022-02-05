#include<iostream>

 using namespace std; 


struct Array{
    int *A;
    int size;
    int length;
};

struct Arrays{
    int A[5];
    int size;
    int length;
};



void Display(struct Array a){
    //Displaying All Elements
    for(int i =0;i<a.length;i++){
        cout<<"Element At Index "<< i<<" is : "<<a.A[i]<<endl;
    }
}

void Displays(struct Arrays a){
    //Displaying All Elements
    for(int i =0; i < a.length; i++){
        cout<<"Element At Index "<< i<<" is : "<<a.A[i]<<endl;
    }
}


 int main(){

 

	 
	 return 0;
 }