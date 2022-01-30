// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
// Approach : https://www.youtube.com/watch?v=dTBpH9YT2HQ
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

int countRev(string s)
{

	int n = s.length();
	double open = 0;
	double close = 0;

	if (n % 2 != 0)
		return -1;

	for (auto it : s)
	{
		if (it == '{')
		{
			open++;
		}
		else
		{
			// else if (s[i] == '}')
			if (open == 0)
				close++;
			else
				open--;
		}
	}
	cout << " open : " << open << endl;
	cout << " close : " << close << endl;
	int rev = llround(open / 2) + llround(close / 2);
	return rev;

	// int n = s.length();
	// int count = 0;

	// cout<<" n value is  : "<<n<<endl;
	// if (n % 2 != 0)
	// 	return -1;

	// for (int i = 0; i < n; i++)
	// {
	// 	if (s[i] == '{')
	// 		count++;
	// }
	// if((n - count)  > count ){
	// 	return count;
	// }

	// return (n - count);
}

int main()
{

	string s;
	cin >> s;
	cout << countRev(s) << endl;
	return 0;
}