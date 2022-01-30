// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution
{

public:
	bool checkRotation(string a, string b)
	{

		if (a.size() != b.size())
			return false;

		queue<char> q1;
		queue<char> q2;
		for (int i = 0; i < a.size(); i++)
		{
			q1.push(a[i]);
		}
		queue<char> q2;
		for (int i = 0; i < b.size(); i++)
		{
			q2.push(b[i]);
		}
		int k = b.size();

		while (k--)
		{
			char ch = q2.front();
			q2.pop();
			q2.push(ch);
			if (q2 == q1)
				return true;
		}
		return false;
	}
};

int main()
{

	Solution obj;
	string s1;
	string s2;

	int sz;
	cin >> sz;

	int sz1;
	cin >> sz1;

	char temp;
	while (sz)
	{
		cin >> temp;
		s1.push_back(temp);
		sz--;
	}
	while (sz1)
	{
		cin >> temp;
		s2.push_back(temp);
		sz1--;
	}
	cout << obj.checkRotation(s1, s2) << endl;

	return 0;
}