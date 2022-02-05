#include <iostream>
using namespace std;
int main()
{

    // int a = 10;
    // int *p;
    // p = &a;
    // cout<<a<<endl;
    // cout<< *p <<endl;
    //  int h =9;
    // cout<<"The Data of Variable h is stored at address : "<<&h<<endl;
    // return 0;

    int a[5] = {8, 5, 3, 5, 6};
    int *p;
    p = a;
    cout << "**********" << endl;
    cout << &a[0] << endl;
    cout << p << endl;
    cout << "**********" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << endl;
    }
    cout << "**********" << endl;
    for (int j = 0; j < 5; j++)
    {
        cout << &p[j] << endl;
    }
    return 0;
}