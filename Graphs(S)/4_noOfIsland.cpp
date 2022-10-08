//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void bfs(int row, int col,vector<vector<char>> &grid,vector<vector<int>> &vis){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m  = grid[0].size();
        
        
    while(!q.empty()){
            
    int rw = q.front().first;
    int cl = q.front().second;
    q.pop();
            
            //traverse the neighbours and mark them in visited array so we dont visit again
    for(int delta_row= -1 ; delta_row <=1 ;delta_row++){
        for(int delta_col = -1; delta_col<=1 ; delta_col++){
            int nei_row = rw + delta_row;
            int nei_col = cl + delta_col;
            if(nei_row>=0 && nei_row < n && nei_col >=0 && nei_col < m && grid[nei_row][nei_col] == '1' && !vis[nei_row][nei_col]){
                vis[nei_row][nei_col] = 1;
                        q.push({nei_row,nei_col});
              }
        }
    }
            
    }
 }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int> > vis(n,vector<int>(m,0));
      int cnt = 0 ;
      for(int row = 0 ; row<n;row++)
      {
          for(int col = 0 ; col<m;col++){
              if(!vis[row][col] && grid[row][col]=='1') {
                  cnt++;
                  bfs(row,col,grid,vis);
              }
          }
      }
      return cnt;
    }
      
    };

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}