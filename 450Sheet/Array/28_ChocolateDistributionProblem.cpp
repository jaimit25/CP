// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include<climits>

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
	long long findMinDiff(vector<long long> a, long long n, long long m)
	{
		sort(a.begin(), a.end());
		for(auto it : a)
			cout<< it<<" ";
		cout<<endl;


		int i = 0;
		int j = i + m - 1;
		long long min_diff = LLONG_MAX;

		while ((i + m - 1) < n)
		{
			min_diff = min(min_diff, a[i + m - 1] - a[i]);
			    i++;
		}
		return min_diff;
	}
};

int main()
{

	Solution obj;
	vector<LL> v;

	long long sz;
	long long m;
	cin >> sz;
	cin>>m;
	long long temp;

	for (int i = 0; i < sz; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	cout << obj.findMinDiff(v , sz , m) << endl;

	return 0;
}