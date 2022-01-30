// ./helloworls on terminal to run the program manually 
//comman+shift +b 
//stop code control + alt + m macos

#include<iostream>
using namespace std;
int main(){
   

// about integers r
// it can make maximum number : 2 ^32-1
// ie because integer has 4 bytes
// and 1 byte = 8 bits 
// to represent integer negatively we represent msb as 1
// so we get 2 ^31 for negative axis and 2 ^31-1 on positive side 
//because +0 and -0 dont make sense
//visuals on int.png -photos

//for float 
//float can store 4 byte
//upto 7 decimal digits 

//for doubles
//size 8 bytes 
//can store upto 15 decimal digits

//for character
//size 1 byte
//we use ASCII table
//1 byte = 8 bits 
//total number of combinations possible we have 2^8 = 256 combinations

 //for boolean  
 //size 1 byte 


//sizeof function is use to get the size of datatype function
// int a =12;
// cout<<"Size of int is :"<<sizeof(a)<<" Bytes";

//Data Modifiers 
//signed ,unsigned ,long and short
//if we use unisgned  then we will have more range for int(4 byte) we have 4,294,967,295
//space consumed 4 bytes,4 bytes ,8 bytes and 2 bytes respectively.
 //ie how to modify length of data type 

 long int x;
 short int y;

// taking input from the terminal 
//cin operator is chainable 
//ie cin>>a>>b on terminal we will just add space ie. 100 200


return 0;

}