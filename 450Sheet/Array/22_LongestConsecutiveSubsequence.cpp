// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
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
	void print(int *a, int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}

	int findLongestConseqSubseq(int arr[], int N)
	{
		// Your code here
		int ans;

		int maxm = arr[0];

		int i = 0;
		for (i = 0; i < N; i++)
			maxm = max(maxm, arr[i]);

		int *m = new int[maxm + 1];
		for (i = 0; i < N; i++)
			m[arr[i]] = 1;

		// print(m, maxm + 1);

		ans = 0;
		int curr = 0;
		for (int j = 0; j < maxm + 1; j++)
		{
			if (m[j] == 0)
				curr = 0;
			else
			{
				curr++;
				ans = max(curr, ans);
				// if(curr > ans )
				// 	ans = curr;
			}
		}

		return ans;
	}
};

int main()
{

	Solution obj;

	int sz;
	cin >> sz;
	int *arr = new int[sz];

	int temp;
	for (int i = 0; i < sz; i++)
		cin >> arr[i];

	cout << obj.findLongestConseqSubseq(arr, sz) << endl;

	return 0;
}

// 6
// 2 6 1 9 4 3

// 7
// 1 9 3 10 4 20 2

