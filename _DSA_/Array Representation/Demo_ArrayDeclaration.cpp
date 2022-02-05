#include<iostream>
using namespace std;

int main()
{
    int a[5];
    int b[2]={1,2};
    int c[10]={1,2,4,6};
    int d[4]={0};
    int e[]={1,2,3,4};
    for (int i=0;i<4;i++){
        cout<<&c[i]<<endl;
    }
    return 0;
}