// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

void display(int *A, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void swap(int *x, int *y)
{

	int temp = *x;
	*x = *y;
	*y = temp;
}

void negativeOneSide(int *arr , int n ){
	int i = 0, j = 0 ;

	for(int j = 0 ; j < n ; j++) {
		if(arr[j] < 0){
			swap(&arr[j],&arr[i]);
			i++;
		}
	}
}

int main()
{

	int arr[] = {-1, 12, 13, -2, -4, -5, 3}, n = 7;
	int i, j = 0;

	display(arr, n);
	negativeOneSide(arr , n);
	// //optimized approach
	// for (i = 0; i < n; i++)
	// {
	// 	if (arr[i] < 0)
	// 	{

	// 		if (i != j)
	// 		{
	// 			swap(arr[i], arr[j]);
	// 		}

	// 		j++; //j pointer will  keep a track of positive number which are going to be shifted on the right side of the Array
	// 	}
	// }

	display(arr, n);

	return 0;
}