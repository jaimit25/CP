#include<iostream>
#include<stdio.h>

using namespace std;
int main(){

    int a[5]={8,2,3,4,5};

    // cout<<sizeof(a)<<endl;
    // printf("%d",a[2]);

    for (int x : a){
        cout<<a[x]<<endl;
    }
   
    return 0;
}
