#include <bits/stdc++.h>
#include <sys/_types/_int32_t.h>
#define ll long long int
#define int long long int
#define push_back pb
#define F first
#define S second
using namespace std;

// Memoization
int32_t fibo(int n, vector<int32_t> &dp) {

  if (n <= 1)
    return n;
  if (dp[n] != -1)
    return dp[n];
  return (dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp));
}

// Tabulation 
void fibon(int n) {
  int32_t prev = 1;
  int32_t prev2 = 0;
  int curr;
  for (int i = 2; i <= n; i++) {
    curr = prev2 + prev;
    prev2 = prev;
    prev = curr;
  }
  cout << curr << endl;
}

// we cannot use int as we have deifined int as long long int
// so other way of denoting int is int32_t
int32_t main() {

  int32_t n;
  cin >> n;

  //   int32_t *dp = new int32_t[n];
  //   memset(dp, -1, sizeof(dp)); //copy all element as -1 in dp array

  vector<int32_t> dp(n + 1, -1);
  cout << fibo(n, dp) << endl;

  return 0;
}
