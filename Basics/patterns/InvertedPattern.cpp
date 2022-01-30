// ./helloworls on terminal to run the program manually 
//comman+shift +b 
//stop code control + alt + m macos

#include<iostream>
using namespace std;
int main(){

 //program for inverted pattern
int height;
cout<<"Enter the Height of pyramid"<<endl;
cin>>height;
int i,j=1;

for(i=height;i>0;i--){
for(j=1;j<=i;j++){
cout<<j;
}
cout<<endl;
}
return 0;
}