#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
	void swap(int *x, int *y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	}

	// complexity o(n2)
	int KthSmallestElement(int arr[], int l, int r, int k)
	{
		for (int i = 0; i < (r + 1) - k + 1; i++)
		{
			for (int j = 0; j < r - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(&arr[j], &arr[j + 1]);
				}
			}
		}

		return arr[k - 1];
	}

	//complexity o(n) using STL
	int kthSmallest(int arr[], int l, int r, int k)
	{

		//priority queue using max heap
		priority_queue<int> q;

		//priority queue using min heap
		// priority_queue<int, vector<int>, greater<int>> pq;

		for (int i = 0; i <= r; i++)
		{
			q.push(-arr[i]); // this will implement
		}
		int j = 1;

		while (j != k)
		{
			q.pop();
			j++;
		}
		return -(q.top());
	}

	void printArray(int *arr, int sz)
	{
		for (int i = 0; i < sz; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{

	int sz = 5;
	// cin>>sz;

	int A[] = {10, 12, 15, 3, 6};
	// int A[sz];

	// for(int  i = 0 ; i < sz ; i++){
	// 	cin>>A[i];
	// }

	int k = 2;
	// cin >> k;

	Solution ob;

	// ob.printArray(A, sz);
	// cout << ob.KthSmallestElement(A, 0, sz - 1, k) << endl;
	cout << ob.kthSmallest(A, 0, sz - 1, k) << endl;
	// ob.printArray(A, sz);

	return 0;
}