#include <bits/stdc++.h>
using namespace std;

int main() {
  // type Code - adj list for representing graph
  int n, m;
  cin >> n >> m;
  vector<int> adj[m];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  return 0;
}