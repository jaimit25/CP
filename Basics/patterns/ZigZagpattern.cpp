// ./helloworls on terminal to run the program manually 
//comman+shift +b 
//stop code control + alt + m macos

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter Num"<<endl;
    cin>>n;

     for(int j=0;j<50;j++){
        cout<<" *";
    }

    cout<<endl;    

    for(int i=1;i<=3;i++){

        for(int j=1;j<=n;j++){

        if(((i+j)%4==0) || ( i==2 && j%4==0)){
        cout<<" *";
        }
        else{
        cout<<"  ";
        }
    }
    cout<<endl;
    }

    for(int i=0;i<50;i++){
        cout<<" *";
    }

    return 0;
}