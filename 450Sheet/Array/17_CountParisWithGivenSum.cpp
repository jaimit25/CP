#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
class Solution
{

public:
	// int getPairsCount(int arr[], int n, int k)
	// {
	// 	int ans = 0;
	// 	int i = 0, j = 0;
	// 	for (i = 0; i < n; i++)
	// 	{
	// 		for (j = i + 1; j < n; j++)
	// 		{
	// 			if (arr[i] + arr[j] == k)
	// 			{
	// 				// cout << "Pair : " << arr[i] << " " << arr[j] << " "<<endl;
	// 				ans++;
	// 			}
	// 		}
	// 	}

	// 	return ans;
	// }

	int getPairsCount(int arr[], int n, int k)
	{
		// int ans = 0;
		// int maxm = INT32_MIN;
		// int i = 0;
		// for (i = 0; i < n; i++)
		// 	maxm = max(maxm, arr[i]);
		// int *h = new int[maxm + 1];

		// for (i = 0; i < n; i++)
		// {
		// 	h[arr[i]]++;
		// }
		// // print(h, maxm + 1);
		// // cout << endl;
		// for (i = 0; i < n; i++)
		// {
		// 	if ((k - arr[i]) >= 0)
		// 	{
		// 		if (h[k - arr[i]] == 1)
		// 		{
		// 			ans++;
		// 			h[k - arr[i]]++;
		// 			// print(h, maxm + 1);
		// 			// cout << "k - arr[i] : " << k - arr[i];
		// 			// cout << endl;
		// 		}
		// 	}
		// }

		// return ans;

		unordered_map<int, int> m;

		// Store counts of all elements in map m to store how many times elemet is repeated
		for (int i = 0; i < n; i++)
			m[arr[i]]++;

		int twice_count = 0;

		// iterate through each element and increment the
		// count (Notice that every pair is counted twice)
		for (int i = 0; i < n; i++)
		{
			twice_count += m[k - arr[i]];
			
			//EDGE CASE
			// if we are considering element whose k - arr[i] is itself considered in frequency then we will subract the frequency
			if (k - arr[i] == arr[i])
				twice_count--;
		}

		// return the half of twice_count so that we can remove the paired element who are again pairing back
		return twice_count / 2;
	}

	void print(int arr[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	int sz;
	cin >> sz;

	int k;
	cin >> k;

	int *arr = new int[sz];

	for (int i = 0; i < sz; i++)
	{
		cin >> arr[i];
	}
	Solution obj;
	cout << obj.getPairsCount(arr, sz, k) << endl;

	return 0;
}