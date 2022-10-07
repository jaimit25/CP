#include <AvailabilityVersions.h>
#include <bits/stdc++.h>
using namespace std;
#define Length 9

// void dfs(int node, vector<int> adj[], int *vis, vector<int> &ans) {

//   ans.push_back(node);
//   vis[node] = 1;
//   for (auto it : adj[node]) {
//     if (!vis[it]) {
//       dfs(it, adj, vis, ans);
//     }
//   }
// }

// vector<int> dfsOfGraph(int V, vector<int> adj[]) {
//   vector<int> ans;
//   int *vis = new int[V];
//   int start = 1;
//   vis[start] = 1;
//   dfs(start, adj, vis, ans);
//   return ans;
// }

void dfs(vector<int> &res, vector<bool> &vis, int node, vector<int> adj[]) {
  vis[node] = true;
  res.push_back(node);

  for (auto &x : adj[node]) {
    if (!vis[x])
      dfs(res, vis, x, adj);
  }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
  vector<bool> vis(V, false);
  vector<int> ans;
  dfs(ans, vis, 1, adj); // starting node is 1

  return ans;
}

int main() {

  int m = 9;
  vector<int> adj[m];
  adj[0] = {};
  adj[1] = {2, 3};
  adj[2] = {1, 5, 6};
  adj[3] = {1, 4, 7};
  adj[4] = {3, 8};
  adj[5] = {2};
  adj[6] = {2};
  adj[7] = {3, 8};
  adj[8] = {4, 7};

  vector<int> ans = dfsOfGraph(m, adj);
  for (auto it : ans) {
    cout << it << " ";
  }
  cout << endl;

  return 0;
}