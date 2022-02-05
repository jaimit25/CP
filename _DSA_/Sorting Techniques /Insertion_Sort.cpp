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

void InsertionSort(int *A, int n)
{
	int i, j, x;
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		x = A[i];

		//for shifting elements we will use while loop
		while (j > -1 && A[j] > x)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}
int main()
{

	int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
	print(A, n);

	InsertionSort(A, n);
	print(A, n);

	return 0;
}