#include <iostream>
#include <stdlib.h>

using namespace std;

void Insert(int H[], int n)
{

	int i = n, temp;
	temp = H[i];

	//we are comparing it with parent value so we took i/2
	while (i > 1 && temp > H[i / 2])
	{
		H[i] = H[i / 2];
		i = i / 2;
	}
	H[i] = temp;
}

int Delete(int A[], int n)
{

	int i, j, x, temp;
	int val = A[1]; //we will store the deleted value or root value
	x = A[n];	// storing last element in the variable x
	A[1] = A[n];	//storing last element to the front of the array
	A[n] = val; //last index should be assigned with deleted value

	i = 1;
	j = 2 * i; // i will point to the parent node and j will point to the left child of the parent node pointed by i.

	//for Adjusting element after deletion
	while (j < n - 1)
	{

		//first we will check which child is greater left or right child of parent pointer by i.
		if (A[j + 1] > A[j])
		{
			j = j + 1;
		}
		// i - pointing to the parent Node
		// j - pointing to the child which is bigger. it may be left child or right child.
		if (A[i] < A[j])
		{

			//swapping elements of the Array.
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;

			//updating new position for i and j.
			// i will be on the new Value as a parent Node which was j previously.
			i = j;
			// j should be pointing to the new left child.
			j = 2 * j;
		}
		else
		{
			//value of parent node is greater then the value of child Node then we dont have to do anything.
			// also we can say value of parent node is properly adjusted od greater then its child value so we don't have to do anything.
			break;
		}
	}

	return val;
}

void print(int H[], int size)
{
	cout<<endl;
	for (int i = 1; i <= size; i++)
	{
		cout << H[i] << " ";
	}
	cout << endl;
	cout << endl;
}

int main()
{

	//we will create a heap and we are not setting 0th index as we are not using it in heap
	int H[] = {0, 10, 20, 30, 25, 5, 40, 35};

	// Insert(Array , index );
	// Insert(H,2);
	// Insert(H,3);
	// Insert(H,4);
	// Insert(H,5);

	//Insert using Loop
	for (int i = 2; i <= 7; i++)
	{
		Insert(H, i);
	}

	cout<<"Heap Created .. "<<endl;
	//printing using loop
	print(H, 7);


	//MANUALLY DELETING ELEMENTS
	// // once we delete one element heap size will be reduced Automatically
	// cout << "Deleted value is : " << Delete(H, 7) << endl;

	// //printing using loop
	// print(H, 7);

	// //we have deleted 40 as root so the new heap size is updated to 6
	// cout << "Deleted value is : " << Delete(H, 6) << endl;
	// print(H, 7);


	//DELETING ELEMENTS WILL THE HELP OF LOOP TO GET THE ARRAY OF SORTED ELEMENTS
	// now we will call delete function with the help of loop so  we will get an array with sorted elements.

	for(int i =  7; i > 1 ;i--){
		cout<<"Deleting element : "<<Delete(H,i)<<endl;
	}

	// printing using loop
	print(H, 7);



	return 0;
}