#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pi pair<int,int>
#define imp cout<<"IMPOSSIBLE"<<endl
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
    //source is 1 destination is n
    vector<int> vis(n+1,0),parent(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    pq.push({1,1});
    vis[1]=1;
    while(pq.size()){
        auto it = pq.top();
        int node = it.second;
        int cnt = it.first;
        pq.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                pq.push({cnt+1,it});
                parent[it] = node;
            }
        }
    }
    if(!vis[n]){
        imp;
        return 0;
    }
    int i =n;
    vector<int> ans;
    while(parent[i]!=i){
       ans.pb(i);
       i=parent[i]; 
    }
    ans.pb(1);
    // for(int i=0;i<=n;i++){
    //     cout<<parent[i]<<" ";
    // }
    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
 return 0;
}