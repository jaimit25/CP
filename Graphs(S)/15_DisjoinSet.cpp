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

int main() {

  DisjointSet ds(7);
  // union by rank

  //   ds.unionByRank(1, 2);
  //   ds.unionByRank(2, 3);
  //   ds.unionByRank(4, 5);
  //   ds.unionByRank(6, 7);
  //   ds.unionByRank(5, 6);

  //  union by size
  ds.unionBySize(1, 2);
  ds.unionBySize(2, 3);
  ds.unionBySize(4, 5);
  ds.unionBySize(6, 7);
  ds.unionBySize(5, 6);

  // to check if 3 AND 7 has the same ultimate parent
  if (ds.findUparent(3) == ds.findUparent(7)) {
    cout << " Same Parent " << endl;
  } else
    cout << " Not Same Parent " << endl;

  // After combining them

  //  union by rank
  // ds.unionByRank(3, 7);

  //  union by size
  ds.unionBySize(3, 7);

  if (ds.findUparent(3) == ds.findUparent(7)) {
    cout << " Same Parent " << endl;
  } else
    cout << " Not Same Parent " << endl;

  return 0;
}
