// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
	vector<vector<int> > sortedMatrix(int N, vector<vector<int> > Mat)
	{
		vector<vector<int> > ans;
		vector<int> vec;

		for (auto v : Mat)
		{
			for (auto it : v)
			{
				vec.push_back(it);
			}
		}
		sort(vec.begin(), vec.end());
		vector<int> temp;
		int start = 0;
		int end = (vec.size() / N) - 1;
		for (int i = 0; i < N; i++)
		{
			for (int k = start; k <= end; k++)
			{
				temp.push_back(vec[k]);
			}

			start = end + 1;
			end = start + (N - 1);

			ans.push_back(temp);
			temp.clear();
		}

		return ans;
	}
};

// 4
// 10 20 30 40
// 15 25 35 45
// 27 29 37 48
// 32 33 39 50

int main()
{

	int N;
	cin >> N;
	vector<vector<int> > v(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> v[i][j];
	Solution ob;
	v = ob.sortedMatrix(N, v);
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << v[i][j] << " ";
		cout << "\n";
	}
}