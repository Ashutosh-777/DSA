#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> adj[],int node,vector<int> &vis,int cnt,int gcd,int a[],vector<pair<int,int>> &b){
    vis[node]=1;
    int temp = __gcd(gcd,a[node-1]);
    b.push_back({temp,cnt+1});
    // cout<<" node: "<<node<<" ";
    for(auto it:adj[node]){
        // cout<<" it: "<<it<<" ";
        if(!vis[it]){
            solve(adj,it,vis,cnt+1,temp,a,b);
        }
    }
}
int main(){
    int n,m,two;
    cin>>n>>m>>two;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<pair<int,int>> edges(m);
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        // cout<<"u: "<<u<<" v: "<<v<<" ";
    }
    // cout<<endl;
    vector<pair<int,int>> gcd[n+1];
    vector<int> vis(n+1,0);
    for(auto it:adj[1]){
        if(!vis[it]){
            vis[it]=1;
            solve(adj,it,vis,0,a[0],a,gcd[it]);
        }
    }
    // cout<<gcd[2].size()<<endl;
    // for(auto it:gcd[2]){
    //     cout<<it.first<<" : "<<it.second<<endl;
    // }
    for(auto it:adj[1]){
        vector<int> b = gcd[it];

    }
 return 0;
}
// 3
// 2
// 2
// 1
// 1
// 1
// 1 2
// 2 3