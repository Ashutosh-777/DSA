//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int d) {
                     
        int matrix[n][n];
        int y = edges.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=1e9;
                if(i==j) matrix[i][i]=0;
            }
        }
        for(int i=0;i<y;i++){
            int u =edges[i][0];
            int v =edges[i][1];
            int w =edges[i][2];
            matrix[u][v] =w;
            matrix[v][u]=w;
        }
        int maxi[n]={0};
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j] = min(matrix[i][j],matrix[i][via]+matrix[via][j]);
                    if(via==n-1&&matrix[i][j]<=d) maxi[i]++;
                }
            }
        }
        int ans = 2*n;
        int index=-1;
        for(int i=0;i<n;i++){
            if(maxi[i]<=ans) {
                ans = maxi[i];
                index = i;
            }
        }
        return index;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends