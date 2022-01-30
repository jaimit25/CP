#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	// void swap(int *a, int *b)
	// {
	// 	int temp = *a;
	// 	*a = *b;
	// 	*b = temp;
	// }

	void display(vector<int> v)
	{
		for (auto it : v)
		{
			cout << it << " ";
		}
		cout << endl;
	}

	// void nextPermutation(vector<int> &nums)
	// {
	// 	// for 1 3 5 4 2    we have 1 4 2 3 5
	// 	// step 1  : find a[i] where a[i+1] is greater than a[i] -  so this is index1
	// 	// step 2  : find index where index2 is greater then index1 element from backwards
	// 	// step 3  : swap the element from index1 and index2
	// 	// step 4 : reverse right side of index1 or from index a[index1 + 1] to a.size()-1

	// 	// Time complexity is : O(n) + O(n) + O(n) = O(3n)
	// 	int n = nums.size(), k, l;
	// 	for (k = n - 2; k >= 0; k--)
	// 	{
	// 		if (nums[k + 1] > nums[k])
	// 		{
	// 			break;
	// 		}
	// 	}
	// 	if (k < 0)
	// 	{
	// 		reverse(nums.begin(), nums.end());
	// 	}
	// 	else
	// 	{
	// 		for (l = nums.size() - 1; l > k; l--)
	// 		{
	// 			if (nums[l] > nums[k])
	// 			{
	// 				break;
	// 			}
	// 		}
	// 		swap(nums[k], nums[l]);
	// 	}

	// 	reverse(nums.begin() + k + 1, nums.end());
	// }

	void nextPermutation(vector<int> &nums)
	{
		int i;
		int n = nums.size();
		for (i = n - 1; i > 0; i--)
		{
			if (nums[i - 1] < nums[i])
				break;
		}

		if (i > 0)
		{
			int j;
			for (j = n - 1; j >= 0; j--)
			{
				if (nums[i - 1] < nums[j])
					break;
			}
			swap(nums[i - 1], nums[j]);
		}
		reverse(nums.begin() + i, nums.end());
	}
};

int main()
{

	vector<int> v;

	int sz;
	cin >> sz;

	int temp;
	for (int i = 0; i < sz; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	Solution obj;
	obj.nextPermutation(v);

	return 0;
}