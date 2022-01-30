#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class SubArray
{

public:
	// ie {-1 , 4 , 7 , 2}

	// All sub Array are :
	//  -1
	//  -1 , 4
	//  -1 , 4 , 7
	//  -1 , 4 , 7 , 2
	//   4
	//   4 , 7
	//   4 , 7 , 2
	//   7
	//   7 , 2
	//   2

	// o(n2) -
	int sub(int *A, int n)
	{

		int i = 0, j = 0;
		int sum = A[0];
		int max = -123;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				sum = 0;
				for (int k = i; k <= j; k++)
				{
					// cout << A[k] << " ";
					sum = sum + A[k];
				}
				if (sum > max)
					max = sum;
			}
		}
		return max;
	}

	// o(n) - Kadanes Algorithm
	int subK(int *A, int n)
	{
		int max = 0, sum = 0;
		int i = 0, j = 0;
		for (i = 0; i < n; i++)
		{
			if (sum < 0)
				sum = 0;
			sum = sum + A[i];
			if (max < sum)
				max = sum;
		}

		return max;
	}
};

int main()
{
	int sz;
	cin >> sz;

	int *A = new int[sz];

	for (int i = 0; i < sz; i++)
	{
		cin >> A[i];
	}

	SubArray obj;
	cout << "Maximum Sum is  from O(n3): " << obj.sub(A, sz) << endl;
	cout << "Maximum Sum(Kadane's Algorithm) is  from O(n) : " << obj.subK(A, sz) << endl;

	return 0;
}