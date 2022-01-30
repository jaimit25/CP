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
	int minLengthSubArray(int *arr, int n, int x)
	{

		int min_length = n + 1;

		int start = 0;
		int end = 0;
		int sum = 0;

		while (end < n)
		{
			// adding element into sum variable until we have sum value greater than x
			while (sum <= x && end < n)
			{
				sum = sum + arr[end];
				end++;
			}

			// we run this loop when value of sum is greater than x value
			while (sum > x && start < n)
			{
				if (min_length > end - start)
				{
					min_length = end - start + 1;
				}
				sum = sum - arr[start];
				start++;
			}
		}

		return min_length;
	}
};

int main()
{
	Solution obj;

	int sz;
	cin >> sz;

	int x;
	cin >> x;

	int *A = new int[sz];
	for (int i = 0; i < sz; i++)
		cin >> A[i];

	// cout << "checking sum Subarray return's : " << obj.sumSubArray(A, sz, x) << endl;
	cout << obj.minLengthSubArray(A, sz, x) << endl;
}