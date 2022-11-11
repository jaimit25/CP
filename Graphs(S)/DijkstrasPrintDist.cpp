//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> dist(V);

    // TO GET THE PATH - UN-COMMENT THIS
    // vector<int> parent(V);
    // for (int i = 0; i < V; i++) {
    //   parent.push_back(i);
    // }

    for (int i = 0; i < V; i++)
      dist[i] = 1e9; // MI

    dist[S] = 0; // distance from source to soruce is 0

    pq.push({0, S});

    while (!pq.empty()) {

      int dis = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      for (auto it : adj[node]) {

        int edgeW = it[1];
        int nd = it[0];

        if (edgeW + dis < dist[nd]) {
          dist[nd] = edgeW + dis;
          pq.push({dist[nd], nd});

          // TO GET THE PATH - UN-COMMENT THIS
          // parent[nd] = node;
        }
      }
    }

    // TO GET THE PATH - UN-COMMENT THIS
    // int src = 5;  // destination;
    // int node = 5; // destination
    // vector<int> path;
    // while (parent[node] != src) {
    //   path.push_back(node);
    //   node = parent[node];
    // }
    // path.push_back(src);

    return dist;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
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
    int S;
    cin >> S;

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
      cout << res[i] << " ";
    cout << endl;
  }

  return 0;
}