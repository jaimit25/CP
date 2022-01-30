// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <climits>

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)

using namespace std;

class Solution
{

public:
	int minSwap(int arr[], int n, int k)
	{
		// Complet the function
		// int i = 0, j = 0;
		// int count = 0;

		// while (i < n && j < n)
		// {
		// 	if (arr[i] < k)
		// 	{
		// 		i++;
		// 		j++;
		// 		// cout<<"i and j incremented"<<endl;
		// 		// cout<<"arr[i] and arr[j] value : "<<arr[i]<<" "<<arr[j]<<endl;
		// 	}
		// 	if (arr[i] > k)
		// 	{
		// 		j++;
		// 		// cout<<"j incremented"<<endl;
		// 	}
		// 	if (arr[j] <= k && arr[i] > k)
		// 	{
		// 		swap(arr[i], arr[j]);
		// 		i++;
		// 		j++;
		// 		count++;
		// 	}
		// 	// cout << " i : " << i << endl;
		// 	// cout << " j : " << j << endl;
		// 	// cout<<endl;
		// }

		int j = n - 1;
		int i = 0;
		int count = 0;
		// 2 1 5 6 3
		//

		while (i < j)
		{
			while (i < j && arr[j] > k)
				j--;

			if (j < 0 || i >= n || j <= i)
				break;

			while (i < j && arr[i] <= k)
				i++;

			if (j < 0 || i >= n || j <= i)
				break;

			swap(arr[i], arr[j]);
			count++;
		}

		return count;
	}
};

int main()
{

	Solution obj;

	int sz;
	cin >> sz;

	int k;
	cin >> k;

	int *A = new int[sz];
	for (int i = 0; i < sz; i++)
	{
		cin >> A[i];
	}
	cout << obj.minSwap(A, sz, k) << endl;

	return 0;
}