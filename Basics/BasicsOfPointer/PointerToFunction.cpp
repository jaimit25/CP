#include <iostream>  
using namespace std;  

int add(int x , int y)  
{  
    return x+y;  
}  
int main()  
{  
 //Syntax : returnType (*[pointervarName]) (parameters);
 int (*funcptr)(int,int);  // Declaration of function pointer
  funcptr=add; // In this case we are pointing to the add function  

 int sum=funcptr(7,10);  
 cout << "Sum=" <<sum<< endl;  
  return 0;  
} 