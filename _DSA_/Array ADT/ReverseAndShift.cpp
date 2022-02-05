#include <iostream>
using namespace std;

typedef struct Array
{
	int A[10];
	int size;
	int length;
} Array;

void Display(struct Array Val)
{
	cout << "Printing ELement ...." << endl;
	for (int i = 0; i < Val.length; i++)
		cout << Val.A[i] << " ";

	cout << endl;
}

void Swap(int *x, int *y)
{

	int temp = *x;
	*x = *y;
	*y = temp;
}

void AuxillaryReverse(Array &val)
{

	Array b = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 10, 10};
	int i;
	int j;

	for (int i = 0, j = val.length - 1; i < val.length; i++, j--)
	{
		b.A[j] = val.A[i];
	}

	for (int i = 0; i < val.length; i++)
	{
		val.A[i] = b.A[i];
	}
}

void Reverse(Array val)
{

	for (int i = 0, j = val.length - 1; i < j; i++, j--)
	{
		Swap(&val.A[i], &val.A[j]);
	}
}

void LeftShift(Array &val)
{
	for (int i = 0; i < val.length; i++)
	{
		val.A[i] = val.A[i + 1];
	}
	val.A[val.length - 1] = 0;
}
void RightShift(Array &val)
{

	for (int i = val.length - 1; i > 0; i--)
	{
		val.A[i] = val.A[i - 1];
	}
	val.A[0] = 0;
}

int main()
{
	Array A = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};
	Display(A);

	AuxillaryReverse(A);
	Display(A);

	AuxillaryReverse(A);
	Display(A);

	LeftShift(A);
	Display(A);

	RightShift(A);
	Display(A);

	RightShift(A);
	Display(A);


	return 0;
}