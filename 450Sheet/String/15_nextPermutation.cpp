// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{

public:
	void swap(int *A, int *B)
	{
		int temp = *A;
		*A = *B;
		*B = temp;
	}

	vector<int> nextPermutation(int N, vector<int> arr)
	{
		int i;
		int n = arr.size();
		for (i = n - 1; i > 0; i--)
		{
			if (arr[i - 1] < arr[i])
				break;
		}
		
		if (i > 0)
		{
			int j;
			for (j = n - 1; j >= 0; j--)
			{
				if (arr[i - 1] < arr[j])
					break;
			}
			swap(&arr[i - 1], &arr[j]);
		}
		reverse(arr.begin() + i, arr.end());

		return arr;
	}
};

int main()
{
	vector<int> v;
	int temp;

	int sz;
	cin >> sz;

	for (int i = 0; i < sz; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	Solution obj;
	vector<int> ans = obj.nextPermutation(sz, v);

	for (auto it : ans)
	{
		cout << it << " ";
	}

	cout << endl;

	return 0;
}