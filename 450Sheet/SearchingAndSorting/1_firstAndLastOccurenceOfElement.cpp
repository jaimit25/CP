// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> find(int arr[], int n, int x)
{
	int first = -1;
	int last = -1;
	bool check_first = true;
	vector<int> result;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			if (check_first)
			{
				first = i;
				check_first = false;
			}

			last = i;
		}
	}

	result.push_back(first);
	result.push_back(last);

	return result;
}

int main()
{

	int n, x;
	cin >> n >> x;
	int arr[n], i;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	vector<int> ans;
	ans = find(arr, n, x);
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}