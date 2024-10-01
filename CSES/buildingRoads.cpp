#include <bits/stdc++.h>
using namespace std;
#define pb push_back
void dfs(int start,vector<int> adj[],vector<int> &vis){
    vis[start]=1;
    for(auto it:adj[start]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    int V = n;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> vis(V+1,0);
    vector<int> v;
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            dfs(i,adj,vis);
            v.pb(i);
        }
    }
    cout<<v.size()-1<<endl;
    for(int i=0;i<v.size()-1;i++){
        cout<<v[i]<<" "<<v[i+1]<<endl;
    }
 return 0;
}