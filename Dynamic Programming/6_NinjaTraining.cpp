#include <bits/stdc++.h>
#define ll long long int
#define push_back pb
#define F first
#define S second
using namespace std;

int f(int day, int last, vector<vector<int>> &p, vector<vector<int>> &dp) {
  if (day == 0) {
    int maxi = 0;
    for (int task = 0; task < 3; task++) {
      if (task != last) {
        maxi = max(maxi, p[0][task]);
      }
    }
    return maxi;
  }
  if (dp[day][last] != -1)
    return dp[day][last];
  int maxi = 0;
  for (int task = 0; task < 3; task++) {
    if (task != last) {
      int point = p[day][task] + f(day - 1, task, p, dp);
      maxi = max(point, maxi);
    }
  }
  return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
  vector<vector<int>> dp(n, vector<int>(4, -1));
  return f(n - 1, 3, points, dp);
}

int ninjaTraining_tabulation(int n, vector<vector<int>> &points) {

  vector<vector<int>> dp(n, vector<int>(4, 0));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][1], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;

      for (int task = 0; task < 3; task++) {
        if (task != last) {
          int pt = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], pt);
        }
      }
    }
  }

  return dp[n - 1][3];
}

int ninjaTraining_SpaceOptimization(int n, vector<vector<int>> &points) {

  vector<int> prev(4, 0);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][1], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    vector<int> temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;

      for (int task = 0; task < 3; task++) {
        if (task != last) {
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }
    prev = temp;
  }

  return prev[3];
}

int32_t main() {

  vector<vector<int>> points = {{2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7}};
  cout << "Recursion and Memoization : " << ninjaTraining(points.size(), points)
       << endl;
  cout << "Tabulation : " << ninjaTraining_tabulation(points.size(), points)
       << endl;
  cout << "Space Optimization(Tabulation) : "
       << ninjaTraining_SpaceOptimization(points.size(), points) << endl;

  return 0;
}
