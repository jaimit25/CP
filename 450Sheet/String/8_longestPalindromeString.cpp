// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	string f;
	bool isPalindrome(string s, int st, int en)
	{
		if (en > (s.length() - 1))
			en = s.length() - 1;
		while (st <= en)
		{
			if (s[st] != s[en])
				return false;
			st++;
			en--;
		}
		return true;
	}
	int len(string s, int st, int en)
	{

		if (st > en)
			return 0;
		int i = st;
		int j = en;
		if (st == en)
			return 1;

		if (en > (s.length() - 1))
			en = s.length() - 1;

		// if (!isPalindrome(s, st, en))
		// {
		// 	return -1;
		// }
		// cout << "(en - st) + 1 = (" << (j) << " - " << (i) << " "
		//      << " + 1 )"
		//      << " = ";
		return (j - i) + 1;
	}
	string getString(string s, int st, int en)
	{
		string str;
		// if (st == en)
		// 	return to_string(s[st]);

		// if (en > (s.length() - 1))
		// 	en = s.length() - 1;

		if (!isPalindrome(s, st, en))
		{
			return "";
		}
		while (st <= en)
		{
			str.push_back(s[st]);
			st++;
		}

		return str;
	}

	// string longestPalin(string S)
	// {
	// 	// string val = to_string(S.front());
	// 	f = S[0];
	// 	int n = S.length();
	// 	string ans = to_string(S.front());
	// 	int curr = 0;
	// 	int maxlen = 0;
	// 	for (int i = 0; i < n; i++)
	// 	{
	// 		for (int j = i; j < n; j++)
	// 		{
	// 			if (isPalindrome(S, i, j))
	// 			{
	// 				curr = len(S, i, j);
	// 				if (curr >= maxlen)
	// 				{
	// 					ans = getString(S, i, j);
	// 				}
	// 				maxlen = max(maxlen, curr);
	// 			}
	// 		}
	// 	}
	// 	if (ans.length() == 0)
	// 		return f;
	// 	else
	// 		return ans;
	// }

	string chartostring(char x)
	{
		string s(1, x);
		return s;
	}

	int expandFromMiddle(string s, int left, int right)
	{

		// example
		//  LR -let at index 1 and right at index 2
		// abba
		//  12

		// from middle we will go to left and right until left and right elements are having equal value
		if (left > right)
			return 0;
		while (left >= 0 && right < s.length() && s[left] == s[right])
		{
			left--;
			right++;
		}
		return right - left - 1;
	}

	// Optimized - go to middle and check and left right
	string longestPalin(string S)
	{
		if (S.length() < 1)
			return "";
		int start = 0;
		int end = 0;

		for (int i = 0; i < S.length(); i++)
		{
			// two cases we have to handle odd and even elements case
			// racecar
			// abba

			int len1 = expandFromMiddle(S, i, i);	  // ie racecar
			int len2 = expandFromMiddle(S, i, i + 1); // ie abba
			int maxm = max(len1, len2);
			if (maxm > end - start)
			{
				start = i - ((maxm - 1)) / 2;
				end = i + (maxm / 2);
			}
		}

		return S.substr(start, end + 1);
	}
};

int main()
{

	string S;
	cin >> S;

	Solution ob;
	cout << ob.longestPalin(S) << endl;
	// cout << "substring (S, 0, 7) is  : " << ob.isPalindrome(S, 0, 7) << " and length is : " << ob.len(S, 0, 7) << " and substring is : " << ob.getString(S, 0, 7) << endl;
	// cout << "substring (S, 2, 7) is  : " << ob.isPalindrome(S, 2, 7) << " and length is : " << ob.len(S, 2, 7) << " and substring is : " << ob.getString(S, 2, 7) << endl;
	// cout << "substring (S, 4, 5) is  : " << ob.isPalindrome(S, 4, 5) << " and length is : " << ob.len(S, 4, 5) << " and substring is : " << ob.getString(S, 4, 5) << endl;
	// cout << "substring (S, 0, 0) is  : " << ob.isPalindrome(S, 0, 0) << " and length is : " << ob.len(S, 0, 0) << " and substring is : " << ob.getString(S, 0, 0) << endl;
	// cout << "substring (S, 3, 6) is  : " << ob.isPalindrome(S, 3, 6) << " and length is : " << ob.len(S, 3, 6) << " and substring is : " << ob.getString(S, 3, 6) << endl;
	// cout << "substring (S, 6, 7) is  : " << ob.isPalindrome(S, 6, 7) << " and length is : " << ob.len(S, 6, 7) << " and substring is : " << ob.getString(S, 6, 7) << endl;

	return 0;
}