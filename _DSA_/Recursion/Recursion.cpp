#include<iostream>
#include<stdio.h>

using namespace std; 

void fun(int n){

//base condition
if(n>0){
cout<<n<<endl;
//calling function again Recursively
fun(n-1);
}

}

int main(){

    int x =3;
    fun(3);



    return 0;
}