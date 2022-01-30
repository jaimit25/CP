// ./helloworld on terminal to run the program manually
//comman+shift +b
//stop code control + alt + m macos

#include <iostream>
using namespace std;
int main()
{

    long int height;
    cout << "Enter The Height of Palindromic pattern" << endl;
    cin >> height;
    int i, j;
    cout<<"***********************************"<<endl;

   for(int i =1;i<=height;i++){
    
       for(j=1;j<=height-i;j++){
           cout<<"  ";
       }

      for(j=i;j>=1;j--){
          cout<<" "<<j;
      }

      for(j=1;j<=i;j++){
          if(j==1){
              cout<<"";
          }
          else{
              cout<<" "<<j;
          }
      }

       cout<<endl;

    }
cout<<"*****************************************"<<endl;
    return 0;
}