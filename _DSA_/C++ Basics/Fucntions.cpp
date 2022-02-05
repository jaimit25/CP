#include<iostream>
using namespace std;

int add(int a , int b ){

int result;

result = a+b;
return result;
}

 int main(){

     int num1;
     int num2;
     num1 = 12;
     num2 = 8;
     int ans = add(num1, num2);
     cout<<"The Answer for addition is : "<<ans<<endl;


     return 0 ;
 }