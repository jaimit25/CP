// ./helloworls on terminal to run the program manually 
//comman+shift +b 
//stop code control + alt + m macos

#include<iostream>
using namespace std;
int main(){
//Rectangle pattern
int row ,column;
cout<<"Enter Number Of Rows And Column"<<endl;
cin>>row>>column;
int i=1 ,j=1;
        for(i=1;i<=row;i++){

            for(j=1;j<=column;j++){

                if(i==1||i==row){
                    cout<<" *";
                }
                else if(j==1||j==column){
                    cout<<" *";
                }
                else{
                    cout<<"  ";
                }

            }
                  
            cout<<endl;
        }
return 0;
}