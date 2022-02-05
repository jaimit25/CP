#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Array
{
	int A[10];
	int size;
	int length;
} Array;

Array *MergeArray(Array *A, Array *B)
{

	// Array C = {{0}, 10, A->length + B->length};
	Array *C = (Array *)malloc(sizeof(Array));
	C->length = A->length + B->length;

	int i = 0;
	int j = 0;
	int k = 0;

	while (i < A->length && j < B->length)
	{
		if (A->A[i] < B->A[j])
		{
			cout << C->A[k] << endl;
			C->A[k++] = A->A[i++];
		}
		else
		{
			C->A[k++] = B->A[j++];
			// cout<<"k : " << k << " j : " << j << endl;
		}
	}
	for (; i < A->length; i++)
	{
		C->A[k++] = A->A[i];
	}
	for (; j < B->length; j++)
	{
		C->A[k++] = B->A[j];
	}
	C->length = A->length + B->length;
	C->size = 10;

	return C;
}

void Display(Array val)
{

	for (int i = 0; i < val.length; i++)
	{

		cout << val.A[i] << " ";
	}
	cout << endl;
}

int main()
{

	Array A = {{2, 6, 10, 15, 25}, 10, 5};
	Array B = {{3, 4, 7, 18, 20}, 10, 5};

	Array *C;
	C = MergeArray(&A, &B);

	Display(*C);
	return 0;
}