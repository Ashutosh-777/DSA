#include<bits/stdc++.h>
using namespace std;
class Solution{
    void finishTime(int start,int vis[],vector<vector<int>>& adj,stack<int>& s){
        vis[start] = 1;
        for(auto it : adj[start]){
            if(!vis[it]){
                finishTime(it,vis,adj,s);
            }
        }
        s.push(start);
    }
    void reverse(int start,vector<vector<int>>& adj,vector<int> ans[]){
        int v= adj.size();
        //vector<int> ans[v];
        int vis[v]={0};
        queue<int> q;
        q.push(start);
        vis[start] = 0 ;
        while(q.size()){
            int front = q.front();
            q.pop();
            for(auto it: adj[front]){
                int u = front;
                int v = it;
                ans[v].push_back(u);
                if(!vis[it]){
                q.push(it);
                vis[it]=1;
                }
            }
        }
    }
    void dfs(int start,int visited[],vector<int> adj[]){
        visited[start]  =  1;
        for(auto it : adj[start]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<vector<int>>& adj)
    {
        int ssc = 0;
        int vis[v]={0};
        int visited[v]={0};
        for(int i=0;i<v;i++){
        if(!visited[i]){
        stack<int> s;
        finishTime( i,vis,adj,s);
        vector<int> ans[v];
        reverse(s.top(),adj,ans);
        while(s.size()){
            if(!visited[s.top()]){
                dfs(s.top(),visited,ans);
                ssc++;
            }
            s.pop();
        }
            }
        }
        return ssc;
    }
};
int main(){
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