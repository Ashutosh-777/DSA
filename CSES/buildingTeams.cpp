#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define imp cout<<"IMPOSSIBLE"
int dfs(int start,vector<int> adj[],vector<int>&vis,int val){
    vis[start] = val;
    for(auto it:adj[start]){
        if(vis[it]==2){
            if(dfs(it,adj,vis,!val)) return 1;
        }else if(vis[it]==val){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> vis(n+1,2);
    for(int i=1;i<=n;i++){
        if(vis[i]==2){
            if(dfs(i,adj,vis,0)){
                imp;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<vis[i]+1<<" ";
    }
    cout<<endl;
 return 0;
}