#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int kLargestEle(int *A, int k, int n)
{
	int i, j;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(A[j], A[j + 1]);
			}
		}
	}
	return A[n - k];
}

void print(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int main()
{

	int A[] = {2000, 11, 229, 1, 3000, 330};
	print(A, 6);
	cout << "kth Largest element in Array is : " << kLargestEle(A, 3, 6) << endl;
	print(A, 6);
	return 0;
}