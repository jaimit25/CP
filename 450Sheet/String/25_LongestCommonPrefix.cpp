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
	// flower   flows
	string longestCommonPrefix(vector<string> &strs)
	{
		int n = strs.size();
		if (strs.size() == 0)
			return "";
		if (strs.size() == 1)
			return strs[0];

		string prefix = strs[0];

		for (int i = 1; i < n; i++)
		{
			while (strs[i].find(prefix) != 0)
			{
				prefix = prefix.substr(0, prefix.size() - 1);
			}
		}

		return prefix;
	}
};

int main()
{

	return 0;
}