// #include <iostream>
// using namespace std;

// int *fun(int n)
// {

//     int *a;
//     a = (int *)malloc(n * sizeof(int));
//     a[3]=12;
//     return a;
// }

// int main()
// {

//     int *A;
//     A= fun(5);
//     for(int i =0; i<5; i++){
//         cout<<A[i]<<endl;
//     }
//     free (A);
//     return 0;
// }

#include<iostream>
using namespace std;
int fun(int A[]){
    cout<<sizeof(A)/sizeof(int)<<endl;
}

int main(){
    int A[]={1,2,3,4,5};
    fun(A);
     cout<<sizeof(A)/sizeof(int)<<endl; 
    return 0;
}