#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Array
{

	int A[10];
	int size;
	int length;
} Array;

int Get(Array val, int index)
{

	if (index >= 0 && index < val.length)
		return val.A[index];
	return -1;
}

void Set(int index, Array &val, int element)
{
	if (index >= 0 && index < val.length)
	{
		val.A[index] = element;
	}
}

int Max(Array val)
{
	int max = val.A[0];
	for (int i = 1; i < val.length; i++)
	{
		if (max < val.A[i])
			max = val.A[i];
	}
	return max;
}

int Min(Array val)
{
	int min = val.A[0];
	for (int i = 1; i < val.length; i++)
	{
		if (min > val.A[i])
			min = val.A[i];
	}
	return min;
}

int Sum(Array val)
{
	int Total = 0;
	for (int i = 0; i < val.length; i++)
	{
		Total = Total + val.A[i];
	}
	return Total;
}

int Rsum(Array val, int n)
{
	if (n < 0)
	{
		return 0;
	}
	else
	{
		return Rsum(val, n - 1) + val.A[n];
	}
}

int Average(Array val)
{

	int total = 0; //
	for (int i = 0; i < val.length; i++)
	{
		total = total + val.A[i];
	}
	return total / val.length;
}

void Display(struct Array Val)
{
	cout << "Printing ELement ...." << endl;
	for (int i = 0; i < Val.length; i++)
		cout << Val.A[i] << " ";

	cout << endl;
}

int main()
{

	Array arr = {{1, 2, 3, 4, 5}, 10, 5};
	cout << Get(arr, 2) << endl;

	Display(arr);

	Set(1, arr, 98);
	
	Display(arr);

	cout << "The sum of all element is : " << Sum(arr) << endl;

	cout << "The sum of all element Recursively is : " << Rsum(arr, 5) << endl;

	cout << "The Maximum element is : " << Max(arr) << endl;

	cout << " The minimum element is : " << Min(arr) << endl;

	cout << " the Average of all element is : " << Average(arr) << endl;

	return 0;
}