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
	void print(string s)
	{
		cout << s << endl;
	}
	string countAndSay(int n)
	{
		if (n == 1)
			return "1";
		if (n == 2)
			return "11";

		string s = "11";
		for (int i = 2; i < n; i++)
		{
			string t = "";
			s = s + '&';
			int c = 1;

			for (int j = 1; j < s.length(); j++)
			{
				if (s[j] != s[j - 1])
				{
					t = t + to_string(c);
					t = t + s[j - 1];
					c = 1;
				}
				else
					c++;
			}
			s = t;
		}
		return s;
	}
};

int main()
{

	Solution obj;
	// string s;
	// int sz;
	// cin >> sz;
	// char temp;
	// while (sz != 0)
	// {
	// 	cin >> temp;
	// 	s.push_back(temp);
	// 	sz--;
	// }
	int num;
	cin >> num;
	cout << obj.countAndSay(num) << " " << endl;
	return 0;
}