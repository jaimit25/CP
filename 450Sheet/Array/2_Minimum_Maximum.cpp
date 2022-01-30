#include <iostream>
using namespace std;

typedef struct Pair
{
	int min;
	int max;
} pairLR;

pairLR getMinMax(int *A, int l, int h)
{

	pairLR left, right, val;
	int mid;

	if (A[l] == A[h])
	{
		//single element in Array
		val.min = A[l];
		val.max = A[h];
		return val;
	}
	else if (h == l + 1)
	{
		//two elements in Array
		if (A[l] > A[h])
		{
			val.min = A[h];
			val.max = A[l];
		}
		else
		{
			val.min = A[l];
			val.max = A[h];
		}
		return val;
	}
	mid = (l + h) / 2;
	left = getMinMax(A, 0, mid);
	right = getMinMax(A, mid + 1, h);

	//For maximum
	if (left.max > right.max)
		val.max = left.max;
	else
		val.max = right.max;

	//For minimum
	if (right.min < left.min)
		val.min = right.min;
	else
		val.min = left.min;

	return val;
}

int main()
{
	pairLR val;
	int A[] = {1000, 1, 445, 9000, 330, 3000};
	// val = minmax(A, 0, 5);
	val = getMinMax(A, 0, 5);
	cout << val.min << " " << val.max << endl;
	return 0;
}