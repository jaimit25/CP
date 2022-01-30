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
	int count(string s)
	{
		int count0 = 0, count1 = 0;
		int count = 0;
		int i = 0;
		int sz = s.size();
		while (i < sz)
		{
			if (s[i] == '0')
			{
				count0++;
			}
			else if (s[i] == '1')
			{
				count1++;
			}
			if (count0 == count1)
			{
				count++;
				count0 = 0;
				count1 = 0;
			}
			i++;
		}

		if (count1 != count0)
		{
			return -1;
		}

		return count;
	}
};

int main()
{

	string s;
	cin >> s;

	Solution obj;

	cout<<obj.count(s)<<endl;

	// string str = "0100110101";
	// int n = str.length();
	// Solution obj;
	// cout<<obj.count(str)<<endl;

	return 0;
}