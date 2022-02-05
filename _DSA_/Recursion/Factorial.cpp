#include <iostream>
using namespace std;


int recursion(int n){

    if(n==0){
        return 1;
    }
    else{
        return recursion(n-1)*n;
    }
}

int loop(int n){

    int k=1;
    for(int i =1;i<=n;i++){
        k=k*i;
    }
    return k;
}


int main()
{
    cout << recursion(3) << endl;
    cout << loop(3) << endl;

    return 0;
}