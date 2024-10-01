//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std
class Solution {
  public:
    vector<int> bellman_ford(int v, vector<vector<int>>& edges, int src) {
        vector<int> dist(v,1e8);
        int n = v;
        n--;
        dist[src]=0;
        while(n--){
            for(auto it : edges){
                if(dist[it[0]]+it[2]<dist[it[1]]){
                    dist[it[1]]=dist[it[0]]+it[2];
                }
            }
        }
        for(auto it : edges){
                if(dist[it[0]]+it[2]<dist[it[1]]){
                    return {-1};
                }
        }
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends