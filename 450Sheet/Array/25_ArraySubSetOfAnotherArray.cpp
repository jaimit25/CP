// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

// typedef long long LL;
// typedef pair<int, int> pii;
// typedef pair<LL, LL> pll;
// typedef pair<string, string> pss;
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef vector<pii> vii;
// typedef vector<LL> vl;
// typedef vector<vl> vvl;

// #define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
// #define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
// #define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
// #define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
// #define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
// #define FOREACH(a, b) for (auto &(a) : (b))
// #define REP(i, n) FOR(i, 0, n)
// #define REPN(i, n) FORN(i, 1, n)
// #define MAX(a, b) a = max(a, b)
// #define MIN(a, b) a = min(a, b)
// #define SQR(x) ((LL)(x) * (x))
// #define RESET(a, b) memset(a, b, sizeof(a))
// #define fi first
// #define se second
// #define mp make_pair
// #define pb push_back
// #define ALL(v) v.begin(), v.end()
// #define ALLA(arr, sz) arr, arr + sz
// #define SIZE(v) (int)v.size()
// #define SORT(v) sort(ALL(v))
// #define REVERSE(v) reverse(ALL(v))
// #define SORTA(arr, sz) sort(ALLA(arr, sz))
// #define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
// #define PERMUTE next_permutation
#define TC(t) while (t--)

using namespace std;

class Solution
{

public:
	string isSubset(int a1[], int a2[], int n, int m)
	{

		int maxm = 0;
		for (int i = 0; i < n; i++)
			maxm = max(a1[i], maxm);
		int *map = new int[maxm+1];

		// unordered_map<int, int> m;

		for (int i = 0; i < n; i++)
		{
			int k = a1[i];
			map[a1[i]]++;

		}

		for (int i = 0; i < m; i++)
		{
			// m[v[i]]++;
			if (map[a2[i]] <= 0)
				return "No";
		}

		return "Yes";
	}
};

int main()
{

	int n, m;

	cin >> n;
	cin >> m;

	int *arr1 = new int[n];
	int *arr2 = new int[m];

	for (int i = 0; i < n; i++)
		cin >> arr1[i];

	for (int i = 0; i < m; i++)
		cin >> arr2[i];
	Solution obj;

	
	cout << obj.isSubset(arr1, arr2, n, m) << endl;

	return 0;
}