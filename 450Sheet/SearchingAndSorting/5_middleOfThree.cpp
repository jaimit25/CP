#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution
{
public:
	int middle(int A, int B, int C)
	{
		if (A < B && A < C)
		{
			if (B > C)
				return C;
			else
				return B;
		}
		else if (B < A && B < C)
		{
			if (A > C)
				return C;
			else
				return A;
		}
		else if (C < A && C < B)
		{
			if (A > B)
				return B;
			else
				return A;
		}
	}
};

int main()
{

	int A, B, C;
	cin >> A >> B >> C;
	Solution ob;
	cout << ob.middle(A, B, C) << "\n";

	return 0;
}