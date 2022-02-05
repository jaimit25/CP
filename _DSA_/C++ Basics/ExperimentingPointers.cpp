#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
struct Rectangle
{
    int l;
    int b;
};

int main()
{
    int *a;
    float *b;
   char *c;
    struct Rectangle *r;
    cout << sizeof(Rectangle) << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    return 0;
}