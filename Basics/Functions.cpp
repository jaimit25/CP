#include<iostream>

using namespace std;


void print(int value){
    cout<<value;
}
void println(int value){
    cout<<value<<endl;
}

int sum(int a,int b){
    int answ =a+b;
    println(a);
    println(b);
    return answ;
}

int main(){
    
   //whenever a function is called System allocates a chunk of memory to the function 
   //the memory chunk is called as stack frame
   //the top most stack frame is the active frame
   //whenever a fucntion returns something it is then popped of from the stack frame


    int ans;
    ans=sum(2,3);
    cout<<"The Answer is : "<<ans<<endl;
    return 0;
}