#include <iostream>
using namespace std; //

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

void swap(struct Array &val, int index, int swapindex)
{

	int x = val.A[index];
	val.A[index] = val.A[swapindex];
	val.A[swapindex] = x;
}

void swappointer(int *index, int *swapindex)
{
	int temp = *index;
	*index = *swapindex;
	*swapindex = temp;
}

int LinearSearch(struct Array &val, int key)
{

	for (int i = 0; i < val.Length; i++)
	{
		if (key == val.A[i])
		{
			return i;
		}
	}
	return -1;
}

int ImprovisedLinearSearch(struct Array &val, int key)
{

	for (int i = 0; i < val.Length; i++)
	{
		if (key == val.A[i])
		{
			//using reference
			// swap(val, i, i - 1);

			//using pointer Transposition
			// swappointer(&val.A[i],&val.A[i-1]);

			//using move to Front/Head
			swappointer(&val.A[i], &val.A[0]);

			return i - 1;
		}
	}
	return -1;
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
		{
			return mid;
		}
		else if (key < val.A[mid])
		{
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
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
		{
			return Recursive_BinarySearch(val, key, l, mid - 1);
		}
		else
		{
			return Recursive_BinarySearch(val, key, mid + 1, h);
		}
	}
	else if (key == val.A[mid])
	{
		return mid;
	}
	else
	{
		return -1;
	}
	return -1;
}

int main()
{
	struct Array A1 = {{1, 2, 3, 4, 5}, 10, 5};

	Insert(A1, 3, 25);
	
	Append(A1, 12);

	cout << Delete(&A1, 9) << endl;

	// cout << LinearSearch(A1, 4) << endl;
	// cout<<ImprovisedLinearSearch(A1,4)<<endl;
	// Display(A1);

	//recursive Binary Search
	cout << BinarySearch(A1, 4) << endl;
	cout << Recursive_BinarySearch(A1, 9, 0, 5) << endl;

	return 0;
}
