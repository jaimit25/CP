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
	// bool ispar(string x)
	// {
	// 	if (x.size() <= 1)
	// 		return false;

	// 	if (x.size() % 2 == 1)
	// 	{
	// 		return false;
	// 	}

	// 	int n = x.size();

	// 	for (int i = 0, j = n - 1; i <= j; i++, j--)
	// 	{
	// 		switch (x[i])
	// 		{
	// 		case '(':
	// 			if (x[j] != ')')
	// 				return false;
	// 			break;
	// 		case '[':
	// 			if (x[j] != ']')
	// 				return false;
	// 			break;
	// 		case '{':
	// 			if (x[j] != '}')
	// 				return false;
	// 			break;
	// 		default:
	// 			return false;
	// 		}
	// 	}
	// 	return true;
	// }

	bool ispar(string x)
	{

		// stack<char> stck;
		// char top;

		// for (int i = 0; i < x.size(); i++)
		// {
		// 	if (x[i] == '(' || x[i] == '[' || x[i] == '{')
		// 	{
		// 		stck.push(x[i]);
		// 	}
		// 	else
		// 	{
		// 		top = stck.top();
		// 		switch (x[i])
		// 		{
		// 		case ']':
		// 			if (top == '[')
		// 				stck.pop();
		// 			else
		// 				return false;
		// 			break;
		// 		case ')':
		// 			if (top == '(')
		// 				stck.pop();
		// 			else
		// 				return false;
		// 			break;
		// 		case '}':
		// 			if (top == '{')
		// 				stck.pop();
		// 			else
		// 				return false;
		// 			break;
		// 		}
		// 	}
		// }

		// if (stck.empty())
		// {
		// 	return true;
		// }
		// return false;

		stack<char> stck;
		char val;

		// Traversing the Expression
		for (int i = 0; i < x.length(); i++)
		{
			if (x[i] == '(' || x[i] == '[' || x[i] == '{')
			{
				// Push the element in the stack
				stck.push(x[i]);
				continue;
			}

			// IF current current character is not opening
			// bracket, then it must be closing. So stack
			// cannot be empty at this point.
			if (stck.empty())
				return false;

			switch (x[i])
			{
			case ')':

				// Store the top element in a
				val = stck.top();
				stck.pop();
				if (val == '{' || val == '[')
					return false;
				break;

			case '}':

				// Store the top element in b
				val = stck.top();
				stck.pop();
				if (val == '(' || val == '[')
					return false;
				break;

			case ']':

				// Store the top element in c
				val = stck.top();
				stck.pop();
				if (val == '(' || val == '{')
					return false;
				break;
			}
		}

		// Check Empty Stack
		return (stck.empty());
	}
};

int main()
{

	string s;
	Solution obj;
	cin >> s;

	cout << obj.ispar(s) << endl;

	return 0;
}