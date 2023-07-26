class Solution {
    int timer = 1;
private:
    void dfs(int start,int *vis,int *tin,int *low,int parent,vector<int> adj[],vector<vector<int>> &bridges){
        vis[start] = 1;
        tin[start] = timer++;
        low[start] = tin[start];
        for(auto it:adj[start]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,vis,tin,low,start,adj,bridges);
                low[start] = min(low[start],low[it]);
                if(tin[start]<low[it]) bridges.push_back({start,it});
            }else{
                low[start] = min(low[start],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int v, vector<vector<int>>& connections) {
        vector<int> adj[v];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }                                
        int vis[v];
        for(int i=0;i<v;i++) vis[i] = 0;
        int tin[v];
        int low[v];
        vector<vector<int>> bridges;
        dfs(0,vis,tin,low,-1,adj,bridges);
        return bridges;
    }
};