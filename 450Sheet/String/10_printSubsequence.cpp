// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int subsequence(string val, string *output)
{

	if (val.size() == 0)
	{
		output[0] = " ";
		return 1;
	}

	int outputsize = subsequence(val.substr(1), output);
	for (int i = 0; i < outputsize; i++)
	{
		output[i + outputsize] = val[0] + output[i];
	}

	return 2 * outputsize;
}

// loop variation
void getSubseq(string val)
{
	string output[1000];

	int n = val.size() - 1;
	int s = 0;

	output[0] = " ";
	output[1] = val[val.size() - 1];
	int outputsize = 2;

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < outputsize; j++)
		{
			output[outputsize + i] = output[j] + output[i];
		}
	}
	
	cout << endl;

}

int main()
{
	string output[1000];
	string value;
	cin >> value;

	// int size = subsequence(value, output);
	// for (int i = 0; i < size; i++)
	// {
	// 	cout << output[i] << endl;
	// }
	//
	// int size = subsequence(value, output);
	getSubseq(value);

	return 0;
}