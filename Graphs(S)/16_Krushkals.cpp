#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
  vector<int> rank, parent, size;

public:
  DisjointSet(int n) {
    rank.resize(n + 1, 0); // for 1 based indexing
    parent.resize(n + 1);
    size.resize(n + 1);

    for (int i = 0; i <= n; i++) {
      parent[i] = i;
      size[i] = i;
    }
  }
  int findUparent(int node) {
    if (node == parent[node])
      return node;
    // return findUparent(parent[node]);
    return parent[node] = findUparent(parent[node]); // path compression
  }

  void unionByRank(int u, int v) {
    int ulp_u = findUparent(u);
    int ulp_v = findUparent(v);
    if (ulp_u == ulp_v)
      return; // belongs to the same component
    if (rank[ulp_u] < rank[ulp_v]) {
      // smaller element is u and it attaches to v
      parent[ulp_u] = ulp_v;
    } else if (rank[ulp_v] < rank[ulp_u]) {
      // smaller element is v and it attaches to u
      parent[ulp_v] = ulp_u;
    } else {
      // ulp of u and v are same
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }

  void unionBySize(int u, int v) {
    int ulp_u = findUparent(u);
    int ulp_v = findUparent(v);
    if (ulp_u == ulp_v)
      return; // belongs to the same component
    if (size[ulp_u] < size[ulp_v]) {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    } else {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

class Solution {
public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  // Krushkals algorithm
  int spanningTree(int V, vector<vector<int>> adj[]) {
    // THE GRAPH HAS BI-DIRECTION EDGE
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++) {
      // going through all the edges including - bi-directional
      for (auto it : adj[i]) {
        int node = i;
        int adjNode = it[0];
        int wt = it[1];

        // The edge is bi-directional so
        // disjoint-set data structure will ignore it By-default
        edges.push_back({wt, {node, adjNode}});
      }
    }
    DisjointSet ds(V);

    sort(edges.begin(), edges.end());
    int mstwt = 0;
    for (auto it : edges) {
      int wt = it.first;
      int u = it.second.first;
      int v = it.second.second;
      if (ds.findUparent(u) != ds.findUparent(v)) {
        // if u and v belong to different component then make an edge or
        // connection between them.
        mstwt += wt;
        ds.unionBySize(u, v);
      }
    }

    return mstwt;
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
