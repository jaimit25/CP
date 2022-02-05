#include<iostream>
using namespace std;


//version 1
int power(int m, int n){
if(n==0){
    return 1;
}else{
    return power(m,n-1)*m;
}
}


//version2
int power2(int m, int n){
    if(n==0){
        return 1;
    }
    else{
        if(n%2==0){
            //even
            return power2(m*m,n/2);
        }else{
            //odd
            return m*power2(m*m,(n-1)/2);
        }
    }
}

int loop(int m,int n){
int k=1;
for(int i =1; i<=n;i++){
k = k*m;
}
return k;
}

int main(){
cout<<"Enter the number m and value of n : "<<endl;
int m,n;
cin>>m>>n;
cout<<power(m,n)<<endl;
cout<<power2(m,n)<<endl;
cout<<loop(m,n)<<endl;
}