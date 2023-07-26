//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int m =grid.size();
        int n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[source.first][source.second]=0;
        int delrow[]={0,0,-1,1};
        int delcol[]={1,-1,0,0};
        queue<pair<int,int>> q;
        q.push({source.first,source.second});
        while(!q.empty()){
            int row =q.front().first;
            int col =q.front().second;
            int dis = dist[row][col];
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&grid[nrow][ncol]==1){
                    if(dist[nrow][ncol]>dis+1) {
                        dist[nrow][ncol]=dis+1;
                        q.push({nrow,ncol});}
                    }
            }
        }
        int row = destination.first;
        int col = destination.second;
        return dist[row][col]==INT_MAX? -1 : dist[row][col];
            
    }
        
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends