// ./helloworls on terminal to run the program manually
//comman+shift +b
//stop code control + alt + m macos

#include <iostream>
using namespace std;
int main()
{

   
    int height;
    cout << "Enter The Height Number Pattern" << endl;
    cin >> height;
    int i, j;

   for(int i =1;i<=height;i++){

       for(j=1;j<=height-i;j++){
           cout<<" ";
       }
       for(j=1;j<=i;j++){
           cout<<" "<<j;
       }

       cout<<endl;
   }

    return 0;
}