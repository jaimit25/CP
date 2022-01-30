#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
	bool rearrangeChar(string str)
	{

		unordered_map<char, int> map;
		int n = str.length();

		for (int i = 0; i < n; i++)
			map[str[i]]++;

		unordered_map<char, int>::iterator itr;
		for (itr = map.begin(); itr != map.end(); itr++)
		{
			cout << itr->first << "  " << itr->second << endl;
			if ((itr->second) > ((n + 1) / 2))
				return 0;
		}

		return 1;
	}
};

int main()
{

	// int t;
	// cin >> t;
	// while (t > 0)
	// {
	string str;
	cin >> str;
	Solution ob;
	cout << ob.rearrangeChar(str) << endl;
	// 	t--;
	// }

	return 0;
}