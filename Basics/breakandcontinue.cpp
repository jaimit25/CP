// ./helloworls on terminal to run the program manually 
//comman+shift +b 
//stop code control + alt + m macos

#include<iostream>
using namespace std;
int main(){
   

//break and continue 
//break will exit from the loop
//ie.
for(int i=0;i<5;i++){
    if(i==3){
        break;
    }
    cout<<i<<endl;
}

//continue will skip the current part of the loop
for(int i=0;i<5;i++){
    if(i==3){
       continue;
    }
    cout<<i<<endl;
}


return 0;

}