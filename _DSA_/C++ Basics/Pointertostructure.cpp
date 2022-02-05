#include<iostream>
#include<stdlib.h>
using namespace std;

struct Rectangle
{
int length;
int breadth;
};

int main(){

    struct Rectangle *p;
     p = (struct Rectangle* )malloc(sizeof(struct Rectangle));

    p -> length = 12;
    p -> breadth =13;

    cout<<p -> length <<endl;
    cout<<p -> breadth <<endl;

    free(p);

    return 0 ;
}