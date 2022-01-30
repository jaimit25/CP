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
	int search(vector<int> &nums, int target)
	{

		int l = 0;
		int h = nums.size() - 1;
		int idx;

		while (l <= h)
		{
			int mid = (l + h) >> 1;
			if (nums[mid] == target)
				return mid;

			if (nums[l] <= nums[mid])
			{
				// left half is sorted
				if (target >= nums[l] && target <= nums[mid])
				{
					// checking if element lie in that range
					h = mid - 1;
				}
				else
				{
					// element does not lie in that range
					l = mid + 1;
				}
			}
			else
			{
				// left half is not sorted
				if (target >= nums[mid] && target <= nums[h])
				{
					l = mid + 1;
				}
				else
				{
					h = mid - 1;
				}
			}
		}
		return -1;

	}
};

int main()
{

	Solution obj;
	vector<int> v;

	int sz;
	cin >> sz;
	int target;
	cin >> target;
	int temp;
	for (int i = 0; i < sz; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	cout << obj.search(v, target) << endl;

	return 0;
}