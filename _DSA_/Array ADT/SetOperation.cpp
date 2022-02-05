#include <iostream>
using namespace std;

typedef struct Array
{
	int A[10];
	int size;
	int length;
} Array;

Array *Union(Array *A, Array *B)
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
			//if A is small then copy and increment i
			C->A[k++] = A->A[i++];
		}
		else if (B->A[j] < A->A[i])
		{	
			//if B is small then copy B and increment j
			C->A[k++] = B->A[j++];
		}
		else
		{	
			//same elements
			C->A[k++] = A->A[i++];
			j++;
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
	C->length = k;
	C->size = 10;

	return C;
}


Array *Intersection(Array *A, Array *B)
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
			//only copy if element is eql otherwise increment
			i++;
		}
		else if (B->A[j] < A->A[i])
		{	
			//only copy if element is eql otherwise increment
			j++;
		}
		else if( A -> A[i] == B -> A[j] )
		{	
			//same elements
			C->A[k++] = A->A[i++];
			j++;
		}
	}
	
	C->length = k;
	C->size = 10;

	return C;
}



Array *Difference(Array *A, Array *B)
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
			//only copy from element in A 
			C->A[k++] = A->A[i++];
		}
		else if (B->A[j] < A->A[i])
		{	
			j++;
		}
		else
		{	
			//only copy when A is small 
			i++;j++;
		}
	}
	for (; i < A->length; i++)
	{
		C->A[k++] = A->A[i];
	}
	
	C->length = k;
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
	Array B = {{3, 6, 7, 15, 20}, 10, 5};

	Array *C;
	C = Union(&A, &B);
	Display(*C);

	Array *D;
	D = Intersection(&A,&B);

	Display(*D);

	Array *E;
	E = Difference(&A,&B);

	Display(*E);

	return 0;
}