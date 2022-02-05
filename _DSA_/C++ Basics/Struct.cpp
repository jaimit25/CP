#include<iostream>
#include<stdio.h>
using namespace std;

struct Rectangle{

    int length;
    int breath; 
    char a;
    //padding: happens while declating structure ,
    // which is allocating of more space but consuming less space than.

};

int main(){

    struct Rectangle r1={1,2,'a'};
    cout<<sizeof(Rectangle)<<endl;
    cout<< r1.length<<endl;
    
    return 0;
}