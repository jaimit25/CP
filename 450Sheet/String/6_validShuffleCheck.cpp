// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution
{

public:
	void print(int *A, int n = 256)
	{
		for (int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << endl;
	}

	// Space - O(255)
	// Time -  O(m+n+l) = O(N)
	//  bool checkShuffle(string a, string b, string shuffle)
	//  {
	//  	int map[255];
	//  	for (int i = 0; i < 255; i++)
	//  		map[i] = 0;

	// 	int m = a.size();
	// 	int n = b.size();
	// 	int l = shuffle.size();

	// 	if ((m + n) != l)
	// 		return false;

	// 	for (int i = 0; i < l; i++)
	// 		map[(int)shuffle[i]]++;

	// 	print(map);

	// 	for (int i = 0; i < m; i++)
	// 		map[(int)a[i]]--;

	// 	for (int i = 0; i < n; i++)
	// 		map[(int)b[i]]--;

	// 	print(map);

	// 	for (int i = 0; i < 255; i++)
	// 	{
	// 		if (map[i] != 0)
	// 			return false;
	// 	}

	// 	return true;
	// }

	// Space - O(1)
	// Time - O(NLogN)
	bool checkShuffle(string a, string b, string shuffle)
	{

		int m = a.size();
		int n = b.size();
		int l = shuffle.size();

		if ((m + n) != l)
			return false;

		sort(shuffle.begin(), shuffle.end());
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		cout << "Sorted string a is  :" << a << endl;
		cout << "Sorted string b is  :" << b << endl;
		cout << "Sorted string a is  :" << shuffle << endl;

		string check = a + b;
		cout << "value stored in check string is  :" << check << endl;

		if (check == shuffle)
			return true;
		else
		{
			check = b + a;
			if (check == shuffle)
				return true;
			else
				return false;
		}

		return false;
	}
};

int main()
{

	Solution obj;

	string s1;
	string s2;
	string s3;

	int sz;
	cin >> sz;

	int sz1;
	cin >> sz1;

	int sz2;
	cin >> sz2;

	char temp;
	while (sz)
	{
		cin >> temp;
		s1.push_back(temp);
		sz--;
	}
	while (sz1)
	{
		cin >> temp;
		s2.push_back(temp);
		sz1--;
	}
	while (sz2)
	{
		cin >> temp;
		s3.push_back(temp);
		sz2--;
	}
	cout << obj.checkShuffle(s1, s2, s3) << endl;

	return 0;
}
