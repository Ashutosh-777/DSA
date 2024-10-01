//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  void bfs(int sr,int sc,vector<vector<char>>& grid,vector<vector<int>>& vis,vector<pair<int,int>> &vec){
      int m =grid.size();
      int n = grid[0].size();
      int delrow[]={-1,0,0,1};
      int delcol[]={0,-1,1,0};
      queue<pair<int,int>> q;
      q.push({sr,sc});
      vec.push_back({sr-sr,sc-sc});
      while(q.size()!=0){
          pair<int,int> ans = q.front();
          q.pop();
          for(int i=0;i<4;i++){
            int nrow = ans.first + delrow[i];
            int ncol = ans.second + delcol[i];
            if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&grid[nrow][ncol]=='X'&&!vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
                vec.push_back({nrow-sr,ncol-sc});
            }
          }
      }
  }
  public:
    int countDistinctIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m,vector<int>(n,0));
    set<vector<pair<int,int>>> s;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='X'&&vis[i][j]==0){
                vector<pair<int,int>> vec;
                bfs(i,j,grid,vis,vec);
                s.insert(vec);
            }
        }
    }
    return s.size();;
        // code here
    }
};


//{ Driver Code Starts.

int main() {

    int t=1;
    //cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends