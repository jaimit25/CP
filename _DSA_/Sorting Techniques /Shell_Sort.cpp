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

void Shell_sort(int A[], int n)
{

	int gap, i, j;
	int temp;

	//outer loop will control the gap
	for (gap = n / 2; gap >= 1; gap = gap / 2)
	{

		//inner loop will control the sliding of index pointer i till the end of the Array
		for (i = gap; i < n; i++)
		{
			temp = A[i];

			//getting the index of the value
			j = i - gap;

			//going backwards to shift the element
			while (j >= 0 && A[j] > temp)
			{
				A[j + gap] = A[j];
				j = j - gap;
			}
			A[j + gap] = temp;
		}
	}
}

int main()
{

	int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10;
	print(A, n);

	Shell_sort(A, n);
	print(A, n);

	return 0;
}