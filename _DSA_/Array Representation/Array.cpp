#include<iostream>
#include<stdlib.h>
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


    //Intializing Array in heap
    struct Array arr;
    cout<<"Enter Size of Array : ";
    cin >> arr.size;
    cout<<endl;
    arr.A = (int*)malloc(arr.size*sizeof(int));
    arr.length =0;


    int n,i;
    //for taking numbers and for loop
    cout<<"Enter how many numbers do you want to Enter : "<<endl;
    cin>>n;
    cout<<"Enter all Elements "<<endl;
    for(i=0;i<n;i++){
    cin>>(arr.A[i]);
    }
    arr.length=n;
    Display(arr);

    struct Arrays Arrstack = { {1,2,3,4 }, 20, 4};
    Displays(Arrstack);

    return 0;
}