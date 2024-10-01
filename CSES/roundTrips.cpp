#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define imp cout<<"IMPOSSIBLE"
int dfs(int start,vector<int> adj[],vector<int>&vis,int parent,vector<int> &ans){
    vis[start] = 1;
    ans.pb(start);
    for(auto it:adj[start]){
        if(!vis[it]){
            if(dfs(it,adj,vis,start,ans)) return 1;
        }else if(it!=parent){
            ans.pb(it);
            return 1;
        }
    }
    ans.pop_back();
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
    vector<int> vis(n+1,0),pathVis(n+1,0),ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,-1,ans)){
                int roundNode = ans[ans.size()-1];
                int firstIndofRndNode = 0;
                while(ans[firstIndofRndNode]!=roundNode){
                    firstIndofRndNode++;
                }
                cout<<ans.size()-firstIndofRndNode<<endl;
                for(int i=firstIndofRndNode;i<ans.size();i++){
                    cout<<ans[i]<<" ";
                }
                cout<<endl;
                return 0;
            }
        }
    }
    imp;
 return 0;
}