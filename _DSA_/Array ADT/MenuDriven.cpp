#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Array
{
	int *A;
	int size;
	int length;
};

void Display(struct Array arr)
{
	int i = 0;
	cout << arr.length << endl;
	for (i = 0; i < arr.length; i++)
	{
		cout << arr.A[i] << endl;
	}
}

void Insert(struct Array *arr, int index, int x)
{

	int i;
	for (int i = arr->length; i > index; i--)
	{
		arr->A[i] = arr->A[i - 1];
	}

	arr->A[index] = x;
	arr -> length++;
}

int Delete(struct Array *arr, int index)
{

	int i;
	int x = 0;

	if (index >= 0 && index < arr->length)
	{

		for (int i = index; i < arr->length - 1; i++)
		{
			x = arr->A[index];
			arr->A[i] = arr->A[i + 1];
		}
		arr->length--;
		return x;
	}

	return 0;
}

void swap(int *x, int *y)
{

	int temp = *x;
	*x = *y;
	*y = temp;
}

int LinearSearch(struct Array *arr, int key)
{

	for (int i = 0; i < arr->length; i++)
	{

		if (arr->A[i] == key)
		{
			return i;
		}
	}
	return -1;
}

int BinarySearch(struct Array *arr, int key)
{

	int l, h, mid;

	while (l <= h)
	{

		mid = (l + h) / 2;
		if (key == arr->A[mid])
			return mid;
		else if (key < arr->A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int RBinSearch(int a[], int l, int h, int key)
{
	int mid;
	if (l <= h)
	{
		mid = (l + h) / 2;
		if (key == a[mid])
			return mid;
		else if (key < a[mid])
			return RBinSearch(a, l, mid - 1, key);
		else
			return RBinSearch(a, mid + 1, h, key);
	}

	return -1;
}

int Get(struct Array arr, int index)
{
	if (index >= 0 && index < arr.length)
		return arr.A[index];
	return -1;
}

// void Set(struct Array *arr, int index, int x)
// {
// }

int Max(struct Array arr)
{
	int max = arr.A[0];
	int i;
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] > max)
			max = arr.A[i];
	}
	return max;
}
int Min(struct Array arr)
{
	int min = arr.A[0];
	int i;
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] < min)
			min = arr.A[i];
	}
	return min;
}

int Sum(struct Array arr)
{
	int s = 0;

	int i;
	for (i = 0; i < arr.length; i++)
		s += arr.A[i];

	return s;
}

float Avg(struct Array arr)
{
	return (float)Sum(arr) / arr.length;
}
void Reverse(struct Array *arr)
{
	int *B;
	int i, j;
	B = (int *)malloc(arr->length * sizeof(int));
	for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
		B[j] = arr->A[i];
	for (i = 0; i < arr->length; i++)
		arr->A[i] = B[i];
}

void Reverse2(struct Array *arr)
{
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--)
	{
		swap(&arr->A[i], &arr->A[j]);
	}
}

void InsertSort(struct Array *arr, int x)
{
	int i = arr->length - 1;
	if (arr->length == arr->size)
		return;
	while (i >= 0 && arr->A[i] > x)
	{
	}
	arr->A[i + 1] = arr->A[i];
	i--;
	arr->A[i + 1] = x;
	arr->length++;
}
int isSorted(struct Array arr)
{
	int i;
	for (i = 0; i < arr.length - 1; i++)
	{
		if (arr.A[i] > arr.A[i + 1])
			return 0;
	}
	return 1;
}

void Rearrange(struct Array *arr)
{
	int i, j;
	i = 0;
	j = arr->length - 1;
	while (i < j)
	{
		while (arr->A[i] < 0)
			i++;
		while (arr->A[j] >= 0)
			j--;
		if (i < j)
			swap(&arr->A[i], &arr->A[j]);
	}
}

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
		else if (A->A[i] == B->A[j])
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
			i++;
			j++;
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

int main()
{
	struct Array arr1;
	int ch;
	int x, index;
	printf("Enter Size of Array");
	scanf("%d", &arr1.size);
	arr1.A = (int *)malloc(arr1.size * sizeof(int));
	arr1.length = 0;

	do
	{
		printf("\n\nMenu\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Sum\n");
		printf("5. Display\n");
		printf("6.Exit\n");
		printf("enter you choice ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			printf("Enter an element and index");
			scanf("%d %d", &x, &index);
			Insert(&arr1, index, x);
			break;

		case 2:
			printf("Enter index ");
			scanf("%d", &index);
			x = Delete(&arr1, index);
			printf("Deleted Element is %d\n", x);
			break;

		case 3:
			printf("Enter element to search ");
			scanf("%d", &x);
			index = LinearSearch(&arr1, x);
			printf("Element index %d", index);
			break;

		case 4:
			printf("Sum is %d\n", Sum(arr1));
			break;
		case 5:
			Display(arr1);
		}
	} while (ch < 6);

	return 0;
}