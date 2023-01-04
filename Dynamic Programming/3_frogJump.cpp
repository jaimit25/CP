#include <bits/stdc++.h>
using namespace std;

// DP using Memoization
int helper(int i, vector<int> H, vector<int> &dp) {
  if (i == 0)
    return 0;
  if (dp[i] != -1)
    return dp[i];

  int take_one_step = helper(i - 1, H, dp) + abs(H[i] - H[i - 1]);
  int take_two_step = INT_MAX;
  if (i > 1) {
    take_two_step = helper(i - 2, H, dp) + abs(H[i] - H[i - 2]);
  }

  return dp[i] = min(take_one_step, take_two_step);
}


int frogJump(int n, vector<int> &heights) {
  vector<int> dp(n + 1, -1);
  return helper(n - 1, heights, dp);
}

// Using Tabulation
// int frogJump(int n, vector<int> &H) {
//   vector<int> dp(n, 0);
//   for (int i = 1; i < n; i++) {
//     int fs = dp[i - 1] + abs(H[i] - H[i - 1]);
//     int ss = INT_MAX;
//     if (i > 1) {
//       ss = dp[i - 2] + abs(H[i] - H[i - 2]);
//     }
//     dp[i] = min(fs, ss);
//   }
//   return dp[n - 1];
// }

int main() {

  vector<int> H = {10, 20, 30, 10};
  cout << frogJump(4, H) << endl;

  return 0;
}