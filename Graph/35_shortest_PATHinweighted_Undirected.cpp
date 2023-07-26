//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int v, int e, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[v+1];
        //pair<node,wt>
        for(int i=0;i<e;i++){
            int node = edges[i][1];
            int wt = edges[i][2];
            int j  = edges[i][0];
            adj[j].push_back({node,wt});
            adj[node].push_back({j,wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0,1});
        vector<int> dist(v+1,INT_MAX);
        dist[1]=0;
        int parent[v+1]={0};
        parent[0]=-1;
        parent[1] =1;
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(dis+wt<dist[adjNode]){
                    dist[adjNode] = dis+wt;
                    parent[adjNode] = node;
                    pq.push({dis+wt,adjNode});
                }
            }
        }
        //first time i missed thios part where you have to return -1 when you can't find the distance
        if(dist[v]==INT_MAX) return {-1};
        stack<int> s;
        s.push(v);
        int m = v;
        while(m!=1){
            s.push(parent[m]);
            m = parent[m];
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        //cout<<endl;
        return ans;

    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
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

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends