#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void SelectionSort(int *A, int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for( j = k = i ; j < n ; j++){
			if(A[j]<A[k]){
				// if we interchange the if condition we will get opposite result
				k = j;
			}
		}
		swap(A[k],A[i]);
	}
}
int main()
{

	int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
	print(A, n);

	SelectionSort(A, n);
	print(A, n);

	return 0;
}