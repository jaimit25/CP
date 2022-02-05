#include<iostream>
#include<stdlib.h>
using namespace std; 
int main(){

    //creating array in heap memory firstly creating pointer to point in heap memory
    int *p;

    //using c syntax;
    // p = (int*)malloc(5*sizeof(int));

    // or usign c++ syntax
     p = new int[5];

    p[0]=12; p[1]=2; p[2]= 21; p[3]=32; p[4]=56;

    for (int i =0 ; i <5; i++){
        cout<< p[i]<<endl;
    }

    delete [] p;
    
    free (p);

    return 0 ; 
}