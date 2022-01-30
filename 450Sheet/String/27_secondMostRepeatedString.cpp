// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
	string secFrequent(string arr[], int n)
	{
		unordered_map<string, int> mp;
		for (int i = 0; i < n; i++)
			mp[arr[i]]++;

		priority_queue<pair<int, string>> pq;
		for (auto pr : mp)
			pq.push({pr.second, pr.first});

		pq.pop();
		return pq.top().second;
	}
};

int main()
{

	int n;
	cin >> n;
	string arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	Solution ob;
	cout << ob.secFrequent(arr, n) << endl;
}
