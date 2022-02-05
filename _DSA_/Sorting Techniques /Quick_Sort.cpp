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

int parition(int A[], int l, int h)
{

	int pivot = A[l];
	int i = l, j = h;

	do
	{
		do
		{
			i++;
		} while (A[i] <= pivot);
		do
		{
			j--;
		} while (A[j] > pivot);

		if (i < j)
		{
			swap(&A[i], &A[j]);
		}

	} while (i < j);

	//swapping pivot element after partitioning the smallest elements on the left side
	//and partioning the big elements on the right side of pivot element.

	swap(&A[l], &A[j]);

	//this will return pivot element after insertion to it's correct location.
	return j;
}

void QuickSort(int *A, int l, int h)
{
	int j;
	if (l < h)
	{
		j = parition(A, l, h);
		//actually this should be j-1 posn but jth position will act as infinity 
		QuickSort(A, l, j);
		QuickSort(A, j+1, h);

	}

}

int main()
{
							//INFINITE ELEMENT 
	int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, INT32_MAX}, n = 11;
	print(A, n-1);
	QuickSort(A, 0,10);
	print(A, n-1);

	return 0;
}