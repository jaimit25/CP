#include <iostream>
using namespace std;
int main()
{

    //linear complexity
    int i;
    cin>>i;
    for(int j =0;j<i;j++){
        cout<<i;
    }
    //the above loops runs for a every single value of i so it is liner
    //or it is doing the given task inside the loop the i times




    //quadratic complexity 
    int n;
    cin>>n;
    for(int x=0;i<n;x++){

     for (int y =0;y<n;y++){
         cout<<x<<" "<<y<<endl;

     }   
    }

    //the above loop is running for n*n time which is n2
    //for evry n single value of first for loop it is running inside for loop n times




    //A program should be consider on following factors to be effcient and fast
    // time complexity
    //space complexity


    //space complexity of an algorithm quantifies the amount of time taken by a program to 
    //run as a function of length of the input. it is directly proportional to largest 
    //memory your program acquire at any instance during run time.

    // if three integer variable are created then the the proram is taking 12 byte because
    // each int value corresponds to 4 byte.
    // also if i put value of n
    int a=0,n,m;
    cin>>n;
    //anything it dosent push the memory. as it is already fixed.
    //space complexity is constant


    //worst case 
    //denoted by big oh notation
    //if we have to find an elemnt in group of element then sometimes we have to loop over every element and
    //to check the element we want is there and on what posn

    //if we found the element at the end of the group then it is worst case
    // ie we have to find 21
    // 212 6 8 21

    //best case denoted by omega
    //found element at beggining then it is best case
    //so we can say it is constant

    //average case 
    //denoted by theta
    //avg case=n(n+1)/n = (n+1)/2


    //in worst case time complexity is proportional to n
    //n= total number of element
    //in best case time complexity is constant
    // in average case time complexity is again n 

    return 0;
}