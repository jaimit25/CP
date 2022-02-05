#include <iostream>
#define SIZE 10

using namespace std;

template <class T>
void Print(T &vec, int n, string s)
{
	for (int i = 0; i < n; i++)
	{
		cout << vec[i] << " ";
		}
}

int Hash(int key)
{
	return key % SIZE;
}


// this function will find out next free space
int LinearProbe(int H[], int key)
{
	int idx = Hash(key);
	int i = 0;
	while (H[(idx + i) % SIZE] != 0)
	{
		i++;
	}
	return (idx + i) % SIZE;
}

void Insert(int H[], int key)
{
	int idx = Hash(key);

	//checking if space is full or not
	if (H[idx] != 0)
	{
		//we need new space because value is not 0 means there is an element
		idx = LinearProbe(H, key);
	}
	H[idx] = key;
}

int Search(int H[], int key)
{
	int idx = Hash(key);
	int i = 0;
	while (H[(idx + i) % SIZE] != key)
	{
		i++;
		if (H[(idx + i) % SIZE] == 0)
		{
			return -1;
		}
	}
	return (idx + i) % SIZE;
}

int main()
{

	int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
	int n = sizeof(A) / sizeof(A[0]);
	Print(A, n, " A");

	// Hash Table
	//initializing all values with 0
	int HT[10] = {0};
	for (int i = 0; i < n; i++)
	{
		Insert(HT, A[i]);
	}
	Print(HT, SIZE, "HT");

	int index = Search(HT, 25);
	cout << "key found at: " << index << endl;

	index = Search(HT, 35);
	cout << "key found at: " << index << endl;

	return 0;
}