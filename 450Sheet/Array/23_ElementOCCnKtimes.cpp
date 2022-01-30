// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

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
	void print_map(unordered_map<int, int> m)
	{
		cout << "Size of map is : " << m.size() << endl;
		for (int i = 0; i < m.size(); i++)
		{
			cout << m[i] << " ";
		}
	}
	vector<int> elementCount(vector<int> v, int n, int k)
	{
		vector<int> ans;
		unordered_map<int, int> m;
		for (int i = 0; i < v.size(); i++)
			m[v[i]]++;

		// print_map(m);
		// cout << " value of n/k is : " << (n / k) << endl;
		for (int i = 0; i < m.size(); i++)
		{
			if (m[i] > (n / k))
			{
				ans.push_back(i);
			}
		}

		return ans;
	}
};

int main()
{

	Solution obj;
	vector<int> v;

	int sz;
	cin >> sz;

	int k;
	cin >> k;

	int temp;
	for (int i = 0; i < sz; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	v = obj.elementCount(v, sz, k);
	for (auto it : v)
	{
		cout << it << " ";
	}
	cout << endl;

	return 0;
}
