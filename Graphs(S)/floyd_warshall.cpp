
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void shortest_distance(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // Easing out the soulution assigning the self node as value 0 and 
    // inifity where the node is not reachable or the path is not yet calculated or edge
    // does not exist
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == -1)
          matrix[i][j] = 1e9; // or inifinity
        if (i == j)
          matrix[i][j] = 0;
      }
    }

    for (int val = 0; val < n; val++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          matrix[i][j] = min(matrix[i][j], matrix[i][val] + matrix[val][j]);
        }
      }
    }

    // Cannot submit 1e9, as the online compiler will evaluate for -1 as the not
    // reachable node
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 1e9)
          matrix[i][j] = -1; // or inifinity
      }
    }
  }
};

int main() {

  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }
  Solution obj;
  obj.shortest_distance(matrix);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}