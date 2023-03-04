
#include <bits/stdc++.h>
#define ll long long int
#define push_back pb
#define F first
#define S second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define vvi vector<vector<int>>

using namespace std;

int minimumTime(vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  if (grid[0][1] > 1 && grid[1][0] > 1)
    return -1;

  vector<vector<int>> vis(n, vector<int>(m, 0));
  vis[0][0] = 1;
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      pq;
  pq.push({0, {0, 0}});
  int delcol[] = {-1, 0, 1, 0};
  int delrow[] = {0, 1, 0, -1};
  while (!pq.empty()) {
    int time = pq.top().first;
    int frow = pq.top().second.first;
    int fcol = pq.top().second.second;
    pq.pop();
    if (frow == n - 1 && fcol == m - 1)
      return time;
    for (int i = 0; i < 4; i++) {
      int nrow = frow + delrow[i];
      int ncol = fcol + delcol[i];
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]) {
        if (grid[nrow][ncol] <= time + 1) {
          pq.push({time + 1, {nrow, ncol}});
        } else {
          int diff = grid[nrow][ncol] - time;
          if (diff % 2 == 0)
            pq.push({grid[nrow][ncol] + 1, {nrow, ncol}});
          else
            pq.push({grid[nrow][ncol], {nrow, ncol}});
        }
        vis[nrow][ncol] = 1;
      }
    }
  }
  return -1;
}

int main() {

  vvi grid = {{0, 1, 3, 2}, {5, 1, 2, 5}, {4, 3, 8, 6}};
  cout << minimumTime(grid);

  return 0;
}
