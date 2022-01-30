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
	int charAddedPalindrome(string str)
	{
		int ans = 0;
		int n = str.length();
		int j = n - 1;
		int i = 0;

		while (j != i)
		{
			if (str[i] == str[j])
				i++;
			else
				ans++;
			j--;
		}

		return ans;
	}
};

int main()
{

	string str;
	cin>>str;
	Solution obj;
	cout << obj.charAddedPalindrome(str) << endl;

	return 0;

}