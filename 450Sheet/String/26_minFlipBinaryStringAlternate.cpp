// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

int minFlips(string S)
{
	int case1 = 0;
	int case2 = 0;

	int n = S.size();

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0 && S[i] == '1')
			case1++;
		if (i % 2 == 1 && S[i] == '0')
			case1++;

		if (i % 2 == 1 && S[i] == '1')
			case2++;
		if (i % 2 == 0 && S[i] == '0')
			case2++;
	}

	return min(case1, case2);
}

int main()
{
	string str;
	cin>>str;

	cout<< minFlips(str)<<endl;

	return 0;
}