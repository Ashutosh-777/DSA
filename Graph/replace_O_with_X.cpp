#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++
class Solution{
private:
    void dfs(int row,int col,vector<vector<char>> mat,vector<vector<int>> &vis,int delrow[4],int delcol[4]){
        int m = mat.size();
        int n = mat[0].size();
        vis[row][col]=1;
        for(int i=0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&mat[nrow][ncol]=='O'&&!vis[nrow][ncol]){
            dfs(nrow,ncol,mat,vis,delrow,delcol);
        }
        }
    }
public:
    vector<vector<char>> fill(int m, int n, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(m,vector<int>(n,0));
        int delrow[]={-1,0,0,1};
        int delcol[]={0,-1,1,0};
        for(int i = 0;i<n;i++){
            if(mat[0][i]=='O'&&!vis[0][i]){
                dfs(0,i,mat,vis,delrow,delcol);
            }
        }
        for(int i = 0;i<n;i++){
            if(mat[m-1][i]=='O'&&!vis[m-1][i]){
                dfs(m-1,i,mat,vis,delrow,delcol);
            }
        }
        for(int i=1;i<m-1;i++){
            if(mat[i][0]=='O'&&!vis[i][0]){
                dfs(i,0,mat,vis,delrow,delcol);
            }
        }
        for(int i=1;i<m-1;i++){
            if(mat[i][n-1]=='O'&&!vis[i][n-1]){
                dfs(i,n-1,mat,vis,delrow,delcol);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends