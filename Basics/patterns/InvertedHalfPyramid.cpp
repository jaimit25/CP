// ./helloworls on terminal to run the program manually 
//comman+shift +b 
//stop code control + alt + m macos

#include<iostream>
using namespace std;
int main(){

int height;
cout<<"Enter Height Of Pyramid"<<endl;
cin>>height;
int i,j;

for(i=height;i>0;i--){
    for(j=1;j<=i;j++){
        cout<< " *";
    } 
    cout<<endl;
}

return 0;
}