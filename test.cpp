#include <bits/stdc++.h>
#include <string>
#define v2 vector<vector<int>>
using namespace std;

void printv(vector<int> v) {
  for (auto it : v) {
    cout << it << " ";
  }
  cout << endl;
}

void print2v(vector<vector<int>> v) {
  for (auto it : v) {
    for (auto it2 : it) {
      cout << it2 << " ";
    }
    cout << endl;
  }
  cout << "____________________" << endl;
}

int f(int day, int last, v2 &task, v2 &dp) {

  // base case
  // if (day == -1)
  //   return 0;

  if (day == 0) {
    int maxm = 0;
    for (int i = 0; i < 3; i++) {
      if (i != last) {
        maxm = max(maxm, task[day][i]);
      }
    }
    return maxm;
  }

  if (dp[day][last] != -1)
    return dp[day][last];

  int maxm = 0;
  for (int i = 0; i < 3; i++) {
    if (i != last) {
      int p = task[day][i] + f(day - 1, i, task, dp);
      maxm = max(maxm, p);
      cout << (task[day][i]) << endl;
    }
  }

  dp[day][last] = maxm;
  print2v(dp);
  return (maxm);
}

int test(int d, v2 &task) {

  if (d == -1)
    return 0;

  int maxm = 0;
  for (int i = 0; i < 3; i++) {
    int p = test(d - 1, task) + task[d][i];
    // if( d == 3 ) cout<<p<<endl;
    maxm = max(maxm, p);
  }
  return maxm;
}

int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  v2 task = {{2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7}};
  int n = task.size();
  // v2 dp(n, vector<int>(4, -1));

  // cout << f(n - 1, 3, task, dp) << endl;


  cout << test(n - 1, task) << endl;

  return 0;
}