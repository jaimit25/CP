
#include<iostream>
#include<stdlib.h>

using namespace std;

void swap(int *i ,  int *j){
	int temp = *i;
	*i = *j;
	*j = temp;
}
int KLargestElement(int *arr , int size , int k){

	int i = 0;
	int j = 0;
		   //k instead of size-1 
	for(i = 0 ; i < k; i++){
		for(j = 0 ; j < size - 1 ;j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j] , &arr[j+1]);
			}
		}
	}
	return arr[(size-1)-(k-1)];
}

void printArray(int arr[], int size){
	for(int i = 0 ; i < size ; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{

	int arr[] = {12,90,80,50,2,3,1};
	printArray(arr,7);

	cout<<"Element is : "<<KLargestElement(arr,6,3)<<endl;

	return 0;
}