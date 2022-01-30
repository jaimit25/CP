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

for(int i=1;i<=row;i++){
    for(int j=1;j<=column;j++){
        cout<<" * ";
    }
    cout<<endl;
}
 




return 0;
}