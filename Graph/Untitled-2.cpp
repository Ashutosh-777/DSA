#include <bits/stdc++.h>
using namespace std;
int minDis(vector<pair<int,int>> adj){
    
}
int main(){
    int V, E;
    cin >> V >> E;
    vector<pair<int,int>> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v,w;
        cin >> u >> v>>w;
        adj[u].push_back({v,w});
   }
 return 0;
}