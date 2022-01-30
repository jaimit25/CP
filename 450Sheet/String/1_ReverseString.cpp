// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution
{
public:
	void reverseString(vector<char> &s)
	{
		reverse(s.begin(), s.end());
	}
	void print(vector<char> &s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
	}
};

int main()
{

	Solution obj;
	vector<char> v;

	int sz;
	cin >> sz;
	char temp = '\0';
	while (sz)
	{
		cin >> temp;
		v.push_back(temp);
		sz--;
	}
	obj.reverseString(v);
	obj.print(v);

	return 0;
}