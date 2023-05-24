#include <iostream>
using namespace std;
int main()
{
    char x;
    int a;
    float b;
    long c;
    double d;
    long double e;
    long long int lli;

    cout<<"Size of char is : "<<sizeof(x)<<" bytes."<<endl;
    cout<<"Size of int is : "<<sizeof(a)<<" bytes."<<endl;
    cout<<"Size of float is : "<<sizeof(b)<<" bytes."<<endl;
    cout<<"Size of long is : "<<sizeof(c)<<" bytes."<<endl;
    cout<<"Size of double is : "<<sizeof(d)<<" bytes."<<endl;
    cout<<"Size of long double is : "<<sizeof(e)<<" bytes."<<endl;
    cout<<"Size of long long int is : "<<sizeof(lli)<<" bytes."<<endl;

    
    return 0;
}
