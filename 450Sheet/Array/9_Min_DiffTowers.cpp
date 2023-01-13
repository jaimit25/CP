#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
	void printArray(int *A, int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << A[i] << " ";
		}
		cout << endl;
	}

	int getMinDiff(int *arr, int n, int k)
	{
		// which pair in the array will give you the minimise maximum difference between them
		// so we sort the array because pair ..meaning next to next element will give you better minimise maximum difference.
		// ie..  3 9 6 12 20 will give maximum diff as 20-3 = 17 ,Also array is sorted so this is the maximum difference but if k = 3 then (3+3= 6 and 20+3 = 23) and 17-0=17 or 23 - 6 = 17 ...there can be many diff ideas
		// this is the maximum diff between first and last ..but we want to minimise the maximum difference so 3+3 = 6 and 9-3 = 6 and 6-6 = 0 so this is the best possible minmize maximum difference we can get if Array is sorted then
		 sort(arr, arr + n);
		int smallest = arr[0] + k;
		int  largest = arr[n - 1] - k;
		int ans = arr[n - 1] - arr[0];
		int mi, ma;

		for (int i = 0; i < n - 1; i++)
		{
			ma = max(largest, arr[i] + k);
			mi = min(smallest, arr[i + 1] - k);
			if (mi < 0) // if rigth pair element is greater then the diff btwn rigth adn left pair is negative
				{
					continue;
				}
			ans = min(ans, ma - mi);
		}
		return ans;
	}
};

int main()
{

	Solution obj;
	int k, n;
	cin >> k;
	cin >> n;
	int *A = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	cout << obj.getMinDiff(A, n, k) << endl;

	return 0;
}
