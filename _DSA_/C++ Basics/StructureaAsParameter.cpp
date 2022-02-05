// #include<iostream>
// using namespace std;

// struct Rectangle{
// int length; 
// int breadth;
// };

// void fun(struct Rectangle r1){

// cout<<"length : "<<r1.length<<endl;
// cout<<"breadth : "<<r1.breadth<<endl;

// }

// int main(){

//     struct Rectangle r={10,5};
//     cout<<r.length<<" "<<r.breadth<<endl;

//     fun(r);

//     return 0 ; 
// }


//pass by address
#include<iostream>
using namespace std;

struct Rectangle{
int length; 
int breadth;
};

// void fun(struct Rectangle *r1){

// cout<<"length : "<<r1->length<<endl;
// cout<<"breadth : "<<r1->breadth<<endl;

// }

// int main(){

//     struct Rectangle r={10,5};
//     cout<<r.length<<" "<<r.breadth<<endl;
 
//     fun(&r);

//     return 0 ; 
// }

//passing address
 struct Rectangle *fun(){

     struct Rectangle *p;
     p = new Rectangle;

    p->length=12;
    p->breadth=14;
    
    return p;

 }

 int main(){

      struct Rectangle *ptr = fun();
      cout<<"length : "<< ptr->length<<" "<<"breadth: "<<ptr->breadth<<endl;

     return 0 ;
 }
 