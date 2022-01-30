#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void print(int *, int );

// void rotate(int *arr, int n)
// {
// 	int i = 0, j = n - 1;

// 	for (i = 0, j = n - 1; i < j; i++,j--)
// 	{
// 		swap(&arr[i], &arr[j]);
// 	}
// 	print(arr,n);
// }

void rotate(int *arr, int n){

	
	int i = 0;
	int last = arr[n-1];
	for( i = n-1 ; i >= 0 ; i--){
		arr[i+1] = arr[i];
	}
	arr[0] = last;
	print(arr,n);
}



void print(int *A, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int main()
{

	int sz;
	cin >> sz;

	int *A = new int[sz];
	for (int i = 0; i < sz; i++)
	{
		cin >> A[i];
	}
	rotate(A, sz);
	return 0;
}