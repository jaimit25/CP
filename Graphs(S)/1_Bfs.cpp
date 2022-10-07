
#include <bits/stdc++.h>

using namespace std;

#define Length 10

void printGraph(vector<int> adj[], int sz) {}

vector<int> bfs(int V, vector<int> adj[Length]) {

  //   int vis[10] = {0};
  int *vis = new int[V]; // all the index are initialized with value 0.

  vis[1] = 1; // here graph is 1 base and 0  based. if the graph is 0 base the
              // vis[0] = 1;
  vector<int> ans;
  queue<int> q;
  q.push(1);
  // Looping
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (auto it : adj[node]) {
      if (!vis[it]) {
        q.push(it);
        vis[it] = 1;
      }
    }
  }

  return ans;

  //   // Initial set up
  //   int vis[10] = {0};
  //   vector<int> ans;
  //   queue<int> q;
  //   q.push(0);
  //   vis[0] = 1;

  //   // Looping
  //   while (!q.empty()) {
  //     int node = q.front();
  //     ans.push_back(node);
  //     q.pop();

  //     for (auto it : adj[node]) {
  //       if (!vis[it]) {
  //         q.push(it);
  //         vis[it] = 1;
  //       }
  //     }
  //   }

  //   return ans;
}

int main() {
  // type Code - adj list for representing graph
  int m = 10;
  vector<int> adj[m];
  adj[0] = {};
  adj[1] = {2, 6};
  adj[2] = {1, 3, 4};
  adj[3] = {2};
  adj[4] = {2, 5};
  adj[5] = {4, 8};
  adj[6] = {1, 7, 9};
  adj[7] = {6, 8};
  adj[8] = {5, 7};
  adj[9] = {6};

  vector<int> ans = bfs(Length, adj);
  for (auto it : ans) {
    cout << it << " ";
  }
  cout << endl;

  return 0;
}