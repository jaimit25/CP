//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[]) {
    // pair<weight,node> instead of pair<weight,node,parent> as we dont have to
    // return the list of the mst nodes.
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    vector<int> vis(V, 0);
    pq.push({0, 0}); // Entering the source(could be any node) Node.
    int sum = 0;

    while (!pq.empty()) {
      auto it = pq.top();
      pq.pop();
      int w = it.first;
      int n = it.second;

      if (vis[n] == 1)
        continue;
      vis[n] = 1;
      sum = sum + w;
      for (auto it : adj[n]) {
        if (!vis[it[0]]) {
          pq.push({it[1], it[0]}); // it[0] : adj node ,it[1] : weight
        }
      }
    }
    return sum;
  }
};

int main() {

  int V, E;
  cin >> V >> E;
  vector<vector<int>> adj[V];
  int i = 0;
  while (i++ < E) {
    int u, v, w;
    cin >> u >> v >> w;
    vector<int> t1, t2;
    t1.push_back(v);
    t1.push_back(w);
    adj[u].push_back(t1);
    t2.push_back(u);
    t2.push_back(w);
    adj[v].push_back(t2);
  }

  Solution obj;
  cout << obj.spanningTree(V, adj) << "\n";

  return 0;
}
