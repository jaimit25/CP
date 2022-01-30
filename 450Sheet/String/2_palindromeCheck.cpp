// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution
{

public:
	int isPalindrome(string S)
	{	
		for (int i = 0, j = S.size() - 1; i < j; i++, j--)
		{
			if (S[i] != S[j])
				return 0;
		}
		return 1;
	}
	void print(vector<char> &s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
	}
	void printString(string s)
	{
		// for(int i = 0 ; i < s.size(); i++){
		for (int i = 0; s[i] != '\0'; i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
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
	cout << obj.isPalindrome(s) << endl;
	// obj.print(v);

	// Solution obj;
	// int sz;
	// cin >> sz;
	// char S[sz];

	// for (int i = 0; i < sz; i++)
	// {
	// 	cin >> S[i];
	// }

	// cout << obj.isPalindrome(S) << endl;
	// obj.printString(S);

	return 0;
}