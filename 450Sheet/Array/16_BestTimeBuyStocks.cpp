#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
	int maxProfit(vector<int> &prices)
	{
		int minm = INT32_MAX;
		int maxPro = 0;
		for (auto it : prices)
		{
			minm = min(it, minm);
			maxPro = max(maxPro, it - minm);
		}

		return (maxPro);
	}
};

int main()
{

	Solution obj;
	vector<int> v;

	int size;
	cin >> size;
	int temp;

	for (int i = 0; i < size; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	cout << obj.maxProfit(v) << endl;

	return 0;
}