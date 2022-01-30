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
	// int median(vector<vector<int> > &matrix, int r, int c)
	// {
	// 	vector<int> ans;
	// 	for (auto v : matrix)
	// 		for (auto it : v)
	// 			ans.push_back(it);

	// 	sort(ans.begin(), ans.end());

	// 	int hlf_size = ans.size() / 2;
	// 	if (ans.size() / 2 == 0)
	// 		return (ans[hlf_size] + ans[hlf_size + 1]);
	// 	else
	// 		return (ans[hlf_size]);
	// }

};

int main()
{
	int r, c;
	cin >> r >> c;
	vector<vector<int>> matrix(r, vector<int>(c));
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> matrix[i][j];

	Solution obj;
	cout << obj.median(matrix, r, c) << endl;
	return 0;
}