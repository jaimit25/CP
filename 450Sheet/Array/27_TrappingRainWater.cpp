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
	void print(int *A, int n)
	{

		for (int i = 0; i < n; i++)
		{
			cout << A[i] << " ";
		}
		cout << endl;
	}

	long long trappingWater(int arr[], int n)
	{

		long long ans = 0;
		int *left = new int[n];
		int *right = new int[n];

		for (int i = 0; i < n; i++)
			left[i] = max(left[i - 1], arr[i]);

		for (int i = n - 1; i >= 0; i--)
			right[i] = max(right[i + 1], arr[i]);

		for (int i = 0; i < n; i++)
			ans += (min(left[i], right[i]) - arr[i]);

		return ans;

		// code here
		// LL ans = 0;
		// int *left = new int[n];
		// int *right = new int[n];

		// int curr_left = 0;
		// int curr_right = 0;

		// // find left wall for every index from left to right
		// for (int i = 0; i < n; i++)
		// {
		// 	left[i] = max(left[i - 1], arr[i]);
		// }

		// // find right wall for every index from right to left
		// for (int i = n - 1; i >= 0; i--)
		// {
		// 	right[i] = max(right[i + 1], arr[i]);
		// }

		// print(left, n);
		// print(right, n);
		// for (int i = 0; i < n; i++)
		// {
		// 	if (right[i] < left[i])
		// 		ans = ans + (right[i] - arr[i]);
		// 	else if (right[i] > left[i])
		// 		ans = ans + (left[i] - arr[i]);

		// 	// ans += (min(left[i], right[i]) - arr[i]);
		// }
		// return ans;

		//      long long int ans=0;

		//   int lmax=0, rmax=0;
		//   int l=0;
		//   int r=n-1;

		//   while(l<r){

		//       if(arr[l]<=arr[r]){

		//           if(arr[l]>lmax){
		//               lmax=arr[l];
		//           }
		//           else{
		//               ans+=lmax-arr[l];
		//               l++;
		//           }
		//       }
		//       else{

		//           if(arr[r]>rmax){
		//               rmax=arr[r];
		//           }
		//           else{
		//               ans+=rmax-arr[r];
		//               r--;
		//           }
		//       }
		//   }
		//   return ans;
	}
};

int main()
{

	Solution obj;

	int sz;
	cin >> sz;

	int *a = new int[sz];
	for (int i = 0; i < sz; i++)
		cin >> a[i];

	cout << obj.trappingWater(a, sz) << endl;
	return 0;
}