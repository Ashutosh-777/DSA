//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    #define pb push_back
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({-1,{0,src}});
        //pq.push({k,{cost,node}});
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].pb({it[1],it[2]});
        }
        vector<int> val(n,1e6);
        int minm = INT_MAX;
        val[src] = 0;
        while(pq.size()){
            int cost = pq.top().second.first;
            int node = pq.top().second.second;
            int k1 = pq.top().first;
            pq.pop();
            if(k1<=k&&node==dst) minm = min(cost,minm) ;
            for(auto it:adj[node]){
                if(k1<k&&val[it.first]>cost+it.second){
                    val[it.first]=cost+it.second;
                    pq.push({k1+1,{cost+it.second,it.first}});
                }
            }
        }
        return minm == INT_MAX ? -1:minm;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends