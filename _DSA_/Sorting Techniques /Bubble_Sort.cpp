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
	cout<<endl;
}

void BubbleSort(int *A, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(A[j], A[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

int main()
{

	int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
	print(A,n);

	BubbleSort(A,n);
	print(A,n);


	return 0;
}