#include<iostream>
#include<stdio.h>
#include<stdio.h>
using namespace std;

struct Array
{
	int A[10];
	int Size;
	int Length;
};

void Display(struct Array Val)
{
	cout << "Printing ELement ...." << endl;
	for (int i = 0; i < Val.Length; i++)
		cout << Val.A[i] << " ";

	cout << endl;
}

void Append(struct Array &val, int element)
{
	if (val.Length < val.Size)
	{
		val.A[val.Length++] = element;
		// val.Length++;
		cout << "Element Appended" << endl;
	}
	else
		cout << "Space Not Available" << endl;
}

void Insert(struct Array &val, int index, int element)
{
	if (index >= 0 && index < val.Size && val.Length < val.Size)
	{
		for (int i = val.Length; i > index; i--)
		{
			val.A[i] = val.A[i - 1];
		}
		val.A[index] = element;

		val.Length++;
		cout << "Element Inserted" << endl;
	}
	else
		cout << "No Space Available" << endl;
}

int Delete(struct Array *val, int index)
{
	int x = 0;
	if (index >= 0 && index < val->Length)
	{
		x = val->A[index];
		for (int i = index; i < val->Length - 1; i++)
		{
			val->A[i] = val->A[i + 1];
		}
		val->Length--;
		cout << "Element Deleted" << endl;
		return x;
	}
	return 0;
}

int BinarySearch(struct Array val, int key)
{
	int l = 0;
	int h = val.Size - 1;
	int mid = 0;

	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == val.A[mid])
			return mid;
		else if (key < val.A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

//for recursive binary search we need array as global
// struct Array Arr = {{1, 2, 3, 4, 5}, 10, 5};
int Recursive_BinarySearch(struct Array val, int key, int l, int h)
{
	int mid = (l + h) / 2;
	if (l <= h)
	{
		if (key < val.A[mid])
			return Recursive_BinarySearch(val, key, l, mid - 1);
		else
			return Recursive_BinarySearch(val, key, mid + 1, h);
	}
	else if (key == val.A[mid])
		return mid;
	else
		return -1;

	return -1;
}

 
int main(){

	struct Array A1 = {{1, 2, 3, 4, 5}, 10, 5};

	cout << BinarySearch(A1, 4) << endl;
	cout << Recursive_BinarySearch(A1, 9, 0, 5) << endl;

	return 0;
}