// CPP program to find length of the
// longest prefix which is also suffix
#include <bits/stdc++.h>
using namespace std;

void print(int *A, int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";

	cout << endl;
}

int lps(string s)
{
	// Your code goes here
	int ls[s.length()];
	//  = {0};
	ls[0] = 0;
	int i = 1, len = 0;
	while (i < s.length())
	{
		if (s[len] == s[i])
		{
			len++;
			ls[i] = len;
			i++;
		}
		else
		{
			if (len == 0)
			{
				ls[i] = 0;
				i++;
			}
			else
			{
				len = ls[len - 1];
			}
		}
	}
	print(ls, s.length());

	return ls[s.length() - 1];
}

// Driver code
int main()
{

	// string s = "blablabla";
	// string s = "aabcdaabc";
	string s = "abab";

	// Function Call
	cout << lps(s) << endl;
	return 0;
}
