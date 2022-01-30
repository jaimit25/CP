#include<iostream>
using namespace std;
int main(){
    //Rhombus pattern
    int i =1,j=1;
    int height;
    cout<<"Enter the height of the Rhombus:"<<endl;
    cin>>height;
    for(i =1;i<=height;i++ ){

        for(j=height-1;j>=i;j--){
            cout<<"  ";
        }
        for(j=1;j<=height;j++){
            cout<<" * ";
        }
        cout<<endl;
        
    }           
    return 0;
}