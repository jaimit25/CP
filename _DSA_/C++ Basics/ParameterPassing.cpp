#include<iostream>
using namespace std;


//pass by value
// void swap(int a, int b){
// int temp;
// temp =a;
// a=b;
// b=temp;
// }


//pass by address
// void swap(int *a, int *b){
// int temp;
// temp = *a;
// *a=*b;
// *b=temp;
// }


// int main(){

// int a =12, b = 21;
// cout<<"value of a and b before swapping: "<<a<<" "<<b<<endl;
// cout<<"Swapping..."<<endl;
// swap(&a,&b);
// cout<<"a: "<<a<<" "<<"b: "<<b<<endl;

// return 0;
// }


//swapping using referencing
int swap(int &x, int &y){
int temp;
temp = x;
x=y;
y=temp;
return 0;
}


int main(){

int a =12, b = 21;
cout<<"value of a and b before swapping: "<<a<<" "<<b<<endl;
cout<<"Swapping..."<<endl;
swap(a,b);
cout<<"a: "<<a<<" "<<"b: "<<b<<endl;

return 0;
}