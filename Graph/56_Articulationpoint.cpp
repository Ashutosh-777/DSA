//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    #define pb push_back
    int timer = 1;
    void dfs(int start,vector<int>&vis,vector<int> adj[],vector<int>&mark,int *tin,int *low,int parent){
        vis[start] = 1;
        tin[start] = timer++;
        low[start] = tin[start];
        int child = 0;
        for(auto it: adj[start]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,vis,adj,mark,tin,low,start);
                low[start] = min(low[it],low[start]);
                if(low[it]>=tin[start]&&parent!=-1){
                    mark[start]=1;
                }
                child++;
            }else{
                low[start] = min(low[start],tin[it]);
            }
        }
        if(child>1 && parent==-1) mark[start] = 1;
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
          vector<int> vis(V,0);
          vector<int> mark(V,0);
          int tin[V];
          int low[V];
          for(int i=0;i<V;i++){
              if(!vis[i]){
                  dfs(i,vis,adj,mark,tin,low,-1);
              }
          }
          vector<int> ans;
          for(int i=0;i<V;i++){
              if(mark[i]==1){
                  ans.pb(i);
              }
          }
          if(ans.size()==0) return {-1};
          return ans;
    }
};



//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends