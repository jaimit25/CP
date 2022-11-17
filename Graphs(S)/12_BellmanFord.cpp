#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /*  Function to implement Bellman Ford
   *   edges: vector of vectors which represents the graph
   *   S: source vertex to start traversing graph with
   *   V: number of vertices
   */
  vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) {

    vector<int> dist(V, 1e8);
    dist[S] = 0;

    for (int i = 0; i < V - 1; i++) {
      for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
        }
      }
    }

    // 1 extra relation to check for the negative cycle - refer notes for
    // finding -ve cycle
    int flag = 0; // if its value is 0 then negative cycle is there

    for (auto it : edges) {
      int u = it[0];
      int v = it[1];
      int w = it[2];
      if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        return {-1};
      }
    }

    return dist;
  }
};

int main() {

  int N, m;
  cin >> N >> m;
  vector<vector<int>> edges;

  for (int i = 0; i < m; ++i) {
    vector<int> temp;
    for (int j = 0; j < 3; ++j) {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    edges.push_back(temp);
  }

  int src;
  cin >> src;

  Solution obj;
  vector<int> res = obj.bellman_ford(N, edges, src);

  for (auto x : res) {
    cout << x << " ";
  }
  cout << "\n";

  return 0;
}
