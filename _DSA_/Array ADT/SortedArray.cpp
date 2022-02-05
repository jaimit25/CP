#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Inserting in an Array
//Checking if an array is sorted
//Arranging -ve on left side

typedef struct Arrays
{
	int A[10];
	int size;
	int length;
} Array;

//swap function
void Swap(int *X,int *Y)
{

	int temp = *X;
	*X = *Y;
	*Y = temp;
}

//inserting in a sorted Array
void InsertingArray(Array &val, int element)
{
	int i = val.length - 1;
	if(val.length = val.size){
		return  ;
	}
	while (val.A[i] > element)
	{
		val.A[i + 1] = val.A[i];
		i--;
	}
	val.A[i + 1] = element;
	val.length++;
}

int SortedListCheck(Array val)
{

	for (int i = 0; i < val.length - 1; i++)
	{

		if (val.A[i] > val.A[i + 1])
		{
			return -1;
		}
	}
	return 0;
}

void Display(Array val)
{

	for (int i = 0; i < val.length; i++)
	{

		cout << val.A[i] << " ";
	}
	cout << endl;
}

void NegativeLeft(Array &val)
{

	int i = 0;
	int j = val.length - 1;
	while (i < j)
	{	
		
		while (val.A[i] < 0)
		{
			
			i++;
		}
		while (val.A[j] >= 0)
		{
			
			j--;
		}
		if (i < j)
		{
			Swap(&val.A[i], &val.A[j]);
		}
	}
}

int main()
{

	//....inserting and checking if array is sorted
	Array val = {{0, 1, 2, 3, 12, 55}, 10, 6};
	InsertingArray(val, 34);
	Display(val);
	cout << SortedListCheck(val) << endl;


	//.. Negative Element on Left Side of the Array
	Array NegativeArray = {{-1, 2, -4, 5, 6}, 10, 5};
	Display(NegativeArray);
	NegativeLeft(NegativeArray);
	Display(NegativeArray);

	return 0;
}