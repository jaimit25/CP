// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution
{
public:
	void dup(string s)
	{

		int map[255];
		for (int i = 0; i < 255; i++)
		{
			map[i] = 0;
		}
		int i = 0;
		for (i = 0; i < s.size(); i++)
		{
			map[(int)s[i]]++;
		}
		print(map);
	}

	void print(int map[], int sz = 255)
	{
		for (int i = 0; i < sz; i++)
		{
			if (map[i] > 0)
			{
				// cout << "value at " << i << " : " << map[i] << " ";
				cout << (char)i << "";
				// cout << endl;
			}
		}
	}
};

int main()
{

	Solution obj;
	string s;

	int sz;
	cin >> sz;
	char temp = '\0';
	while (sz)
	{
		cin >> temp;
		s.push_back(temp);
		sz--;
	}
	obj.dup(s);

	return 0;
}