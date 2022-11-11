//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 // flag variable to be true when there is cycle in the graph
  int flag = 0;

  void dfs(int v, int parent, vector<int> &vist, vector<int> adj[]) {

    //visiting a node node mark as 1
    vist[v] = 1;

    for (auto u : adj[v]) {
      if (vist[u] == 0) {
        dfs(u, v, vist, adj);
      }
      else if (u != parent) {
        flag = 1;
      }
    }
  }

  bool isCycle(int V, vector<int> adj[]) {
    vector<int> vist(V, 0);
    for (int i = 0; i < V; i++) {
      if (vist[i] == 0) {
        dfs(i, -1, vist, adj);
      }
    }
    if (flag == 1)
      return true;
    return false;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isCycle(V, adj);
    if (ans)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}
// } Driver Code Ends