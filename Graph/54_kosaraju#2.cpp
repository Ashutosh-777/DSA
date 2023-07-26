//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfs(int start,int vis[],vector<int> adj[]){
        vis[start] = 1;
        for(auto it: adj[start]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    void finishTime(int start,int vis[],vector<vector<int>>& adj,stack<int>& s){
        vis[start]=1;
        for(auto it : adj[start]){
            if(!vis[it]){
                finishTime(it,vis,adj,s);
            }
        }
        s.push(start);
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<vector<int>>& adj)
    {
        stack<int> s;
        int vis[v]={0};
        //got the nodes by their finishing time 
        for(int i=0;i<v;i++){
            if(!vis[i]){
                finishTime(i,vis,adj,s);
            }
        }
        //node need to reverse the graph
        vector<int> ans[v];
        for(int i=0;i<v;i++){
            vis[i]=0;
            for(auto it: adj[i]){
                int u = i;
                int v = it;
                ans[v].push_back(u);
            }
        }
        //now need to do a dfs traversal to count all the ssc's
        int ssc = 0 ;
        while(s.size()){
            int front= s.top();
            s.pop();
            if(!vis[front]){
                dfs(front,vis,ans);
                ssc++;
            }
        }
        return ssc;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends